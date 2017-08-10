#include<stdio.h>

int main(){

struct process{
int bt, wt, tat, at, rt;
};

int n, i ,j, tq, remain, flag, time;

struct process proc [10];

float avwt=0, avtat=0;


printf("Enter the no of processes\n");
scanf("%d", &n);
remain = n;


printf("Enter burst times\n");
for(i=0; i<n; i++){
	scanf("%d", &proc[i].bt);
	proc[i].rt = proc[i].bt;
}

printf("Enter arrival time\n");
for(i=0; i<n; i++)
        scanf("%d", &proc[i].at);

printf("Enter time quantum\n");
scanf("%d", &tq);

printf("Process\t Waiting time\t Turnaround time\t\n");

//calc waiting time
for(time=0, i=0; remain!= 0;){
	if(proc[i].rt <= tq && proc[i].rt > 0){
		time += proc[i].rt;
		proc[i].rt = 0;
		flag = 1;
	}

	else if(proc[i].rt > 0 ){
		proc[i].rt -= tq;
		time += tq;
	}

	if(proc[i].rt == 0 && flag == 1){
		remain--;
		printf("%d\t\t %d\t\t %d\t \n",i+1, time - proc[i].at - proc[i].bt, time - proc[i].at);
		avwt += time - proc[i].at - proc[i].bt;
		avtat += time - proc[i].at;
		flag = 0;
	}

if(i==n-1)
	i=0;

else if(proc[i+1].at <= time)
	i++;

else
	i =0;
}

avwt /= n;
avtat /= n;

printf("Avg waiting time =  %f, avg turnaround time = %f\n", avwt, avtat); 


}
