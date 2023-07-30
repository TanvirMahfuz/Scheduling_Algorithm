#include<iostream>
#include<iomanip>
#define rep(n) for(i=0;i<n;i++)
#define lf cout<<endl
using namespace std;
void printString(string s)
{
    cout<<s;
}
int main()
{
    int i,total_burst_time,j,k;
    int n;
    cout<<"Enter the Number of processes: ";
    cin>>n;
    int prc[n],arr[n],bt[n],com[20],tr[n],wt[n];
    double avg_tr,avg_wt;
    rep(n)
    {
        printString("Enter Arrival Time (AT) and Burst Time (BT) for process P");
        cout<<i+1<<" : "<<endl;
        prc[i]=i+1;
        printString("AT : ");cin>>arr[i];lf;
        printString("BT : ");cin>>bt[i];lf;
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]>arr[j] or (arr[i]==arr[j] and prc[i]>prc[j])){
            swap(arr[i],arr[j]);
            swap(prc[i],prc[j]);
            swap(bt[i],bt[j]);
            }
        }
    }
    total_burst_time=arr[0];
    rep(n)
    {
        total_burst_time+=bt[i];
        com[i]=total_burst_time;
        tr[i]=com[i]-arr[i];
        wt[i]=tr[i]-bt[i];
        avg_tr+=tr[i];
        avg_wt+=wt[i];
    }

    avg_tr=(double)avg_tr/(double)n;
    avg_wt=(double)avg_wt/(double)n;
    printString("Process\t Arrival_Time\t Burst_Time\t Completion_Time\t Turnaround_Time\t Waiting_Time:\n");
    rep(n)
    {
        cout<<"  P"<<i<<"\t\t"<<arr[i]<<"\t\t"<<bt[i]<<"\t\t"<<com[i]<<"\t\t\t"<<tr[i]<<"\t\t\t"<<wt[i]<<endl;
    }
    cout<<"Average Turnaround time : "<<setprecision(2)<<avg_tr<<endl;
    cout<<"Average waiting time : "<<setprecision(2)<<avg_wt<<endl;

    return 0;

}#include<iostream>
#include<iomanip>
#define rep(n) for(i=0;i<n;i++)
#define lf cout<<endl
using namespace std;
void printString(string s)
{
    cout<<s;
}
int main()
{
    int i,total_burst_time,j,k;
    int n;
    cout<<"Enter the Number of processes: ";
    cin>>n;
    int prc[n],arr[n],bt[n],com[20],tr[n],wt[n];
    double avg_tr,avg_wt;
    rep(n)
    {
        printString("Enter Arrival Time (AT) and Burst Time (BT) for process P");
        cout<<i+1<<" : "<<endl;
        prc[i]=i+1;
        printString("AT : ");cin>>arr[i];lf;
        printString("BT : ");cin>>bt[i];lf;
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]>arr[j] or (arr[i]==arr[j] and prc[i]>prc[j])){
            swap(arr[i],arr[j]);
            swap(prc[i],prc[j]);
            swap(bt[i],bt[j]);
            }
        }
    }
    total_burst_time=arr[0];
    rep(n)
    {
        total_burst_time+=bt[i];
        com[i]=total_burst_time;
        tr[i]=com[i]-arr[i];
        wt[i]=tr[i]-bt[i];
        avg_tr+=tr[i];
        avg_wt+=wt[i];
    }

    avg_tr=(double)avg_tr/(double)n;
    avg_wt=(double)avg_wt/(double)n;
    printString("Process\t Arrival_Time\t Burst_Time\t Completion_Time\t Turnaround_Time\t Waiting_Time:\n");
    rep(n)
    {
        cout<<"  P"<<i<<"\t\t"<<arr[i]<<"\t\t"<<bt[i]<<"\t\t"<<com[i]<<"\t\t\t"<<tr[i]<<"\t\t\t"<<wt[i]<<endl;
    }
    cout<<"Average Turnaround time : "<<setprecision(2)<<avg_tr<<endl;
    cout<<"Average waiting time : "<<setprecision(2)<<avg_wt<<endl;

    return 0;

}
