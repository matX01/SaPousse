
namespace SaPousseOS_v0_2
{
    partial class MainWindow
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
            this.P_MainContainer = new System.Windows.Forms.SplitContainer();
            this.P_SideMenuSelected = new System.Windows.Forms.Panel();
            this.B_Menu3 = new System.Windows.Forms.Button();
            this.B_Menu2 = new System.Windows.Forms.Button();
            this.B_MainMenu = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.P_MainContainer)).BeginInit();
            this.P_MainContainer.Panel1.SuspendLayout();
            this.P_MainContainer.SuspendLayout();
            this.SuspendLayout();
            // 
            // P_MainContainer
            // 
            this.P_MainContainer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.P_MainContainer.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.P_MainContainer.Location = new System.Drawing.Point(0, 0);
            this.P_MainContainer.Margin = new System.Windows.Forms.Padding(0);
            this.P_MainContainer.Name = "P_MainContainer";
            // 
            // P_MainContainer.Panel1
            // 
            this.P_MainContainer.Panel1.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.SubMenu;
            this.P_MainContainer.Panel1.Controls.Add(this.P_SideMenuSelected);
            this.P_MainContainer.Panel1.Controls.Add(this.B_Menu3);
            this.P_MainContainer.Panel1.Controls.Add(this.B_Menu2);
            this.P_MainContainer.Panel1.Controls.Add(this.B_MainMenu);
            this.P_MainContainer.Panel1.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "SubMenu", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.P_MainContainer.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.P_MainContainer_Panel1_Paint);
            // 
            // P_MainContainer.Panel2
            // 
            this.P_MainContainer.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.P_MainContainer_Panel2_Paint);
            this.P_MainContainer.Size = new System.Drawing.Size(800, 450);
            this.P_MainContainer.SplitterDistance = 185;
            this.P_MainContainer.SplitterWidth = 1;
            this.P_MainContainer.TabIndex = 0;
            // 
            // P_SideMenuSelected
            // 
            this.P_SideMenuSelected.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.P_SideMenuSelected.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.P_SideMenuSelected.Location = new System.Drawing.Point(0, 0);
            this.P_SideMenuSelected.Name = "P_SideMenuSelected";
            this.P_SideMenuSelected.Size = new System.Drawing.Size(5, 62);
            this.P_SideMenuSelected.TabIndex = 2;
            // 
            // B_Menu3
            // 
            this.B_Menu3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Menu3.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.B_Menu3.FlatAppearance.BorderSize = 0;
            this.B_Menu3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.B_Menu3.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.B_Menu3.Location = new System.Drawing.Point(0, 124);
            this.B_Menu3.Margin = new System.Windows.Forms.Padding(0);
            this.B_Menu3.Name = "B_Menu3";
            this.B_Menu3.Size = new System.Drawing.Size(182, 62);
            this.B_Menu3.TabIndex = 1;
            this.B_Menu3.Text = "Menu3";
            this.B_Menu3.UseVisualStyleBackColor = true;
            // 
            // B_Menu2
            // 
            this.B_Menu2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Menu2.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.B_Menu2.FlatAppearance.BorderSize = 0;
            this.B_Menu2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.B_Menu2.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.B_Menu2.Location = new System.Drawing.Point(0, 62);
            this.B_Menu2.Margin = new System.Windows.Forms.Padding(0);
            this.B_Menu2.Name = "B_Menu2";
            this.B_Menu2.Size = new System.Drawing.Size(182, 62);
            this.B_Menu2.TabIndex = 1;
            this.B_Menu2.Text = "Menu2";
            this.B_Menu2.UseVisualStyleBackColor = true;
            // 
            // B_MainMenu
            // 
            this.B_MainMenu.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_MainMenu.DataBindings.Add(new System.Windows.Forms.Binding("ForeColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "FontColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.B_MainMenu.FlatAppearance.BorderSize = 0;
            this.B_MainMenu.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.B_MainMenu.ForeColor = global::SaPousseOS_v0_2.Properties.Settings.Default.FontColor;
            this.B_MainMenu.Location = new System.Drawing.Point(0, 0);
            this.B_MainMenu.Margin = new System.Windows.Forms.Padding(0);
            this.B_MainMenu.Name = "B_MainMenu";
            this.B_MainMenu.Size = new System.Drawing.Size(182, 62);
            this.B_MainMenu.TabIndex = 1;
            this.B_MainMenu.Text = "Main Menu";
            this.B_MainMenu.UseVisualStyleBackColor = true;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = global::SaPousseOS_v0_2.Properties.Settings.Default.BackgroundColor;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.P_MainContainer);
            this.DataBindings.Add(new System.Windows.Forms.Binding("BackColor", global::SaPousseOS_v0_2.Properties.Settings.Default, "BackgroundColor", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.Name = "MainWindow";
            this.Text = "SaPousseOS";
            this.P_MainContainer.Panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.P_MainContainer)).EndInit();
            this.P_MainContainer.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer P_MainContainer;
        private System.Windows.Forms.Button B_MainMenu;
        private System.Windows.Forms.Panel P_SideMenuSelected;
        private System.Windows.Forms.Button B_Menu2;
        private System.Windows.Forms.Button B_Menu3;
    }
}

