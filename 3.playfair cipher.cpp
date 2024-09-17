#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
void prepareKeyMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0}, row = 0, col = 0;
    used['J' - 'A'] = 1;  // Treat I and J as the same
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[toupper(key[i]) - 'A']) {
            matrix[row][col++] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            if (col == SIZE) { row++; col = 0; }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[row][col++] = ch;
            if (col == SIZE) { row++; col = 0; }
        }
    }
}
void findPosition(char ch, char matrix[SIZE][SIZE], int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char digraph[2], char matrix[SIZE][SIZE]) {
    int row1, col1, row2, col2;
    findPosition(digraph[0], matrix, &row1, &col1);
    findPosition(digraph[1], matrix, &row2, &col2);

    if (row1 == row2) {
        digraph[0] = matrix[row1][(col1 + 1) % SIZE];
        digraph[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        digraph[0] = matrix[(row1 + 1) % SIZE][col1];
        digraph[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        digraph[0] = matrix[row1][col2];
        digraph[1] = matrix[row2][col1];
    }
}
void prepareText(char text[], char preparedText[]) {
    int len = strlen(text), index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            preparedText[index++] = toupper(text[i]);
            if (index > 1 && preparedText[index - 1] == preparedText[index - 2])
                preparedText[index++] = 'X';
        }
    }
    if (index % 2 != 0)
        preparedText[index++] = 'X';
    preparedText[index] = '\0';
}

int main() {
    char key[100], text[100], matrix[SIZE][SIZE], preparedText[100];
    printf("Enter keyword: ");
    scanf("%s", key);
    printf("Enter plaintext: ");
    scanf("%s", text);
    prepareKeyMatrix(key, matrix);
    prepareText(text, preparedText);
    for (int i = 0; i < strlen(preparedText); i += 2) {
        char digraph[2] = {preparedText[i], preparedText[i + 1]};
        encryptDigraph(digraph, matrix);
        printf("%c%c", digraph[0], digraph[1]);
    }

    return 0;
}
