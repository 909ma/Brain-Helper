#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variable.h"
#include "test.h"
//2. ���� ���� ��� 
int SequentialQuiz(int QuestionCount, Question* questions){
	if(QuestionNow==0){//������ �� ���� ���� ���� ��ġ 
		//���� ���� ��ȣ �ޱ�-------------------------------------------------------------------- 
		printf("�� �� ���� �����ϰ� �ͳ���?(1������ %d������ ����)\n", QuestionCount);
		scanf("%d", &QuestionStart); 
		if(QuestionStart>=1 && QuestionStart<=QuestionCount){
			getchar();
		}
		else{
			printf("�߸��� ���� �����Դϴ�. �ٽ� ó������ ���ư��ϴ�. \n");
			getchar();
			getchar();
			return -1;
		}
		//���� �� ��ȣ �ޱ�------------------------------------------------------------------------ 
		printf("�� ������ Ǯ�� �ͳ���?(%d������ %d������ ����)\n", QuestionStart, QuestionCount);
		scanf("%d", &QuestionEnd);
		if(QuestionEnd>=QuestionStart && QuestionEnd<=QuestionCount){
			getchar();
		}
		else{
			printf("�߸��� ���� �����Դϴ�. �ٽ� ó������ ���ư��ϴ�. \n");
			getchar();
			getchar();
			return -1;
		}
		QuestionNow = QuestionStart;
		getchar();
	}
	//���� ���� ���� ��Ʈ--------------------------------------------------------------------------- 
	for(;QuestionNow<=QuestionEnd;QuestionNow++){
		system("cls");
		test(&questions[QuestionNow]);
    	getchar();
	}
	QuestionNow=0;//���� ��ȣ�� �ʱ�ȭ����� �������� ��� �����ϴ�. 
	return 0;
}
