//#include <asm-generic/errno-base.h>
#include <bits/stdc++.h>
#include <cstring>
#include <math.h>
using namespace std;
ifstream f("date.in");
vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int n = expenditure.size();
    int count[201];
    int nr=0;
    //memset(count,0,sizeof(count));
    for(int j=0;j<=200;j++)
        count[j]=0;
    if(d==n) return 0;
    //int s;
    for(int i=0;i<d;i++)
    {
        count[expenditure[i]]++;
    }
    for(int i=1;i<201;i++)
        count[i]+=count[i-1];
    int m=d/2;
    for(int i=d;i<n;i++)
    {
        int ex[201];
        for(int j=1;j<=200;j++)
        {
            ex[j]=count[j];
        }
        if(d%2==1)
        {
            int p =0;
            for(int j=i-d;j<i;j++)
            {
                if(ex[expenditure[j]]-1==m)
                {
                    p = expenditure[j];
                    break;
                }
                --ex[expenditure[j]];
            }
            if(expenditure[i]>=2*p) nr++;
        }
        else
        {
            int p=0; int k=0;
            for(int j=i-d;j<i;j++)
            {
                if(ex[expenditure[j]]-1==m-1||ex[expenditure[j]]-1==m)
                {
                    p += expenditure[j];
                    k++;
                }
                if(k==2) break;
                --ex[expenditure[j]];
            }
            if(expenditure[i]>=p) nr++;
        }
        if(expenditure[i]<expenditure[i-d])
            for(int j=expenditure[i];j<expenditure[i-d];j++)
                count[j]++;
        else
            for(int j=expenditure[i-d];j<expenditure[i];j++)
                count[j]--;
    }
    return nr;
}

int main()
{
    /**ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(f, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);


    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }
    **/
    vector<int> expenditure;
    int n,d;
    f>>n>>d;
    for(int i=0;i<n;i++)
    {
        int x;
        f>>x;
        expenditure.push_back(x);
    }
    int result = activityNotifications(expenditure, d);

    cout << result << "\n";

    //fout.close();

    return 0;
}
/*
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}*/
