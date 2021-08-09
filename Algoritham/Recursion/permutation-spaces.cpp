#include<iostream>
using namespace std;
void solve(string op,string in)
{
    if (in == "")
    {
        cout<<"\""<<op<<"\""<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(in[0]);
    op2.push_back('_');
    op2.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(op1,in);
    solve(op2,in);
    return;
}
int main()
{
    string in,op="";
    cout<<"Enter your string : ";
    cin>>in;
    op.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(op,in);
    
    return 0;
}