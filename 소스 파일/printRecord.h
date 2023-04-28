#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "variable.h"

void printRecord(Question* questions, int question_count){
    printf("Results:\n");
    int CountCorrect = 0;
    int CountIncorrect = 0;
    int CountNoAnswer = 0;
    for (int i = 1; i <= question_count; i++) {
    	if(questions[i].correct != 0 || questions[i].correct + questions[i].incorrect != 0)
    		CountCorrect += questions[i].correct;
    	if(questions[i].incorrect != 0||questions[i].correct+questions[i].incorrect != 0)
    		CountIncorrect += questions[i].incorrect;
    	if(questions[i].correct+questions[i].incorrect == 0)
    		CountNoAnswer ++;
    }
    float CountRating = (float)CountCorrect / (CountCorrect + CountIncorrect) * 100;
    printf("Correct : %d\nIncorrect : %d\nRating : %.2f%%\n\nNo Answer : %d\n",CountCorrect,CountIncorrect,CountRating,CountNoAnswer);
}
