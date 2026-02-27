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
printf("enter the key to search\n");
scanf("%d",&key);
int low=0,high=n-1;
int mid;
int found=0;
while(low<=high){
        mid=(low+high)/2;
    if(arr[mid]==key){
        found=1;
        break;
    }
    else if(arr[mid]>key){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
}
if(found==1){
    printf("found\n");
}
else{
    printf("not found\n");
}
}
