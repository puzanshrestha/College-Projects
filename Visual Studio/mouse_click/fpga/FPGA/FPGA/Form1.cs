using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace FPGA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                comboBox1.Items.Add(port);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBox1.Text;
            serialPort1.BaudRate = Convert.ToInt32(textBox1.Text);
            if(!serialPort1.IsOpen)
            serialPort1.Open();

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string p;
            p = serialPort1.ReadExisting();


            if (p != String.Empty)
            {
                Invoke(new Action(() => richTextBox1.AppendText(p)));
            }
        }


        private void richTextBox1_KeyPress(object sender, KeyPressEventArgs e)
        {

            char p = e.KeyChar;

            serialPort1.Write("" + p);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }
    }
}
