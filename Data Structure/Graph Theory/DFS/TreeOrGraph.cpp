// PT07Y - Is it a tree
// You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.
// Link : https://www.spoj.com/problems/PT07Y/
#include<iostream>
using namespace std;
#include<vector>

vector<int> graph[10000];
bool discover[10000];
void dfs(int v){
    discover[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        if (!discover[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    int temp = b;
    int x,y;
    while (temp--)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int count = 0;
    bool ans;

    for (int i = 1; i <= a; i++)
    {
        if(!discover[i])
            dfs(i),
            count++;
    }
    if(count == 1 &&b == (a-1)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}