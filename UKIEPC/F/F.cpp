#include <iostream>
# include<algorithm>

using namespace std;

int main()
{
    int n;
    long long c;
    cin>>n>>c;
    long long arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    sort(arr , arr+n);
    int max_comb_pos = n-1;
    int cnt = 0;
    while(max_comb_pos >= 0 && arr[0] + arr[max_comb_pos] > c)
    {
        ++cnt;
        --max_comb_pos;
    }
    int i = 0 , j = max_comb_pos;
    while(i < j)
    {
        cnt++;
        if(arr[i] + arr[j] <= c)
            i++;
        j--;
    }
    cnt += j-i+1;
    cout<<cnt<<"\n";
    return 0;
}