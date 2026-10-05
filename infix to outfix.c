#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
int priority(char ch)
{
    switch (ch)
    {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else
        {
            switch (ch)
            {
                case '(':
                    push(ch);
                    break;
                case ')':
                    while (top != -1 && stack[top] != '(')
                        postfix[j++] = pop();
                    if (top != -1)
                        pop();
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (top != -1 &&
                           stack[top] != '(' &&
                           priority(stack[top]) >= priority(ch))
                    {
                        postfix[j++] = pop();
                    }
                    push(ch);
                    break;
                default:
                    printf("Invalid character: %c\n", ch);
                    return 1;
            }
        }
        i++;
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
