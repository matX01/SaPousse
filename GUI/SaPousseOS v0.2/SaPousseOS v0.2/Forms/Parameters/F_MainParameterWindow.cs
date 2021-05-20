using System.Windows.Forms;
using SaPousseOS_v0_2.SideMenuMethods;

using System.Collections.Generic;
using SaPousseOS_v0_2.CustomisedControls.MenuControls;
using SaPousseOS_v0_2.Forms.Parameters;

namespace SaPousseOS_v0_2.Forms.Parameters
{
    public partial class F_MainParameterWindow : Form
    {
        public SmartButton MainMenuSelector;
        public static SmartButton Menu2Selector;
        public SmartButton Menu3Selector;
        public SideMenu MainSideBar;
        


        
        public F_MainParameterWindow()
        {
            InitializeComponent();
            
            MainMenuSelector = new SmartButton(B_MainMenu,new F_Menu1() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true });
            Menu2Selector = new SmartButton(B_Menu2, new F_Menu2() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true });
            Menu3Selector = new SmartButton(B_Menu3, new F_Menu3() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true });
           
            MainSideBar = new SideMenu(new List<SmartButton> { MainMenuSelector , Menu2Selector ,Menu3Selector}, P_SideMenuSelected, P_MainContainer.Panel2);
            


        }

        private void P_MainContainer_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void P_MainContainer_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void B_MainMenu_Click(object sender, System.EventArgs e)
        {

        }
        private void B_GoBack_Click(object sender, System.EventArgs e)
        {

            Program.Control.SetNewMenu(new MainMenu.MainMenu() { TopLevel = false, Visible = true, Dock = DockStyle.Fill });

        }

 
    }
}
