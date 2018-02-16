#include <iostream>
#include "node.h"

using namespace std;

int main()
{
    node *head = new node(4, nullptr); //creates a head pointer pointing to a new node with data of 4 pointing to null
    node *tail(head); //creates a tail pointer equal to the head pointer
    node *temp; //creates an empty temp pointer

    temp = new node(1, nullptr); //sets the temp pointer pointing to a new node with data of 1 pointing to null
    tail->set_link(temp); //sets the tail pointer link pointing to temp pointer
    tail = temp; //sets the tail pointer equal to the temp pointer

    head = new node(1, head); //sets the head pointer to a new node with data of 1 pointing to the old head
    head = new node(3, head); //sets the head pointer to a new node with data of 3 pointing to the old head

    temp = new node(5, nullptr); //sets the temp pointer to a new node with data of 5 pointing to null
    tail->set_link(temp); //sets the tail pointer pointing to the last node in the linked list
    tail = temp; //sets the tail pointer equal to the temp pointer

    for (node *p = head; p != nullptr; p = p->link()) //for loop that loops through the links of the linked list
        cout << p->data() << " "; //prints out data of linked list

    cout << endl; //endline after the printed linked list

    return 0;
}
