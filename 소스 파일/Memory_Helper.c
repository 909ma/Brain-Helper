#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
/////////////////
#include "variable.h"
#include "read_tsv.h"
//#include "Question.h"
#include "write_tsv.h"
#include "WriteReviewNote.h"
#include "write_html.h"
#include "getTotalLine.h"
#include "print_question.h"
#include "test.h"
#include "printRecord.h"
#include "display.h" 
#include "SequentialQuiz.h"
#include "Language.h"
#include "Exit.h"
 
int main() {
	int question_line = getTotalLine("questions.tsv")+1;
    Question *questions = (Question*)malloc(sizeof(Question) * question_line);
    int question_count = 0;//총 문제 갯수 저장하는 변수 
    read_tsv("questions.tsv", questions, &question_count);   
    //모드 선택 --------------------------------------------------------------- 
	START :
	for(;;){
		typeQ = display();
		//printf("typeQ : %d\nq_num : %d\n", typeQ,q_num);//디버깅 소스 
		switch(typeQ){
			case 1:
				//1. 과목 조회 기능
				//ViewSubject();
				break;
			case 2:
				//2. 순차 출제 기능 
				SequentialQuiz(question_count, questions);
				break;
			case 3:
				//3. 랜덤 출제 기능 
				//RandomQuiz();
				break;
			case 4:
				//4. 선택 출제 기능 
				//SelectiveQuiz();
				break;
			case 5:
				//5. 성적 확인 기능 CheckGrade();<-- 이미 있어서 안 만듬. 
				//성적 출력 ------------------------------------------------------------ 
	    		printRecord(questions, question_count);
	    		getchar();
				break;
			case 6:
				//6. 일일 숙제 기능 
				//DailyHomework();
				break;
			case 7:
				//7. 문제 추천 기능
				//QuestionRecommendation();
				break;
			case 8:
				//8. 문제 리뷰 기능 
				//QuestionReview();
				break;
			case 9:
				/*
				9. 설정 
		 			1) 언어 변경 기능
		 				ChangeLanguage();
		 			2) 성적 초기화 기능 
		 				ResetGrade();
		 		*/
		 		//Settings();
				break;
			case 0:
				//0. 종료 기능 
				Mod0 = Exit(&q_num, questions, question_count);
				if(Mod0 == 0){
					free(questions);
			    	return 0;
				}
				//printf("typeQ : %d\nq_num : %d\n", typeQ,q_num);//디버깅 소스 
				break;
			case -1:
				printf("잘못된 입력입니다.\n");
				getchar();
				getchar();
				break;
		}
	}
	/*
    //printf("랜덤모드, 자동 순차 모드, 선택 모드, 리뷰 모드 [1,2,3,4]\n");
    if(typeQ == 1){
    	printf("How many resolve Question? (Max : %d)\n",question_count);
    	scanf("%d",&RandemModCycle);
    	printf("Enter to start question number (1-%d) or 0 to exit: ", question_count);
        scanf("%d", &Mod1Start);
        getchar();
        printf("Enter to end question number (1-%d) or 0 to exit: ", question_count);
        scanf("%d", &Mod1End);
        getchar();
    	if(RandemModCycle <0 || RandemModCycle>question_count){
    		printf("Invalid Question Cycle.\n");
    		getchar();
    		return 1;
		}
	}
    getchar();
    while (1) {
		system("cls");
		if(typeQ==1){//랜덤 모드
			if(QuestionCycle >= RandemModCycle)
				break;
        	QuestionCycle ++;
			srand(time(NULL));
        	q_num=rand()%(Mod1End-Mod1Start)+1;
        	printf("%d/%d\n",QuestionCycle,RandemModCycle);
		}
		else if(typeQ==2){//자동 순차 모드
			if(q_num==0){
        		printf("Enter to start question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &q_num);
        		getchar();
        		printf("Enter to end question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &Mod2End);
        		getchar();
        		q_num --;
			}
			q_num ++;
        	if (q_num == 0||q_num>Mod2End) {
        	    break;
        	}
    	    if (q_num < 1) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==3){//선택 모드 
        	printf("Enter question number (1-%d) or 0 to exit: ", question_count);
        	scanf("%d", &q_num);
        	getchar();

        	if (q_num == 0) {
        	    break;
        	}

    	    if (q_num < 1 || q_num > question_count) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==4){//리뷰 모드 
			if(Mod4Count == 0){
				printf("Enter start question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &q_num);
        		getchar();	
        		Mod4Count=1;
        		q_num --;
			}
        	else if(Mod4Count==1){
        		printf("Enter 0 to exit: ");
        		scanf("%d", &Mod4Exit);
        		getchar();
			}
			q_num ++;
			
        	if (q_num == 0 || Mod4Exit == 0) {
        	    break;
        	}

    	    if (q_num < 1 || q_num > question_count) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==0)
    		break;
        test(&questions[q_num]);
    	getchar();
    }
    */
}
