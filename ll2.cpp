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
  for(int i=0;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
int lengthofLL(Node* head){
  int cnt = 0;
  Node* temp  =head;
  while(temp){
    //cout<<temp->data<<" ";
    temp = temp->next;
    cnt++;
  }
  return cnt;
}
int checkIfPresent(Node* head,int val){
  Node* temp  =head;
  while(temp){
    if(temp->data==val) return 1;
    temp = temp->next;
  }
  return 0;
}
int main(){
  vector<int> arr = {12,5,8,7};
  Node* head = convertArr2LL(arr);
  cout<<head->data<<endl;
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
  cout<<lengthofLL(head);
  cout<<checkIfPresent(head,5);
  
}