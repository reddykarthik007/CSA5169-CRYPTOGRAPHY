#include <stdio.h>
#include <ctype.h>
#include <string.h>

void monoalphabeticCipher(char text[], char key[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = toupper(text[i]) - 'A';
            text[i] = isupper(text[i]) ? key[index] : tolower(key[index]);
        }
    }
}

int main() {
    char text[100], key[27];
    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline
    printf("Enter 26-letter key: ");
    scanf("%26s", key);

    monoalphabeticCipher(text, key);
    printf("Encrypted message: %s\n", text);
    return 0;
}
