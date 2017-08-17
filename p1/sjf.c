#include<stdio.h>

int main(){

struct process{

int bt, wt, tat, pno;

};

int n, i ,j, tmp, pos;

struct process proc [10];

float avwt=0, avtat=0;

printf("Enter the no of processes\n");

scanf("%d", &n);

printf("Enter burst times\n");

for(i=0; i<n; i++)
	scanf("%d", &proc[i].bt);
	proc[i].pno = i+1;

//sort

for(i=0; i <n; i++){
	pos = i;
	for(j=j+1;  j<n; j++){
		if(proc[j].bt < proc[pos].bt)
			pos = j;
	}
	tmp = proc[pos].bt;
	proc[pos].bt = proc[i].bt;
	proc[i].bt = tmp;

	tmp = proc[pos].pno;
	proc[pos].pno = proc[i].pno;
	proc[i].pno = tmp;
}


for(i=0; i<n; i++){
	proc[i].wt = 0;
	for(j=0; j<i; j++){
		proc[i].wt +=  proc[j].bt;
	}
}

for(i=0; i<n; i++){
	proc[i].tat = proc[i].bt + proc[i].wt;
	avwt +=  proc[i].wt;
	avtat += proc[i].tat;
}

avwt /= n;
avtat /= n;

printf("Process no\t Waiting time\t Turnaround time\n");

for(i=0; i<n; i++)
	printf("%d\t\t %d\t\t %d\n", p[i], proc[i].wt, proc[i].tat);

printf("Avg waiting time =  %f, avg turnaround time = %f\n", avwt, avtat);


}
