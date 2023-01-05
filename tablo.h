#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void tablo(int a,int square[16],char liste[16]){
	// oyun tablosu döngü ile yapıldı
	// taploda tekrar eden kısımlar bulunarak döngü ile oluşturlması sağlandı
	
	int a1 = 1; // kaçıncı numarayı yazıdığnı bulmak için sayaç
	int square_item = 0; // sürekli artarak liste içindeki indeksdeki elamanı yazdırmak için
	
	for (int satir = 0;satir<a*3+1;satir++){  // b = satır  satır satır gezme için  
		kordinat(satir-5,-5);
		for(int i = 0;i<a;i++){ //  a = sütun satırların içini yazdırmak için
			
			if (satir==a*3)
				{
					if(i == a-1)
					{
						continue;
					}
					
					else{	
					    	printf("     |");
					}
					
		       	}
		       	
			else if (satir%3 == 1)
				{	
					if(i<a-1){
						printf("     |");
					}
			
				}
				
			else if (satir%3 == 2)
			{
				if (i<a-1){
					if(a1>9){
						
						if(liste[square_item]=='1')
							{
								printf(" %d  |",square[square_item]);
								square_item++;
								a1++;
							}
							
						else{							
							printf("  %c  |",liste[square_item]);
							square_item++;
							a1++;							
						}
						
					}
					
					
					else{
						
						if(liste[square_item]=='1')
							{							
								printf("  %d  |",square[square_item]);
								square_item++;
				  			  	a1++;
							}
							
						else{							
								printf("  %c  |",liste[square_item]);
								square_item++;
				  			  	a1++;
							}
					}

				}
				
				
				else{
					if(a1>9){
						
						if(liste[square_item]=='1')
							{								
								printf(" %d ",square[square_item]);
								square_item++;
								a1++;
							}
							
						else{
							
							printf("  %c ",liste[square_item]);
							square_item++;
							a1++;
						}
					}
					
					else{
						
						if(liste[square_item]=='1')
							{
								printf(" %d",square[square_item]);
								square_item++;
								a1++;
							}
							
						else{							
							printf(" %c",liste[square_item]);
							square_item++;
							a1++;
						}
					}
				}
			}
			
	
			else if (satir%3 == 0 && satir!=0){
				
				if(i<a-1)
					{					
						printf("_____|");
					}
				
				else{					
					printf("_____");
				}
			}
			
	}
	
	printf("\n");
		
}
	
}


// açılış animasyonu

