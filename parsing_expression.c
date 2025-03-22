#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Struktur Stack
typedef struct {
    int top;
    char items[MAX][MAX];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char *str) {
    if (!isFull(s)) {
        strcpy(s->items[++(s->top)], str);
    }
}

char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return "";
}
char* peek(Stack *s) {
    return s->items[s->top];
}

char* peek(Stack *s) {
    return s->items[s->top];
}

int priority(char c) {
    switch (c) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

void strrev(char *str) {
    int i, j;
    char temp;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

