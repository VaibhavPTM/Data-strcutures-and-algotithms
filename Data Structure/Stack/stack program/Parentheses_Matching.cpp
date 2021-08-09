#include<iostream>
#include<stack>
using namespace std;
bool isSame(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}
bool isMatch(string str){
    stack<char> s;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(' ||str[i] == '{' ||str[i] == '[')
        {
            s.emplace(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (s.empty())
            {
                return 0;
            }
            if (!isSame(s.top(),str[i]))
            {
                return 0;
            }
             s.pop();
        }
        i++;
    }
    if (!s.empty())
    {
        return 0;
    }
    return 1;
}
int main()
{
    string str;
    cin>>str;
    if (isMatch(str))
        cout<<"Parentheses are matched";
    else
        cout<<"Parentheses are not matched";
    return 0;
}