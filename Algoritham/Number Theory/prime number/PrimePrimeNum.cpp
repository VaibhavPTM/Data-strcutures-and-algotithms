// // problem is from hakerEarth(coderearth)
#include<iostream>
using namespace std;
int arr[1000001];
int ppNum[1000001];
void seive(){
    int maxN = 1000000;
    for (int i = 0; i <= maxN; i++)
    {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    for (long long int i = 2; i * i <= maxN; i++)
    {
        if (arr[i] == 1)
        {
            for (long long int j = i * i; j <= maxN; j+=i)
            {
                arr[j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < maxN; i++)
    {
        if(arr[i] == 1)
        cnt++;

        if(arr[cnt] == 1)
        ppNum[i] = 1;
        else
        ppNum[i] = 0;
    }
}
int main()
{
    seive();
    int t , l ,r;
    cin>>t;
    while (t--)
    {
        cin>>l>>r;
        int cnt = 0;
        for (; l <= r; l++)
        {
            cnt += ppNum[l];
        }
        cout<<cnt<<endl;
        
    }
    
    return 0;
}