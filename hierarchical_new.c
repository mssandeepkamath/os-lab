#include<stdio.h>
#include<stdlib.h>
struct node
{
char N[25];
int df;
struct node *pc;
struct node *ps;
};
struct node * A[20];
int in=0, c=0;
struct node * create(struct node *P, int N)
{
int i;
struct node *Tmp, *T;
Tmp=P;
for(i=0;i&lt;N;i++)
{
T=(struct node *)malloc(sizeof(struct node));
printf(&quot;Enter name : &quot;);
scanf(&quot;%s&quot;, T-&gt;N);
printf(&quot;Enter dir(1) or file(0): &quot;);
scanf(&quot;%d&quot;, &amp;T-&gt;df);
if(T-&gt;df==1)
{
A[c]=T;
c++;
}
T-&gt;pc=NULL;

T-&gt;ps=NULL;
if(i==0)
{
Tmp-&gt;pc=T;
Tmp=T;
}
else
{
Tmp-&gt;ps=T;
Tmp=T;
}
}
}
void display(struct node *P)
{
int i;
P=P-&gt;pc;
do
{
printf(&quot;\n%s(%d)&quot;,P-&gt;N, P-&gt;df);
if(P-&gt;df==1 &amp;&amp; P-&gt;pc!=NULL)
display(P);
P=P-&gt;ps;
}while(P!=NULL);
}
int main()
{
int nu,nc;
int i,j,k;
struct node *Hdr;
Hdr =(struct node *)malloc(sizeof(struct node));

Hdr-&gt;df=1;
Hdr-&gt;pc=NULL;
Hdr-&gt;ps=NULL;
printf(&quot;\nEnter number of users :\n &quot;);
scanf(&quot;%d&quot;,&amp;nu);
create(Hdr, nu);
for(in=0;in&lt;c;in++)
{
printf(&quot;\nEnter number of child nodes for %s : &quot;, A[in]-&gt;N);
scanf(&quot;%d&quot;, &amp;nc);
create(A[in], nc);
}
printf(&quot;\n Hierarchical\n&quot;);
display(Hdr);
return 0;
}
