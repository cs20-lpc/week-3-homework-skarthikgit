#include "LinkedList.hpp"
template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    typename LinkedList<T>::Node *curr = head;
    typename LinkedList<T>::Node *tmp = nullptr;

    while (curr) {
        tmp = curr->next;
        delete curr;
        curr = tmp;
    }
    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    typename LinkedList<T>::Node *curr = head;

    if (position < 0 || position >= this->length) {
        throw string("getElement: position out of bounds");
    }

    while (position > 0) {
        position--;
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    typename LinkedList<T>::Node *curr = head;

    if (position < 0 || position >= this->length) {
        throw string("getElement: position out of bounds");
    }

    while (position--) {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    typename LinkedList<T>::Node *prev = head;

    if (position < 0 || position >= this->length) {
        throw string("remove: position out of bounds");
    }

    typename LinkedList<T>::Node *to_delete = nullptr;
    if (position == 0) {
        to_delete = head;
        head = head->next;
    } else {
        for (int i = 0; i < position - 1; i++) {
            prev = prev->next;
        }
        to_delete = prev->next;
        prev->next = to_delete->next;
    }

    delete to_delete;
    this->length--;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
