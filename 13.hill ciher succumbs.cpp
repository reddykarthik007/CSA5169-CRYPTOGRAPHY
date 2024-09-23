#include <stdio.h>
#include <stdlib.h>

#define MOD 26
int determinant(int matrix[2][2]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % MOD;
}
int modInverse(int a) {
    for (int x = 1; x < MOD; x++) {
        if ((a * x) % MOD == 1)
            return x;
    }
    return -1;
}
void invertMatrix(int matrix[2][2], int inverse[2][2]) {
    int det = determinant(matrix);
    int invDet = modInverse((det + MOD) % MOD);

    if (invDet == -1) {
        printf("Inverse does not exist for the given matrix.\n");
        exit(1);
    }
    inverse[0][0] = ( matrix[1][1] * invDet) % MOD;
    inverse[0][1] = (-matrix[0][1] * invDet) % MOD;
    inverse[1][0] = (-matrix[1][0] * invDet) % MOD;
    inverse[1][1] = ( matrix[0][0] * invDet) % MOD;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (inverse[i][j] < 0)
                inverse[i][j] += MOD;
        }
    }
}
void multiplyMatrices(int a[2][2], int b[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= MOD;
        }
    }
}
void multiplyMatrixVector(int matrix[2][2], int vector[2], int result[2]) {
    for (int i = 0; i < 2; i++) {
        result[i] = 0;
        for (int j = 0; j < 2; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] %= MOD;
        if (result[i] < 0) result[i] += MOD;
    }
}
void deriveKey(int plaintext[2][2], int ciphertext[2][2], int key[2][2]) {
    int inversePlaintext[2][2];
    invertMatrix(plaintext, inversePlaintext);
    multiplyMatrices(ciphertext, inversePlaintext, key);
}
void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int plaintext[2][2] = {
        {7, 11},
        {4, 15}
    };

    int ciphertext[2][2] = {
        {23, 22}, 
        {14, 14}
    };

    int key[2][2]; 
    deriveKey(plaintext, ciphertext, key);
    printf("Derived Key Matrix:\n");
    printMatrix(key);
    return 0;
}
