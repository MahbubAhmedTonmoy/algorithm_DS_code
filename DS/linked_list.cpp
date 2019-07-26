#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node *link;
};

struct node *root = NULL;/// create root node

void add_element_last()
{

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    cout << "enter an element : ";
    cin >> temp->data;
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else{
        struct node *select;
        select = root;
        while(select->link != NULL)
        {
            select = select->link;
        }
        select->link = temp;
    }
}

void print_linked_list()
{
    cout << "linked list : ";
    struct node *select;
    select = root;
    if(select == NULL) return;
    else{
        while(select != NULL)
        {
            cout << select->data<<" ";
            select= select->link;
        }
    }
}
int length_of_linked_list()
{
    int count = 0;
    struct node *select;
    select = root;
    while(select != NULL)
    {
        count++;
        select= select->link;
    }
    return count;
}
int main()
{
    //node *n;
    add_element_last();
    add_element_last();add_element_last();add_element_last();add_element_last();

    print_linked_list();
    printf("\nlength : %d ",length_of_linked_list());
}
