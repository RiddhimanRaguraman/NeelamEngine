using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeelamEditor.Utilities
{
    // One reversible editor action. Implementations capture before/after state
    // in their ctor and apply it in Undo/Redo.
    public interface IUndoRedo
    {
        string Name { get; }
        void Undo();
        void Redo();
    }

    // Lambda-based IUndoRedo. Use when you don't want a dedicated command class
    // for a simple before/after pair — pass two Actions and a label.
    public class UndoRedoAction : IUndoRedo
    {
        private Action _undoAction;
        private Action _redoAction;

        public string Name { get; }

        public void Redo() => _redoAction();
        public void Undo() => _undoAction();

        // Subclass-friendly ctor: lets a derived type set Name first and assign
        // the Actions later (e.g. when it needs `this` to build the closures).
        public UndoRedoAction(string name)
        {
            Name = name;
        }

        public UndoRedoAction(Action undo, Action redo, string name)
            : this(name)
        {
            Debug.Assert(undo != null && redo != null);
            _undoAction = undo;
            _redoAction = redo;
        }
    }

    // Owns the undo / redo stacks. Add an IUndoRedo with Add(...) when the user
    // performs an action; call Undo() / Redo() to walk history.
    public class UndoRedo
    {
        private bool _enableAdd = true;
        // Most-recently-executed action is at the end of _undoList.
        private readonly ObservableCollection<IUndoRedo> _redoList = new ObservableCollection<IUndoRedo>();
        private readonly ObservableCollection<IUndoRedo> _undoList = new ObservableCollection<IUndoRedo>();

        // Read-only views for the UI (history panel, menu enable/disable).
        public ReadOnlyObservableCollection<IUndoRedo> RedoList { get; }
        public ReadOnlyObservableCollection<IUndoRedo> UndoList { get; }

        // Drop everything, e.g. when a new project loads.
        public void Reset()
        {
            _redoList.Clear();
            _undoList.Clear();
        }

        public void Add(IUndoRedo undo)
        {
            if (_enableAdd)
            {
                _undoList.Add(undo);
                _redoList.Clear();
            }
        }

        // Pop the most recent action off the undo stack, invoke its Undo, and
        // push it onto the front of the redo stack so it can be replayed.
        public void Undo()
        {
            if (_undoList.Any())
            {
                var cmd = _undoList.Last();
                _undoList.RemoveAt(_undoList.Count - 1);
                _enableAdd = false;
                cmd.Undo();
                _enableAdd = true;
                _redoList.Insert(0, cmd);
            }
        }

        // Mirror of Undo: pull the head of the redo stack, re-apply, push to undo.
        public void Redo()
        {
            if (_redoList.Any())
            {
                var cmd = _redoList.First();
                _redoList.RemoveAt(0);
                _enableAdd = false;
                cmd.Redo();
                _enableAdd = true;
                _undoList.Add(cmd);
            }
        }

        public UndoRedo()
        {
            RedoList = new ReadOnlyObservableCollection<IUndoRedo>(_redoList);
            UndoList = new ReadOnlyObservableCollection<IUndoRedo>(_undoList);
        }
    }
}
