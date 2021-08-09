#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int precedence(char);
int isOprator(char c){
    if (c == '+' || c == '-' || c == '/' || c == '*' || c =='%' || c == '(' || c == ')')
    {
        return 1;
    }
    else{
        return 0;
    }
}
vector<char> postfix(string inFix)
{
    stack<char> s;
    vector<char> postFix;
    int i = 0;
    while (inFix[i] != '\0')
    {
        if (!isOprator(inFix[i]))
        {
            postFix.push_back(inFix[i]);
            i++;
        }
        else if (inFix[i] == '(' || inFix[i] == ')')
        {
            if (inFix[i] == '(')
            {
                s.push(inFix[i]);
                i++;
            }
            else{
                if (s.top() == '(')
                {
                    s.pop();
                    i++;
                }
                else{
                    postFix.push_back(s.top());
                    s.pop();
                }
            }
        }
        else{
            if (s.empty())
            {
                s.emplace(inFix[i]);
                i++;
            }
            
            else if (precedence(s.top()) < precedence(inFix[i]))
            {
                s.emplace(inFix[i]);
                i++;
            }
            else{
                postFix.push_back(s.top());
                s.pop();
            }
        }
    }
    while (!s.empty())    
    {
        postFix.push_back(s.top());
        s.pop();
    }
    return postFix;
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
int precedence(char c){
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '(' || c == ')')
    {
        return 1;
    }
    
    else{
        return 0;
    }   
}