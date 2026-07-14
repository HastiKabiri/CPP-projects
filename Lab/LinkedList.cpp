// Hasti Kabiri TP085940

/*Question 1
Create a basic linked list node.
Write a C++ struct for a linked list node that stores an integer.
*/ 
struct ListNode {
    int value; // The integer value stored in the node
    ListNode* next; // Pointer to the next node in the linked list

    // Constructor to initialize the node with a value and set next to nullptr
    ListNode(int val) : value(val), next(nullptr) {}



/* Question 2
    
What’s being inserted?
Look at the code below: 

 Linked list is initially empty
insertAtHead(10);
insertAtHead(20);
insertAtHead(30);
printList();

What function is being called and what will the output be?
Function used: 

insertAtHead(int value) - This function is likely inserting a new node with the given value at the head of the linked list.
   
*/




/*
Question 3
What’s missing here?
You’re given this output:

40  20  10  NULL

But the only code you have is:
insertAtHead(10);
insertAtHead(20);
// ??? missing line
insertAtHead(40);
printList();

Fill in the missing line.






*/

