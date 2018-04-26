#include <stdio.h>
#include <math.h>
#define NUMKEYS 88
#define INITIALFREQ 27.5

int main(void) {
    
    char keys[12][3] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int steps = 12;
    

    for (int i = 0; i < NUMKEYS; i++) {
        
        
        float frequency = INITIALFREQ * powf(2.0, ((float)i / (float)steps));
        printf("%s\t%.04f\n", keys[i % steps], frequency);
        
        
    }
    return 0;
}
