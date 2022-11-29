#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define s  second
#define f first
ll infLL=1e17;
const int mx=1e5+9;
#define vll vector<pair<ll,ll>>
#define pll pair<ll,ll>
vll adj[mx];
ll dist[mx];
void dijkstra(int s,int n)
{
    for(int i=1;i<=n;i++)
        dist[i]=infLL;

    dist[s]=0;

    priority_queue<pll,vll,greater<pll>>pq;

    pq.push({0,s});
    while(!pq.empty())
    {
        ll u = pq.top().s;
        ll curD= pq.top().f;

        pq.pop();

        if(dist[u]<curD)continue;

        for(auto p:adj[u])
        {
            ll v=p.f;
            ll w = p.s;
            if(curD+w<dist[v])
            {
                dist[v]=curD+w;

                pq.push({dist[v],v});
            }
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});

    }

    dijkstra(1,n);

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";

    return 0;
    
}
