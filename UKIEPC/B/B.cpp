#include<iostream>

using namespace std;

int main()
{
    string num;
    cin>>num;
    if(num.size() == 1)
    {
        cout<<num<<"\n";
        return 0;
    }

    
    if(num[1] >= '5')
    {
        if(num[0] == '9')
        {
            num[0] = '0';
            num = "1" + num;
        }
        else
        {
            num[0]++;
        }
        
    }
    for(int i=1;i<num.size();++i)
        num[i] = '0';
    cout<<num<<"\n";
    return 0;
    
}