#include<bits/stdc++.h>
using namespace std;

struct process
{
	int at,bt,id,old_bt;
	bool complete;
};

bool comp(process &a,process &b)
{
	return (a.at<b.at);
}

int main()
{
	int n,i,q;
	cout<<"Enter No. of process: ";
	cin>>n;
	process p[n];
	cout<<"Enter Arrival and Dept. time of process:\n";
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].old_bt=p[i].bt;
		p[i].id=i+1;
		p[i].complete=0;
	}
	sort(p,p+n,comp);
	cout<<"Enter Quantum: ";
	cin>>q;
	queue<process> rr;
		
	float wt=0,tat=0,t=0;
	t=p[0].at;
	p[0].complete=1;
	rr.push(p[0]);
	
	while(!rr.empty())
	{
		process temp=rr.front();
		rr.pop();
		if(temp.bt<=q)
		{
			t+=temp.bt;
			temp.bt=0;
			tat+=t-temp.at;
			wt+=t-temp.at-temp.old_bt;
		}
		else
		{
			t+=q;
			temp.bt-=q;
		}
		for(i=0;i<n;i++)
		{
			if(p[i].complete!=true && p[i].at<=t)
			{
				rr.push(p[i]);
				p[i].complete=1;
			}
		}
		if(temp.bt!=0)
			rr.push(temp);
	}
	cout<<"Average Waiting Time: "<<wt/n<<endl;
	cout<<"Average TurnAroundTime: "<<tat/n<<endl;
}
