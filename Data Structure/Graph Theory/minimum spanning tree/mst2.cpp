// Link : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
struct edge
{
    int a;
	int b;
	int w;
};
edge ar[100000];
int par[10001];

int find(int a){
    if(par[a] == -1) return a;
    else return par[a] = find(par[a]);
}

bool cmp(edge a,edge b){
    if(a.w < b.w) {
        return true;
    }
	else 
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <=n; i++){
    	par[i] = -1;
	}
    for(int i = 0; i < m; i++){
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    sort(ar,ar+m,cmp);
    int sum = 0;
    for(int i = 0; i < m; i++){
        int x = find(ar[i].a);
        int y = find(ar[i].b);
        if(x != y){
			par[x] = y;
        	sum += ar[i].w;
    	}
	}
    cout<<sum;
}
