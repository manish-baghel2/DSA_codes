#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define SIZE 100
#define SUCCESS 0
#define ERROR -1

struct Stack
{
    int stack[SIZE];
    int top;
};

void stack_push(int stack[], int &top, int item)
{
    if (top == (SIZE - 1))
    {
        cout << "Stack overflow and hence push operation is unsuccessful" << endl;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

void intg_push(int stack[], int &top, int item)
{
    if (top == (SIZE - 1))
    {
        cout << "Stack overflow and hence push operation is unsuccessful" << endl;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

int stack_pop(int stack[], int &top, int &item)
{
    if (top == -1)
    {
        cout << "Stack underflow and hence pop operation is unsuccessful" << endl;
        return ERROR;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

int intg_pop(int stack[], int &top, int &item)
{
    if (top == -1)
    {
        cout << "Stack underflow and hence pop operation is unsuccessful" << endl;
        return ERROR;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

int priority(char p)
{
    if (p == '/' || p == '*')
    {
        return 2;
    }
    else if (p == '+' || p == '-')
    {
        return 1;
    }
    else if (p == '(')
    {
        return 0;
    }
    return -1; // Return -1 for unknown characters
}

int InfixToPostfix(int &top, string exp, string &postfix, int stack[])
{
    int i = 0, j;
    int item;

    while (exp[i] != '\0')
    {
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {
            postfix += exp[i];
        }
        else if (exp[i] == '(')
        {
            stack_push(stack, top, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (stack[top] != '(')
            {
                stack_pop(stack, top, item);
                postfix += static_cast<char>(item);
            }
            stack_pop(stack, top, item);
        }
        else if (exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-')
        {
            if (top == -1)
            {
                stack_push(stack, top, exp[i]);
            }
            else
            {
                if (priority(stack[top]) < priority(exp[i]))
                {
                    stack_push(stack, top, exp[i]);
                }
                else if (priority(stack[top]) >= priority(exp[i]) && top != -1)
                {
                    {
                        stack_pop(stack, top, item);
                        postfix += static_cast<char>(item);
                    }
                    stack_push(stack, top, exp[i]);
                }
            }
        }
        i++;
    }
    while (top != -1)
    {
        stack_pop(stack, top, item);
        postfix += static_cast<char>(item);
    }
    return SUCCESS;
}

int char_to_int(char ch)
{
    return static_cast<int>(ch - '0');
}

int operation(int op1, int op2, char operator)
{
    int result;
    if (operator == '*')
    {
        result = op1 * op2;
    }
    else if (operator == '/')
    {
        result = op1 / op2;
    }
    else if (operator == '+')
    {
        result = op1 + op2;
    }
    else if (operator == '-')
    {
        result = op1 - op2;
    }
    return result;
}

void Evaluation(string postfix)
{
    int i = 0, result, intg_top = -1, intg_stack[SIZE];
    int op1, op2;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            intg_push(intg_stack, intg_top, char_to_int(postfix[i]));
        }
        else
        {
            intg_pop(intg_stack, intg_top, op2);
            intg_pop(intg_stack, intg_top, op1);
            result = operation(op1, op2, postfix[i]);
            intg_push(intg_stack, intg_top, result);
        }
        i++;
    }
    intg_pop(intg_stack, intg_top, result);
    cout << "\nThe Result of the given infix expression is: " << result << endl;
}

int main()
{
    int status, top = -1;
    string exp, postfix;
    int stack[SIZE];
    cout << "Enter the Infix expression: ";
    cin >> exp;
    cout << "Postfix expression of given infix expression is: ";
    InfixToPostfix(top, exp, postfix, stack);
    cout << postfix << endl;
    Evaluation(postfix);
    return 0;
}
