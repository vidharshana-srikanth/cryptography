#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptRailFence(char *text, int key, char *result) {
    int len = strlen(text);

    char **rail = malloc(key * sizeof(char *));
    for (int i = 0; i < key; i++)
        rail[i] = malloc(len * sizeof(char));

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, dirDown = 0;

    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];
        if (row == 0 || row == key - 1)
            dirDown = !dirDown;
        row += dirDown ? 1 : -1;
    }

    int idx = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                result[idx++] = rail[i][j];
    result[idx] = '\0';

    for (int i = 0; i < key; i++)
        free(rail[i]);
    free(rail);
}

void decryptRailFence(char *cipher, int key, char *result) {
    int len = strlen(cipher);

    char **rail = malloc(key * sizeof(char *));
    for (int i = 0; i < key; i++)
        rail[i] = malloc(len * sizeof(char));

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, dirDown = 0;

    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';
        if (row == 0 || row == key - 1)
            dirDown = !dirDown;
        row += dirDown ? 1 : -1;
    }

    int idx = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*')
                rail[i][j] = cipher[idx++];

    row = 0;
    dirDown = 0;
    for (int i = 0; i < len; i++) {
        result[i] = rail[row][i];
        if (row == 0 || row == key - 1)
            dirDown = !dirDown;
        row += dirDown ? 1 : -1;
    }
    result[len] = '\0';

    for (int i = 0; i < key; i++)
        free(rail[i]);
    free(rail);
}

int main() {
    char text[100], encrypted[100], decrypted[100];
    int key;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of rails (key): ");
    scanf("%d", &key);

    encryptRailFence(text, key, encrypted);
    printf("Encrypted: %s\n", encrypted);

    decryptRailFence(encrypted, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
