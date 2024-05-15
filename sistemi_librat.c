#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

#define GJATESIA_MAX_RRESHT 270
#define GJATESIA_MAX_TITULL (200 * sizeof (char))
#define GJATESIA_MAX_AUTOR  (40 * sizeof (char))

struct data{
    int viti;
    int muaji;
    int dita;
};

struct liber{
    unsigned long long int ISBN;
    char *titulli;
    char *autori;
    unsigned viti_botimit;
};

struct perdorim_libri{
    char *ID_student;
    unsigned long long int ISBN;
    struct data data_marrjes;
    struct data data_kthimit;
    bool statusi;
};

void shtoLiber(void){
    int vazhdo_loop = 1;
    char vazhdim_pj;

    FILE *libratp;                                                    //hap txt file me mode append. referimi me pointer
    libratp = fopen("lista_librat.txt", "a");

    if (libratp == NULL){
        printf("error ne hapjen e file-it lista_librat");
        return;
    }

    while (vazhdo_loop){
        struct liber libri_shtuar;

        //cakto madhesine e pointerave (stringjeve) te struct
        libri_shtuar.titulli = (char *) malloc(GJATESIA_MAX_TITULL);
        libri_shtuar.autori = (char *) malloc(GJATESIA_MAX_AUTOR);      //emri+mbiemri me i gjate ne Shqiperi i kalonte 20 char te rekomanduara

        //ploteso struct per librin qe do te shtohet
        printf("\t\tISBN\t\t=>\t");
        scanf("%llu", &libri_shtuar.ISBN);
        printf("\t\tTitulli\t\t=>\t");
        scanf("%s", libri_shtuar.titulli);
        printf("\t\tAutori\t\t=>\t");
        scanf("%s", libri_shtuar.autori);
        printf("\t\tViti i botimit\t=>\t");
        scanf("%u", &libri_shtuar.viti_botimit);

        //formati i shkrimit te se dhenave
        fprintf(libratp, "%llu|%s|%s|%u\n", libri_shtuar.ISBN, libri_shtuar.titulli, libri_shtuar.autori, libri_shtuar.viti_botimit);
        printf("\t\tte dhenat u ruajten\a\n");

        //lirim i mem dhe mbyllja e file
        free(libri_shtuar.titulli);
        free(libri_shtuar.autori);

        printf("\n\t\tDeshironi te vazhdoni te shtoni libra? (p/j):\t");
        scanf(" %c", &vazhdim_pj);          //!!!duhet hapesire perpara %c sepse scanf lexon whitespace dhe enter nga me pare!!!
        //scanf("%c", &vazhdim_pj);
        if (vazhdim_pj == 'p') {
            vazhdo_loop = 1;
        } else if (vazhdim_pj == 'j') {
            vazhdo_loop = 0;
        } else {
            return;
        }
    }
    fclose(libratp);
}
void lexoLibratTxt(void){
    char rreshti[GJATESIA_MAX_RRESHT];
    char *token;

    FILE *libratp;
    libratp = fopen("lista_librat.txt", "r");

    if (libratp == NULL){
        printf("error ne hapjen e file-it lista_librat");
        return;
    }

    while (fgets(rreshti, sizeof (rreshti), libratp) != NULL){
        token = strtok(rreshti, "|");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, "|");
        }
    }
    fclose(libratp);
}

void levijeLibri(int veprimi){

    FILE *log_levizjeP;
    log_levizjeP = fopen("ditar_levizje_librash.txt", "a");

    FILE *libratP;
    libratP = fopen("librat.txt", "r");

    if (log_levizjeP == NULL /*|| libratP == NULL*/){
        printf("\t\terror: file nuk u hap");
        return;
    }

    switch (veprimi){
        case 1:
            printf("\t\tJepni te dhenat per te marre liber nga bibloteka:\n\n");
            int vazhdo1;
            char pj1;
            do {
                struct perdorim_libri liber_marrje;
                liber_marrje.ID_student = (char *) malloc(8 * sizeof (char));

                printf("\t\tID e studentit\t=>\t");
                scanf("%s", liber_marrje.ID_student);
                printf("\t\tISBN e librit\t=>\t");
                scanf("%llu", &liber_marrje.ISBN);
                printf("\n\t\tData e kthimit:\n");
                printf("\t\t\tViti\t=>\t");
                scanf("%d", &liber_marrje.data_kthimit.viti);
                printf("\t\t\tMuaji:\t=>\t");
                scanf("%d", &liber_marrje.data_kthimit.muaji);
                printf("\t\t\tData:\t=>\t");
                scanf("%d", &liber_marrje.data_kthimit.dita);

                printf("\n\t\tDeshironi te vazhdoni te merrni libra? (p/j):\t");
                scanf(" %c", &pj1);          //!!!duhet hapesire perpara %c sepse scanf lexon whitespace dhe enter nga me pare!!!
                if (pj1 == 'p'){
                    vazhdo1 = 1;
                } else if (pj1 == 'j'){
                    vazhdo1 = 0;
                }
            }while(vazhdo1);
            break;

        case 2:
            printf("\t\tJepni te dhenat per te kthyer liber ne biblioteke:\n\n");
            int vazhdo2;
            char pj2;
            do{
                struct perdorim_libri liber_kthim;
                liber_kthim.ID_student = (char *) malloc(8 * sizeof (char));

                printf("\t\tID e studentit\t=>\t");
                scanf("%s", liber_kthim.ID_student);
                printf("\t\tISBN e librit\t=>\t");
                scanf("%llu", &liber_kthim.ISBN);

                printf("\n\t\tDeshironi te vazhdoni te merrni libra? (p/j):\t");
                scanf(" %c", &pj2);          //!!!duhet hapesire perpara %c sepse scanf lexon whitespace dhe enter nga me pare!!!
                if (pj2 == 'p'){
                    vazhdo2 = 1;
                } else if (pj2 == 'j'){
                    vazhdo2 = 0;
                }
            }while(vazhdo2);
            break;

        default:
            printf("error: veprimi nuk mund te kryhej");
    }

    fclose(log_levizjeP);
    fclose(libratP);
}