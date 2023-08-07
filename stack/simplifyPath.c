#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_char.h"

int main() {
	
    char* str = "/a//b/./../c";
    stack p;

    // Initialize the stack
    init(&p);

    // Process the path components
    int len = strlen(str);
    int start = 1; // Start from index 1 to skip the first '/'
    int end = 1;

    while (end <= len) {
        if (str[end] == '/' || str[end] == '\0') {
			if (end > start) {
                char* token = (char*)malloc((end - start + 1) * sizeof(char));
                strncpy(token, &str[start], end - start);
                token[end - start] = '\0';
                if (strcmp(token, "..") == 0) {
                    if (!is_empty(&p)) {
                        pop(&p);
                    }
                } else if (strcmp(token, ".") != 0) {
                    // Push the directory name onto the stack (skip ".")
                    push(&p, token);
                }
                free(token);
            }
            
            start = end + 1;
        }
        
        end++;
    }

    // Construct the simplified path from the stack elements
    char simplifiedPath[1024] = ""; // Assuming max path length of 1024, adjust as needed

    while (!is_empty(&p)) {
        char* dirName = pop(&p);
        char temp[1024] = "/";
        strcat(temp, dirName);
        strcat(temp, simplifiedPath);
        strcpy(simplifiedPath, temp);
    }

    if (strlen(simplifiedPath) == 0) {
        strcat(simplifiedPath, "/");
    }

    printf("Simplified Path: %s\n", simplifiedPath);

    // Clear the stack
    clear(&p);

    return 0;
}

