#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "renkler.h"
#include "kordinat.h"
#include "background.h"
#include "tablo.h"

void PLAYERvsPLAYER(int square[144],char liste[144],int karakter);
void robot_hamlesi(int a,char liste[144]);
int checkWin(int a,char liste[144],int winer_top,char player);
void PLAYERvsCOMPUTER(int square[144],char liste[144]);
void baslangic_ekrani();
// kordinat tek satır için geçerli
int loop = -1; // hamle sayısını kontrol etmek için bir sayaç


int renk;// renk seceneği
int renk_sorgu = 1;// ilk başta sorucak sonrakilerde bu değer 0 oluca renk bilgisi sormuyacak


int main(){
	
	
	baslangic_ekrani();// başlangıç ekranı
	
	/////  gerekli arrayler oluşturuldu
	char liste[144]= {};
	int square[144]={};
	
	for(int i = 1;i<145;i++){   // liste arrayi oluşturuldu
		liste[i-1]='1';
	}
	for(int i = 1;i<145;i++){
		square[i-1]=i;          // square arrayi oluşturuldu
	}
		
		system("cls"); 
		purple();
		background(); // yıldızlardan oluşan arka plan
		
		while(1)
		{  	
				//  bu iki yer kullanıcı doğru başlatma seçeneğini seçmez ise tekrar sorulucak 
				
				
				
				char baslama_secenegi[10];
				char baslama_secenegi_kontrol_char[10] = "a";
				int baslama_secenegi_kontrol_len = 0;
				
				kordinat(-1,-5); 
				printf("      ");     //  bu yüzden girdi kısmı " " ile yani bir boşluk ile önceki yanlış girişi gözükmesi engellendi
				
				
				kordinat(-2,-15);
				purple();
				printf("XOX\n");
				
				
				
				kordinat(-1,0);
				
				reset ();
				printf("Baslatmak icin Enter tusuna basin\n");
				
			
				kordinat(0,-5);
				
				// kullanıcı enter tuşuna basarsa string ifadenin boyutu değişmez 1 de kalır ve enter tuşuna basıldığı anlaşılır
				gets(baslama_secenegi);          
				strcat(baslama_secenegi_kontrol_char,baslama_secenegi);  // strcat ile iki string birleştirildi
				baslama_secenegi_kontrol_len = strlen(baslama_secenegi_kontrol_char); // birleştirilen ifadelerin boyutu hesaplandı
				
				if(baslama_secenegi_kontrol_len > 1)
					{
						kordinat(0,-5);
						printf("    ");
						continue;
					}
				else{
					kordinat(0,-5);
					printf("    ");
					break;
				}
		}
		
		while(1){
			loop = -1;
			if(renk_sorgu == 1) // renk bilgisinin sadece oyun ilk kez açıldığında sorulması sağlandı
			{
				kordinat(-2,5);
				
				printf("Renkler : 1-Kirmizi 2-Sari 3-Mor 4-Rasgele\n");
				reset();
				

				
				kordinat(-1,10);
				printf("                                            ");
				
				kordinat(-1,0);
				scanf("%d",&renk);
				
				renk_sorgu++;
			}
			renkler(renk);
			
			
			system("cls");
			background();
			kordinat(-2,1);
			
			int oyun_secenegi;// 1vs1 , 1vsRobot
			reset();
			printf("1 - Bilgisayara Karsi | 2 - Oyuncuya Karsi\n");
			kordinat(-1,1);
			scanf("%d",&oyun_secenegi);	
			switch(oyun_secenegi){
			
				case 1: // player vs robot
					{
						system("cls");
						background();
						kordinat(-2,1);
						char karakter = 'O';
						reset();
						
					
						  // yazdırılan kısımların yok olması için boşluk ile ile üstü kapatılması sağlandı
						kordinat(-2,1);
						printf("                                                 ");
						
						
						
						kordinat(-2,-5);
						
						PLAYERvsCOMPUTER(square,liste);
						
					
						while(1){ // yeniden başlatma sorgusu
							
							kordinat(0,30);
							printf("Tekrar oynamak istermisiniz ?\n");
							kordinat(1,20);
							printf("[y] - [n] : ");
							char restart = getch();
							
							if(restart == 'n'){
								goto label;
							}
							else if(restart == 'y'){
								break;
							}
							else if(restart != 'y'){
								continue;
							}
						}
						
						
						
						
						break;
					}
				case 2:
				{  // player vs player
					
						system("cls");
						renkler(renk);
						background();
						
						kordinat(-2,1);
						int karakter;
						reset ();
						
						printf("Player 1 icin taraf seciniz\n");
						kordinat(-1,-5);
						printf("1 - X | 2 - O\n");
						
						
						
						
						while(1){
							kordinat(0,-5);
							printf("    ");
							kordinat(0,-5);
							scanf("%d",&karakter);
							if(karakter == 1 || karakter == 2){
								break;
							}
						}
						
						
						kordinat(0,-5);
						printf("             ");  // yazdırılan kısımların yok olması için boşluk ile ile üstü kapatılması sağlandı
						kordinat(-2,1);
						printf("             ");
						kordinat(-1,-5);
						printf("             ");
						
						
						kordinat(-2,-5);
						PLAYERvsPLAYER(square,liste,karakter);
						
						
						
						
						while(1){ // yeniden başlatma sorgusu
							
							kordinat(0,30);
							printf("Tekrar oynamak istermisiniz ?\n");
							kordinat(1,20);
							printf("[y] - [n] : ");
							char restart = getch();
							
							if(restart == 'n'){
								goto label; // goto ile oyunun kapanması sağlandı
							}
							else if(restart == 'y'){
								break;
							}
							else if(restart != 'y'){
								continue;
							}
						}		
						
				}

			}
			
			
	}
label:
	system("cls");
	printf("");

}


