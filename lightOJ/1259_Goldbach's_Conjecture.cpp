#include<bits/stdc++.h>
using namespace std;

bool sieve[10000060];
vector <int> v;

void sievePrime()
{
    sieve[1] = 1;
    for(long long int i=4; i<=10000000; i+=2)
    {
        sieve[i]=1;
    }

    for(long long int i=3; i<=10000000; i+=2)
    {
        if(!sieve[i])
        {
            for(long long int j=i*i;j<=10000000; j+=(i*2))
            {
                sieve[j]=1;
            }
        }
    }
    for(long long int i=2;i<=10000000;i++)
    {
        if(!sieve[i])
        {
            v.push_back(i);
        }
    }
}
int main()
{
    sievePrime();
    long long int test;
    cin>>test;
    long long int num,d=0;
    for(long long int i=1;i<=test;i++)
    {
        cin>>num;
        d=0;
        for(long long int j=0;j<v.size();j++)
        {
            if(v[j]>num/2)
            {
                break;
            }
            long long int r=num-v[j];
            if(sieve[r]==0)
                d++;
        }
        printf("Case %lld: %lld\n",i,d);
    }

    return 0;
}
