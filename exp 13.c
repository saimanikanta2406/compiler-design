#include <stdio.h>
#include <ctype.h>

int main() {
    int characters = 0, words = 0, lines = 0;
    char ch;
    int inWord = 0;

    printf("Enter text (Ctrl+D on Linux / Ctrl+Z then Enter on Windows):\n");

    while ((ch = getchar()) != EOF) {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    printf("\nNumber of Characters: %d", characters);
    printf("\nNumber of Words     : %d", words);
    printf("\nNumber of Lines     : %d\n", lines);

    return 0;
}
