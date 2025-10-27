#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char url[100];
    struct Node*prev;
    struct Node*next;
};
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    struct Node*current=NULL,*head=NULL;
     char url[100];
     int choice;
     printf("Browser\n1.new\n2.back\n3.forward\n4.exit\n");
do{
    printf("enterr your choice: ");
    scanf("%d",&choice);
    getchar();
     
    switch (choice){
        case 1:
               printf("Enter the url to visit: ");
               fgets(url,sizeof(url),stdin);
               struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
               strcpy(newNode->url,url);
               newNode->prev=current;
               newNode->next=NULL;
             if(current!=NULL) 
             {
                current->next=newNode;

             } else
                    head = newNode;
             current=newNode;
             printf("Visited %s\n",url);
             break;
        case 2:
               if(current==NULL||current->prev==NULL)
               {
                printf("Cannot go back!!!");
                printf("\n");
               }else{
                 current=current->prev;
                 printf("Moved to %s",current->url);
               }
               break;
        case 3:
                if(current == NULL || current->next == NULL)
                {
                    printf("Cannot go forward!!!1");
                    printf("\n");
                } else{
                    current= current->next;
                    printf("moved to %s",url);
                }
                break;
        case 4:
                  printf("Exiting.......");
                  free(newNode);
                  freeList(head);
                  exit(0);
        default : 
                  printf("invalid input!!!!!!!");
    }

  
}while(choice<=4);

return 0;
}
