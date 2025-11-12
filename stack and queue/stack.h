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
} Stack;

// Создать новый пустой стек
Stack* newStack();

// Удалить весь стек
void deleteStack(Stack *s);

// Положить элемент на стек
void push(Stack *s, int value);

// Взять элемент со стека
int pop(Stack *s, bool *success);

// Посмотреть верхний элемент стека
int peek(Stack *s, bool *success);

// Проверка пустоты стека
bool isEmpty(Stack *s);

#endif