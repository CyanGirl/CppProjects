#include<iostream>
using namespace std;

template <class T>
struct node
{
	node<T> *prev;
	T data;
	node<T> *next;
};

template <class T>
class DList
{
	private:
		node<T> *head, *tail;
	public:
		DList()
		{
			head=NULL;
			tail=NULL;
		}
		~DList()
		{
		}
		void createnode(T value)
		{
			node<T> *temp= new node<T>;
			temp->data=value;
			temp->next=NULL;
			temp->prev=NULL;
			if(head==NULL && tail==NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				temp->prev=tail;
				tail->next=temp;
				tail=temp;
			}
			cout<<endl<<"Node has been inserted successfully"<<endl;
		}
		int insertAtPos(T data, T pos)
		{
			node<T> *temp=new node<T>;
			node<T> *pre=new node<T>;
			node<T> *cur=new node<T>;
			cur->data=data;
			int i=0;
			temp=head;
			while(i!=(pos-1) && temp->next!=NULL)
			{
				temp=temp->next;
				i=i+1;
			}
			if(i==(pos-1))
			{
				pre=temp->prev;
				pre->next=cur;
				temp->prev=cur;
				cur->prev=pre;
				cur->next=temp;
				cout<<endl<<"Node has been inserted successfully"<<endl;
				return 1;
			}
			else
			{
				cout<<endl<<"You entered an invalid position!"<<endl;
				return 0;
			}
		}
		int insertAtBeg(T data)
		{
			node<T> *temp=new node<T>;
			node<T> *cur=new node<T>;
			temp->data=data;
			if(head==NULL && tail==NULL)
			{
				temp->next=NULL;
				temp->prev=NULL;
				head=temp;
				tail=temp;
			}
			else
			{
				cur=head;
				cur->prev=temp;
				temp->next=cur;
				temp->prev=NULL;
				head=temp;
			}
			cout<<endl<<"Node has been inserted successfully!"<<endl;
		}
		void display()
		{
			node<T> *temp=new node<T>;
			temp=head;
			cout<<endl<<"The list created is  "<<endl;
			while(temp!=NULL)
			{
				cout<<temp->data<<"     ";
				temp=temp->next;
			}
		}
		void deleteNode(T item)
		{
			int flag=0;
			node<T> *pre=new node<T>;
			node<T> *temp=new node<T>;
			node<T> *nxt=new node<T>;
			temp=head;
			while(temp!=NULL)
			{
				if(temp->data==item)
				{	
					pre=temp->prev;
					flag=1;
					nxt=temp->next;
					break;
				}
				else
				{
					temp=temp->next;
					
				}
			}
			
			if(flag==1)
			{
				if(temp->next!=NULL)
				{
				pre->next=temp->next;
				nxt->prev=temp->prev;
				}
				else
				{
					pre->next=NULL;
				}
				delete(temp);
				cout<<endl<<"Deleted successfully!"<<endl;
			}
		}
		void reverse()
		{
			node<T> *temp=new node<T>;
			node<T> *current=new node<T>; 
			temp=NULL;
			current=head;  
     		while (current !=  NULL) 
    		 { 
       			temp = current->prev; 
      			current->prev = current->next; 
       			current->next = temp;               
       			current = current->prev; 
     		}       
     		if(temp != NULL ) 
        	head= temp->prev; 
        	cout<<endl<<"The list has been successfully reversed!"<<endl;
		}
};


int main()
{
	DList <int> obj;
	char choice1='Y';
	int choice2,i=0,item,data,flag=0;
	char choice3;
	while(choice1=='Y' || choice1=='y')
	{
		cout<<endl<<"-----------Enter your choice:----------"<<endl<<endl;
		cout<<"1. For creating node "<<endl;
		cout<<"2.For deleting an existing node: "<<endl;
		cout<<"3. For reversing the list:  "<<endl;
		cout<<"4. For displaying the list "<<endl;
		fflush(stdin);
		cin>>choice2;
		if(choice2==1)
		{
			cout<<endl<<"Enter the value of the node:    ";
			fflush(stdin);
			cin>>item;
			cout<<endl<<endl<<"Enter a for inserting at the end: "<<endl;
			cout<<"Enter b for inserting at position:  "<<endl;
			cout<<"Enter c for inserting at the beginning:  "<<endl;
			fflush(stdin);
			cin>>choice3;
			if(choice3=='a')
			{
				obj.createnode(item);
				i++;
			}
			else if(choice3=='b')
			{
				if(i==0)
				{
					cout<<endl<<"There is no list yet!";
				}
				else
				{
				cout<<"Enter the position where it has to be inserted:   ";
				fflush(stdin);
				cin>>data;
				flag=obj.insertAtPos(item,data);
				if(flag==1)
				i++;
				}
			}
			else if(choice3=='c')
			{
					obj.insertAtBeg(item);
					i++;
			}
			else
			{
				cout<<endl<<"Wrong choice!"<<endl;
			}
		}
		else if(choice2==2)
		{
			cout<<endl<<"Enter the data which is to be deleted:  ";
			fflush(stdin);
			cin>>item;
			obj.deleteNode(item);
		}
		else if(choice2==3)
		{
			if(i==0)
			{
				cout<<endl<<"There is empty list!"<<endl;
			}
			else
			obj.reverse();
		}
		else if(choice2==4)
		{
			if(i==0)
			{
				cout<<endl<<"Empty list!"<<endl;
			}
			else
			{
				obj.display();
			}
		
		}
		cout<<endl<<"Do you want to continue?(Y/N):  ";
		fflush(stdin);
		cin>>choice1;
	}
	return 0;
}