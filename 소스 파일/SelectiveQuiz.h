#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"
#include "test.h"

int SelectiveQuiz(int QuestionCount, Question* questions){
	//실제 문제 출제 파트--------------------------------------------------------------------------- 
	for(;;){
		printf("몇 번 문제를 풀고  싶나요?(1번부터 %d번까지 가능, 0 입력 시 종료)\n", QuestionCount);
		scanf("%d", &QuestionNow); 
		if(QuestionNow>=1&&QuestionNow<=QuestionCount) {
			getchar();
		}
		else if(QuestionNow==0){
			break;
		}
		else{
			printf("잘못된 숫자 기입입니다. 다시 처음으로 돌아갑니다. \n");
			getchar();
			getchar();
			return -1;
		}
		system("cls");
		test(&questions[QuestionNow]);
    	getchar();
	}
	QuestionNow=0;//문제 번호를 초기화해줘야 다음에도 사용 가능하다. 
	return 0;
}
