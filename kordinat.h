#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void kordinat(int satir,int sutun){
	
	int column = 40-sutun;
	int line = 10+satir;
    
    COORD coord;
    coord.X = column;
    coord.Y = line;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (!SetConsoleCursorPosition(hConsole, coord))
	    {
	        
	    }
	    
}