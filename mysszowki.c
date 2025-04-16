#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void assignRanks(char *key, int *ranks) {
    int len = strlen(key);
    char *sortedKey = (char *)malloc((len + 1) * sizeof(char));
    strcpy(sortedKey, key);

    for (int i = 0; i < len; i++)
        sortedKey[i] = tolower(sortedKey[i]);

    qsort(sortedKey, len, sizeof(char), compare);

    int rank = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (tolower(key[j]) == sortedKey[i] && ranks[j] == 0) {
                ranks[j] = rank;
                break;
            }
        }
        if (i + 1 < len && sortedKey[i] != sortedKey[i + 1])
            rank++;
    }

    free(sortedKey);
}

void encryptMyszkowski(char *text, char *key, char *result) {
    int tlen = strlen(text);
    int klen = strlen(key);
    int rows = (tlen + klen - 1) / klen;

    char **matrix = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (char *)malloc(klen * sizeof(char));

    for (int i = 0; i < rows * klen; i++)
        matrix[i / klen][i % klen] = (i < tlen) ? text[i] : 'X';

    int *ranks = (int *)calloc(klen, sizeof(int));
    assignRanks(key, ranks);

    int maxRank = 0;
    for (int i = 0; i < klen; i++)
        if (ranks[i] > maxRank)
            maxRank = ranks[i];

    int idx = 0;
    for (int r = 1; r <= maxRank; r++) {
        for (int col = 0; col < klen; col++) {
            if (ranks[col] == r) {
                for (int row = 0; row < rows; row++) {
                    result[idx++] = matrix[row][col];
                }
            }
        }
    }

    result[idx] = '\0';

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(ranks);
}

int main() {
    char text[200], key[50], encrypted[300];

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key (letters only, repeated allowed): ");
    scanf("%s", key);

    encryptMyszkowski(text, key, encrypted);
    printf("Encrypted: %s\n", encrypted);

    return 0;
}
