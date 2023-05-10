/*
	@Author   : 909ma
	@Date     : 2023. 5. 11
	@Function : tsv ������ json ���Ϸ� ��ȯ 
 */
 #pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"

//Web Porting
void write_json(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "{\n");
    fprintf(fp, "  \"questions\": [\n");
    
  
	//���� ������ ���� ��� �κ� 
    int i, j, k;
    for (i = 1; i <= question_count; i++) {
    	//���� ��� �κ� 
		fprintf(fp, "    {\n");
		fprintf(fp, "      \"Question%d\": \"",i);
        k = 0;
        while(questions[i].question[k] != '\0') {
            if(questions[i].question[k] == '.' || questions[i].question[k] == '?') {
                fprintf(fp, "%c<br>", questions[i].question[k]);
            } else {
                fprintf(fp, "%c", questions[i].question[k]);
            }
            k++;
        }
		fprintf(fp, "\",\n");
		//���� ��� �κ� 
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "      \"Answer %d\": \"%s\"", j+1,questions[i].answers[j]);
            if(j == questions[i].answer_count - 1){
				fprintf(fp, "\n");
            	
			}
			else{
				fprintf(fp, ",\n");
			}
        }
        if(i == question_count){
        	fprintf(fp, "      }\n");
		}
		else{
			fprintf(fp, "      },\n");
		}
    }
    fprintf(fp, "  ]\n");
    fprintf(fp, "}");
    fclose(fp);
}
