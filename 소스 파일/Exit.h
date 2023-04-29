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
	//프로그램 종료 선택-------------------------------------------------------------------------------------- 
	int inputShutdown;
	printf("정말로 종료하시겠습니까? [1/2]\n");
	scanf("%d", &inputShutdown);
	if(inputShutdown == 1){
		//백업본 작성 ------------------------------------------------------- 
		time_t now;
	    struct tm *local;
	    char timestamp[25];
	    time(&now);
	    local = localtime(&now);
	    strftime(timestamp, 28, "%Y-%m-%d %H %M %S.backup", local);
	    write_tsv(timestamp, questions, question_count);
	    printf("백업본이 작성되었습니다. 파일명 :  \"%s%\"\n", timestamp);
	    //저장---------------------------------------------- 
	    write_tsv("questions.tsv", questions, question_count);
	    printf("데이터베이스가 갱신되었습니다.\n");
	    //리뷰노트 저장------------------------------------------------------------------------- 
	    WriteReviewNote("questions review.txt", questions, question_count);
	    printf("리뷰 노트가 저장되었습니다.\n");
	    //html 형식으로 Export------------------------------------------------------------------- 
	    write_html("questions review html.txt", questions, question_count);
	    printf("html소스가 저장되었습니다.\n");
    	return 0;}
	else{
		getchar();
		q_num = 0;
		return -1;}
	
} 
