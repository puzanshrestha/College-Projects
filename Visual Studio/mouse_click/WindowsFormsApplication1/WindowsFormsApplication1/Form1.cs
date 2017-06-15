using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.Security.Cryptography;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Bitmap bmp1, bmp2;
        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog opn = new OpenFileDialog();
            opn.ShowDialog();
            bmp1 = (Bitmap) Image.FromFile(opn.FileName);
            pictureBox1.Image = bmp1;
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;

        }


        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog opn = new OpenFileDialog();
            opn.ShowDialog();
            bmp2 =(Bitmap) Image.FromFile(opn.FileName);
            pictureBox2.Image = bmp2;
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
        }


        private void button3_Click(object sender, EventArgs e)
        {
            
            ComparingImages.Compare(bmp1, bmp2);
        }

    }
    public class ComparingImages
    {
        public enum CompareResult
        {
            ciCompareOk,
            ciPixelMismatch,
            ciSizeMismatch
        };

        public static CompareResult Compare(Bitmap bmp1, Bitmap bmp2)
        {
           
            CompareResult cr = CompareResult.ciCompareOk;
            int flag = 0;
           
            //Test to see if we have the same size of image
            if (bmp1.Size != bmp2.Size)
            {
                cr = CompareResult.ciSizeMismatch;
                MessageBox.Show("mismatched");
            }
            else
            {
                //Convert each image to a byte array
                System.Drawing.ImageConverter ic =
                       new System.Drawing.ImageConverter();
                byte[] btImage1 = new byte[1];
                btImage1 = (byte[])ic.ConvertTo(bmp1, btImage1.GetType());
                byte[] btImage2 = new byte[1];
                btImage2 = (byte[])ic.ConvertTo(bmp2, btImage2.GetType());

                //Compute a hash for each image
                SHA256Managed shaM = new SHA256Managed();
                byte[] hash1 = shaM.ComputeHash(btImage1);
                byte[] hash2 = shaM.ComputeHash(btImage2);

                //Compare the hash values
                for (int i = 0; i < hash1.Length && i < hash2.Length; i++)
                {
                    MessageBox.Show("" + flag);
                    if (hash1[i] == hash2[i])
                    {
                        //  cr = CompareResult.ciPixelMismatch;
                        flag++;
                        MessageBox.Show("" + flag);
                       
                    }
                }
                if (flag > 10)
                {
                    MessageBox.Show("matched"+flag);
                }
                else
                {
                    MessageBox.Show("mismatched"+flag);
                }
            }
            
            return cr;
        }
    }
}