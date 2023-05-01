#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "write_tsv.h"
#include "WriteReviewNote.h"
#include "write_html.h"
#include "variable.h"

int Exit(int* q_num, Question* questions, int question_count){
	system("cls");
	getchar();
	//���α׷� ���� ����-------------------------------------------------------------------------------------- 
	int inputShutdown;
	printf("������ �����Ͻðڽ��ϱ�? [1/2]\n");
	scanf("%d", &inputShutdown);
	if(inputShutdown == 1){
		//����� �ۼ� ------------------------------------------------------- 
		time_t now;
	    struct tm *local;
	    char timestamp[25];
	    time(&now);
	    local = localtime(&now);
	    strftime(timestamp, 28, "%Y-%m-%d %H %M %S.backup", local);
	    write_tsv(timestamp, questions, question_count);
	    printf("������� �ۼ��Ǿ����ϴ�. ���ϸ� :  \"%s%\"\n", timestamp);
	    //����---------------------------------------------- 
	    write_tsv("questions.tsv", questions, question_count);
	    printf("�����ͺ��̽��� ���ŵǾ����ϴ�.\n");
	    //�����Ʈ ����------------------------------------------------------------------------- 
	    WriteReviewNote("questions review.txt", questions, question_count);
	    printf("���� ��Ʈ�� ����Ǿ����ϴ�.\n");
	    //html �������� Export------------------------------------------------------------------- 
	    write_html("questions review html.txt", questions, question_count);
	    printf("html�ҽ��� ����Ǿ����ϴ�.\n");
    	return 0;}
	else{
		getchar();
		q_num = 0;
		return -1;}
	
} 
