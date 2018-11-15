#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id,at,bt,old_bt;
	bool complete;
};

bool comp(process &a,process &b)
{
	return (a.at<b.at);
}

int main()
{
	int n,i,q,ind,mini;
	cout<<"Enter No. of process : ";
	cin>>n;
	process p[n];
	cout<<"Enter Arrival time and Burst time for processes:\n ";
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].old_bt=p[i].bt;
		p[i].complete=0;
		p[i].id=i+1;
	}
	sort(p,p+n,com);
	float wt=0,tat=0,t=0;
	cout<<"Enter Quantum: ";
	cin>>q;
	while(1)
	{
		ind=-1,mini=INT_MAX;
		for(i=0;i<n;i++)
		{
			if(t>=p[i].at && p[i].complete!=true)
			{
				if(ind==-1)
					ind=i;
				else if(p[ind].bt > p[i].bt)
					ind=i;
			}
			if(p[i].complete!=true && mini>p[i].at)
				mini=p[i].at;
		}
		if(ind==-1 && mini == INT_MAX)
			break;
		
		if(p[ind].bt<=q)
		{
			t+=p[ind].bt;
			tat+=t-p[ind].at;
			wt+=t-p[ind].at-p[ind].old_bt;
			p[ind].complete=1;	
		}
		else
		{
			t+=q;
			p[ind].bt-=q;
		}
	}
	cout<<"Average Waiting Time: "<<wt/n<<endl;
	cout<<"Average TurnAroundTime: "<<tat/n<<endl;
}
