#include<iostream>
#include<vector>
using namespace std;
// Problem from leetcode
int main()
{
    int arr[4] = {1,3,4,6};
    int q[4][2] = {{0,1},{1,2},{0,3},{2,3}};
    
    int n = sizeof(arr)/sizeof(int);
    int pre[n];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i-1] ^ arr[i];
    }
    vector <int> res;
    for (int i = 0; i < sizeof(q)/sizeof(int); i++)
    {
        int L = q[i][0];
        int r = q[i][1];

        if (L==0)
        {
            res.push_back(pre[r]);
        }
        else
        {
            res.push_back(pre[r] ^ pre[L-1]);
        }
        
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<endl;
        }
        

    }
    
    
    return 0;
}