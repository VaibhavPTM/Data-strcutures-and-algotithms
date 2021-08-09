#include<iostream>
using namespace std;
/*
write a program to count x raise to power n int low time complexity 
*/
long int solve(int, int);
int main()
{
    int base,power;
    cin>>base >> power;
    cout<<solve(base,power);
    return 0;
}
long int solve(int b , int p){
    long int res = 1;
    while (p > 0)
    {
        if(p % 2 == 0){
            p /= 2;
            b *= b;
        }
        else{
            res *= b;
            p--;
        }
    }
    return res;
}