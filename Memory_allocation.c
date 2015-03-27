// Memory allocation best next and first fit 
// Taking 100 process and 100 blocks initially
#include<stdio.h>
int main ()
{
  int pro[100], pro_num, block[100], blo_num, prt1[100], prt2[100],
    alloc[100], flag[100], cnt1, cnt2;
  printf ("\nNumber of proesss: ");
  scanf ("%d", &pro_num);
  printf ("\nNumber of blocks: ");
  scanf ("%d", &blo_num);
  printf ("\n");
  for (cnt1 = 0; cnt1 < pro_num; cnt1++)
    {
      printf ("\nSize of process %d: ", cnt1);
      scanf ("%d", &pro[cnt1]);
    }
  for (cnt2 = 0; cnt2 < blo_num; cnt2++)
    {
      printf ("\nSize of block %d: ", cnt2);
      scanf ("%d", &block[cnt2]);
      prt1[cnt2] = block[cnt2];
      prt2[cnt2] = block[cnt2];
    }
  if (pro_num <= blo_num)
    {
      printf ("\n\nFirst Fit");
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  for (cnt2 = 0; cnt2 < blo_num; cnt2++)
	    {
	      if (pro[cnt1] <= block[cnt2])
		{
		  alloc[cnt2] = pro[cnt1];
		  printf
		    ("\nprocess %d of size %d is allocated in block:%d of size:%d",
		     cnt1, pro[cnt1], cnt2, block[cnt2]);
		  flag[cnt1] = 0, block[cnt2] = 0;
		  break;
		}
	      else
		flag[cnt1] = 1;
	    }
	}
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  if (flag[cnt1] != 0)
	    printf ("\n\nprocess %d of size %d is not allocated", cnt1,
		    pro[cnt1]);
	}
      printf ("\n\nBest Fit");
      for (cnt1 = 0; cnt1 < blo_num; cnt1++)
	{
	  for (cnt2 = cnt1 + 1; cnt2 < blo_num; cnt2++)
	    {
	      if (prt1[cnt1] > prt1[cnt2])
		{
		  int temp = prt1[cnt1];
		  prt1[cnt1] = prt1[cnt2];
		  prt1[cnt2] = temp;
		}
	    }
	}
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  for (cnt2 = 0; cnt2 < blo_num; cnt2++)
	    {
	      if (pro[cnt1] <= prt1[cnt2])
		{
		  alloc[cnt2] = pro[cnt1];
		  printf
		    ("\nprocess %d of size %d is allocated in block %d of size %d",
		     cnt1, pro[cnt1], cnt2, prt1[cnt2]);
		  flag[cnt1] = 0, prt1[cnt2] = 0;
		  break;
		}
	      else
		flag[cnt1] = 1;
	    }
	}
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  if (flag[cnt1] != 0)
	    printf ("\nprocess %d of size %d is not allocated", cnt1,
		    pro[cnt1]);
	}
      printf ("\n\nWorst Fit");
      for (cnt1 = 0; cnt1 < blo_num; cnt1++)
	{
	  for (cnt2 = cnt1 + 1; cnt2 < blo_num; cnt2++)
	    {
	      if (prt2[cnt1] < prt2[cnt2])
		{
		  int temp = prt2[cnt1];
		  prt2[cnt1] = prt2[cnt2];
		  prt2[cnt2] = temp;
		}
	    }
	}
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  for (cnt2 = 0; cnt2 < blo_num; cnt2++)
	    {
	      if (pro[cnt1] <= prt2[cnt2])
		{
		  alloc[cnt2] = pro[cnt1];
		  printf
		    ("\nprocess %d of size %d is allocated in block %d of size %d",
		     cnt1, pro[cnt1], cnt2, prt2[cnt2]);
		  flag[cnt1] = 0;
		  prt2[cnt2] = 0;
		  break;
		}
	      else
		flag[cnt1] = 1;
	    }
	}
      for (cnt1 = 0; cnt1 < pro_num; cnt1++)
	{
	  if (flag[cnt1] != 0)
	    printf ("\nprocess %d of size %d is not allocated", cnt1,
		    pro[cnt1]);
	}
    }
  else
    {
      printf ("\nImproper input. Re-enter.");
    }
  printf ("\n\n");
  return 0;
}
