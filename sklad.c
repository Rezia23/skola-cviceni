#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct polozka
{
    char nazev[50];
    int pocet;
    int cena;
};
struct polozka sklad[1000];

//funkce k nacteni polozky do skladu
void nacistPolozku(int porPol, FILE** file){
    int tmp;
    printf("Zadejte nazev, pocet kusu a cenu (oddeleno mezerou): ");
    scanf("%s %d %d", &sklad[porPol].nazev, &sklad[porPol].pocet, &sklad[porPol].cena);

    fprintf(*file, "\n%s %d %d",sklad[porPol].nazev, sklad[porPol].pocet, sklad[porPol].cena);
    return;
}


//serazeni a vypis polozek podle poctu
void poradi(int porPol){
    printf("Vypis polozek v poradi dle poctu\n");
    char tmpNazev[50];
    int tmpPocet;
    int tmpCena;
    int n,r;

    //bubblesort
    for(r = 0; r<porPol-1;r++){
        for(n = 0; n < porPol-r-1; n++){
            if(sklad[n].pocet<sklad[n+1].pocet){
                    strcpy(tmpNazev,sklad[n].nazev);
                    tmpPocet = sklad[n].pocet;
                    tmpCena = sklad[n].cena;

                    strcpy(sklad[n].nazev,sklad[n+1].nazev);
                    sklad[n].pocet = sklad[n+1].pocet;
                    sklad[n].cena = sklad[n+1].cena;

                    strcpy(sklad[n+1].nazev, tmpNazev);
                    sklad[n+1].pocet = tmpPocet;
                    sklad[n+1].cena = tmpCena;


            }

        }
    }

    //vypis polozek
     for(int m = 0; m < porPol; m++){
        printf("%s: %d\n", sklad[m].nazev, sklad[m].pocet);
     }

}

//vypis polozek s jejich celkovou cenou
void inventura(int porPol){
    printf("Vypis polozek s jejich cenou\n");
    int cenaCelkem = 0;
    int cena;
    for(int i = 0; i < porPol; i++){
        cena = sklad[i].pocet * sklad[i].cena;
        cenaCelkem += cena;
        printf("%s: %d\n",sklad[i].nazev,cena);
    }
    printf("Cena celkem: %d ", cenaCelkem);
}



int main (void){
    FILE *file = fopen("sklad.txt","a+");

    char nazev[50];
    int pocet = 0;
    int cena = 0;
    int porPol = 0;

    if (file == NULL){
        printf("Problem s otviranim souboru\n");
        exit(1);
    }
    //nacteni obsahu souboru
    while(feof(file)==0){
        fscanf(file,"%s %d %d", nazev, &pocet, &cena);
        strcpy(sklad[porPol].nazev, nazev);
        sklad[porPol].pocet = pocet;
        sklad[porPol].cena = cena;
        porPol++;

    }

    //volba uzivatele
    int volba;
    printf("1) Nacist 5 polozek \n2) Pridat polozku \n3) Vypis v poradi dle poctu \n4) Inventura \n5) Konec programu\n");
    scanf("%d", &volba);

    switch(volba){
    case 1:
        for ( int i = 0; i < 5; i++){
            nacistPolozku(porPol, &file);
            porPol++;
        }
        break;
    case 2:
        nacistPolozku(porPol, &file);
        porPol++;
        break;
    case 3:
        poradi(porPol);
        break;
    case 4:
        inventura(porPol);
        break;
    case 5:
        return 0;
    default:
        printf("Neplatna volba");
    }
    fclose(file);
    return 0;
}
