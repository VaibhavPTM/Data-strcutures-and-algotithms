#include<iostream>
#include<vector>
#include<queue>

#define iil long long int
#define vi vector<int>
using namespace std;

vi graph[10001];
bool dis[10001];
int count[10001];

void bfs(int node){
    queue<int> q;
    dis[node] = true;
    count[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int crr_node = q.front();
        q.pop();
        for(int i : graph[crr_node]){
            if(!dis[i]){
                q.push(i);
                count[i] = count[crr_node] + 1;
                dis[i] = true;
            }
        }   
    }
}

int main()
{
    int v,e,s,r;
    cin>>v>>e;
    while(e--){
        cin>>s>>r;
        graph[s].push_back(r);
        graph[r].push_back(s);
    }

    bfs(1);
    cout<<count[v];
    return 0;
}