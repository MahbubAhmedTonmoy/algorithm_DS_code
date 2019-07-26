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
void Delete_a_node()
{
    struct node *temp;
    int location;
    cout << "enter a location you want to delete : ";
    cin >> location;
    int len = length_of_linked_list();
    if(location>len) cout << "out of linked list"<<endl;
    else if (location == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node *p = root,*q;
        int i=1;
        while(i<location-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);

    }
}
void Delete_a_element()
{
    int ele;
    cout << "enter a element you want to delete : ";
    cin >> ele;

    struct node *temp=root,*q;
    while(temp->link->data != ele){
        temp = temp->link;
    }
    q = temp->link;
    temp->link = q->link;
    q->link = NULL;
    free(q);

}
int main()
{
    //node *n;
    add_element_last();
    add_element_last();add_element_last();add_element_last();add_element_last();

    print_linked_list();
    //Delete_a_node();
    Delete_a_element();
    print_linked_list();
    printf("\nlength : %d ",length_of_linked_list());
}
