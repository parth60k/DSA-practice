#include<bits/stdc++.h>
using namespace std;
int cntBook(vector<int> &nums, int m,int mid)
    {
        int cntstudent=1,pages=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+pages<=mid)   
            {
                pages+=nums[i];
            }
            else
            {
                cntstudent++;
                pages=nums[i];
            }
        }
        return cntstudent;
    }
    int findPages(vector<int> &nums, int m)  {       //low=max[arr] ,high=sum[arr]
        int low=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(cntBook(nums,m,mid)<=m) high=mid-1; //if cnt<=m move to left to find lower
            else low=mid+1;        
        }
        return low;
    }
int main()
{
    vector<int> nums={12, 34, 67, 90};
    int m=2;
    cout<<"output: "<<findPages(nums,m)<<endl;
}