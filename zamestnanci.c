
#include<stdio.h>
#include<stdlib.h>

/*definovani struktur, hlavni struktura zamestnanec, v ni podstruktury narozeni a bydliste*/
struct bydliste
    {
        char ulice[30];
        char posta[30];
        char cisloDomu[10];
        int PSC;
    };
struct narozeni
    {
        int den;
        int mesic;
        int rok;
    };

struct zamestnanec
    {
     char jmeno[30];
     char prijmeni[30];
     struct bydliste adresa;
     struct narozeni datum;
     int letPraxe;
     float mzdaNaHodinu;
    };

//prohledani pocatecnich pismen prijmeni zamestnancu a porovnani s pismenem yadanym uzivatelem, vypis shody
int najdiPrijmeni(struct zamestnanec p, char pismeno){
    int vyskyt = 0;
    if (p.prijmeni[0] == pismeno){
        vyskyt ++;
        printf("%s %s: %f korun/h\n", p.jmeno, p.prijmeni, p.mzdaNaHodinu);

    }
    return vyskyt;
}

//vypis udaju o zamestnanci k inventure
void inventura(struct zamestnanec p){
    float celorocniMzda = p.mzdaNaHodinu*8*21*11;
    printf("%s %s %f korun/rok, bydliste: %s %d, %s %s, narozen %d.%d.%d\n",
            p.jmeno, p.prijmeni, celorocniMzda, p.adresa.posta, p.adresa.PSC,
            p.adresa.ulice, p.adresa.cisloDomu, p.datum.den, p.datum.mesic, p.datum.rok);
    return;
}

int main(void){
    //vytvoreni seznamu zamestnancu a prirazeni hodnot
    struct zamestnanec zamestnanci[3] = {{"Franta", "Novak",{"Cervena", "Dusseldorf", "321",59789},{12,10,1987},14,112.8},
                                        {"Lojza", "Nozicka",{"Hrncirska", "Constanta", "231",5978},{11,11,1966},3,73.5},
                                        {"Ferda", "Budik",{"Nemecka", "Milano", "5",64566},{18,04,1996},6,176.5}};

    //hledani zamestnancu podle pismena zadaneho uzivatelem
    char hledanePrijmeni;
    printf("Zadejte prvni (velke) pismeno z prijmeni hledaneho zamestnance: ");
    scanf("%c", &hledanePrijmeni);
    int pocetPismeno = 0;
    printf("\n");
    for (int j = 0; j<3;j++){//prochazeni vsech zamestnancu
        pocetPismeno = pocetPismeno + najdiPrijmeni(zamestnanci[j], hledanePrijmeni);
    }

    printf("\nPocet zamestnancu s prijmenim na %c: %d\n\n", hledanePrijmeni,pocetPismeno);
    printf("--------------------------------------------------------------------------------------\n");
    //hledani zamestnancu podle delky praxe
    int hledanaPraxe;
    int pocetZamestnancu = 0;
    printf("Zadejte hledanou praxi v celych letech: ");
    scanf("%d", &hledanaPraxe);
    printf("\n");
    for (int i = 0; i < 3; i++){//prochazeni vsech zamestnancu
        if (zamestnanci[i].letPraxe >= hledanaPraxe){
            printf("%s %s, delka praxe v letech: %d\n", zamestnanci[i].jmeno, zamestnanci[i].prijmeni, zamestnanci[i].letPraxe);
            pocetZamestnancu ++;
        }
    }

    printf("\nPocet zamestnancu s minimalni praxi %d let: %d\n\n", hledanaPraxe, pocetZamestnancu);
    printf("--------------------------------------------------------------------------------------\n");

    //vypis zamestnancu k inventure
    int volba;
    printf("Pro vypsani udaju k inventure napiste cislo 1: ");
    scanf("%d", &volba);
    printf("\n");
    if (volba == 1){
        for (int k = 0; k<3;k++){
            inventura(zamestnanci[k]);
        }
    }
    else{
        return 0;
    }
    return 0;
}
