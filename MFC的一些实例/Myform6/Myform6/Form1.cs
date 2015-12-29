using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Myform6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string time1 = System.DateTime.Now.ToString();
            string t1 = "";
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
                t1 += this.checkedListBox1.CheckedItems[i] + "\n";
            if (t1 == "")
                MessageBox.Show("你没有选择你喜欢的图书，请选择",time1 );
            else
                MessageBox.Show("你选择的图书是\n"+t1,time1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
