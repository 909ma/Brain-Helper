#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTION_INPUT 20000
#define MAX_ANSWER_INPUT 3
#define MAX_ANSWER_LEN 2048
#define Yes 1
#define No 2

//tsv �����ͺ��̽� ����
typedef struct {
    int no;
    int correct;
    int incorrect;
    char question[MAX_QUESTION_INPUT];
    char answers[MAX_ANSWER_INPUT][MAX_ANSWER_LEN];
    int answer_count;
} Question;


int typeQ;//��� ��ȣ Ȯ�ο� ���� 
int i;
int q_num=0;//���� Ǫ�� ���� ��ȣ 
int RandemModCycle = 0;//
int QuestionCycle = 0;
int Mod1Start;
int Mod1End;
int Mod2End;//���� ���� ����� ���� ��ȣ 
int Mod4Count=0;
int Mod4Exit=1;
int Mod0=0;
