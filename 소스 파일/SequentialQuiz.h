#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variable.h"
//2. ���� ���� ��� 
int SequentialQuiz(int question_count, Question* questions){
	if(q_num==0){//������ �� ���� ���� ���� ��ġ 
		printf("�� �� ���� �����ϰ� �ͳ���?(1������ %d������ ����)\n", question_count);
		scanf("%d", &q_num);
		if(q_num>=1 && q_num<=question_count){
			getchar();
		}
		else{
			printf("�߸��� ���� �����Դϴ�. �ٽ� ó������ ���ư��ϴ�. \n");
			return -1;
		}
		printf("�� ������ Ǯ�� �ͳ���?(%d������ %d������ ����)\n", q_num, question_count);
		scanf("%d", &Mod2End);
		if(Mod2End>=q_num && Mod2End<=question_count){
			getchar();
		}
		else{
			printf("�߸��� ���� �����Դϴ�. �ٽ� ó������ ���ư��ϴ�. \n");
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
