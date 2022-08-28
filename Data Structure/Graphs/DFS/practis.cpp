// PT07Y - Is it a tree
// You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.
// Link : https://www.spoj.com/problems/PT07Y/
#include<iostream>
using namespace std;
#include<vector>

vector<int> graph[10000];
bool discover[10000];

int main()
{
    int a,b;
    cin>>a>>b;
    int x,y;
    while (b--)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    if(b == (a-1)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    
    return 0;
}
