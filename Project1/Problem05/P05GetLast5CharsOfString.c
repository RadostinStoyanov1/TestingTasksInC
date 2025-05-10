#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 256

char *getLast5CharsFromString(char input[]);

int main() {
    char input[LENGTH];
    printf("\nEnter a string up to %d characters\n", LENGTH);
    gets(input);
    
    char *outputString = getLast5CharsFromString(input);
    printf("%s\n", outputString);
    free(outputString);

    return 0;
}

char *getLast5CharsFromString(char input[]) {
    int outputLength, i, inputLength = strlen(input);

    if (strlen(input) < 5) {
        outputLength = inputLength;
    } else {
        outputLength = 5;
    }

    char *output = malloc((outputLength + 1) * sizeof(char));

    for (i = 0; i < outputLength; i++) {
        output[i] = input[inputLength - 1 - i];
    }
    
    return output;
}
