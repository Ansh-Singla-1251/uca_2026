#include <stdio.h>
#include <string.h>

const char base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64Encode(const char *input) {
    int len = strlen(input);

    for (int i = 0; i < len; i += 3) {

        unsigned char b1 = input[i];
        unsigned char b2 = (i + 1 < len) ? input[i + 1] : 0;
        unsigned char b3 = (i + 2 < len) ? input[i + 2] : 0;

        int index1 = b1 >> 2;

        int index2 = ((b1 & 0x03) << 4) |
                     (b2 >> 4);

        int index3 = ((b2 & 0x0F) << 2) |
                     (b3 >> 6);

        int index4 = b3 & 0x3F;

        printf("%c", base64[index1]);
        printf("%c", base64[index2]);

        if (i + 1 < len)
            printf("%c", base64[index3]);
        else
            printf("=");

        if (i + 2 < len)
            printf("%c", base64[index4]);
        else
            printf("=");
    }

    printf("\n");
}

int main() {

    char input[1000];

    printf("Enter ASCII string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline
    input[strcspn(input, "\n")] = '\0';

    base64Encode(input);

    return 0;
}