#include <stdio.h>
#include <string.h>
int main() {
    char input[1000];
    printf("Enter a line:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(input[0] == '/' && input[1] == '/') {
        printf("It is a SINGLE-LINE comment.\n");
    }
    else if(input[0] == '/' && input[1] == '*' &&
            strstr(input, "*/") != NULL) {
        printf("It is a MULTI-LINE comment.\n");
    }
    else {
        printf("It is NOT a comment.\n");
    }
    return 0;
}
