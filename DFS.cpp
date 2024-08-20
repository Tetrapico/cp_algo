/*
ID: ibrahim55
LANG: C++
TASK: test
*/


#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//cout<<s.order_of_key(5)::Number of items strictly smaller than k
//cout<<*s.find_by_order(0)::K-th element in a set (counting from zero)

#define mp make_pair
#define pb push_back
#define ll long long
#define F first
#define S second
#define Fast ios::sync_with_stdio(0);cin.tie(0)
 
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first){
        if(a.first>b.first)
            return true;
        return false;
    }
    else{
        if(a.second<b.second)
            return true;
        return false;
    }
}
vector<int>node[10005];
vector<int>color(10005);
int nodes,edgs;
void dfs(int x){
    color[x]=1;
    for(auto u:node[x]){
        if(color[u]==0){
            dfs(u);
        }
    }
}
void solved()
{
     cin>>nodes>>edgs;
     for(int i=0;i<edgs;i++){
        int u,v;cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
     }
   //  memset(color,0,sizeof(color));
     dfs(1);
     for(int i=1;i<=7;i++){
        cout<<color[i]<<endl;
     }
}
int main()
{
   // freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
   Fast;
   int t=1;
  // cin>>t;
   while(t--)
   {
      solved();
      cout<<'\n';
   }

}
