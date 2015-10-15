#ifndef List_H
#define List_H
template <class T>
#include <iostream>
#include <string>
#include <cstdlib>

//#include "ListOfAny.h"
using namespace std;
// Specification file for the Linked List class
#ifndef LISTOFANY_H
#define LISTOFANY_H
#include <cstdlib>
struct Person{
    string name;
    int inches;
};

class ListOfAny
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        Person data;           // The value in this node
        struct ListNode *next;  // To point to the next node
    };
    
    ListNode *head;            // List head pointer
    
public:
    // Constructor
    ListOfAny()
    {
        head = NULL;
    }
    
    // Destructor
    ~ListOfAny();
    
    // Linked list operations
    void appendNode(Person);
    void insertNode(Person);
    bool deleteNode(string);
    void displayList() const;
    int countNodes();
};
#endif
ListOfAny::~ListOfAny()
{
    ListNode* nodeptr;
    nodeptr = head;
    ListNode* nextnode = NULL;
    while (nodeptr)
    {
        nextnode = nodeptr -> next;
        cout << "Destroy: " << nodeptr->data.name << endl;
        delete nodeptr;
        nodeptr = nextnode;
    
    }
    head = NULL;
}
// This program demonstrates the displayList member function.
void ListOfAny::appendNode(Person num)
{
    ListNode *newNode;  // To point to a new node
    ListNode *nodePtr;  // To move through the list
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->data.name = num.name;
    newNode->data.inches = num.inches;
    newNode->next = NULL;
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
        head = newNode;
    else  // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;
        
        // Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        
        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}
void ListOfAny::displayList() const
{
    ListNode* nodeptr;
    nodeptr = head;
    while (nodeptr){
        cout << nodeptr->data.name << "  " << nodeptr->data.inches << endl;
        nodeptr = nodeptr->next;
    }
    return;
}

int ListOfAny::countNodes()
{
    int count = 0;
    ListNode* nodeptr; // like int i;
    nodeptr = head; // i = 0
    
    while(nodeptr)
    {
        count++;
        nodeptr = nodeptr -> next;//i++ for an array
    
    }
    return count;
}
void ListOfAny::insertNode(Person added)
{
    ListNode* nodeptr = head;
    ListNode* newnode;
    ListNode* prevnode = NULL;
    
    newnode = new ListNode; // getting memory for our new node
    newnode -> data = added;
    newnode ->next = NULL;
    if (head == NULL) // case of empty list
    {
        head = newnode;
        head -> next = NULL;
        return;
    }
    
    while (nodeptr != NULL && nodeptr -> data.inches < added.inches)
        // Walking through to find the right place
    {
        prevnode = nodeptr;
        nodeptr = nodeptr -> next;
    }
    
    if(prevnode == NULL) // it is the next head
    {
        head = newnode;
        newnode-> next = nodeptr;
    }
    
    else // middle or end of list
    {
    prevnode->next = newnode;
    newnode -> next = nodeptr;
    }
    return;
}

bool ListOfAny::deleteNode(string who)
{
    bool found = false;
    
    ListNode* nodeptr = head;
    ListNode* prevnode = NULL;
    
    if ( !head) // empty list
        return false;
    
    if(head->data.name == who) //delete head node
    {
        nodeptr= head->next;
        delete head;
        head = nodeptr; // saving the new head
        found = true;
    
    }
    else
    {
        while(nodeptr != NULL && nodeptr-> data.name != who)
        {
            prevnode = nodeptr;
            nodeptr = nodeptr -> next;
            
        
        }
        if(nodeptr)
        {
            prevnode->next = nodeptr -> next;
            delete nodeptr;
            found = true;
        
        }
    
    }

    return found;
}
