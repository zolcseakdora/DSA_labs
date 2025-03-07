#include <stdio.h>
#include "utils.h"


int main(void)
{
    printf("Prim-e %d\n ", isPrime(13));
    printf("Prim-e %d\n", isPrime(112));
    printf("Prim-e %d\n", isPrime(2));
    printf("Palindrom %d\n", isPalindrome(121));
    printf("Palindrome %d\n", isPalindrome(-121));
    printf("Palindrome %d\n", isPalindrome(12321));
    return 0;
}