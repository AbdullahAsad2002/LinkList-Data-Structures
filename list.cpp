#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void deleteNode(struct Node **head)
{
    if (*head == NULL)
    {
        cout << "Cannot Delete Node Because List is Empty!!!" << endl;
    }
    else
    {    
        struct Node *preNode;
        struct Node *del;
        del = *head;
        while (del->next != NULL)
        {
            preNode = del;
            del = del->next;
        }
        if (del == *head)
        {
            head = NULL;
        }
        else
        {
            preNode->next = NULL;
        }
        delete (del);
    }
}
void addNode(int d,struct Node**head)   
{   
    struct Node*th;
    struct Node *temp;
    temp = new struct Node();
    temp->data = d;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {        
        th = *head;
        while (th->next != NULL)
        {
            th = th->next;
        }
        th->next = temp;
    }
}              
void printList(struct Node **head)
{ 
    struct Node *print = *head;
    cout << "The current List is [  ";
    while (print != NULL)
    {
        cout << print->data << "  ";
        print = print->next;
    }
    cout << "]";
}
int main()
{   
    struct Node *head;
    head =NULL;
    string delChoice = "yes";
    int choice = 1;
    int data;
    while (choice == 1)
    {
        cout << "Enter data: ";
        cin >> data;
        addNode(data,&head);
        cout << "Do you want to Continue?? (for Yes = 1 , for No = 0) : ";
        cin >> choice;
    }
    printList(&head);
    cout<<endl;
    while (delChoice == "yes")
    {
        cout << "Do You Wanna delete last Node?? (yes OR no) :";
        cin >> delChoice;
        if (delChoice == "yes")
        {
            deleteNode(&head);
            cout << "Last Node has been Deleted!!" << endl;
        }
    }
    printList(&head);
    return 0;
}
//     41
//    /
//   51
//    \
//     31
