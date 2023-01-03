using System;
using System.Runtime.InteropServices;

public class PInvoke
{
    [DllImport("User32.dll", CharSet = CharSet.Unicode)]
    public static extern int MessageBoxW(int handle, String message, String caption, int type);

    public static void Main()
    {
        MessageBoxW(0, "Message from Unicode", "Message", 0);
    }
}

