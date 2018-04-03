#include "ll.h"


namespace snakelinkedlist {

	//MODIFIERS

	//given during lecture:  https://courses.engr.illinois.edu/cs126/sp2018/slides/L20-Big5Lists.pdf
	//using given code for : push_front, pop_front, and pop_back 
	void push_front(SnakeBodySegment value) {
		ListNode *new_node = new ListNode(value);
		new_node->next_ = head_;
		head_ = new_node;
	}

	void push_back(SnakeBodySegment value) {
		ListNode *new_node = new ListNode(value);
		if (!head_) {
			push_front(value);
		} else {
			ListNode *tail = head_;
			while (tail->next_) {
				tail = tail->next_;
			}
			tail->new_node;
			new_node ->nullptr;
		}
	}

	void pop_front() {
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

	void pop_back() {
		if (!head_) {
			return;
		}
		ListNode *remove_next = head_;
		while (remove_next->next_ && remove_next->next_->next) {
			remove_next = remove_next->next_;
		}
		delete remove_next->next;
		remove_next = nullptr;
	}

	void removeNth(int n) {
		if (n == 0) {
			pop_front();
		} else if (n == this.size() - 1) {
			pop_back();
		}
		else if (n < 0 || n >= this.size()) {
			return;
		} else {
			counter = n - 1;
			ListNode *previous = head_;
			ListNode *current = head_->next;
			//iterate to get current to the nth node
			while (counter > 0) {
				current->next_;
				previous->next_;
			}
			//now point previous to the next of the current and take the nth element out
			previous = current->next;
			delete current;
		}
	}

	void clear() {
		ListNode *current = head_;
		ListNode *next;
		while (current != NULL) {
			next = current->next_;
			delete current;
			current = next;
		}
	}

	//ACCESSORS

	SnakeBodySegment front() {
		if (size() == 0) {
			return SnakeBodySegment();
		}
		return this.head_;
	}

	SnakeBodySegment back() {
		if (size() == 0) {
			return SnakeBodySegment();
		}

		ListNode *current = head_;
		while(current->next) {
			current = current->next_;
		}
		return current->next_;
	}

	int size() {
		int counter = 0;
		ListNode *current = head_;
		while (current != NULL) {
			current = current->next_;
			counter++;
		}
		delete current;
		return counter;
	}

	std::vector<SnakeBodySegment> GetVector() {
		ListNode* current = head_;
		std::vector<SnakeBodySegment> snake_data;
		while (current != NULL) {
			vector.push_back(SnakeBodySegment{ current->data_ });
		}
		delete current;
		return snake_data;
	}

	bool empty() {
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

	bool operator==(const LinkedList& rhs) {
		ListNode* current = head_->next_;
		while (current != NULL) {
			if (head_ != current) {
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
	LinkedList::LinkedList() : head_(nullptr);

	//INITALIZE FROM VECTOR
	explicit LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
		ListNode *current = head_;
		for (int i = 0; i < values.size - 1; i++) {
			current = value[i];
			current = current->next_;
		}
		current = values[values.size - 1];
		current->next_ = nullptr;
	}

	//BIG 5
	//Delete LinkedList
	LinkedList::~LinkedList() {
		clear();
		*head_ = NULL;
	}



} // namespace snakelinkedlist
