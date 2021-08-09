#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cin>>n>>i;
    int f = 1;
    f = f<<i;
    int ans = n & f;
    if (ans==0)
    {
        cout<<"false";
    }
    else
    {
        cout<<"True";
    }
    return 0;
}