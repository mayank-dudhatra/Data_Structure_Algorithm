#include <iostream>
#include <vector>
using namespace std;

class hashtable {
  
  vector<int> table;
  int size;
  
  public:
  
  hashtable(int s){
    size=s;
    table.resize(size,-1);
    
  }
   int hashfunction(int key){
     return key%size;
     
   }
   
   void insert(int key, int value){
    int index=hashfunction(key);
     
     if(table[index]==-1){
        table[index]=value;
        
     }else{
       cout<<key << "key ocupaid"<< endl;
     }
    
     
   }
   
   void display(){
       for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
     }
};

int main(){
  
  hashtable table(6);
  
  table.insert(1,12);
    table.insert(2,13);
  
  table.display();
}
