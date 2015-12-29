using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Myform5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string t1 = "";
            string t2 = "";
            label1.Text = "";
            label2.Text = "";
            if (radioButton1.Checked)
                t1 = radioButton1.Text;
            if (radioButton2.Checked)
                t1 = radioButton2.Text;
            if (radioButton3.Checked)
                t1 = radioButton3.Text;
            label1.Text = "你最喜欢的活动是" + t1;

            if (checkBox1.Checked)
                t2 = t2 + checkBox1.Text + "  ";
            if (checkBox2.Checked)
                t2 = t2 + checkBox2.Text + "  ";
            if (checkBox3.Checked)
                t2 = t2 + checkBox3.Text + "  ";
            if (checkBox4.Checked)
                t2 = t2 + checkBox4.Text + "  ";
            if (checkBox5.Checked)
                t2 = t2 + checkBox5.Text + "  ";
            label2.Text = "你本学期选修的课程是：" + t2;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
