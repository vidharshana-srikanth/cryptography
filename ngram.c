#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int n, i, len;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the value of N: ");
    scanf("%d", &n);

    len = strlen(text);

    if (n > len || n <= 0) {
        printf("Invalid N-gram size.\n");
        return 1;
    }

    printf("\n%d-grams:\n", n);
    for (i = 0; i <= len - n; i++) {
        printf("%.*s\n", n, &text[i]);
    }

    return 0;
}
