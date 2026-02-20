#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
        int n=nums.size();                //find sorted half ,put the nums[mid] in ans
        int low=0,high=n-1;               //then move to unsorted part and keep checking cond
        int ans=INT_MAX;               
        while(low<=high)
        {
            int mid=(low+high) /2;
            if(nums[low]<=nums[high]) 
            {
                ans=min(ans,nums[low]);     //incase we have sorted part left 
                break;                      //no need to check further and store nums[low] and break  
            }   
            if(nums[low]<=nums[mid])
            {
                ans=min(ans,nums[mid]);
                low=mid+1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }

int main()
{
    vector<int> nums={3,4,5,1,2};
    int result=findMin(nums);
    cout<<result;
}