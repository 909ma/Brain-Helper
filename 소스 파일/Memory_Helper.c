#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
/////////////////
#include "read_tsv.h"
//#include "Question.h"
#include "variable.h"
#include "write_tsv.h"
#include "WriteReviewNote.h"
#include "write_html.h"
#include "getTotalLine.h"
#include "print_question.h"
#include "test.h"
////////////////

int main() {
	int question_line = getTotalLine("questions.tsv")+1;
    Question *questions = (Question*)malloc(sizeof(Question) * question_line);
    int question_count = 0;
    read_tsv("questions.tsv", questions, &question_count);    
	int typeQ; 
    int i;
    int q_num=0;
    int RandemModCycle = 0;
    int QuestionCycle = 0;
    int Mod1Start;
    int Mod1End;
    int Mod2End;
    int Mod4Count=0;
    int Mod4Exit=1;
    
	START :
		
    printf("랜덤모드, 자동 순차 모드, 선택 모드, 리뷰 모드 [1,2,3,4]\n");
    scanf("%d",&typeQ);
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
    printf("Results:\n");
    int CountCorrect = 0;
    int CountIncorrect = 0;
    int CountNoAnswer = 0;
    for (i = 1; i <= question_count; i++) {
    	if(questions[i].correct != 0 || questions[i].correct + questions[i].incorrect != 0)
    		CountCorrect += questions[i].correct;
    	if(questions[i].incorrect != 0||questions[i].correct+questions[i].incorrect != 0)
    		CountIncorrect += questions[i].incorrect;
    	if(questions[i].correct+questions[i].incorrect == 0)
    		CountNoAnswer ++;
    }
    float CountRating = (float)CountCorrect / (CountCorrect + CountIncorrect) * 100;
    printf("Correct : %d\nIncorrect : %d\nRating : %.2f%%\n\nNo Answer : %d\n",CountCorrect,CountIncorrect,CountRating,CountNoAnswer);
    time_t now;
    struct tm *local;
    char timestamp[25];

    time(&now);
    local = localtime(&now);
    strftime(timestamp, 28, "%Y-%m-%d %H %M %S.backup", local);

    printf("Backup at \"%s%\"\n", timestamp);
    write_tsv("questions.tsv", questions, question_count);
    write_tsv(timestamp, questions, question_count);
    WriteReviewNote("questions review.txt", questions, question_count);
    write_html("questions review html.txt", questions, question_count);
	getchar();
	
	int inputShutdown;
	printf("Are you want shutdown?[1/2]\n");
	scanf("%d", &inputShutdown);
	if(inputShutdown == 1){
		free(questions);
    	return 0;}
	else{
		getchar();
		q_num = 0;
		goto START;}
}
