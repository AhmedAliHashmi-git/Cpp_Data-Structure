    #include<iostream>
    using namespace std;
    struct Node{
    int info;
    Node* next;
    };
    class CircularLinkedList{
        private:
        Node* head;
        Node* temp;
        public:
        CircularLinkedList();
        // ~CircularLinkedList();
        void addInsert();
        void remove();
        void update();
        void print();
    };
    CircularLinkedList :: CircularLinkedList(){
        head = NULL;
        temp = NULL;
    }
    void CircularLinkedList ::  addInsert(){
        if(head == NULL){
            head = new Node;
            cout<<"Enter the value: ";
            cin>>head->info;
            head->next = head;
            return;
        }
        int key;
        cout<<"Enter the key after you want to insert: ";
        cin>>key;

        if(temp->next == head && temp->info == key){
            Node* temp1 =new Node;
            cout<<"Enter the value: ";
            cin>>temp1->info;
            temp->next = temp1;
            temp1->next = head;
            return;
        }
        bool found = false;
        temp = head;
    //      for (temp = head; ; temp = temp->next) {
    //     if (temp->info == key) {
    //         Node* temp1 = new Node;
    //         cout << "Enter the value: ";
    //         cin >> temp1->info;

    //         temp1->next = temp->next;
    //         temp->next = temp1;
    //         return;
    //     }

    //     if (temp->next == head) {
    //         break; // Break the loop if we have traversed the entire circular list.
    //     }
    // }

        do{
        	if(temp->info==key){
        		Node* temp1=new Node;
        		cout<<"Enter the value: ";
        		cin>>temp1->info;
        		
        		temp1->next=temp->next;
        		temp->next=temp1;
                found = true;
        		return;
			}
			temp=temp->next;
		}
        while(temp!= head);
        if(!found){
        cout<<"Key did'nt found!!!\n";
        }

        
    }
    void CircularLinkedList :: remove(){
    int key;
    if(head == NULL){
        cout<<"List is already empty!!!\n";
        return;
    }
    temp = head;
    cout<<"Enter the key you want to delete: ";
    cin>>key;
    Node* curr;
       while(temp->next != head){
        curr = temp;
        temp = temp->next;
       }
       curr = temp;
       temp = head;
    if(head->info == key){
       Node* temp2 = temp;
       temp = temp->next;
       curr->next = temp;
       head = temp;
       delete temp2;
       return;
    }
    temp = head;

    do{
        if(temp->next->info == key){
          Node* temp1 = temp->next;
          temp->next = temp1->next;
          delete temp1;
          return;
        }temp = temp->next;
    }while(temp->next != head);
    cout<<"Item did'nt found\n";


}
void CircularLinkedList :: update(){
    if(head == NULL){
        cout<<"List is Empty!!!";
        return;
    }
    int key;
    temp = head;
    cout<<"Enter the key: ";
    cin>>key;
    Node* curr;
    while(temp->next != head){
        curr = temp;
        temp = temp->next;
    }
    curr = temp;
    temp = head;
    if(curr->info == key){
        cout<<"Enter the new value: ";
        cin>>curr->info;
        return;
    }
    if(temp->info == key){
        cout<<"Enter the new value: ";
        cin>>temp->info;
        return;
    }
     while(temp->next != head){
        if(temp->info == key){
            cout<<"Enter the new value: ";
            cin>>temp->info;
            return;
        }temp= temp->next;
     }
     cout<<"Key did'nt found\n";

}
 void CircularLinkedList::print() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }

    temp = head;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}



    int main(){
        CircularLinkedList CLL;
        CLL.addInsert();
        CLL.print();
        CLL.addInsert();
        CLL.print();
        CLL.addInsert();
        CLL.print();
        CLL.addInsert();
        CLL.print();
        CLL.addInsert();
        CLL.print();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        CLL.remove();
        CLL.print();
        CLL.remove();
        CLL.print();
        CLL.remove();
        CLL.print();
        CLL.remove();
        CLL.print();
        CLL.remove();
        CLL.print();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        CLL.update();
        CLL.print();
        CLL.update();
        CLL.print();
        CLL.update();
        CLL.print();
    }