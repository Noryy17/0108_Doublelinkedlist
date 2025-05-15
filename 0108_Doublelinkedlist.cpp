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

