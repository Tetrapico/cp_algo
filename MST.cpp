#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
int nodeCount,edgeCount;
struct edge{
    int from,to,weight;
    edge(int _u,int _v,int _w)

    {
       from=_u,to=_v,weight=_w;
    }
    bool operator< (const edge& p)const{
        return weight<p.weight;
    }
};
vector<edge>graph;
int findParent(int node)
{
    if(parent[node]==node)
        return node;
    return parent[node]=findParent(parent[node]);
}
int mst(int nodeNumber)
{
    sort(graph.begin(),graph.end());
    for(int i=0;i<=nodeNumber;i++)
        parent.push_back(i);

    int cost=0;
    for(int i=0;i<graph.size();i++)
    {
        int from=findParent(graph[i].from);
        int to=findParent(graph[i].to);
        if(from!=to)
        {
            parent[to]=from;
            cost+=graph[i].weight;
        }
    }
    return cost;
}
int main()
{

    cin>>nodeCount>>edgeCount;
    for(int i=1;i<=edgeCount;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(edge(u,v,w));

    }
    cout<<mst(nodeCount);
    
}
