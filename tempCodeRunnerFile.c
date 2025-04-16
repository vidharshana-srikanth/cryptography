#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base - key + 26) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; 

    printf("Enter key (shift): ");
    scanf("%d", &key);

    encrypt(text, key);
    printf("Encrypted: %s\n", text);

    decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
