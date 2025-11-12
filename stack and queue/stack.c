#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Создать новый пустой стек
Stack* newStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (!s) return NULL;
    s->top = NULL;
    return s;
}

// Освободить весь стек
void deleteStack(Stack *s) {
    if (!s) return;
    StackNode *current = s->top;
    while (current) {
        StackNode *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(s);
}

// Положить элемент на стек
void push(Stack *s, int value) {
    if (!s) return;
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) return;
    node->value = value;
    node->next = s->top;
    s->top = node;
}

// Взять элемент со стека
int pop(Stack *s, bool *success) {
    if (!s || !s->top) {
        if (success) *success = false;
        return 0;
    }
    StackNode *node = s->top;
    int val = node->value;
    s->top = node->next;
    free(node);
    if (success) *success = true;
    return val;
}

// Посмотреть верхний элемент
int peek(Stack *s, bool *success) {
    if (!s || !s->top) {
        if (success) *success = false;
        return 0;
    }
    if (success) *success = true;
    return s->top->value;
}

// Проверка пустоты
bool isEmpty(Stack *s) {
    return !s || s->top == NULL;
}