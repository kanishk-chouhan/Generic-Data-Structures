#include<stdio.h>
#include<stdlib.h>
#include<tm_stack.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(x[e]<=x[lb] && e<ub) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
}
}
return f;
}
void quickSort(int *x,int lb,int ub)
{
struct _lb_ub
{
int lb;
int ub;
};
int succ;
int a,b,pp;
Stack *stack;
struct _lb_ub LbUb;
struct _lb_ub *lb_ub;
stack=createStack(&succ);
if(succ==false)
{
printf("Stack cannot being created\n");
return;
}
LbUb.lb=lb;
LbUb.ub=ub;
pushOnStack(stack,&(LbUb),&succ);
while(!isStackEmpty(stack))
{
lb_ub=(struct _lb_ub *)popFromStack(stack,&succ);
a=lb_ub->lb;
b=lb_ub->ub;
pp=findPartitionPoint(x,a,b);
if(pp+1<b)
{
LbUb.lb=pp+1;
LbUb.ub=b;
pushOnStack(stack,&(LbUb),&succ);
}
if(a<pp-1)
{
LbUb.lb=a;
LbUb.ub=pp-1;
pushOnStack(stack,&(LbUb),&succ);
}
}
}
int main()
{
int *x;
int req,y;
printf("Enter your requirement : ");
scanf("%d",&req);
fflush(stdin);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}