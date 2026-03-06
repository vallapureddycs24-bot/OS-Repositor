#include<stdio.h>
int main(){
int n;
printf("enter the num of elements\n");
scanf("%d",&n);
int p[n+1];
for(int i=1;i<=n;i++){
    p[i]=i;
}
int at[n+1],bt[n+1];
for(int i=1;i<=n;i++){
    printf("enter arrival time for process p of %d ",i);
    scanf("%d",&at[i]);
}
for(int i=1;i<=n;i++){
    printf("enter burst time for process p of %d ",i);
    scanf("%d",&bt[i]);
}
int ct[n+1],tat[n+1],wt[n+1];
int temp;
for(int i=1;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
        if(at[i]>at[j]){
            temp=at[i];
            at[i]=at[j];
            at[j]=temp;
             temp=p[i];
            p[i]=p[j];
            p[j]=temp;

             temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
        }
    }
}
int sum=0, completed=0;
int visited[n+1];
for(int i=1;i<=n;i++){
    visited[i]=0;
}
    while(completed<n){
        int min_bt=9999;
        int idx=-1;
        for(int i=1;i<=n;i++){
            if(at[i]<=sum && visited[i]==0){
                if(bt[i]<min_bt){
                    min_bt=bt[i];
                    idx=i;
                }
            }
        }
        if(idx==-1){
            sum++;
        }
        else{
            sum += bt[idx];
            ct[idx]=sum;
            visited[idx]=1;
            completed++;
        }
    }
for(int i=1;i<=n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
}
            printf("process\tat\tbt\tct\ttat\twt");
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==p[j]){

            printf("%d     \t%d\t%d\t%d\t%d \t%d\n",i,at[j],bt[j],ct[j],tat[j],wt[j]);
        }
    }
}
return 0;
}
