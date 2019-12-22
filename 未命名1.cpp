#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v;
	stack<int> s;
	
	int n,m;
	cin>>n;
	string name;
	int j;
	for(int i=0;i<n;i++)
	{
		cin>>name;
		if(name=="Pop")
		{
			if(s.empty())
			{
				cout<<"Invalid"<<endl;
			}
			else
			{
				cout<<s.top()<<endl;
				//vector<int>::iterator j=lower_bound(v.begin(),v.end(),s.top());
				//v.erase(j)
				v.erase((lower_bound(v.begin(),v.end(),s.top())));
				s.pop();
			}
		}
		else if(name=="Push")
		{
			cin>>m;
			s.push(m);
//			vector<int>::iterator j=lower_bound(v.begin(),v.end(),t);
//			v.insert(j,t);			
			v.insert(lower_bound(v.begin(),v.end(),m),m);
		}
		else if(name=="PeekMedian")
		{
			if(s.empty())
			{
				cout<<"Invalid"<<endl;
			}
			
			else
			{
//				cout<<v[(v.size()+1)/2-1]<<endl;
				cout<<v.at((v.size()+1)/2-1)<<endl;
			}
			
		}
		else
		{
			;
			
			
		}

		
	}
	

	
	return 0;
 }
