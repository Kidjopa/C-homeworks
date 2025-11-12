#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Элемент стека
typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

// указатель на верхушку стека
typedef struct {
    StackNode* top;
} stack;

// Создать новый пустой стек
stack* newStack();

// Удалить весь стек
void deleteStack(stack *s);

// Положить элемент на стек
void push(stack *s, int value);

// Взять элемент со стека
int pop(stack *s, bool *success);

// Посмотреть верхний элемент стека
int peek(stack *s, bool *success);

// Проверка пустоты стека
bool isEmpty(stack *s);

#endif