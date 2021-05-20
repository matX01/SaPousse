
namespace SaPousseOS_v0_2.Forms.MainMenu
{
    partial class MainMenu
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
            this.EFIS = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // EFIS
            // 
            this.EFIS.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.SubMenu;
            this.EFIS.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.EFIS.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "SubMenu", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.EFIS.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.EFIS.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.EFIS.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.EFIS.Location = new System.Drawing.Point(12, 12);
            this.EFIS.Name = "EFIS";
            this.EFIS.Size = new System.Drawing.Size(227, 46);
            this.EFIS.TabIndex = 0;
            this.EFIS.Text = "EFIS";
            this.EFIS.UseVisualStyleBackColor = false;
            this.EFIS.Click += new System.EventHandler(this.button1_Click);
            // 
            // button1
            // 
            this.button1.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.SubMenu;
            this.button1.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.button1.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "SubMenu", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.button1.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.button1.Location = new System.Drawing.Point(12, 64);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(227, 46);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // MainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.BackgroundColor;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.EFIS);
            this.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "BackgroundColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MainMenu";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button EFIS;
        private System.Windows.Forms.Button button1;
    }
}