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
const int mxN = 1e6+6;
int spf[mxN];
void sieve() {
    spf[0] = 1;
    for (int i = 1; i < mxN; i++)
        spf[i] = i;
    for (int i = 2; i*i < mxN; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j < mxN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solved()
{
    int x;cin>>x;
    vector<int>prime_factorization;

    while(x>1){
        int y = spf[x];
        prime_factorization.push_back(y);
        while(x%y==0)x/=y;
    }

}
int main()
{
   // freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
   Fast;
   sieve();
   int t=1;
   cin>>t;
   while(t--)
   {
      solved();
      cout<<'\n';
   }

}
