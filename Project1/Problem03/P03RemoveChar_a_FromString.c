#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 256

int findCountOf_a_Char(char *input);

void removeAllChars_a(char input[]);

int main() {

    char input[LENGTH];
    printf("\nEnter a string up to %d characters\n", LENGTH);
    fgets(input, sizeof(input), stdin);

    removeAllChars_a(input);
    printf("%s\n", input);
    return 0;
}

int findCountOf_a_Char(char *input) {
    int i, count = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            count++;
        }
    }

    return count;
}

void removeAllChars_a(char input[]) {
    int i, aCount, inputArrayLength, outputArrayLength, outputArrayIndexer = 0;
    inputArrayLength = strlen(input);
    aCount = findCountOf_a_Char(input);
    outputArrayLength = inputArrayLength - aCount;

    char *output = malloc((outputArrayLength + 1) * sizeof(char));

    for (i = 0; i < inputArrayLength; i++) {
        if (input[i] != 'a') {
            output[outputArrayIndexer] = input[i];
            outputArrayIndexer++;
        }        
    }

    output[outputArrayLength] = '\0';

    strcpy(input, output);
}