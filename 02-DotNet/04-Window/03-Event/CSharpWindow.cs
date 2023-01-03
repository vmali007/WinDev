using System;
using System.Windows.Forms;
using System.Drawing;

public class CSharpWindow:Form
{
    public static void Main()
    {
        Application.Run(new CSharpWindow());
    }

    public CSharpWindow()
    {
        Text = "MyCSharpWindow"; //MessageBox Caption
        BackColor = Color.Black;
        ResizeRedraw = true;
        Width = 800;
        Height = 600;

        this.KeyDown += new KeyEventHandler(MyKeyDown);
        this.MouseDown += new MouseEventHandler(MyMouseDown);
    }

    protected override void OnPaint(PaintEventArgs pea) //WMPaint
    {
        Graphics grfx = pea.Graphics;

        StringFormat strfmt = new StringFormat();
        strfmt.Alignment = StringAlignment.Center;
        strfmt.LineAlignment = StringAlignment.Center;

        grfx.DrawString("Hello World!!!",
            Font,
            new SolidBrush(Color.Green),
            ClientRectangle,
            strfmt
            );
    }

    public void MyKeyDown(Object sender, KeyEventArgs e)
    {
        MessageBox.Show("A key is Pressed");
    }

    public void MyMouseDown(Object sender, MouseEventArgs e)
    {
        MessageBox.Show("A Mouse is clicked");
    }
}
