#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"
#include "test.h"

int SelectiveQuiz(int QuestionCount, Question* questions){
	//���� ���� ���� ��Ʈ--------------------------------------------------------------------------- 
	for(;;){
		printf("�� �� ������ Ǯ��  �ͳ���?(1������ %d������ ����, 0 �Է� �� ����)\n", QuestionCount);
		scanf("%d", &QuestionNow); 
		if(QuestionNow>=1&&QuestionNow<=QuestionCount) {
			getchar();
		}
		else if(QuestionNow==0){
			break;
		}
		else{
			printf("�߸��� ���� �����Դϴ�. �ٽ� ó������ ���ư��ϴ�. \n");
			getchar();
			getchar();
			return -1;
		}
		system("cls");
		test(&questions[QuestionNow]);
    	getchar();
	}
	QuestionNow=0;//���� ��ȣ�� �ʱ�ȭ����� �������� ��� �����ϴ�. 
	return 0;
}
