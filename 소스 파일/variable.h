#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTION_INPUT 20000
#define MAX_ANSWER_INPUT 3
#define MAX_ANSWER_LEN 2048
#define Yes 1
#define No 2

//tsv 데이터베이스 구조
typedef struct {
    int no;
    int correct;
    int incorrect;
    char question[MAX_QUESTION_INPUT];
    char answers[MAX_ANSWER_INPUT][MAX_ANSWER_LEN];
    int answer_count;
} Question;
