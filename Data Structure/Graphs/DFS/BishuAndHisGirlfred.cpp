//This is the problem of dfs named bhishu and his girk friend
//link : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[1001];
int distent[1001];
bool discover[1001];

void DFS(int v , int count){
    discover[v] = true;
    distent[v] = count;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        if (!discover[child])
        {
            DFS(child , distent[v] + 1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int edge = n-1;
    int a,b;
    while (edge--)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1,0);
    int q; 
    cin>>q;
    int ans = 0, min_dis = 1000000000;
    
    while (q--)
    {
        int girl_city;
        cin>>girl_city;
        if (distent[girl_city] < min_dis)
        {
            min_dis = distent[girl_city];
            ans = girl_city;
        }
        else if (distent[girl_city] == min_dis && ans > girl_city)
        {
            ans = girl_city;
        }
    }
    cout<<ans;
    return 0;
}
