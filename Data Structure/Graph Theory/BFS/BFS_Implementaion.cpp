// Name : Monk and the Islands
// This Problem is releted to bfs search and can be solved using bfs serach witch is level order search
// Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#include<iostream>
#include<vector>
#include<queue>
#define iil long long int
#define vi vector<int>
using namespace std;

vector<int> graph[10001];
bool dis[10001];
int count[10001];

void BFS(int node){
    queue<int> bfs;
    dis[node] = true;
    count[node] = 0;
    bfs.push(node);
    while (!bfs.empty())
    {
        int crr_node = bfs.front();
        bfs.pop();
        for(int child : graph[crr_node]){
            if(!dis[child]){
                dis[child] = true;
                bfs.push(child);
                count[child] = count[crr_node] + 1;
            }
        }
    }
}

int main()
{
    int t , v, e, s, r;
    cin>>t;

    while (t--)
    {
        cin>>v>>e;

        for(int i = 1; i <= v; i++){
            graph[i].clear();
            dis[i] = false;
        }

        while (e--)
        {
            cin>>r>>s;
            graph[r].push_back(s);
            graph[s].push_back(r);
        }

        BFS(1);

        cout<<count[v]<<endl;   
    }
    return 0;
}