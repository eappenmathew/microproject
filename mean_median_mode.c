#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,a[100],sum=0,i;
    int k,pass,p,sp=0,small=0,temp;
    float median;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    float mean=(float)sum/n;
    printf("%.1f\n",mean);
    for(pass=0;pass<n;pass++)
    {
        small=a[pass];
        for(p=pass;p<n;p++)
        {
            if(a[p]<=small)
                {
                small=a[p];
                sp=p;
                }
        }
    temp=a[sp];
    a[sp]=a[pass];
    a[pass]=temp;
    }
    if(n%2==0)
    {
        k=n/2;
        median=(a[k]+a[k+1])/2;
    }
    else
    {
        k=n/2;
        median=a[k+1];
    }
    printf("%.1f\n",median);
    printf("%d",a[0]);
    return 0;
}
