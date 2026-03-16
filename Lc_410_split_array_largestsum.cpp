#include<bits/stdc++.h>
using namespace std;
int cntSubarray(vector<int>& nums, int k,int mid)
    {
        int cntsub=1,summ=0;
        for(int i=0;i<nums.size();i++)
        {
            if(summ+nums[i]<=mid)
            {
                summ+=nums[i];
            }
            else
            {
                cntsub++;
                summ=nums[i];
            }
        }
        return cntsub;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(cntSubarray(nums,k,mid)<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
int main()
{

    vector<int> nums={7,2,5,10,8};
    int k=2;
    cout<<"Output is: "<<splitArray(nums,k);
}