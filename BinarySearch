#include<stdio.h>
#include<time.h>
int BinarySearch(int arr[],int n,int target)
{int low=0,high=n-1;
   int mid;
   while (low <= high)
   {
      mid  = (low+high)/2;
      if (arr[mid]==target)
          {
            return mid;
            break;
          }else if(arr[mid]>target)
          {
           
            high=mid-1;
          }else
          {
            low=mid+1;
          }
          
   }
   return -1;
}
int main(){
    int i,n,key;
    printf("Enter the number of terms of arraay: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array in sorted way\n");
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }
    printf("Enter the key to search\n");
    scanf("%d",&key);
    clock_t start,end;
    double cpu_time;
    start = clock();
    int result =BinarySearch(arr,n,key);
    end=clock();
    cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
    if(result!=-1)
    {
        printf("\nElement found at index %d",result+1);
    }else{
        printf("Element not found!!!!");
    }
    printf("\nExcecution time : %f",cpu_time);

size_t space_used = sizeof(arr)+sizeof(n)+sizeof(i)+sizeof(key);
printf("\nApproximate space: %zu bytes",space_used);
return 0;


}
