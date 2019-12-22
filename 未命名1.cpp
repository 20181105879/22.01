#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio> 
int s[1000000];
int a[100]={0};
using namespace std;
int main()
{
	long long  n,i;
	cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>s[i];
	  a[s[i]]++;	
	}
	for(i=0;i<=50;i++)
	{
		if(a[i]!=0)
		{
			cout<<i<<":"<<a[i]<<endl;
		} 
	}

	
	return 0;
}

