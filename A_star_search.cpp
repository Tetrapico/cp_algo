#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector<pair<int,int>>adj[100000];
vector<int>huristice;
bool vis[100000];
vector<int>path;
int Total_cost=0;
void A_star(int starting_node,int end_node)
{
     path.push_back(starting_node);
     cout<<starting_node<<endl;
     vis[starting_node]=1;
     if(starting_node==end_node)return;

     int mx=100000000;
     int node,cost;
     bool ok=false;
     for(auto u:adj[starting_node]){

       if(vis[u.first]==0)
        {
           int x = u.second+huristice[u.first];
           if(x+Total_cost<mx)
           {
              node=u.first;
              cost=u.second;
              ok=true;
              mx=x+Total_cost;
           }
           vis[u.first]=1;
       }


     }
     Total_cost+=cost;
    if(ok) A_star(node,end_node);
}
int main()
{
    cin>>node>>edge;
    huristice.push_back(0);
    for(int i=0;i<edge;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=0;i<node;i++){
        int x;cin>>x;
        huristice.push_back(x);
    }
    int starting_node,end_node;
    cin>>starting_node>>end_node;
   A_star(starting_node,end_node);
   

}
