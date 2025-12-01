#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,n1,*queue;
void FD(int n){
    if( front == -1){
        printf("Underflow!!!");
        return;}
    else if(front==rear){
        front =rear=-1;}
    else if(front == n-1){
        front = 0;}
    else{
        front++; 
    }
}
void RD(int n){
if(rear==-1){
    printf("Underflow...");
}else if(front == rear){
    rear = front = -1;
}else if(rear == 0){
    rear =n-1;
}else{
    rear --;
}
}
void FE(int n)
{  

    printf("Enter element \n");
    scanf("%d",&n1);
     if(((rear+1)%n==front)||(front == 0 && rear==n-1))
    {
        printf("Overflow!!!");
        
    }else{
        if(front == -1){
           rear= front = 0;
        }else if(front == 0){
            front = n-1;
        }else{
        front -- ;}
       queue[front]=n1; 
          
        
    }

}
void RE(int n)
{  

    printf("Enter element \n");
    scanf("%d",&n1);
    if(((rear+1)%n==front)||(front == 0 && rear==n-1))
    {
        printf("Overflow!!!");
        
    }else{
        if(front == -1){
            rear = front = 0;
        }else if(rear == n-1){
            rear=0;
        }else{
        rear++;}
       queue[rear]=n1; 
     
        
    }

}
void Display(int n){
    if(front == -1 || rear==-1)
    {
        printf("Queue Empty!!");
    }else{
        printf("Queue elements\n");
       int i=front;
       do{
              printf("%d\t",queue[i]);
            i=(i+1)%n;
       
        } while(i!=rear);
        printf("%d",queue[rear]);
        printf("\n");
    }
}
int main()
{
  int n,i,choice;
  printf("Enter the sizee of queue: ");
  scanf("%d",&n);
  queue = (int*)malloc(n*sizeof(int));
  if(queue==NULL)
  {
    printf("Memeory allocation failed !");}
    do{
       printf("-------------------\n1.FE\n2.FD\n3.RE\n4.RD\n5.DISPLAY\n6.exit\nSSEnter your choice: ");
       scanf("%d",&choice);
       switch(choice){
        case 1: FE(n);break;
        case 2:FD(n);break;
        case 3:RE(n);break;
        case 4:RD(n);break;
        case 5:Display(n);break;
        case 6:printf("Exiting....");break;
        default: printf("invalid input....");

       }
    }while(choice!=6);
  
  free(queue);
  return 0;
}
