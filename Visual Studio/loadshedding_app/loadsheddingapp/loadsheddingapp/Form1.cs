using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;



namespace loadsheddingapp
{
    
    public partial class Form1 : Form
    {
        int day;

        public Form1()
        {
            InitializeComponent();
         
            
        }

        private string convert_time_format(Double time)
        {
            if (time >= 12)
                return time.ToString() + " AM";

            else
                return time.ToString() + " PM";
             

        }
        
        

        private void button1_Click(object sender, EventArgs e)
        {
            
            try
            {
                MySqlConnection con = new MySqlConnection("datasource=localhost;port=3306;database=loadshedding; username=root; password=;");
                MySqlDataAdapter data = new MySqlDataAdapter("select * from loadshedding", con);
                try
                {
                    con.Open();
                    DataSet ds = new DataSet();
                    data.Fill(ds, "loadshedding");
                    dataGridView1.DataSource = ds.Tables["loadshedding"];
                    con.Close();
                    ds.WriteXml("test.xml");
                    MessageBox.Show("Successfully Updated");

                }
                catch
                {
                    MessageBox.Show("Failed to Connect to the Server. Please try again later");
                }




            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);


            }

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            try
            {
                DataSet dsload = new DataSet();
                dsload.ReadXml("test.xml");
                dataGridView1.DataSource = dsload.Tables[0];
                day = (int)DateTime.Now.DayOfWeek;
                label1.Text = dataGridView1.Rows[day].Cells[0].Value.ToString();
                label2.Text = DateTime.Now.ToString("h:mm:ss tt");
                string time1 = dataGridView1.Rows[day].Cells[1].Value.ToString();
                string time2 = label4.Text = dataGridView1.Rows[day].Cells[2].Value.ToString();

                time1= time1.Replace(':', '.');
                string [] ar = time1.Split('-');
                label3.Text = dataGridView1.Rows[day].Cells[1].Value.ToString();
                label4.Text = dataGridView1.Rows[day].Cells[2].Value.ToString();
                Double time1_number = Convert.ToDouble(ar[0]);
                Double time2_number = Convert.ToDouble(ar[1]);
              //  label3.Text = convert_time_format(time1_number);
                


            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }


        }

        

    
    }


      
    }

