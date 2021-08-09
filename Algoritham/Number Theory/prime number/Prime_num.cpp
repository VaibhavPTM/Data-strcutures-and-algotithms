#include<iostream>
using namespace std;
// better aproch to do this run a loop to i<=sqare root of n! 
int main()
{
    int n;
    cout<<"enter your number : ";
    cin>>n;
    int flage = 1;
    if (n==1)
    {
        flage=0;
    }
    
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flage = 0;
        }
    }
    if (flage == 1)
    {
        cout<<"Number is prime";
    }
    else
    {
        cout<<"Number is not prime";
    }
    return 0;
}