/*
when we have large array of numbers and we want to find all number is whther number is prime or not then
this algorithem will work
time complexity = N(Nlog(logN))
*/
#include <iostream>
int is_prime[1000001];
using namespace std;
void sieve(void)
{
    // it will print all the prime number from a to maxN
    int maxN = 50;
    for (int i = 1; i <= maxN; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxN; j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 0; i <= maxN; i++)
    {
        if (is_prime[i]==1)
        {
            cout<<i<<" ";
        }
        
    }
    
}
int main()
{
    sieve();

    return 0;
}