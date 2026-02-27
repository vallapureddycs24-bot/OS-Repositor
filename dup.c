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
int found=0;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            found=1;
            break;
        }
    }
}
if(found==1){
    printf("present");
}
else{
    printf("not present");
}
return 0;
}
