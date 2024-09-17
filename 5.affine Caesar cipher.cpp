#include <stdio.h>
#include <ctype.h>

#define MOD 26

// Function to encrypt using affine cipher
char affineEncrypt(char p, int a, int b) {
    if (!((a % 2 != 0 && a % 13 != 0) && (b >= 0 && b < MOD))) {
        printf("Invalid 'a' value or 'b' out of range.\n");
        return '\0';
    }
    int p_num = toupper(p) - 'A';
    int C_num = (a * p_num + b) % MOD;
    return C_num + 'A';
}

int main() {
    char text[100];
    int a, b;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter value for a (must be coprime with 26): ");
    scanf("%d", &a);
    
    printf("Enter value for b: ");
    scanf("%d", &b);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char encrypted = affineEncrypt(text[i], a, b);
            if (encrypted != '\0') {
                printf("%c", encrypted);
            }
        }
    }
    printf("\n");

    return 0;
}
