
#include<stdio.h>
void main()
{
 int pr,i, timelapse = 0, true = 1, small_sack_time = 200, index = -1, count = 0;
 int exec[pr],start[pr],deadline[pr], flag[pr];
 printf("\nEnter the no of processes:");
 scanf("%d",&pr);
 
 for(i=0;i<pr;i++)
	flag[pr] = 0;
  
 for(i=0;i<pr;i++)
 {
 	printf("\nEnter absolute start time, \n exec time  \n absolute deadline for process %d:",i+1);
 	scanf("%d %d %d", &start[i], &exec[i], &deadline[i]);
 }
	
 while(true)
 {
	for(i = 0; i< pr;i++)
	{
	
		if(start[i] == timelapse || exec[index] == 0)
		{
			if(flag[i] != 1)
			{
				if((deadline[i] - timelapse)-exec[i] < small_sack_time)
				{
					small_sack_time = (deadline[i] - timelapse - exec[i]];
					index = i;
				}
			}
		}
		
		
	}
	if(exec[index] == 0)
			{
				small_sack_time = 200;
				index=-1;
			}
	if(index!=-1)
	{
		printf("\n from time quantum %d to %d, process %d", timelapse, timelapse+1, index+1);
		exec[index]--;
		
		if(exec[index] == 0)
		{
			flag[index]=1;
			count++;
		}
	}
	if(count == pr)
		true = 0;
	
 timelapse++;
 }
