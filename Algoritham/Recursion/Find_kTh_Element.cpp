#include <iostream>
#include <cmath>
using namespace std;
int solve(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int mid = pow(2, n - 1) / 2;
    if (k > (mid * 2))
    {
        return -1;
    }
    if (k <= mid)
    {
        return solve(n - 1, k);
    }
    else
    {
        return !(solve(n - 1, k - mid));
    }
    return -1;
}
int main()
{
    int n, k;
    cout << "Enter your column number and k th element : ";
    cin >> n >> k;
    if (solve(n, k) == -1)
    {
        cout << "Element not found";
    }
    else
        cout << "Your answer is " << solve(n, k);
}