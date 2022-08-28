// Name : TOPOSORT - Topological Sorting
// Link : https://www.spoj.com/problems/TOPOSORT/
#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

vi arr[10001],ans;
int in[10001];

bool kahnS(int n){
    priority_queue<int,vector<int>,greater<>> pq;
    fori(i,n){
        if(in[i] == 0){
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int crr = pq.top();
        ans.pb(crr);
        pq.pop();
        for(int i : arr[crr]){
            in[i]--;
            if(in[i] == 0){
                pq.push(i);
            }
        }
    }
    return n == ans.size();
}
int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while (e--)
    {
        cin>>a>>b;
        arr[a].pb(b);
        in[b]++;
    }
    if(!kahnS(v)){
        cout<<"Sandro fails.";
    }
    else{
        for(auto i : ans){
            cout<<i<<" ";
        }
    }
    
    
    return 0;
}