#include<stdio.h>

void display(int tree[],int n)
{
    int p;
    printf("\nHeap elements are\n");
    for(p=1;p<n;p++)
    {
        printf("%4d",tree[p]);
    }
}


void insertheap(int tree[],int n,int item)
{
    int child,parent,temp;
    child=n;
    tree[child]=item;
    printf("\n n= %d",n);
     parent=n/2;
    while(child>1&&(tree[child]<tree[parent]))
    {
        temp=tree[child];
        tree[child]=tree[parent];
        tree[parent]=temp;
        child=parent;
        parent=child/2;
    }
}



void delete(int tree[],int n)
{
    int item=tree[1];
    tree[1]=tree[n-1];
    printf("\n n=%d",n-2);
    n--;
    int child=1,leftchild=2,rightchild=3;
    while(rightchild<=n)
    {
        if(tree[rightchild]<tree[leftchild] && tree[rightchild]<tree[child])
        {
            int temp;
            temp=tree[rightchild];
            tree[rightchild]=tree[child];
            tree[child]=temp;
            child=rightchild;
        }
        else if(tree[leftchild]<tree[child])
        {
            int t;
            t=tree[leftchild];
            tree[leftchild]=tree[child];
            tree[child]=t;
            child=leftchild;
        }
        else
            break;
        leftchild=2*child;
        rightchild=leftchild+1;

    }

    if(leftchild==n&& tree[child]<tree[leftchild])
    {
        int te;
        te=tree[child];
        tree[child]=tree[leftchild];
        tree[leftchild]=te;
    }



}


void main()
{
    int tree[10],n=1,item;
    while(1)
    {
        int ch;
        printf("\n1.insert\n2.delete\n3.exit\n");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:
                printf("\nEnter any value\n");
                scanf("%d",&item);
                insertheap(tree,n,item);
                n++;
                display(tree,n);
                break;
            case 2:
                delete(tree,n);
                n--;
                display(tree,n);
                break;
            case 3:

                exit(0);



        }
        printf("\n\n=============================================\n\n");






    }


}
