using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Myform3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult dr1 = MessageBox.Show("提示对话框","我的对话框",MessageBoxButtons.YesNo,
                MessageBoxIcon.Information,MessageBoxDefaultButton.Button1,
                MessageBoxOptions.DefaultDesktopOnly);
            if (dr1 == DialogResult.Yes)
                MessageBox.Show("你单击了是！");
            else
                MessageBox.Show("你单击了否");
        }
    }
}
