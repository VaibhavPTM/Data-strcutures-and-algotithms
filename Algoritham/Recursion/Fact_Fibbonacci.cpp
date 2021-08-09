#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 1 || n == 0) //------> Base condition
    {
        return 1;
    }
    return fact(n - 1) * n; //------> Hypothesis
    // Here we don't need Induction beacuse our inditon of function setisfied the answer
}
int fibonacci(int n)
{
    if (n == 1 || n == 0)
        return n;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
int main()
{
    int n, temp = 0;
    cout << "Enter your number : ";
    cin >> n;
    cout << "Fcatorial : " << fact(n) << endl;
    cout << "Fibbonacci... : ";
    for (int i = 1; i <= n; i++)
    {
        cout << fibonacci(temp) << " ";
        temp++;
    }
    return 0;
}