#include <stdio.h>
#include <ctype.h>
#include <string.h>

void atbashCipher(char *text) {
    if (text == NULL) {
        return;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                text[i] = 'z' - (text[i] - 'a');
            } else {
                text[i] = 'Z' - (text[i] - 'A');
            }
        }
    }
}

int main() {
    char message[1000]; 

    printf("Enter the text to be ciphered/deciphered: ");
    fgets(message, sizeof(message), stdin); 

    message[strcspn(message, "\n")] = 0;

    printf("Original message: %s\n", message);

    atbashCipher(message);

    printf("Atbash ciphered message: %s\n", message);

    atbashCipher(message);

    printf("Decrypted message: %s\n", message);

    return 0;
}