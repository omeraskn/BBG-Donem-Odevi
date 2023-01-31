#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){

	int i, j, k, karmailk, karmaiki, temp, zaman, counter3=0, memorytrue, sat1, sut1, sat2, sut2;
	int gameover,round, samenumber, samenumber1, pcnumber, gamerscore=0, pcscore= 0;
	int a, b, c, e, d; 																			// e= zorluk  d= oyun baþlatma
	int u, o, s, l= 0;																			//koordinatlarý hatýrlama
	int sayi[8][8];
	char yildiz[8][8];
	char car, car1;
	int memory3[16], memory4[16], memory5[16];
	int numaralar1[16]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
	int numaralar2[36]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18};
	int numaralar3[64]= {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32};

	printf("\t\t\t\tBASLA\n\n \t\tLutfen istediginiz zorluk seviyesinin numarisini yaziniz:\n\n\t\t\t\t1.Kolay\n\n\t\t\t\t2.Orta\n\n\t\t\t\t3.Zor\n\n\t\tBu bir hafiza oyunudur ve sectiginiz zorluga gore size bazi sayilar gosterilecektir.\n\t\tKolay modda 4x4luk, orta modda 6x6lik ve zor modda 8x8lik matrisler size verilecektir.\n\t\t Bilgisayarin hatirlama miktari da zorluga gore 2,6,16 olarak degismektedir.\n ");
	srand(time(NULL));																			
	printf("\nZorluk seviyenizin numarasi:");													// giris, menu ve zorluk secýmý
	scanf("%d", &e);	
	if(e==1){
		printf("\t\t\tOyun modu kolay olarak ayarlandi."); 										//oyun modu secildi
    }
	else if(e==2){
		printf("\t\t\tOyun modu orta olarak ayarlandi.");		
	}
	else if(e==3){
		printf("\t\t\tOyun modu zor olarak ayarlandi.");
	}
	else if(e!=1 && e!=2 && e!=3){
		printf("\t\tLutfen gecerli bir sayi girin.\n");						 		 // yanlýs yazýlmasý durumunda 2. bir sanss
		printf("Zorluk seviyenizin numarasi:");
		scanf("%d", &e);
			if(e==1){
				printf("\t\tOyun modu kolay olarak ayarlandi.\n");
    		}
			else if(e==2){
				printf("\t\tOyun modu orta olarak ayarlandi.\n");
			}
			else if(e==3){
				printf("\t\tOyun modu zor olarak ayarlandi.\n");
			}
	}

	printf("\n\n\t\t\tOyuna baslamak icin ENTER'a basin.");
	scanf("%c", &car1);
	scanf("%c", &car);
	system("cls");																	// oyun icin bos ekran
		
	if(e==1){																  	 	// KOLAY MODDA MATRÝS

		for(i=0; i<16; i++){
			karmailk= (rand() % 16);												//sayýlarý karma
   	    	karmaiki= (rand() % 16);	
			temp= numaralar1[karmailk];
   	    	numaralar1[karmailk]=numaralar1[karmaiki];
   	    	numaralar1[karmaiki]= temp;
   		}
		for(j=0; j<16; j++){  														// sayý matrisini yazdýr
			if(j%4==0){
			printf("\n\n\t\t");
			}
			  printf("\t%d", numaralar1[j]);
		}
		printf("\n\n\t\tSayilari aklinizda tutmaya calisin \n\t\t\t 2 saniyeniz var.\n\n ");
		for(zaman=2; zaman>0; zaman--){
			sleep(1);	
			printf("\n\n\t\t\t %d", zaman);		
		}
		sleep(1);
		system("cls");
		
	
		a=4;
		b=4; 
		for(i=0; i<4; i++){ 														//  yýldýz matrisi olusturma
			printf("\t\t\t\t");
			for(j=0; j<4; j++){
				yildiz[i][j]= '*';				
	//			printf("\t%c", yildiz[i][j]);
			}
		}	
		
	while(pcscore<5 && gamerscore<5 && !(gamerscore==4 && pcscore==4)){	
		
		samenumber=1;
		samenumber1=1;
		while(samenumber==samenumber1){												// OYUNCU SÝRASÝ
			
			printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore);
			for(i=0; i<4; i++){ 													// sayýlarý görünmeyen yýldýz matrisi verme
				printf("\n\n\t\t\t\t");
				for(j=0; j<4; j++){				
					printf("\t%c", yildiz[i][j]);
				}
			}	  		  
			printf("\n\n\t\tBelirtlien yildiz matrisinin icinde rastgele dagitilmis sayilar bulunmaktadir.\n\t\t\t\tLutfen ilk tahmininizin satir ve sutun numarasini girin.\n\n\t\tTur %d\n", round);
			i=0;
			j=0;
			d=0;
			printf("\nSatir numarasi\n(0,1,2,3)"); 									// kullanýcýdan ilk kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi\n(0,1,2,3)");
			scanf("%d", &j);
			u= i;
			o= j;
			
			d=(4*i+j);
			samenumber=numaralar1[d];
				for(a=0; a<4; a++){													// ilk kartý yýldýz matrisi içinde gösterme
					printf("\n");
					for(b=0; b<4; b++){
						if(a==i && b==j){
							printf("\t%d", samenumber);
						}				
						else{
							printf("\t%c", yildiz[a][b]);		
						}		
					}
				}
			
			
			printf("\n\nIkinci kartin satir ve sutun numarisini giriniz.\n");
			i=0;
			j=0;
			d=0;
			printf("\nSatir numarasi:"); 											// kullanýcýdan ikinci kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi:");
			scanf("%d", &j);
			
			d=(4*i+j);
			samenumber1=numaralar1[d];
				for(a=0; a<4; a++){						
					printf("\n");
					for(b=0; b<4; b++){
						if(a==i && b==j){
							printf("%d\t", samenumber1);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				}
			if(samenumber==samenumber1){											// kullanýcýnýn tahmini doðru mudur
				round++;
				gamerscore++;
				printf("\n\t\tTahmininiz dogru!!\n\t\tTahmin yapmak icin bir cift hak kazandinz!!\n\t\tTur %d", round);		
				yildiz[u][o]= '-';										 			//  bilinen noktalarý - ile deðiþmek
				yildiz[i][j]= '-';
				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
			}
			else{
				printf("\n\t BILEMEDIN!!\n\tSIRA BILGISAYARDA\n\tTur %d", round);
				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
			}
		}	
		
		samenumber=1;
		samenumber1=1;	
		while(samenumber==samenumber1){ 
			printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore); 										   // BILGISAYARIN OYUN SIRASI !!!!
		
		s= (rand() % 4);																				  // bilinmemis random deger alma
		l= (rand() % 4);
			while(yildiz[s][l]== '-' || (s==i && l==j) || (s==u && l==o)){
				s= (rand() % 4);
				l= (rand() % 4);		
			}
		
		karmailk=(4*s+l);
		samenumber= numaralar1[karmailk];

		for(a=0; a<4; a++){						
			printf("\n\n\t");
			for(b=0; b<4; b++){
				if(a==s && b==l){
					printf("%d\t", numaralar1[karmailk]);
				}				
				else{
					printf("%c\t", yildiz[a][b]);		
				}		
			}
		}
		printf("\nBilgisayarin ilk tahmini : %d", numaralar1[karmailk] );
		sleep(2);
		printf("\n\n"); 		
		if(numaralar1[karmailk]== numaralar1[4*i+j]){
			for(a=0; a<4; a++){						
				printf("\n\n\t");
				for(b=0; b<4; b++){																 // EGER ILK TAHMIN OYUNCUNUN IKINCI TAHMINIYLE AYNIYSA
					if(a==i && b==j){
						printf("%d\t", numaralar1[4*i+j]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			} 
			round++;
			printf("\nTur %d\n\n", round);
			pcscore++;
			printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \nBilgisayarin puani: %d", pcscore);	
			printf("\n Sira tekrar bilgisayarda ");	
			yildiz[s][l]= '-';
			samenumber1=numaralar1[4*i+j];					 							  	 //  bilinen noktalarý - ile deðiþmek
			yildiz[i][j]= '-';
//			scanf("%c", &car);
			scanf("%c", &car1);
			system("cls");	
		}
		else if(numaralar1[karmailk]== numaralar1[4*u+o]){
			samenumber1= numaralar1[4*u+o];
			for(a=0; a<4; a++){						
				printf("\n\n\t");												 // EGER ILK TAHMIN OYUNCUNUN ILK TAHMINIYLE AYNIYSA
				for(b=0; b<4; b++){
					if(a==u && b==o){
						printf("%d\t", numaralar1[4*u+o]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			} 
			round++;
			printf("\nTur %d\n\n", round);
			pcscore++;
			printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \nBilgisayarin puani: %d", pcscore);	
			printf("\n Sira tekrar bilgisayarda ");	
			yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile deðiþmek
			yildiz[u][o]= '-';
//			scanf("%c", &car);
			scanf("%c", &car1);
			system("cls");	
		}
		
		else if(numaralar1[karmailk]!= numaralar1[4*u+o] || numaralar1[karmailk]!= numaralar1[4*i+j]){

			c= (rand() % 4);																				  // bilinmemis random deger alma
			e= (rand() % 4);
				while(yildiz[c][e]== '-' || (c==i && e==j) || (c==u && e==o) || (c==s && e==l)){
					c= (rand() % 4);
					e= (rand() % 4);		
				}
		
			karmaiki=(4*c+e);
			samenumber1= numaralar1[karmaiki];
			printf("\n\n");														 // EGER HAFIZA HICBIR KARTLA TUTUSMAZSA IKINCI TAHMIN
			for(a=0; a<4; a++){						
			printf("\n\n\t");
				for(b=0; b<4; b++){
					if(a==c && b==e){
						printf("%d\t", numaralar1[karmaiki]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			}	
			printf("\nBilgisayarin ikinici tahmini : %d", numaralar1[karmaiki] );
			round++;
			printf("\nTur %d\n\n", round);
			if(samenumber==samenumber1){
				pcscore++;
				round++;
				printf("\n\n\t\tBilgisayar bir adet dogru eslesme yapti.\n Bilgisayarin puani: %d", pcscore);	
				printf("\n\t\t Sira tekrar bilgisayarda ");	
				yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile deðiþmek
				yildiz[c][e]= '-';
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");	
			}
			else{
				printf("\n Bilgisayar sirasini kaybetti sira size geciyor. ");	
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
				
			} 		    			                						
		}	
		}	
	}
	printf("\n\n\t\t\tOyun tamamlandi\n");
	
	if(gamerscore>=4){
						system("cls");
		printf("\t\t\tKAZANAN OYUNCU!!\n");
	}
	else if(pcscore>=4){
						system("cls");
		printf("\t\t\tKAZANAN BILGISAYAR\n");
	}
	else if(pcscore==4 && gamerscore==4){
						system("cls");
		printf("\t\t\tOYUN BERABERE TAMAMLANDI\n");
		
	}
	printf("\n");
	for(a=0; a<4; a++){						
		printf("\n\t");
		for(b=0; b<4; b++){
			printf("%d\t", numaralar1[4*a+b]);
		}
	}
	printf("\t\t\tOynanilan tur sayisi: %d", round);
	scanf("%c", car);
  	}
	  	 	
	else if(e==2){ 																  
		
		for(i=0; i<36; i++){
			karmailk= (rand() % 36); 											   // ORTA MODDA MATRÝS
   	   		karmaiki= (rand() % 36);	
			temp= numaralar2[karmailk];
   	   		numaralar2[karmailk]=numaralar2[karmaiki];
   	   		numaralar2[karmaiki]= temp;
   		}
		
		for(j=0; j<36; j++){ 											      	  // sayý matrisini yazdýr	
				if(j%6==0){
				printf("\n\n\t");
				}
			    printf("\t%d", numaralar2[j]);
		}	
		
		printf("\n\n\t\tSayilari aklinizda tutmaya calisin \n\t\t\t 3 saniyeniz var.\n\n ");
		for(zaman=3; zaman>0; zaman--){
			sleep(1);	 
			printf("\n\n\t\t\t %d", zaman);		
		}
		sleep(2);
		system("cls");
		
		for(i=0; i<6; i++){
			printf("\t\t\t");
			for(j=0; j<6; j++){
				yildiz[i][j]= '*';
			}
		}		
	while(gamerscore<10 && pcscore<10 && !(gamerscore==9 && pcscore==9)){			
		samenumber=1;
		samenumber1=1;
		while(samenumber==samenumber1){
			printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore);
		 				
			for(i=0; i<6; i++){
				printf("\n\n\t\t\t");
				for(j=0; j<6; j++){
				printf("\t%c", yildiz[i][j]);
				}
			}
	
		printf("\n\n\t\tBelirtlien yildiz matrisinin icinde rastgele dagitilmis sayilar bulunmaktadir.\n\t\t\t\tLutfen ilk tahmininizin satir numarasini girin. \n\n\t\tTur %d\n", round);
			i=0;
			j=0;		
			d=0;
			printf("\nSatir numarasi\n(0,1,2,3,4,5)"); 					 			// kullanýcýdan ilk kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi\n(0,1,2,3,4,5)");
			scanf("%d", &j);
		
			d=(6*i+j);
			samenumber=numaralar2[d];
				for(a=0; a<6; a++){													// ilk kartý yýldýz matrisi içinde gösterme
					printf("\n");
					for(b=0; b<6; b++){
						if(a==i && b==j){
							printf("%d\t", samenumber);
						}				
						else{
							printf("*\t");		
						}		
					}
				}			
			u= i;
			o= j;
			
			printf("\n\nIkinci kartin satir ve sutun numarisini giriniz.\n");
			i=0;
			j=0;
			d=0;
			printf("\nSatir numarasi:"); 											// kullanýcýdan ikinci kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi:");
			scanf("%d", &j);
			s= i;
			l= j;
			
			d=(6*i+j);
			samenumber1=numaralar2[d];
				for(a=0; a<6; a++){						
					printf("\n");
					for(b=0; b<6; b++){
						if(a==i && b==j){
							printf("%d\t", samenumber1);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				}
			if(samenumber==samenumber1){																	// kullanýcýnýn tahmini doðru mudur
				printf("\n\t\tTahmininiz dogru!!\n\t\tTahmin yapmak icin bir cift hak kazandinz!!");
				yildiz[u][o]= '-'; 																			// bilinenleri - olarak güncelleme
				yildiz[s][l]= '-';					
						
				scanf("%c", &car);
				round++;
				gamerscore++;
				scanf("%c", &car1);
				system("cls");
			}
			else{
				printf("\n\t\t BILEMEDIN!!\n\t\tSIRA BILGISAYARDA");
				memory3[counter3]= sayi[u][o];
				memory4[counter3]= u;
				memory5[counter3]= o; 																		// TAHMINLER
				counter3++;
				
				memory3[counter3]= sayi[s][l];
				memory4[counter3]= s;
				memory5[counter3]= l;
				counter3++;
				if(counter3>=6){
					counter3=0;
				}
					
				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
			}
		}
	
		samenumber=1;
		samenumber1=1;																							// BILGISAYARIN OYUN SIRASI
		while(samenumber==samenumber1){
			printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore);
		 
			s= (rand() % 6);																				    // bilinmemis random deger alma
			l= (rand() % 6);
				while(yildiz[s][l]== '-' || (s==i && l==j), (s==u && l==o)){
					s= (rand() % 6);
					l= (rand() % 6);		
				}	
			karmailk=(6*s+l);
			samenumber= numaralar2[karmailk];
		
			for(a=0; a<5; a++){						
				for(b=0; b<5; b++){
					if(memory3[a]==memory3[b] && !((memory4[a]== memory4[b]) && (memory5[a]== memory5[b]))){					// Hafiza mekanizmasi
						memorytrue++;
						sat1=memory4[a];
						sut1=memory4[b];
						sat2=memory4[a];
						sut2=memory4[b];
					
					}						
				}
  	
			for(a=0; a<6; a++){						
				printf("\n\n\t");
				for(b=0; b<6; b++){
					if(a==s && b==l){
						printf("%d\t", numaralar2[karmailk]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			} 
			printf("\nBilgisayarin ilk tahmini : %d", numaralar2[karmailk] );
			sleep(1);
			printf("\n\n"); 		
			if(numaralar2[karmailk]== numaralar2[6*i+j]){
				for(a=0; a<6; a++){						
					printf("\n\n\t");
					for(b=0; b<6; b++){												 // EGER ILK TAHMIN OYUNCUNUN IKINCI TAHMINIYLE AYNIYSA
						if(a==i && b==j){
							printf("%d\t", numaralar2[6*i+j]);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				} 
				round++;
				printf("\nTur %d\n\n", round);
				pcscore++;
				printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \n\t\tBilgisayarin puani: %d", pcscore);	
				printf("\n\t\t Sira tekrar bilgisayarda ");	
				samenumber1=numaralar1[6*i+j];
				yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile deðiþmek
				yildiz[i][j]= '-';
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");	
			}
			else if(numaralar2[karmailk]== numaralar2[6*u+o]){
				samenumber1= numaralar2[6*u+o];
				for(a=0; a<6; a++){						
					printf("\n\n\t");												 // EGER ILK TAHMIN OYUNCUNUN ILK TAHMINIYLE AYNIYSA
					for(b=0; b<6; b++){
						if(a==u && b==o){
							printf("%d\t", numaralar2[6*u+o]);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				} 
				round++;
				printf("\nTur %d\n\n", round);
				pcscore++;
				printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \n\t\tBilgisayarin puani: %d", pcscore);	
				printf("\n\t\t Sira tekrar bilgisayarda ");	
				yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile deðiþmek
				yildiz[u][o]= '-';
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");	
			}
		
			else if(numaralar2[karmailk]!= numaralar2[6*u+o] || numaralar2[karmailk]!= numaralar2[6*i+j]){

			c= (rand() % 6);																				  // bilinmemis random deger alma
			e= (rand() % 6);
				while(yildiz[c][e]== '-' || (c==i && e==j) || (c==u && e==o) || (c==s && e==l)){
					c= (rand() % 6);
					e= (rand() % 6);		
				}
		
			karmaiki=(6*c+e);
			samenumber1= numaralar2[karmaiki];
			printf("\n\n");														 // EGER HAFIZA HICBIR KARTLA TUTUSMAZSA IKINCI TAHMIN
			for(a=0; a<6; a++){						
			printf("\n\n\t");
				for(b=0; b<6; b++){
					if(a==c && b==e){
						printf("%d\t", numaralar2[karmaiki]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			}
			printf("\nBilgisayarin ikinci tahmini : %d", numaralar2[karmaiki] );	
			round++;
			printf("\nTur %d\n\n", round);
			if(samenumber==samenumber1){
				pcscore++;
				round++;
				printf("\n\n\t\tBilgisayar bir adet dogru eslesme yapti. Bilgisayarin puani: %d", pcscore);	
				printf("\n\t\t Sira tekrar bilgisayarda ");	
				yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile deðiþmek
				yildiz[c][e]= '-';
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");	
			}
			else{
				printf("\n\t Bilgisayar sirasini kaybetti sira size geciyor. ");	
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
				
			} 		    			                						
		}
	    }  
	}
	if(gamerscore>9){
						system("cls");
		printf("\t\t\tKAZANAN OYUNCU!!\n");
	}
	else if(pcscore>9){
						system("cls");
		printf("\t\t\tKAZANAN BILGISAYAR\n");
	}
	else if(pcscore==9 && gamerscore==9){
						system("cls");
		printf("\t\t\tOYUN BERABERE TAMAMLANDI\n");		
	}

  	}
  		printf("\t\t\tOynanilan tur sayisi: %d", round);
	printf("\n\n\t\t\tOyun tamamlandi\n");
	printf("\n");
	for(a=0; a<6; a++){						
		printf("\n\t");
		for(b=0; b<6; b++){
			printf("%d\t", numaralar2[6*a+b]);
		}
	}
	scanf("%c", car);
	}
	

	else if(e==3){ 																	// ZOR MODDA MATRÝS
		for(i=0; i<64; i++){
			karmailk= (rand() % 64);
   	    	karmaiki= (rand() % 64);	
			temp= numaralar3[karmailk];
   	    	numaralar3[karmailk]=numaralar3[karmaiki];
   	    	numaralar3[karmaiki]= temp;
   		}
		for(j=0; j<64; j++){  														// sayý matrisini yazdýr
			if(j%8==0){
			printf("\n\n");
			}
			printf("\t%d", numaralar3[j]);
		}
		printf("\n\n\t\tSayilari aklinizda tutmaya calisin \n\t\t\t 5 saniyeniz var.\n\n ");
		for(zaman=5; zaman>0; zaman--){
			sleep(1);	
			printf("\n\n\t\t\t %d", zaman);		
		}
		sleep(2);
		system("cls");
	   	   		   	
		a=8;
		b=8;
		
	
	while(gamerscore<17 && pcscore<17 && !(gamerscore==16 && pcscore==16)){	
		samenumber=1;
		samenumber1=1;
		printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore);
		while(samenumber==samenumber1){
			for(i=0; i<a; i++){
				printf("\n\n\t\t\t");
				for(j=0; j<b; j++){
					yildiz[i][j]= '*';
					printf("\t%c", yildiz[i][j]);
				}	
			}

		printf("\n\n\t\tBelirtlien yildiz matrisinin icinde rastgele dagitilmis sayilar bulunmaktadir.\n\t\t\t\tLutfen ilk tahmininizin satir ve sutun numarasini girin.\n\n\t\tTur %d\n", round);
			i=0;
			j=0;
			d=0;
			printf("\nSatir numarasi\n(0,1,2,3,4,5,6,7)"); 							// kullanýcýdan ilk kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi\n(0,1,2,3,4,5,6,7)");
			scanf("%d", &j);
		
			d=(8*i+j);
			samenumber=numaralar3[d];
				for(a=0; a<8; a++){													// ilk kartý yýldýz matrisi içinde gösterme
					printf("\n");
					for(b=0; b<8; b++){
						if(a==i && b==j){
							printf("%d\t", samenumber);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				}
						
			printf("\n\nIkinci kartin satir ve sutun numarisini giriniz.\n");
			i=0;
			j=0;
			d=0;
			printf("\nSatir numarasi:"); 											// kullanýcýdan ikinci kartýn koordinatlarýný alma
			scanf("%d", &i);
			printf("\nSutun numarasi:");
			scanf("%d", &j);
			u= i;
			o= j;
			
			d=(8*i+j);
			samenumber1=numaralar3[d];
				for(a=0; a<8; a++){						
					printf("\n");
					for(b=0; b<8; b++){
						if(a==i && b==j){
							printf("%d\t", samenumber1);
						}				
						else{
							printf("%c\t", yildiz[a][b]);		
						}		
					}
				}
			if(samenumber==samenumber1){											// kullanýcýnýn tahmini dogru mudur
				printf("\n\t\tTahmininiz dogru!!\n\t\tTahmin yapmak icin bir cift hak kazandinz!!");
				yildiz[u][o]= '-';
				yildiz[i][j]= '-';
				scanf("%c", &car);
				round++;
				gamerscore++;
				scanf("%c", &car1);
				system("cls");
			}
			else{
				printf("\n\t\t BILEMEDIN!!\n\t\tSIRA BILGISAYARDA");
				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
			}
		}
		samenumber=1;
		samenumber1=1;		
		while(samenumber==samenumber1){
		printf("\nBilgisayarin puani: %d\nOyuncunun puani: %d\n", pcscore, gamerscore); 										  // Bilgisayarin oyun sirasi  
		s= (rand() % 8);																				  // bilinmemis random deger alma
		l= (rand() % 8);
			while(yildiz[s][l]== '-' || (s==i && l==j) || (s==u && l==o)){
				s= (rand() % 8);
				l= (rand() % 8);		
			}
		
		karmailk=(8*s+l);
		samenumber= numaralar3[karmailk];
  	
		for(a=0; a<8; a++){						
			printf("\n\n\t");
			for(b=0; b<8; b++){
				if(a==s && b==l){
					printf("%d\t", numaralar3[karmailk]);
				}				
				else{
					printf("%c\t", yildiz[a][b]);		
				}		
			}
		} 
		sleep(2);
		printf("\nBilgisayarin ilk tahmini : %d", samenumber );
		printf("\n\n"); 		
		if(numaralar3[karmailk]== numaralar3[8*i+j]){
			for(a=0; a<8; a++){						
				printf("\n\n\t");
				for(b=0; b<8; b++){												 // EGER ILK TAHMIN OYUNCUNUN IKINCI TAHMINIYLE AYNIYSA
					if(a==i && b==j){
						printf("%d\t", numaralar3[8*i+j]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			} 
			round++;
			printf("\nTur %d\n\n", round);
			pcscore++;
			printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \n\t\tBilgisayarin puani: %d", pcscore);	
			printf("\n\t\t Sira tekrar bilgisayarda ");	
			samenumber1=numaralar1[8*i+j];
			yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile degiþmek
			yildiz[i][j]= '-';
//			scanf("%c", &car);
			scanf("%c", &car1);
			system("cls");	
		}
		else if(numaralar3[karmailk]== numaralar3[8*u+o]){
			samenumber1= numaralar3[8*u+o];
			for(a=0; a<8; a++){						
				printf("\n\n\t");												 // EGER ILK TAHMIN OYUNCUNUN ILK TAHMINIYLE AYNIYSA
				for(b=0; b<8; b++){
					if(a==u && b==o){
						printf("%d\t", numaralar3[8*u+o]);
					}				
					else{
						printf("%c\t", yildiz[a][b]);		
					}		
				}
			} 
			round++;
			printf("\nTur %d\n\n", round);
			pcscore++;
			printf("\n\n\t\tBilgisayar onceki tahminlerinizden birini hatirladi ve sonucu buldu. \n\t\tBilgisayarin puani: %d", pcscore);	
			printf("\n\t\t Sira tekrar bilgisayarda ");	
			yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile degismek
			yildiz[u][o]= '-';
//			scanf("%c", &car);
			scanf("%c", &car1);
			system("cls");	
		}
		
		else if(numaralar3[karmailk]!= numaralar3[8*u+o] || numaralar3[karmailk]!= numaralar3[8*i+j]){

			c= (rand() % 8);																				  // bilinmemis random deger alma
			e= (rand() % 8);
				while(yildiz[c][e]== '-' || (c==i && e==j) || (c==u && e==o) || (c==s && e==l)){
					c= (rand() % 8);
					e= (rand() % 8);		
				}
		
			karmaiki=(8*c+e);
			samenumber1= numaralar3[karmaiki];
			printf("\n\n");														 // EGER HAFIZA HICBIR KARTLA TUTUSMAZSA IKINCI TAHMIN
			for(a=0; a<8; a++){						
			printf("\n\n\t");
				for(b=0; b<8; b++){
					if(a==c && b==e){
						printf("%d\t", numaralar3[karmaiki]);
					}				
					else{
						printf("*\t");		
					}		
				}
			}	
			printf("\nBilgisayarin ikinci tahmini : %d", numaralar3[karmaiki] );
			round++;
			printf("\nTur %d\n\n", round);
			if(samenumber==samenumber1){
				pcscore++;
				round++;
				printf("\n\n\t\tBilgisayar bir adet dogru eslesme yapti.\n Bilgisayarin puani: %d", pcscore);	
				printf("\n\t\t Sira tekrar bilgisayarda ");	
				yildiz[s][l]= '-';					 							  	 //  bilinen noktalarý - ile degismek
				yildiz[c][e]= '-';
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");	
			}
			else{
				printf("\n\t Bilgisayar sirasini kaybetti sira size geciyor. ");	
//				scanf("%c", &car);
				scanf("%c", &car1);
				system("cls");
				
			} 		    			                						
		}
	}	                      		                            				
	}	
	printf("\n\n\t\t\tOyun tamamlandi\n");
	
	if(gamerscore>16){
		system("cls");
		printf("\t\t\tKAZANAN OYUNCU!!\n");
	}
	else if(pcscore>16){
		system("cls");
		printf("\t\t\tKAZANAN BILGISAYAR\n");
	}
	else if(pcscore==16 && gamerscore==16){
		system("cls");
		printf("\t\t\tOYUN BERABERE TAMAMLANDI\n");
		
	}
	printf("\t\t\tOynanilan tur sayisi: %d", round);
		printf("\n");
	for(a=0; a<8; a++){						
		printf("\n\t");
		for(b=0; b<8; b++){
			printf("%d\t", numaralar3[8*a+b]);
		}
	scanf("%c", car);
	
  	}
}
return 0;
}

