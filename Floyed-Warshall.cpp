// It can detect negative edge weight cycle.
//Finding the shortest path
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<stack>
#include <sstream>
#include<unordered_map>
using namespace std;

vector<vector<int>>dis;

void Floydd_Warshall(const vector<vector<int>> & graph){
    int v=graph.size();
    for(int k=0;k<v;k++){
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                    if (dis[i][k]==INT_MAX || dis[k][j]==INT_MAX)continue;                   
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                  
            }
        }
    }
}

int main()
{

    int v=4;
    vector<vector<int>>graph(v,vector<int>(v,INT_MAX));
    graph[0][0]=0;
    graph[1][1]=0;
    graph[2][2]=0;
    graph[3][3]=0;
    
    graph[0][3]=5;
    graph[0][1]=3;
    graph[1][0]=2;
    graph[1][3]=8;
    graph[2][1]=1;
    graph[3][2]=2;
    
    dis=graph;


    Floydd_Warshall(graph);

    cout<<dis[1][3];

    
    return 0;
}