//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i, len;
    scanf("%s", str);
    len = strlen(str);
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    return 0;
}
