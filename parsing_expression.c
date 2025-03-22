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

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&s, "(");
        } else if (token == ')') {
            while (!isEmpty(&s) && strcmp(peek(&s), "(") != 0) {
                postfix[j++] = pop(&s)[0];
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && priority(peek(&s)[0]) >= priority(token)) {
                postfix[j++] = pop(&s)[0];
            }
            char op[2] = {token, '\0'};
            push(&s, op);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s)[0];
    }
    postfix[j] = '\0';
}

void postfixToInfix(char *postfix, char *infix) {
    Stack s;
    init(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        if (isalnum(token)) {
            char operand[2] = {token, '\0'};
            push(&s, operand);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op2, pop(&s));
            strcpy(op1, pop(&s));
            sprintf(expr, "(%s%c%s)", op1, token, op2);
            push(&s, expr);
        }
    }
    strcpy(infix, pop(&s));
}

