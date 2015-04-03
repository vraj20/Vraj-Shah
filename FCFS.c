// Assuming the arrival time of all the process is zero.
#include<stdio.h>

struct templet
{
    char name[8];
    int st,pt,ft,tat,wt;
}p[20],temp;

void fcfs()
{
    int no,i,j,fcnt=0,scnt=0;
    printf("\n\tEnter no of processes : ");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        printf("\n\tEnter process name : ");
        scanf("%s",p[i].name);
        printf("\n\tEnter Burst time : ");
        scanf("%d",&p[i].pt);
    }
    printf("\n\t Grant Chart : \n\t\t");
    for(i=0;i<no;i++)
    {
        p[i].st=fcnt;
        fcnt+=p[i].pt;
        p[i].wt=fcnt-p[i].pt;
        p[i].tat=fcnt;
        printf("%s -->",p[i].name);
    }
    printf("Finish");
    fcnt=0;
    printf("\n\tProcess \t burst time \t waiting time \t turn around time");
    for(i=0;i<no;i++)
    {
        printf("\n\t%s\t\t\t%d\t\t%d\t \t%d",p[i].name,p[i].pt,p[i].wt,p[i].tat);
        fcnt+=p[i].wt;
        scnt+=p[i].tat;
    }
    printf("\n\n\t\t\t\tAverage : \t %d\t   \t%d",fcnt/no,scnt/no);
}

int main()
{
	printf("\n ------------------FCFS POLICY-------------------------");
    fcfs();
    return 0;
}
