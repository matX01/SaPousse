using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SaPousseOS

{

    public abstract class SmartPanel
    {

        public String Name;
        public Panel Pane;
        public abstract void Display(Panel WorkPanel);

    }
}
