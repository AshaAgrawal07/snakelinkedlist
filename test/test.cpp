#include "../src/ll.h"
#include "../src/snakebody.h"
#include "../test/catch.hpp"
#include <vector>

using namespace snakelinkedlist {
	TEST_CASE("push_front tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		snake_list.push_front(SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		snake_list.push_front(SnakeBodySegment{ 2 });
		REQUIRE(snake_list.size() = 2);
		REQUIRE(snake_list.head_.data_ == 2);
		REQUIRE(snake_list.head_->next_.data_ == 1);
		REQUIRE(*snake_list.head_->next_->next == nullptr);
	}

	TEST_CASE("push_back test cases") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		snake_list.push_back(SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		snake_list.push_back(SnakeBodySegment{ 2 });
		REQUIRE(snake_list.size() == 2);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(snake_list.head_->next_.data == 2);
		REQUIRE(*snake_list.head_->next_->next_ == nullptr);
	}

	TEST_CASE("pop_front tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		REQUIRE(snake_list.size == 0);
		REQUIRE(*snake_list.head_ == nullptr);

		snake_list.push_back(SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_front();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);

	}

	TEST_CASE("pop_back tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);

		snake_list.push_back(SnakeBodySegment{ 1 });
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_back();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);
	}

	TEST_CASE("removeNth tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		snake_list.push_back(SnakeBodySegment{ 1 });
		snake_list.push_back(SnakeBodySegment{ 2 });
		snake_list.push_back(SnakeBodySegment{ 3 });
		snake_list.push_back(SnakeBodySegment{ 4 });

		//tests that will not return anything, so check that size remains same
		snake_list.removeNth(-1);
		REQUIRE(snake_list.size() == 4);
		snake_list.removeNth(4);
		REQUIRE(snake_list.size() == 4);

		//tests that will see if pop front was called and executed properly
		snake_list.removeNth(0); //new size is 3
		REQUIRE(snake_list.size() == 3);
		REQUIRE(snake_list.head_.data == 2);
		
		//check again that something over the size cannot be removed
		snake_list.removeNth(3);
		REQUIRE(snake_list.size() == 3);

		//tests that will see if pop back was called and executed properly
		snake_list.removeNth(2);
		REQUIRE(snake_list.size() == 2);
		REQUIRE(snake_list.head_.data_ == 2);
		REQUIRE(snake_list.head_->next_.data_ == 3);
		REQUIRE(*snake_list.head_->next->next == nullptr)
	}

	TEST_CASE("clear tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList;
		snake_list.clear();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);

		snake_list.push_back(SnakeBodySegment{ 1 });
		snake_list.clear();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);
	}

	std::cin >> int x;
}