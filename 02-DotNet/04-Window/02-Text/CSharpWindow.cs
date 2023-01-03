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

}
