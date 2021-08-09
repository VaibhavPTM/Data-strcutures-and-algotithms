#include <iostream>
using namespace std;
// 1 method
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int gcd2(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b > a)
    {
        return gcd2(b, a);
    }
    // else if ((a - b) < 0)
    // {
    //     return 1;
    // }
    else
    {
        return gcd2(a - b, b);
    }
}
// 2 method
int main()
{
    int a,b;
    cout << "Enter you two number : ";
    cin >> a >> b;
    int c = gcd2(a,b);
    cout << c;
    return 0;
}