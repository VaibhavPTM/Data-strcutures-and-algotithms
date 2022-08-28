// Link : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
int par[10001];
multimap<int,pair<int,int>> edge;

int find(int a){
    if(par[a] == -1) return a;
    else return par[a] = find(par[a]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i =1; i <= n; i++) par[i] = -1;
    int i = 0;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edge.insert({c,{a,b}});
    }
    long ans = 0;
    for(auto i : edge){
        int a = i.second.first;
        int b = i.second.second;
        if(find(a) != find(b)){
            par[b] = a;
            ans += i.first;
        }
    }
    
    cout<<ans;
    
    return 0;
}
