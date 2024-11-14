using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PracticaV3
{
    public partial class Form1 : Form
    {
        System.IO.Ports.SerialPort Port;
        bool IsClosed = false;
        public Form1()
        {
            InitializeComponent();
            Port = new System.IO.Ports.SerialPort();
            Port.PortName = "COM12";
            Port.BaudRate = 9600;
            Port.ReadTimeout = 500;
            try
            {
                Port.Open();
            }
            catch
            {

            }
            Thread Hilo = new Thread(EscuchaSerial);
            Hilo.Start();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void EscuchaSerial()
        {
            while (!IsClosed)
            {
                try
                {
                    string cadena = Port.ReadLine();
                    txtAlgo.Invoke(new MethodInvoker(delegate
                    {
                        txtAlgo.Text = cadena;
                    }));

                }
                catch { }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            IsClosed = true;
            if (Port.IsOpen)
            {
                Port.Close();
            }
        }
    }
}