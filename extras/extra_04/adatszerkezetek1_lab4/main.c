#include <stdio.h>
int balancedStringSplit(char *s);
int main() {
    // Example test cases
    printf("%d\n", balancedStringSplit("RLRRLLRLRL")); // Output: 4
    printf("%d\n", balancedStringSplit("RLRRRLLRLL")); // Output: 2
    printf("%d\n", balancedStringSplit("LLLLRRRR"));   // Output: 1
    return 0;
}
int balancedStringSplit(char *s) {
    int count = 0, a = 0;
    while (*s) {
        if (*s == 'L')
            a++;
        else
            a--;

        if (a == 0)
            count++;
        s++;
    }
    return count;
}