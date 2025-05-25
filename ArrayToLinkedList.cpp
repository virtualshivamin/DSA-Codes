#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1)
    {
        data = data1;
    }
};

// Here i learned how to convert array to linked list 
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    Node* temp = head;

    // Here i learned Traversal in Linked List 
    while(temp)
    {
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    return 0;
}