
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cstring>
#include <cassert>
#include <bitset>
#include <random>
#include <chrono>
#include <tuple>
#include <fstream>
#include <regex>
using namespace std;
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
vector<pair<int,int>>go(string S){
    vector<pair<int,int>> ans;
    int N = S.size();

    while(true){
        bool allZero=true;
        for(auto u:S){
            if(u=='1')allZero=false;
        }
        if(allZero)break;
        int L=0,R=2;
        for(int i=0;i<N-1;i++){
            if(S[i]==S[i+1]){
                L=i,R=i;
                for(int j=i+1;j<N;j++){
                    if(S[i]==S[j])R++;
                    else break;
                }break;
            }
        }
        for(int i=L;i<=R;i++){
            S[i]='0'+'1'-S[i];
        }
        ans.push_back({L,R});
    }
    return ans;
}
void solved()
{
     int n;cin>>n;

     string S,T;cin>>S>>T;
     vector<pair<int,int>> A = go(S);//make all zero
     vector<pair<int,int>> B = go(T);//make all zero
     reverse(B.begin(),B.end());//reverse to Z to B
     for(auto u:B)A.push_back(u);
     cout<<A.size()<<endl;
     for(auto u:A){
        cout<<u.F+1<<" "<<u.S+1<<endl;
     }
}
int main()
{
   // freopen("test.in", "r", stdin);
   // freopen("test.out", "w", stdout);
   Fast;
   int t=1;
   cin>>t;
   while(t--)
   {
      solved();
      //cout<<'\n';
   }

}
