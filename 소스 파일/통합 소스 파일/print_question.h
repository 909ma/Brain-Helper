#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void print_question(Question* q) {
    printf("Question %d:\n", q->no);
    printf("%s\n", q->question);
}
