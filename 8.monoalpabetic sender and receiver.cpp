#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
void generateCipherAlphabet(char key[], char cipherAlphabet[]) {
    int used[ALPHABET_SIZE] = {0}, idx = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (isalpha(key[i])) {
            char letter = toupper(key[i]);
            if (!used[letter - 'A']) {
                cipherAlphabet[idx++] = letter;
                used[letter - 'A'] = 1;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            cipherAlphabet[idx++] = c;
        }
    }
}
void encrypt(char plaintext[], char cipherAlphabet[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char letter = toupper(plaintext[i]);
            plaintext[i] = isupper(plaintext[i]) ? cipherAlphabet[letter - 'A'] : tolower(cipherAlphabet[letter - 'A']);
        }
    }
}

int main() {
    char key[] = "CIPHER";
    char plaintext[100], cipherAlphabet[ALPHABET_SIZE + 1] = {0};

    printf("Enter the message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    generateCipherAlphabet(key, cipherAlphabet);

    encrypt(plaintext, cipherAlphabet);
    printf("Encrypted message: %s", plaintext);

    return 0;
}