void robot_hamlesi(int a,char liste[144]){
		
			int hamle_kontrolu = 0; // bir olursa fonksiyondan çıkması sağlanıcak
			
			/////////////////////////// üçlü hamle
			if(hamle_kontrolu == 0){
			
				for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
					{
						////////////   YATAY TARAMA //////////////////////////////
						for(int t = katman;t<katman+2;t=t+1){                       
							
							if(liste[t] == 'X' && liste[t+1] == 'X' && liste[t+2] != 'X' && liste[t+2] != 'O')  // baş ve orta kısım x ise ve son kısım x yada o değilse son kısıma x yazar
								{
									liste[t+2] = 'X';
									hamle_kontrolu = 1;
									break;
								}
							else if(liste[t] == 'X' && liste[t+2] == 'X' && liste[t+1] != 'X' && liste[t+1] != 'O')
								{
									liste[t+1] = 'X';
									hamle_kontrolu = 1;
									break;
								}
								
							else if(liste[t+1] == 'X' && liste[t+2] == 'X' && liste[t] != 'X' && liste[t] != 'O')
								{
									liste[t] = 'X';
									hamle_kontrolu = 1;
									break;
								}
							////////////   YATAY TARAMA ENGELLEME //////////////////////////////
							else if(liste[t] == liste[t+1] &&   liste[t] == 'O' && liste[t+2] != 'X' && liste[t+2] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
								{
									liste[t+2] = 'X';
									hamle_kontrolu = 1;
									break;
								}
							else if(liste[t] == liste[t+2] &&   liste[t] == 'O' && liste[t+1] != 'X' && liste[t+1] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
								{
									liste[t+1] = 'X';
									hamle_kontrolu = 1;
									break;
								}
							else if(liste[t+2] == liste[t+1] &&   liste[t] == 'O' && liste[t] != 'X' && liste[t] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
								{
									liste[t] = 'X';
									hamle_kontrolu = 1;
									break;
								}
							
						}
						if(hamle_kontrolu == 1){
							break;
						}
						
					}
			}
			/////////////////////// AŞAĞI TARAMA ///////////////////////////////
			
			if(hamle_kontrolu == 0){ ////////////// hata verdiriyor
				
				for(int katman = 0; katman < a*a-2*a+1;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+a] == 'X' && liste[t+a+a] != 'X' && liste[t+a+a] != 'O')
							{
								liste[t+a+a] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
						///
						
						else if(liste[t] == 'X' && liste[t+a+a] == 'X' && liste[t+a] != 'X' && liste[t+a] != 'O')
							{
								liste[t+a] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
							
						else if(liste[t+a+a] == 'X' && liste[t+a] == 'X' && liste[t] != 'X' && liste[t] != 'O')//////////////// hate verdiriyor
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
						
						/////////////////////// AŞAĞI TARAMA ENGELLEME ///////////////////////////////
						else if(liste[t] == liste[t+a] && liste[t] == 'O' && liste[t+a+a] != 'X' && liste[t+a+a] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+a+a] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
							
						else if(liste[t] == liste[t+a+a] && liste[t] == 'O' && liste[t+a] != 'X' && liste[t+a] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+a] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
						else if(liste[t+a+a] == liste[t+a] && liste[t] == 'O' && liste[t] != 'X' && liste[t] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								
								break;
							}
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
					
				}
				
			}
			
			
			if(hamle_kontrolu == 0){
				/////////////////// SAĞ ÇAPRAZ TARAMA ///////////////////////////////////
			for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       
						
						if(liste[t] == 'X' && liste[t+a+1] == 'X' && liste[t+2*a+2] != 'X' && liste[t+2*a+2] != 'O')
							{
								liste[t+2*a+2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							//
						else if(liste[t] == 'X' && liste[t+2*a+2] == 'X' && liste[t+a+1] != 'X' && liste[t+a+1] != 'O')
							{
								liste[t+a+1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+a+1] == 'X' && liste[t+2*a+2] == 'X' && liste[t] != 'X' && liste[t] != 'O')
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							/////////////////// SAĞ ÇAPRAZ TARAMA ENGELLEME ///////////////////////////////
						else if(liste[t] == liste[t+a+1] &&  liste[t] == 'O' && liste[t+2*a+2] != 'X' && liste[t+2*a+2] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+2*a+2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t] == liste[t+2*a+2] &&  liste[t] == 'O' && liste[t+a+1] != 'X' && liste[t+a+1] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+a+1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+2*a+2] == liste[t+a+1] &&  liste[t] == 'O' && liste[t] != 'X' && liste[t] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								break;
							}
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
				}
				
			}
			//////////////////// SOL ÇAPRAZ ///////////////////////////////
			if(hamle_kontrolu == 0){
				
				for(int katman = a-1;katman<a*a;katman = katman + a)
				{
					for(int t = katman;t>a-katman;t=t-1){                       
						
						if(liste[t] == 'X' && liste[t+a-1] == 'X' && liste[t+2*a-2] != 'X' && liste[t+2*a-2] != 'O')
							{
								liste[t+2*a-2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							//
						else if(liste[t] == 'X' && liste[t+2*a-2] == 'X' && liste[t+a-1] != 'X' && liste[t+a-1] != 'O')
							{
								liste[t+a-1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+a-1] == 'X' && liste[t+2*a-2] == 'X' && liste[t] != 'X' && liste[t] != 'O')
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								break;
							}	
						//////////////////// SOL ÇAPRAZ ENGELLEME ///////////////////////////////
							
						else if(liste[t] == liste[t+a-1]  && liste[t] == 'O' && liste[t+2*a-2] != 'X' && liste[t+2*a-2] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+2*a-2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t] == liste[t+2*a-2]  && liste[t] == 'O' && liste[t+a-1] != 'X' && liste[t+a-1] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t+a-1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+2*a-2] == liste[t+a-1]  && liste[t] == 'O' && liste[t] != 'X' && liste[t] != 'O')// bu kısmım bloklama kısmı ve buranında 3 farklı durumu olucak yazmayı unutma
							{
								liste[t] = 'X';
								hamle_kontrolu = 1;
								break;
							}
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
				}
				
			}
			/////////////////////////// ikili hamle
			if(hamle_kontrolu == 0){
				for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
				{
					////////////   YATAY TARAMA //////////////////////////////
					for(int t = katman;t<katman+2;t=t+1){                       
						
						if(liste[t] == 'X' && liste[t+1] != 'X' && liste[t+1] != 'O')  // baş ve orta kısım x ise ve son kısım x yada o değilse son kısıma x yazar
							{
								liste[t+2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+1] == 'X' && liste[t+2] != 'X' && liste[t+2] != 'O')
							{
								liste[t+2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+2] == 'X' && liste[t+1] != 'X' && liste[t+1] != 'O')
							{
								liste[t+1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							
						
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
				}
			}
			
			
			
				
			/////////////////////// AŞAĞI TARAMA ///////////////////////////////
			if(hamle_kontrolu == 0){
				
				for(int katman = 0;katman < a*a-2*a+1;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+a] != 'X' && liste[t+a] != 'O')
							{
								liste[t+a] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						///
						
						else if(liste[t+a] == 'X' && liste[t+a+a] != 'X' && liste[t+a+a] != 'O')
							{
								liste[t+a+a] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							
						else if(liste[t+a+a] == 'X' && liste[t+a] != 'X' && liste[t+a] != 'O')
							{
								liste[t+a] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							
						
						
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
				}
				
			}
			
			if(hamle_kontrolu == 0){
				/////////////////// SAĞ ÇAPRAZ TARAMA ///////////////////////////////////
			for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       
						
						if(liste[t] == 'X' && liste[t+a+1] != 'X' && liste[t+a+1] != 'O')
							{
								liste[t+a+1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							//
						else if(liste[t+a+1] == 'X' && liste[t+2*a+2] != 'X' && liste[t+2*a+2] != 'O')
							{
								liste[t+2*a+2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+2*a+2] == 'X' && liste[t+a+1] != 'X' && liste[t+a+1] != 'O')
							{
								liste[t+a+1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
					
				}
				
			}
			//////////////////// SOL ÇAPRAZ ///////////////////////////////
			if(hamle_kontrolu == 0){
				for(int katman = a-1;katman<a*a;katman = katman + a)
				{
					for(int t = katman;t>a-katman;t=t-1){                       
						
						if(liste[t] == 'X' && liste[t+a-1] != 'O' && liste[t+a-1] != 'X')
							{
								liste[t+a-1] = 'X';
								hamle_kontrolu = 1;
								break;
							}
							//
						else if(liste[t+a-1] == 'X' && liste[t+2*a-2] != 'O' && liste[t+2*a-2] != 'X')
							{
								liste[t+2*a-2] = 'X';
								hamle_kontrolu = 1;
								break;
							}
						else if(liste[t+2*a-2] == 'X' && liste[t+a-1] != 'O' && liste[t+a-1] != 'X')
							{
								liste[t+a-1] = 'X';
								hamle_kontrolu = 1;
								break;
							}	
						
					}
					if(hamle_kontrolu == 1){
						break;
					}
					
				}
				
			}
			
			
			
			if(hamle_kontrolu == 0){
				srand(time(NULL));
				int hamle = rand()%a+1;
				if(liste[hamle] != 'O' && liste[hamle] != 'X')
					{
						liste[hamle] = 'X';
						
					} 
			}
			
			
}
int checkWin(int a,char liste[144],int winer_top,char player){
	reset ();
	
	
	struct scor{
		int player1_skor;
		int player2_skor;
	}game;
	
	game.player1_skor = 0; // O
	game.player2_skor = 0; // X

	
	if(player == 'X'){
				////////////   YATAY TARAMA //////////////////////////////
			for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+1] == 'X' && liste[t+2] == 'X')
							{
								game.player2_skor = game.player2_skor + 1;
							}
						
						if(liste[t] == liste[t+1] && liste[t+1] == liste[t+2] && liste[t] == 'O')
							{
								game.player1_skor = game.player1_skor + 1;
							}
					}
					
				}
			/////////////////////// AŞAĞI TARAMA ///////////////////////////////
			for(int katman = 0;katman<a*a-2*a+1;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+a] == 'X' && liste[t+a+a] == 'X')
							{
								game.player2_skor = game.player2_skor + 1;
							}
							
						if(liste[t] == liste[t+a] && liste[t] == liste[t+a+a] && liste[t] == 'O')
							{
								game.player1_skor = game.player1_skor + 1;
							}
					}
					
				}
			
			/////////////////// SAĞ ÇAPRAZ TARAMA ///////////////////////////////////
			for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
				{
					for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+a+1] == 'X' && liste[t+2*a+2] == 'X')
							{
								game.player2_skor = game.player2_skor + 1;
							}
						if(liste[t] == liste[t+a+1] && liste[t] == liste[t+2*a+2] && liste[t] == 'O')
							{
								game.player1_skor = game.player1_skor + 1;
							}
					}
					
				}
			/////////////////// SOL ÇAPRAZ TARAMA ///////////////////////////////////
			for(int katman = a-1;katman<a*a;katman = katman + a)
				{
					for(int t = katman;t>a-katman;t=t-1){                       //  6  7  8
						
						if(liste[t] == 'X' && liste[t+a-1] == 'X' && liste[t+2*a-2] == 'X')
							{
								game.player2_skor = game.player2_skor + 1;
							}
							
						if(liste[t] == liste[t+a-1] && liste[t] == liste[t+2*a-2] && liste[t] == 'O')
							{
								game.player1_skor = game.player1_skor + 1;
							}
					}
					
				}
	}
	else{
					////////////   YATAY TARAMA //////////////////////////////
					for(int katman = 0;katman<a*(a-1)+2;katman = katman + a)
						{
							for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
								
								if(liste[t] == 'O' && liste[t+1] == 'O' && liste[t+2] == 'O')
									{
										game.player2_skor = game.player2_skor + 1;
									}
									
								if(liste[t] == liste[t+1] && liste[t+1] == liste[t+2] && liste[t] == 'X')
									{
										game.player1_skor = game.player1_skor + 1;
									}
							}
							
						}
					/////////////////////// AŞAĞI TARAMA ///////////////////////////////
					for(int katman = 0;katman<a*a-2*a+1;katman = katman + a)
						{
							for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
								
								if(liste[t] == 'O' && liste[t+a] == 'O' && liste[t+a+a] == 'O')
									{
										game.player2_skor = game.player2_skor + 1;
									}
								
								if(liste[t] == liste[t+a] && liste[t] == liste[t+a+a] && liste[t] == 'X')
									{
										game.player1_skor = game.player1_skor + 1;
									}
							}
							
						}
					
					/////////////////// SAĞ ÇAPRAZ TARAMA ///////////////////////////////////
					for(int katman = 0;katman<a*(a-1)+2;katman = katman + a){
						for(int t = katman;t<katman+2;t=t+1){                       //  6  7  8
							
							if(liste[t] == 'O' && liste[t+a+1] == 'O' && liste[t+2*a+2] == 'O')
								{
									game.player2_skor = game.player2_skor + 1;
								}
								
							if(liste[t] == liste[t+a+1] && liste[t] == liste[t+2*a+2] && liste[t] == 'X')
								{
									game.player1_skor = game.player1_skor + 1;
								}
						}
						
					}
					/////////////////// SOL ÇAPRAZ TARAMA ///////////////////////////////////
					for(int katman = a-1;katman<a*a;katman = katman + a){
						for(int t = katman;t>a-katman;t=t-1){                       //  6  7  8
							
							if(liste[t] == 'O' && liste[t+a-1] == 'O' && liste[t+2*a-2] == 'O')
								{
									game.player2_skor = game.player2_skor + 1;
								}
								
							if(liste[t] == liste[t+a-1] && liste[t] == liste[t+2*a-2] && liste[t] == 'X')
								{
									game.player1_skor = game.player1_skor + 1;
								}
						}
						
					}
	}
	/////////////////////////////////////////////////////////////////////
	
	
	loop = loop + 1;
	
	
	
	
	if(loop >= winer_top){
		
		
		if(game.player1_skor > game.player2_skor)
			{
				return 1;
			}
			
		else if(game.player2_skor > game.player1_skor)
			{	
				return 2;
			}
		
		else{
			return 0;	
			}
			
		}
		
	else{
		return 3;// rasgele değer göndermesin diye
	}
		
		
}



