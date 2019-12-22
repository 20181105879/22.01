#include <iostream>
#include <map>
using namespace std;
map<string,long> m;
int main()
{
	long n;
	cin>>n;
	string t1,t2;
	string t;
	long max=-1;
	long num;
	long s=0;
	for(long i=0;i<n;i++)
	{
		cin>>t1>>t2;
		num=++m[t1];
		if(num>=max)
		{
		
			if(num==max)
			{	s++;
				if(t1<t)
				{
				
					t=t1;
				}
			}
			else
			{
				s=0;
				max=num;
				t=t1;
			}
			
		}
		
		
		num=++m[t2];
		if(num>=max)
		{
			if(num==max)
			{
				s++;
				if(t2<t)
				{
					t=t2;
				}
			}
			else
			{
				s=0;
				max=num;
				t=t2;
			}
		}
		
	}
	cout<<t<<" "<<max;
	if(s!=0)
	{
		cout<<" "<<s+1;
	}
	return 0;
}
