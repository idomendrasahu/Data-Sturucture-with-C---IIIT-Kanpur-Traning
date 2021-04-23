#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct linklist
{
	int num;
	struct linklist *previous;
	struct linklist *next;
};

struct linklist *start;
//start->previous=null;

void insert();
void display();
void del();
void edit();
void count();
void sort();
void reverse();
void exit();
void atbeg();
void atbeg1();
void atend();
void atend1();
void before();
void before1();
void after();
void after1();
void atpos();
void atpos1();
int length();

int length()
{
    struct linklist *temp;
    temp = start;
    int len = 0;
    while(temp!= NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void atbeg()
{
	struct linklist *temp,*node;
	node =(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n enter a no.");
	scanf("%d",&node->num);
	node->next=NULL;
    node->previous = NULL;
	if(start==NULL)
	{
		start=node;
		return;
	}
	else
	{
		temp=start;
		start=node;
		node->previous = NULL;
		node->next=temp;
		temp->previous = node;
	}
}
void atend ( )
{

	struct linklist *temp,*node;
	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node : ");
	scanf("%d",&node->num);
	node->previous = NULL;
	node->next = NULL;
	if(start==NULL)
	{
		start=node;

		return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next; //temp is last node
	}
	node->next = temp->next;
	temp->next->previous = node;
		temp->next=node;
		node->previous = temp;
}

void before( )
{
	int val;
	struct linklist *temp,*temp1,*node;

	printf("\n before which node u want to insert = ");
	scanf("%d",&val);

	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node");
	scanf("%d",&node->num);
	node->next = NULL;

	temp=start;
	while(temp->num != val)
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next=node;
	node->next=temp;
	node->previous = temp->previous;
	// node->previous = temp1;
	temp->previous = node;
}

void after( )
{
	int val;
	struct linklist *temp,*temp1,*node;
	printf("\n after which node u want to insert = ");
	scanf("%d",&val);

	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node :");
	scanf("%d",&node->num);
	node->next =NULL;

	temp=start;
	while(temp->num != val )
	{
	//	temp1=temp;
		temp=temp->next;
	}
//	temp1 = temp;
	node->next=temp->next;
	temp->next->previous = node;
	temp->next=node;
	node->previous = temp;
}

void atpos( )
{
	int i=1,c=0,n;
	struct linklist *temp,*temp1,*node;
	printf("enter the position no=");
	scanf("%d",&n);


	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n enter the data of node : ");
	scanf("%d",&node->num);
	node->next = NULL;
	node->previous=NULL;

	temp=start;

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	if (n>c)
	{
		printf("\n Not valid ");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i+1;
		temp1=temp;
		temp=temp->next;
	}
	temp->next->previous = node;
	node->next = temp->next;
	temp->next = node;
	node->previous = temp;

	/*
	temp1->next=node;
	node->previous = temp1;
	node->next=temp->next;
	temp->next = node;
	node->previous = temp;
	//temp->previous = node;*/
}

void atbeg1(){

	struct linklist *temp;

	temp=start;


	start->next->previous = NULL;
	start=start->next;


	temp->next = NULL;
	temp->previous=NULL;

	free(temp);


}
void atend1( )

	{
		struct linklist *temp,*temp1;
		temp = start;
		while(temp->next!=NULL)
			{
				temp1=temp;
				temp=temp->next; //temp is last node
			}

			temp1->next=NULL;
			temp1->previous = NULL;

			free(temp);
	}

	void before1( )
{
	int i;
	struct linklist *temp,*temp1,*temp2;
	printf("\n Before which node u want to delete = ");
	scanf("%d",&i);
	temp=start;
	temp1=temp->next;
	temp2=temp1->next;

	while(temp2->num !=i)
	{
		temp=temp->next;
		temp1=temp->next;
		temp2=temp1->next;
	}
	temp->next=temp2;
	temp2->previous = temp;
	temp1->next=NULL;
	temp1->previous = NULL;
	free(temp1);
}

void after1( )
{
	int i;
	struct linklist *temp,*temp1,*temp2;
	printf("\n Before which node u want to delete = ");
	scanf("%d",&i);
	temp=start;
	temp1=temp->next;
	temp2=temp1->next;

	while(temp->num !=i)
	{
		temp=temp->next;
		temp1=temp->next;
		temp2=temp1->next;
	}
	temp->next=temp2;
	temp2->previous = temp;

	temp1->next=NULL;
	temp1->previous=NULL;

	free(temp1);
}
	//dispaly the link list
void display( )
	{
		struct linklist *temp;
		temp = start;
		if(temp == NULL)
		{
		    printf("List is empty\n");
		}
		else
		{
        while(temp!=NULL)
		{
		printf("%d-->",temp->num);
		temp=temp->next;
		}
		}

	}
void atpos1( )
{
	int i=1,c=0,n;
	struct linklist *temp,*temp1;
	printf("enter the position no=");
	scanf("%d",&n);

	temp=start;

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	if (n>c)
	{
		printf("\n Not valid ");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i+1;
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=temp->next;
	temp->next->previous = temp1;
	temp->previous = NULL;
	temp->next=NULL;
	free(temp);
}

void del( )
{
	int ch3;
	char choice3;

	do
	{
		printf("\n 1. ATBEG 	");
		printf("\n 2. ATEND 	");
		printf("\n 3. BEFORE 	");
		printf("\n 4. AFTER      ");
		printf("\n 5. ATPOST   ");
		printf("\n 6. EXIT         ");

		printf("\n\n Enter Your Choice = ");
		scanf("%d",&ch3);

		switch(ch3)
		{
			case 1:
				atbeg1( );
				break;
			case 2:
				atend1( );
				break;
			case 3:
				before1( );
				break;
			case 4:
				after1( );
				break;
			case 5:
				atpos1( );
				break;
			case 6:
				choice3='n';
				break;
			default:
				printf("\n\n INVALID CHOICE ");
			}
		}while(choice3=='y');
}

void count()
 {

	int count=0;

	struct linklist *temp;

	temp=start;

	while (temp!=NULL)
{
	count=count+1;

	temp=temp->next;
}

	printf("\n\n the total nodes = %d", count);
}

void edit ( )
{
	int i=1,count=0,pos,num1;
	struct linklist *temp;
	printf("\n enter the position of node for edit =");
	scanf("%d",&pos);

	printf("\n\n enter the data of new node :");
	scanf("%d",&num1);

	temp=start;

	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}

	if(pos>count)
	{
		printf("\n Not valid");
		return;
	}

	temp=start;

	while(i<pos)
	{
		i=i+1;
		temp=temp->next;
	}
	temp->num=num1;
}

// sorting of the link list //
void sort( )
{
	int n;
	struct linklist *temp,*temp1;
	temp=start;
	while(temp==start)
	while(temp!=NULL)
	{
		temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->num>temp1->num)
			{

				n=temp->num;
				temp->num=temp1->num;
				temp1->num=n;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}
}

void reverse()
	{

		struct linklist *ptr,*temp,*old;
		temp=start;
		ptr=NULL;
		while(temp!=NULL)
		{
			old = ptr;
			ptr = temp;
			temp=temp->next;
			ptr->next= old;
			ptr->previous = temp;
		}
		start = ptr;
	}



int main ( )
{
	int ch1;
	char choice1='y';
	start=NULL;
	system("cls");//to clean the screen

	do
	{
		printf ("\n 1. INSERT     ");
		printf ("\n 2. DISPLAY     ");
		printf ("\n 3. DELETE      ");
		printf ("\n 4. EDIT        ");
		printf ("\n 5. COUNT NODES ");
		printf ("\n 6. SORTING      ");
		printf ("\n 7. REVERSE     ");
		printf ("\n 8. EXIT        ");

		printf ("\n\n Enter Your Choice = ");
		scanf("%d",&ch1);

		switch (ch1)
		{
			case 1:
				insert ( );
				break;

			case 2:
				display ( );
				break;
			case 3:
				del ( );
				break;
			case 4:
				edit ( );
				break;
			case 5:
				count ( );
				break;
			case 6:
				sort();
				break;
			case 7:
				reverse ( );
				break;
			case 8:
				choice1='n';
				break;
			default:
				printf ("invalid choice");
		}
	} while (choice1== 'y');
	return 0;
}	// end of main //
void insert ( )
{
	int ch2;
	char choice2;

	do
	{
		printf ("\n 1. ATBEG ") ;
		printf ("\n 2. ATEND")  ;
		printf ("\n 3. BEFORE") ;
		printf ("\n 4. AFTER ")	 ;
		printf ("\n 5. ATPOSI")  ;
		printf ("\n 6. EXIT      ")  ;

		printf ("\n\n Enyer Your Choice = ") ;
		scanf ("%d",& ch2);

		switch(ch2)
		{
			case 1:
				atbeg ( );
				break;
			case 2:
			  	atend ( );
				break;
			case 3:
		    	before ( );
				break;
			case 4:
				after ( );
				break;
			case 5:
				atpos ( );
				break;
			case 6:
		    	choice2='n';
				break;
			befault:
				printf("INVALID CHOICE");
		}
	}while(choice2=='y');
	}
