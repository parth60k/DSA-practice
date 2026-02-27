#include<bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;                                                //set boundaries low=1 to high = max 
        int high=*max_element(nums.begin(),nums.end());           //find mid and then find sum and check whether it is 
        while(low<high)                                           //<= or > threshold value and do further reduction   
        {
            int mid=(low+high)/2;
            long long sum=0;
            for(int num:nums)
            {
                sum+=(num+mid-1)/mid;
            }
            if(sum<=threshold) high=mid;
            else low=mid+1;
        }
        return high;
    }
int main()
{
    vector<int> nums={1,2,3,5,9};
    int threshold=6;
    int ans=smallestDivisor(nums,threshold);
    cout<<"Output is: "<<ans<<endl;
    return 0;
}
