#include<stdio.h>
int main()
{
int heap[1000];
int heapSize;
int ch,num,ri,ci,lci,rci,g,swi,lb,ub;
heapSize=0;
lb=-1;
ub=-1;
while(1)
{
printf("1. Add to heap\n");
printf("2. Remove from heap\n");
printf("3 Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number to add to heap : ");
scanf("%d",&num);
if(heapSize==0)
{
heap[0]=num;
lb=0;
ub=0;
heapSize=1;
}
else
{
ub++;
heap[ub]=num;
heapSize++;
ci=ub;
while(ci>lb)
{
ri=(ci-1)/2;
if(heap[ci]<heap[ri])
{
g=heap[ci];
heap[ci]=heap[ri];
heap[ri]=g;
}
ci=ri;
}
}
printf("%d Added to heap\n",num);
}
else if(ch==2)
{
if(heapSize==0)
{
printf("No elements to remove from heap\n");
}
else if(heapSize==1)
{
num=heap[0];
heapSize=0;
printf("%d removed from heap\n",num);
lb=-1;
ub=-1;
}
else
{
num=heap[0];
heapSize--;
printf("%d removed from heap\n",num);
heap[0]=heap[ub];
ub--;
ri=0;
while(ri<ub)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>ub) break;
if(rci<=ub)
{
if(heap[lci]<heap[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
else
{
swi=lci;
}
if(heap[swi]<heap[ri])
{
g=heap[swi];
heap[swi]=heap[ri];
heap[ri]=g;
}
ri=swi;
}
}
}
else if(ch==3) break;
}
return 0;
}
