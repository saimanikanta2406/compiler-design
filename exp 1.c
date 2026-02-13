#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    printf("Enter the input (Ctrl+Z to stop):\n");

    while ((ch = getchar()) != EOF) {

        /* Ignore spaces, tabs, new lines */
        if (ch == ' ' || ch == '\n' || ch == '\t')
            continue;

        /* Ignore single line comments */
        if (ch == '/') {
            char next = getchar();
            if (next == '/') {
                while (getchar() != '\n'); // skip comment
                continue;
            } else {
                printf("Operator: /\n");
                ungetc(next, stdin);
                continue;
            }
        }

        /* Identifier */
        if (isalpha(ch)) {
            printf("Identifier: %c\n", ch);
        }

        /* Constant */
        else if (isdigit(ch)) {
            printf("Constant: %c\n", ch);
        }

        /* Operator */
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '=' ) {
            printf("Operator: %c\n", ch);
        }
    }

    return 0;
}
