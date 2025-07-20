#include<stdio.h>

struct poly{
    int coeff;
    int exp;
}p1[100],p2[100],p3[100];
void sum( struct poly arr[],int n)
{   int i;
    for(i=0;i<n;i++)
    {
        if(i > 0 && arr[i].coeff > 0)
        {
            printf("+");
        }
        printf("%d(x^%d)",arr[i].coeff,arr[i].exp);
    }
    printf("\n");
}
int main()
{
    int j,k=0,i,n1,n2;
    printf("Enter the number of terms of polynomial-1:\t");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter the cofficient part: ");
        scanf("%d",&p1[i].coeff);
        printf("Enter the exponent part: ");
        scanf("%d",&p1[i].exp);
        
    }
    printf("Enter the number of terms of polynomial-2:\t");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter the cofficient part: ");
        scanf("%d",&p2[i].coeff);
        printf("Enter the exponent part: ");
        scanf("%d",&p2[i].exp); 
    }
    i=0;
    j=0;
    while(i < n1 && j < n2)
    {
        if(p1[i].exp == p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff+p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
        }else if(p1[i].exp > p2[j].exp)
        {
          p3[k].coeff = p1[i].coeff;
          p3[k].exp = p1[i].exp;
          i++;
        }
        else{
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
        }
      k++;
    }
    while(i<n1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }
    while(j<n2) 
    {
      p3[k].coeff = p2[j].coeff;
      p3[k].exp = p2[j].exp;
      j++;
      k++;
    }
    printf("\nSUM IS:\n");
    sum(p1,n1);
    sum(p2,n2);
    printf("\n__________________________________\n");
    sum(p3,k);
    return 0;
}
