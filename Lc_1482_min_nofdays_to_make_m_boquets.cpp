#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> bloomDay,int day,long long k,long long m)
    {
        int cnt=0;
        int n=bloomDay.size();
        int flowerbloom=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day) cnt++;
            else
            {
                flowerbloom+= cnt/k;
                cnt=0;
            }

        }
        flowerbloom += cnt/k;
        return flowerbloom>= m;
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long n=bloomDay.size();
        long long p=m*k;
        if(p>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(ispossible(bloomDay,mid,k,m))
            {
                
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
int main()
{
    vector<int> bloomDay={7,7,7,7,12,7,7};
    int ans=minDays(bloomDay,2,3);

    cout<<"output: "<<ans<<endl;
}