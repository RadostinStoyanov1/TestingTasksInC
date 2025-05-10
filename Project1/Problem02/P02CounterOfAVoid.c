#include <stdio.h>
#include <string.h>

#define LENGTH 256

void findCountOf_a_Char(char *input, int *counter) {
    int i;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            *counter = *counter + 1;
        }
    }

}

int main() {

    char input[LENGTH];
    printf("\nEnter a string up to %d characters\n", LENGTH);
    fgets(input, sizeof(input), stdin);

    int aCount = 0;

    findCountOf_a_Char(input, &aCount);
    printf("Character 'a' was met %d times\n", aCount);

    return 0;
}