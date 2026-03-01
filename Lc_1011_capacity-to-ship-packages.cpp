#include<bits/stdc++.h>
using namespace std;
int noDays(vector<int>&weights,int capacity)
    {
        int days=1,load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load+weights[i]>capacity)
            {
                days++;
                load=weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        long long sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
        }
        int high=sum;
        while(low<high)
        {
            int mid=(low+high)/2;
            int ans=noDays(weights,mid);
            if(ans<=days) high=mid;
            else low=mid+1;
        }
        return high;
    }
int main()
{
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int ans=shipWithinDays(weights,5);
    cout<<"Output is: "<<ans<<endl;
}