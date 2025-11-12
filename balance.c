#include <stdio.h>
#include <string.h>
#include "stack and queue/stack.h"

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    Stack *s = newStack();
    if (!s) return 1;

    int balanced = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(s)) {
                balanced = 0;
                break;
            }

            int last = pop(s, NULL);
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                balanced = 0;
                break;
            }
        }
    }

    if (!isEmpty(s)) balanced = 0;

    if (balanced)
        printf("Строка сбалансирована\n");
    else
        printf("Строка несбалансирована\n");

    deleteStack(s);
    return 0;
}