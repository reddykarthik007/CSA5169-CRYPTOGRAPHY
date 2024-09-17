#include <stdio.h>
#include <ctype.h>
#include <string.h>

void polyalphabeticCipher(char text[], const char key[]) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char shift = toupper(key[j % keyLen]) - 'A';
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            }
            j++;
        }
    }
}

int main() {
    char text[100], key[100];
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    polyalphabeticCipher(text, key);
    printf("Encrypted message: %s\n", text);
    return 0;
}
