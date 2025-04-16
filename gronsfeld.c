#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int *key, int keyLength) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = key[i % keyLength];
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int *key, int keyLength) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = key[i % keyLength];
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

int main() {
    char message[100];
    char keyStr[20];
    int key[20];
    int keyLength, i;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter numeric key (digits only): ");
    fgets(keyStr, sizeof(keyStr), stdin);
    keyStr[strcspn(keyStr, "\n")] = '\0';

    keyLength = strlen(keyStr);
    for (i = 0; i < keyLength; i++) {
        key[i] = keyStr[i] - '0';
    }

    encrypt(message, key, keyLength);
    printf("Encrypted: %s\n", message);

    decrypt(message, key, keyLength);
    printf("Decrypted: %s\n", message);

    return 0;
}
