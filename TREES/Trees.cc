#include<iostream>
using namespace std;
struct node
{
    int info;
    node* left;
    node* right;
    node(){
        left = right = nullptr;
    }
};
class Tree{
      node* temp;

      public:
      int num;
      node* root;
      Tree(){
        temp = nullptr;
        root= nullptr;
      }

      void insert(node* temp){
         if(temp == NULL){
            temp = new node;
            cout<<"Enter the value: ";
            cin>>temp->info;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            return;
        
         }
        if (temp->info == num)
        {
            cout<<"\nNumber already exist\n";
            return;
        }
        if (num < temp->info   )
        {
           if (temp->left != NULL)
           {
                insert(temp->left);
                return;
           }
           else{
            temp->left = new node;
            temp->left->info = num;
            temp->left->left = NULL;
            temp->left->right = nullptr;
            return;
           }
           
        }
        if (num > temp->info   )
        {
           if (temp->right!= NULL)
           {
                insert(temp->right);
                return;
           }
           else{
            temp->right= new node;
            temp->right->info = num;
            temp->right->right= NULL;
            temp->right->left = nullptr;
            return;
           }
           
        }
        


      }

      void remove(node* temp , int key){

           if(temp == nullptr){
            cout<<"Tree is Empty!!!\n";
            return;
           }
           if(key == temp->info){
            if(temp->right == nullptr && temp->left == nullptr){
                delete temp;
                temp = nullptr;
                return;
            }
            
           }
           
           if(key > temp->info){
            if(temp->right != nullptr && temp->right->info== key){
                if(temp->right->right == nullptr && temp->right->left == nullptr){
                      delete temp->right;
                      temp->right = nullptr;
                      return;
                }


                if((temp->right->right != nullptr && temp->right->left == nullptr ) || (temp->right->right == nullptr && temp->right->left != nullptr )){
                    node* curr = temp->right;
                    if(curr->right != nullptr){
                        temp->right =curr->right;
                        delete curr;
                        curr =nullptr;
                        return;
                    }
                    if(curr->left != nullptr)
                    {
                        temp->right = curr->left;
                        delete curr;
                        curr = nullptr;
                         return;
                    }


                }
                if(temp->right->right != nullptr && temp->right->left != nullptr){
                    node* curr = temp->right->right;
                            if(curr->left == nullptr){
                                temp->right->info = curr->info;
                                if(curr->right == nullptr){
                                    node* current = temp->right;
                                    delete current->right;
                                    curr= nullptr;
                                    current->right = curr;
                                    return;
                                }
                                if(curr->right != nullptr){
                                    node* current = curr->right;
                                    temp->right->right = current;
                                    delete curr;
                                    curr = nullptr;
                                    return; 
                                }
                               
                            }
                            while(curr->left->left != nullptr){
                           curr = curr->left;
                    }
                        
                         
                    
                        if(curr->left->right != nullptr){
                        node* curr2 = curr->left;
                        temp->right->info = curr2->info;
                        curr->left  = curr2->right;
                        delete curr2;
                        curr2 = nullptr;
                        return;

                    } 
                       
                       
                         if(curr->right != nullptr){
                            node* curr2 = curr->right;
                            temp->right->info = curr->info;
                            temp->right->right = curr2;
                            delete curr;
                            curr = nullptr;
                            return;
                         }
                       
                        
                       
                       
                    
                    temp->right->info = curr->left->info;
                    delete curr->left;
                    curr->left = nullptr;
                    return;
                    
                    
                    
                    

                }


            }


           }
           if(key < temp->info){
            if(temp->left != nullptr && temp->left->info== key){
                if(temp->left->right == nullptr && temp->left->left == nullptr){
                      delete temp->left;
                      temp->left = nullptr;
                      return;
                }
                
                if((temp->left->right != nullptr && temp->left->left == nullptr ) || (temp->left->right == nullptr && temp->left->left != nullptr )){
                    node* curr = temp->left;
                    if(curr->right != nullptr){
                        temp->left =curr->right;
                        delete curr;
                        curr =nullptr;
                        return;
                    }
                    if(curr->left != nullptr)
                    {
                        temp->left = curr->left;
                        delete curr;
                        curr = nullptr;
                         return;
                    }


                }

                if(temp->left->right != nullptr && temp->left->left != nullptr){
                    node* curr = temp->left->left;
                    while(curr->right->right != nullptr){
                          curr = curr->right;
                    }
                    if(curr->right->left != nullptr){
                        node* curr2 = curr->right;
                        temp->left->info = curr2->info;
                        curr->right  = curr2->left;
                        delete curr2;
                        curr2 = nullptr;
                        return;

                    }
                    temp->left->info = curr->right->info;
                    delete curr->right;
                    curr->right = nullptr;
                    return;

                }


            }
           }




           if(temp->info < key){
            remove(temp->right , key);
           }
           if(temp->info > key){
            remove(temp->left , key);
           }
        }

        
        
      


      void inOrder(node* temp){
        if(temp == NULL){
            cout<<"Empty!!!\n";
            return;
        }
        if (temp->left != NULL)
        {
            inOrder(temp->left);
        }
        cout<<temp->info<<" ";
        if (temp->right != NULL)
        {
            inOrder(temp->right);
        }
        

      }
       
    
       
        
      
};


int main(){
    Tree t;
    t.insert(t.root);
    t.inOrder(t.root);
    int op;
    int a;
    while (true)
    {
    cout<<"Enter choice: ";
    cin>>op;
    if (op == 1)
    {
    cout<<"\nEnter Num: ";
    cin>>t.num;
    t.insert(t.root);
    t.inOrder(t.root);
    }
    else if (op == 2)
    {
    cout<<"\nEnter key: ";
    cin>>a;
    t.remove(t.root , a);
    cout<<endl;
    t.inOrder(t.root);
    } 
    
    }
    
}
