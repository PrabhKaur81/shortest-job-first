
#include<stdio.h>
#include<conio.h>
int main()
{

 FILE* file = fopen ("CPU_BURST.txt", "r");
  int i = 0;
  int j = 0;
  int arr[100];
  //initializing arr with -1 as bust time cannot be negative
  memset( arr,-1, 100*sizeof(int));

  while (!feof(file))
    {
      fscanf (file, "%d", &i);
        //checking if bust time is postive
        if(i>0)
        {
        arr[j]=i;

        j++;


        }

    }


  fclose (file);
   int bt[20],p[20],wt[20],tat[20],n,total=0,pos,temp;
    float avg_wt,avg_tat;

    n=j;
    for(i=0;i<n;i++)
    {
         //recreating array
        bt[i]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }


 for(i=0;i<n;i++)
    {   //selection sort used in bt
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}




