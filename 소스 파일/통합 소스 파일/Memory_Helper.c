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
    int QuestionCount = 0;//�� ���� ���� �����ϴ� ���� 
    read_tsv("questions.tsv", questions, &QuestionCount);   
    //��� ���� --------------------------------------------------------------- 
	for(;;){
		typeQ = display();
		//printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//����� �ҽ� 
//		printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//����� �ҽ� 
//				getchar();
//				getchar();
		switch(typeQ){
			case 1:
				//1. ���� ��ȸ ���
//				printf("typeQ : %d\nQuestionNow : %d\n", typeQ,QuestionNow);//����� �ҽ� 
//				getchar();
//				getchar();
				ViewSubject(questions, &QuestionCount);
				break;
			case 2:
				//2. ���� ���� ��� 
				SequentialQuiz(QuestionCount, questions);
				break;
			case 3:
				//3. ���� ���� ��� 
				RandomQuiz(QuestionCount, questions);
				break;
			case 4:
				//4. ���� ���� ��� 
				SelectiveQuiz(QuestionCount, questions);
				break;
			case 5:
				//5. ���� Ȯ�� ��� CheckGrade();<-- �̹� �־ �� ����. 
				//���� ��� ------------------------------------------------------------ 
	    		printRecord(questions, QuestionCount);
	    		getchar();
				break;
			case 6:
				//6. ���� ���� ��� 
				//DailyHomework();
				break;
			case 7:
				//7. ���� ��õ ���
				//QuestionRecommendation();
				break;
			case 8:
				//8. ���� ���� ��� 
				//QuestionReview();
				break;
			case 9:
				/*
				9. ���� 
		 			1) ��� ���� ���
		 				ChangeLanguage();
		 			2) ���� �ʱ�ȭ ��� 
		 				ResetGrade();
		 		*/
		 		//Settings();
				break;
			case 0:
				//0. ���� ��� 
				Mod0 = Exit(&QuestionNow, questions, QuestionCount);
				if(Mod0 == 0){
					free(questions);
			    	return 0;
				}
				//printf("typeQ : %d\nq_num : %d\n", typeQ,q_num);//����� �ҽ� 
				break;
			case -1:
				printf("�߸��� �Է��Դϴ�.\n");
				getchar();
				getchar();
				break;
		}
	}
}
