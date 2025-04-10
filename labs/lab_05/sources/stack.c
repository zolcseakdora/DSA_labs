//
// Created by Dora on 2025. 03. 20..
//

#include "stack.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//STACK LETREHOZASA, VAGYIS INICIALIZALAS ES DINAMIKUS HELYFOGLALAS
void createStack(int capacity, Stack_t* stack){
  stack->capacity = capacity;
  stack->top = -1;
  stack->elements = (int *)malloc(stack->capacity* sizeof(int));
  if(!(stack->elements)){
    printf("error");
    exit(-1);
   }
}
//FELSZABADITAS
void destroyStack(Stack_t* stack){
  stack->capacity=0;
  stack->top=-1;
  free(stack->elements);
  stack = NULL;
}
//ELLENORZI HOGY TELE VAN-E
bool isFull(Stack_t stack){
    if(stack.top==stack.capacity-1){
      return true;
    }
    return false;
}
//ELLENORZI HOGY URES-E
bool isEmpty(Stack_t stack){
   if (stack.top==-1)
    {
        return true;
    }
    return false;
}
//BETESZ EGY ERTEKET HATULRA VAGYIS NOVELI A "TOP" ERTEKET ES ODA SZURJA BE
void push(Stack_t* stack, int item){
  if(isFull(*stack)){
    printf("A verem tele van");
  }
  stack->elements[++stack->top]=item;
}
//KIVESZ EGY ELEMET AZ UTOLSO POZICIOROL ES UTANA CSOKKENTEM A "TOP" ERTEKET
int pop(Stack_t* stack){
  if(isEmpty(*stack)){
    printf("A verem ures");
    return -1;
  }
  return stack->elements[stack->top--];
}
//MEGMONDJA HOGY A LEGFELSO HELYEN AMI A "TOP" MILYEN ELEM VAN
int peek(Stack_t stack){
  if(isEmpty(stack)){
    printf("A verem ures");
    return -1;
  }
  return stack.elements[stack.top];
}
//MEGMONDJA HOGY HANY ELEM VAN A STACKBEN
int size(Stack_t stack) {
    return stack.top + 1;
}

int performOperation(int num1, int num2, char op) {
  switch (op) {
  case '+': return num1 + num2;
  case '-': return num1 - num2;
  case '*': return num1 * num2;
  case '/': return (num2 == 0) ? printf("Cannot divide by 0"), exit(-4),0 : num1 / num2;
  case '%': return (num2 == 0) ? printf("Cannot divide by 0"), exit(-4),0 : num1 % num2;
  default: printf("Invalid operation %c\n",op); exit(-4);
  }
}

bool isPalindrome(const char *text) {
  Stack_t stack;
  createStack(100,&stack);
  int length = strlen(text);
  char cleanedText[100];
  int cleanedIndex = 0;
  for (int i = 0; i < length; i++) {
    if (isalpha(text[i])) {
      cleanedText[cleanedIndex++] = tolower(text[i]);
    }
  }
  cleanedText[cleanedIndex] = '\0';
  for (int i = 0; i < cleanedIndex; i++) {
    push(&stack, cleanedText[i]);
  }
  for (int i = 0; i < cleanedIndex; i++) {
    if (cleanedText[i] != pop(&stack)) {
      return false;
    }
  }
  return true;
}