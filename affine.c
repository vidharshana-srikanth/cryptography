#include <stdio.h>
#include <ctype.h>
#include <string.h>

int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, &x, &y);
    if (gcd != 1) return -1; 
    return (x % m + m) % m; 
}

void affineCipher(char *text, int a, int b, int encrypt) {
    if (text == NULL) return;
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            if (encrypt) {
                text[i] = (a * (text[i] - base) + b) % 26 + base;
            } else {
                int aInverse = modInverse(a, 26);
                if (aInverse == -1) {
                    printf("Error: 'a' and 26 are not coprime.\n");
                    return;
                }
                text[i] = (aInverse * (text[i] - base - b + 26)) % 26 + base;
            }
        }
    }
}

int main() {
    char message[1000];
    int a, b;

    printf("Enter the text to be ciphered/deciphered: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter the key 'a' (coprime with 26): ");
    scanf("%d", &a);

    printf("Enter the key 'b': ");
    scanf("%d", &b);
    getchar();

    affineCipher(message, a, b, 1);
    printf("Affine ciphered message: %s\n", message);

    affineCipher(message, a, b, 0);
    printf("Decrypted message: %s\n", message);

    return 0;
}