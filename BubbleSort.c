#include<stdio.h>
void bubblesort(int arr[],int n)
{    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
              temp = arr[j+1];
              arr[j+1]=arr[j];
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
bubblesort(arr,n);
return 0;

}
