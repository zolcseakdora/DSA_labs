//
// Created by Dora on 2025. 02. 27..
//

#include "utils.h"

bool isPrime(int number){
  if(number<1){
    return false;
  }
  for(int i=2; i*i<number; ++i){
    if(number%i==0){
      return false;
    }
  }
  return true;
}
bool isPalindrome(int number)
{
    if (number < 0) {
      return false;
    }
    int originalNumber = number;
    int reversedNumber = 0;

    while (number != 0) {
      int digit = number % 10;
      reversedNumber = reversedNumber * 10 + digit;
      number /= 10;
    }
    return originalNumber == reversedNumber;
  }
