// this is the linked list class header file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
	private:
		struct ListNode
		{
			double value;           	//value node
			struct ListNode *next;  	//pointer to next node
		}; 

		ListNode *head;		//list head pointer
		ListNode *tail;		//list tail pointer

	public:
		//constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (deallocates all nodes)
		~LinkedList();
};

#endif
