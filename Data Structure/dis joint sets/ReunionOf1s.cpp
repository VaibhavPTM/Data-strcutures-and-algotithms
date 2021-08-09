// #include<bits/stdc++.h>
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/
#include<iostream>
using namespace std;
int _rank[100001];
int par[100001];
char ar[100010];

int find(int a)
{
	if(par[a] == -1)
	return a;
 
	else
	return par[a] = find(par[a]);
}
 
void merge(int a , int b)
{
	a = find(a);
	b = find(b);
 
	if(a == b)
	return ;
 
	if(_rank[a] > _rank[b])
	{
		_rank[a] += _rank[b];
		par[b] = a;
	}
	else
	{
		_rank[b] += _rank[a];
		par[a] = b;
	}
}
 
int main()
{
	int n,k,a;
	char c;
	cin>>n>>k;
 
	int mx = 0;
 
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
 
		if(ar[i] == '1')
		{
			par[i] = -1;
			_rank[i] = 1;
 
			if(i > 1 && ar[i-1] == '1') merge(i , i-1);
 
			int p = find(i);
			if(_rank[p] > mx)
			mx = _rank[p];
		}
	}
 
	while(k--)
	{
		cin>>a;
 
		if(a == 1)
		cout<<mx<<'\n';
		else
		{
			cin>>a;
 
			if(ar[a] == '1')
			continue;
			else
			{
				ar[a] = '1';
				par[a] = -1;
				_rank[a] = 1;
 
				if(a > 1 && ar[a - 1] == '1') merge(a , a - 1);
 
				if(a < n && ar[a + 1] == '1') merge(a , a + 1);
 
				int p = find(a);
				if(_rank[p] > mx)
				mx = _rank[p];
			}
		}
	}
 
	return 0;
}