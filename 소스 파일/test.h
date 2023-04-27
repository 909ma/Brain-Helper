#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void test(Question* q) {
    int i, j;
    int percent;
	if( q->correct + q->incorrect == 0)
		percent = 0;
	else
		percent = (float)q->correct/(q->correct + q->incorrect)*100;
    printf("\nQuestion %d: O(%d), X(%d), rate : %d%% \n", q->no,q->correct,q->incorrect,percent);
	for(int kk1 = 0; kk1 < MAX_QUESTION_INPUT ; kk1++){
		if(q->question[kk1] != '.' && q->question[kk1] != '?'){
			printf("%c",q->question[kk1]);
		}
		else{
			printf("%c\n",q->question[kk1]);
		}
	}
	printf("\n");
    int correct_count = 0;
    char answer[MAX_ANSWER_INPUT][MAX_ANSWER_LEN];
    for (i = 0; i < q->answer_count; i++) {
        printf("Enter answer %d/%d: ", i+1, q->answer_count);
        fgets(answer[i], MAX_ANSWER_LEN, stdin);
        answer[i][strcspn(answer[i], "\n")] = 0;
        int match = 1;
        for (j = 0; j < q->answer_count; j++) {
            if (strlen(answer[i]) != strlen(q->answers[j])) {
                continue;
            }
            int k;
            for (k = 0; k < strlen(answer[i]); k++) {
                if (tolower(answer[i][k]) != tolower(q->answers[j][k])) {
                    break;
                }
            }
            if (k == strlen(answer[i])) {
                correct_count++;
                match = 0;
                break;
            }
        }
        if (match) {
        }
    }
    if (correct_count == q->answer_count) {
        printf("\nYou answered all questions correctly!\n");
    } else {
        printf("\nYou answered %d/%d questions correctly.\n", correct_count, q->answer_count);
    }
    printf("The correct answer is\n\n");
    for (i = 0; i < q->answer_count; i++) {
        printf("Answer %d: %s\n", i+1, q->answers[i]);
    }
    int inputA;
    printf("\nDo you want to mark it as correct?[1/2]\n");
    scanf("%d",&inputA);
    if(inputA == Yes){
    	printf("I will mark it as correct.\n");
    	q->correct += 1;
	}
	else if(inputA == No){
		printf("I will mark it as incorrect.\n");
		q->incorrect += 1;
	}
	else
		printf("I will not make any changes.\n");
}
