#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsTheCloseOfOpen(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else if (open == '{' && close == '}')
        return true;
    return false;
}

bool IsBalancedParathness(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty() || !IsTheCloseOfOpen(s.top(), exp[i]))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

string ConvertFromInfixToPostfix(string exp)
{
    stack<char> s;
    string result = "";
    char x;
    for (int i = 0; i < exp.length(); i++)
    {
        x = exp[i];
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '(' || exp[i] == ')')
        {
            if (s.empty() || x == '(')
                s.push(x);
            else
            {
                if (x == '+' || x == '-')
                {
                    while (true)
                    {
                        if (s.top() == '*' || s.top() == '/' || s.top() == '(')
                            break;
                        result += s.top();
                        s.pop();
                    }
                    s.push(x);
                }
                else if (x == '*' || x == '/')
                {
                    while (true)
                    {
                        if (s.top() == '(')
                            break;
                        result += s.top();
                        s.pop();
                    }
                    s.push(x);
                }
                else
                {
                    while (true)
                    {
                        if (s.top() == '(')
                            break;
                        result += s.top();
                        s.pop();
                    }
                    s.pop();
                }
            }
        }
        else
            result += x;
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}
