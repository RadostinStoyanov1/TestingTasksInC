#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Calculates the needed size of the string 
int calculateNumberOfSymbols(int number) {
    int output = 0;

    for (int i = 0; i < number; i++) {
        output = (output * 2) + 1;
    }
    
    return output;
}

int appendStep(char *inputArr, int step, int maxStep) {
    int numbersFromPreviousStep = calculateNumberOfSymbols(step - 1);
    int numbersForCurrentStep = (numbersFromPreviousStep * 2) + 1;

    inputArr[numbersFromPreviousStep] = (char) (step + '0'); //append digit of next step

    memmove(inputArr + numbersFromPreviousStep + 1, inputArr, numbersFromPreviousStep); //add the string from the previous step after the digit from the current step

    if (step + 1 > maxStep) {
        return 0;
    }

    appendStep(inputArr, step + 1, maxStep);
}

int main() {
    int number, neededDigits;

    printf("\nEnter a nuber between 1 and 19\n");
    scanf("%d", &number);

    if (number < 1 || number > 19) {
        printf("Number must be between 1 and 19.\n");
        return 1;
    }

    neededDigits = calculateNumberOfSymbols(number);

    char *outputArr = malloc(sizeof(char) * (neededDigits + 1)); //creating array for output including the string terminating character
    if (outputArr == NULL) {
        printf("Failed to allocate memory");
        return 1;
    }

    outputArr[0] = '1';
    outputArr[1] = '\0';

    appendStep(outputArr, 2, number);

    outputArr[neededDigits] = '\0';
    printf("%s\n", outputArr);
    free(outputArr);

    return 0;
}