#include <stdio.h>
#include <string.h>

#define LENGTH 256

int findCountOf_a_Char(char *input) {
    int i, count = 0;

    for (i = 0; i < LENGTH; i++) {
        if (input[i] == 'a') {
            count++;
        }
    }
    
    return count;
}

int main() {

    char input[LENGTH];
    printf("\nEnter a string up to %d characters\n", LENGTH);
    fgets(input, sizeof(input), stdin);

    int aCount = findCountOf_a_Char(input);
    printf("Character 'a' was met %d times\n", aCount);

    return 0;
}