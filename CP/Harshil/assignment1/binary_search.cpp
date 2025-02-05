#include<bits/stdc++.h>
using namespace std;


void binary_search(long long int c)
{
    double left=0,right=100;
    double x=(left+right)/2;
    for(int i=0;i<100;i++)
    {
        if(x*x*x*x+x*x==c)
        {
            x=
        }
        else if(x*x*x*x+x*x<c)
        {
            left=x;
        }
        else
        {
            right=x;
        }
    }
}

int main()
{
    long long int c;
    cin>>c;

}