#include<stdio.h>
#include<iostream>
#include<malloc.h> 
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
void append(struct Node **head, int val)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = NULL;
	if(*head == NULL)
		*head = newnode;
	else
	{
		struct Node *temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return;
}
int josephus(struct Node *head, int n)
{
	while(head->next != head)
	{
		struct Node *ptr = head;
		for(int i=1; i<n; i++)
		{
			ptr = head;
			head = head->next;
		}
		ptr->next = head->next;
		free(head);
		head = ptr->next;
	}
	return head->data;
}
int main()
{
	struct Node *head = NULL;
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		append(&head, i);
	}
	struct Node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
	cout<<josephus(head, m)<<endl;
}
