#include<stdio.h>
void main ()
{

   int m, n,i,c,j;
  int allo[m][n];
  int claim[m][n];
  int need[m][n];
  int resource[m];
  int cnt, process_cnt;
  int checked[20] = { 0 };

 
  printf("\n enter the number of resources (row)");
  scanf("%d", &m);
  printf("\n enter the number of processes (column)");
  scanf("%d", &n);
  printf ("\n Enter the values of allocated matrix");

  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &allo[i][j]);
	}
    }
 printf("\n");
  for (i = 0; i < m; i++)
  {
	  printf ("%c\t", (i + 97));
  }
 printf("\n");
   for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  printf ("%d\t ", allo[i][j]);
	}
    printf("\n");
    }


  printf ("\n Enter values of total requirement matrix");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &claim[i][j]);
	}
    }
 printf("\n");
  for (i = 0; i < m; i++)
  {
	  printf ("%c\t", (i + 97));
  }
  printf("\n");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  printf("%d\t", claim[i][j]);
	}
      printf("\n ");
    }


  printf ("\n Enter 5 values of available vector:");
  for (j = 0; j < m; j++)
    {
      scanf ("%d", &resource[j]);
    }

   for (i=0;i<5;i++)
     {
       for (j=0;j<5;j++)
         {
		need[i][j]=claim[i][j]-allo[i][j];
         }
      }
  printf ("The process flow...\n");

 process_cnt=n;

  while (process_cnt >= 1)
    {
      for (i = 0; i < m; i++)
	{
	  cnt = 0;
	  if (checked[i] != 1)
	    {
	      for (j = 0; j < n; j++)
		{
		  if (need[i][j] <= resource[j])
		    {
		      cnt++;
		    }
		}
	    }
	  if (cnt == n)
	    {
	      process_cnt--;
	      checked[i] = 1;
	      c = i + 1;
	      printf ("\nProcess %d", c);
	      for (j = 0; j < m; j++)
		{
		  resource[j] = resource[j] + allo[i][j];
		}
	    }
	}
    }
}
