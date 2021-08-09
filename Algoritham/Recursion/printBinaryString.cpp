#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve(int n, string op, vector <string> &v){
    if (n == 0)
    {
        v.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back('0');
    op2.push_back('1');
    solve(n-1,op1,v);
    solve(n-1,op2,v);
    
}
int main()
{
    string op = "";
    int n;
    cin>>n;
    string in;
    vector <string> v;
    solve(n,op,v);
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}