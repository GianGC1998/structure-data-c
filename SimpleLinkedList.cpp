// SimpleLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Node {
    int value;
    // Inicialmente este valor empieza en NULL
    Node* next;
public:
    int getValue() {
        return this->value;
    }
    void setValue(int value) {
        this->value = value;
    }

    Node* getNext() {
        return this->next;
    }

    void setNextNode(Node* next) {
        this->next = next;
    }

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

class LinkedList {
    int size;
    // Inicialmente este valor empieza en NULL
    Node* head;

public:
    int getSize() {
        return this->size;
    }

    void setSize(int size) {
        this->size = size;
    }

    Node* getHead() {
        return this->head;
    }

    void setHead(Node* head) {
        this->head = head;
    }

    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    // PRINTEAR VALORES DE LISTA;
    void Print() {
        Node* current = this->head;
        while (current) {
            cout << current->getValue() << ' ';
            current = current->getNext();
        }
    }


    // FUNCIONES DE OPERACIONES CON LA LISTA: AGREGAR, ELIMINAR, MOSTRAR

    // AGREGAR

    void AgregarAlInicio(int newValue) {
        Node* node = new Node(newValue, this->head);
        this->head = node;
        this->size++;
    }

    void AgregarAlFinal(int newValue) {
        Node* node = new Node(newValue, nullptr);
        if (this->head) {
            Node* aux = this->head;
            while (aux->getNext()) {
                aux = aux->getNext();
            }
            aux->setNextNode(node);
        }
        else {
            this->head = node;
        }
        this->size++;
    }

    void AgregarEnUnIndice(int newValue, int position) {
        if (position < 0 || position > this->size) {
            cout << "La posicion del nuevo valor es incorrecta. Agregue una posicion correcta";
        }
        else {
            if (position == 0) {
                AgregarAlInicio(newValue);
            }
            else if(position == this->size){
                AgregarAlFinal(newValue);
            }
            else {
                Node* current = this->head;
                Node* prev;
                for (int i = 0; i < position; i++) {
                    prev = current;
                    current = current->getNext();
                }
                Node* node = new Node(newValue, current);
                prev->setNextNode(node);
                this->size++;
            }
        }
    }

    // ELIMINAR
};


int main()
{
    LinkedList *list = new LinkedList();
    // head => null
    list->AgregarAlInicio(1); // head => 1 => null
    list->Print();
    cout << '\n';
    list->AgregarAlInicio(2); // head => 2 => 1 => null
    list->Print();
    cout << '\n';
    list->AgregarAlInicio(3); // head => 3 => 2 => 1 => null
    list->Print();
    cout << '\n';
    list->AgregarAlFinal(4); // head => 3 => 2 => 1 => 4 => null
    list->Print();
    cout << '\n';
    list->AgregarAlFinal(5); // head => 3 => 2 => 1 => 4 => 5 => null
    list->Print();
    cout << '\n';
    list->AgregarAlFinal(6); // head => 3 => 2 => 1 => 4 => 5 => 6 => null
    list->Print();

}