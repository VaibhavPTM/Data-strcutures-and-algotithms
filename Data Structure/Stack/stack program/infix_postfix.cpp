#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<char> postfix(string str)
{
    stack<char> s;
    vector<char> c;
    int i = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] == '-' || str[i] == '%' || str[i] == '/' || str[i] == '*' || str[i] == '+')
        {
            if (s.empty())
            {
                s.emplace(str[i]);
            }
            else
            {
                if (s.top() == '+' || s.top() == '-')
                {
                    if (str[i] == '+' || str[i] == '-')
                    {
                        c.push_back(s.top());
                        s.pop();
                        s.emplace(str[i]);
                    }
                    else
                    {
                        s.emplace(str[i]);
                    }
                }
                else
                {
                    if (str[i] == '+' || str[i] == '-')
                    {
                        while (!s.empty())
                        {
                            c.push_back(s.top());
                            s.pop();
                        }
                        s.emplace(str[i]);
                    }
                    else
                    {
                        c.push_back(s.top());
                        s.pop();
                        s.emplace(str[i]);
                    }
                }
            }
        }
        else
        {
            c.push_back(str[i]);
        }
        i++;
    }
    while (!s.empty())
    {
        c.push_back(s.top());
        s.pop();
    }

    return c;
}
int main()
{
    string str;
    vector<char> c;
    cout << "Enter your infix expresson : ", cin >> str;
    c = postfix(str);
    cout << "postfix expression : ";
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i];
    }

    return 0;
}