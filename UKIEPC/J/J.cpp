#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>
#define MAXN 105
using namespace std;

struct point
{
    double x , y;
    point(double xx ,double yy)
    {
        x = xx;
        y = yy;
    }
};

vector<vector<pair<point , int > > > of_type; //(point , id)
int n;
int seq[MAXN];
int m;

double dp[MAXN][MAXN];

double dist(point a , point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>seq[i+1];
    cin>>m;
    of_type.resize(MAXN);
    double curr_angle = 0 , angle_inc = 2*M_PI / (double)m;
    for(int i=0;i<m;++i)
    {
        point curr_point = point(sin(curr_angle) , cos(curr_angle));
        int t;
        cin>>t;
        of_type[t].push_back(make_pair(curr_point , i+1));

        //cout<<curr_point.x <<" "<< curr_point.y <<"\n";
        curr_angle += angle_inc;
        
    }
    of_type[0].push_back(make_pair(point(0,0) , 0));
    for(int i= n -1;i>=0;--i)
    {
        int targ = seq[i+1];
        int curr = seq[i];
        for(int j=0;j<of_type[curr].size();++j)
        {
            dp[i][of_type[curr][j].second] = 1e9;
            for(int k=0;k<of_type[targ].size();++k)
            {
                point c = of_type[curr][j].first;
                point t = of_type[targ][k].first;
                double d = dist(c,t);
                dp[i][of_type[curr][j].second] = min(dp[i][of_type[curr][j].second] , d + dp[i+1][of_type[targ][k].second]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    double ans = dp[0][0];
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}