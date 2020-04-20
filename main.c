//RICHARD GAJDOŠÍK, IDE = CLION
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 2
#define abeceda 26
#define MAX 100

void up_right(char slovo[], char **tajnicka, int stlpce, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a - f < 0 || b + f > stlpce ||
            (tajnicka[a - f][b + f] != slovo[f] && tajnicka[a - f][b + f] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a - f][b + f] = tolower(tajnicka[a - f][b + f]);
        }
    }
}

void up_left(char slovo[], char **tajnicka, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a - f < 0 || b - f < 0 ||
            (tajnicka[a - f][b - f] != slovo[f] && tajnicka[a - f][b - f] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a - f][b - f] = tolower(tajnicka[a - f][b - f]);
        }
    }
}

void down_right(char slovo[], char **tajnicka, int riadky, int stlpce, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a + f > riadky || b + f > stlpce ||
            (tajnicka[a + f][b + f] != slovo[f] && tajnicka[a + f][b + f] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a + f][b + f] = tolower(tajnicka[a + f][b + f]);
        }
    }
}

void down_left(char slovo[], char **tajnicka, int riadky, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a + f > riadky || b - f < 0 ||
            (tajnicka[a + f][b - f] != slovo[f] && tajnicka[a + f][b - f] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a + f][b - f] = tolower(tajnicka[a + f][b - f]);
        }
    }
}

void up(char slovo[], char **tajnicka, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a - f < 0 || (tajnicka[a - f][b] != slovo[f] && tajnicka[a - f][b] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a - f][b] = tolower(tajnicka[a - f][b]);
        }
    }
}

void down(char slovo[], char **tajnicka, int riadky, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (a + f > riadky || (tajnicka[a + f][b] != slovo[f] && tajnicka[a + f][b] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a + f][b] = tolower(tajnicka[a + f][b]);
        }
    }
}

void right(char slovo[], char **tajnicka, int stlpce, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (b + f > stlpce || (tajnicka[a][b + f] != slovo[f] && tajnicka[a][b + f] != tolower(slovo[f]))) {
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) {
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a][b + f] = tolower(tajnicka[a][b + f]);
        }
    }
}

void left(char slovo[], char **tajnicka, int *index[], int i) {
    char kontrola = slovo[0];
    int poriadok = 0, f = 0, a = index[kontrola - 'A'][i], b = index[kontrola - 'A'][i + 1];
    for (f = 0; f < strlen(slovo); f++) {
        if (b - f < 0 || (tajnicka[a][b - f] != slovo[f] && tajnicka[a][b - f] !=
                                                            tolower(slovo[f]))) { // kontrola či mi b-f nezišlo preč z tajničky, či sa nerovná slovo tajničke, tá istá kontrola aj pre malé písmená
            poriadok = 0;
            break;
        } else {
            poriadok = 1;
        }
    }
    if (poriadok == 1 && f == strlen(slovo)) { //ak sme našli zhodu a vykonal sa celý for cyklus
        for (f = 0; f < strlen(slovo); f++) {
            tajnicka[a][b - f] = tolower(tajnicka[a][b - f]);//... tak v tajničke vyškrtáme s tolower
        }
    }
}

void lustenie(char slovo[], char **tajnicka, int riadky, int stlpce, int *index[], int vyskyt[]) {
    char kontrola = slovo[0];
    if (((vyskyt[kontrola - 'A'] + 1) / 2) >
        0) { // vyskyty mi idú po +2, čo znamená že musím použiť ((-1 + 1)/2 = 0) ((1+1)/2 = 1) ((3+1)/2 = 2) ((5+1)/2 = 3)
        for (int i = 0; i <= vyskyt[kontrola -
                                    'A']; i += 2) { //for cyklus ide po výskytoch, nakoľko používam vo výskytoch + 2 musím ísť aj vo for cykly +2
            right(slovo, tajnicka, stlpce, index, i);
            left(slovo, tajnicka, index, i);
            down(slovo, tajnicka, riadky, index, i);
            up(slovo, tajnicka, index, i);
            up_right(slovo, tajnicka, stlpce, index, i);
            up_left(slovo, tajnicka, index, i);
            down_right(slovo, tajnicka, riadky, stlpce, index, i);
            down_left(slovo, tajnicka, riadky, index, i);
        }
//        for (int o = 0; o < riadky; o++) {
//            for (int f = 0; f < stlpce; f++) {
//                printf("%c", tajnicka[o][f]);   //po skontrolovaní slova vypíšeme tajničku
//            }
//            printf("\n");
//        }
//        printf("\n");
    } else {
        printf("Slovo %s sa nepodarilo najst\n", slovo);
    }

}

