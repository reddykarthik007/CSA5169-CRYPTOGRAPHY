#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
void encrypt(char plaintext[], int key[], char ciphertext[], int length) {
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            int shift = key[i % length];
            ciphertext[i] = ((tolower(plaintext[i]) - 'a') + shift) % 26 + 'a';
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[length] = '\0';
}
void decrypt(char ciphertext[], int key[], char decryptedtext[], int length) {
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            int shift = key[i % length];
            decryptedtext[i] = ((tolower(ciphertext[i]) - 'a') - shift + 26) % 26 + 'a';
        } else {
            decryptedtext[i] = ciphertext[i];
        }
    }
    decryptedtext[length] = '\0';
}

int main() {
    char plaintext[MAX] = "send more money";
    char ciphertext[MAX];
    char decryptedtext[MAX];
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int keyLength = sizeof(key) / sizeof(key[0]);
    int length = strlen(plaintext);
    encrypt(plaintext, key, ciphertext, length);
    printf("Encrypted Text: %s\n", ciphertext);
    char desiredPlaintext[MAX] = "cash not needed";
    int newKey[MAX];
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i]) && isalpha(desiredPlaintext[i])) {
            newKey[i] = (tolower(ciphertext[i]) - tolower(desiredPlaintext[i]) + 26) % 26;
        } else {
            newKey[i] = 0;
        }
    }

    printf("New Key for decrypting to 'cash not needed': ");
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            printf("%d ", newKey[i]);
        }
    }
    printf("\n");
    decrypt(ciphertext, newKey, decryptedtext, length);
    printf("Decrypted Text with new key: %s\n", decryptedtext);

    return 0;
}
