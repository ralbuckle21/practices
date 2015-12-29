using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Myform9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int count;
            count = int.Parse(label1.Text);
            count++;
            label1.Text = count.ToString();
            this.Text = "现在的日期" + System.DateTime.Now.Year.ToString() + "年" +
                System.DateTime.Now.Month.ToString() + "月" + System.DateTime.Now.Day.ToString() + "日" +
                System.DateTime.Now.Hour.ToString() + ":" + System.DateTime.Now.Minute.ToString() + ":" +
                System.DateTime.Now.Second.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            button1.Enabled = true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (button3.Text.Equals("暂停计时"))
            {
                timer1.Enabled = false;
                button3.Text = "继续计时";
            }
            else
            {
                button3.Text = "暂停计时";
                timer1.Enabled = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = "0";
            timer1.Enabled = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "现在的日期" + System.DateTime.Now.Year.ToString() + "年" +
               System.DateTime.Now.Month.ToString() + "月" + System.DateTime.Now.Day.ToString() + "日" +
               System.DateTime.Now.Hour.ToString() + ":" + System.DateTime.Now.Minute.ToString() + ":" +
               System.DateTime.Now.Second.ToString();

        }
    }
}
