#include<bits/stdc++.h>
using namespace std;
int koko(vector<int> nums,int h)
{
    int low=1,high=*max_element(nums.begin(),nums.end());
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=(nums[i]+mid-1)/mid;
        }
        if(ans>h) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
    vector<int> nums={3,6,7,11};
    int h=8;
    int k=koko(nums,h);
    cout<<"Minimum integer for koko to finish bananas is: "<< k <<endl;
}