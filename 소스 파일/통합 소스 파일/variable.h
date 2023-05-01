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


int typeQ;//모드 번호 확인용 변수 
int i;
int QuestionNow=0;//현재 푸는 문제 번호 
int QuestionStart;//문제 범위 시작 지점
int QuestionEnd;//문제 범위 끝 지점 
int RandemModCycle = 0;
int QuestionCycle = 0;
int Mod1Start;
int Mod1End;
int QuestionRandomCount;//랜덤 출제 모드의 풀 문제 개수 
int Mod4Count=0;
int Mod4Exit=1;
int Mod0=0;
