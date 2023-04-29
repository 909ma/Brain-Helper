#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variable.h"
#include "test.h"
//2. 순차 출제 기능 
int SequentialQuiz(int QuestionCount, Question* questions){
	if(QuestionNow==0){//문구를 한 번만 띄우기 위한 장치 
		//문제 시작 번호 받기-------------------------------------------------------------------- 
		printf("몇 번 부터 시작하고 싶나요?(1번부터 %d번까지 가능)\n", QuestionCount);
		scanf("%d", &QuestionStart); 
		if(QuestionStart>=1 && QuestionStart<=QuestionCount){
			getchar();
		}
		else{
			printf("잘못된 숫자 기입입니다. 다시 처음으로 돌아갑니다. \n");
			getchar();
			getchar();
			return -1;
		}
		//문제 끝 번호 받기------------------------------------------------------------------------ 
		printf("몇 번까지 풀고 싶나요?(%d번부터 %d번까지 가능)\n", QuestionStart, QuestionCount);
		scanf("%d", &QuestionEnd);
		if(QuestionEnd>=QuestionStart && QuestionEnd<=QuestionCount){
			getchar();
		}
		else{
			printf("잘못된 숫자 기입입니다. 다시 처음으로 돌아갑니다. \n");
			getchar();
			getchar();
			return -1;
		}
		QuestionNow = QuestionStart;
		getchar();
	}
	//실제 문제 출제 파트--------------------------------------------------------------------------- 
	for(;QuestionNow<=QuestionEnd;QuestionNow++){
		system("cls");
		test(&questions[QuestionNow]);
    	getchar();
	}
	QuestionNow=0;//문제 번호를 초기화해줘야 다음에도 사용 가능하다. 
	return 0;
}
