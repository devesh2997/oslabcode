#include<bits/stdc++.h>
using namespace std;


void findPageFaults(int p[],int n,int capacity)
{
	int i,hits=0,val;
	set<int> s;
	queue<int> index;
	for(i=0;i<n;i++)
	{
		if(s.find(p[i])==s.end())
		{
			if(capacity>s.size())
			{
				s.insert(p[i]);
				index.push(p[i]);
			}
			else
			{
				val=index.front();
				index.pop();
				s.erase(val);
				s.insert(p[i]);
				index.push(p[i]);
			}
		}
		else
		{
			hits++;
		}
	}
	cout<<"Total Hits are: "<<hits<<endl;
	cout<<"Total PageFaults are : "<<n-hits<<endl;
}

int main()
{
	int n;
	cout<<"Enter Number of Pages: ";
	cin>>n;
	int p[n],i,capacity;
	cout<<"Enter "<<n<<" Pages:\n";
	for(i=0;i<n;i++)
		cin>>p[i];
	cout<<"Enter Buffer Size : ";
	cin>>capacity;
	findPageFaults(p,n,capacity);
}
