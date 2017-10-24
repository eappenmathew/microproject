#include <stdio.h>
#include <stdlib.h>

struct node // Creating the node
{
    int num;
    struct node *next;
};

void push(struct node **startptrptr,struct node **endptrptr) //To Push the elemnt to the stack
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the valuve:");
    scanf("%d",&nnodeptr->num); //scan elemnt to the num field

    if (*startptrptr!=NULL)
    {
        nnodeptr->next=*startptrptr;
        *startptrptr=nnodeptr;
    }
    else // if its the first element
    {
       nnodeptr->next=NULL;
        *endptrptr=*startptrptr=nnodeptr;
    }


}

void displaystack(struct node *startptr) //display the stack
{

    if (startptr!=NULL) //Check if Que is empty
    {
        printf("The Stack is:\n");
        printf("\n--Que------memory--\n");
        while (startptr!=NULL) //Tranverse the list till it become null
        {
            printf("|%5d | %10u |\n",startptr->num,&startptr);
            startptr=startptr->next;
        }
        printf("---------------------\n");
    }
    else
        printf("The Que is empty!");

}
int pop(struct node **startptrptr,struct node **endptrptr) // pop the element and return to main
{
    struct node *temp,*rider;
    int ele;
    if (*endptrptr!=NULL)
    {

        temp=*endptrptr; //storing the address to free it later
        ele=(*endptrptr)->num;

        rider=*startptrptr;
        if (rider->next!=NULL)
        {
                while (rider->next->next!=NULL)
                    rider=rider->next;

            rider->next=NULL;
            *endptrptr=rider;
        }
        else
            *startptrptr=*endptrptr=NULL;
        free(temp); // free the occupied space
        return ele;
    }
    else
        return -1; //If no elements in stack


}
void main()
{
    struct node *start=NULL,*end=NULL;
    int ele,ch;

    while(1)
    {
        printf("\n\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("9. Exit\n");
        printf("-----------\n");

        printf("Enter choice :");
        scanf("%d",&ch);

        if (ch==1) // Call pust function here
        {
            push(&start,&end);
            displaystack(start);
        }
        else if (ch==2) //call pop function here
        {
            ele=pop(&start,&end);
            if (ele!=-1) // if not Empty list
                printf("The Element poped is %d!\n",ele);
            displaystack(start);
        }
        else if (ch==3) // call diplay function here
        {
            displaystack(start);
        }
        else if (ch==9) // exit the program
        {
            exit(0);
        }
        else
            printf("\nInvalid Choice!!"); // handling valid choice

    }
}

