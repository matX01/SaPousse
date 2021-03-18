using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
namespace SaPousseOS_v0_2.SideMenuMethods
{
    public struct SmartButton
    {


        public Button button;
        public Form form;
        public SmartButton(Button b = null, Form f = null)
        {
            this.button = b;
            this.form = f;

        }
    }

    public class SideMenu
    {
        private List<SmartButton> PanelList;
        private Panel SelectedMenuIndicator;
        private Panel PanelToDisplay;
        public SideMenu(List<SmartButton> PanelList,Panel SelectedMenuIndicator,Panel PanelToDisplay)
        {
            this.PanelList = PanelList;
            this.SelectedMenuIndicator = SelectedMenuIndicator;
            this.PanelToDisplay = PanelToDisplay;
            foreach (SmartButton Element in PanelList)
            {


                Element.button.Click += new EventHandler(this.HandleSideMenuEvent);



            }

            HandleSideMenuEvent(PanelList[0].button, new EventArgs());

        }

        private void HandleSideMenuEvent(Object Sender, EventArgs e)
        {
            PanelToDisplay.Controls.Clear();
            int IndexOfButton = 0;
            for(int i = 0;i < PanelList.Count;i++)
            {

                if((Button) Sender == PanelList[i].button)
                {

                    IndexOfButton = i;
                    break;


                }
                

            }
            
            PanelToDisplay.Controls.Add(PanelList[IndexOfButton].form);

            
            SelectedMenuIndicator.Location = new Point(((Button)Sender).Location.X, ((Button)Sender).Location.Y);
            SelectedMenuIndicator.Size = new Size(Properties.Settings.Default.SideMenuIndicatorPanelSize,((Button)Sender).Height);
           

        }










        }
}
