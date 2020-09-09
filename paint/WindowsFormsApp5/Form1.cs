using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        int x= 150;
        int y = 350;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
         
            Graphics nowy = panel1.CreateGraphics();
            SolidBrush pen1 = new SolidBrush(Color.Green);
            nowy.FillRectangle(pen1,y , x-25 , 25, 25);
            x -= 25;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics nowy = panel1.CreateGraphics();
            SolidBrush pen1 = new SolidBrush(Color.Green);
            nowy.FillRectangle(pen1, y, x+25, 25, 25);
            x += 25;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics nowy = panel1.CreateGraphics();
            SolidBrush pen1 = new SolidBrush(Color.Green);
            nowy.FillRectangle(pen1, y-25, x, 25, 25);
            y -= 25;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics nowy = panel1.CreateGraphics();
            SolidBrush pen1 = new SolidBrush(Color.Green);
            nowy.FillRectangle(pen1, y + 25, x, 25, 25);
            y += 25;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            panel1.Refresh();
             x = 150;
             y = 350;
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            
        }
    }
}
