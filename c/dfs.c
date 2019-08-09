#include<stdio.h>
int main()
{
  char ph[8]={'A','B','C','D','E','F','G','H'};
  int cm[8][8]={{1,3,-1,-1,-1,-1,-1,-1},
                        {2,4,7,-1,-1,-1,-1,-1},
   	                   {-1,-1,-1,-1,-1,-1,-1,-1},
  	                    {4,5,0,-1,-1,-1,-1,-1},
  	                     {1,2,3,6,-1,-1,-1,-1},
  	                      {6,-1,-1,-1,-1,-1,-1,-1},
  	                       {7,5,0,-1,-1,-1,-1,-1},
  	                        {4,5,6,3,-1,-1,-1,-1}};
  int path[8]={-1,-1,-1,-1,-1,-1,-1,-1};
  int visited[8]={-1,-1,-1,-1,-1,-1,-1,-1};

  char src='A';
  char dst='G';
int i,dstI;
for(i=0;i<8;i++)if(ph[i]==src)break;
for(dstI=0;dstI<8;dstI++)if(ph[dstI]==dst)break;
int depth[8]={-1,-1,-1,-1,-1,-1,-1,-1};

  //Stack declarations
  int stack[100];
  int lowerBound=0;
  int upperBound=99;
int top=100;

//pushing src to stack and setting its depth 0
stack[--top]=i;
depth[i]=0;

int current,j;
while(top!=upperBound+1)
{
  //popping an element from stack
current=stack[top];
top++;
if(visited[dstI]==1 && depth[current]>=depth[dstI])continue;
if(ph[current]==src && visited[current]==1)continue;
printf("%c",ph[current]);
j=0;
while(cm[current][j]!=-1 && j<8)
{
  if(visited[cm[current][j]]==1)
  {
    if(depth[current]+1<depth[cm[current][j]])
    {
      depth[cm[current][j]]=depth[current]+1;
      path[cm[current][j]]=current;
    }
  }
  else
  {
    visited[cm[current][j]]=1;
    path[cm[current][j]]=current;
    depth[cm[current][j]]=depth[current]+1;
    stack[--top]=cm[current][j];
  }
  j++;
}

}

printf("\n---------------------\n");

int index;
if(visited[dstI]==1)
{index=dstI;
  while(1)
  {
    printf("%c  \n",ph[index]);
    if(ph[index]==src)break;
    index=path[index];
  }
}else printf("No path bruh");
return 0;
}
