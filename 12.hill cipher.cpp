#include <stdio.h>
#include <string.h>

#define SIZE 100
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
    return -1;
}
void matrixMultiplication(int key[2][2], int vector[2], int result[2]) {
    result[0] = (key[0][0] * vector[0] + key[0][1] * vector[1]) % 26;
    result[1] = (key[1][0] * vector[0] + key[1][1] * vector[1]) % 26;
    if (result[0] < 0) result[0] += 26;
    if (result[1] < 0) result[1] += 26;
}
void hillEncrypt(char message[], int key[2][2]) {
    int length = strlen(message);
    int vector[2], result[2];
    printf("Encrypted Text: ");
    for (int i = 0; i < length; i += 2) {
        vector[0] = message[i] - 'a';
        vector[1] = message[i + 1] - 'a';
        matrixMultiplication(key, vector, result);
        printf("%c%c", result[0] + 'a', result[1] + 'a');
    }
    printf("\n");
}
void hillDecrypt(char ciphertext[], int key[2][2]) {
    int determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    int invDet = mod26Inverse(determinant % 26);
    int inverseKey[2][2] = {
        { invDet * key[1][1] % 26, -invDet * key[0][1] % 26 },
        { -invDet * key[1][0] % 26, invDet * key[0][0] % 26 }
    };
    int length = strlen(ciphertext);
    int vector[2], result[2];
    printf("Decrypted Text: ");
    for (int i = 0; i < length; i += 2) {
        vector[0] = ciphertext[i] - 'a';
        vector[1] = ciphertext[i + 1] - 'a';
        matrixMultiplication(inverseKey, vector, result);
        printf("%c%c", result[0] + 'a', result[1] + 'a');
    }
    printf("\n");
}
int main() {
    char message[SIZE] = "meetmeattheusualplaceattenratherthaneightoclock";
    int key[2][2] = { {9, 4}, {5, 7} }; 
    int length = strlen(message);
    if (length % 2 != 0) {
        message[length] = 'x';
        message[length + 1] = '\0';
    }

    printf("Original Message: %s\n", message);
    hillEncrypt(message, key);
    char ciphertext[SIZE] = "yoaabx...";
    hillDecrypt(ciphertext, key);

    return 0;
}
