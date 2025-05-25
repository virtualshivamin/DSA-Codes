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

// Hear i learned how to calculate the length of Linked List
int LengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// here i learned to check if a no is present in LL or not 
int ifPresentInLL(Node* head, int val){
    Node* temp = head;
    while(temp)
    {
        if(temp->data == val) return 1; // Returns 1 if present 
        temp = temp->next;
    }
    return 0; // returns 0 if not present 
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
    cout << endl <<  "Length of Linked List : " << LengthOfLL(head) << endl;

    cout << ifPresentInLL(head,5) << endl;

    return 0;
}