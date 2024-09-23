#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0}, index = 0;
    char adjustedKey[100] = "";
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (isalpha(key[i]) && !used[toupper(key[i]) - 'A']) {
            used[toupper(key[i]) - 'A'] = 1;
            strncat(adjustedKey, &key[i], 1);
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch - 'A']) {
            strncat(adjustedKey, &ch, 1);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = adjustedKey[i * SIZE + j];
        }
    }
}

void findPosition(char ch, char keyMatrix[SIZE][SIZE], int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decrypt(char ciphertext[], char keyMatrix[SIZE][SIZE], char decryptedText[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPosition(ciphertext[i], keyMatrix, &r1, &c1);
        findPosition(ciphertext[i + 1], keyMatrix, &r2, &c2);

        if (r1 == r2) {
            decryptedText[i] = keyMatrix[r1][(c1 + SIZE - 1) % SIZE];
            decryptedText[i + 1] = keyMatrix[r2][(c2 + SIZE - 1) % SIZE];
        } else if (c1 == c2) {
            decryptedText[i] = keyMatrix[(r1 + SIZE - 1) % SIZE][c1];
            decryptedText[i + 1] = keyMatrix[(r2 + SIZE - 1) % SIZE][c2];
        } else {
            decryptedText[i] = keyMatrix[r1][c2];
            decryptedText[i + 1] = keyMatrix[r2][c1];
        }
    }
    decryptedText[len] = '\0';
}

int main() {
    char key[] = "PT109";
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGON";
    char keyMatrix[SIZE][SIZE];
    char decryptedText[100];

    generateKeyMatrix(key, keyMatrix);
    decrypt(ciphertext, keyMatrix, decryptedText);

    printf("Decrypted message: %s\n", decryptedText);
    return 0;
}
