using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using SaPousseOS_v0_2.Forms.MenuControl;

namespace SaPousseOS_v0_2
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>

        public static MenuController Control;

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Control = new MenuController();
            Application.Run(Control);
        }
    }
}
