using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace imageprocessing1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
            OpenFileDialog opn = new OpenFileDialog();
            opn.ShowDialog();
            pictureBox1.Image = Image.FromFile(opn.FileName);
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
        }

        private void load2ToolStripMenuItem_Click(object sender, EventArgs e)
        {

            OpenFileDialog opn = new OpenFileDialog();
            opn.ShowDialog();
            pictureBox2.Image = Image.FromFile(opn.FileName);
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
             
        }
        Bitmap bmp,bmp1,bmp2;
       
        
        private void compareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bmp = (Bitmap)pictureBox1.Image;
            bmp1 = (Bitmap)pictureBox2.Image;
            bmp2 = (Bitmap)pictureBox1.Image;
            int c = 0;
           
            for (int j = 0; j <bmp.Height; j++)
            {
                if ((j + bmp1.Height) > bmp.Height)
                    break;
                for (int i = 0; i < bmp.Width; i++)
                {
                    if ((i + bmp1.Width) > bmp.Width)
                        break;
                  
                    int m = 0, n = 0,sum=0;
                        for (int k=j; k<j+bmp1.Height; k++)
                        {
                            
                            for (int l=i; l<i+bmp1.Width; l++)    
                            {
                               
                                label3.Text=(l + " " + k + " ,"+i+" " + j +"," + n +" " +m);
                                int value1 = bmp1.GetPixel(n, m).R;
                                int value2 = bmp.GetPixel(l, k).R;
                                int value3 = bmp1.GetPixel(n, m).G;
                                int value4 = bmp.GetPixel(l, k).G;
                                int value5 = bmp1.GetPixel(n, m).B;
                                int value6 = bmp.GetPixel(l, k).B;
                                label4.Text = "value1= " + value1 + " value2= " + value2 + " value3= " + value3 + " value4= " + value4 + " value5= " + value5 + " value6= " + value6;
                                //bmp1.SetPixel(n,m, Color.FromArgb(255, 255, 255));
                              
                                sum += value1-value2+value3-value4+value5-value6;
                               // MessageBox.Show(""+sum);
                                n++;
                                if (sum != 0)
                                    break;
                              //  MessageBox.Show("" + c);
                               
                            }
                            n = 0;
                            m++;
                           
                        }
                        if (sum == 0)
                            c++;
                        
                       
                }
               
            }
            MessageBox.Show("number of match found = " + c);
        }

     

    }
}
