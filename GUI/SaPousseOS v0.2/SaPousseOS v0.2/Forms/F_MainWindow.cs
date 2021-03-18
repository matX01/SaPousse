using System.Windows.Forms;
using SaPousseOS_v0_2.SideMenuMethods;
using SaPousseOS_v0_2.Forms;
using System.Collections.Generic;
using SaPousseOS_v0_2.CustomisedControls.MenuControls;

namespace SaPousseOS_v0_2
{
    public partial class MainWindow : Form
    {
        public SmartButton MainMenuSelector;
        public static SmartButton Menu2Selector;
        public SmartButton Menu3Selector;
        public SideMenu MainSideBar;
        


        
        public MainWindow()
        {
            InitializeComponent();
            
                   
            MainMenuSelector = new SmartButton(B_MainMenu,new F_MainMenu() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true });
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
    }
}
