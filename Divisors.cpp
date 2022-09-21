#include<bits/stdc++.h>
using namespace std;
vector<int>divisors[1000002];
void Divisor(int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    return ;
}
int main()
{
    Divisor(1000000);
}
