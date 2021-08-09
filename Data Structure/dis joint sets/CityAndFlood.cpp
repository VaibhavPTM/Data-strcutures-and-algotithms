// Link : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
#include<iostream>
#include<cmath>
#include<vector>
#define endl "\n"
using namespace std;

int find(vector<int> v,int n){
    if(v[n] < 0) return n;
    return v[n] = find(v,v[n]);
}

int main()
{
    int n;
    cin>>n;
    vector<int> par(n+1,-1);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        a = find(par,a);
        b = find(par,b);
        if(a != b){
            par[a] += par[b];
            par[b] = a;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(par[i] < 0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}