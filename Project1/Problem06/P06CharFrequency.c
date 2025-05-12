#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 255 //Maximum number of characters to store in map

//Below two arrays represent a map - 1st array stores the keys and the 2nd array stores the values:
char keys[MAX_CHARS]; //Array for the keys - max 255 keys (ASCII codes including extended character set)
int values[MAX_CHARS] = {0}; //Array for values
int size = 0; //Current number of elements in the map

int getIndex(char key) {
    for (int i = 0; i < size; i++) {
        if (keys[i] == key) {
            return i;
        }
    }

    return -1; //Key not found
}

void insertKeyAndValue(char key, int value) {
    int index = getIndex(key);

    if (index == -1) {          //key does not exists
        keys[size] = key;
        values[size] = value;
        size++;
    } else {                    //key exists already
        values[index] = value;
    }
}

int getValue(char key) {
    int index = getIndex(key);

    if (index == -1) {          //key does not exist
        return -1;
    } else {                    //key exists
        return values[index];
    }
    
}

//Bubble sort both arrays - keys and values
void sortMapByValues() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                int tempInt = values[j];
                char tempChar = keys[j];
                values[j] = values[j + 1];
                keys[j] = keys[j + 1];
                values[j + 1] = tempInt;
                keys[j + 1] = tempChar;
            }
        }
    }  
}

//Print Map as every key is printed as many times as its value 
void printMap() {
    for (int i = size - 1; i >= 0; i--) {
        int printTimes = getValue(keys[i]);

        for (int j = 0; j < printTimes; j++) {
            printf("%c", keys[i]);
        }
        
    }
    
    printf("\n");
}

int main() {
    char input[MAX_CHARS];
    printf("\nEnter a string up to %d characters\n", MAX_CHARS);
    gets(input);

    //inserting the map
    for (int i = 0; i < strlen(input); i++) {
        int indexOfMap = getIndex(input[i]);
        int newValue = 1;

        if (indexOfMap != -1) {
            newValue = getValue(input[i]) + 1;
        }

        insertKeyAndValue(input[i], newValue);
    }

    sortMapByValues();
    printMap();
    
    return 0;
}