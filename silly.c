#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* silly(char* s, char* k);

int main(int argc, char* argv[]) {
    
    printf("%s\n", silly("bro", "hello"));
    
    return 0;
}

char* silly(char* s, char* k) {
    int firstLen = (strlen(s) + 1) * (strlen(s) / 2);
    int secondLen = (strlen(k) + 1) * (strlen(k) / 2);
    
    char* output = malloc(firstLen + secondLen);
    
    for (int i = 0; i <= strlen(s); i++) {
        for (int t = 0; t < i; t++) {
            *(output + i) = s[t];
            printf("%c", s[t]);
        }
    }
    
    
    for (int i = strlen(k); i >= 0; i--) {
        for (int t = 0; t < i; t++) {
            *(output + strlen(s) + i) = k[t];
            printf("%c", k[t]);
        }
    }
    
    
    
    return output;
}
