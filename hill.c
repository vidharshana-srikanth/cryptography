#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int determinant(int a, int b, int c, int d) {
    return mod26(a * d - b * c);
}

int inverseMod(int a) {
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

void encrypt(char *msg, int key[2][2]) {
    int len = strlen(msg);
    if (len % 2 != 0) strcat(msg, "X"); // pad if odd length

    printf("Encrypted: ");
    for (int i = 0; i < len; i += 2) {
        int x = toupper(msg[i]) - 'A';
        int y = toupper(msg[i+1]) - 'A';
        int e1 = mod26(key[0][0] * x + key[0][1] * y);
        int e2 = mod26(key[1][0] * x + key[1][1] * y);
        printf("%c%c", e1 + 'A', e2 + 'A');
    }
    printf("\n");
}

void decrypt(char *cipher, int key[2][2]) {
    int det = determinant(key[0][0], key[0][1], key[1][0], key[1][1]);
    int detInv = inverseMod(det);
    if (detInv == -1) {
        printf("Key matrix is not invertible in mod 26.\n");
        return;
    }

    // Inverse of 2x2 matrix mod 26
    int invKey[2][2];
    invKey[0][0] = mod26( key[1][1] * detInv);
    invKey[0][1] = mod26(-key[0][1] * detInv);
    invKey[1][0] = mod26(-key[1][0] * detInv);
    invKey[1][1] = mod26( key[0][0] * detInv);

    printf("Decrypted: ");
    for (int i = 0; i < strlen(cipher); i += 2) {
        int x = toupper(cipher[i]) - 'A';
        int y = toupper(cipher[i+1]) - 'A';
        int d1 = mod26(invKey[0][0] * x + invKey[0][1] * y);
        int d2 = mod26(invKey[1][0] * x + invKey[1][1] * y);
        printf("%c%c", d1 + 'A', d2 + 'A');
    }
    printf("\n");
}

int main() {
    char message[100];
    int key[2][2];

    printf("Enter 2x2 key matrix (4 numbers): ");
    scanf("%d %d %d %d", &key[0][0], &key[0][1], &key[1][0], &key[1][1]);

    getchar(); // consume newline
    printf("Enter message (letters only): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    for (int i = 0; i < strlen(message); i++) {
        if (!isalpha(message[i])) {
            printf("Only letters are allowed.\n");
            return 1;
        }
    }

    encrypt(message, key);

    char cipher[100];
    printf("Enter ciphertext to decrypt: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    decrypt(cipher, key);

    return 0;
}
