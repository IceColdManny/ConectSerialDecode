namespace PracticaV3
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtAlgo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtAlgo
            // 
            this.txtAlgo.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.txtAlgo.Location = new System.Drawing.Point(34, 48);
            this.txtAlgo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtAlgo.Name = "txtAlgo";
            this.txtAlgo.Size = new System.Drawing.Size(638, 36);
            this.txtAlgo.TabIndex = 0;
            this.txtAlgo.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(695, 554);
            this.Controls.Add(this.txtAlgo);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtAlgo;
    }
}

