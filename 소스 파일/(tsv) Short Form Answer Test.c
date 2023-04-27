#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTION_INPUT 20000
#define MAX_ANSWER_INPUT 3
#define MAX_ANSWER_LEN 2048
#define Yes 1
#define No 2

//tsv 데이터베이스 구조
typedef struct {
    int no;
    int correct;
    int incorrect;
    char question[MAX_QUESTION_INPUT];
    char answers[MAX_ANSWER_INPUT][MAX_ANSWER_LEN];
    int answer_count;
} Question;

//tsv 파일 읽는 함수
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

//tsv 데이터베이스 갱신
void write_tsv(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "no\tcorrect\tincorrect\tquestion\tanswer1\tanswer2\tanswer3\n");
    int i, j;
    for (i = 1; i <= question_count; i++) {
        fprintf(fp, "%d\t%d\t%d\t%s", i, questions[i].correct, questions[i].incorrect, questions[i].question);
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "\t%s", questions[i].answers[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

//Review note 작성
void WriteReviewNote(const char* filename, Question* questions, int question_count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "https://github.com/909ma\n\n\n");
    int i, j, k;
    for (i = 1; i <= question_count; i++) {
        fprintf(fp, "No. %d\t correct : %d,\t incorrect : %d\nQ : ", i, questions[i].correct, questions[i].incorrect);
        k = 0;
        while(questions[i].question[k] != '\0') {
            if(questions[i].question[k] == '.' || questions[i].question[k] == '?') {
                fprintf(fp, "%c\n", questions[i].question[k]);
            } else {
                fprintf(fp, "%c", questions[i].question[k]);
            }
            k++;
        }
        for (j = 0; j < questions[i].answer_count; j++) {
            fprintf(fp, "\nAnswer %d : %s", j+1,questions[i].answers[j]);
        }
        fprintf(fp, "\n\n\n");
    }
    fclose(fp);
}

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

//파일의 Line 수를 측정한다.
int getTotalLine(char* filename) { // Code that gets the total number of lines in a csv file
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}


void print_question(Question* q) {
    printf("Question %d:\n", q->no);
    printf("%s\n", q->question);
}

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

int main() {
	int question_line = getTotalLine("questions.tsv")+1;
    Question *questions = (Question*)malloc(sizeof(Question) * question_line);
    int question_count = 0;
    read_tsv("questions.tsv", questions, &question_count);    
	int typeQ; 
    int i;
    int q_num=0;
    int RandemModCycle = 0;
    int QuestionCycle = 0;
    int Mod1Start;
    int Mod1End;
    int Mod2End;
    int Mod4Count=0;
    int Mod4Exit=1;
    
	START :
		
    printf("랜덤모드, 자동 순차 모드, 선택 모드, 리뷰 모드 [1,2,3,4]\n");
    scanf("%d",&typeQ);
    if(typeQ == 1){
    	printf("How many resolve Question? (Max : %d)\n",question_count);
    	scanf("%d",&RandemModCycle);
    	printf("Enter to start question number (1-%d) or 0 to exit: ", question_count);
        scanf("%d", &Mod1Start);
        getchar();
        printf("Enter to end question number (1-%d) or 0 to exit: ", question_count);
        scanf("%d", &Mod1End);
        getchar();
    	if(RandemModCycle <0 || RandemModCycle>question_count){
    		printf("Invalid Question Cycle.\n");
    		getchar();
    		return 1;
		}
	}
    getchar();
    while (1) {
		system("cls");
		if(typeQ==1){//랜덤 모드
			if(QuestionCycle >= RandemModCycle)
				break;
        	QuestionCycle ++;
			srand(time(NULL));
        	q_num=rand()%(Mod1End-Mod1Start)+1;
        	printf("%d/%d\n",QuestionCycle,RandemModCycle);
		}
		else if(typeQ==2){//자동 순차 모드
			if(q_num==0){
        		printf("Enter to start question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &q_num);
        		getchar();
        		printf("Enter to end question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &Mod2End);
        		getchar();
        		q_num --;
			}
			q_num ++;
        	if (q_num == 0||q_num>Mod2End) {
        	    break;
        	}
    	    if (q_num < 1) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==3){//선택 모드 
        	printf("Enter question number (1-%d) or 0 to exit: ", question_count);
        	scanf("%d", &q_num);
        	getchar();

        	if (q_num == 0) {
        	    break;
        	}

    	    if (q_num < 1 || q_num > question_count) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==4){//리뷰 모드 
			if(Mod4Count == 0){
				printf("Enter start question number (1-%d) or 0 to exit: ", question_count);
        		scanf("%d", &q_num);
        		getchar();	
        		Mod4Count=1;
        		q_num --;
			}
        	else if(Mod4Count==1){
        		printf("Enter 0 to exit: ");
        		scanf("%d", &Mod4Exit);
        		getchar();
			}
			q_num ++;
			
        	if (q_num == 0 || Mod4Exit == 0) {
        	    break;
        	}

    	    if (q_num < 1 || q_num > question_count) {
        	    printf("Invalid question number.\n");
            	continue;
        	}
		}
		else if(typeQ==0)
    		break;
        test(&questions[q_num]);
    	getchar();
    	
    }
    printf("Results:\n");
    int CountCorrect = 0;
    int CountIncorrect = 0;
    int CountNoAnswer = 0;
    for (i = 1; i <= question_count; i++) {
    	if(questions[i].correct != 0 || questions[i].correct + questions[i].incorrect != 0)
    		CountCorrect += questions[i].correct;
    	if(questions[i].incorrect != 0||questions[i].correct+questions[i].incorrect != 0)
    		CountIncorrect += questions[i].incorrect;
    	if(questions[i].correct+questions[i].incorrect == 0)
    		CountNoAnswer ++;
    }
    float CountRating = (float)CountCorrect / (CountCorrect + CountIncorrect) * 100;
    printf("Correct : %d\nIncorrect : %d\nRating : %.2f%%\n\nNo Answer : %d\n",CountCorrect,CountIncorrect,CountRating,CountNoAnswer);
    time_t now;
    struct tm *local;
    char timestamp[25];

    time(&now);
    local = localtime(&now);
    strftime(timestamp, 28, "%Y-%m-%d %H %M %S.backup", local);

    printf("Backup at \"%s%\"\n", timestamp);
    write_tsv("questions.tsv", questions, question_count);
    write_tsv(timestamp, questions, question_count);
    WriteReviewNote("questions review.txt", questions, question_count);
    write_html("questions review.html", questions, question_count);
	getchar();
	
	int inputShutdown;
	printf("Are you want shutdown?[1/2]\n");
	scanf("%d", &inputShutdown);
	if(inputShutdown == 1){
		free(questions);
    	return 0;}
	else{
		getchar();
		q_num = 0;
		goto START;}
}
