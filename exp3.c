//Name- Sadhana Sharma
//Enrollment no.- 21UCS037
#include <stdio.h>

void extractComments(FILE *input, FILE *output) {
    int ch, prevCh = EOF;

    while ((ch = fgetc(input)) != EOF) {
        if (ch == '/' && prevCh == '/') {
            // Single-line comment
            while ((ch = fgetc(input)) != EOF && ch != '\n')
                fputc(ch, output);
            fputc('\n', output);
        } else if (ch == '*' && prevCh == '/') {
            // Multi-line comment
            while ((ch = fgetc(input)) != EOF) {
                if (ch == '*' && (ch = fgetc(input)) == '/')
                    break;
                fputc(ch, output);
            }
            fputc('\n', output);
        }
        prevCh = ch;
    }
}

int main() {
    FILE *input = fopen("exp3_input.c", "r");
    FILE *output = fopen("exp3_output.txt", "w");

    if (!input || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    extractComments(input, output);

    fclose(input);
    fclose(output);

    printf("Comments extracted successfully. Result written to comments_output.txt\n");

    return 0;
}
