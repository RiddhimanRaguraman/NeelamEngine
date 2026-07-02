using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;

namespace NeelamEditor.Utilities
{
    enum MessageTypes
    {
        Info = 0x01,
        Warning = 0x02,
        Error = 0x04,
    }

    class LogMessage
    {
        //Data members
        public DateTime Time { get; }
        public MessageTypes Type { get; }
        public string Message { get; }
        public string File { get; }
        public string Caller { get; }
        public int Line { get; }
        public string Metadata => $"{File}: {Caller} (Line :{Line})";

        public LogMessage(MessageTypes _type, string _msg, string _file, string _caller, int _line)
        {
            this.Time = DateTime.Now;
            this.Type = _type;
            this.Message = _msg;
            this.File = _file;
            this.Caller = _caller;
            this.Line = _line;
        }

    }
    static class Logger
    {
        // Bitmask of which MessageTypes pass through FilteredMessages.
        // Default: Info | Warning | Error (everything).
        private static int _messageFilter = (int)(MessageTypes.Info | MessageTypes.Warning | MessageTypes.Error);

        private static readonly ObservableCollection<LogMessage> _messages = new ObservableCollection<LogMessage>();
        public static ReadOnlyObservableCollection<LogMessage> Messages { get; } = new ReadOnlyObservableCollection<LogMessage>(_messages);

        // UI binds to FilteredMessages.View so changing _messageFilter (then
        // Refresh()) reactively hides/shows entries by severity.
        public static CollectionViewSource FilteredMessages { get; } = new CollectionViewSource { Source = Messages };

        // Append a log entry. Marshals to the UI thread because _messages drives
        // ObservableCollection updates that must run there.
        public static async void Log(MessageTypes type, string msg,
            [CallerFilePath] string file = "",
            [CallerMemberName] string caller = "",
            [CallerLineNumber] int line = 0)
        {
            await Application.Current.Dispatcher.BeginInvoke(new Action(() =>
            {
                _messages.Add(new LogMessage(type, msg, file, caller, line));
            }));
        }

        // Wipe all entries. Same UI-thread marshalling.
        public static async void Clear()
        {
            await Application.Current.Dispatcher.BeginInvoke(new Action(() =>
            {
                _messages.Clear();
            }));
        }

        // Update the severity bitmask and tell the view to re-evaluate Accepted
        // against every existing entry.
        public static void SetMessageFilter(int mask)
        {
            _messageFilter = mask;
            FilteredMessages.View.Refresh();
        }

        // Wire the filter predicate once, lazily on first access to the type.
        static Logger()
        {
            FilteredMessages.Filter += (s, e) =>
            {
                var type = (int)(e.Item as LogMessage).Type;
                e.Accepted = (type & _messageFilter) != 0;
            };
        }
    }
}
