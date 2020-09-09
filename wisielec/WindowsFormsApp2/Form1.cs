using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        static char[] tab;
        string podana;
        string haslo,bierzaca;
        int ilosc, i, wylosowana;
        Random random = new Random();

        public Form1()
        {
            InitializeComponent();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            podana = textBox1.Text;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {
            
        }

        private void label3_Click_1(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            podana = textBox1.Text;
            int y = 0;

            label1.Text = "";

            for (i = 0; i < ilosc; i++)
            {
                if (podana[0] == haslo[i])
                    tab[i] = podana[0];
            }
            for (i = 0; i < ilosc; i++)
            {
                label1.Text += " " + tab[i] + " ";
            }
            
            if (tab.ToString() != haslo)
                y++;


            if (y == 1)
            {
                label3.Text = "/\\";
                
            }
            if (y == 2)
            {
                label5.Text = "|";
               
            }
            if (y == 3)
            {
                label6.Text = "/";
               
            }
            if (y == 4)
            {
                label7.Text = "_";
             
            }
            if (y == 5)
            {
                label9.Text = "|";
        
            }
            if (y == 6)
            {
                label10.Text = "O";
          
            }
            if (y == 7)
            {
                label11.Text = "/|\\";
 
            }
            if (y == 8)
            {
                label12.Text = "/\\";
          
            }

            textBox1.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = "";
            wylosowana = random.Next(0, 11);
            string[] linia = System.IO.File.ReadAllLines(@"../../../wyrazy.txt");
            haslo = linia[wylosowana];
            ilosc = haslo.Length;
            tab = new char[ilosc];
            for (i = 0; i < ilosc; i++)
            {
                tab[i] = '_';
            }
            for (i = 0; i < ilosc; i++)
            {
                label1.Text +=  " " + tab[i] + " ";
            }
        }
    }
}
