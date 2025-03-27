#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/stack.h"

int main(void) {
    char expression[] = "2 5 3 6 + * * 15 / 2 -";
    Stack_t stack;
    createStack(100,&stack);

    char text[100];

    printf("Adj meg egy szoveget: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0;

    if (isPalindrome(text)) {
        printf("A(z) \"%s\" palindrom!\n", text);
    } else {
        printf("A(z) \"%s\" nem palindrom!\n", text);
    }

    char *token = strtok(expression," ");
    while (token) {
        if (isdigit(token[0])) {
            push(&stack,atoi(token));
        }
        else if (strchr("+-*/%",token[0]) && token[1] =='\0') {
            if (isEmpty(stack)) {
                printf("Missing operand!");
                destroyStack(&stack);
                return -4;
            }
            int op2 = pop(&stack);
            if (isEmpty(stack)) {
                printf("Missing operand!");
                destroyStack(&stack);
                return -4;
            }
            int op1 = pop(&stack);
            push(&stack,performOperation(op1,op2,token[0]));
        }

        else {
            printf("Invalid operator");
            destroyStack(&stack);
            return -4;
        }
        token = strtok(NULL, " ");
    }

    if (stack.top == 0) {
        printf("Result: %d\n", pop(&stack));
    }

    destroyStack(&stack);
    return 0;
}
