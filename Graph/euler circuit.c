/*

(*) ​​Assume​ V={1,2,3,...,n}. 
 Assume n is bounded by 30.
 (*) ​​Assume graph is given by​ list of edges  

 Input:  First line contains number of vertices in the graph and followed by list of edges. 
 Example: 11  1 2 3 11 5 6 0  
 and​​ 0​​ indicates end of input. 

​Given an undirected graph G=(V,E) by ​by list of edges​, write a program to check if G has an Euler circuit or not (YES/NO).
If G has an Euler circuit then output an Euler circuit.
You may use the following procedure discussed in the DM class: 

(i) First check if G is not connected or G has any odd degree vertex then output no Euler circuit in G and return. 
(ii) Find some circuit in G. Let it be C. 
(iii) Remove all edges occurring in C from G. Remove any isolated vertex if any. Let this new graph also be called G.  
 
(iv) Find some circuit starting at a vertex v in G such that v also occurs in the circuit C. Let this new circuit be C’. 
(v) Remove all edges occurring in C’ from G. Remove any isolated vertex if any. Let this new graph also be called G. 
(vi) Combine circuits C and C’. Let this combined circuit also be called C. 
(vii) Repeat steps  (iv),(v) &  (vi) as long as there are edges in this new graph.  
 
(viii) Output the circuit C. 
 
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define new_node (struct node*)malloc(sizeof(struct node));

int n;
int k;
int e;

struct node
{
	int v;
	struct node* nxt;
};


int circuit(int* t, int** matrix, int m, int y)
{
	if(y == 0)
	{
		t[0] = m;
		return circuit(t,matrix,m,y+1);
	}
	else
	{
		int j = 0;
		if(y>2 && matrix[t[y-1]][m]==1)
		{
			t[y] = m;
			j = m;
			matrix[t[y-1]][m] = 0;
			matrix[m][t[y-1]] = 0;
			e--;
			return y;
		}
		else{
		while(matrix[t[y-1]][j]==0)
		{
			j++;
		}
		if(j == m)
		{
				j++;
				while(matrix[t[y-1]][j]==0)
				{
					j++;
				}
				t[y] = j;
				matrix[t[y-1]][j] = 0;
				matrix[m][t[y-1]] = 0;
		}
		else
		{
			t[y] = j;
			matrix[t[y-1]][j] = 0;
			matrix[j][t[y-1]] = 0;
		}}
		matrix[t[y-1]][j] = 0;
		e--;
		return circuit(t,matrix,m,y+1);
	}
}


void cc(int* arr, int** matrix, int u, int l)
{
	if(arr[u] == l)
		return;
	arr[u] = l;
	for(int i=0;i<n;i++)
	{
		if(matrix[u][i] == 1)
			cc(arr,matrix,i,l);
	}
}


int main()
{
	srand(time(NULL));
	int a,b;
	e = 0;
    printf("Enter the number of vertexes\n");
	scanf("%d",&n);
	int ** matrix;
	matrix = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			matrix[i][j]=0;
	}

	printf("Enter the edges\n");
	while(1)
	{
		scanf("%d",&a);
		if(a == 0)
			break;
		scanf("%d",&b);
		e++;
		matrix[a-1][b-1]++;
		matrix[b-1][a-1]++;
	}
    printf("\nGraph entered successfully\n");

	int arr[n],sum;
	for(int i=0;i<n;i++)
		arr[i] = 0;
	int l = 1;
	cc(arr,matrix,0,l);

	int s = 1;
	for(int i=0; i<n; i++)
	{
		if(arr[i]!=l)
		{
			s=0;
			printf("\nNO\n");
			break;
		}
	}

	for(int i=0; i<n; i++)
		arr[i]=1;

	if(s==1)
	{
		for(int i=0; i<n; i++)
		{
			sum=0;
			for(int j=0; j<n; j++)
			{
				sum+=matrix[i][j];
			}
			if(sum%2!=0)
			{
				s=0;
				printf("\nNO\n");
				break;
			}
		}
		if(s==1)
		{
			printf("\nYES\n");
			int * t;
			int y;
			int temp = n;
			struct node* list=NULL;
			struct node* p;
			struct node* c;
			struct node* h;
			int x=0;
			while(e>0)
			{
				int temp1=0;
				for(int ui=0; ui<n; ui++)
				{
					if(arr[ui]==1)
					{
						temp1=1;
						break;
					}
				}
				if(temp1==1)
				{
					while(arr[x]==0)
						x=(rand()%n);
				}
				else
				{
					int temp2;
					for(int ua=0; ua<n; ua++)
					{
						temp2=0;
						for(int ub=0; ub<n; ub++)
						{
							if(matrix[ua][ub]==1)
							{
								x=ua;
								temp2=1;
								break;
							}
						}
						if(temp2==1)
							break;
					}
				}
				int tl;
				t=(int*)malloc((e+1)*sizeof(int));
				tl=circuit(t,matrix,x,0);
				if(list==NULL)
				{
					c=new_node;
					c->v=t[0];
					c->nxt=NULL;
					list=c;
				}
				p=list;
				while(p->v!=t[0])
				{
					p=p->nxt;
				}
				int i=1;
				while(tl>0)
				{
					c=new_node;
					c->v=t[i];
					c->nxt=p->nxt;
					p->nxt=c;
					tl--;
					i++;
					p=p->nxt;
				}
				tl=i-1;
				i--;
				int status;
				for(int u=0; u<n; u++)
					arr[u]=0;
				for(int u=0; u<i; u++)
				{
					arr[t[u]]=1;
				}
				for(int u=0; u<n; u++)
				{
					status=0;
					for(int v=0; v<n; v++)
					{
						if(matrix[u][v]==1)
						{
							status=1;
							break;
						}
					}
					if(status==0)
					{
						arr[u]=0;
					}
				}
			}
			p=list;
			while(p->nxt!=NULL)
			{
				printf("%d ",(p->v)+1);
				p=p->nxt;
			}
			printf("%d ",(p->v)+1);
			printf("\n");
		}
	}
}

