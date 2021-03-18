
namespace SaPousseOS
{
    partial class MainForm
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
            this.LightMode = new System.Windows.Forms.CheckBox();
            this.LeftMenu_B_Settings = new System.Windows.Forms.Button();
            this.LeftMenu_B_Start = new System.Windows.Forms.Button();
            this.SelectedToolIndicator = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // LightMode
            // 
            this.LightMode.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.LightMode.AutoSize = true;
            this.LightMode.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.LightMode.ForeColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.LightMode.ImageAlign = System.Drawing.ContentAlignment.BottomRight;
            this.LightMode.Location = new System.Drawing.Point(960, 589);
            this.LightMode.Name = "LightMode";
            this.LightMode.Size = new System.Drawing.Size(95, 22);
            this.LightMode.TabIndex = 1;
            this.LightMode.Text = "LightMode";
            this.LightMode.UseVisualStyleBackColor = true;
            this.LightMode.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // LeftMenu_B_Settings
            // 
            this.LeftMenu_B_Settings.AutoSize = true;
            this.LeftMenu_B_Settings.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.LeftMenu_B_Settings.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.LeftMenu_B_Settings.FlatAppearance.BorderSize = 0;
            this.LeftMenu_B_Settings.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LeftMenu_B_Settings.ForeColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.LeftMenu_B_Settings.Location = new System.Drawing.Point(-6, 541);
            this.LeftMenu_B_Settings.Name = "LeftMenu_B_Settings";
            this.LeftMenu_B_Settings.Size = new System.Drawing.Size(235, 71);
            this.LeftMenu_B_Settings.TabIndex = 2;
            this.LeftMenu_B_Settings.Text = "Settings";
            this.LeftMenu_B_Settings.UseVisualStyleBackColor = false;
            this.LeftMenu_B_Settings.Click += new System.EventHandler(this.ParameterButton_Click);
            // 
            // LeftMenu_B_Start
            // 
            this.LeftMenu_B_Start.AutoSize = true;
            this.LeftMenu_B_Start.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.LeftMenu_B_Start.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.LeftMenu_B_Start.FlatAppearance.BorderSize = 0;
            this.LeftMenu_B_Start.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LeftMenu_B_Start.ForeColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.LeftMenu_B_Start.Location = new System.Drawing.Point(0, 13);
            this.LeftMenu_B_Start.Name = "LeftMenu_B_Start";
            this.LeftMenu_B_Start.Size = new System.Drawing.Size(235, 71);
            this.LeftMenu_B_Start.TabIndex = 2;
            this.LeftMenu_B_Start.Tag = "";
            this.LeftMenu_B_Start.Text = "Start";
            this.LeftMenu_B_Start.UseVisualStyleBackColor = false;
            this.LeftMenu_B_Start.Click += new System.EventHandler(this.MainMenuButton_Click);
            // 
            // SelectedToolIndicator
            // 
            this.SelectedToolIndicator.AutoScroll = true;
            this.SelectedToolIndicator.AutoSize = true;
            this.SelectedToolIndicator.BackColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.SelectedToolIndicator.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.SelectedToolIndicator.Location = new System.Drawing.Point(0, 13);
            this.SelectedToolIndicator.Margin = new System.Windows.Forms.Padding(0);
            this.SelectedToolIndicator.Name = "SelectedToolIndicator";
            this.SelectedToolIndicator.Size = new System.Drawing.Size(5, 71);
            this.SelectedToolIndicator.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.AutoSize = true;
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button1.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.button1.FlatAppearance.BorderSize = 0;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.ForeColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.button1.Location = new System.Drawing.Point(0, 87);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(235, 71);
            this.button1.TabIndex = 3;
            this.button1.Tag = "";
            this.button1.Text = "Main Menu";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.AutoSize = true;
            this.button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button2.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.button2.FlatAppearance.BorderSize = 0;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.ForeColor = global::SaPousseOS.Properties.Settings.Default.FontColor;
            this.button2.Location = new System.Drawing.Point(3, 164);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(235, 71);
            this.button2.TabIndex = 4;
            this.button2.Tag = "";
            this.button2.Text = "Main Menu";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer1.Location = new System.Drawing.Point(1, -1);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.BackColor = global::SaPousseOS.Properties.Settings.Default.ContextMenuColor;
            this.splitContainer1.Panel1.Controls.Add(this.button2);
            this.splitContainer1.Panel1.Controls.Add(this.button1);
            this.splitContainer1.Panel1.Controls.Add(this.SelectedToolIndicator);
            this.splitContainer1.Panel1.Controls.Add(this.LeftMenu_B_Start);
            this.splitContainer1.Panel1.Controls.Add(this.LeftMenu_B_Settings);
            this.splitContainer1.Panel1.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS.Properties.Settings.Default, "ContextMenuColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.splitContainer1.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel1_Paint);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel2_Paint);
            this.splitContainer1.Size = new System.Drawing.Size(1066, 629);
            this.splitContainer1.SplitterDistance = 229;
            this.splitContainer1.TabIndex = 2;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = global::SaPousseOS.Properties.Settings.Default.BackgroundColor;
            this.ClientSize = new System.Drawing.Size(1067, 623);
            this.Controls.Add(this.LightMode);
            this.Controls.Add(this.splitContainer1);
            this.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS.Properties.Settings.Default, "BackgroundColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.Font = new System.Drawing.Font("Candara", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "MainForm";
            this.Text = "SaPousseOS";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.CheckBox LightMode;
        private System.Windows.Forms.Button LeftMenu_B_Settings;
        private System.Windows.Forms.Button LeftMenu_B_Start;
        private System.Windows.Forms.Panel SelectedToolIndicator;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        public System.Windows.Forms.SplitContainer splitContainer1;
    }
}

