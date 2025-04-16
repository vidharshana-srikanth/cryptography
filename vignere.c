#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

void decrypt(char *text, char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            text[i] = (text[i] - base - shift + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter key (letters only): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key);
    printf("Encrypted: %s\n", message);

    decrypt(message, key);
    printf("Decrypted: %s\n", message);

    return 0;
}
