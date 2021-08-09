// Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

int knapSack(int w, int wt[], int val[], int n) 
    { 
        if(w == 0 || n == 0){
            return 0;
        }
        else if(wt[n-1] <= w){
            return max(val[n-1] + knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1));
        }
        else{
            return knapSack(w,wt,val,n-1);
        }
    }
int main()
{
    int w,n;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    cout<<knapSack(w,wt,val,n);
    return 0;
}