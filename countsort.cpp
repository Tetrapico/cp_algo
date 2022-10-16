#include<bits/stdc++.h>
using namespace std;

void countsort(vector<int>& arr)
{
    int max =*max_element(arr.begin(),arr.end());
    int min =*min_element(arr.begin(),arr.end());

    int range = max-min+1;
    vector<int>count(range,0);
    vector<int>random;

    for(int i=0;i<arr.size();i++)
    {
        count[arr[i]-min]++;
    }
    for(int i=0;i<range;i++)
    {
        while(count[i])
        {
            random.push_back(i+min);
            count[i]--;
        }
    }
    for(int i=0;i<random.size();i++)
    {
        arr[i]=random[i];
    }
    return;
}
int main()
{
    vector<int>arr = {-5,-10,0,-3,8,5,-1,10};

    countsort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }




   


}
