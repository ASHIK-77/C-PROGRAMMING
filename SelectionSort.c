#include<stdio.h>
void Selectionsort(int arr[],int n)
{    int temp,x;
    for(int i=0;i<n;i++)
    {  
        for(int j=i;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
              temp = arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
            }
        }
    }
    printf("\nAfter sorting\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main(){
    int i,j;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
int arr[n];
printf("\nEnter elements: ");
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
Selectionsort(arr,n);
return 0;

}
