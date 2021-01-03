#include<iostream>
#include<list>

#define MAXVAL 1000005
#define MAXN 1000005
using namespace std;

int remaining[MAXVAL];

int main()
{
    int n,h;
    cin>>n>>h;
    list<int> cards_available;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        ++remaining[tmp];
        if(remaining[tmp] == 1)
            cards_available.push_back(tmp);
    }
    int cnt = 0;
    while(cards_available.size() >= h)
    {
        cnt++;
        list<int>::iterator it = cards_available.begin();
        for(int i=0;i<h;++i)
        {
            cout<< *it << " ";
            --remaining[*it];
            list<int>::iterator curr = it;
            ++it;
            if(remaining[*curr] == 0)
            {
                cards_available.erase(curr);
            }
            
        }
        cout<<"\n";
    }

    if(cnt == 0)
        cout<<"impossible\n";
    return 0;
}