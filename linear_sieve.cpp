#include<bits/stdc++.h>
using namespace std;
#define N 150
vector<int>primes;
bool isComposite[N];
void seive(int n)
{
  for(int i=2;i<=n;i++)
  {
    if(!isComposite[i])primes.push_back(i);

  for(int j=0;j<primes.size()&&i*primes[j]<=n;j++)
    {
     isComposite[i*primes[j]]=true;
     if(i%primes[j]==0)break;

    }
  }
}
int main()
{
  int n;
  cin>>n;
  seive(n);
  for(int i=2;i<=n;i++)
    if(!isComposite[i])cout<<i<<endl;

}
