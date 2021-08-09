// Name : Fire Escape Routes
// Link : https://www.codechef.com/problems/FIRESC

#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[100001];
bool dis[100001];
int timer;
void dfs(int v){
	dis[v] = true;
	timer++;
	
	for(int i = 0; i< graph[v].size(); i++){
		int child = graph[v][i];
		if(!dis[child]){
			dfs(child);
		}
	}
}
int main(){
	int t,v,e,a,b;
	cin>>t;
	while(t--){
		cin>>v>>e;
		
		for(int i = 1; i<= v; i++)graph[i].clear(),dis[i] = false;
		while(e--){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int count = 0;
		long long int path = 1;
		for(int i = 1; i <= v; i++){
			if(!dis[i]){
				timer = 0;
				dfs(i);
				count++;
				path = (path * timer) % 1000000007;
			
			}
		}
		cout<<count<<" "<<path<<endl;
	}
	return 0;
}
