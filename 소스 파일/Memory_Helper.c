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
////////////////

int main() {
	int question_line = getTotalLine("questions.tsv")+1;
    Question *questions = (Question*)malloc(sizeof(Question) * question_line);
    int question_count = 0;
    read_tsv("questions.tsv", questions, &question_count);   
    //모드 선택 --------------------------------------------------------------- 
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
    //성적 출력 ------------------------------------------------------------ 
    printRecord(questions, question_count);

	//백업본 작성 ------------------------------------------------------- 
	time_t now;
    struct tm *local;
    char timestamp[25];
    time(&now);
    local = localtime(&now);
    strftime(timestamp, 28, "%Y-%m-%d %H %M %S.backup", local);

    printf("Backup at \"%s%\"\n", timestamp);
    write_tsv(timestamp, questions, question_count);
    //저장---------------------------------------------- 
    write_tsv("questions.tsv", questions, question_count);
    //리뷰노트 저장------------------------------------------------------------------------- 
    WriteReviewNote("questions review.txt", questions, question_count);
    //html 형식으로 Export------------------------------------------------------------------- 
    write_html("questions review html.txt", questions, question_count);
	getchar();
	//프로그램 종료 선택-------------------------------------------------------------------------------------- 
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
