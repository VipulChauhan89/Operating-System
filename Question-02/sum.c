/*
	Write a C program in which parent process computes the sum of even Numbers and child process computes the sum of odd number stored in an array using a fork().
	First the child process should print its answer i.e sum of odd number then the parent process should print its answer i.e the sum of even number.
	
	PID is the Process Identification Number on Linux/Unix OS. In the child process, it returns 0
*/
#include<stdio.h> 
#include<unistd.h>
int main() 
{
	printf("\nName - Vipul Chauhan\nSection - A\nStudent id - 20011016\n\n");
	int even_sum=0,odd_sum=0,n;
	printf("Enter the size of an array : "); 
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d numbers : ",n); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int pid=fork(); 
	if(pid==0)
	{
		for(int i=0;i<n;i++) 
		{
			if(arr[i]%2 != 0)
				odd_sum+=arr[i];
		}
		printf("Sum of Odd Numbers = %d\n", odd_sum);
 	}
 	else
 	{
 		for(int i=0;i<n;i++) 
		{
			if(arr[i]%2 == 0) 
				even_sum+=arr[i];
		}
		printf("Sum of Even Numbers = %d\n", even_sum);
 	}
	return 0; 
}