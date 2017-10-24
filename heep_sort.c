#include<stdio.h>


void addheep(int heep[],int elem,int size)
{
    int par,pos;

    if(size==1)
    {
        heep[1]=elem;
        return;
    }
    else
    {
        par=size/2;
        pos=size;
        while(par>=1)
        {
            if(heep[par]>elem)
            {
                heep[pos]=heep[par];
                pos=par;
                par=par/2;
            }
            else
                break;
        }
        heep[pos]=elem;
    }
}



void delheep(int heep[],int size)
{
    int elem=heep[1],left=2,right=3,up,par=1,lpos=par*2,rpos=par*2+1;
    heep[1]=heep[size];
    size--;
    while(lpos<=size)
    {

    }
}




void printheep(int heep[],int size)
{
    int p;
    for(p=1;p<size+1;p++)
        printf("%d\n",heep[p]);
    printf("------\n");
}


void main()
{
    int arr[11]={70,40,50,80,30,10,100,90,110,20,60,},heep[11],size,p;
    for(size=0;size<11;size++)
    {
        addheep(heep,arr[size],size+1);
        printheep(heep,size+1);
        getch();
    }
}
