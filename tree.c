#include<stdio.h>
struct tnode
{
    struct tnode *lchild;
    int num;
    struct tnode *rchild;
};
void inorder(struct tnode *rider)
{
    if(rider==NULL)
        return;
    inorder(rider->lchild);
    printf("%5d",rider->num);
    inorder(rider->rchild);
}
void preorder(struct tnode *rider)
{
    if(rider==NULL)
        return;
    printf("%5d",rider->num);
    preorder(rider->lchild);
    preorder(rider->rchild);
}
void postorder(struct tnode *rider)
{
    if(rider==NULL)
        return;
    preorder(rider->lchild);
    preorder(rider->rchild);
    printf("%5d",rider->num);
}
void findpar(struct tnode **parptrptr,int val,struct tnode **rootptrptr)
{
    struct tnode *par=*rootptrptr,*child=NULL;
    if(*rootptrptr==NULL)//for first node
        *parptrptr=NULL;
    else
    {
        if(val<par->num)
            child=par->lchild;
        else
            child=par->rchild;
        while(child!=NULL)
        {
            if(val<child->num)
            {
                par=child;
                child=child->lchild;
            }
            else
            {
                par=child;
                child=child->rchild;
            }
        }
        *parptrptr=par;
    }
}
void addnode(struct tnode **rootptrptr)
{
    struct tnode *par;
    int val;
    printf("\nEnter element\n");
    scanf("%d",&val);
    findpar(&par,val,rootptrptr);
    struct tnode *nnode=(struct tnode *)malloc(sizeof(struct tnode));
    nnode->num=val;
    nnode->lchild=nnode->rchild=NULL;
    if(par!=NULL)
        printf("\nparent is %d\n",par->num);
    if(par==NULL)//new node has to be added
        *rootptrptr=nnode;
    else
    {
        if(val<par->num)
            par->lchild=nnode;
        else
            par->rchild=nnode;
    }
}
void delzero(struct tnode **rootptrptr,int val)
{
    struct tnode *par=*rootptrptr,*child=NULL;
    if((*rootptrptr)->lchild==NULL&&(*rootptrptr)->rchild==NULL)
        *rootptrptr=NULL;
    else
    {
        if(val<par->num)
            child=par->lchild;
        else
            child=par->rchild;
        while(child->num!=val)
        {
            if(child->lchild==NULL&&child->rchild==NULL)
            {
                printf("%d not fount",val);
                return;
            }
            else if(val<child->num)
            {
                par=child;
                child=child->lchild;
            }
            else
            {
                par=child;
                child=child->rchild;
            }
        }
        if(val<par->num)
            par->lchild=NULL;
        else
            par->rchild=NULL;
        printf("\ndeleted %d\n",child->num);
    }
}
void delone(struct tnode **rootptrptr,int val)
{
    struct tnode *par=*rootptrptr,*child=NULL,*gchild=NULL;
    if((*rootptrptr)->lchild==NULL&&(*rootptrptr)->rchild==NULL)
        *rootptrptr=NULL;
    else
    {
        if(val<par->num)
            child=par->lchild;
        else
            child=par->rchild;
        if(child==NULL)
        {
            printf("\n%d not fount\n",val);
            return;
        }
        while(child->num!=val)
        {
            if(child->lchild==NULL&&child->rchild==NULL)
            {
                printf("%d not fount",val);
                return;
            }
            else if(val<child->num)
            {
                par=child;
                child=child->lchild;
            }
            else
            {
                par=child;
                child=child->rchild;
            }

        }
        if(child->lchild==NULL)
            gchild=child->rchild;
        else
            gchild=child->lchild;
        if(gchild==NULL)
        {
            printf("\n%d is node with two children\n",val);
            return;
        }
        if(gchild->num<par->num)
            par->lchild=gchild;
        else
            par->rchild=gchild;
        printf("\ndeleted %d\n",child->num);
        free(child);
    }
}
void deltwo(struct tnode **rootptrptr,int val)
{
    struct tnode *par=*rootptrptr,*child=NULL,*gchild=NULL,*succ=NULL,*parsucc=NULL;
    if((*rootptrptr)->lchild==NULL&&(*rootptrptr)->rchild==NULL)
        *rootptrptr=NULL;
    else
    {
        if(val<par->num)
            child=par->lchild;
        else
            child=par->rchild;
        while(child->num!=val)
        {
            if(child->lchild==NULL&&child->rchild==NULL)
            {
                printf("%d not fount",val);
                return;
            }
            else if(val<child->num)
            {
                par=child;
                child=child->lchild;
            }
            else
            {
                par=child;
                child=child->rchild;
            }

        }
        //child is the node to be deleted
        parsucc=child;
        succ=child->rchild;
        while(succ->lchild!=NULL)
        {
            parsucc=succ;
            succ=succ->lchild;
        }
        child->num=succ->num;
        if(parsucc==child)//only one node in right side
            parsucc->rchild=succ->rchild;
        else
            parsucc->lchild=succ->rchild;
        printf("\ndeleted %d\n",child->num);
        free(succ);
    }
}
void main()
{
    struct tnode *root=NULL;
    int ch,del;
    while(1)
    {
        printf("\n1.add \n2.delete zero\n3.delete one\n4.delete two\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            addnode(&root);
        }
        else if(ch==2)
        {
            printf("\nenter the element to delete\n");
            scanf("%d",&del);
            delzero(&root,del);
        }
        else if(ch==3)
        {
            printf("\nenter the element to delete\n");
            scanf("%d",&del);
            delone(&root,del);
        }
        else if(ch==4)
        {
            printf("\nenter the element to delete\n");
            scanf("%d",&del);
            deltwo(&root,del);
        }
        else
            break;
        printf("  inorder=>");
        inorder(root);
        printf("\n");
        printf(" preorder=>");
        preorder(root);
        printf("\n");
        printf("postorder=>");
        postorder(root);
    }
}

