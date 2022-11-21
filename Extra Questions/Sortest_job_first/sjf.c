/*
	Write a C program to demonstrate Sortest Job First (SJF) Scheduling.
	
	In SJF scheduling, the process with the lowest burst time, among the list of available processes in the ready queue, is going to be scheduled next.However, it is very difficult to predict the burst time needed for a process hence this algorithm is very difficult to implement in the system. Moreover it is the non premptive version of SRTF algorithm.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct process
{
	int at,bt,st,ct,tat,wt,rt,pid,is_completed;
}st;
int comp(const void *a, const void *b)
{
	st *p1=(st*)a;
	st *p2=(st*)b;
	return p1->at > p2->at;
}
void averageTime(st *arr,int n,float total_it)
{
	float total_wt=0,total_tat=0,total_rt=0;
	printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
	{
		total_wt+=arr[i].wt;
		total_tat+=arr[i].tat;
		total_rt+=arr[i].rt;
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
	}
	printf("\nAverage Waiting time %f\n",total_wt/(float)n);
	printf("Average Turn Around time %f\n",total_tat/(float)n);
	printf("Average Response time %f\n",total_rt/(float)n);
	printf("CPU utilization %f\n",((arr[n-1].ct-total_it)/(float)arr[n-1].ct)*100);
	printf("Throughput %f\n",(float)n/(arr[n-1].ct-arr[0].at));
}
int main()
{
	printf("\nName - Vipul Chauhan\nSection - A\nStudent id - 20011016\n\n");
	int n;
	printf("Enter the Number of elements : ");
	scanf("%d",&n);
	
	st arr[n];
	
	for(int i=0;i<n;i++)
	{	
		printf("For process %d Enter Arrival time and Burst time respectively : ",i+1);
		arr[i].pid=i+1;
		scanf("%d%d",&arr[i].at,&arr[i].bt);
		arr[i].is_completed=0;
	}
	int current_time=0,completed=0,total_it=0,prev=0;
	qsort(arr,n,sizeof(st),comp);
	while(completed!=n)
	{
		int idx=-1,mn=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(arr[i].at<=current_time && arr[i].is_completed==0)
			{
				if(arr[i].bt<mn)
				{
					mn=arr[i].bt;
					idx=i;
				}
				if(arr[i].bt==mn)
				{
					if(arr[i].at<arr[idx].at)
					{
						mn=arr[i].bt;
						idx=i;
					}
				}
			}
		}
		if(idx!=-1)
		{
			arr[idx].st=current_time;		//start time
			arr[idx].ct=arr[idx].st+arr[idx].bt;				//completion time
			arr[idx].tat=arr[idx].ct-arr[idx].at;	//turn around time
			arr[idx].wt=arr[idx].tat-arr[idx].bt;	//waiting time
			arr[idx].rt=arr[idx].st-arr[idx].at;	//response time
			total_it+=arr[idx].st-prev;
			current_time++;
			arr[idx].is_completed=1;
			completed++;
			current_time=arr[idx].ct;
			prev=current_time;
		}
		else
		{
			current_time++;
		}
	}
	averageTime(arr,n,total_it);
}