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

int Precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string ConvertFromInfixToPostfix(string exp)
{
    stack<char> s;
    string result = "";
    char x;
    for (int i = 0; i < exp.length(); i++)
    {
        x = exp[i];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        {
            if (s.empty() || x == '(')
                s.push(x);
            else
            {
                if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
                {
                    while (!s.empty() && Precedence(x) <= Precedence(s.top()))
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
