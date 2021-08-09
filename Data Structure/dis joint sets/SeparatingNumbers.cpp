// Link : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9/
#include<bits/stdc++.h>
using namespace std;
#define mx 300002
#define lli long long int
int par[mx];
int arr[mx];
vector<pair<int,int> > edges;
vector<int> opreations;
map<lli,lli> mp[mx];

int find(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);
}

long long int mearge(int a,int b){
    long long int res = 0;
    if(mp[a].size() < mp[b].size()){
        swap(a,b);
    }
    for (auto p : mp[b])
    {
        if(mp[a].find(p.first) == mp[a].end())
            mp[a][p.first] - p.second;
        else
            res += mp[a][p.first] * p.second;
            mp[a][p.first] += p.second;
    }
    par[b] = a;
    return res;
}

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        par[i] = i;
    }
    for (int i = 1; i <= n-1; i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    for (int i = 1; i <= n; i++){
        cin>>arr[i];
        mp[i][arr[i]] = 1;
    }
    
    for (int i = 1; i <= n-1; i++){
        int t;
        cin>>t;
        opreations.push_back(t);
    }
    
    long long int res = 0;
    vector<long long int> ans;
    while (opreations.size() > 0)
    {
        int t = opreations.back();
        opreations.pop_back();

        int a = find(edges[t-1].first);
        int b = find(edges[t-1].second);

        ans.push_back(mearge(a,b));

    }
    while (ans.size() > 0)
    {
        cout<<ans.back()<<endl;
        ans.pop_back();
    }
    
    return 0;
}