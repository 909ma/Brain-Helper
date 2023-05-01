#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "variable.h"

//Web Porting
void write_html(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "<!-- https://github.com/909ma -->\n");
    fprintf(fp, "<!DOCTYPE html>\n");
    fprintf(fp, "<html lang=\"kr\">\n");
    fprintf(fp, "  <head>\n");
    fprintf(fp, "    <meta charset=\"UTF-8\" />\n");
    fprintf(fp, "    <title>정보처리기사 실기 요약</title>\n");
    fprintf(fp, "    <link rel=\"stylesheet\" href=\"index.css\" />\n");
    fprintf(fp, "  </head>\n");
    fprintf(fp, "  <body>\n");
    int i, j, k;
    fprintf(fp, "<div class=\"question-container\">\n");
    for (i = 1; i <= question_count; i++) {
        fprintf(fp, "<div class=\"question\" id=\"question%d\">\n",i);
        fprintf(fp, "<div>\n<p>Question %d.\n<br>\n", i);
        k = 0;
        while(questions[i].question[k] != '\0') {
            if(questions[i].question[k] == '.' || questions[i].question[k] == '?') {
                fprintf(fp, "%c\n<br>", questions[i].question[k]);
            } else {
                fprintf(fp, "%c", questions[i].question[k]);
            }
            k++;
        }
        fprintf(fp,"\n</p>\n<br>\n<p class=\"answer\">");
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "\nAnswer %d : %s<br>", j+1,questions[i].answers[j]);
        }
        fprintf(fp, "\n</p>\n</div>\n<br>\n<br>\n<br>\n</div>\n");
    }
    fprintf(fp, "\n</div>");
    fprintf(fp, "    <div class=\"gotoB\">\n");
    fprintf(fp, "      <button  onclick=\"goToQuestion()\">Go to</button>\n");
    fprintf(fp, "      <input type=\"number\" id=\"questionNumInput\" />\n");
    fprintf(fp, "    </div>\n");
    fprintf(fp, "      <button class=\"show\">Show</button>\n");
    fprintf(fp, "      <button class=\"backB\" onclick=\"backQuestion()\">Back</button>\n");
    fprintf(fp, "      <button class=\"nextB\" onclick=\"nextQuestion()\">Next</button>\n");
    fprintf(fp, "    <br />\n");
    fprintf(fp, "    <script src=\"index.js\"></script>\n");
    fprintf(fp, "  </body>\n");
    fprintf(fp, "</html>\n");
    fclose(fp);
}
