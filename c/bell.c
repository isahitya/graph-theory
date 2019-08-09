#include<stdio.h>
int main()
{
char src='A';
char dst='G';
char vertices[8]={'A','B','C','D','E','F','G','H'};
int srcI,dstI;
for(srcI=0;srcI<8;srcI++)if(vertices[srcI]==src)break;
for(dstI=0;dstI<8;dstI++)if(vertices[dstI]==dst)break;

int graph[2][8][8]=
{
{
{1,3,5,-1,-1,-1,-1,-1},
{4,-1,-1,-1,-1,-1,-1,-1},
{5,7,-1,-1,-1,-1,-1,-1},
{2,6,-1,-1,-1,-1,-1,-1},
{2,3,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{5,-1,-1,-1,-1,-1,-1,-1},
{5,-1,-1,-1,-1,-1,-1,-1},
},
{
{2,4,7,-1,-1,-1,-1,-1},
{-3,-1,-1,-1,-1,-1,-1,-1},
{3,1,-1,-1,-1,-1,-1,-1},
{1,1,-1,-1,-1,-1,-1,-1},
{-2,1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{1,-1,-1,-1,-1,-1,-1,-1},
}
};

int path[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int visited[8]={0,0,0,0,0,0,0,0};
int weight[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int isWeightUpdated[8]={0,0,0,0,0,0,0,0};

//Setting weight of source as 0 and weightUpdated as True
weight[srcI]=0;
isWeightUpdated[srcI]=1;

int times=0;
int e,f,j,sum;
while(times<7)
{
for(e=0;e<8;e++)
{
if(isWeightUpdated[e]==0)continue;
for(j=0;j<8 && graph[0][e][j]!=-1;j++)
{
f=graph[0][e][j];
//if(visited[f])continue;
//visited[f]=1;
sum=weight[e]+graph[1][e][j];//Graph of e ke jth index pe f ka weight rakha hai,fth index pe rakhne wali approach NAHI use ki
if(isWeightUpdated[f]==0 || sum<weight[f])
{
printf("vertice of %c, %c got updated from %d to %d\n",vertices[e],vertices[f],weight[f],sum);
isWeightUpdated[f]=1;
weight[f]=sum;
path[f]=e;
}
}
}
times++;
}

int negativeCycle=0;

for(e=0;e<8;e++)
{
for(j=0;j<8 && graph[0][e][j]!=-1;j++)
{
f=graph[0][e][j];
sum=weight[e]+graph[1][e][j];//Graph of e ke jth index pe f ka weight rakha hai,fth index pe rakhne wali approach nahi use ki
if(isWeightUpdated[f] && sum<weight[f])
{
printf("sum:%d and weight of f:%d\n",sum,weight[f]);
negativeCycle=1;
}
}
}

int index;
if(negativeCycle)
{
printf("Graph mei negative cycle hai bro\n");
}
else
{
index=dstI;
while(1)
{
printf("%c\n",vertices[index]);
if(vertices[index]==src)break;
index=path[index];
}
printf("%d\n",weight[dstI]);
}



return 0;
}
