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

int main(){
  vector<int> arr = {2,5,8,7};
  Node* y = new Node(arr[0],nullptr);
  cout<<y<<endl; // pointer to the new memory location created
  cout<<y->data;
}