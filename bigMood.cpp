  
#define ll long long
ll bigmod(ll a,ll b,ll M)
{
    if(b==0)return 1;
    ll x=bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2==1)x=(x*a)%M;
    return x;
}

