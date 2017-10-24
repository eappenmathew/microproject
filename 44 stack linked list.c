#include <stdio.h>
#include <stdlib.h>

struct node // Creating the node
{
    int num;
    struct node *next;
};

void push(struct node **stactptrptr) //To Push the elemnt to the stack
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the valuve:");
    scanf("%d",&nnodeptr->num); //scan elemnt to the num field
    nnodeptr->next=*stactptrptr;
    *stactptrptr=nnodeptr;


}

void displaystack(struct node *top) //display the stack
{

    if (top!=NULL) //Check if stack is empty
    {
        printf("The Stack is:\n");
        printf("\n--stack------memory--\n");
        while (top!=NULL) //Tranverse the list till it become null
        {
            printf("|%5d | %10u |\n",top->num,&top);
            top=top->next;
        }
        printf("---------------------\n");
    }
    else
        printf("The Stack is empty!");

}
int pop(struct node **stackptrptr) // pop the element and return to main
{
    struct node *temp;
    int ele;
    if (*stackptrptr!=NULL)
    {
        temp=*stackptrptr; //storing the address to free it later
        ele=temp->num;
        temp=*stackptrptr;
        *stackptrptr=(*stackptrptr)->next;
        free(temp); // free the occupied space
        return ele;
    }
    else
        return -1; //If no elements in stack


}
void main()
{
    struct node *stack=NULL;
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
            push(&stack);
            displaystack(stack);
        }
        else if (ch==2) //call pop function here
        {
            ele=pop(&stack);
            if (ele!=-1) // if not Empty list
                printf("The Element poped is %d!\n",ele);
            displaystack(stack);
        }
        else if (ch==3) // call diplay function here
        {
            displaystack(stack);
        }
        else if (ch==9) // exit the program
        {
            exit(0);
        }
        else
            printf("\nInvalid Choice!!"); // handling valid choice

    }
}
