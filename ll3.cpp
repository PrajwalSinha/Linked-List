#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  public:
  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }
  //you can have multiple constructors
  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};
//convert array to linked list
Node* convertArr2LL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}
Node* removesHead(Node* head){
  if(head==NULL) return head;
  Node* temp = head;
  head=head->next;
  delete temp;
  return head;
}
Node* removeTail(Node* head){
  if((head==NULL)||(head->next==NULL)) return NULL;
  Node* temp = head;
  while(temp->next->next!=NULL){
    temp = temp->next;
  }
  delete temp->next;
  temp->next=nullptr;
  return head;
}
Node* removeK(Node* head,int k){
  if(head==NULL) return head;
  Node* temp = head;
  if(k==1){
    head = head->next;
    free(temp);
    return head;
  }
  int cnt = 0;
  Node* prev = nullptr;
  while(temp!=NULL){
    cnt++;
    if(cnt==k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}
Node* removeele(Node* head,int val){
  if(head==NULL) return head;
  Node* temp = head;
  if(head->data==val){
    head = head->next;
    free(temp);
    return head;
  }
  Node* prev = nullptr;
  while(temp!=NULL){
    if(temp->data==val){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}
int main(){
  vector<int> arr = {12,5,8,7};
  Node* head = convertArr2LL(arr);
  //head = removesHead(head);
  //head=removeTail(head);
  //head = removeK(head,k);
  head= removeele(head,5);
  print(head);
}