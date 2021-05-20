using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SaPousseOS_v0_2.Forms;


namespace SaPousseOS_v0_2.Forms.MenuControl
{
    
    public partial class MenuController : Form
    {

        public MenuController()
        {
            InitializeComponent();
            MainPanel.Controls.Clear();
            MainPanel.Controls.Add(new MainMenu.MainMenu() { TopLevel = false, Visible = true , Dock = DockStyle.Fill});
        }

        private void MenuController_Load(object sender, EventArgs e)
        {
            
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
           

        }

        public void SetNewMenu(Form Menu)
        {

            MainPanel.Controls.Clear();
            MainPanel.Controls.Add(Menu);


        }

    }
}
