//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>
int main() {
    char str[1000];
    int freq[26] = {0};  
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }
    printf("$\n");
    return 0;
}
