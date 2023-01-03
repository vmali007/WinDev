using System;
using System.Windows.Forms;

public class CSharpWindow:Form
{
    public static void Main()
    {
        Application.Run(new CSharpWindow());
    }

    public CSharpWindow()
    {
        Text = "MyCSharpWindow"; //MessageBox Caption
        BackColor = System.Drawing.Color.Black;
        ResizeRedraw = true;
    }

}
