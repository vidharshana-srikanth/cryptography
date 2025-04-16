#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void encryptRouteCipher(char *text, int cols, char *encrypted) {
    int len = strlen(text);
    int rows = (int)ceil((double)len / cols);

    char **matrix = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(char));

    int idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (idx < len) ? text[idx++] : 'X';

    idx = 0;
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            encrypted[idx++] = matrix[i][j];

    encrypted[idx] = '\0';

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void decryptRouteCipher(char *cipher, int cols, char *decrypted) {
    int len = strlen(cipher);
    int rows = (int)ceil((double)len / cols);

    char **matrix = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(char));

    int idx = 0;
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            matrix[i][j] = cipher[idx++];

    idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            decrypted[idx++] = matrix[i][j];

    decrypted[idx] = '\0';

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    char text[100], encrypted[100], decrypted[100];
    int cols;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    encryptRouteCipher(text, cols, encrypted);
    printf("Encrypted: %s\n", encrypted);

    decryptRouteCipher(encrypted, cols, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
