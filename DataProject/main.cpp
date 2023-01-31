#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
const int l = 100;
const int u = 999;
struct Data {
    string name;
    int id;
    int age;
    string address;
    int phone_number;
    string sex;
    string type;
};
class dia {
    struct node {
        node* next;
        node* pre;
        Data data;
    };
    node* head = NULL;
public:
    bool isempty() {
        if (head == NULL) {
            return true;
        }
        else
        {
            return false;
        }
    }
    //=========================yara==========================
    void append(string name, int age, string address, int phone_number, string sex, string type) {
        node* new_node = new node;
        new_node->data.name = name;
        new_node->data.id = (rand() % (u - l + 1)) + l;
        new_node->data.age = age;
        new_node->data.address = address;
        new_node->data.phone_number = phone_number;
        new_node->data.sex = sex;
        new_node->data.type = type;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->pre = temp;
        }
    }

    void insert_in_frist() {
        int num;
        cout << "Please Enter Number of Nodes : ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            string name, address, sex, type;
            int age, phone_number;
            node* new_node = new node;
            int lengh = 0;
            cout << "Please Enter Name : ";
            cin >> name;
            cout << "Please Enter Age : ";
            cin >> age;
            cout << "Please Enter Adress : ";
            cin >> address;
            cout << "Please Enter Phone Number : ";
            cin >> phone_number;
            cout << "Please Enter Sex : ";
            cin >> sex;
            cout << "Please Enter Type : ";
            cin >> type;
            cout << "----------------------------------"<<endl;
            new_node->data.name = name;
            new_node->data.id = (rand() % (u - l + 1)) + l;
            new_node->data.age = age;
            new_node->data.address = address;
            new_node->data.phone_number = phone_number;
            new_node->data.sex = sex;
            new_node->data.type = type;

            if (head == NULL) {
                head = new_node;
                new_node->next = new_node->pre = NULL;
            }
            else
            {
                new_node->next = head;
                new_node->pre = NULL;
                head->pre = new_node;
                head = new_node;

            }
            lengh++;
        }
    }
    void insert_in_last() {
        int num;
        cout << "Please Enter Number of Nodes : ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            string name, address, sex, type;
            int age, phone_number;

            int lengh = 0;
            cout << "Please Enter Name : ";
            cin >> name;
            cout << "Please Enter Age : ";
            cin >> age;
            cout << "Please Enter Adress : ";
            cin >> address;
            cout << "Please Enter Phone Number : ";
            cin >> phone_number;
            cout << "Please Enter Sex : ";
            cin >> sex;
            cout << "Please Enter Type : ";
            cin >> type;
            cout << "----------------------------------" << endl;
            node* new_node = new node;
            new_node->data.name = name;
            new_node->data.id = (rand() % (u - l + 1)) + l;
            new_node->data.age = age;
            new_node->data.address = address;
            new_node->data.phone_number = phone_number;
            new_node->data.sex = sex;
            new_node->data.type = type;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
            }
            else {
                node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->pre = temp;
            }
        }
    }
    void insert_in_middle() {
        int pos;
        cout << "Please Enter the Positin of new node you want to Add :" << endl;
        cin >> pos;

        string name, address, sex, type;
        int age, phone_number;

        int lengh = 0;
        cout << "Please Enter Name : ";
        cin >> name;
        cout << "Please Enter Age : ";
        cin >> age;
        cout << "Please Enter Adress : ";
        cin >> address;
        cout << "Please Enter Phone Number : ";
        cin >> phone_number;
        cout << "Please Enter Sex : ";
        cin >> sex;
        cout << "Please Enter Type : ";
        cin >> type;
        cout << "----------------------------------" << endl;
        node* new_node = new node;
        new_node->data.name = name;
        new_node->data.id = (rand() % (u - l + 1)) + l;
        new_node->data.age = age;
        new_node->data.address = address;
        new_node->data.phone_number = phone_number;
        new_node->data.sex = sex;
        new_node->data.type = type;
        node* temp = head;
        node* temp2 = NULL;
        node* temp3 = head;
        if (pos == 0) {
            head = new_node;
            new_node->next = new_node->pre = NULL;
            return;
        }
        for (int i = 1; i < pos; i++) {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->pre = temp;
        temp->next->pre = new_node;
        temp->next = new_node;
    }
    void Search() {
        cout << "1 -If you want to search with name " << endl;
        cout << "2 -If you want to search with id " << endl;
        cout << "Enter your choice :";
        int x;
        cin >> x;
        if (x == 1) {
            string name;
            cout << "please enter the name : ";
            cin >> name;
            node* temp = head;
            if (isempty()) {
                cout << "The list is empty" << endl;
                return;
            }
            else {
                int found = 0;
                while (temp != NULL) {
                    if (temp->data.name == name) {
                        cout << "NAME : " << temp->data.name << endl;
                        cout << "ID : " << temp->data.id << endl;
                        cout << "AGE : " << temp->data.age << endl;
                        cout << "ADDRESS : " << temp->data.address << endl;
                        cout << "TELEPHONE NUMBER : " << temp->data.phone_number << endl;
                        cout << "SEX : " << temp->data.sex << endl;
                        cout << "TYPE : " << temp->data.type << endl;
                        cout << "==============================================" << endl;
                        found++;
                        break;
                    }
                    temp = temp->next;
                }
                if (found != 1) {
                    cout << "This Name " << "-> " << name << " is not found in the list" << endl;
                }
            }
        }
        else {
            int id;
            cout << "please enter the id :  ";
            cin >> id;
            node* temp = head;
            if (isempty()) {
                cout << "The list is empty" << endl;
                return;
            }
            else {
                int found = 0;
                while (temp != NULL) {
                    if (temp->data.id == id) {
                        cout << "NAME :" << temp->data.name << endl;
                        cout << "ID : " << temp->data.id << endl;
                        cout << "AGE : " << temp->data.age << endl;
                        cout << "ADDRESS : " << temp->data.address << endl;
                        cout << "TELEPHONE NUMBER : " << temp->data.phone_number << endl;
                        cout << "SEX : " << temp->data.sex << endl;
                        cout << "TYPE : " << temp->data.type << endl;
                        cout << "==============================================" << endl;
                        found++;
                        break;
                    }
                    temp = temp->next;
                }
                if (found != 1) {
                    cout << "This id " << "-> " << id << " is not found in the list" << endl;
                }
            }
        }
    }
    //==========================youssef=============================

    bool search_name(string name) {   //Me
        node* temp = head;
        int found = 0;
        while (temp != NULL) {
            if (temp->data.name == name) {

                found = 1;
                break;
            }
            temp = temp->next;
        }
        if(found){
            return true;
        }else {
            return false;
        }
    }
    node* Search_name(string name) {   //Me
        node* temp = head;
        int found = 0;
        while (temp != NULL) {
            if (temp->data.name == name) {

                found = 1;
                return temp;
            }
            temp = temp->next;
        }
    }
    void update() {
        cout << "Enter the name : " << endl;
        string s; cin >> s;

        if(!search_name(s)){
            cout<<"The name you have entered isn't found please enter a valid name\n";
            return;
        }else{

            cout << "What do you want to update ? " << endl;
            cout << "1 - NAME" << endl;
            cout << "2 - AGE" << endl;
            cout << "3 - ADDRESS" << endl;
            cout << "4 - TELEPHONE NUMBER" << endl;
            cout << "5 - TYPE" << endl;
            int n; cin >> n;
            int y; string p;
            node* t = Search_name(s);
            if (n == 1) {
                cout << "Please enter the new name : " << endl;
                cin >> p;
                t->data.name = p;
            }
            else if (n == 2) {
                cout << "Please enter the new age : " << endl;

                cin >> y;
                t->data.age = y;
            }
            else if (n == 3) {
                cout << "Please enter the new address : " << endl;


                cin >> p;
                t->data.address = p;
            }
            else if (n == 4) {
                cout << "Please enter the new telephone number : " << endl;

                cin >> y;
                t->data.phone_number = y;
            }
            else if (n == 5) {
                cout << "Please enter the new type : " << endl;

                cin >> p;
                t->data.type = p;
            }
        }
        cout<<" the data has been updated successfully\n";
    }

    void delete_first() {  //Me
        node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        head->pre = NULL;
    }
    void remove_with_name(string val) {   //Me
        node* temp = head;
        if (isempty()) {
            cout <<"no data available"<<endl;
            return;
        }
        if (temp->data.name == val) {
            head = temp->next;
            if (head != NULL) {
                head->pre = NULL;
            }
            delete temp;
            return;
        }
        else {
            while (temp->data.name != val && temp != NULL) {
                temp = temp->next;
            }
            if (temp->next==NULL){
                temp->pre->next=NULL;
                delete temp;
                return;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            delete temp;
        }
    }
    void remove_with_id(int val) {   //Me
        node* temp = head;
        if (isempty()) {
            return;
        }
        if (temp->data.id == val) {
            head = temp->next;
            if (head != NULL) {
                head->pre = NULL;
            }
            delete temp;
            return;
        }
        else {
            bool f = 0;
            while (temp->data.id != val && temp != NULL) {
                temp = temp->next;
                if (temp->data.id == val)f = 1;
            }
            if (!f) {
                cout << "There is no id like this" << endl;
                return;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            delete temp;
        }
    }
    void delete_last() {    //Me
        node* temp = head;
        node* temp2;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }
    void display() {   //Me
        node* temp = head;
        while (temp != NULL) {
            cout << "NAME : " << temp->data.name << endl;
            cout << "ID : " << temp->data.id << endl;
            cout << "AGE : " << temp->data.age << endl;
            cout << "ADDRESS : " << temp->data.address << endl;
            cout << "TELEPHONE NUMBER : " << temp->data.phone_number << endl;
            cout << "SEX : " << temp->data.sex << endl;
            cout << "TYPE : " << temp->data.type << endl;
            cout << "==============================================" << endl;
            temp = temp->next;
        }
    }

    void Sort() {   //Hana
        struct node* current = head, * index = NULL;
        int temp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->data.id > index->data.id) {
                        temp = current->data.id;
                        current->data.id = index->data.id;
                        index->data.id = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};
class stack {   //Mark && Badr
    struct node {
        Data d;
        node* next;
    };
    node* top;
public:
    stack()
    {
        top = NULL;
    }
    bool is_empty() {
        return top == NULL;
    }

    void count()
    {
        if (is_empty()) { cout << "stack is empty\n"; }
        node* temp = top;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        cout << "the number of patients are " << counter;
    }
    void push(Data d1)
    {
        node* newNode = new node;
        newNode->d.name = d1.name;
        newNode->d.id = d1.id;
        newNode->d.age = d1.age;
        newNode->d.type = d1.type;
        newNode->d.address = d1.address;
        newNode->d.phone_number = d1.phone_number;
        newNode->d.sex = d1.sex;
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void peak()
    {
        if (is_empty()) { cout << "stack is empty\n"; }
        else
        {
            cout << "the name of the patient is " << top->d.name << endl;
            cout << " the patient of ID is " << top->d.id << endl;
            cout << " the patient sex is " << top->d.sex << endl;
            cout << "the patient's age is " << top->d.age << endl;
            cout << "the patient's phone number is " << top->d.phone_number << endl;
            cout << " patient's address is " << top->d.address << endl;
            cout << "the patient's has diabetes of  " << top->d.type << endl;
        }
    }

    void display() {
        if (is_empty()) { cout << "stack is empty\n"; }
        node* temp = top;
        while (temp != NULL)
        {
            cout << "the name of the patient is " << temp->d.name << endl;
            cout << " the patient of ID is " << temp->d.id << endl;
            cout << " the patient sex is " << temp->d.sex << endl;
            cout << "the patient's age is " << temp->d.age << endl;
            cout << "the patient's phone number is " << temp->d.phone_number << endl;
            cout << " patient's address is " << temp->d.address << endl;
            cout << "the patient's has diabetes of  " << temp->d.type << endl;
            cout << "==============================================" << endl;
            temp = temp->next;
        }
    }
};
bool choice() {
    string x;
    cout << "\n\n\npress m or M to go back to main menu\npress q to exit";
    cin >> x;
    if (x == "m" || x == "M")
        return true;
    else if (x == "q" || x == "Q")
        return false;
}
int main() {
    dia s;
    stack s1;

    Data p1;

    s.append("no_m", 77, "01002824714", 328743264, "male", "b");
    s.append("youssef", 22, "1244edrf", 0101203, "male", "a");
    s.append("reem", 19, "353444te", 1023432, "female", "b");
    do {
        cout << "What do you want to do ? " << endl;
        cout << "1 - Show all the entered data " << endl;
        cout << "2 - Enter new data " << endl;
        cout << "3 - Search " << endl;
        cout << "4 - Delete data  " << endl;
        cout << "5 - Update data " << endl;
        cout << "6 - sort data " << endl;
        cout << "7 - push to the stack" << endl;
        cout << "8 - pop from stack" << endl;
        cout << "9 - peak of the stack\n";
        cout << "10 - display how many elements in the stack\n";
        cout << "11 - display elements of the stack\n";
        cout << "Enter your choice : " << endl;

        int x; cin >> x;
        system("cls");
        switch (x) {
            case 1:
                // s.Sort();
                s.display();
                break;


            case 2:
                cout << "1 - if you want to add first " << endl;
                cout << "2 - if you want to add last " << endl;
                cout << "3 - if you want to add in the Middle " << endl;

                int i; cin >> i;
                system("cls");
                if (i == 1) {
                    s.insert_in_frist();
                }
                else if(i==2) {
                    s.insert_in_last();
                }
                else {
                    s.insert_in_middle();
                }
                break;
            case 3:
                s.Search();
                break;



            case 4:
                cout << "1 - if you want to delete with name " << endl;
                cout << "2 - if you want to delete with id " << endl;
                cout << "3 - if you want to delete from frist " << endl;
                cout << "4 - if you want to delete from last " << endl;
                int x; cin >> x;
                if (x == 1) {
                    cout << "Please enter the name : ";
                    string b; cin >> b;
                    s.remove_with_name(b);
                }
                else if(x==2) {
                    int o; cin >> o;
                    s.remove_with_id(o);
                }
                else if (x == 3) {
                    s.delete_first();
                }
                else {
                    s.delete_last();
                }

                break;
            case 5:
                s.update();

                break;


            case 6:
                s.Sort();
                break;


            case 7:
                cout << "Please Enter Name : ";
                cin >> p1.name;
                cout << "Please Enter Age : ";
                cin >> p1.age;
                cout << "Please Enter Adress : ";
                cin >> p1.address;
                cout << "Please Enter Phone Number : ";
                cin >> p1.phone_number;
                cout << "Please Enter Sex : ";
                cin >> p1.sex;
                cout << "Please Enter Type : ";
                cin >> p1.type;
                p1.id = (rand() % (u - l + 1)) + l;
                s1.push(p1);
                cout << "\n\n\nyour data has been added successfully";

                break;
            case 8:
                s1.pop();
                cout << "\n\nyour data has been popped successfully";

                break;
            case 9:
                s1.peak();

                break;
            case 10:
                s1.count();

                break;
            case 11:
                s1.display();

                break;
        }
        char y;
        cout << "\n\n\npress m or M to go back to main menu\npress q to exit";
        cin >> y;
        if (y == 'm' || y == 'M')
        {
            system("cls");
            continue;
        }
        else if (y == 'q' || y == 'Q')
            break;

    } while (true);
}
