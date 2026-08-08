using System.Windows;

namespace NeelamEditor.Utilities.Controls
{
    // A NumberBox with its own default style (a pill-shaped single field). Behaviour
    // is identical to NumberBox; only the template differs.
    class ScalarBox : NumberBox
    {
        static ScalarBox()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof(ScalarBox),
                new FrameworkPropertyMetadata(typeof(ScalarBox)));
        }
    }
}
