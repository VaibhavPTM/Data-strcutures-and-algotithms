#include<iostream>
#include<vector>
using namespace std;
void solve(int open,int close,vector<string> &v,string op,int &count){
    if (open==0 && close==0)
    {
        v.push_back(op);
        count++;
        return;
    }
    if (close>open)
    {
        string op2;
        op2 = op;
        op2.push_back(')');
        solve(open,close-1,v,op2,count);
    }
    if (open!=0)
    {
        string op1;
        op1 = op;
        op1.push_back('(');
        solve(open-1,close,v,op1,count);
    }
    return;
}
int main()
{
    int n;
    cout<<"Enter the number of parentheses : ";
    cin>>n;
    int open = n,close = n;
    vector <string> v;
    string op = "";
    int count=0;
    solve(open,close,v,op,count);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"Number of parentheses is : "<<count;
    return 0;
}