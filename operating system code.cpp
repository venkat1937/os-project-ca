#include<stdio.h> 
#include<conio.h>

void rr(int N,int remaining_time[30],int current_time,int arT[15], int brst_time[25]);

main() 
{
	int pn,j,N,CurT,rp,indicator,time_quantum,wait,tut,arT[15],brst_time[25],remaining_time[30];
	indicator = 0;
	wait = 0;
	tut = 0;
        int f=1;
	printf("Enter number of processes "); 
	scanf("%d",&N);
	rp = N;
	
	printf("\nEnter the arrival time and burst time of the processes\n");
	for(pn = 0;pn < N;pn++) 
	{
		printf("\nProcess P%d\n",pn+1);
		printf(" please enter the Arrival time  for the process= "); 
		scanf("%d",&arT[pn]);
		printf("please enter the Burst time for the process = "); 
		scanf("%d",&brst_time[pn]); 
		remaining_time[pn]=brst_time[pn]; 
	} 
	printf("time quantum :\n"); 
	time_quantum=3;
	CurT=0;
	for(pn=0;rp!=0;) 
	{
		if(remaining_time[pn]<=time_quantum && remaining_time[pn]>0)
		{ 
			CurT+=remaining_time[pn]; 
			remaining_time[pn]=0; 
			indicator=1; 
			
		} 
		else if(remaining_time[pn]>0)
		{ 
			remaining_time[pn]-=time_quantum; 
			CurT+=time_quantum; 
		} 
		if(remaining_time[pn]==0 && indicator==1)			
		{ printf("%d",pn);
			rp--;				
			printf("P %d",pn+1); 
			printf("\t\t\t%d",CurT-arT[pn]);
			printf("\t\t\t%d\n",CurT-brst_time[pn]-arT[pn]);
			wait+=CurT-arT[pn]-brst_time[pn]; 
			tut+=CurT-arT[pn]; 
			indicator=0; 
                       
		} 
		if(pn==N-1){
			f++;
			if(f==2){
				pn=0;
				time_quantum=6;
				
				printf("The time quantum used for \n");
			}
			else{
				break;
			}
		}
		else if(CurT >= arT[pn+1]){
			pn++;
		}
		else{
			pn=0;
		}
	}
	
	rr(N,remaining_time,CurT,arT,brst_time);
	return 0;
}


void rr(int N,int remaining_time[30],int current_time,int arT[15], int brst_time[25]){
	
	float average_waiting_time,average_turn_around_time;
    int i,j,n=N,temp,burst_time[20],pn[20],waiting_time[20],tut_t[20],total=0,loc;
    
    printf("least burst time\n");
    
    for(i=0;i<n;i++)
    {
        burst_time[i]=remaining_time[i];
        waiting_time[i]=current_time-arT[i]-burst_time[i];
		pn[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[loc]){
            	loc=j;
            }
        }
        temp=burst_time[i];
        burst_time[i]=burst_time[loc];
        burst_time[loc]=temp;
        temp=pn[i];
        pn[i]=pn[loc];
        pn[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	waiting_time[i]+=burst_time[j];
        }
        total+=waiting_time[i];
    }
 
    average_waiting_time=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tut_t[i]=burst_time[i]+waiting_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",pn[i],burst_time[i],waiting_time[i],tut_t[i]);
    }
    average_turn_around_time=(float)total/n;
    printf("\n\nAverage waiting time = %f",average_waiting_time);
    printf("\n Average turn around time = %f\n",average_turn_around_time);
    
	
}



