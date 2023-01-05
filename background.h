#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void background(){
	
	for(int i = 0;i<30;i++){
		for(int a = 0;a<120;a++){  // yatay
			if(i==0 || i == 29)
				{
					printf("*");
				}
			else{
				
				if(a==0 || a == 119 )
					{
						printf("*");
					}
				
				else{
					if(a==0 || a == 119 )
						{
							printf("*");
						}
						
					else{
						printf(" ");
					}
				}		
			}	
		}
	}
}