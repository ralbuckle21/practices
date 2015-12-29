using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Myform10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex == 0)
            {
                textBox1.Text = "窗体是windows应用程序的基本单元";
            }
            if (listBox1.SelectedIndex == 1)
            {
                textBox1.Text = "消息对话框是用MessageBox对象的show方法显示的";
            }
            if (listBox1.SelectedIndex == 2)
            {
                textBox1.Text = "在Visual C#.NET中，常用的文本空间有标签和文本框";
            }
            if (listBox1.SelectedIndex == 3)
            {
                textBox1.Text = "当只需要显示少数几种选择时，一般使用复选框和单选按钮";
            }
            if (listBox1.SelectedIndex == 4)
            {
                textBox1.Text = "许多需要滚动的控件都内嵌了其自身的滚动条";
            }
            if (listBox1.SelectedIndex == 5)
            {
                textBox1.Text = "计时器控件也称为定时器或时钟，是一个非可视控件";
            }

        }
    }
}
