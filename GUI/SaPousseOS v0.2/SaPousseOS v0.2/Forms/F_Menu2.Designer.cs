
namespace SaPousseOS_v0_2.Forms
{
    partial class F_Menu2
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
            this.LABEL = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // LABEL
            // 
            this.LABEL.AutoSize = true;
            this.LABEL.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.LABEL.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.LABEL.Location = new System.Drawing.Point(285, 195);
            this.LABEL.Name = "LABEL";
            this.LABEL.Size = new System.Drawing.Size(35, 13);
            this.LABEL.TabIndex = 0;
            this.LABEL.Text = "label1";
            // 
            // F_Menu2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.BackgroundColor;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.LABEL);
            this.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "BackgroundColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "F_Menu2";
            this.Text = "Menu2";
            this.Load += new System.EventHandler(this.F_Menu2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Label LABEL;
    }
}