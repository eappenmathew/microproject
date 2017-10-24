#include<stdio.h>
#include<conio.h>
void main()
{
    int l,left=123456,top=1,t,h,ht=12,w,wid=9,s,sp,de,d;
    for(l=9;l<=left;l++)
    {
        wid=l;
        ht=wid*(5/3);
        for(h=1;h<=(ht-2)/2;h++)
        {
            printf("U");
            for(sp=1;sp<=wid-2;sp++)
                printf("_");
            printf("U\n");
        }
        for(w=1;w<=wid;w++)
            printf("U");
        printf("\n");
        for(h=1;h<=(ht-2)/2;h++)
        {
            for(w=1;w<=wid/2;w++)
                    printf(" ");
            printf("I\n");
        }
        for(w=1;w<=wid;w++)
        {
            printf("I");
        }
        printf("\n\n\n");
        for(d=1;d<=8766;d++)
            for(de=1;de<=234;de++);
    }
    getch();
}
