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
{{9,10,-1,-1,-1,-1,-1,-1},
{10,9,9,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{9,9,10,-1,-1,-1,-1,-1},
{10,10,9,9,-1,-1,-1,-1},
{10,-1,-1,-1,-1,-1,-1,-1},
{9,10,9,-1,-1,-1,-1,-1},
{9,9,10,10,-1,-1,-1,-1}}
};

char vertices[8]={'A','B','C','D','E','F','G','H'};
int weight[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int isWeightUpdated[8]={0,0,0,0,0,0,0,0};
int path[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int visited[8]={0,0,0,0,0,0,0,0};
char srcC,dstC;
int srcI,dstI;



int queue[100];
int front=-1;
int rear=-1;
int lowerBound=0;
int upperBound=99;


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

//Setting the weight of source as 0
//and pushing it to the back of the queue.
weight[srcI]=0;
rear++;
queue[rear]=srcI;
front=0;

int current,i,j,adv,advw,sum;
while(rear!=-1)
{
//Removing an element from the front of the queue
current=queue[front];
i=0;
while(i<rear)
{
queue[i]=queue[i+1];
i++;
}
rear--;
if(rear==-1)front=-1;
visited[current]=1;

j=0;
while(j<8 && graph[0][current][j]!=-1)
{
adv=graph[0][current][j];
sum=weight[current]+graph[1][current][j];
if(visited[adv])
{
j++;
continue;
}
if(isWeightUpdated[adv]==0 || sum<weight[adv])
{
isWeightUpdated[adv]=1;
weight[adv]=sum;
path[adv]=current;
if(graph[1][current][j]==9)//Lower weight among the binary
{
if(rear==-1)
{
rear=0;
front=0;
queue[front]=adv;
}
else
{
for(i=rear;i>=0;i--)queue[i+1]=queue[i];
rear++;
queue[front]=adv;
}
}
else
{
rear++;
queue[rear]=adv;
if(front==-1)front=0;
}
}
j++;
}
}

int index;
if(visited[dstI]==0)
{
printf("No path bruh");
}
else
{
index=dstI;
while(1)
{
printf("%c\n",vertices[index]);
if(index==srcI)break;
index=path[index];
}
printf("Total weight : %d\n",weight[dstI]);
}












return 0;
}
