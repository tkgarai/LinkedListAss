#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int data;
struct node *next;
};

struct node * CreateLinkedList(int n);
void PrintList(struct node *head);
struct node *InsertAtPos(struct node *head,int pos, int data);
struct node *Delete_val(struct node *head,int val);
void remove_Duplicates(struct node **head);
int Length(struct node *head);
int Middle_element(struct node * head);
int maxElement(struct node * head);
float Average(struct node *head);
void sortLinkedList(struct node** head_ref);
void reverse(struct node** head_ref);

void main()
{
    int n;
    struct node *head;
    printf("Enter the number of datas for creating linked list:");
    scanf("%d",&n);
    printf("\nEnter %d data values(separated by comma): ", n);
    /*1. Create a linked list by inserting the following items/values sequentially.
Input: 4, 3, 8, 7, 8, 12, 9, 3, 81, 24, 4, 18, 8, 66, 39, 6, 3, 12
Output: 4->3->8->7->8->12->9->3->81->24->4->18->8->66->39->6->3->12*/
    head = CreateLinkedList(n);
    PrintList(head);
    /*2. Insert value 6 into the 6th position of the above linked list:
Input: 4->3->8->7->8->12->9->3->81->24->4->18->8->66->39->6->3->12
Output: 4->3->8->7->8->6->12->9->3->81->24->4->18->8->66->39->6->3->12*/
    printf("\n\nAfter inserting 6 at 6th postion: ");
    head=InsertAtPos(head, 6, 6);
    PrintList(head);
    /*3. Delete value 66 from the resultant linked list:
Input: 4->3->8->7->8->6->12->9->3->81->24->4->18->8->66->39->6->3->12
Output: 4->3->8->7->8->6->12->9->3->81->24->4->18->8->39->6->3->12*/
    printf("\n\nAfter deleting 66 from the list: ");
    head = Delete_val(head, 66);
    PrintList(head);
    /*4. Remove the duplicate elements present in the above unsorted resultant 
linked list
Input: 4->3->8->7->8->6->12->9->3->81->24->4->18->8->39->6->3->12
Output: 4->3->8->7->6->12->9->81->24->18->39*/
    printf("\n\nAfter deleting the duplicate elements: ");
    remove_Duplicates(&head);
    PrintList(head);
    /*5. Find the length, middle element, maximum element and average values of 
the above resultant linked list:
Input: 4->3->8->7->6->12->9->81->24->18->39
Output: Length: 11, Middle element: 12, Maximum element: 81, Average value= 
19.18181
*/
    printf("\nLength: %d, ",Length(head));
    printf("Middle element: %d, ",Middle_element(head));
    printf("Maximum element: %d, ",maxElement(head));
    printf("Average value= %f",Average(head));
    /*6. Sort the above resultant linked list: (Sorting function already given in the 
materials provided below; just append the function as it is.)
Input: 4->3->8->7->6->12->9->81->24->18->39
Output: 3->4->6->7->8->9->12->18->24->39->81
*/
    sortLinkedList(&head);
    printf("\n\nAFTER SORTING:");
    PrintList(head);
    /*7. Finally generate the reverse order of the above resultant linked list:
Input: 3->4->6->7->8->9->12->18->24->39->81
Output: 81->39->24->18->12->9->8->7->6->4->3
*/
    reverse(&head);
    printf("\n\nAtrer Reversing");
    PrintList(head);
}

struct node * CreateLinkedList(int n)
{
    int i = 1;
    struct node *head=NULL,*newnode=NULL,*temp=NULL;
    while(i <= n)
    {
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d, ",&newnode->data);
    newnode -> next = NULL;
    if(head == 0)
                head = temp = newnode;
            else
            {
                temp -> next = newnode;
                temp = newnode;
            }
            i++;
    }
    return head;
}

void PrintList(struct node *head)
{
    printf("\nThe list is now:\n");
    if(head==NULL)
        printf("Empty\n");
    while (head != NULL)
    {
    printf("%d", head -> data);
    head = head -> next;
    if(head != NULL)
        printf("->");
    }
}

struct node * InsertAtPos(struct node *head, int index, int val)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 1;
    while (i!=index-1)
    {
        p = p -> next;
        i++;
    }
    ptr -> data = val;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct node * Delete_val(struct node * head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q -> data != value && q -> next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

void remove_Duplicates(struct node **head)
{
    struct node *p, *q, *prev, *temp;

    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}

int Length(struct node *head)
{
    int i=0;
    if(head==NULL)
        return 0;
    else
    {
        while (head!= NULL)
        {
            i++;
            head=head->next;
        }
    }
    return i;
}

int maxElement(struct node *head)
{
    int max;
    if(head==NULL)
        return -9999999;
    else
    {
        max=head->data;
        while (head!= NULL)
        {
        if(max<head->data)
            max=head->data;
        head=head->next;
        }
        return max;
    }
}

float Average(struct node *head)
{
    int l = Length(head);
    float avg = 0;
    if(head==NULL)
        return 0;
    else
    {
        while (head!= NULL)
        {
        avg = avg + head -> data;
        head = head->next;
        }
    return (avg/l);
    }
}

int Middle_element(struct node * head)
{
    int l=Length(head),i;
    int position=l/2;
    //for even length I am printing right middle element
    for(i=1;i<=position;i++)
        head=head->next;
    return head->data;
}

void sortLinkedList(struct node** head_ref)
{
    struct node *current = *head_ref, *index = NULL;
    int temp;
    if (head_ref == NULL)
    {
        return;
    }
    else 
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
