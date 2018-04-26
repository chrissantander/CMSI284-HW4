#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* rotate(char* s, int k);

int main(int argc, char* argv[]) {
    printf("%s\n", rotate("doghouse", 5));
    return 0;
}

char* rotate(char* s, int k) {
    if (k < 0) {
        return "Input must be a positive number\n";
    }
    int length = strlen(s);
    int start = k % length;
    char *output = malloc(length);
    for (int i = 0; i < length; i++) {
        *(output + i) = s[start % length];
        start++;
    }
    return output;
}
