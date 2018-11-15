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
	int n,i,ind,mini,q;
	cout<<"Enter No. of process: ";
	cin>>n;
	process p[n];
	cout<<"Enter arrival time and burst time : \n";
	for(i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].old_bt=p[i].bt;
		p[i].id=i+1;
	}
	sort(p,p+n);
	cout<<"Enter Quantum: ";
	cin>>q;
	float wt=0,tat=0,t=0;
	while(1)
	{
		ind=-1,mini=INT_MAX;
		for(i=0;i<n;i++)
		{
			if(t>=p[i].at && p[i].complete!=true)
			{
				if(ind==-1)
					ind=i;
				else if(p[ind].bt < p[i].bt)
					ind=i;
			}
			if(p[i].complete!=true && p[i].at<mini)
				mini=p[i].at;
		}
		if(ind==-1 && mini==INT_MAX)
			break;
		if(ind==-1)
		{
			t=mini;
			continue;
		}
		if(p[ind].bt <= q)
		{
			p[ind].complete=1;
			t+=p[ind].bt;
			tat+=t-p[ind].at;
			wt+=t-p[ind].at-p[ind].old_bt;
		}
		else
		{
			p[ind].bt-=q;
			t+=q;
		}
	}
	cout<<"Average waiting time: "<<wt/n<<endl;
	cout<<"Average turnAroundTime: "<<tat/n<<endl;
}
