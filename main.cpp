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
    int tab[] = {1000,10000,100000};
    for(int data : tab){
        List list;
        int end = data;
        int mid = data/2;
        int first = 0;
        cout<<"-----------------------"<<data<<"-----------------------"<<endl;
        //Dodanie elementow do pustej listy
        auto start = high_resolution_clock::now();
        for (int i = 0; i < data; i++) {
            list.add(i, 0);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Dodanie "<<data<<" elementów zajęło: " << duration.count() << " nanosekund."<<endl;

        //DODAWANIE
        //na poczatku
        auto start2 = high_resolution_clock::now();
        list.add(77, first);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
        cout << "Dodanie elementu na poczatku zajęło: " << duration2.count() << " nanosekund."<<endl;

        //w srodku
        auto start3 = high_resolution_clock::now();
        list.add(79, mid);
        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
        cout << "Dodanie elementu w srodku zajęło: " << duration3.count() << " nanosekund."<<endl;

        //na koncu
        auto start4 = high_resolution_clock::now();
        list.add(78, mid);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
        cout << "Dodanie elementu na koncu zajęło: " << duration4.count() << " nanosekund."<<endl;

        //USUWANIE
        //na poczatku
        auto start5 = high_resolution_clock::now();
        list.remove(first);
        auto stop5 = high_resolution_clock::now();
        auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
        cout << "Usunięcie elementu na poczatku zajęło: " << duration5.count() << " nanosekund."<<endl;

        //w srodku
        auto start6 = high_resolution_clock::now();
        list.remove(mid);
        auto stop6 = high_resolution_clock::now();
        auto duration6 = duration_cast<nanoseconds>(stop6 - start6);
        cout << "Usunięcie elementu w srodku zajęło: " << duration6.count() << " nanosekund."<<endl;

        //na koncu
        auto start7 = high_resolution_clock::now();
        list.remove(end);
        auto stop7 = high_resolution_clock::now();
        auto duration7 = duration_cast<nanoseconds>(stop7 - start7);
        cout << "Usunięcie elementu na koncu zajęło: " << duration7.count() << " nanosekund."<<endl;

        //SZUKANIE
        //na poczatku
        auto start8 = high_resolution_clock::now();
        list.exist(first);
        auto stop8 = high_resolution_clock::now();
        auto duration8 = duration_cast<nanoseconds>(stop8 - start8);
        cout << "Znalezienie pierwszego elementu zajęło: " << duration8.count() << " nanosekund."<<endl;

        //w srodku
        auto start9 = high_resolution_clock::now();
        list.exist(mid);
        auto stop9 = high_resolution_clock::now();
        auto duration9 = duration_cast<nanoseconds>(stop9 - start9);
        cout << "Znalezienie srodkowego elementu zajęło: " << duration9.count() << " nanosekund."<<endl;

        //na koncu
        auto start10 = high_resolution_clock::now();
        list.exist(first);
        auto stop10 = high_resolution_clock::now();
        auto duration10 = duration_cast<nanoseconds>(stop10 - start10);
        cout << "Znalezienie ostatniego elementu zajęło: " << duration10.count() << " nanosekund."<<endl;
        cout<<endl<<endl;
    }
    return 0;
}