void uvolnenie_pamate(char **tajnicka, int *index[], int riadky) {
    //printf("%d ", riadky);
    for (int i = 0; i < riadky; i++) {
        free(tajnicka[i]);
    }
    for (int i = 0; i < abeceda; i++) {
        free(index[i]);
        //printf("UVOLNILSOM: %d \n", i);
    }
}
void vypis_indexy(int *index[], int vyskyt[]){
    int o = 0, kontrola = 0;
    printf("\n");
    for(int i = 0; i < 26; i++){
        if (vyskyt[i] > 0){
            kontrola++;
            printf("%c: ", 'A' + i);
            for(o = 0; o <= (vyskyt[i]); o++){
            printf("%d ", index[i][o]);
            }
        }
        if(kontrola > 0){
        printf("\n");
        }
        kontrola = 0;
    }
}
int kontrolSum(char **tajnicka, int *index[], int riadky, int stlpce){
//    printf("%d %d", riadky, stlpce);
    int r = 0, s = 0;
    char c;
    for(int i = 0; i < riadky; i++){
        for(int o = 0; o < stlpce; o++){
            c = tajnicka[i][o];
            if(c >= 'A' && c <= 'Z'){
                c = tolower(c);
            }
            c -= 'a';
//            printf(" %d", c);
            if(i % 2 == 0){
                r += c;
            }
            if(o % 2 != 0){
                s += c;
            }
        }
    }
    printf("\ns:%d d:%d", r, s);
    if(r == s){
        return 1;
    }
    else{
        return 0;
    }
}
void zmenIndex(char **tajnicka, int *index[], int vyskyt[]){
        int i, j, o = 0, docasne[1000], kontrola = 0, p = 0;
        char c, vymazane;
        scanf("%d %d %c", &i, &j, &c);
        vymazane = tajnicka[i][j];
        //printf("\n%c\n", tajnicka[i][j]);
        vymazane = tolower(vymazane);
        if(vymazane == c){
            return;
        }
        for(o = 0; o < vyskyt[vymazane - 'a']; o++){
            if((vyskyt[vymazane - 'a'] < 0) || index[vymazane - 'a'] == NULL){
                break;
            }
                if(o == i && (o + 1) == j){
                kontrola++;
                }
                else{
                    docasne[o] = index[vymazane - 'a'][o];
                    ++o;
                    docasne[o] = index[vymazane - 'a'][o];
                }
            }
        vyskyt[vymazane - 'a'] -= 2;
        for(p = 0; p < vyskyt[vymazane - 'a']; p++){
            index[vymazane - 'a'][p] = docasne[p];
        }
        vyskyt[c - 'a'] += 2;
        index[c - 'a'][vyskyt[c - 'a'] - 1] = i;
        index[c - 'a'][vyskyt[c - 'a']] = j;
        index[c - 'a'] = (int *) realloc(index[c - 'a'], ((N + vyskyt[c - 'a'])) * 2 * sizeof(int));// reallocujeme si miesto o dalšie pozície + všetky pozície doteraz
        printf("%d", vyskyt[vymazane - 'a']);
        if(vyskyt[vymazane - 'a'] == -1){
            free(index[vymazane - 'a']);
            printf("UVOLNIL SOM PAMAT");
        }
}
void nacitaj(int riadky, int stlpce, int *index[], int vyskyt[]) {
    FILE *fr;
    char c;
    char **tajnicka;
    int kontrola = 0;
    if ((fr = fopen("osemsmerovka.txt", "r")) == NULL) { // skontrolovania správnosti otvorenia súboru
        printf(" Spravu sa nepodarilo nacitat \n");
    } else {
        for (int o = 0; o < abeceda; o++) {
            index[o] = (int *) malloc(
                    N * 2 * sizeof(int)); // allocujeme si v indexe inicializačné miesto pre prvé hodnoty
        }
        fscanf(fr, "%d %d", &riadky, &stlpce);               // načítame si rozmer tajničky
        tajnicka = (char **) malloc((N + riadky) * sizeof(char *));
        for (int f = 0; f < stlpce; f++) {
            tajnicka[f] = (char *) malloc(stlpce * sizeof(char));
        }
        for (int o = 0; o < riadky; o++) {
            for (int f = 0; f < stlpce; f++) { // pre každé jedno miesto v tajničke
                c = getc(fr);
                if (c != '\n') {
                    tajnicka[o][f] = c;     //.. zapíšeme načítaný znak
                    vyskyt[c - 'A'] += 2;   // urobíme záznam do výskytu písmenka že sme načítali prvý výskyt
                    index[c - 'A'][vyskyt[c - 'A'] - 1] = o; // uložíme si súradnice
                    index[c - 'A'][vyskyt[c - 'A']] = f;
                    index[c - 'A'] = (int *) realloc(index[c - 'A'], ((N + vyskyt[c - 'A'])) * 2 *
                                                                     sizeof(int));// reallocujeme si miesto o dalšie pozície + všetky pozície doteraz
                } else {
                    f--;
                }
            }
        }
        char slovo[MAX];
        while (fscanf(fr, "%s", slovo) != EOF) {
            lustenie(slovo, tajnicka, riadky, stlpce, index,
                     vyskyt); //načítané slovo si pošleme do funkcie ktorá vyškrtáva z tajničky pri zistení zhody
        }
        for (int o = 0; o < riadky; o++) {
            for (int f = 0; f < stlpce; f++) {
                if (tajnicka[o][f] >= 'A' && tajnicka[o][f] <= 'Z') {
                    printf("%c", tajnicka[o][f]);           // vypísanie tajničky
                    kontrola++;
                }
            }
        }
        if (kontrola == 0) {
            printf("Tajnicka je prazdna."); //ak sme vyškrtali celú tajničku vypíšeme správu o prázdnosti tajničky
        }
        //printf("\n");
        if (fclose(fr) == EOF) {
            printf("Chyba: zatvarania suboru.");
        }
        int je = 0;
        je = kontrolSum(tajnicka, index, riadky, stlpce);
        if(je == 1){
        printf("\nSucty su rovnake");
        }
        else{
            printf("\nSucty nie su rovnake");
        }
        vypis_indexy(index, vyskyt);
        zmenIndex(tajnicka, index, vyskyt);              // kvôli spôsobu akým je riešený projekt bohužiaľ nemôžem callovať funkcie z písomky z mainu, kedže mám tuto jednu veľku funkciu ktorá handluje všetko
        vypis_indexy(index, vyskyt);
        uvolnenie_pamate(tajnicka, index, riadky); //uvoľnenie pamäte
        free(tajnicka);
        free(index);
    }
}


int main() {
    int riadky = 0, stlpce = 0;
    int *index[abeceda] = {NULL}; //vytvorenie a vynulovanie
    int vyskyt[abeceda] = {0};
    for (int i = 0;
         i < abeceda; i++) { // nastavíme si pole vyskyt na -1 nakoľko budeme používať +2 ako indikátor počtu načítaných
        vyskyt[i] = -1;
    }
    nacitaj(riadky, stlpce, index, vyskyt);


    return 0;
}
