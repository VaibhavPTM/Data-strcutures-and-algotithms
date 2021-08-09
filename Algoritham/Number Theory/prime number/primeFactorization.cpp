#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // cout<<1<<" ";
    for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++,n/=i;
            // cout<<i<<" ";
        }
        cout<<i<<"^"<<count<<" * ";
    }
    if(n > 1){
        cout<<n<<"^"<<1;
        // cout<<n<<" ";
    }
    // complexity of this approch is O(sqrt(N)) 
    return 0;
}