#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* newNode(int data) {
	Node* temp = new Node;
	temp->next = NULL;
	temp->data = data;
	return temp;
}

void push(Node *&head, Node *node) {
	if (head == NULL) {
		head = node;
		return;
	}
	else {
		node->next = head;
		head = node;
	}
}
void push(Node *&head, int data) {
	Node* temp = newNode(data);
	push(head, temp);
}

void removeLoop(Node *head,Node* loopNode) {
	/*int looplength = 1;
	Node* temp = loopNode->next;
	while (temp != loopNode) {
		looplength++;
		temp = temp->next;
	}
	Node *pt1, *pt2;
	pt1 = head;
	pt2 = head;
	int count = 0;
	while (count < looplength) {
		pt2 = pt2->next;
		count++;
	}
	while (pt1!=pt2) {
		pt1 = pt1->next;
		pt2 = pt2->next;
	}
	pt2 = pt2->next;
	while (pt2->next!=pt1) {
		pt2 = pt2->next;
	}
	pt2->next = NULL;*/
	Node* pt1 = head;
	while (pt1 != loopNode->next) {
		pt1 = pt1->next;
		loopNode = loopNode->next;
	}
	loopNode->next = NULL;
}

void reverse(Node**head) {
	if (head == NULL) return;
	Node *prev=NULL, *next;
	Node *curr = *head;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
Node* reverse(Node*head, int k) {
	if (head == NULL) return NULL;
	int count = 0;
	Node *prev = NULL, *next;
	Node *curr = head;
	while (count < k && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	head->next = reverse(curr, k);
	return prev;
}

void detectAndRemoveLoop(Node *head) {
	Node *slow, *fast;
	slow = head;
	fast = head->next;
	while (fast && fast->next) {
		if (slow == fast) {
			cout << "Loop found. Will try to remove it now!!" << endl;
			removeLoop(head, fast);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
}

void printList(Node* head) {
	while (head) {
		cout << head->data<<" ";
		head = head->next;
	}
	cout << "\n";
}

int main() {
	/* Start with the empty list */
	Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(head, 9);
	push(head, 8);
	push(head, 7);
	push(head, 6);
	push(head, 5);
	push(head, 4);
	push(head, 3);
	push(head, 2);
	push(head, 1);
	printList(head);
	head = reverse(head,3);
	printList(head);
	return 0;
}