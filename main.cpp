#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class List{
public:
    struct Node{
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
public:
    List() : head(nullptr) {}
    ~List(){
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void add(int value, int position) {
        if (position <0) return;
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node*current=head;
            for (int i = 1; current != nullptr && i< position; ++i) {
                current = current->next;
            }
            if (current == nullptr) {
                cout<<"Nieprawidlowa pozycja elementu."<<endl;
                delete newNode;
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void show() {
        Node* current = head;
        while(current !=nullptr) {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    bool exist(int value) const{
        Node* current = head;
        while (current != nullptr){
            if (current->data==value){
                return true;
            }
            current=current->next;
        }
        return false;
    }

    void remove(int position) {
        if(head ==nullptr){
            cout<<"Lista jest pusta."<<endl;
            return;
        }
        if(position == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            cout<<"Usunieto pierwszy element z listy."<<endl;
        } else {
            Node* current = head;
            for (int i=1; current->next != nullptr && i<position; ++i){
                current = current->next;
            }
            if(current->next == nullptr) {
                cout<<"Nie ma elementu o takim indeksie do usuniecia."<<endl;
                return;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout<<"Usunieto element o indeksie "<<position<<"."<<endl;
        }
    }
};

int main() {
    List list;

    //Dodanie elementow do pustej listy
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 5000; i++) {
        list.add(i, 0);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dodanie elementów zajęło: " << duration.count() << " nanosekund."<<endl<<endl;

    //Szukanie elementu
    auto start2 = high_resolution_clock::now();
    list.exist(19);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Znalezienie danego elementu zajęło: " << duration2.count() << " nanosekund."<<endl<<endl;

    //Dodanie elementu w dowolne miejsce
    auto start3 = high_resolution_clock::now();
    list.add(77, 19);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
    cout << "Dodanie elementu w dowolne miejsce zajęło: " << duration3.count() << " nanosekund."<<endl<<endl;

    //Usuwanie dowolnego elementu
    auto start4 = high_resolution_clock::now();
    list.remove(10);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
    cout << "Usunięcie danego elementu zajęło: " << duration4.count() << " nanosekund."<<endl<<endl;


    return 0;
}
