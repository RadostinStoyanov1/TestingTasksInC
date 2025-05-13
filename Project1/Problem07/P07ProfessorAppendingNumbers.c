#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Calculates the needed size of the string 
int calculateNumberOfDigits(int number) {
    int output = 0;

    for (int i = 0; i < number; i++) {
        output = (output * 2) + 1;
    }
    
    return output;
}

void appendStep(char *inputArr, int step) {
    int numbersFromPreviousStep = calculateNumberOfDigits(step - 1);
    int numbersForCurrentStep = (numbersFromPreviousStep * 2) + 1;

    inputArr[numbersFromPreviousStep] = (char) (step + '0'); //append digit of next step

    memmove(inputArr + numbersFromPreviousStep + 1, inputArr, numbersFromPreviousStep); //add the string from the previous step after the digit from the surrent step
}

int main() {
    int number, neededDigits;

    printf("\nEnter a nuber between 1 and 19\n");
    scanf("%d", &number);

    if (number < 1 || number > 19) {
        printf("Number must be between 1 and 19.\n");
        return 1;
    }

    neededDigits = calculateNumberOfDigits(number);

    char *outputArr = malloc(sizeof(char) * (neededDigits + 1)); //creating array for output including the string terminating character
    if (outputArr == NULL) {
        printf("Failed to allocate memory");
        return 1;
    }

    printf("%d\n", neededDigits);

    outputArr[0] = '1';
    outputArr[1] = '\0';

    for (int i = 2; i <= number; i++) {
        appendStep(outputArr, i);
    }

    outputArr[neededDigits] = '\0';
    printf("%s\n", outputArr);
    free(outputArr);

    return 0;
}