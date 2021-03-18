using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;




namespace SaPousseOS_v0_2.CustomisedControls.MenuControls
{


    public class CheckSlider : Control
    {
        private Rectangle test;
        private bool isChecked;
        //private Timer AnimationTicker;
        public event SliderStateChangedEventHandler CheckSliderChanged;

        public bool IsChecked
        {
            get => this.isChecked;

            set

            {
                this.isChecked = value;
                if (this.CheckSliderChanged != null)
                {

                    this.CheckSliderChanged(this, EventArgs.Empty);

                }

            }

        }
    

  
        
        public CheckSlider()
        {

            InitializeComponent();

            this.test = new Rectangle(100, 10,90,40);

        }

        private void InitializeComponent()
        {

            //this.AnimationTicker.Tick += new EventHandler(this.Tick);
            //this.test = new Rectangle(2, 2,this.Width,this.Height);

        }
        protected override void OnEnabledChanged(EventArgs e)
        {
            base.OnEnabledChanged(e);
        }
        protected override void OnMouseDown(MouseEventArgs e)
        {
            this.IsChecked = !this.IsChecked;
            base.OnMouseDown(e);
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            Pen pn = new Pen(Color.White, 2f);
            SolidBrush brsh = new SolidBrush(Color.Black);
            
            e.Graphics.SmoothingMode = (SmoothingMode)SmoothingMode.HighQuality;
            //e.Graphics.FillRectangle((Brush)brsh, this.test);
            e.Graphics.DrawRectangle(Pens.White,this.test);
            
            base.OnPaint(e);
        }
        protected override void OnResize(EventArgs e)
        {
            base.Height = base.Width/2;
            this.test = new Rectangle(10, 10, this.Width-20,this.Height - 20);
            base.OnResize(e);
        }
        private void Tick(Object sender,EventArgs e)
        {




        }



        public delegate void SliderStateChangedEventHandler(object Sender, EventArgs e);

    }
}