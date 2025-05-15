#include <iostream>
#include <string>
using namespace std;


class Node{
    public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList{
    private:
    Node *START;

    public:
    DoubleLinkedList(){
        START = NULL;
    }
    void addNode(){

        int nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim; 

        //Step 1 : Allow Cote Memory for new Code
        Node *newNode = new Node();

        //Step 2 : ASSIGN vallue to the data fields
        newNode->noMhs = nim;

        //step 3 : Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs){
            if (START != NULL && nim == START->noMhs){
            cout << "\nDuplicate Number Not Allowed"<<endl;
            return;
            }
            //step 4 : newNode.next = START
            newNode->next = START;
            //Step 5 : START.prev = newNode (if START exits)
            if (START != NULL)
            START->prev = newNode;

            //Step 6 : newNode.prev = NULL
            newNode->prev = NULL;

            //STEP 7 : START = NewNode
            START = newNode;
            return;
        }
        //Insert in between node
        //step 8 : Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim){
          current = current->next;
        }

        if(current -> next != NULL && nim == current->next->noMhs){
           cout << "\nDuplicate roll numbers not allowed" << endl;
           return;
        }

        //STEP 9 : Insert between current  and current->next
        newNode->next = current->next; //Step 9a : newNode.next = Current.next
        newNode->prev = current;       //Step 9b : newNode.prev = current



