#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[10000];
int discover[10000];

bool dfs(int v, int parent){
	discover[v] = true;
	for(int i= 0; i< graph[v].size();i++){
		int child = graph[v][i];
		if(!discover[child]){
			if(dfs(child,v)== true){
				return true; // true meanse there is a back edge and it contains a cycle
			}
		}
		else if(child != parent){
			return true;
		}
	}
	return false;
}

int main(){
	int a,b,s,r;
	cin>>a>>b;
	while(b--){
		cin>>s>>r;
		graph[s].push_back(r);
		graph[r].push_back(s);
	}
	bool temp = false;
	for(int i = 1; i <= a; i++){
		if(!discover[i]){
			if(dfs(i,-1)== true){
				temp = true;
			}
		}
	}
	if(temp)
		cout<<"Graph contains cycle";
	else
		cout<<"Graph does't contains cycle";
	return 0;
}
