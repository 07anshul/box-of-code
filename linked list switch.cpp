#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
};

void insert_the_list(node* *head, int &x)
{
    node* block = new node();
    node* head_block = *head;

    if(*head == nullptr)
    {
        block -> data = x;
        block -> next = nullptr;
        *head = block;
    }
    else
    {
        block -> data = x;
        while(head_block -> next != nullptr)
              head_block = head_block -> next;
        head_block -> next = block;
        block -> next = nullptr;
    }
}
void insert_at_position(node* *head, int &x, int &pos)
{
    int node_number = 0;
    node* block = new node();
    node* head_block = *head;
    if(*head == nullptr)
    {
        if(pos == 1)
        {
            block -> data = x;
                 block -> next = nullptr;
                 *head = block;
        }
        else if(pos >1)
        {
            cout << "LIST IS EMPTY. DO YOU WANT TO INSERT THE DATA AT FIRST NODE?\n\t1. IF YES, ENTER '1' \n\t2. IF NO, ENTER '0' AND EXIT THE LIST\n ENTER CHOICE : ";
            int choice;
            cin >> choice;
            if(choice == 1)
            {
                 block -> data = x;
                 block -> next = nullptr;
                 *head = block;
            }
            else
            {
                cout << "\n\tNO DATA IS BEEN ENTERED. LIST IS EMPTY";
                return;

            }
        }
    }
    else if(pos ==1)
    {
        block -> data = x;
        block -> next = *head;
        *head = block;
    }
    else if(pos >1)
    {
        for(int i = 1; i <= pos -2; i++)
        {
            node_number++;
        head_block = head_block -> next;
            if(head_block -> next == nullptr)
            {
                cout << "POSITION IS GREATER THAN THE NUMBER OF NODES. DO YOU WANT TO INSERT THIS DATA AT THE END OF THIS LIST?\n\t1. IF YES, ENTER '1' \n\t2. IF NO, ENTER '0'\n ENTER CHOICE : ";
                int c;
                cin >> c;
                if(c == 1)
                {
                 insert_the_list(&head_block, x);
                 return;
                }
                else
                {
                    cout << "\n\tNO DATA IS BEEN ENTERED.";
                    return;
                }
            }
        }
        block -> data = x;
        block -> next = head_block -> next;
        head_block -> next = block;
    }
}


void search_the_list(node* head_block, int &s)
{
    int node_number = 0;
    while(1)
    {
        node_number++;
        if(head_block -> data == s)
        {
            cout << "\n\tDATA IS PRESENT AT NODE NUMBER " << node_number;
            break;
        }
        if(head_block -> next == nullptr)
        {
            cout << "\n\tDATA IS NOT PRESENT IN THE LIST";
            break;
        }
        head_block = head_block -> next;
    }
}

void delete_node(node* *head, int &pos)
{
    node* head_block = *head;
    for(int i = 1; i <= pos -2; i++)
    {
        head_block = head_block -> next;
    }
    node* node_to_be_deleted = head_block -> next;
    head_block -> next = node_to_be_deleted -> next;
    delete(node_to_be_deleted);
    cout << "\n\tNODE IS SUCCESSFULLY DELETED";
}

void reverse_list(node* *head)
{
    node* prev = nullptr;
    node* next_node = nullptr;
    node* current = *head;

    while(current != nullptr)
    {
        next_node = current -> next;
        current -> next = prev;
        prev = current;
        current = next_node;
    }
    *head = prev;

}
void print(node* head)
{
    cout << "\n";
    while(head != nullptr)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << "\n";
}
int main()
{
    int mode, data, pos, s;
    node* head = nullptr;

    cout << "EDIT LINKED LIST\n";
    cout << "\n\t1. INSERT \n\t2. INSERT AT A PARTICULAR POSITION \n\t3. DELETE \n\t4. SEARCH \n\t5. REVERSE \n\t6. PRINT \n\t7. END EDITING\n";
    do
    {
        cout << "\nENTER MODE : ";
        cin >> mode;
        switch(mode)
        {
        case 1:
            cout << "\nENTER DATA : ";
            cin >> data;
            insert_the_list(&head, data);
            break;
        case 2:
            cout << "\nENTER DATA : ";
            cin >> data;
            cout << "\nENTER POSITION : ";
            cin >> pos;
            insert_at_position(&head, data, pos);
            break;
        case 3:
            cout << "\nENTER POSITION TO BE DLETED: ";
            cin >> pos;
            delete_node(&head, pos);
            break;
        case 4:
            cout << "\nENTER DATA TO SEARCH : ";
            cin >> s;
            search_the_list(head, s);
            break;
        case 5:
            reverse_list(&head);
            break;
        case 6:
            print(head);
            break;
        case 7:
            cout << "\n\tLIST SUCCESSFULLY EDITED\n";
            break;
        default:
            cout << "\n\n\tNOT A VALID MODE\n";
        }
    }
    while(mode != 7);
}
