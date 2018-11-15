#include<bits/stdc++.h>
using namespace std;

bool find(vector<int> s,int x)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==x)
			return true;
	return false;
}

int predict(int p[],vector<int> s,int n,int index)
{
	int i,far=index,res=0;
	for(i=0;i<s.size();i++)
	{
		int j;
		for(j=index;j<n;j++)
		{
			if(s[i]==p[j])
			{
				if(j>far)
				{
					res=i;
					j=far;
				}
				break;
			}
		}
		if(j==n)
			return i;
	}
	return res;
}

void findPageFaults(int p[],int n,int capacity)
{
	vector<int> s;
	queue<int> index;
	int i,hits=0,ind;
	for(i=0;i<n;i++)
	{
		if(find(s,p[i]))
		{
			hits++;
			continue;
		}
		else if(capacity>s.size())
			s.push_back(p[i]);
		else
		{
			ind=predict(p,s,n,i+1);
			s[ind]=p[i];
		}
	}
	cout<<"Total Hits: "<<hits<<endl;
	cout<<"Total PageFaults: "<<n-hits<<endl;
}

int main()
{
	int n;
	cout<<"Enter No. of pages: ";
	cin>>n;
	int p[n],i;
	cout<<"Enter "<<n<<" pages:\n";
	for(i=0;i<n;i++)
		cin>>p[i];
	int capacity;
	cout<<"Enter BufferSize: ";
	cin>>capacity;
	findPageFaults(p,n,capacity);
	return 0;	
}
