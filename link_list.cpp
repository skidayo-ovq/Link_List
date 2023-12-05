#include <complex.h>
#include <cstddef>
#include <iostream>
using namespace std;

#define ERROR   -1
#define CORRECT 1

struct Node{
    int elem {};
    Node* prev;
    Node* next;
};

Node* LinkList;

Node* CreateLinkList(int e[], int n) {
    Node* head = new Node;
    Node* temp = head;

    for (int i = 1; i <= n; i++){
        Node* newNode = new Node;
        newNode->elem = e[i];
        newNode->next = nullptr;
        
        newNode->prev = temp;
        temp->next    = newNode;
        temp          = newNode;
    }
    return head; 
}

int ShowLinkList(Node* head){
    Node* ptr = head->next;
    if (!head) {
      return ERROR;
    }
    while (ptr != nullptr) {
        cout << ptr->elem << ' ';
        ptr = ptr->next;
    }
    cout << endl;
    return CORRECT;
}

//Search an element in the specified position
Node* SearchLinkList(Node* head, int pos){
    if (!head || pos < 0) {
       return (NULL);
    }else if (pos == 0) {
        return head;
    }else {
        Node* ptr = head->next;
        for (int i=1; i<pos; i++) {
            ptr = ptr->next;
            if (ptr == nullptr) {
            return (NULL);
        }
    }
    return ptr;
    }
}

//Find the position of an specified element
Node* FindLinkList(Node*head, int val){
    Node* temp = head->next;
    while (temp != nullptr) {
        if (temp->elem == val) {
            return temp;
        }
    }
    return nullptr;
}

int InsertLinkList(Node* head, int elem, int pos){
    Node* newNode = new Node;

    if (pos <= 0 || !elem) {
        return ERROR;
    }else {
        Node* prev = SearchLinkList(head, pos-1);
        Node* ptr  = SearchLinkList(head, pos);
        if (prev == nullptr) {
            return ERROR;
        }else if (ptr == nullptr) {      //in the end of the LinkList
            prev->next    = newNode;
            newNode->prev = prev;
            newNode->elem = elem;
            newNode->next = nullptr;
            return CORRECT;
        }else {                         //specified position
            newNode->next = ptr;
            newNode->prev = prev;
            newNode->elem = elem;
            prev->next    = newNode;
            ptr->prev     = newNode;
            return CORRECT;
        }
    }    
}
    
int DeleteLinklist(Node* head, int pos){
    Node* prev = SearchLinkList(head, pos-1);
    Node* ptr = SearchLinkList(head, pos);

    if (ptr == nullptr) {
       return ERROR;
    }else{
       prev->next = ptr->next;
       delete ptr;
    }
    return CORRECT;
}

int main(){
    int r[100], i, SampleNum, SearchPos, NewPos, NewItem, DelPos;
    Node* p;

    cin >> SampleNum;
    for (i = 1; i <= SampleNum; i++){
        cin >> r[i];
    }
    
    LinkList = CreateLinkList(r, SampleNum);
    ShowLinkList(LinkList);

    cin >> SearchPos;
    p = SearchLinkList(LinkList, SearchPos);
    cout << p->elem << endl;

    cin >> NewPos;
    cin >> NewItem;
    InsertLinkList(LinkList, NewItem, NewPos);
    ShowLinkList(LinkList);

    cin >> DelPos;
    DeleteLinklist(LinkList, DelPos);
    ShowLinkList(LinkList);

    return 0;
}

