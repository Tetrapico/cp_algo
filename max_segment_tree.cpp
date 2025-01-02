#include<bits/stdc++.h>
using namespace std;



int a[100000],seg[4*100000];

void build(int indx,int low , int high){

    if(low==high){
        seg[indx]=a[low];return;
    }

    int mid = (low+high)/2;
    build(indx*2+1,low,mid);
    build(indx*2+2,mid+1,high);
    seg[indx]=max(seg[indx*2+1],seg[indx*2+2]);
    return ;
}


int query(int indx,int low,int high,int l,int r){

    if(l<=low&&r>=high)return seg[indx]; 
    if(r<low||high<l)return INT_MIN;
    int mid = (low+high)/2;
    int left = query(indx*2+1,low,mid,l,r);
    int right = query(indx*2+2,mid+1,high,l,r);
    return max(left,right);
}


int main(){

   int n;cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   build(0,0,n-1);
   int q;cin>>q;
   while(q--){
      int l,r;cin>>l>>r;l--,r--;//0 based index;
      
      cout<<query(0,0,n-1,l,r)<<endl;
            

   }

}
