#include <stdio.h>
#include <string.h>

void printSingleDigitAsOnes(int digit) {
    char *digits[] = {"нула", "едно", "две", "три", "четири", "пет", "шест", "седем", "осем", "девет"};
    printf("%s\n", digits[digit]);
}

void printSingleDigitAsRoundTens(int digit) {
    char *digits[] = {"десет", "двадесет", "тридесет", "четиридесет", "петдесет", "шестдесет", "седемдесет", "осемдесет", "деветдесет"};
    printf("%s", digits[digit - 1]);
}

void printElevens(int digit) {
    char *digits[] = {"единадесет", "дванадесет", "тринадесет", "четиринадесет", "петнадесет", "шестнадесет", "седемнадесет", "осемнадесет", "деветнадесет"};
    printf("%s", digits[digit - 1]);
}

void printTwoDigitsAsTensAndOnes(int tens, int ones) {
    printSingleDigitAsRoundTens(tens);
    printf(" и ");
    printSingleDigitAsOnes(ones);
}

void printHundredsOnly(int digit) {
    char *digits[] = {"сто", "двеста", "триста", "четиристотин", "петстотин", "шестстотин", "седемстотин", "осемстотин", "деветстотин"};
    printf("%s", digits[digit - 1]);
}

void printOutputString(char *charsArr, int length) {

    switch (length) {
        case 1:
            int digit = charsArr[0] - '0';
            printSingleDigitAsOnes(digit);
            break;

        case 2:
            if (charsArr[0] == '0'){
                printSingleDigitAsRoundTens(charsArr[1] - '0');
            } else {
                if (charsArr[1] == '1') {
                    printElevens(charsArr[0] - '0');
                } else {
                    printTwoDigitsAsTensAndOnes(charsArr[1] - '0', charsArr[0] - '0');
                }
            }
            break;

        case 3:
            int hundreds = charsArr[2] - '0';
            int tens = charsArr[1] - '0';
            int ones = charsArr[0] - '0';

            printHundredsOnly(hundreds);
            
            if (ones == 0 && tens != 0) {
                printf(" и ");
                printSingleDigitAsRoundTens(charsArr[1] - '0');
            } else if (ones != 0 && tens == 0) {
                printf(" и ");
                printSingleDigitAsOnes(ones);
            } else if (ones != 0 && tens == 1) {
                printf(" и ");
                printElevens(ones);
            } else {
                if (ones != 0 && tens != 0) {
                    printf(", ");
                    printTwoDigitsAsTensAndOnes(tens, ones);
                }
            }
            break;

        case 4:
            printf("хиляда");
            break;
    }    
    
}

int main() {

    int inputNumber;

    printf("\nEnter a number between 0 and 1000 including:\n");
    scanf("%d", &inputNumber);

    if (inputNumber < 0 || inputNumber > 1000) {
        printf("Number must be between 1 and 1000 including.\n");
        return 1;
    }

    char charsArr[4] = {0};
    int counter = 0;

    while (inputNumber > 0) {
        int currentDigit = inputNumber % 10;
        charsArr[counter] = currentDigit + '0';
        counter++;
        inputNumber /= 10;
    }

    printf("\n Array of chars is: ");

    for (int i = 0; i < 4; i++) {
        printf("%c ", charsArr[i]);
    }

    printf("\n");
    
    printf("The length of the string with digits is: %d\n", strlen(charsArr));

    printOutputString(charsArr, counter);

    return 0;
}