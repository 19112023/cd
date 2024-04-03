#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[20], c;
    int state = 0, i = 0;
    
    printf("\nEnter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove the newline character from fgets
    
    while (s[i] != '\0') {
        switch (state) {
            case 0:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 1:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 2:
                c = s[i++];
                if (c == 'a')
                    state = 6;
                else if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 6:
                printf("\n%s is not accepted.\n", s);
                exit(0);
        }
    }

    if (state == 1)
        printf("\n%s is accepted under rule 'a*'.\n", s);
    else if (state == 2)
        printf("\n%s is accepted under rule 'a*b+'.\n", s);

    return 0;
}

