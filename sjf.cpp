#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id,at,bt;
	bool complete;
};

bool comp(process &a,process &b)
{
	return (a.at<b.at);
}

int main()
{
	int n,i,at,bt,ind,mini;
	cout<<"Enter no. of process: ";
	cin>>n;
	process p[n];
	cout<<"Enter Proceesses:\n";
	for(i=0;i<n;i++)
	{
		cin>>at>>bt;
		p[i].at=at;
		p[i].bt=bt;
		p[i].id=i+1;
		p[i].complete=0;
	}
	sort(p,p+n,comp);
	float wt=0,tat=0,t=0;
	
	while(1)
	{
		ind=-1;
		mini=INT_MAX;
		for(i=0;i<n;i++)
		{
			if(t>=p[i].at && p[i].complete!=true)
			{
				if(ind==-1)
					ind=i;
				else if(p[ind].bt > p[i].bt )
					ind=i;
			}
			if(p[i].at<mini && p[i].complete!=true)
				mini=p[i].at;
		}
		if(ind ==-1 && mini ==INT_MAX)
			break;
		if(ind==-1)
		{
			t=mini;
			continue;
		}
		t+=p[ind].bt;
		tat+=t-p[ind].at;
		wt+=t-p[ind].at-p[ind].bt;
		p[ind].complete=1;
	}
	cout<<"Average Waiting Time :"<<wt/n<<endl;
	cout<<"Average TurnAroundTime :"<<tat/n<<endl;
}
