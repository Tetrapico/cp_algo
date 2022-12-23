#include<bits/stdc++.h>
using namespace std;
#define mx 100000
int arr[mx];
#define ll long long
struct info{
    ll prop,sum;
}tree[mx*3];

void init(int node ,int b, int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    init(left ,b,mid);
    init(right,mid+1,e);

    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].prop = 0;
}

void update(int node ,int b,int e ,int i, int j, ll x)
{
    if(i>e||j<b)
        return;

    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;

}

int query(int node , int b, int e, int i,int j, int carry =0)
{
    if(i>e||j<b)
        return 0;

    if(b>=1&&e<=j)
        return tree[node].sum + carry*(e-b+1);

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int p1 = query(left,b,mid,i,j, carry + tree[node].prop);
    int p2 = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    init(1,1,5);

    update(1,1,5,2,4,100);
    
    for(int i=1;i<=10;i++)
    {
        cout<<tree[i].sum<<endl;
    }

}
