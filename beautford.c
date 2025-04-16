#include <stdio.h>
#include <string.h>
#include <ctype.h>

void beaufortEncrypt(char *text, char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int plainChar = toupper(text[i]) - 'A';
            int keyChar = toupper(key[j % keyLen]) - 'A';
            int cipherChar = (keyChar - plainChar + 26) % 26;
            text[i] = cipherChar + base;
            j++;
        }
    }
}

void beaufortDecrypt(char *text, char *key) {
    beaufortEncrypt(text, key);
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

    beaufortEncrypt(message, key);
    printf("Encrypted: %s\n", message);

    beaufortDecrypt(message, key);
    printf("Decrypted: %s\n", message);

    return 0;
}