void move1(){
	// karakter animasyonu 1
		kordinat(-7,-1);
		printf("Powered by TK | KT Software");
		kordinat(-5,-5);
		printf("   _--_     _--_\n");
		kordinat(-4,-5);
		printf("  (    )~~~(    )\n");
		kordinat(-3,-5);
		printf("   \\           /\n");
		kordinat(-2,-5);
		printf("    (  ' _ `  )\n");
		kordinat(-1,-5);
		printf("     \\       /\n");
		kordinat(0,-5);
		printf("   .__( `-' )\n");
		kordinat(1,-5);
		printf("  / !  `---' \\\n");
		kordinat(2,-5);
		printf(" /  \\         !\n"); 
		kordinat(3,-5);
		printf("!   /\\        ))\n");
		kordinat(4,-5);
		printf("!   !_\\       ).\n");
		kordinat(5,-5);
		printf(" \\    \\       ! \\\n");
		kordinat(6,-5);
		printf("  \\___/   )  /__/\n");
		kordinat(7,-5);
		printf("    \\    /   !/\n");
		kordinat(8,-5);
		printf("    /   !   /\n");
		kordinat(9,-5);
		printf("   !   /__ /___\n");
		kordinat(10,-5);
		printf("   (______)____)\n");
		kordinat(12,-5);
		printf("XOX Baslatiliyor...");
		Sleep(1000);
		system("cls");
}
void move2(){
	// karakter animasyonu 2
		kordinat(-7,-1);
		printf("Powered by TK | KT Software");
		kordinat(-5,-5);
		printf("  _--_     _--_\n");
		kordinat(-4,-5);
		printf(" (    )~~~(    )\n");
		kordinat(-3,-5);
		printf("  \\           /\n");
		kordinat(-2,-5);
		printf("   (  ' _ `  )\n");
		kordinat(-1,-5);
		printf("    \\       /\n");
		kordinat(0,-5);
		printf("     ( `-' )\n");
		kordinat(1,-5);
		printf("   _--'`---_ \n");
		kordinat(2,-5);
		printf("  /         \\___ \n");
		kordinat(3,-5);
		printf(" /   /       !  \\\n");
		kordinat(4,-5);
		printf("(   <        !__/\n");
		kordinat(5,-5);
		printf(" \\   \\      /\\\n");
		kordinat(6,-5);
		printf("  \\--/   \\ /  \\._\n");
		kordinat(7,-5);
		printf("  `.    )-   \\/  )\n");
		kordinat(8,-5);
		printf("   !   !  `.    /\n");
		kordinat(9,-5);
		printf("   /  /__   \\__/\n");
		kordinat(10,-5);
		printf("  (______)      \n");
		kordinat(12,-5);
		printf("XOX Baslatiliyor...");
		Sleep(1000);
		system("cls");	
}
void move3(){
	// karakter animasyonu 3
		kordinat(-7,-1);
		printf("Powered by TK | KT Software");
		kordinat(-5,-5);
		printf("   _--_     _--_\n");
		kordinat(-4,-5);
		printf("  (    )~~~(    ) \n");
		kordinat(-3,-5);
		printf("   \\           / \n");
		kordinat(-2,-5);
		printf("    (  ' _ `  )  \n");
		kordinat(-1,-5);
		printf("     \\       /  \n");
		kordinat(0,-5);
		printf("      ( `-' )   \n");
		kordinat(1,-5);
		printf("    .--`---'\\    \n");
		kordinat(2,-5);
		printf("   /        _>\\  \n");
		kordinat(3,-5);
		printf("  /  /-___-'   ) \n");
		kordinat(4,-5);
		printf("/'  (        _/  \n");
		kordinat(5,-5);
		printf("\\___/`------' )   \n");
		kordinat(6,-5);
		printf("    \\      `<       \n");
		kordinat(7,-5);
		printf(" ___>-_     \\   /-\\    \n");
		kordinat(8,-5);
		printf("/      `-_   `-/  /   \n");
		kordinat(9,-5);
		printf("(  \\---__/ `-_    /    \n");
		kordinat(10,-5);
		printf(" \\__)         `-_/   \n");
		kordinat(12,-5);
		printf("XOX Baslatiliyor...");
		Sleep(1000);
		system("cls");	
}
void move4(){
	// karakter animasyonu 4
		kordinat(-7,-1);
		printf("Powered by TK | KT Software");
		kordinat(-5,-5);
		printf("     _--_     _--_\n");
		kordinat(-4,-5);
		printf("    (    )~~~(    )\n");
		kordinat(-3,-5);
		printf("     \\           /\n");
		kordinat(-2,-5);
		printf("      (  ' _ `  )\n");
		kordinat(-1,-5);
		printf("       \\       /\n");
		kordinat(0,-5);
		printf("     .__( `-' )  ___\n");
		kordinat(1,-5);
		printf("    /   /`---'`-'   \\\n");
		kordinat(2,-5);
		printf("   /   /          ._/   __\n");
		kordinat(3,-5);
		printf(" /'   /.-----\\___/     /  )\n");
		kordinat(4,-5);
		printf(" \\___//          `----'   !\n");
		kordinat(5,-5);
		printf("      \\            ______/\n");
		kordinat(6,-5);
		printf("       `--_____----'\n");
		kordinat(7,-5);
		printf("         \\    /\n");
		kordinat(8,-5);
		printf("         !   !\n");
		kordinat(9,-5);
		printf("         /  /__\n");
		kordinat(10,-5);
		printf("        (______)\n");
		kordinat(12,-5);
		printf("XOX Baslatiliyor...");
		Sleep(1000);
		system("cls");	
}