
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
int N=2000000;
vector<int>primes;
int status[2000000/32];
int cntfactor[2000001];
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
void factor(int i)
{
   int n=i;
   int cnt=0;
   for(int j=0;primes[j]*primes[j]<=n;j++)
   {
      if(n%primes[j]==0)
      {
         while(n%primes[j]==0)
         {
           n/=primes[j];
           cnt++;
           if(cntfactor[n]!=0)
           {
              cnt+=cntfactor[n];
              cntfactor[i]=cnt;
              return;
           }

         }
      }
      if(Check(status[n/32],n%32)==0)break;
   }
   if(n!=1)cnt++;
   cntfactor[i]=cnt;
  
   return ;
}
void factorization()
{
   for(int i=1;i<=2000000;i++)
   {
      factor(i);
   }
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
   if(a.first!=b.first)
   {
      if(a.first<b.first)return true;
      else
        return false;
   }
   else
   {
      if(a.second<b.second)return true;
      else
        return false;
   }
}
int main()
{
   seive();

   factorization();
  
}
