#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // Read from stdin
        char userInput[1000];
        printf("Enter some text:\n");
        
        while (fgets(userInput, sizeof(userInput), stdin) != NULL) {
            // Process each line and returns a pointer to the buffer(userInput) and ensures not null
            int count = 0;
            while (userInput[count] != '\0') {
                //If space, we print a new line which indicates a new word
                if (isspace(userInput[count])) {
                    if (count > 0 && !isspace(userInput[count-1])) {
                        printf("\n");
                    }
                }
                //If not a space, then we just print the character with NO NEW LINE
                else {
                    printf("%c", userInput[count]);
                }
                count++;
            }
            
        }
    } else {
        // We wanna read from the files
        for (int i = 1; i < argc; i++) {
            //fopen opens a file and returns a pointer to read/write 
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Error: Cannot open file '%s'\n", argv[i]);
                continue;
            }
            
            char line[1000];
            while (fgets(line, sizeof(line), file) != NULL) {
                // Run the same function as the stdin but for each individual file
                int count = 0;
                while (line[count] != '\0') {
                    if (isspace(line[count])) {
                        if (count > 0 && !isspace(line[count-1])) {
                            printf("\n");
                        }
                    } else {
                        printf("%c", line[count]);
                    }
                    count ++;
                
                }
                
            }
            //DONT FORGET TO CLOSE THE FILE
            fclose(file);
        }
    }
    return 0;
}
