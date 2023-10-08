#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	int key;
	Node()
	{
		next = NULL;
		data = 0;
		key = 0;
	}
	Node(int key, int data)
	{
		this->key = key;
		this->data = data;
	}
	Node(int data)
	{
		this->data = data;
	}
	~Node()
	{
		delete next;
	}
};
class linkedList
{
public:
	Node *head;
	linkedList()
	{
		head = NULL;
	}
	linkedList(Node *head)
	{
		this->head = head;
	}
	Node *nodeExists(int key)
	{
		Node *temp = NULL;
		Node *ptr = head;

		while (ptr != NULL)
		{
			if (ptr->key == key)
			{
				temp = ptr;
				return temp;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		return temp;
	}

	void append(int key, int data)
	{
		Node *ptr = new Node(key, data);
		Node *temp = head;
		if (head == NULL)
		{
			head = ptr;
			ptr->next = NULL;
			cout << "Node added after head \n";
		}
		else
		{
			if (nodeExists(ptr->key) != NULL)
			{
				cout << "The node with" << ptr->key << " already exists";
				delete ptr;
			}
			else
			{
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = ptr;
				ptr->next = NULL;
				cout << "Node added in the end of list ";
				cout << ptr->data << "\n";
			}
		}
	}

	void prependNode(int key, int data)
	{
		Node *ptr = new Node(key, data);
		if (nodeExists(ptr->key) != NULL)
		{
			cout << "The node with" << ptr->key << " already exists";
			delete ptr;
		}
		else
		{
			if (head == NULL)
			{
				head = ptr;
				ptr->next = NULL;
				cout << "Node added after head \n";
			}
			else
			{
				ptr->next = head;
				head = ptr;
				cout << "Node added in the end \n";
			}
		}
	}
	void insertAfterNode(int key, int key1, int data)
	{
		Node *ptr = nodeExists(key1);
		Node *newNode = new Node(key, data);

		if (ptr == NULL)
		{
			cout << "No node exists with this key";
			delete newNode;
		}
		else
		{
			if (nodeExists(key) != NULL)
			{
				cout << "This key already exists! Enter a new key";
				delete newNode;
			}
			else
			{
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}
	}
	void deleteNode(int key)
	{
		Node *temp = head;
		Node *ptr = nodeExists(key);
		while (temp->next->key != key)
		{
			temp = temp->next;
		}
		temp->next = ptr->next;
		ptr = NULL;
		delete ptr;
		cout << "Node deleted succesfully!";
	}
	// void modifiedList(int data,){
	//
	// }
	void print()
	{
		for (Node *current = head; current != NULL; current = current->next)
		{
			cout << current->data << "\n";
		}
	}


	void evenOdd()
	{
		Node *temp = head;
		Node *ptr = new Node();
		while (temp != NULL)
		{
			if (temp->data % 2 == 0 && temp->next->data % 2 != 0)
			{
				ptr = temp;
			}
		}
		while (temp->next->data % 2 != 0)
		{
			if (temp->data % 2 == 0)
			{
				ptr->next = temp;
				temp = ptr->next;
			}
		}
		if (head->data % 2 != 0)
		{
			while (temp->next != NULL)
			{
				if (temp->next->data % 2 == 0)
				{
					ptr = temp->next;
					ptr->next = head;
					head = ptr;
				}
				temp=temp->next;
			}
		}
		if (head->data % 2 == 0)
		{
			while (temp != NULL)
			{
				if (temp->data % 2 != 0 && temp->next->data % 2 == 0)
				{
					ptr = temp->next;
					ptr->next = head->next;
					head->next = ptr;
				}
			}
		}
	}
};
int main()
{
	Node *one = new Node(1, 1);
	linkedList l = linkedList();
	Node *two = new Node(2, 2);
	//	Node* three= new Node(3,3);
	//	Node* four= new Node(4);
	//	Node* five= new Node(5);
	//
	l.append(1, 1);
	l.append(2, 2);
	l.append(3, 3);
	l.append(4, 4);
	//    l.prependNode(5,5);
	//	l.prependNode(3,4);
	//	l.prependNode(two,2);
	//	l.prependNode(three,3);

	l.print();
	cout << endl;
	l.deleteNode(2);
}