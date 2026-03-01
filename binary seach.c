#include<stdio.h>
int main(){
int n;
printf("enter the num of elements\n");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter element %d",i+1);
    scanf("%d",&arr[i]);
}
int key;
int found=0;
printf("enter the key to search\n");
scanf("%d",&key);
int i;
for(i=0;i<n;i++){
    if(key==arr[i]) {
        found=1;
        break;
    }
}
if(found==0){
    printf("not found");
}
else{
    printf("found at position %d ",i);
}
return 0;}
