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

// Deleating first element from linked list 
Node* removesHead(Node* head){
    if (head == NULL) return head; // agar list khali hai to kuch bhi nahi hoga 
    Node* temp = head; // temp me head store hoga (starting point)
    head = head->next; // head (starting point) ko ek aage shift kar denge 
    delete temp; // ek aage shift hone pe jo purana wala tha jisko temp me store kiye the usko delete kar denge 
    // JAVA me ye karna jaruri nahi hota hai kyuki java me garbage collector hota hai, jo automatically kar deta hai ye Memory Free. 
    return head; // naye head ko return kar denge 
}

// Deleating last element from linked list 
Node* removeTail(Node* head) {
    // agar list khali hua ya 1 element bas hua to list khali ho jayega (NULL)
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head; // temp me head store hoga (starting point)

    while(temp->next->next != NULL) // last second element pe jake rukna hai 
        temp = temp->next; // aage badhate rahenge temp ko jab tak last second element pe naa mile 
    
    delete temp->next; // last wala delete kar denge 
    temp->next = nullptr; // second last ko null kar denge 

    return head; // naye head ko return kar denge 
}

// Remove k element from linked list 
Node* removeK(Node* head, int k){
    if(head == NULL) return head; // agar list khali hua ya 1 element bas hua to list khali ho jayega (NULL) 
    if (k == 1) // agar first element ko delete karna hai to 
    {
        Node* temp = head; // temp me head store hoga (starting point)
        head = head->next; // head (starting) ek aage ho jayega 
        free(temp); // pichla head jo temp me tha delete hoga 
        return head; // naya head return hoga 
    }
    int count = 0; // count check karne ke liye k tak pahuche ki nahi 
    Node* temp = head; // temp me head store hoga (starting point)
    Node* prev = NULL; // naya khali Object 
    while (temp != NULL)
    {
        count++;
        if (count == k) // agar k th element tak pahuch gaye to 
        {
            prev->next = prev->next->next; // previous ka next ke baad ek skip kar ke uska adress de denge 
            free(temp); // temp ko free kardege 
            break;
        }
        prev = temp; // previous temp jaise hi badhega previous bhi badhega (temp ke ek pehle previous wala hai)
        temp = temp->next; // temp aage badhega 
    }
    return head; // naya head return hoga 
}

// Here i learned Traversal in Linked List by print function 
void print(Node* head) 
{
    while (head != NULL)
    {
        cout << head->data << " "; 
        head = head->next; 
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12,5,6,10,9,8,7};
    Node* head = convertArr2LL(arr);
    Node* temp = head;

    print(head);
    
    cout << "Length of Linked List : " << LengthOfLL(head) << endl;

    cout << ifPresentInLL(head,5) << endl;

    // first element delete 
    head = removesHead(head);
    print(head); 

    // last element delete 
    head = removeTail(head);
    print(head); 

    // beech me ya last me ka koi bhi k th element delete (jaise yaha 3 rd element delete ho raha hai) 
    head = removeK(head,3);
    print(head); 

    return 0;
}
