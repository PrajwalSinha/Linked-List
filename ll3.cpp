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
Node* insertHead(Node* head,int val){
  Node* temp = new Node(val,head);
  return temp;
}
Node* insertEnd(Node* head,int val){
  if(head==NULL){
    return new Node(val);
  }
  Node* temp = head;
  while(temp->next!=NULL){ //so that i can stop at the lat element
    temp=temp->next; //increment
  }
  Node* newNode = new Node(val);
  temp->next = newNode;
  return head;
}
Node* insertPosition(Node* head,int el,int k){
  if(head==NULL){
    if(k==1){
      return new Node(el);
    }
    else{
      return head;
    }
  }
  if(k==1){
     return new Node(el,head);
  }
  int cnt = 0;
  Node* temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt==(k-1)){
      Node* x = new Node(el,temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}
Node* insertBeforeValue(Node* head,int el,int val){
  if(head==NULL){
    return NULL;
  }
  if(head->data==val){
     return new Node(el,head);
  }
 
  Node* temp = head;
  bool found = false;
  while(temp->next!=NULL){//never go to last element
   
    if(temp->next->data==val){
      Node* x = new Node(el,temp->next);
      temp->next = x;
      found=1;
      break;
    }
    temp = temp->next;
  }
  if(found==false){
    cout<<"Not found";
  }
  return head;
}
int main(){
  vector<int> arr = {12,5,8,7};
  Node* head = convertArr2LL(arr);
  //head = removesHead(head);
  //head=removeTail(head);
  //head = removeK(head,k);
  //head= removeele(head,5);
  //head = insertHead(head,100);
  //head = insertEnd(head,100);
  //head = insertPosition(head,100,3);
  head = insertBeforeValue(head,100,5);
  print(head);
}