#include<bits/stdc++.h>
using namespace std;

struct process
{
        int id;
        int at;
        int bt;
};

bool comp(process &a,process &b)
{
        return (a.at<b.at);
}

int main()
{
        cout<<"Enter No. of Process:";
        int n,i,at,bt,id;
        cin>>n;
        process p[n];
        cout<<"enter arrival time and burst time:\n";
        for(i=0;i<n;i++)
        {
                cin>>at>>bt;
                p[i].id=i+1;
                p[i].at=at;
                p[i].bt=bt;
        }
        
        sort(p,p+n,comp);
        float tat=0,wt=0,t=0;
        for(i=0;i<n;i++)
        {
                if(t<p[i].at)
                	t=p[i].at;
                t+=p[i].bt;
                tat+=t-p[i].at;
                wt+=t-p[i].at-p[i].bt;
        }
        cout<<wt/n<<" "<<tat/n<<endl;
}
