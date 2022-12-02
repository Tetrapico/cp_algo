#include<bits/stdc++.h>
using namespace std;

struct DisjointSetUnion{
    int n;
    vector<int>par,sz;
    DisjointSetUnion(){ }
    DisjointSetUnion(int _n) : n(_n){
        par.resize(n+1,0);
        sz.assign(n+1,1);
        iota(par.begin(),par.end(),0);
    }
    int find(int u){
        return par[u]= (u==par[u]?u:find(par[u]));
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u==v)return false;
        if(sz[u]>sz[v])swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};
int main()
{
     int n;cin>>n;
     int m;cin>>m;
     DisjointSetUnion d1(n),d2(n);
     while(m--){
        int u,v;
        cin>>u>>v;
        d1.unite(u,v);
     }





}
