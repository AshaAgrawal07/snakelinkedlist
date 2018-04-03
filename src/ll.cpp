#include "ll.h"
#include <vector>

namespace snakelinkedlist {

	//MODIFIERS

	//given during lecture:  https://courses.engr.illinois.edu/cs126/sp2018/slides/L20-Big5Lists.pdf
	//using given code for : push_front, pop_front, and pop_back 
	void LinkedList::push_front(SnakeBodySegment value) {
		ListNode *new_node = new ListNode(value);
		new_node->next_ = head_;
		head_ = new_node;
	}

	void LinkedList::push_back(SnakeBodySegment value) {
		ListNode *new_node = new ListNode(value);
		if (!head_) {
			push_front(value);
		} else {
			ListNode *tail = head_;
			while (tail->next_) {
				tail = tail->next_;
			}
			tail->new_node;
			new_node->nullptr;
		}
	}

	void LinkedList::pop_front() {
		if (!head_) {
			return;
		} 
		ListNode *tmp = head_;
		if (!head_->next_) {
			head_ == nullptr;
		} else {
			head_ = head_->next_;
		}
		delete tmp;
	}

	void LinkedList::pop_back() {
		if (!head_) {
			return;
		}
		ListNode *remove_next = head_;
		while (remove_next->next_ && remove_next->next_->next_) {
			remove_next = remove_next->next_;
		}
		delete remove_next->next_;
		remove_next = nullptr;
	}

	void LinkedList::RemoveNth(int n) {
		if (n == 0) {
			pop_front();
		} else if (n == size() - 1) {
			pop_back();
		}
		else if (n < 0 || n >= size()) {
			return;
		} else {
			int counter = n - 1;
			ListNode *previous = head_;
			ListNode *current = head_->next_;
			//iterate to get current to the nth node
			while (counter > 0) {
				current->next_;
				previous->next_;
			}
			//now point previous to the next of the current and take the nth element out
			previous = current->next_;
			delete current;
		}
	}

	void LinkedList::clear() {
		ListNode *current = head_;
		ListNode *next;
		while (current != NULL) {
			next = current->next_;
			delete current;
			current = next;
		}
	}

	//ACCESSORS

	SnakeBodySegment LinkedList::front() const{
		if (size() == 0) {
			return SnakeBodySegment();
		}
		return SnakeBodySegment(head_->data_);
	}

	SnakeBodySegment LinkedList::back() const{
		if (size() == 0) {
			return SnakeBodySegment();
		}

		ListNode *current = head_;
		while(current->next_) {
			current = current->next_;
		}
		return SnakeBodySegment(current->next_->data_);
	}

	int LinkedList::size() const{
		int counter = 0;
		ListNode *current = head_;
		while (current != NULL) {
			current = current->next_;
			counter++;
		}
		delete current;
		return counter;
	}

	std::vector<SnakeBodySegment> LinkedList::GetVector() const{
		ListNode* current = head_;
		std::vector<SnakeBodySegment> snake_data;
		while (current != NULL) {
			snake_data.push_back(SnakeBodySegment{ current->data_ });
		}
		delete current;
		return snake_data;
	}

	bool LinkedList::empty() const{
		if (size() == 0) {
			return true;
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
		ListNode* current = list.head_;
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

	bool operator==(const LinkedList& rhs) const{
		ListNode* current = rhs.head_->next_;
		while (current != NULL) {
			if (rhs.head_ != current) {
				delete current;
				return false;
			}
			current = current->next_;
		}
		return true;
	}

	bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
		if (rhs == lhs) {
			return false;
		}
		return true;
	}

	//DEFAULT CONSTRUCTOR
	LinkedList::LinkedList() {
		head_ = NULL;
	}

	//INITALIZE FROM VECTOR
	explicit LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
		ListNode *current = head_;
		for (int i = 0; i < values.size() - 1; i++) {
			current = values[i];
			current = current->next_;
		}
		current = values[values.size() - 1];
		current->next_ = nullptr;
	}

	//BIG 5
	//Delete LinkedList
	LinkedList::~LinkedList() {
		clear();
		head_ = NULL;
	}



} // namespace snakelinkedlist
