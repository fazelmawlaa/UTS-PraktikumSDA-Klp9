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