void PLAYERvsCOMPUTER(int square[144],char liste[144]){
	
	char player1 = 'O';
	char player2 = 'X'; // ROBOT
	int a ;
	while(1){
		system("cls");
		renkler(renk);
		background();
		reset();
		
		kordinat(-2,-5);
		
		printf("tablo boyutu seciniz : ");

		scanf("%d",&a);
		if(a>=3){
			break;
		}
	}

	int winer_top = a*a; // kaç tur oynanılacağı
	int choice;
	int player = 1;
	
	

		
	while(1){
		
			
			
			//kordinat();
			system("cls");
			background();
			
			///////////////////////////////////////////////////////////////////////////////
			
			int winner = checkWin(a,liste,winer_top,player1);
		
		
		
		
			
				if(winner == 1)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("computer kazandi\n");
					
					break;
				}
				else if(winner == 2)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("player 1 kazandi\n");
					
					break;
				}
			
				else if(winner == 0){
					system("cls");
					background();
					kordinat(-7,-10);
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("berabere\n");
					
					break;
				}	
			///////////////////////////////////////////////////////////////////////////////
			
			tablo(a,square,liste);
			
			kordinat(-7,-10);
			
			if(player ==1 )
				{
						printf("Player 1 : ");
						scanf("%d",&choice); 
						
						if(choice > a*a)
							{
								system("cls");
								background();
								continue;
							}
							
						else if(liste[choice -1]!='1')
							{
								system("cls");
								background();
								continue;
							}
							
						else
						{
							liste[choice-1]='O';
							player = 2;
							
						}
						//player = 2;
				}
			else{
				
				robot_hamlesi(a,liste);	
				player = 1;			
			}
			
			
		}
		
		
		
	
	

	for(int i = 1;i<145;i++)
		{   
			liste[i-1]='1';
		}
	
	for(int i = 1;i<145;i++)
		{
			square[i-1]=i;
		}
}
void PLAYERvsPLAYER(int square[144],char liste[144],int karakter){
	
	char player1 = 'O';
	char player2 = 'X';
	
	if(karakter == 1)
	{
		player1 = 'X';
		player2 = 'O';
	}
	
	
	int a ;
	while(1){
		system("cls");
		renkler(renk);
		background();
		reset();
		
		kordinat(-2,-5);
		
		printf("tablo boyutu seciniz : ");

		scanf("%d",&a);
		if(a>=3){
			break;
		}
	}
	
	
	int winer_top = a*a; // kaç tur oynanılacağı 5
	int choice;
	int player = 1;
	
	while(1){
		
		
		

		int winner = checkWin(a,liste,winer_top,player1);
		
		
		if(player1 == 'O')
		{
			
				if(winner == 1)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("player 2 kazandi\n");
					
					break;
				}
				else if(winner == 2)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("player 1 kazandi\n");
					
					break;
				}
			
				else if(winner == 0){
					system("cls");
					background();
					kordinat(-7,-10);
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("berabere\n");
					
					break;
				}	
		}
		
		
		else
		{
			if(winner == 1)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("player 2 kazandi\n");
					
					break;
				}
			else if(winner == 2)
				{
					system("cls");
					background();
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("player 1 kazandi\n");
					
					break;
				}
				
			else if(winner == 0)
				{
					system("cls");
					background();
					kordinat(-7,-10);
					tablo(a,square,liste);
					kordinat(-7,-10);
					printf("berabere\n");
					
					break;
				}
		}
			
		
		
		
		
	while(1){
		
					
			
			system("cls");
			background();
			

			tablo(a,square,liste);
			
			kordinat(-7,-10);
			
			printf("Player %d : ",player);
			scanf("%d",&choice); 
			
			if(choice > a*a)
				{
					system("cls");
					background();
					continue;
				}
				
			else if(liste[choice -1]!='1')
				{
					system("cls");
					background();
					continue;
				}
				
			else
			{
				break;
			}
			
		}
		
		
		
		
		if(player == 1)
			{
				liste[choice -1]=player1;
				player = 2;
			}
		
		else
			{
				liste[choice -1]=player2;
				player = 1;
			}
		
	
}
	
		
	for(int i = 1;i<145;i++)
		{   
			liste[i-1]='1';
		}
	
	for(int i = 1;i<145;i++)
		{
			square[i-1]=i;
		}
}

void baslangic_ekrani(){
	system("cls");
	yellow();
	background();
	move1();
	red();
	background();
	move2();
	cyan();
	background();
	move3();
	blue();
	background();
	move4();
	yellow();
	background();
	move3();
	red();
	background();
	move2();
	kordinat(2,3);
	printf("UYARI !! Hamle sayisi tablo boyutu ile sinirlidir\n");
	kordinat(3,-3);
	printf("Tablo dolduktan sonra oyun biter");
	kordinat(5,-15);
	printf("5\n");
	Sleep(1000);
	kordinat(5,-15);
	printf("4\n");
	Sleep(1000);
	kordinat(5,-15);
	printf("3\n");
	Sleep(1000);
	kordinat(5,-15);
	printf("2\n");
	Sleep(1000);
	kordinat(5,-15);
	printf("1");
	Sleep(1000);
	
	
	
}

