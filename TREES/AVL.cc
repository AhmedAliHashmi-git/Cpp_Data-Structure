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
      
      public:
      node* temp;
      int num;
      node* root;
       int gh;
       int flag;
      Tree(){
        temp = nullptr;
        root= nullptr;
        flag = -1;
      }
     int height(node* temp,int lh){
        
			if(temp==NULL){
				return 0;
			}
			if(temp->left != NULL){
				height(temp->left,lh+1);
			}
			if(temp->right!=NULL){
				
				height(temp->right,lh+1);
			}
			if(gh<lh){
			
				gh=lh;
			}
			return gh;
		}
        node* leftRotation(node* root) {
        node* temp1 = root->right;
        root->right = temp1->left;
        temp1->left = root;
        return temp1;
    }
      

      void insert(node* temp){
         
         
         if(temp == NULL){
            temp = new node;
            cout<<"Enter the value: ";
            cin>>temp->info;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            height(temp , 0);
            return;
        
         }
        
        
        if (temp->info == num)
        {
            cout<<"\nNumber already exist\n";
            return;
        }
        if (num < temp->info)
        {

           if (temp->left != NULL)
           {
                insert(temp->left);
           }
           else{
            temp->left = new node;
            temp->left->info = num;
            temp->left->left = NULL;
            temp->left->right = nullptr;
            return;
           }
        //    int bf;
        //    gh = 0;
        //    int bf1 = height(temp->left , 1);
        //    gh = 0;
        //    int bf2 = height(temp->right , 1);
        //    bf = bf1 - bf2;
           
        }
        
        
        
        if (num > temp->info)
        {
            if(flag == 4){
                node* temp1 = temp->right;
                temp->right = temp1->right;
                temp->right->left = temp1;
                flag = -1;  
                return;
            }
           if (temp->right!= NULL)
           {
                insert(temp->right);
                
           }
           else{
            temp->right= new node;
            temp->right->info = num;
            temp->right->right= NULL;
            temp->right->left = nullptr;
            return;
           }
           int lh = 0;  
	// cout<<height(root , lh+1)<<endl;
        gh = 0;
        int X = height(root->left , lh+1);
	    gh = 0;
	    int Y = height(root->right , lh+1);
        int bf = X - Y;
        cout<<"Balance Factor: "<<bf<<endl;
        if(bf == 1 || bf == 0 ||  bf == -1){
        return;
        }
        if(bf > -1 ){
           if (num < temp->left->info) {
                temp = leftRotation(temp);
            }
        }
       


        }
    
               
      }
        
      


    //   void inOrder(node* temp){
    //     if(temp == NULL){
    //         cout<<"Empty!!!\n";
    //         return;
    //     }
    //     if (temp->left != NULL)
    //     {
    //         inOrder(temp->left);
    //     }
    //     cout<<temp->info<<" ";
    //     if (temp->right != NULL)
    //     {
    //         inOrder(temp->right);
    //     }
        

    //   }

    //pre_order traversal
			void pre_order(node* temp){
			if(temp == NULL){
				cout<<"Empty\n";
				return;
			}
			cout<<temp->info<<" ";
			if(temp->left != NULL){
				pre_order(temp->left);
			}
			if(temp->right != NULL){
				pre_order(temp->right);
			}
		}
};

int main(){
    Tree t;
    t.insert(t.root);
    t.pre_order(t.root);
    int op;
    int a;
    while (true)
    {
    cout<<"\nEnter choice: \n1. Insert:\n";
    cin>>op;
    if (op == 1)
    {
    cout<<"\nEnter Num:\n ";
    cin>>t.num;
    t.insert(t.root);
    t.pre_order(t.root);
    }
   else if(op==2){
    
}
    
    }
    
}
