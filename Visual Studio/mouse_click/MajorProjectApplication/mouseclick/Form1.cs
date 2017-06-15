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



namespace mouseclick
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                comboBox2.Items.Add(port);
            }

            dataGridView1.MultiSelect = false;

            dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            button4.Enabled = false;
            dataGridView1.Enabled = false;
            button6.Enabled = false;
            richTextBox1.Enabled = false;

           

            

        }
    
   
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(textBox1.Text, "[^0-9]"))
            {
                MessageBox.Show("Please enter only numbers.");
                textBox1.Text.Remove(textBox1.Text.Length - 1,1);
            }
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(textBox2.Text, "[^0-9]"))
            {
                MessageBox.Show("Please enter only numbers.");
                textBox2.Text.Remove(textBox2.Text.Length - 1,1);
            }
        }





        private void mouseclickfunction(object sender, MouseEventArgs e)
        {

            SizeF imagesize = pictureBox1.Image.Size;
            SizeF boxsize = pictureBox1.Size;

            float xfactor, yfactor;

            xfactor = (imagesize.Width / boxsize.Width);
            yfactor = (imagesize.Height / boxsize.Height);

            this.Cursor = new Cursor(Cursor.Current.Handle);
            Point p = this.PointToScreen(pictureBox1.Location);



            int xCoordinate =(int)Math.Ceiling( (Cursor.Position.X - p.X) * xfactor);
            int yCoordinate =-(int)Math.Ceiling((Cursor.Position.Y - p.Y-boxsize.Height) * yfactor);

            
            textBox1.Text = xCoordinate.ToString();
            textBox2.Text = yCoordinate.ToString();
            if(checkBox1.Checked)
            {
                int x_step, y_step;
                x_step = (int)(0.67 * (Convert.ToInt32(textBox1.Text)));
                y_step = (int)(0.67 * (Convert.ToInt32(textBox2.Text)));
                dataGridView1.Rows.Add(textBox1.Text, textBox2.Text, x_step.ToString(), y_step.ToString());
            }

        }









      
    

        private void pictureBox1_MouseLeave(object sender, EventArgs e)
        {
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.Cursor = Cursors.Default;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            // image filters
            open.Filter = "Image Files(*.jpg; *.png; *.jpeg; *.gif; *.bmp)|*.jpg; *.png; *.jpeg; *.gif; *.bmp";
            if (open.ShowDialog() == DialogResult.OK)
            {
                // display image in picture box
                pictureBox1.Image = new Bitmap(open.FileName);
                // image file path

            }
        }
        void serial_write_number(int b)

        {
            byte[] buffer = new byte[] { Convert.ToByte(b) };
            serialPort1.Write(buffer, 0, 1);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (dataGridView1.RowCount - 1 > 0)
            {
                string[] value_datagrid = new string[2];
                value_datagrid[0] = dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells[2].Value.ToString();
                serialPort1.Write(value_datagrid[0]);
                serial_write_number(13);

                Thread.Sleep(50);

                value_datagrid[1] = dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells[3].Value.ToString();
                serialPort1.Write(value_datagrid[1]);
                serial_write_number(13);
            }
            else
                MessageBox.Show("Error has been Occured Please Make sure that there are Coordinates in Data Grid");
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
           
            int x_step, y_step;
            x_step = (int)(0.63 * (Convert.ToInt32(textBox1.Text)));
            y_step = (int)(0.67 * (Convert.ToInt32(textBox2.Text)));
            dataGridView1.Rows.Add(textBox1.Text, textBox2.Text,x_step.ToString(),y_step.ToString());

           

            if (dataGridView1.SelectedRows.Count > 0)
                button4.Enabled = true;
            else
                button4.Enabled = false;
            


        }

        private void button4_Click(object sender, EventArgs e)
        {

            if (dataGridView1.RowCount-1 > dataGridView1.CurrentCell.RowIndex)
            {
                dataGridView1.Rows.RemoveAt(dataGridView1.SelectedCells[0].RowIndex);
                MessageBox.Show("The Selected Coordinate has Been Deleted");

            }

            else
            {
                button4.Enabled = false;
                MessageBox.Show("No valid rows has been selected");
                
            }


                //check here whether row is selected or not and remove that one

            
        }

        
     
        void initialize_serialport()
        {

            

            if (!serialPort1.IsOpen)
            {
                

                serialPort1.BaudRate = 9600;
                try
                {
                    serialPort1.PortName = comboBox2.Text;
                    serialPort1.Open();
                }
             
                catch
                {
                    MessageBox.Show("Error has been occured Please Make Sure that you have Selected proper COM port");
                    

                }

             }
            else
                MessageBox.Show("Cannot Open Serial Port ");

        }

    

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string p;
            p=serialPort1.ReadExisting();
            
            
            if (p != String.Empty)
            {
                Invoke(new Action(() => richTextBox1.AppendText(p)));
            }
        }

        private void richTextBox1_KeyPress(object sender, KeyPressEventArgs e)
        {

            char p = e.KeyChar;
            
            serialPort1.Write(""+p);
           
        }

     

        private void button5_Click(object sender, EventArgs e)
        {
            initialize_serialport();
            button2.Enabled = true;
            dataGridView1.Enabled = true;
            button5.Enabled = false;
            button6.Enabled = true;
            richTextBox1.Enabled = true;

         
        }

        private void button6_Click(object sender, EventArgs e)
        {
            button2.Enabled = false;
            dataGridView1.Enabled = false;
            button5.Enabled = true;
            serialPort1.Close();
            richTextBox1.Enabled = false;
        }






        private void button8_Click(object sender, EventArgs e)
        {
            
            if (dataGridView1.RowCount - 1 > 0)
            {
                
                int n = dataGridView1.RowCount-1;
                serialPort1.Write(n.ToString());
                serial_write_number(13);

                int i=0;
                while(true)
                {
                    
                    
                    if (i == n)
                        break;

                    serialPort1.Write(dataGridView1.Rows[i].Cells[2].Value.ToString());
                    Thread.Sleep(250);
                    serial_write_number(13);
                    
                        i++;
                        
                    
                }
                i = 0;
                while (true)
                {


                    if (i == n)
                        break;

                    serialPort1.Write(dataGridView1.Rows[i].Cells[3].Value.ToString());
                    Thread.Sleep(250);
                    serial_write_number(13);

                    i++;


                }
            }

            else
                MessageBox.Show("Error has been occured");
        }

        private void mouseenters(object sender, EventArgs e)
        {
            pictureBox1.Cursor = Cursors.Cross;
        }

        private void mouseleave(object sender, EventArgs e)
        {
            pictureBox1.Cursor = Cursors.Default;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            int n = dataGridView1.RowCount - 1;


            for (int i = n - 2; i>= 0; i--)
            {
                for (int j = 0; j<=i; j++)
                {
                    if ((Convert.ToDouble(dataGridView1.Rows[j].Cells[0].Value) * 
                        Convert.ToDouble(dataGridView1.Rows[j].Cells[0].Value)) + 
                        (Convert.ToDouble(dataGridView1.Rows[j].Cells[1].Value) * 
                        Convert.ToDouble(dataGridView1.Rows[j].Cells[1].Value)) > 
                        (Convert.ToDouble(dataGridView1.Rows[j+1].Cells[0].Value) * 
                        Convert.ToDouble(dataGridView1.Rows[j+1].Cells[0].Value)) + 
                        (Convert.ToDouble(dataGridView1.Rows[j+1].Cells[1].Value) * 
                        Convert.ToDouble(dataGridView1.Rows[j+1].Cells[1].Value)))
                    {
                        DataGridViewRow temp1, temp2;
                        temp1 = dataGridView1.Rows[j];
                        temp2 = dataGridView1.Rows[j+1];
                        
                        dataGridView1.Rows.Remove(temp1);
                        dataGridView1.Rows.Remove(temp2);

                        dataGridView1.Rows.Insert(j,temp2);
                        dataGridView1.Rows.Insert(j + 1, temp1);

                    }
                }
            }
            
            {
                
                {
                    
                }

            }
        }

      
    }
}


