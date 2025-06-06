#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 256

int findCountOf_a_Char(char *input);

void replaceAllChars_a(char input[]);

void setRangeOfCharsInString(char *baseString, int strartingIndex, char *addedString);

int main() {

    char input[LENGTH];
    printf("\nEnter a string up to %d characters\n", LENGTH);
    //fgets(input, sizeof(input), stdin); //fgets includes the '\n' symbol at the end of the read string
    gets(input);

    replaceAllChars_a(input);
    printf("%s\n", input);
    return 0;
}

void replaceAllChars_a(char input[]) {
    int i, aCount, inputArrayLength, outputArrayLength, outputArrayIndexer = 0;
    inputArrayLength = strlen(input);
    aCount = findCountOf_a_Char(input);
    outputArrayLength = inputArrayLength + (aCount * 3);

    char *output = malloc((outputArrayLength + 1) * sizeof(char));

    for (i = 0; i < inputArrayLength; i++) {
        if (input[i] != 'a') {
            output[outputArrayIndexer] = input[i];
            outputArrayIndexer++;
        } else {
            setRangeOfCharsInString(output, outputArrayIndexer, "baba");
            outputArrayIndexer += 4;
        }        
    }

    output[outputArrayLength] = '\0';

    strcpy(input, output);
    free(output);
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

void setRangeOfCharsInString(char *baseString, int strartingIndex, char *addedString) {
    int lengthOfAddedString = strlen(addedString);

    for (int i = 0; i < lengthOfAddedString; i++) {
        baseString[strartingIndex + i] = addedString[i];
    }
}
