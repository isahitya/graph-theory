#include<stdio.h>
#include<stdlib.h>
struct __node__;
struct __list__;
struct __vertex;
struct __listiterator__;
typedef struct __vertex__
{
char name[25];
struct __list__* list;
}Vertex;
typedef struct __node__
{
struct __node__* next;
Vertex* data;
}Node;
typedef struct __list__
{
struct __node__* start;
struct __node__* end;
}List;
typedef struct __listiterator__
{
Node* current;
}ListIterator;

List* initList()
{
List* list=(List*)malloc(sizeof(List));
list->start=NULL;
list->end=NULL;
return list;
}

ListIterator* initListIterator(List* list)
{
ListIterator* listIterator=(ListIterator*)malloc(sizeof(ListIterator));
listIterator->current=list->start;
return listIterator;
}

void setToStart(ListIterator* li,List* list)
{
li->current=list->start;
}
void setToEnd(ListIterator* li,List* list)
{
li->current=list->end;
}

Vertex* next(ListIterator* li)
{
if(li->current==NULL)return NULL;
Vertex* ver=li->current->data;
li->current=li->current->next;
return ver;
}

int atEnd(ListIterator* li)
{
return li->current==NULL;
}

void addElement(List* list,Vertex* vertex)
{
Node* node=(Node*)malloc(sizeof(Node));
node->data=vertex;
node->next=NULL;
if(list->start==NULL)
{
list->start=node;
list->end=node;
}
else
{
list->end->next=node;
list->end=list->end->next;
}
}

int isEmpty(List* list)
{
return list->start==NULL;
}

Vertex* initVertex(char* name)
{
Vertex* vertex=(Vertex*)malloc(sizeof(Vertex));
int x=0;
for(x=0;name[x];x++)vertex->name[x]=name[x];
vertex->name[x]='\0';
vertex->list=NULL;
return vertex;
}

int main()
{
FILE* f;
f=fopen("cities.graph","r");

List* mainList=initList();
ListIterator* mainListIterator=initListIterator(mainList);
Vertex* current;
Vertex* tmp;

char c;
char eachName[25];
int x=0;
int newLine=0;
int setNewLineInNextLoop;
int z;
int found=0;
while(!feof(f))
{
c=getc(f);
if(setNewLineInNextLoop)
{
newLine=1;
setNewLineInNextLoop=0;
}
if(c!=',' && c!='\n' && c!=EOF)
{
eachName[x]=c;
x++;
}
else
{
if(c=='\n')setNewLineInNextLoop=1;
eachName[x]='\0';
printf("%s\n",&eachName[0]);
x=0;
if(isEmpty(mainList))//First element
{
newLine=0;
tmp=initVertex(eachName);
addElement(mainList,tmp);
current=tmp;
}
else
{
if(newLine)
{
newLine=0;
found=0;
setToStart(mainListIterator,mainList);
while(!atEnd(mainListIterator))
{
tmp=next(mainListIterator);
for(z=0;eachName[z] && tmp->name[z];z++)if(tmp->name[z]!=eachName[z])break;
if(tmp->name[z]=='\0' && eachName[z]=='\0')
{
found=1;
current=tmp;
break;
}
}
if(!found)
{
tmp=initVertex(eachName);
addElement(mainList,tmp);
current=tmp;
}

}
else
{
found=0;
setToStart(mainListIterator,mainList);
while(!atEnd(mainListIterator))
{
tmp=next(mainListIterator);
for(z=0;eachName[z] && tmp->name[z];z++)if(tmp->name[z]!=eachName[z])break;
if(tmp->name[z]=='\0' && eachName[z]=='\0')
{
if(current->list==NULL)current->list=initList();
addElement(current->list,tmp);
found=1;
break;
}
}
if(!found)
{
tmp=initVertex(eachName);
if(current->list==NULL)current->list=initList();
addElement(current->list,tmp);
addElement(mainList,tmp);
}

}//newLine wale if ka else
}//is empty ka else

}//big else
}//big while loop


printf("*********************************\n");

setToStart(mainListIterator,mainList);
ListIterator* tmpIterator=initListIterator(mainList);
while(!atEnd(mainListIterator))
{
tmp=next(mainListIterator);
printf("%s :",tmp->name);
if(tmp->list!=NULL)
{	
setToStart(tmpIterator,tmp->list);
while(!atEnd(tmpIterator))printf("%s, ",next(tmpIterator)->name);
}
printf("\n");
}

return 0;
}