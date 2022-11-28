#include <iostream>
#include <stack>

using namespace std;
struct node {
  int data;
  node * next;
};

class linkedList {
  private:
  node * head;
  node * tail;
  public:
    linkedList() //konstruktorius
    {
    head = NULL;
    // tail = NULL;
    }
    ~linkedList()
    {
        clear();
    }

    void addNodeEnd (int value )
    {
    node * temp = new node;
    temp -> data = value;
    temp -> next = NULL;

    if (head == NULL)
    {
      head = temp;
      tail = temp;
    } else
    {
    tail -> next = temp ;
    tail = temp;
    }
}
  void addNodeStart(int value) {
    node * temp = new node;
    temp -> data = value;
    temp -> next = head;

    if (head == NULL)
    {
      head = temp;
      tail = temp;
    } else
    {
    // node *cur = head ;
    // head = temp;
    // temp -> next = cur;
    // }

  }

  void addNodePos(int pos, int value) {
    node * temp = new node;
    temp -> data = value;
    if (head == NULL)
    {
      temp -> next = NULL; // KODEL CIA TURIU TOKIA OPERACIJA O KITUR NETURIU
      head = temp;
      tail = temp;
    }
    else if( pos == size() )
        {
            addNodeEnd(value);
        }
         else if( pos == 0 )
        {
            addNodeStart(value);
        }

    else if (pos > 0 && pos <= size()) {

      node * pre = nullptr;
      node * cur = head;

      for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur -> next;

      }
      pre -> next = temp;
      temp -> next = cur;
    }
else if( pos<0 || pos > size() ) { cout << "DUOMENU NEGALIMA IVESTI";};
}

  void DeleteStart()
  {
    if  (isEmpty()==true)//----------------------------------- HEAD IR TAIL YRA NULL
        {cout<<"nera elementu kuriuos naikinti";}
        else if  (head  ==  tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{

    node * temp ;
    head = head -> next;
    delete temp;
    temp -> next = nullptr;

    }
  }

  void DeleteEnd() {
     if  (isEmpty()==true)//----------------------------------- HEAD IR TAIL YRA NULL
        {cout<<"nera elementu kuriuos naikinti";}
        else if  (head  ==  tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else {
            node *cur = head;
        while ( tail == cur -> next)
        {
           cur = cur -> next;
        }
        delete cur -> next;
        tail = cur;
        tail -> next = NULL;
    }


  }

  void DeleteMid(int pos) {

    node * pre = nullptr;
    node * cur = head;

    if ( pos > 0&& pos<size()){
    for (int i = 0; i < pos; i++) {
      pre = cur;
      cur = cur -> next;
    }
    pre -> next = cur-> next;
    delete cur;}
    else { cout<< " NERA ELEMENTO SIOJE POZICIJOJE";};
  }

  void search( int value )
  { node * temp = head ;
    int i = 0;

    while ( temp != NULL)
      {

          if ( temp -> data == value)
          {
              cout<<" Elementas "<<value<<" yra "<<i<<" pozicijoje.\n";
          }temp = temp -> next;
          i++;
      }

    cout<<endl;
  }

  bool isEmpty()
  {
      if (head == NULL)
      {
          return true;
      }
      else
      {
          return false;
      }
  }

  int size()
  {
    node * temp = head ;
    int i = 0;

    while ( temp != NULL)
      {
        temp = temp -> next;
          i++;
      }
    return i;
  }


  void display() {
    node * temp = head;
    while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
  void clear()
  {
    node* temp = head;
    while(temp->next!=NULL)
    {
        head=head->next;
        delete temp;
        temp= head;
    }
        delete temp;
        head= NULL;
        tail = NULL;

  }
  void reverse()
  {
    node * temp = head;
    node * pre = nullptr;
    node * cur = head;
    node * next = nullptr;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
    tail = temp;
  }

 void reverseStack()
  {
    stack<node*> s;
    node * temp = head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
  }
};

void meniu()
{
    cout<< " VIENAKRYPTIS TIESINIS SARASAS"<<endl<<endl;
    cout<<" FUNKCIJOS :"<<endl;
    cout<<"1. Ivedimas"<<endl<<"2. Naikinimas"<<endl<<"3. Paieska"<<endl<<"4. Ar tuscia?"<<endl<<"5. Elementu kiekis: ";
    cout<<endl<<"6. Vaizdavimas"<<endl<<"7. Reverse Pointer"<<endl<<"8. Reverse Stack"<<endl<<"9. Trinimas"<<endl<<"0. EXIT"<<endl<<endl;
}

int main() {
  linkedList listas;
    char i;
  int data, pozic;
    while ( i!='0')
    {
        meniu();
        cin >> i;
        char ived ;
        if (i == '1') {
            cout<< "IVEDIMAS : "<<endl <<"1. Pradzioje"<<endl<<"2. Viduryje"<<endl<<"3. Pabaigoje"<<endl<<endl<<"0. Grizimas prie funkciju"<<endl<<endl;
            cin >> ived;
            if ( ived == '1') {cout<<"Iveskite duomeni: "; cin>> data;  listas.addNodeStart(data);}
            if ( ived == '2') {cout<<"Iveskite duomeni: "; cin>> data; cout<< "iveskite pozicija: ";cin >> pozic; listas.addNodePos(pozic,data);}
            if ( ived == '3') {cout<<"Iveskite duomeni: "; cin>> data;  listas.addNodeEnd(data);}

        };

        if (i=='2'){
            char naik;

              cout<< "NAIKINIMAS : "<<endl <<"1. Pradzioje"<<endl<<"2. Viduryje"<<endl<<"3. Pabaigoje"<<endl<<endl<<"0. Grizimas prie funkciju"<<endl<<endl;
            cin >> ived;
            if ( ived == '1') { listas.DeleteStart();}
            if ( ived == '2') {cout<< "Nurodykite naikinimo pozicija: ";cin >> pozic; listas.DeleteMid(pozic);}
            if ( ived == '3') {  listas.DeleteEnd();}

        };
        if ( i == '3') {cout<< "Koki rasti skaiciu: "; int sk; cin>> sk; listas.search(sk);};
        if ( i == '4') { if (listas.isEmpty()==true){cout<<"Tuscia";} else {cout<<" Yra duomenu";};};
        if ( i == '5') { cout << listas.size();};
        if ( i == '6') {listas.display();};
        if ( i == '7') {listas.reverse();};
        if ( i == '8') {listas.reverseStack();};
        if ( i == '9') {listas.clear();};
        cout<<endl<<endl;
    }
  return 0;

}
