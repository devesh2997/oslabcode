#include<bits/stdc++.h>
using namespace std;
#define pb push_back

class Process
{
	public:
	int id,at,bt,ct,wt,tat,rt,obt;
	Process(int a,int b,int c)
	{
		id=a;at=b;bt=c;rt=-1;obt=c;
	}
};

bool fsort(Process a, Process b)
{
	if(a.at==b.at)
		{if(a.bt==b.bt)
			return a.id <b.id;
		else
			return (a.bt>=b.bt);
		}
	return (a.at<=b.at);
}

void LRTF(vector<Process> &ar)
{
	cout<<"For LRTF scheduling :\n";
	int n =ar.size(),gant=0,dct=0,tatavg=0,wtavg=0,rtavg=0;
	vector<bool> done(n,false);
	while(dct<n)
	{	
		int burst=INT_MIN,i=-1;
		for(int j(0);j<n;j++)
		{
			if(gant>=ar[j].at && done[j]==false && (burst<ar[j].bt || burst==ar[j].bt && ar[i].id>ar[j].id))
			{
				i=j;
				burst=ar[j].bt;
			}
		}
		if(i==-1)
		{
			sort(ar.begin(),ar.end(),fsort);
			for(int j(0);j<n;j++)
			{
				if(done[j]==false)
				{
					i=j;
					gant=ar[i].at;
					break;
				}
			}
		}
		
		if(i==-1)break;
		if(ar[i].rt==-1)
		{
			ar[i].rt=gant;rtavg+=ar[i].rt;
		}
		ar[i].bt--;
		gant++;
		if(ar[i].bt==0 && done[i]==false)
		{
			cout<<ar[i].id<<" completed at ct = "<<gant<<endl;
			done[i]=true;
			ar[i].ct=gant;
			ar[i].tat=ar[i].ct-ar[i].at;
			ar[i].wt=ar[i].tat-ar[i].obt;
			tatavg+=ar[i].tat;
			wtavg+=ar[i].wt;
			dct++;
		}
	}
	cout<<"Average TAT = "<<(1.0*tatavg)/n<<"\t Average WT = "<<(1.0*wtavg)/n<<"\t Average RT = "<<(1.0*rtavg)/n<<endl;	
}

void RR(vector<Process> &ar,int tq)
{
	cout<<"For Round-Robin scheduling :\n";
	int n =ar.size(),gant=0,dct=0,tatavg=0,wtavg=0,rtavg=0;
	vector<bool> done(n,false);
	queue<Process> q;
	while(dct<n)
	{
		int burst=INT_MIN,i=-1;
		if(q.empty())
		{
			for(int j(0);j<n;i++)
			{
				if(done[j]==false)
				{					
					i=j;
					
					gant=ar[i].at;
					break;				
				}
			}
		
		if(i==-1)
			break;
		if(ar[i].rt==-1)
		{
			ar[i].rt=gant;rtavg+=ar[i].rt;
		}
		
		ar[i].bt=max(0,ar[i].bt-tq);
		
		}
		
		
	}
}

// i/p --- 6 1 5 5 2 4 6 3 3 7 4 1 9 5 2 2 6 6 2
int main()
{
	int n;
	cout<<"Enter the number of processes\n";
	cin>>n;
	vector<Process> stuff;
	cout<<" For each, enter process ID, arrival time and burst time resp.\n";
	for(int i(0);i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		Process p(a,b,c);
		stuff.pb(p);
	}
	vector<Process> lrtf=stuff;
	sort(lrtf.begin(),lrtf.end(),fsort);
	LRTF(lrtf);
	vector<Process> rr = stuff;
	cout<<"Enter time quantum for the processor\n";
	int tq;
	cin>>tq;
	
	sort(rr.begin(),rr.end(),fsort);
	RR(rr,tq);
}
