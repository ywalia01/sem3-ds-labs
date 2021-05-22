#include <stdlib.h>
#include <stack.h>
#include <stdio.h>
#include <string.h>

bool Pairing(char o, char c)
{
    if (o == "(" && c == ")")
        return true;
    else if (o == "{" && c == "}")
        return true;
    else if (o == "[" && c == "]")
        return true;
    return false;
}

bool CheckParantheses(string exp)
{
    stack<char> s;
    n = exp.length;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == "(" || exp[i] == "{" || exp[i] == "[")
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ")" || exp[i] == "}" || exp[i] == "]")
        {
            if (s.empty || !Pairing(s[top], exp[i]))
                return false;
            else
                s.pop();
        }
    }
}

int main(void)
{
    char exp[25];
    printf("Enter the expression: ");
    scanf("%s", exp);

    if (CheckParantheses(exp))
    {
        printf("The parantheses are balanced ");
    }
    else
    {
        printf("Error! Parantheses not balanced");
    }
}