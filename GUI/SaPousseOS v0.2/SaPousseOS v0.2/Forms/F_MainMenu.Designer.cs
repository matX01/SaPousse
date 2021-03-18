
namespace SaPousseOS_v0_2.Forms
{
    partial class F_MainMenu
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.P_MainMenuSeparator = new System.Windows.Forms.SplitContainer();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.checkSlider1 = new SaPousseOS_v0_2.CustomisedControls.MenuControls.CheckSlider();
            ((System.ComponentModel.ISupportInitialize)(this.P_MainMenuSeparator)).BeginInit();
            this.P_MainMenuSeparator.Panel2.SuspendLayout();
            this.P_MainMenuSeparator.SuspendLayout();
            this.SuspendLayout();
            // 
            // P_MainMenuSeparator
            // 
            this.P_MainMenuSeparator.Dock = System.Windows.Forms.DockStyle.Fill;
            this.P_MainMenuSeparator.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.P_MainMenuSeparator.Location = new System.Drawing.Point(0, 0);
            this.P_MainMenuSeparator.Name = "P_MainMenuSeparator";
            this.P_MainMenuSeparator.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // P_MainMenuSeparator.Panel1
            // 
            this.P_MainMenuSeparator.Panel1.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.SubMenu;
            this.P_MainMenuSeparator.Panel1.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "SubMenu", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.P_MainMenuSeparator.Panel1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.P_MainMenuSeparator.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel1_Paint);
            this.P_MainMenuSeparator.Panel1MinSize = 10;
            // 
            // P_MainMenuSeparator.Panel2
            // 
            this.P_MainMenuSeparator.Panel2.Controls.Add(this.checkSlider1);
            this.P_MainMenuSeparator.Panel2.Controls.Add(this.checkBox1);
            this.P_MainMenuSeparator.Panel2.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.P_MainMenuSeparator.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.P_MainMenuSeparator.Size = new System.Drawing.Size(800, 450);
            this.P_MainMenuSeparator.SplitterDistance = 28;
            this.P_MainMenuSeparator.SplitterWidth = 1;
            this.P_MainMenuSeparator.TabIndex = 0;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.checkBox1.Location = new System.Drawing.Point(495, 163);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(78, 17);
            this.checkBox1.TabIndex = 0;
            this.checkBox1.Text = "checkBox1";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // checkSlider1
            // 
            this.checkSlider1.IsChecked = false;
            this.checkSlider1.Location = new System.Drawing.Point(82, 116);
            this.checkSlider1.Name = "checkSlider1";
            this.checkSlider1.Size = new System.Drawing.Size(407, 203);
            this.checkSlider1.TabIndex = 1;
            this.checkSlider1.Text = "checkSlider1";
            // 
            // F_MainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.BackgroundColor;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.P_MainMenuSeparator);
            this.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "BackgroundColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "F_MainMenu";
            this.Text = "Form1";
            this.P_MainMenuSeparator.Panel2.ResumeLayout(false);
            this.P_MainMenuSeparator.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.P_MainMenuSeparator)).EndInit();
            this.P_MainMenuSeparator.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer P_MainMenuSeparator;
        private System.Windows.Forms.CheckBox checkBox1;
        private CustomisedControls.MenuControls.CheckSlider checkSlider1;
    }
}