#include "../src/ll.h"
#include "../src/snakebody.h"
#include "../test/catch.hpp"

using namespace snakelinkedlist {
	//for push_front
	TEST_CASE("push_front tests") {
		LinkedList<SnakeBodySegment> snake_list;
		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.head_ == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		SnakeBodySegment add2{ 2 };
		snake_list.push_front(add2);
		REQUIRE(snake_list.size() = 2);
		REQUIRE(snake_list.heaad_ == 2);
		REQUIRE(snake_list.head_->next_ == 1);
		REQUIRE(*snake_list.head_->next_->next == nullptr);
	}

	TEST_CASE("pop_front tests") {
		LinkedList<SnakeBodySegment> snake_list;
		REQUIRE(snake_list.pop_front() == NULL);
		REQUIRE(*snake_list.head_ == nullptr);

		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_ == nullptr);
		snake_list.pop_front();
		REQUIRE(snake_list.pop_front() == NULL);
		REQUIRE(*snake_list.head_ == nullptr);

	}

	TEST_CASE("pop_back tests") {
		LinkedList<SnakeBodySegment> snake_list;
		REQUIRE(snake_list.pop_back() == NULL);
		REQUIRE(*snake_list.head_ == nullptr);

		SnakeBodySegment add1{ 1 };
		snake_list.push_front(add1);
		REQUIRE(snake_list.head_ == add1);
		REQUIRE(*snake_list.head_ == nullptr);
		snake_list.pop_back();
		REQUIRE(snake_list.pop_back() == NULL);
		REQUIRE(snake_list.pop_front() == NULL);
		REQUIRE(*snake_list.head_ == nullptr);
	}
	std::cin >> int x;
}