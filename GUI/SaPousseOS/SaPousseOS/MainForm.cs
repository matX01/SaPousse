using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace SaPousseOS
{


    
    public partial class MainForm : Form
    {

        ContextMenuSideBar SideMenu;
        static StartupMenu ui = new StartupMenu("haha");
        static StartupMenu no = new StartupMenu("uilio");
        static MainMenu il = new MainMenu() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
        static Settings li = new Settings() { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
        public MainForm() 
        {
            
            InitializeComponent();

            LightMode.Checked = (Properties.Settings.Default.BackgroundColor == Properties.Settings.Default.DarkModeBackGround);

            LightMode.Text = ((Properties.Settings.Default.BackgroundColor == Properties.Settings.Default.DarkModeBackGround) ? "LightMode" : "DarkMode");

            SideMenu = new ContextMenuSideBar(new List<Button>{LeftMenu_B_Settings, LeftMenu_B_Start },
                SelectedToolIndicator,
                splitContainer1.Panel2,
                new Form[]{ il , li });
            ui.Pane = splitContainer1.Panel2;
            no.Pane = splitContainer1.Panel2;
            

        }
        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (LightMode.Checked)
            {
                
                LightMode.Text = "LightMode";
                Properties.Settings.Default.BackgroundColor = Properties.Settings.Default.DarkModeBackGround;
                Properties.Settings.Default.ContextMenuColor = Properties.Settings.Default.DarkModeContextMenu;
                Properties.Settings.Default.FontColor = Properties.Settings.Default.DarkModeFont;
            }
            else
            {
                
                LightMode.Text = "DarkMode";
                Properties.Settings.Default.BackgroundColor = Properties.Settings.Default.LightModeBackGround;
                Properties.Settings.Default.ContextMenuColor = Properties.Settings.Default.LightModeContextMenu;
                Properties.Settings.Default.FontColor = Properties.Settings.Default.LightModeFont;


            }


            Properties.Settings.Default.Save();
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void ParameterButton_Click(object sender, EventArgs e)
        { 

        }

        private void MainMenuButton_Click(object sender, EventArgs e)
        {

        
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }







}
