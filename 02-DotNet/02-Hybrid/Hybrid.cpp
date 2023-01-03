#include<stdio.h>
#using<MSCorLib.dll>
using namespace System;

int main(void) 
{
	printf("This Line is from Nativ CPP\n");
	Console::WriteLine("This Line is From DOTNET managed C++\n");
}

//cl.exe /clr Hybrid.cpp