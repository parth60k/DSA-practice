#include<bits/stdc++.h>
using namespace std;
    int findK(vector<int> &arr,int val)
    {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=val) cnt++;
            else break;
        }
        return val-cnt;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low=1,high=*max_element(arr.begin(),arr.end())+k;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int kmissing=findK(arr,mid);
            if(kmissing<k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
int main()
{
    vector<int> arr={2,3,4,7,11};
    int k=5;
    int ans=findKthPositive(arr,k);
    cout<<"The answer is: "<<ans;

}