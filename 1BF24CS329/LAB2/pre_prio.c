#include<stdio.h>
int main(){
int n;
printf("enter the num of processes\n");
scanf("%d",&n);
int p[n+1];
for(int i=1;i<=n;i++){
    p[i]=i;
}

int at[n+1],bt[n+1],pr[n+1],rt[n+1];
for(int i=1;i<=n;i++){
    printf("enter arrival time for process %d ",i);
    scanf("%d",&at[i]);
}
for(int i=1;i<=n;i++){
    printf("enter burst time for process %d ",i);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
}
for(int i=1;i<=n;i++){
    printf("enter priority for process %d ",i);
    scanf("%d",&pr[i]);
}
int ct[n+1],tat[n+1],wt[n+1];
int time=0,completed=0;
while(completed<n){
    int min_pr=9999;
    int index=-1;
    for(int i=1;i<=n;i++){
        if(at[i]<=time &&  rt[i]>0 &&pr[i]<min_pr){
            min_pr=pr[i];
            index=i;
        }}
        if(index==-1){
            time++;
            continue;
        }
        rt[index]--;
        time++;
        if(rt[index]==0){
            ct[index]=time;
            completed++;
        }
    }


printf("1BF24CS329 VALLAPUREDDY VAISHNAVI\n");
int avgtat=0,avgwt=0;
for(int i=1;i<=n;i++){
    tat[i]=ct[i]-at[i];
    avgtat=avgtat+tat[i];
    wt[i]=tat[i]-bt[i];
    avgwt=avgwt+wt[i];
}
printf("process\tat\tbt\tpr\tct\ttat\twt\n");

for(int i=1;i<=n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
printf("avg tat = %.2f and avg wt = %.2f",(float)avgtat/n,(float)avgwt/n);
return 0;
}
