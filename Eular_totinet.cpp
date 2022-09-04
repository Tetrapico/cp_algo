
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
double Phi(int n)
{
   double result=(double)n;
   for(int i=2;i<=n;i++)
   {
      if(n%i==0)
      {
         while(n%i==0)
         {
            n/=i;
         }
         result*=(1-((double)1/i));
      }

   }
   return round(result);
}
void solved()
{
   int n;
   cin>>n;
   cout<< Phi(n)<<endl;
}
int32_t main()
{
  int t=1;
 // cin>>t;
  while(t--)
  {
    solved();
    cout<<'\n';
  }
}
