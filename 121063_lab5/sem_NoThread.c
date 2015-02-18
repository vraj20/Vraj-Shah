#include<stdio.h>
#include<stdlib.h>
int goods;
int queue[2]={0};
int semaphore=1;
int semsignal();
void Shopkeeper();
void cust1();
void cust2();
int semwait();
void enqueue(int);
void dequeue();
void display();

void main()
{
	int ch;
	while(1)
	{
		printf("1.Shopkeeper\n");
		printf("2.cust1\n");
		printf("3.cust2\n");
		printf("4.Queue Content\n");
		printf("0. for Exit\n");
		printf("Enter Your Choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				Shopkeeper();
				break;
			case 2:
				cust1();
				break;
			case 3:
				cust2();
				break;
			case 4:
				display();
		}
	
	}	
}
int semwait()
{
return semaphore--;
}

int semsignal()
{
return semaphore++;
}
void enqueue(int b)
{
	int q1=0,i;
	for(i=0;i<2;i++)
	{
		if(queue[i]==0)
		{
			q1=1;
			queue[i]=b;
			break;
		}
	}		
}
void dequeue()
{
	queue[0]=queue[1];
	queue[1]=0;	
}
void Shopkeeper()
{
	if(goods==semwait())
	{
		goods=1;
	}
	else if(goods==1)
	{
		printf("\nList Overflowed...");
	} 
	semsignal();
}

void cust1()
{
	if(goods!=semwait())
	{
		if(queue[0]==0 || queue[0]==1 )
		{
			goods=0;
			dequeue();
		}
		else
			enqueue(1);
		
	}
	else
		enqueue(1);
	semsignal();
}

void cust2()
{
	if(goods!=semwait())
	{
		if(queue[0]==0 || queue[0]==2 )
		{
			goods=0;
			dequeue();
		}
		else
			enqueue(2);
	}	
	else
		enqueue(2);	
	semsignal();
}

void display()
{
	int i;
	for(i=0;i<2;i++)
	{
		printf("\n");
		if(queue[i]==1)
			printf("%d. cust1\n", i+1);
		else if(queue[i]==2)
			printf("%d. cust2\n", i+1);	
		else
			printf("%d. Empty!\n", i+1);
	}
}









