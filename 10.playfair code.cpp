#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
void generatePlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0}, index = 0;
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char adjustedKey[SIZE * SIZE] = "";
    for (int i = 0; key[i] != '\0'; i++) {
        if (toupper(key[i]) == 'J') key[i] = 'I';
        if (isalpha(key[i]) && !used[toupper(key[i]) - 'A']) {
            used[toupper(key[i]) - 'A'] = 1;
            strncat(adjustedKey, &key[i], 1);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 'J') continue;  // Skip 'J'
        if (!used[alphabet[i] - 'A']) {
            strncat(adjustedKey, &alphabet[i], 1);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = adjustedKey[index++];
        }
    }
}
void displayMatrix(char matrix[SIZE][SIZE]) {
    printf("Playfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char key[] = "CIPHER"; 
    char playfairMatrix[SIZE][SIZE];
    generatePlayfairMatrix(key, playfairMatrix);
    displayMatrix(playfairMatrix);

    return 0;
}
