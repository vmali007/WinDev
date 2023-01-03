using System;
using System.Runtime.InteropServices;

public class PInvoke
{
    [DllImport("User32.dll")]
    public static extern int MessageBoxA(int handle, String message, String caption, int type);

    public static void Main()
    {
        MessageBoxA(0, "Message from Ansi", "Message", 0);
    }
}

