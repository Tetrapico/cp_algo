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
int N=100000000;
int status[100000000/32];
int Phi[2000001];
vector<int>primes;
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
   primes.push_back(2);
  for( i=3;i<=N;i+=2)
  {
    if(Check(status[i/32],i%32)==0)
      primes.push_back(i);
  }
}
void Eulartotient()
{

    for(int i=2;i<=2000000;i++)Phi[i]=i;

      for(int i=0;primes[i]<=2000000;i++)
      {
         for(int j=primes[i];j<=2000000;j+=primes[i])
         {
            Phi[j]-=Phi[j]/primes[i];
         }
      }
}
int main()
{
   seive();
   Eulartotient();
}
