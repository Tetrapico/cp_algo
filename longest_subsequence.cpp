#include<bits/stdc++.h>
using namespace std;
int ara[] = {0,3,1,8,2,5,6,13,8,10,1};
const int M = 10000;
int mem[M];
int lis(int i)
{
	if(mem[i]!=-1)
		return mem[i];
	mem[i] = 1;
	for(int j=1;j<i;j++)
	{
		if(ara[j]<ara[i])
			mem[i] = max(mem[i],1+lis(j));
	}
	return mem[i];
}
int dp[1000];
int parent[1000];
int calclution(int n)
{
	memset(parent,-1,sizeof(parent));
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(ara[j]<ara[i])
			{
				if(1+dp[j]>dp[i])
				{
					dp[i] = 1+dp[j];
					parent[i]=j;
				}
			}
		}
	}
	int ans=0,opt = -1;;

	for(int i=1;i<=n;i++)
	{
		if(dp[i]>ans)
		{
			ans = dp[i];
			opt = i;
		}
	}
	cout<<"iterative "<<ans<<endl;
	
	cout<<endl;
	vector<int>path;
	while(opt!=-1)
	{
         path.push_back(opt);
         opt = parent[opt];
	}
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++)
	{
         cout<<path[i]<<" ";

	}
	cout<<endl;
	return 0;
}
int main()
{
	for(int i=1;i<=10;i++)
		cout<<ara[i]<<" ";
	cout<<endl;
     memset(mem,-1,sizeof(mem));
     calclution(10);
     int ans=0;
     int n=10;
     for(int i=1;i<=n;i++)
     {
     	ans=max(ans,lis(i));
     }
     cout<<"recursive "<<ans<<endl;
}
