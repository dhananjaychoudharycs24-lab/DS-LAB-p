#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {

    char str1[50] = "Hello";
    char str2[50] = " World";
    char concatenatedStr[100];

    printf("Original String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);


    strcat(concatenatedStr, str2);

    printf("Concatenated String: %s\n", concatenatedStr);

    reverseString(str1);
    printf("Reversed String 1: %s\n", str1);

    reverseString(concatenatedStr);
    printf("Reversed Concatenated String: %s\n", concatenatedStr);

    return 0;
}
