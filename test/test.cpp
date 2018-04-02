#include "../src/ll.h"
#include "../src/snakebody.h"
#include "../test/catch.hpp"
#include <vector>

using namespace snakelinkedlist {
	TEST_CASE("push_front tests") {
		LinkedList<SnakeBodySegment<int>> snake_list;
		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		SnakeBodySegment add2{ 2 };
		snake_list.push_front(add2);
		REQUIRE(snake_list.size() = 2);
		REQUIRE(snake_list.head_.data_ == 2);
		REQUIRE(snake_list.head_->next_.data_ == 1);
		REQUIRE(*snake_list.head_->next_->next == nullptr);
	}

	TEST_CASE("push_back test cases") {
		LinkedList<SnakeBodySegment<int>> snake_list;
		SnakeBodySegment add1{ 1 };
		snake_list.push_back(add1);
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		SnakeBodySegment add2{ 2 };
		snake_list.push_back(add2);
		REQUIRE(snake_list.size() == 2);
		REQUIRE(snake_list.head_.data_ == 1);
		REQUIRE(snake_list.head_->next_.data == 2);
		REQUIRE(*snake_list.head_->next_->next_ == nullptr);
	}

	TEST_CASE("pop_front tests") {
		LinkedList<SnakeBodySegment<int>> snake_list;
		REQUIRE(snake_list.size == 0);
		REQUIRE(*snake_list.head_ == nullptr);

		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_front();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);

	}

	TEST_CASE("pop_back tests") {
		LinkedList<SnakeBodySegment<int>> snake_list;
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);

		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_back();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.head_ == nullptr);
	}
	std::cin >> int x;
}