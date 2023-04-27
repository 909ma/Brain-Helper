#pragma warning(disable:4996)
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read_tsv(const char* filename, Question* questions, int* question_count) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to owpen file %s\n", filename);
        exit(1);
    }
    char line[1024];
    int count = 0;
    while (fgets(line, 1024, fp)) {
        if (count == 0) {
            count++;
            continue;
        }

        char* tmp = strdup(line);
        char* token = strtok(tmp, "\t");
        questions[count].no = atoi(token);

        token = strtok(NULL, "\t");
        questions[count].correct = atoi(token);

        token = strtok(NULL, "\t");
        questions[count].incorrect = atoi(token);

        token = strtok(NULL, "\t");
        strcpy(questions[count].question, token);

        token = strtok(NULL, "\t");
        int idx = 0;
        while (token != NULL) {
    	size_t token_len = strlen(token);
    		if (token[token_len-1] == '\n') {
        		token[token_len-1] = '\0'; // Replace the \n at the end of the string with a null character
    		}
    	strcpy(questions[count].answers[idx], token);
    	idx++;
    	token = strtok(NULL, "\t");
	}
        questions[count].answer_count = idx;
        count++;
        free(tmp);
    }
    *question_count = count-1;
    fclose(fp);
}