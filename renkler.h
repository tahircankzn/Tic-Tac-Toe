
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void renkler(int renk){
	printf("\033[0m");
	
	if(renk == 1)
		{			
			printf("\033[1;31m");
		}
  	
  	else if(renk == 2)
		{
			printf("\033[1;33m");
		}
  
  	else if(renk == 3)
		{
			printf("\033[1;35m");
		}
		
	else if(renk == 4)
		{	
			srand(time(NULL));
			int renk_sayaci = rand()%3+1;
			printf("\033[0m");
				if(renk_sayaci == 1)
					{
						printf("\033[1;31m");
					}
	  	
	  			else if(renk_sayaci == 2)
					{
						printf("\033[1;33m");
					}
	  
	  			else if(renk_sayaci == 3)
					{
						printf("\033[1;35m");
					}
			
		}
	

}
void reset () {
  printf("\033[0m");
}
void purple (){
  printf("\033[1;35m");
}
void red (){
  printf("\033[1;31m");
}
void yellow (){
  printf("\033[1;33m");
}
void cyan(){
	printf("\033[0;36m");
}
void blue(){
	printf("\033[0;34m");
}

