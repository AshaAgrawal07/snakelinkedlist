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

	void pop_front() {
		if (!head_) {
			return;
		} 
		ListNode *tmp = head_;
		head_ = head_->next_;
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

} // namespace snakelinkedlist
