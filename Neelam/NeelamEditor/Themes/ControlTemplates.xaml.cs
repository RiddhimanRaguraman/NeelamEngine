using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;

namespace NeelamEditor.Themes
{
    // Shared event handlers for the implicit styles in ControlTemplates.xaml.
    public partial class ControlTemplates : ResourceDictionary
    {
        // Commits the textbox: if Tag is an ICommand (e.g. RenameCommand),
        // execute it with the current text so the change lands in undo/redo;
        // otherwise just push the binding source. Returns true if anything
        // was committed (used by KeyDown to clear focus + mark handled).
        private static bool Commit(TextBox textBox, BindingExpression exp)
        {
            if (textBox.Tag is ICommand command && command.CanExecute(textBox.Text))
            {
                command.Execute(textBox.Text);
                return true;
            }
            exp.UpdateSource();
            return false;
        }

        // Enter commits, Escape reverts. Either way, drop focus so the editor
        // hotkeys (Ctrl+Z/Y/S) are immediately live again.
        private void OnTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            var textBox = sender as TextBox;
            var exp = textBox.GetBindingExpression(TextBox.TextProperty);
            if (exp == null) return;

            if (e.Key == Key.Enter)
            {
                Commit(textBox, exp);
                Keyboard.ClearFocus();
                e.Handled = true;
            }
            else if (e.Key == Key.Escape)
            {
                exp.UpdateTarget();
                Keyboard.ClearFocus();
            }
        }

        // Tab-away / click-away commit. Uses LostKeyboardFocus so this runs
        // BEFORE the binding's default LostFocus update — important because
        // RenameCommand.CanExecute compares against the current source value,
        // and if the binding has already pushed, oldName == newName and no
        // undo entry is created.
        private void OnTextBox_LostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
        {
            var textBox = sender as TextBox;
            var exp = textBox.GetBindingExpression(TextBox.TextProperty);
            if (exp == null) return;
            Commit(textBox, exp);
        }
    }
}
