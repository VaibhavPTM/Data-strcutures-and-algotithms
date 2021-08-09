#include<iostream>
using namespace std;

int main()
{
    int arr[4] = {1,4,5,6};
    int sum;
    sum = 0; 
    for (int i = 0; i < 4 /*langth of arr*/ ; i++)
    {
        sum = sum ^ (arr[i] * 2);
    }
    cout<<sum;  // =====  cout<<(2,8,10,12)<<endl;
    return 0;
}