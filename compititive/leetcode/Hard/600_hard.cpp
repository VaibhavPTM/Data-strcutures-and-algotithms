// Link : https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Topic : Non-negative Integers without Consecutive Ones
#include <bits/stdc++.h>
using namespace std;
int findIntegers(int n){
    int f[31];
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 31; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    int res = 0, bit = 30, pre_bit = 0;
    while (bit >= 0)
    {
        if (n & (1 << bit))
        {
            res += f[bit];
            if (pre_bit)
                return res;
            pre_bit = 1;
        }
        else
        {
            pre_bit = 0;
        }
        bit--;
    }
    return res + 1;
}
int main()
{
    int n;
    cin>>n;
    cout<<findIntegers(n);

    return 0;
}