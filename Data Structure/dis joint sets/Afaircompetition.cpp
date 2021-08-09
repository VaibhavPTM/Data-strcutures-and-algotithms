// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/fair-competition-0315250e/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Using disjont set
int find(vector<int> &v,int n){
    if(v[n] < 0) return n;
    return v[n] = find(v,v[n]);
}

int main()
{
    int t,n,m,l,r;
    cin>>t;
    while(t--){
        vector<int> v(n+1,-1);
        cin>>n>>m;
        while(m--){
            cin>>l>>r;
            l = find(v,l);
            r = find(v,r);
            if(l != r){
                v[l] += v[r];
                v[r] = l;
            }
        }
        sort(v.begin(),v.end());
        int ans = 2;
        for(int i = 0; i <= n; i++){
            if(v[i] < -1){
                ans *= abs(v[i]);
            }
            else break;
        }
        cout<<ans<<endl;
    }   
    return 0;
}


// using graphs
/*
#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353
 
// perform the depth first search traversal
// get the size of the connected component
void dfs(ll v,vector<bool>& vis,vi adj[],ll& sz)
{
	sz++;
	vis[v] = true;
 
	for(ll u:adj[v])
	{
		if(!vis[u])
		{
			dfs(u,vis,adj,sz);
		}
	}
}
 
signed main()
{
	FIO;
 
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,a,b,ans=0;
		cin>>n>>m;
		vi adj[n+1];
		vector<bool> vis(n+1,false);
 
		while(m--)
		{
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for(ll i=1;i<=n;i++)
		{
			ll sz = 0;
			if(!vis[i])
			{
				// get the number of friends for the current friend circle
				dfs(i,vis,adj,sz);
 
				// add the answer if one person is choosen from the current friend circle
				ans+=(sz*(n-sz));
			}
		}
 
		cout<<ans<<endl;
	}
}
*/