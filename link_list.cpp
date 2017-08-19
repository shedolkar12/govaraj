#include<iostream>
using namespace std;
class Node
{
public:
	Node* next;
	int data;
Node()
{
	cout<<"created node\n"<<endl;
}
~Node()
{cout<<"deleted node";}

};
class link_list
{
public:
	Node* Header;
	link_list()
	{
		Header=NULL;
		cout<<"Header is created"<<endl;

	}
	void add_node(int data);
	void display();
	bool search(int n);
	bool deleted(int n);
	int length_list(Node*temp);
	~link_list()
	{
		cout<<"deleted"<<endl;
	}

};
int link_list::length_list(Node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	return 1+length_list(temp->next);
}


bool link_list::deleted(int n)
{
	Node *temp=Header;
	Node* previos=Header;
	if(temp!=NULL && (Header->data==n))
	{
		Header=Header->next;
		delete temp;
		return true;
	}

	while(temp)
	{
		if (temp->data==n)
		{
			previos->next=temp->next;
			delete temp;
			return true;
		}
		previos=temp;
		temp=temp->next;
	}
return false;
}
bool link_list::search(int n)
{
	Node *temp=Header;
	while(temp)
	{
	if (temp->data==n)
	{

		return true;
	}
	temp=temp->next;
	}
	return false;


}
void link_list::add_node(int data)
{
	Node* n=new (Node);
	if (n==NULL)
	{
		cout<<"memory is not allocated"<<endl;
	}
	n->next=Header;
	n->data=data;
	Header=n;

}
void link_list::display()
{
	Node* temp=Header;
	while(temp)
	{
		cout<<"element: "<<temp->data<<endl;
		temp=temp->next;

	}

}


int main(int argc, char const *argv[])
{
link_list List;
int C;
while(true)
{
	cout<<"\n1) add node"<<"\n2) display"<<"\n3)search"<<"\n4) delete "<<"\n5) length"<<"\n enter the choice"<<endl;
	cin>>C;
	switch(C)
	{
	case 5:
		Node *temp;
		temp=List.Header;
		cout<<"length of list :"<<List.length_list(temp)<<endl;
		break;
	case 4:
		int data1;
		cout<<"enter the data:";
		cin>>data1;
	
		if(List.deleted(data1))
		{
			cout<<"deleted item"<<endl;
		}
		else
		{
			cout<<"Not found the element"<<endl;
		}
		break;
	case 1:
		int data;
		cout<<"enter the data:\n"<<endl;

		cin>>data;
		List.add_node(data);
		break;
	case 2:
		cout<<"here is list"<<endl;
		List.display();
		break;
	case 3:
		cout<<"search data:";
		cin>>data;
		if (List.search(data)){
			cout<<"found"<<endl;

		}
		else
		{
			cout<<"not found"<<endl;

		}
		break;
	default:
		cout<<"hi this is default"<<endl;
	}
}
	return 0;
}