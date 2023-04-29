#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variable.h"
//2. 순차 출제 기능 
int SequentialQuiz(int question_count, Question* questions){
	if(q_num==0){//문구를 한 번만 띄우기 위한 장치 
		printf("몇 번 부터 시작하고 싶나요?(1번부터 %d번까지 가능)\n", question_count);
		scanf("%d", &q_num);
		if(q_num>=1 && q_num<=question_count){
			getchar();
		}
		else{
			printf("잘못된 숫자 기입입니다. 다시 처음으로 돌아갑니다. \n");
			return -1;
		}
		printf("몇 번까지 풀고 싶나요?(%d번부터 %d번까지 가능)\n", q_num, question_count);
		scanf("%d", &Mod2End);
		if(Mod2End>=q_num && Mod2End<=question_count){
			getchar();
		}
		else{
			printf("잘못된 숫자 기입입니다. 다시 처음으로 돌아갑니다. \n");
			return -1;
		}
		getchar();
	}
	for(;q_num<=Mod2End;q_num++){
		system("cls");
		test(&questions[q_num]);
    	getchar();
	}
	return 0;
}
