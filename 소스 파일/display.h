#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"
/* 
display();
문제 기능 
	1. 과목 조회 기능
	 
	2. 순차 출제 기능 
	3. 랜덤 출제 기능 
	4. 선택 출제 기능 
	
	5. 성적 확인 기능 
	
	6. 일일 숙제 기능 
	
	7. 문제 추천 기능
	
	8. 문제 리뷰 기능 
	9. 설정 
	 	1) 언어 변경 기능
	 	2) 성적 초기화 기능 
	
	0. 종료 기능 
	
	auto.
	리뷰 노트 생성 기능
	백업 기능 
*/
int display(){
	system("cls");
	printf("1.  과목 조회\n");
	printf("2.  순차 출제\n");
	printf("3.  랜덤 출제\n");
	printf("4.  선택 출제\n");
	printf("5.  성적 확인\n");
	printf("6.  일일 숙제\n");
	printf("7.  문제 추천\n");
	printf("8.  문제 리뷰\n");
	printf("9.  설정\n");
	printf("0.  프로그램 종료\n"); 
	printf("\nInput : ");
    scanf("%d",&typeQ);
    
    if(typeQ>=0 && typeQ <=9){
    	return typeQ;
	}
	else{
		return -1;
	}
}
