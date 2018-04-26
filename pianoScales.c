#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void printScale(int index, int type[][1], char k[][3]);

int main(int argc, char* argv[]) {
    char keys[12][3] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int numNotes = 12;
    int majorSteps[6][1] = {2, 2, 1, 2, 2, 2};
    int minorSteps[6][1] = {2, 1, 2, 2, 1, 2};
    int numSteps = 6;
    int index = 0;
    // check if more or less than one argument
    if (argc != 2) {
        printf("This program requires exactly one command line argument\n");
        return 0;
    }
    // check if input is in correct array of keys
    int temp = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(argv[1], keys[i]) == 0) {
            temp++;
            index = i;
        }
    }
    if (temp != 1) {
        printf("No such key. %s\n", argv[1]);
        return 0;
    }
    // print major scale
    printf("%s %s %s ", argv[1], "major:", argv[1]);
    printScale(index, majorSteps, keys);
    // print minor scale
    printf("%s %s %s ", argv[1], "minor:", argv[1]);
    printScale(index, minorSteps, keys);
    return 0;
}

void printScale(int index, int type[][1], char k[][3]) {
    for (int i = 0; i < 6; i++) {
        printf("%s ", k[(index + *type[i]) % 12]);
        index = index + *type[i];
    }
    printf("\n");
    return;
}
