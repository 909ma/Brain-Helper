#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "SubjectRead_tsv.h"

char* ViewSubject(Question* questions, int* QuestionCount) {
    DIR *dir;
    struct dirent *ent;
    char *filename_pattern = "";
    char *extension = ".tsv";

    if ((dir = opendir("./subject/")) != NULL) {
        // Print the list of files
        int file_count = 0;
        printf("Subject list:\n");
        while ((ent = readdir(dir)) != NULL) {
            // Check if the file name matches the pattern
            if (strstr(ent->d_name, filename_pattern) == ent->d_name) {
                // Check if the file extension is ".tsv"
                if (strstr(ent->d_name, extension) != NULL && strcmp(strstr(ent->d_name, extension), extension) == 0) {
                    printf("%d. %s\n", ++file_count, ent->d_name);
                }
            }
        }
        closedir(dir);

        // Ask the user to choose a file
        printf("Choose a subject file (enter a number): ");
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > file_count) {
            printf("Invalid choice.\n");
            return NULL;
        }

        // Print the selected file name
        if ((dir = opendir("./subject/")) != NULL) {
            int selected_file_count = 0;
            while ((ent = readdir(dir)) != NULL) {
                if (strstr(ent->d_name, filename_pattern) == ent->d_name) {
                    if (strstr(ent->d_name, extension) != NULL && strcmp(strstr(ent->d_name, extension), extension) == 0) {
                        selected_file_count++;
                        if (selected_file_count == choice) {
                            printf("Selected file: %s\n", ent->d_name);
                            SubjectRead_tsv(ent->d_name, questions, &QuestionCount);//과목 불러오기 
                            
	    					write_tsv("questions.tsv", questions, QuestionCount);//과목 저장하기 
                            break;
                        }
                    }
                }
            }
            closedir(dir);
        } else {
            perror("");
            return NULL;
        }
    } else {
        perror("");
        return NULL;
    }
    return ent->d_name;
}
