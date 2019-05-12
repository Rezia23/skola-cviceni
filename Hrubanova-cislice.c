/*
Autor: Terezie Hrubanová
Třída: 7.A
Datum: 14.10.2017
*/
/*
Vstup: celé kladné číslo
Vstupní podmínka: číslo nepřesahuje hodnotu maximálního integeru
Výstup: řádkový diagram
Výstupní podmínka:čísla od 0 do 9 s jejich počtem výskytů ve vstupu vyjádřeném pomocí znaku "*".
*/

#include <stdio.h>
#include <stdlib.h>

int id = 0;

void printStar(int pocet){	//funkce na vytisknuti diagramu, jako parametr dostane cislo, pokud n1 nenulove, vytiskne takovy pocet hvezdicek
	if(id<=9){
		if (pocet!=0){
			printf("%d: ",id);
			while(pocet>0){
				printf("*");
				pocet-=1;
			}
		printf("\n");

		}
		id+=1;
	}
}

int main(void){
	int vstup = 0, input = 0;
	int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
        printf("Zadejte cislo: ");
        scanf("%d", &input);	//naskenovani vstupu
	if (input==0){
		n0+=1;
	}
	while (input != 0){	//cyklus, ktery ziskava posledni cislici ze vstupu
		vstup = input%10;
		input /= 10;
//zjistuje, o jake se jedna cislo, do promenne oznacujici pocet jeho vyskytu pricte 1. Aby se nemuselo prochazet tolik podminek,
//rozdeli se  rozmezi cisel na poloviny a pak na ctvrtiny.
		if(vstup<5){
			if(vstup<3){
				if(vstup==0){
					n0+=1;
				}
				else if(vstup==1){
                                        n1+=1;
                                }
				else if(vstup==2){
                                        n2+=1;
                                }

			 }
			else{
				if(vstup==3){
                                        n3+=1;
                                }
                                else if(vstup==4){
                                        n4+=1;
                                }

			}
		}
		else{
			if(vstup<8){
                                if(vstup==5){
                                        n5+=1;
                                }
                                else if(vstup==6){
                                        n6+=1;
                                }
                                else if(vstup==7){
                                        n7+=1;
                                }

                         }
                        else{
                                if(vstup==8){
                                        n8+=1;
                                }
                                else if(vstup==9){
                                       	n9+=1;
                                }

                        }

		}
	}
//zavolani funkce na tisknuti hvezdicek s parametry podle jednotlivych poctu vyskytu cislic
	printStar(n0);
	printStar(n1);
	printStar(n2);
	printStar(n3);
	printStar(n4);
	printStar(n5);
	printStar(n6);
	printStar(n7);
	printStar(n8);
	printStar(n9);

}
