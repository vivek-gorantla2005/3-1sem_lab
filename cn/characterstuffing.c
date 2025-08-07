#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char data[MAX], stuffed[MAX * 2];
    int i, j = 0;

    // DLE = Data Link Escape
    // STX = Start of Text
    // ETX = End of Text
    // These are just represented here as 'D', 'S', and 'E' for simplicity

    printf("Enter the data to be sent: ");
    scanf("%s", data);

    // Add start delimiter
    stuffed[j++] = 'D';  // DLE
    stuffed[j++] = 'S';  // STX

    for (i = 0; i < strlen(data); i++) {
        if (data[i] == 'D') {
            // Stuff an extra DLE if DLE found in data
            stuffed[j++] = 'D';
        }
        stuffed[j++] = data[i];
    }

    // Add end delimiter
    stuffed[j++] = 'D';  // DLE
    stuffed[j++] = 'E';  // ETX

    stuffed[j] = '\0';

    printf("Stuffed data: %s\n", stuffed);

    return 0;
}
