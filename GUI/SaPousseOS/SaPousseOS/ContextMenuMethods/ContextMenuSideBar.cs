using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SaPousseOS
{
    public class ContextMenuSideBar
    {
        private Panel IndicatorPanel;
        private Panel WorkPanel;
        private List<Button> ButtonList;
        private Form[] FormToDisplay;
        public ContextMenuSideBar(List<Button> ButtonList, Panel SideBar,Panel PanelToDisplay,Form[] FormToDisplay)
        {
            this.WorkPanel = PanelToDisplay;
            this.FormToDisplay = FormToDisplay;
            this.IndicatorPanel = SideBar;
            this.ButtonList = ButtonList;

            foreach(Button Element in ButtonList){


                Element.Click += new EventHandler(this.HandleSideBarEvent);
                
            
            }

            


        }
        private void HandleSideBarEvent(Object sender,EventArgs e)
        {

            WorkPanel.Controls.Clear();
            WorkPanel.Controls.Add(FormToDisplay[ButtonList.IndexOf((Button)sender)]);

 
            IndicatorPanel.Location = new Point(0, ((Button)sender).Location.Y);
            IndicatorPanel.Size = new Size(5, ((Button)sender).Size.Height);
            


        }
       





    }
}
