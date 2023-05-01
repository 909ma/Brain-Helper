#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"

//Review note ¿€º∫
void WriteReviewNote(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "https://github.com/909ma\n\n\n");
    int i, j, k;
    for (i = 1; i <= question_count; i++) {
        fprintf(fp, "No. %d\t correct : %d,\t incorrect : %d\nQ : ", i, questions[i].correct, questions[i].incorrect);
        k = 0;
        while(questions[i].question[k] != '\0') {
            if(questions[i].question[k] == '.' || questions[i].question[k] == '?') {
                fprintf(fp, "%c\n", questions[i].question[k]);
            } else {
                fprintf(fp, "%c", questions[i].question[k]);
            }
            k++;
        }
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "\nAnswer %d : %s", j+1,questions[i].answers[j]);
        }
        fprintf(fp, "\n\n\n");
    }
    fclose(fp);
}
