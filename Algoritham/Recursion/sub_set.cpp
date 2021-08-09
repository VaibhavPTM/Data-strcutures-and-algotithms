#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(string op, string in, vector<string> &v1){
    if (in=="")
    {
        // v1.push_back(op);
        cout<<op<<endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(op1,in,v1);
    solve(op2,in,v1);
    
    return;
}
int main()
{
    string in,op;
    cout<<"Enter your string : ";
    cin>>in;
    op = "";
    vector<string> v1;
    solve(op,in,v1);
    
    sort(v1.begin(),v1.end());
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<"\" "<<v1[i]<<" \","<<" ";
    }
    
    return 0;
}