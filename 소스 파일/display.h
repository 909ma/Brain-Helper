#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"
/* 
display();
���� ��� 
	1. ���� ��ȸ ���
	 
	2. ���� ���� ��� 
	3. ���� ���� ��� 
	4. ���� ���� ��� 
	
	5. ���� Ȯ�� ��� 
	
	6. ���� ���� ��� 
	
	7. ���� ��õ ���
	
	8. ���� ���� ��� 
	9. ���� 
	 	1) ��� ���� ���
	 	2) ���� �ʱ�ȭ ��� 
	
	0. ���� ��� 
	
	auto.
	���� ��Ʈ ���� ���
	��� ��� 
*/
int display(){
	system("cls");
	printf("1.  ���� ��ȸ\n");
	printf("2.  ���� ����\n");
	printf("3.  ���� ����\n");
	printf("4.  ���� ����\n");
	printf("5.  ���� Ȯ��\n");
	printf("6.  ���� ����\n");
	printf("7.  ���� ��õ\n");
	printf("8.  ���� ����\n");
	printf("9.  ����\n");
	printf("0.  ���α׷� ����\n"); 
	printf("\nInput : ");
    scanf("%d",&typeQ);
    
    if(typeQ>=0 && typeQ <=9){
    	return typeQ;
	}
	else{
		return -1;
	}
}
