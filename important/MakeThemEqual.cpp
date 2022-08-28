// Link : https://codeforces.com/contest/1633/problem/D
// Tag : DP
#include<bits/stdc++.h>
using namespace std;
int v[10000];
int b[1009];
int c[1009];
int dp[1000009];
int main()
{
	ios::sync_with_stdio(false);
	for(int i=2;i<=1000;i++) v[i]=10000;
	v[1]=0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			v[i+i/j]=min(v[i+i/j],v[i]+1);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int j=k;j>=0;j--) dp[j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=k;j>=0;j--)
			{
				if((j-v[b[i]])>=0) dp[j]=max(dp[j],dp[j-v[b[i]]]+c[i]);
			}
		}
		cout<<dp[k]<<endl;
	}
}