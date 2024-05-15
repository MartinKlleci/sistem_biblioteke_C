#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "sistemi_librat.h"
#include "sistemi_studentet.h"

void titulli(void);
void menuja_kryesore(void);
void rikthim(void);

int main() {
    SetConsoleTitle("Sistemi i Adminstrimit te Bibliotekes Studentore");
    system("color F0");

    titulli();
    menuja_kryesore();

    return 0;
}

void titulli(void){
    printf("\n"
           "\t\t        ___ _    _             _    _      _      _       _      _    _       _       _ _       \n"
           "\t\t       / __(_)__| |_ ___ _ __ (_)  (_)    /_\\  __| |_ __ (_)_ _ (_)__| |_ _ _(_)_ __ (_) |_     \n"
           "\t\t       \\__ \\ (_-<  _/ -_) '  \\| |  | |   / _ \\/ _` | '  \\| | ' \\| (_-<  _| '_| | '  \\| |  _|    \n"
           "\t\t  _    |___/_/__/\\__\\___|_|_|_|_|  |_|  /_/ \\_\\__,_|_|_|_|_|_||_|_/__/\\__|_| |_|_|_|_|_|\\__|    \n"
           "\t\t | |_ ___   | _ |_) |__| (_)___| |_ ___| |_____ ___  / __| |_ _  _ __| |___ _ _| |_ ___ _ _ ___ \n"
           "\t\t |  _/ -_)  | _ \\ | '_ \\ | / _ \\  _/ -_) / / -_|_-<  \\__ \\  _| || / _` / -_) ' \\  _/ _ \\ '_/ -_)\n"
           "\t\t  \\__\\___|  |___/_|_.__/_|_\\___/\\__\\___|_\\_\\___/__/  |___/\\__|\\_,_\\__,_\\___|_||_\\__\\___/_| \\___|\n"
           "\t\t                                                                                                ");
    Sleep(1000);
    printf("\n\n\n");
    for (int i=0; i<5; i++){
        printf("\a");
        switch (i){
            case 0:
                printf("\n\t\tProjekt kursi");
                break;
            case 1:
                printf("\n\n\t\tLenda:\t\tTeknikat dhe gjuhet e programimit");
                break;
            case 2:
                printf("\n\t\tStudenti:\tMartin Klleci");
                break;
            case 3:
                printf("\n\t\tPedagogu:\tEduart Torba");
                break;
            case 4:
                printf("\n\t\tGrupi:\t\t1A Elektronike");
                break;
            default: return;
        }
        Sleep(1000);
    }

    printf("\n\n\n\t\t Shtypni nje buton per te vazhduar...\n\t\t");
    getch();
}

void menuja_kryesore(void){
    unsigned short int zgjedhja;
    system("cls");
    printf("\t\t+---------------------------------------------------------------------------------------+\n"
           "\t\t|                                    MENUJA KRYESORE                                    |\n"
           "\t\t+---------------------------------------------------------------------------------------+\n");

    printf("\n\n\t\t Zgjidhni veprimin qe doni te kryeni: \n\n"
           "\n\t\t[1] - Marrje libri"
           "\n\t\t[2] - Kthim libri"
           "\n\t\t[3] - Regjistrim libri"
           "\n\t\t[4] - Regjistrim studenti"
           "\n\t\t[5] - Kerkim me ISBN"
           "\n\t\t[6] - Lista e librave"
           "\n\t\t[7] - Lista e studenteve anetare"
           "\n\t\t[8] - Librat me te lexuar"
           "\n\t\t[9] - Studentet qe lexojne me shume"
           "\n\n\t\t[0] - Dilni");

    do{
        printf("\n\n\n\t\tzgjidhni veprimin (0-9)\t\t=>\t\t");
        scanf("\t%hu", &zgjedhja);

        switch (zgjedhja) {
            case 0:
                exit(0);
            case 1:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                     MARRJE  LIBRI                                     |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                levijeLibri(1);
                rikthim();
                menuja_kryesore();
            case 2:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                      KTHIM LIBRI                                      |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                levijeLibri(2);
                rikthim();
                break;
            case 3:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                   REGJISTRIM  LIBRI                                   |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                printf("\t\tVendosni te dhenat e librit duke plotesuar hapesirat e meposhtme:\n");
                shtoLiber();
                menuja_kryesore();
                break;

            case 4:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                  REGJISTRIM STUDENTI                                  |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");

                printf("\t\tVendosni te dhenat e studentit duke plotesuar hapesirat e meposhtme:\n"
                       "\t\t*per fakultetet zgjidhni nje prej numrave:\n"
                       "\t\t([1]->FIE, [2]->FIM, [3]->FIN, [4]->FAU, [5]->FTI, [6]->FIMIF, [7]->FGjM)\n\n");
                shtoStudent();
                menuja_kryesore();

            case 5:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                      KERKIM ISBN                                      |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                rikthim();
                break;
            case 6:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                    LISTA E LIBRAVE                                    |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                lexoLibratTxt();
                rikthim();
                break;
            case 7:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                  LISTA E STUDENTEVE                                   |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                lexoStudentetTxt();
                rikthim();
                break;
            case 8:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                                  LIBRAT ME TE LEXUAR                                  |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                rikthim();
                break;
            case 9:
                system("cls");
                printf("\t\t+---------------------------------------------------------------------------------------+\n"
                       "\t\t|                             STUDENTET QE LEXOJNE ME SHUME                             |\n"
                       "\t\t+---------------------------------------------------------------------------------------+\n\n");
                printf("\t\t\n");
                rikthim();
                break;
            default:
                printf("\n\t\tju lutemi zgjidhni nje opsion te vlefshem\t");
        }

    }while (zgjedhja > 8 || zgjedhja < 0);
}

void rikthim(void){
    char kthehuP;
    printf("\n\n\n\n\n\n\t\tRikthehuni te faqja kryesore? (p):\t");
    scanf(" %c", &kthehuP);
    if (kthehuP == 'p'){
        menuja_kryesore();
    } else{
        rikthim();
    }
}