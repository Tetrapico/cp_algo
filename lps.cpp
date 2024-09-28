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
vector<int> LPS(string s,int n){


    vector<int>lps(n,0);

    for(int i=1;i<n;i++){
        if(s[i]==s[lps[i-1]]){
            lps[i]=lps[i-1]+1;
        }
        else{
            int k=lps[i-1];
            while(k>0 and s[i]!=s[k]){
                k=lps[k-1];
            }
            if(s[i]==s[k])k=k+1;
            lps[i]=k;
        }
    }
    return lps;
}
void solved()
{
    int n;cin>>n;
    string s;cin>>s;

   vector<int>lps = LPS(s,n);  
   for(int i=0;i<n;i++){
      cout<<lps[i]<<endl;
   }
}
int main()
{
   // freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
   Fast;
   int t=1;
   //cin>>t;
   while(t--)
   {
      solved();
      cout<<'\n';
   }

}
