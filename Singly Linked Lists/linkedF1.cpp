#include<iostream>
#include<cstring>
using namespace std;
class node{
public:
    char nm[20];
    int PRN;
    node *next;
	
};
class list{
public:
    friend class node;
    node *p,*head,*n;
    list()
    {
        p=NULL;
        head=NULL;
    }
    void create()
    {
    node *t;
        t=head;
int g,g2;        
p=new node;
        cout<<"enter the details:\n";
        cin>>p->nm;
        cin>>p->PRN;
g=p->PRN;
g2=unique(g);
p->PRN=g2;
        p->next=NULL;
        if(!head)
        {
            head=p;
        }
        else
        {
            node *t;
            t=head;
            while(t->next)
            {
                
                t=t->next;
            }
	t->next=p;
        }
    }
int unique(int g1)
{
	node *t1;
	t1=head;
	while(t1)
{
	while(t1->PRN==g1)
                {
			cout<<"enter the new PRN:\n";
                    cin>>g1;
                    //p->next=NULL;
                }
t1=t1->next;
}
return g1;
}

void insert()
{
    node *p;
    p=head;
    int v,v1,pre,cnt=0;
    n=new node;
    cout<<"enter the prn after which you wanna insert a node\n";
    cin>>v;
    //p=head;
    cout<<"enter the details of the new node\n";
    cin>>n->nm>>n->PRN;
        //pre=p->next;
        //cnt=0;
    v1=n->PRN;
    pre=unique(v1);
	n->PRN=pre;
        while(p)
        {
          if(v==p->PRN)
          {
              n->next=p->next;
              p->next=n;
          }
		p=p->next;
        }
}
void deletelist()
{
    node *p;
    node *pre;
    p=head;
    pre=head;
    int v;
    cout<<"enter the PRN of the node that you want to delete\n";
    cin>>v;
    while(p)
    {       
            //pre=p
            if(v==p->PRN)
            {

                pre->next=p->next;
            }
	pre=p;
     p=p->next;
    }
}
    void display()
    {
int c=0;        
node *t;
        t=head;
if(t==NULL)
{
cout<<"the given list is empty\n";
}
else
{
        cout<<"the output is :\n";
        while(t)
        {
            cout<<t->nm<<endl<<t->PRN<<endl;
            t=t->next;
		c++;
        }
	cout<<"student count has been appended successfully:\n"<<c<<endl;
}
    }
void displayrev(node *head)
{
   if(!head)
{
	return;
}
else
{
displayrev(head->next);
}
cout<<head->nm<<head->PRN;
}
void deleted()
{
node *pre;
node *p;
p=head;
pre=head;
int h;
 cout<<"which node would you like to delete?\n";
 cout<<"1.president\n2.secretary\n";
 cin>>h;
 if(h==1)
 {
while(p)
{
     	head=NULL;
	p=p->next;
	head=p;
break;
 }
}
if(h==2)
{
	while(p)
    {       
            //pre=p
            if(p->next==NULL)
            {

                pre->next=p->next;
            }
	pre=p;
     p=p->next;
    }
}
}
void swap(node *a,node *b){
int p;
char p1[10];
strcpy(p1,a->nm);
strcpy(a->nm,b->nm);
strcpy(b->nm,p1);
p=a->PRN;
a->PRN=b->PRN;
b->PRN=p;
}
void selectionsort()
{
	node *p;
node *t=head;
	p=head;
while(p->next)  
{
t=p->next;
while(t)
{
if(t->PRN < p->PRN)
{
swap(t,p);
}
t=t->next;
}
p=p->next;
}
}
void concatenate(list s2)
{
	node *p=head;
	//node *t=s2.head;
	while(p->next!=NULL)
	{
	p=p->next;
	}
	p->next=s2.head;
	selectionsort();
}
};

int main()
{
	int n;	
	list s1,s2,s3;
       do{
          cout<<"which function do you want to perform?\n 1. create or \n2.display or \n3.insert a node in between \n4.delete a node \n5.reverse the linked list\n6.delete the first or the last node\n7.sort the linked list.\n8. create a second linked list\n9. concatenate\n";
	cin>>n;
	switch(n)
	{
	case 1:{
		s1.create();
break;
	       }	
	case 2:{
		s1.display();
break;
		}
	case 3:{
		s1.insert();
break;		
	}
    case 4:{
        s1.deletelist();
        break;
    }
case 5:{
	s1.displayrev(s1.head);
	break;
	}
case 6:{
	s1.deleted();	
	break;
	}
case 7:{
	s1.selectionsort();
break;
       }
case 8:{
	s2.create();
break;
}
case 9:{
	s1.concatenate(s2);
}      
	default:break;
	}
}
while(n!=0);
    return 0;
}

 
