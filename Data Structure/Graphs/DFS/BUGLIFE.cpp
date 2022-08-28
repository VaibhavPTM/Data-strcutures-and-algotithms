/*
This problem is from spoj and based on Bipartite graph
Name : BUGLIFE - A Bug’s Life
Link : https://www.spoj.com/problems/BUGLIFE/
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[2001];
int color[2001];
bool discover[2001];

bool dfs(int v, int c){

    
    discover[v] = true;
    color[v] = c;
    for (int i:graph[v])
    {
        if (!discover[i])
        {
            if(!dfs(i,c ^ 1)){
                return false;
            }
        }
        else if(color[v] == color[i])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int t , vertex, edge , source, root;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin>>vertex>>edge;
        for (int i = 1; i <= vertex ; i++)
        graph[i].clear(),discover[i] = false;
        
        for (int i = 0; i < edge; i++)
        {
            cin>>source>>root;
            graph[source].push_back(root);
            graph[root].push_back(source);
        }
        bool flag = true;
        for (int i = 1; i <= vertex; i++)
        {
            if(!discover[i]){
                if(dfs(i,0) == false){
                    flag = false;
                }
            }
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        if (!flag)
        {
            cout<<"Suspicious bugs found!"<<endl;
        }
        else{
            cout<<"No suspicious bugs found!"<<endl;
        }
    }
    return 0;
}