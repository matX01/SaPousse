using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SaPousseOS_v0_2.Forms.MenuControl;


namespace SaPousseOS_v0_2.Forms.MainMenu
{
    public partial class MainMenu : Form
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            Program.Control.SetNewMenu(new Parameters.F_MainParameterWindow() { TopLevel = false, Visible = true, Dock = DockStyle.Fill });

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            new Parameters.F_MainParameterWindow() { TopLevel = false, Visible = true, Dock = DockStyle.Fill };
        }
    }
}
