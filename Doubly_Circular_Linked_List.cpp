// Doubly Circular Linked list
// SAJAL BRAHMA - 21BPS1045

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
}*head,*temp,*newnode,*dnode;

void insert_beg(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->left=head;
		newnode->right=head;
	}
	else
	{
		temp=head;
		while(temp->right!=head)
		{
			temp=temp->right;
		}
		newnode->right=head;
		newnode->left=temp;
		temp->right=newnode;
		head->left=newnode;
		head=newnode;
	}
}

void insert_mid(int value,int val)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->left=head;
		newnode->right=head;
	}
	else
	{
		temp=head;
		while(temp->data!=val)
		{
			temp=temp->right;
		}
		newnode->right=temp->right;
		newnode->left=temp;
		temp->right->left=newnode;
		temp->right=newnode;
	}
}

void insert_end(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->left=head;
		newnode->right=head;
	}
	else
	{
		temp=head;
		while(temp->right!=head)
		{
			temp=temp->right;
		}
		newnode->right=head;
		newnode->left=temp;
		temp->right=newnode;
		head->left=newnode;
		temp=newnode;
	}
}

void delete_beg()
{
	if(head==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		if(head->right==head)
		{
			dnode=head;
			head=NULL;
			free(dnode);	
		}
		else
		{
			temp=head;
			while(temp->right!=head)
			{
				temp=temp->right;
			}
			temp->right=head->right;
			head->right->left=temp;
			dnode=head;
			head=head->right;
			free(dnode);
		}
	}
}

void delete_mid(int val)
{
	if(head==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		if(head->right==head)
		{
			dnode=head;
			head=NULL;
			free(dnode);
		}
		else
		{
			temp=head;
			while(temp->right!=head)
			{
				if(temp->data==val)
				{
					temp->left->right=temp->right;
					temp->right->left=temp->left;
					dnode=temp;
					free(dnode);
					return ;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
	}
}

void delete_end()
{
	if(head==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		if(head->right==head)
		{
			dnode=head;
			head=NULL;
			free(dnode);
		}
		else
		{
			temp=head;
			while(temp->right!=head)
			{
				temp=temp->right;
			}
			temp->left->right=head;      //temp->left=prev
			head->left=temp->left;
			dnode=temp;
			free(dnode);
		}
	}
}

void display()
{
	if(head==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		temp=head;
		while(temp->right!=head)
		{
			printf("%d ",temp->data);
			temp=temp->right;
		}
		printf("%d.",temp->data);
	}
}

void search(int val)
{
	temp=head;
	int flag=0;
	while(temp->right!=head)
	{
		if(temp->data==val)
		{
			flag=1;
			printf("\nFound");
			break;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(temp->data==val)
	{
		flag=1;
		printf("\nFound");
	}
	if(flag==0)
	{
		printf("\nNot Found.");
	}
}

int main()
{
	int ch,num,element,element1,element2,val1,element3,val2,val3;
	do
	{
		printf("\n1. Create a list.");
		printf("\n2. Insert an element in the beginning of the list.");
		printf("\n3. Insert an element in the middle of the list.");
		printf("\n4. Insert an element in the end of the list.");
		printf("\n5. Delete an element in the beginning of the list.");
                printf("\n6. Delete an element in the middle of the list.");
                printf("\n7. Delete an element in the end of the list.");
                printf("\n8. Display the list elements :- ");
                printf("\n9. Search for element in the list.");
                printf("\n10. Exit.");
                printf("\nEnter your choice :- ");
                scanf("%d",&ch);
                switch(ch)
                {
        	       case 1: printf("\nEnter the number of elements to be inserted in the list :- ");
        	               scanf("%d",&num);
        	               for(int i=0;i<num;i++)
        	               {
        	        	      scanf("%d",&element);
        	        	      insert_end(element);
				}
				printf("\nList elements after creation of list :- ");
				display();
				break;
					
			case 2: printf("\nEnter the element to be inserted in the beginning of the list :- ");
			        scanf("%d",&element1);
			        insert_beg(element1);
			        printf("\nList elements after insertion of element in the beginning of the list :- ");
			        display();
			        break;
			        
			case 3: printf("\nEnter the element to be inserted in the middle of the list :- ");
			        scanf("%d",&element2);
			        printf("\nEnter the element after which its to be inserted :- ");
			        scanf("%d",&val1);
			        insert_mid(element2,val1);
			        printf("\nList elements after insertion of element in the middle of the list :- ");
			        display();
			        break;
			        
			case 4: printf("\nEnter the element to be inserted in the end of the list. :- ");
			        scanf("%d",&element3);
			        insert_end(element3);
			        printf("\nList elements after insertion of element in the end of the list :- ");
			        display();
			        break;
			        
			case 5: delete_beg();
			        printf("\nList elements after deletion of first element from the list :- ");
				display();
				break;
					
			case 6: printf("\nEnter the data to be deleted from the list :- ");
			        scanf("%d",&val2);
			        delete_mid(val2);
			        printf("\nList elements after deletion of middle element from the list :- ");
				display();
				break;
					
			case 7: delete_end();
			        printf("\nList elements after deletion of last element from the list :- ");
				display();
				break;
				
			case 8: printf("\nList elements :- ");
			        display();
			        break;
			        
			case 9: printf("\nEnter the element to be searched in the list :- ");
			        scanf("%d",&val3);
			        search(val3);
			        break;
			        
			case 10:exit(0);
			        break;
			        
			default:printf("\nWrong choice.");
			        break;
		}
	}while(ch>=1 || ch<=10);
	return 0; 
}

// Input -> 1 -> 1 2 3 4 5
// Input -> 2 -> 0 -> 0 1 2 3 4 5
// Input -> 3 -> 7,3 -> 0 1 2 3 7 4 5 
// Input -> 4 -> 6 -> 0 1 2 3 7 4 5 6
// Input -> 5 -> 1 2 3 7 4 5 6
// Input -> 6 -> 7 -> 1 2 3 4 5 6
// Input -> 7 -> 1 2 3 4 5
// Input -> 8 -> 1 2 3 4 5
// Input -> 9 -> 3 -> Found
