#include "sistemi_studentet.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define GJATESIA_MAX_RRESHT 120

struct student{
    char *ID;
    char *emri;
    char *mbiemri;
    unsigned short int fakulteti;                                            //mundesi zgjedhje nga disa fakultete te dhene (nuk e shkruan vete)
};

void shtoStudent(void){
    int vazhdo_loop;
    char vazhdim_pj;

    FILE *studentetp;
    studentetp = fopen("lista_studentet.txt", "a");

    if (studentetp == NULL){
        printf("error ne hapjen e file-it lista_studentet");
        return;
    }

    do{
        //cakto madhesine e pointerave (stringjeve) te struct
        struct student studenti_shtuar;
        studenti_shtuar.ID = (char *) malloc(8 * sizeof(char));          //ID permban 8 shifra
        studenti_shtuar.emri = (char *) malloc(50 * sizeof(char));       //nga 50 char per emrin dhe mbiemrin
        studenti_shtuar.mbiemri = (char *) malloc(50 * sizeof(char));

        //ploteso struct per studentin qe do te shtohet
        printf("\n\t\tID\t\t=>\t");
        scanf("%s", studenti_shtuar.ID);
        printf("\t\tEmri\t\t=>\t");
        scanf("%s", studenti_shtuar.emri);
        printf("\t\tMbiemri\t\t=>\t");
        scanf("%s", studenti_shtuar.mbiemri);
        printf("\t\tFakulteti\t=>\t");
        scanf("%hu", &studenti_shtuar.fakulteti);

        //formati i shkrimit te se dhenave
        fprintf(studentetp, "%s | %s | %s | %hu\n", studenti_shtuar.ID, studenti_shtuar.emri, studenti_shtuar.mbiemri,
                studenti_shtuar.fakulteti);
        printf("\t\tte dhenat u ruajten\a\n");

        //lirim i mem dhe mbyllja e file
        free(studenti_shtuar.ID);
        free(studenti_shtuar.emri);
        free(studenti_shtuar.mbiemri);

        printf("\n\t\tDeshironi te vazhdoni te shtoni studente? (p/j):\t");
        scanf(" %c", &vazhdim_pj);          //!!!duhet hapesire perpara %c sepse scanf lexon whitespace dhe enter nga me pare!!!
        if (vazhdim_pj == 'p'){
            vazhdo_loop = 1;
        } else if (vazhdim_pj == 'j'){
            vazhdo_loop = 0;
        } else{
            return;
        }

    } while (vazhdo_loop);
    fclose(studentetp);
}

void lexoStudentetTxt(void){
    char rreshti[GJATESIA_MAX_RRESHT];
    char *token;

    FILE *studentetp;
    studentetp = fopen("lista_studentet.txt", "r");

    if (studentetp == NULL){
        printf("error ne hapjen e file-it lista_librat");
        return;
    }

    while (fgets(rreshti, sizeof (rreshti), studentetp) != NULL){
        token = strtok(rreshti, "|");
        printf("\n\t\t");
        while (token != NULL) {
            printf("%s", token);
            token = strtok(NULL, "|");
        }
        //printon derisa te arrije te | e pare. kur thirret perseri me NULL vazhdon te stringu ku e la
        //strtok ka register te veten ku mban callin e meparshem prandaj heren e dyte nuk ka nevoje te specifikohet stringu (NULL)
    }
    fclose(studentetp);
}