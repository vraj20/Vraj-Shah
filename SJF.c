// The arrival time of all the process is zero.
#include<stdio.h>

struct templet
{
    char name[8];
    int pt,tat,wt,remain,flag;
}p[20],temp;

void sjf()
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
        p[i].remain=p[i].pt;
        p[i].flag=0;
    }
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            if(p[i].pt<p[j].pt)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    printf("\n\t Grant Chart : \n\t\t");
    
    i=0;
    scnt=p[i].pt;
    while(1)
    {
        if(p[i].flag==0)
        {
            p[i].remain--;
            scnt++;
            if(p[i].remain>0)
            {
                for(j=0;j<no;j++)
                {
                    if(p[j].pt<=scnt && p[j].flag==0)
                    {
                        if(p[i].remain>p[j].remain)
                        {
                            i=j;
                        }
                    }
                }
            }
            else
            {
                p[i].wt=scnt-p[i].pt;
                p[i].tat=scnt;
                p[i].flag=1;
                fcnt++;
                if(fcnt==no)
                    break;
                if(i<no-1)
                    i++;
                else
                    i=0;
                for(j=i;j>0;j--)
                        if(p[j].remain < p[i].remain && p[j].flag==0)
                            i=j;
            }
        }
        else
            i++;
    }
    
    fcnt=0,scnt=0;
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
	sjf();
	return 0;    
}

