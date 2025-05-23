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

        // Inssert last mode
        if(current->next != NULL)
        current->next->prev = newNode; //STEP 9c : current.next
        current->next = newNode; //STEP 9d : current.next = newNode
    }

    void hapus(){
     if(START == NULL){
        cout << "\nList is Empty" << endl;
        return;
     }
     cout << "\nEnter the roll number of the student whose record is to be deleted";
     int rollNo;
     cin >> rollNo;

     Node *current = START;

     //Step 1 : Tranverse the list to find the node
    while(current != NULL && current->noMhs != rollNo){
        current = current->next;
    }

    if (current == NULL){
        cout << "RECORD NOT FOUND" <<endl;
        return;
    }

    //STEP 2 : IF NODE IS AT THE BEGINNING
    if (current == START){
        START = current->next; // STEP 2a : START = START.next
        if (START != NULL){
           START->prev = NULL; // STEP 2b : START.prev = NULL
        }
    }
    else{
        //STEP 3 : LINK PREVIOUS NODE TO NEXT OF CURRENT
        current->prev->next = current->next;

        //STEP 4 : if current is not the last node
        if(current->next != NULL)
        current->next->prev = current->prev;
    }

    //STEP 5 : Delete the node
    delete current;
    cout << "RECORD With roll number" << rollNo << "Deleted" << endl;

    }

    void traverse(){
        if (START == NULL){
            cout << "\nList is Empty" << endl;
            return;
        }
        //Step 1 : MARK FIRST NODE AS CURRENTNODE
        Node *CurrentNode = START;

        //STEP 2 : REPEAT UNTIL CURRENTNODE == NULL
        cout << "/nRecord in ASCENDING ORDER OF ROLL NUMBER ARE:\n";
        int i = 0;
        while (CurrentNode != NULL){
            cout << i + 1 << ". " << CurrentNode->noMhs << " " << endl;

            //STEP 3 : MOVE TO NEXT NODE
            CurrentNode = CurrentNode->next;
            i++;
        }
    }

    void revtraverse(){
        if (START == NULL){
            cout << "\nList is Empty" << endl;
            return;
        }
        //Step 1 : Move to Last Node
        Node *currentNode  = START;
        int i=0;
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
            i++;
        } 
        //STEP 2 : TRAVERSE BACKWARD
        cout << "\nRecord In  Descending order of roll number are : \n";
        while (currentNode != NULL){
            cout << i + 1 << ". "<< currentNode->noMhs <<" "<< endl;

            //Step 3 : Move To Provesious node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData(){
        if (START == NULL){
            cout << "\nList is Empty" <<endl;
            return;
        }

        int rollNo;
        cout << "\nEnter The Roll number to search :";
        cin >> rollNo;

        Node *current = START;

        //STEP 1 : TRAVERSE TO FIND MATCHING ROLL NUMBER
        while (current != NULL && current->noMhs != rollNo)
        current= current->next;

        //Step 2 : Output Result 
        if (current == NULL){
            cout << "RECORD NOT FOUND\n";
        }
        else{
            cout << "Record Found\n";
            cout << "Roll Number : " << current->noMhs<<endl;
        }
    }


};

int main(){
    DoubleLinkedList List;
    char choice;

    do
{
    cout << "\nMenu:\n";
    cout << "1. Add Record\n";
    cout << "2. Delete Record\n";
    cout << "3. View Ascending\n";
    cout << "4. View Descending\n";
    cout << "5. Search Record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    switch (choice)
    {
        case '1':
            List.addNode();
            break;
        case '2':
            List.hapus();
            break;
        case '3':
            List.traverse();
            break;
        case '4':
            List.revtraverse();
            break;
        case '5':
            List.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
    system("clear");
} while (choice != '6');
}

