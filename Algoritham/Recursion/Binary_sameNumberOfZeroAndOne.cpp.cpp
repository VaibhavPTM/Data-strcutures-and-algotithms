#include <iostream>
using namespace std;
void solve(int n,int one,int zero,string op,int n2){
    if(n==0){
        cout<<"\""<<op<<"\" ";
        return;
    }
    int mid = (n2/2)+1;
    if (n2 % 2 == 1 && n == mid)
    {
        string op3 = op;
        string op4 = op;
        op3.push_back('1');
        op4.push_back('0');
        solve(n-1,one,zero,op3,n2);
        solve(n-1,one,zero,op4,n2);
    }
    
    if(zero <(n2/2)){
        string op1 = op;
        op1.push_back('0');
        solve(n-1,one,zero+1,op1,n2);
    }
    if(one < (n2/2)){
        string op2 = op;
        op2.push_back('1');
        solve(n-1,one+1,zero,op2,n2);
    }
    return;
}
int main() {
	int n;
	cout<<"Enter your number : ";
	cin>>n;
    int n2 = n;
	int one = 0,zero = 0;
	string op = "";
	solve(n,one,zero,op,n2);
	return 0;
}