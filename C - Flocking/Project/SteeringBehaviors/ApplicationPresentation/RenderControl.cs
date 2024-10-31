using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FullSailAFI.SteeringBehaviors.ApplicationPresentation
{
    public partial class RenderControl : UserControl
    {
        public RenderControl()
        {
            InitializeComponent();
            this.SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.Opaque, true);
        }
    }
}
