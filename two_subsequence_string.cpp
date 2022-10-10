#include<bits/stdc++.h>
using namespace std;
const int M=1000;
string s1,s2;
int dp[M][M];
int lcs(int i,int j)
{
	if(i==-1||j==-1)
	{
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];

	if(s1[i]==s2[j])
		return dp[i][j]=1+lcs(i-1,j-1);
	else
		dp[i][j] = max(lcs(i-1,j),lcs(i,j-1));
	return 
	    dp[i][j];
}
int main()
{
   cin>>s1>>s2;
   memset(dp,-1,sizeof(dp));

   int n=s1.size();
   int m=s2.size();
   cout<<"LCS lenght "<<lcs(n-1,m-1)<<endl;
    
}
