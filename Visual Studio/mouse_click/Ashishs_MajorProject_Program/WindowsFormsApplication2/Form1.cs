using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO.Ports;
namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button2.Enabled = false;
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                comboBox1.Items.Add(port);
            }


        }

        void initialize_serial()
        {
            serialPort1.PortName = comboBox1.Text;
            if (!serialPort1.IsOpen)
            {
                serialPort1.Open();

                MessageBox.Show("serialport has been opened");
            }
            else
            {
                MessageBox.Show("Serial Port has already been opened");
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {

            initialize_serial();
            button2.Enabled = true;
            button1.Enabled = false;


        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string str;
            str = serialPort1.ReadLine();
          
            


            

            if (str != String.Empty)
            {   
                if (str[0] == 'm')
                {
                    Invoke(new Action(() => textBox1.Text = "60"));
                    Invoke(new Action(() => textBox5.Text = ("" + str.Length)));




                }
                else if (str[0] == 'c')
                {
                    Invoke(new Action(() => textBox2.Text = "50"));
                    Invoke(new Action(() => textBox6.Text = ("" + str.Length)));


                }

                else if (str[0] == 'd')
                {
                    Invoke(new Action(() => textBox3.Text = "30"));
                    Invoke(new Action(() => textBox7.Text = ("" + str.Length)));
                }

                else
                {
                    MessageBox.Show("Invalid data");
                    

                }


            }
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                char p = e.KeyChar;
                serialPort1.Write("" + p);
            }

        }
        private void button2_Click(object sender, EventArgs e)
        {
            button1.Enabled = true;
            button2.Enabled = false;
            serialPort1.Close();
        }

        double total, momo_price, chowmein_price, coke_price;

        private void button3_Click_1(object sender, EventArgs e)
        {
            

            
            total = 0;
            if (textBox5.Text!="0")
            {
                momo_price = Convert.ToDouble(textBox1.Text);
            }
            if (textBox6.Text != "0")
            {
                chowmein_price = Convert.ToDouble(textBox2.Text);
            }

            if (textBox7.Text != "0")
            {
                coke_price = Convert.ToDouble(textBox3.Text);
            }

            int  momo_qty,chowmein_qty,coke_qty;
            momo_qty = Convert.ToInt32(textBox5.Text);
            chowmein_qty = Convert.ToInt32(textBox6.Text);
            coke_qty = Convert.ToInt32(textBox7.Text);


            if (momo_qty>0)
            {
                total = total + momo_price*momo_qty;
            }

            if (chowmein_qty>0)
            {
                total = total + chowmein_price*chowmein_qty;
            }

            if (coke_qty>0)
            {
                total = total + coke_price*coke_qty;
            }

            textBox4.Text = total.ToString();

            textBox1.Text = "0";
            textBox2.Text = "0";
            textBox3.Text = "0";
            textBox5.Text = "0";
            textBox6.Text = "0";
            textBox7.Text = "0";
        }
    }
}
