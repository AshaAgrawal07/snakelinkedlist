#include <utility>
#include "ll.h"
#include <vector>

template<typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {

}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : head_(nullptr), tail_(nullptr), size_(0) {
    if (values.size() > 0){
        for (int i = 0; i < values.size(); i++) {
            push_back(values.at(i));
        }
    }
}

// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
    if (source.head_) {
        head_ = new ListNode(*source.head_);
        ListNode *current = head_;
        ListNode *original = source.head_;

        while (original->next_) {
            //current->next_ = new ListNode(original->data_);
            original = original->next_;
            current->next_ = original;
            current = current->next_;
        }
    } else {
        head_ = nullptr;
    }
    this->size_ = source.size_;
}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
    size_ = source.size_;
    head_ = source.head_;
    ListNode *current = head_;
    ListNode *original = source.head_;

    while (original->next_) {
        original = original->next_;
        current->next_ = original;
        current = current->next_;
    }

    source.size_ = 0;
}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    clear();
}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
    if (this == &source) {
        return *this;
    } else {
        head_ = source.head_;
        ListNode *current = head_;
        ListNode *original = source.head_;

        while (original->next_) {
            current->next_ = new ListNode(original->data_);
            original = original->next_;
            current = current->next_;
        }
        return *this;
    }
}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {
    if (this == &source) {
        return *this;
    } else {
        delete head_;
        head_ = source.head_;
        source.head_ = nullptr;
        return *this;
    }
}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
    ListNode *new_node = new ListNode(value);
    new_node->next_ = head_;
    head_ = new_node;
    size_++;
}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    ListNode *add_node = new ListNode(value);
    if (!head_) {
        push_front(value);
    } else {
        ListNode *tail = head_;
        while (tail->next_) {
            tail = tail->next_;
        }
        tail->next_ = add_node;
        size_++;
    }
}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
    if (size() == 0) {
        return SnakeBodySegment();
    }
    return SnakeBodySegment(head_->data_);
}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    if (size() == 0) {
        return SnakeBodySegment();
    }

    ListNode *current = head_;
    while (current->next_ != nullptr) {
        current = current->next_;
    }
    return current->data_;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {
    if (!head_) {
        return;
    }
    ListNode *tmp = head_;
    if (!head_->next_) {
        head_ = nullptr;
    } else {
        size_--;
        head_ = head_->next_;
    }
    delete tmp;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {
    if (!head_) {
        return;
    }
    ListNode *remove_next = head_;
    while (remove_next->next_ && remove_next->next_->next_) {
        remove_next = remove_next->next_;
    }
    delete remove_next->next_;
    remove_next = nullptr;
    size_--;
}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
    return size_;
}

template<typename ElementType>
std::vector<ElementType> LinkedList<ElementType>::GetVector() const {
    ListNode *current = head_;
    vector<SnakeBodySegment> snake_data;
    while (current != nullptr) {
        snake_data.push_back(current->data_);
        current = current->next_;
    }
    return snake_data;
}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
    if (size() == 0) {
        return true;
    }
    return false;
}

template<typename ElementType>
void LinkedList<ElementType>::clear() {
    ListNode *current = head_;
    ListNode *next;
    while (current != nullptr) {
        next = current->next_;
        delete current;
        current = next;
    }
    size_ = 0;
}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
    ListNode *current = list.head_;
    if (list.size() == 1) {
        os << current->data_;
    } else {
        while (current && current->next_) {
            os << current->data_ << ", ";
            current = current->next_;
        }
        if (list.size() > 1) {
            os << current->data_;
        }
    }
}

template<typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
    if (n == 0) {
        pop_front();
    } else if (n == size() - 1) {
        pop_back();
    } else if (n < 0 || n >= size()) {
        return;
    } else {
        ListNode *current = head_;

        //iterate to get current to the nth node
        for (int counter = n - 1; counter > 0; counter--) {
            current = current->next_;
        }
        //now point previous to the next of the current and take the nth element out
        ListNode *link = current->next_->next_;
        delete current->next_;
        current->next_ = link;
        size_--;
    }
}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
    if (this->size() != rhs.size()) {
        return false;
    }
    ListNode* curr = this->head_;
    ListNode* current = rhs.head_;
    while (current != nullptr) {
        if (curr->data_ != current->data_) {
            return false;
        }
        current = current->next_;
        curr = curr->next_;
    }
    return true;
}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {
    if(lhs.size() != rhs.size()) {
        return true;
    }
    ListNode* curr = lhs.head_;
    ListNode* current = rhs.head_;
    while (current != NULL && curr != NULL) {
        if (curr->data_ == current->data_) {
            return false;
        }
        current = current->next_;
        curr = curr->next_;
    }
    return true;
}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator& LinkedList<ElementType>::Iterator::operator++() {
    if(current_) {
        current_->current_->next_;
    }
    return *this;
}

template<typename ElementType>
ElementType& LinkedList<ElementType>::Iterator::operator*() {
    return current_->data_;
}

template<typename ElementType>
bool LinkedList<ElementType>::Iterator::operator!=(const LinkedList<ElementType>::Iterator& other) {
    return (current_ != other.current_);
}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::begin() {
    Iterator start;
    start.current_ = head_;
    return start;
}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::end() {
    Iterator stop;
    stop.current_ = nullptr;
    return stop;
}
