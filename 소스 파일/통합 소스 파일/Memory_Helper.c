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
#include "Language.h"
#include "Exit.h"
#include "SequentialQuiz.h"
#include "RandomQuiz.h"
#include "SelectiveQuiz.h"
#include "ViewSubject.h"
 
int main() {
	int question_line = getTotalLine("questions.tsv")+1;
    Question *questions = (Question*)malloc(sizeof(Question) * question_line);
    int QuestionCount = 0;//총 문제 갯수 저장하는 변수 
    read_tsv("questions.tsv", questions, &QuestionCount);   
    //모드 선택 --------------------------------------------------------------- 
	for(;;){
		typeQ = display();
		//printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//디버깅 소스 
//		printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//디버깅 소스 
//				getchar();
//				getchar();
		switch(typeQ){
			case 1:
				//1. 과목 조회 기능
//				printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//디버깅 소스 
//				getchar();
//				getchar();
				ViewSubject(questions, &QuestionCount);
				break;
			case 2:
				//2. 순차 출제 기능 
				SequentialQuiz(QuestionCount, questions);
				break;
			case 3:
				//3. 랜덤 출제 기능 
				RandomQuiz(QuestionCount, questions);
				break;
			case 4:
				//4. 선택 출제 기능 
				SelectiveQuiz(QuestionCount, questions);
				break;
			case 5:
				//5. 성적 확인 기능 CheckGrade();<-- 이미 있어서 안 만듬. 
				//성적 출력 ------------------------------------------------------------ 
	    		printRecord(questions, QuestionCount);
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
				Mod0 = Exit(&QuestionNow, questions, QuestionCount);
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
}
