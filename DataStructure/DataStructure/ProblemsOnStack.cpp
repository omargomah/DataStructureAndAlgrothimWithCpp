#include <iostream>
#include <string>
#include <stack>
using namespace std;
int GetPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

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


string ConvertFromInfixToPostFix(string exp)
{
    stack<char> c;
    char x;
    string result = "";
    for (int i = 0; i < exp.length(); i++)
    {
        x = exp[i];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        {
            if (c.empty() || x == '(')
                c.push(x);
            else if (x == ')')
            {
                while (c.top() != '(')
                {
                    result += c.top();
                    c.pop();
                }
                c.pop();
            }
            else
            {
                while (!c.empty() && GetPriority(c.top()) >= GetPriority(x))
                {
                    result += c.top();
                    c.pop();
                }
                c.push(x);
            }
        }
        else
            result += x;
    }
    while (!c.empty())
    {
        result += c.top();
        c.pop();
    }
    return result;
}


string ConvertFromInfixToPrefix(string exp)
{
    stack<char> c;
    char x;
    string result = "";
    for (int i = exp.length() - 1; i > -1; i--)
    {
        x = exp[i];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        {
            if (c.empty() || x == ')')
                c.push(x);
            else if (x == '(')
            {
                while (c.top() != ')')
                {
                    result = c.top() + result;
                    c.pop();
                }
                c.pop();
            }
            else
            {
                while (!c.empty() && GetPriority(c.top()) > GetPriority(x))
                {
                    result = c.top() + result;
                    c.pop();
                }
                c.push(x);
            }
        }
        else
            result = x + result;
    }
    while (!c.empty())
    {
        result = c.top() + result;
        c.pop();
    }
    return result;
}

void ConvertFromDecimalToBinary(int num)
{
    stack<int> s;
    while (num != 0)
    {
        s.push(num % 2);
        num /= 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

}

double EvaluationPostFix(string exp)
{
    stack<double> s;
    char x;
    double num1, num2, result;
    for (int i = 0; i < exp.length(); i++)
    {
        x = exp[i];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        {
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            switch (x)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
            {
                if (num2 == 0)
                {
                    cout << "you can't divide by zero" << endl;
                    return NULL;
                }
                result = num1 / num2;
                break;
            }
            case '^':
                result = pow(num1, num2);
                break;
            default:
                cout << "Invalid operation" << endl;
                return NULL;
            }
            s.push(result);
        }
        else
        {
            if (x < 48 || x > 57)
            {
                cout << "Invalid operation" << endl;
                return NULL;
            }
            s.push(x - '0');
        }
    }
    result = s.top();
    s.pop();
    return result;
}
int EvaluatePreFix(string exp)
{
    stack<double> s;
    char x;
    for (int i = exp.length() - 1; i > -1; i--)
    {
        x = exp[i];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        {
            double num1 = s.top();s.pop();
            double num2 = s.top();s.pop();
            switch (x)
            {
            case '+':
                s.push(num1 + num2);
                break;
            case '-':
                s.push(num1 - num2);
                break;
            case '*':
                s.push(num1 * num2);
                break;
            case '^':
                s.push(pow(num1, num2));
                break;
            case '/':
            {
                if (num2 == 0)
                {
                    cout << "divide by zero invalid" << endl;
                    return NULL;
                }
                s.push(num1 / num2);
                break;
            }
            default:
                cout << "invalid operation" << endl;
                return NULL;
            }
        }
        else
            s.push(x - '0');
    }
    return s.top();
}

