// Problem from spoj 
// Link : https://www.spoj.com/problems/PT07Z/
#include<iostream>
#include<vector>

#define iil long long int
#define vi vector<int>
using namespace std;

vi graph[10001];
bool discover[10001];
// Better approch
int rooNode,maxD;
void dfs(int v, int c){
    discover[v] = true;
    if(c > maxD)
    maxD = c, rooNode = v;

    for(int i : graph[v]){
        if(!discover[i])
            dfs(i ,c + 1);
    }
}
int main()
{
    int v, e, s, r;
    cin>>v;
    e = v - 1;
    while (e--)
    {
        cin>>s>>r;
        graph[s].push_back(r);
        graph[r].push_back(s);
    }
    maxD = -1;
    dfs(1,0);
    for (int i = 1; i <= v; i++)
        discover[i] = false;

    maxD = -1;
    dfs(rooNode,0);
    
    cout<<maxD;
    return 0;
}



// Naive Approch
// int count[10001];

// void dfs(int v, int count2){
//     discover[v] = true;
//     count[v] = count2;

//     for(int i : graph[v]){
//         if(!discover[i])
//             dfs(i ,count2 + 1);
//     }
// }
// int main()
// {
//     int v, e, s, r;
//     cin>>v;
//     e = v - 1;
//     while (e--)
//     {
//         cin>>s>>r;
//         graph[s].push_back(r);
//         graph[r].push_back(s);
//     }
//     dfs(1,0);
//     int rootNode;
//     int dia = count[0];
//     for(int i = 1; i <= v; i++){
//         if(dia < count[i]){
//             dia = count[i];
//             rootNode = i;
//         }
//     }
//     for (int i = 1; i <= v; i++)
//         count[i] = 0,discover[i] = false;
//     dfs(rootNode,0);
//     dia = count[0];
//     for(int i = 1; i <= v; i++){
//         if(dia < count[i]){
//             dia = count[i];
//             rootNode = i;
//         }
//     }
//     cout<<dia;
//     return 0;
// }
