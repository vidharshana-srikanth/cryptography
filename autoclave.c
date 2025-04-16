#include <stdio.h>
#include <string.h>
#include <ctype.h>

void autokeyEncrypt(char *plaintext, char *keyword, char *ciphertext) {
    int ptLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    char fullKey[200];
    int i;

    strcpy(fullKey, keyword);
    strncat(fullKey, plaintext, ptLen - keyLen);

    for (i = 0; i < ptLen; i++) {
        if (isalpha(plaintext[i])) {
            int p = toupper(plaintext[i]) - 'A';
            int k = toupper(fullKey[i]) - 'A';
            ciphertext[i] = (p + k) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[ptLen] = '\0';
}

void autokeyDecrypt(char *ciphertext, char *keyword, char *plaintext) {
    int ctLen = strlen(ciphertext);
    int keyLen = strlen(keyword);
    char currentKey[200];
    int i;

    strcpy(currentKey, keyword);

    for (i = 0; i < ctLen; i++) {
        int k = toupper(currentKey[i]) - 'A';
        int c = toupper(ciphertext[i]) - 'A';
        int p = (c - k + 26) % 26;
        plaintext[i] = p + 'A';
        currentKey[i + keyLen] = plaintext[i];
    }
    plaintext[ctLen] = '\0';
}

int main() {
    char plaintext[100], keyword[100], ciphertext[100], decrypted[100];

    printf("Enter plaintext (letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter keyword (letters only): ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    autokeyEncrypt(plaintext, keyword, ciphertext);
    printf("Encrypted: %s\n", ciphertext);

    autokeyDecrypt(ciphertext, keyword, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
