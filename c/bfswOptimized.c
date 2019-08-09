#include<stdio.h>
int main()
{

int graph[2][8][8]={
{{1,3,-1,-1,-1,-1,-1,-1},
{2,4,7,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{4,5,0,-1,-1,-1,-1,-1},
{1,2,3,6,-1,-1,-1,-1},
{6,-1,-1,-1,-1,-1,-1,-1},
{7,5,0,-1,-1,-1,-1,-1},
{4,5,6,3,-1,-1,-1,-1}}
,
{{2,5,-1,-1,-1,-1,-1,-1},
{4,3,6,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{3,6,2,-1,-1,-1,-1,-1},
{2,3,4,5,-1,-1,-1,-1},
{4,-1,-1,-1,-1,-1,-1,-1},
{3,1,5,-1,-1,-1,-1,-1},
{2,3,7,2,-1,-1,-1,-1}}
};

///////////////////////////////////////////////////////GRAPH NOT FILLED YET//////////////////////////////////////////////////

char vertices[8]={'A','B','C','D','E','F','G','H'};
int weight[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int path[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int visited[8]={-1,-1,-1,-1,-1,-1,-1,-1};
char srcC,dstC;
int srcI,dstI;

//Heap Declarations
int heap[1000];
int ri,ci,lci,rci,g,lb,ub,heapSize,swi,sum;
heapSize=0;
lb=-1;
ub=-1;

char temp[3];
printf("Enter source vertex : ");
fgets(temp,3,stdin);
srcC=temp[0];
printf("Enter destination vertex : ");
fgets(temp,3,stdin);
dstC=temp[0];
int l;
for(l=0;l<8;l++)if(srcC==vertices[l])break;
srcI=l;
for(l=0;l<8;l++)if(dstC==vertices[l])break;
dstI=l;

//Add source to heap
heapSize++;
lb++;
ub++;
heap[ub]=srcI;


int current,adv,advw,j;

while(heapSize>0)
{
if(heapSize==1)
{
current=heap[0];
heapSize=0;
ub=-1;
lb=-1;
}
else
{
current=heap[0];
heapSize--;
heap[0]=heap[ub];
ub--;
ri=0;
while(ri<ub)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>ub)break;
if(rci<=ub)
{
if(weight[heap[rci]]<weight[heap[lci]])swi=rci;
else swi=lci;
}else swi=lci;
if(weight[heap[swi]]<weight[heap[ri]])
{
g=heap[swi];
heap[swi]=heap[ri];
heap[ri]=g;
visited[heap[swi]]=ri;
visited[heap[ri]]=swi;
}
ri=swi;
}
}
visited[current]=-2;//Heap mei add hokar bahar bhi aa gya
if(current==dstI)break;//khel khtm

//Traversing adjacent vertices
j=0;
while(j<8 && graph[0][current][j]!=0)
{
adv=graph[0][current][j];
advw=graph[1][current][j];
sum=advw+weight[current];
if(adv==srcI || visited[adv]!=-1 || (weight[adv]!=-1 && sum>=advw))
{
j++;
continue;
}
weight[adv]=sum;
path[adv]=current;
if(visited[adv]>=0)//Already in heap,first remove it.
{
if(heapSize==1)
{
heapSize=0;
ub=-1;
lb=-1;
}
else
{
heap[visited[adv]]=heap[ub];
ub--;
heapSize--;
ri=visited[adv];
while(ri<ub)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>ub)break;
if(rci<=ub)
{
if(weight[heap[rci]]<weight[heap[lci]])swi=rci;
else swi=lci;
}else swi=lci;
if(weight[heap[swi]]<weight[heap[ri]])
{
g=heap[swi];
heap[swi]=heap[ri];
heap[ri]=heap[swi];
visited[heap[ri]]=swi;
visited[heap[swi]]=ri;
}
ri=swi;
}
}
}
//Add adv to heap.
if(heapSize==0)
{
heapSize=1;
lb=0;
ub=0;
heap[0]=adv;
}
else
{
ub++;
heap[ub]=adv;
heapSize++;
ci=ub;
while(ci>lb)
{
ri=(ci-1)/2;
if(weight[heap[ci]]<weight[heap[ri]])
{
g=heap[ci];
heap[ci]=heap[ri];
heap[ri]=g;
visited[heap[ci]]=ri;
visited[heap[ri]]=ci;
}
ci=ri;
}
}

j++;
}//While loop to traverse adjacent vertices


}//Big while loop



int index;
if(visited[dstI]==-1)
{
printf("Path ni mila bro");
}
else
{
index=dstI;
while(1)
{
printf("%c\n",vertices[index]);
if(vertices[index]==srcC)break;
index=path[index];
}
printf("Total weight-%d\n",weight[dstI]);
}



return 0;
}

