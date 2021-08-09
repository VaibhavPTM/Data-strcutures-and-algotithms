#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count = 0;
    // Algoruthm 1
    while (n>0)
    {
        count++;
        n = n & (n - 1);
    }
    if (count == 1)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    // Algorithm 2
    /*
    if (n <= 0)
        cout << "false";
    if ((n & (n - 1)) == 0)
        cout << "true";
    else
        cout << "false";
    */
    return 0;
}