#include<stdio.h>
void Insertionsort(int arr[],int n)
{    int temp,x;
    for(int i=0;i<n;i++)
    {  x=arr[i];
        int j=i-1;
        while(j>-1&&arr[j]>x)
        { arr[j+1]=arr[j];j--;}
                    arr[j+1]=x;

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
Insertionsort(arr,n);
return 0;

}
