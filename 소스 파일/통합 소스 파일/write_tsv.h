#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"

//tsv 데이터베이스 갱신
void write_tsv(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "no\tcorrect\tincorrect\tquestion\tanswer1\tanswer2\tanswer3\n");
    int i, j;
    for (i = 1; i <= question_count; i++) {
        fprintf(fp, "%d\t%d\t%d\t%s", i, questions[i].correct, questions[i].incorrect, questions[i].question);
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "\t%s", questions[i].answers[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
