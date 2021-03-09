using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FirstGUI
{
    public partial class SaPousse : Form
    {
        public SaPousse()
        {
            InitializeComponent();
            textBox1.AcceptsReturn = true;
           
            this.BackColor = Program.BackGroundColor;

        }



        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

            if (textBox1.Text.Contains("ROUGE"))
            {
                label1.ForeColor = Color.Red;




            }
            else
            {
                label1.ForeColor = Color.White;



            }

            if (textBox1.Text.Contains("INVISIBLE"))
            {

                label1.Visible = false;

            }
            else {

                label1.Visible = true;
                label1.Text = textBox1.Text;
                
            }

           
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {

                Program.BackGroundColor = Color.FromArgb(255, 255, 255, 255);


            }
            else
            {

                Program.BackGroundColor = Color.FromArgb(255, 46, 51, 73);

            }

        }
    }
}
