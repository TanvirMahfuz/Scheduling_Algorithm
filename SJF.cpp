#include<iostream>
#include<iomanip>
#define rep(n) for(i=0;i<n;i++)
#define lf cout<<endl
using namespace std;
int farr(int arr[],int n);
int minArrval(int arr[],int n);
int minBurstIndex(int bt[],int n,int processed_time,int arr[]);
void printString(string s)
{
    cout<<s;
}
int main()
{
   int n,i,j;
   printString("Enter the number of Processes:\n");
   cin>>n;
   int arr[n],bt[n],prc[n],btcp[n];
   rep(n){
    printString("enter Arrival Time,Burst Time and Priority(higher the number higher the priority order):\n");
    cout<<"Arrival time: ";cin>>arr[i];
    cout<<"Burst time: ";cin>>bt[i];
    btcp[i]=bt[i];
    prc[i]=i+1;
    }
int process_queue[n],process_queue_index=0,processed_time=0;
int arr_time_index=farr(arr,n);
int  min_burst,min_burst_index=0;


process_queue[process_queue_index]=arr_time_index;
processed_time+=btcp[process_queue[process_queue_index]];
btcp[process_queue[process_queue_index]]=100000000;
cout<<"arrtimeindes: "<<arr_time_index<<endl;
cout<<"bt0 "<<bt[process_queue[process_queue_index]]<<endl;
cout<<"process_queue[process_queue_index] "<<bt[process_queue[process_queue_index]]<<endl;

for(process_queue_index=1;process_queue_index<n;process_queue_index++)
{
    min_burst_index=minBurstIndex(btcp,n,processed_time,arr);
    process_queue[process_queue_index]=min_burst_index;
    processed_time+=bt[process_queue[process_queue_index]];
    btcp[min_burst_index]=100000000;
    
}

int total_burst_time=0,com[20],tr[n],wt[n];
double avg_tr,avg_wt;

    for(j=0;j<n;j++)
    {
        i=process_queue[j];
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
    for(j=0;j<n ;j++)
    {
        i=process_queue[j];
        cout<<"  P"<<prc[i]<<" \t \t "<<arr[i]<<" \t \t "<<bt[i]<<" \t \t "<<com[i]<<" \t \t\t "<<tr[i]<<" \t \t\t "<<wt[i]<<endl;
    }
    cout<<"Average Turnaround time : "<<setprecision(2)<<avg_tr<<endl;
    cout<<"Average waiting time : "<<setprecision(2)<<avg_wt<<endl;


    return 0;

}
int farr(int arr[],int n)
{
    int i;
    int minarr=1000000000;
    int arr_time_index=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]<minarr)
        {
            minarr=arr[i];
            arr_time_index=i;
            
        }
    }
    return arr_time_index;
}
int minArrval(int arr[],int n){
    sort(arr,arr+n);
    return arr[0];
    
}
int minBurstIndex(int bt[],int n,int processed_time,int arr[])
{
    int i,min=100000000,j=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>processed_time)break;
        else 
        {
            if(bt[i]<min)
            {
                j=i;
                min=bt[i];
            }
        }
    }
    return j;
}
