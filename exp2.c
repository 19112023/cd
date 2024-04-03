//Name - Sadhana Sharma
//Enroll- 21UCS037
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 30

// Function to check if a string is a keyword
int isKeyword(char *str) {
    char keywords[][10] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1; // It is a keyword
        }
    }
    return 0; // It is not a keyword
}

int main() {
    FILE *inputFile, *identifiersFile, *keywordsFile, *integersFile, *operatorsFile;
    char c, token[MAX_IDENTIFIER_LENGTH];
    int tokenIndex = 0;
    int inComment = 0; // Flag to check if inside a comment
    int inPreprocessorDirective = 0; // Flag to check if inside a preprocessor directive

    // Open files
    inputFile = fopen("temp.c", "r");
    identifiersFile = fopen("identifiers.txt", "w");
    keywordsFile = fopen("keywords.txt", "w");
    integersFile = fopen("integers.txt", "w");
    operatorsFile = fopen("operators.txt", "w");

    if (inputFile == NULL || identifiersFile == NULL || keywordsFile == NULL || integersFile == NULL || operatorsFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Read input file character by character
    while ((c = fgetc(inputFile)) != EOF) {
        // Check for the start of a comment
        if (c == '/') {
            char nextChar = fgetc(inputFile);
            if (nextChar == '/') {
                inComment = 1;
                continue;
            } else {
                ungetc(nextChar, inputFile);
            }
        }

        // Check for the end of a comment
        if (inComment && c == '\n') {
            inComment = 0;
            continue;
        }

        // Ignore characters inside comments and preprocessor directives
        if (inComment || inPreprocessorDirective) {
            if (c == '\n') {
                inPreprocessorDirective = 0;
            }
            continue;
        }

        // Check for the start of a preprocessor directive
        if (c == '#') {
            inPreprocessorDirective = 1;
            continue;
        }

        // Ignore spaces, tabs, and new lines
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        }

        // Check if the character is an operator
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '!' || c==',') {
            fprintf(operatorsFile, "%c\n", c);
            continue;
        }

        // Check if the character is a digit
        if (isdigit(c)) {
            tokenIndex = 0;
            token[tokenIndex++] = c;
            while (isdigit(c = fgetc(inputFile))) {
                token[tokenIndex++] = c;
            }
            token[tokenIndex] = '\0';
            fprintf(integersFile, "%s\n", token);
            ungetc(c, inputFile); // Put back the non-digit character
            continue;
        }

        // Check if the character is a letter (possible identifier or keyword)
        if (isalpha(c) || c == '_') {
            tokenIndex = 0;
            token[tokenIndex++] = c;
            while (isalnum(c = fgetc(inputFile)) || c == '_') {
                token[tokenIndex++] = c;
            }
            token[tokenIndex] = '\0';

            if (isKeyword(token)) {
                fprintf(keywordsFile, "%s\n", token);
            } else {
                fprintf(identifiersFile, "%s\n", token);
            }

            ungetc(c, inputFile); // Put back the non-alnum character
            continue;
        }
    }

    // Close files
    fclose(inputFile);
    fclose(identifiersFile);
    fclose(keywordsFile);
    fclose(integersFile);
    fclose(operatorsFile);

    printf("Lexical analysis completed. Check the output files.\n");

    return 0;
}
