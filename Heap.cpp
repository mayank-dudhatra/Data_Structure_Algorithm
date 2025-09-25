#include <iostream>
#include<vector>
using namespace std;

void insertmax(vector<int>& tree,int val){
  tree.push_back(val);
  int i=tree.size()-1;
  while(i>1){
    int parent=i/2;
    if(tree[i]>tree[parent]){
      swap(tree[i],tree[parent]);
      i=parent;
      
    }else{
      break;
    }
  }
}

void insertmin(vector<int>& tree,int val){
  tree.push_back(val);
  int i=tree.size()-1;
  while(i>1){
    int parent=i/2;
    if(tree[i]<tree[parent]){
      swap(tree[i],tree[parent]);
      i=parent;
      
    }else{
      break;
    }
  }
}


void print(vector<int>& tree){
  for(int i=1;i<tree.size();i++){
    cout << tree[i] << " ";
    
  }
}


int main() 
{
   vector<int> tree ={0,60};
   insertmax(tree,48);
   insertmax(tree,80);
   insertmax(tree,50);
   insertmax(tree,56);
   insertmax(tree,32);
   insertmax(tree,47);
   insertmax(tree,70);
   
  print(tree);
   
}