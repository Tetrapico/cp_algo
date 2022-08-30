#include<bits/stdc++.h>
using namespace std;
bool Check(int n,int pos)
{
  return (bool)(n&(1<<pos));
}
int Set(int n,int pos)
{
  return n=n|(1<<pos);
}
int N=100,prime[100];
int status[100/32];
void seive()
{
  int i,j,sqrtN;
  sqrtN=int(sqrt(N));
  for( i=3;i<=sqrtN;i+=2)
  {
    if(Check(status[i/32],i%32)==0)
    {
      for( j=i*i;j<=N;j+=2*i)
        status[j/32]=Set(status[j/32],j%32);
    }
  }
  cout<<2<<endl;
  for( i=3;i<=N;i+=2)
  {
    if(Check(status[i/32],i%32)==0)
      cout<<i<<endl;
  }
}
int main()
{
   seive();
}
