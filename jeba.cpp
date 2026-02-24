#include <iostream>
#include <string>
using namespace std;

int main()
{
    string regex;
    cout << "Input the regular expression: ";
    cin >> regex;

    if (regex.empty())
    {
        cout << "Expression is not valid."<< endl;
        return 0;
    }

    int operatorCount = 0;
    char op = '\0';

    for (char c : regex)
    {
        if (c == 'U' || c == '*' || c == '+')
        {
            operatorCount++;
            op = c;
        }
    }

    if (operatorCount != 1)
    {
        cout << "Expression is not valid."<< endl;
        return 0;
    }

    string str;
    cout << "Enter the test string: ";
    cin >> str;

    bool result = false;

    if (op == '*')
    {
        char ch = regex[0];
        result = true;
        for (char c : str)
        {
            if (c != ch)
            {
                result = false;
                break;
            }
        }
    }

    else if (op == '+')
    {
        char ch = regex[0];
        if (!str.empty())
        {
            result = true;
            for (char c : str)
            {
                if (c != ch)
                {
                    result = false;
                    break;
                }
            }
        }
    }

    else if (op == 'U')
{
    char ch1 = regex[0];
        char ch2 = regex[2];
        if (str.length() == 1 && (str[0] == ch1 || str[0] == ch2))
        {
            result = true;
        }
    }

    if (result)
    cout << "Result: Accepted by the expression."<< endl;
    else
        cout << "Result: Rejected by the expression." << endl;

        return 0;
    }
