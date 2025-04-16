#include <stdio.h>
#include <ctype.h>
#include <string.h>

void augustCipher(char *text, int key) {
    if (text == NULL) return;
    key %= 26; 
    if (key < 0) key += 26; 

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter the text to be ciphered/deciphered: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter the key (integer): ");
    scanf("%d", &key);
    getchar(); 

    printf("Original message: %s\n", message);

    augustCipher(message, key);
    printf("August ciphered message: %s\n", message);

    augustCipher(message, -key); 
    printf("Decrypted message: %s\n", message);

    return 0;
}