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
    int i,total_burst_time=0,j,k;
    int n;
    cout<<"Enter the Number of processes: ";
    cin>>n;
    int prc[n],arr[n],bt[n],com[20],tr[n],wt[n];
    int process_queue[n],queue_index=0,processed_time=0,queue_index_min=0;
    double avg_tr,avg_wt;

    rep(n)
    {
        printString("Enter Arrival Time (AT) and Burst Time (BT) for process P");
        cout<<i+1<<" : "<<endl;
        printString("AT : ");cin>>arr[i];lf;
        prc[i]=i+1;
        printString("BT : ");cin>>bt[i];lf;
    }

   //sort by arrival time;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]>arr[j]){
            swap(arr[i],arr[j]);
            swap(prc[i],prc[j]);
            swap(bt[i],bt[j]);
            }
        }
    }
    queue_index=0;processed_time+=bt[queue_index];
    //sort by burst time;
    for(i=0;i<n;i++)
    {
        
        
        queue_index++;
        queue_index_min=queue_index;
        while(arr[queue_index]<=processed_time and queue_index<n)
        {
            queue_index++;
        }
        cout<<"queue_index "<<queue_index<<endl;
        for(k=queue_index_min;k<queue_index;k++)
        {
            for(j=k;j<queue_index;j++)
            {
                if(bt[j]==bt[k])continue;
                else if(bt[k]>bt[j]){
                swap(prc[k],prc[j]);
                swap(bt[k],bt[j]);
                swap(arr[k],arr[j]);
                }

            }
            
        }
        for(j=queue_index_min;j<=queue_index;j++)
        {
            processed_time+=bt[i];
        }
        
    i+=queue_index;
    }

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
    printString("Process \t Arrival_Time \t Burst_Time \t Completion_Time \t Turnaround_Time \t Waiting_Time:\n");
    rep(n)
    {
        cout<<"  P"<<prc[i]<<" \t \t "<<arr[i]<<" \t \t "<<bt[i]<<" \t \t "<<com[i]<<" \t \t\t "<<tr[i]<<" \t \t\t "<<wt[i]<<endl;
    }
    cout<<"Average Turnaround time : "<<setprecision(2)<<avg_tr<<endl;
    cout<<"Average waiting time : "<<setprecision(2)<<avg_wt<<endl;

    return 0;

}
