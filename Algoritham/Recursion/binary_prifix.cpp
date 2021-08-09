#include<iostream>
using namespace std;
void solve(int one,int zero,int n,string op){
    if (n==0)
    {
        cout << "\'" << op << "\' | "<< " ";
        return;
    }
    if (one>zero)
    {
        string op2 = op;
        op2.push_back('0');
        solve(one,zero+1,n-1,op2);
    }
    string op1 = op;
    op1.push_back('1');
    solve(one+1,zero,n-1,op1);
    return;
    
}
int main()
{
    int n;
    cout<<"Enter your N : ";
    cin>>n;
    int one = 0;
    int zeroes = 0;
    string op = "";
    solve(one,zeroes,n,op);
    
    return 0;
}