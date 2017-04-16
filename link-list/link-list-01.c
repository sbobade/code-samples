/*
* file: link-list-01.c
* 
* single link list program: condition when user enter -1 the list gets complete,
* as soon as list ends, this program prints it.
* TODO Solution1: with -1: exit condition, prepare next type where we can use -1 
* as well for node data. 
*
*/

#include<malloc.h>

struct node 
{
	int data;
	struct node *next;
};


struct node * create()
{	
	struct node *n, *t, *home=NULL;
	int i;

	while(1)
	{
		printf("\n Plz enter the Data in Node: \n");
		scanf("%d",&i);	

		if(i==-1)	
		break;

		n=(struct node *)malloc(sizeof(struct node));
		n->next=NULL;
		n->data=i;
	
		if(home==NULL){
			t=home=n;
		}
		else {
			t->next = n;
			t = n;	
		}
	}

	return home;
}


void disp(struct node *t)
{
	
	printf("\n Data in Link List is \n ");
		
	while(t) {
		printf("\n Data in Link list: %d \n",t->data);
		t=t->next;
	}
}


int main()
{
	struct node *home;
	
	home = create();
	disp(home);
}
