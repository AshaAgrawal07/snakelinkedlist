#include "../src/ll.h"
#include "../src/snakebody.h"
#include "../test/catch.hpp"
#include <vector>

	//TESTS FOR MODIFIER METHODS

	TEST_CASE("push_front tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.front() == 1);
		REQUIRE(*(snake_list.front()->next_) == nullptr);

		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE(snake_list.size() = 2);
		REQUIRE(snake_list.front() == 2);
		REQUIRE(snake_list.head_->next_.data_ == 1);
		REQUIRE(*snake_list.head_->next_->next == nullptr);
	}

	TEST_CASE("push_back test cases") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.front() == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE(snake_list.size() == 2);
		REQUIRE(snake_list.front() == 1);
		REQUIRE(snake_list.head_->next_.data == 2);
		REQUIRE(*snake_list.head_->next_->next_ == nullptr);
	}

	TEST_CASE("pop_front tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.size == 0);
		REQUIRE(*snake_list.front() == nullptr);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);
		REQUIRE(snake_list.front() == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_front();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.front() == nullptr);

	}

	TEST_CASE("pop_back tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.front() == nullptr);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.front() == 1);
		REQUIRE(*snake_list.head_->next_ == nullptr);
		snake_list.pop_back();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.front() == nullptr);
	}

	TEST_CASE("removeNth tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 3 });
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 4 });

		//tests that will not return anything, so check that size remains same
		snake_list.RemoveNth(-1);
		REQUIRE(snake_list.size() == 4);
		snake_list.RemoveNth(4);
		REQUIRE(snake_list.size() == 4);

		//tests that will see if pop front was called and executed properly
		snake_list.RemoveNth(0); //new size is 3
		REQUIRE(snake_list.size() == 3);
		REQUIRE(snake_list.front() == 2);
		
		//check again that something over the size cannot be removed
		snake_list.RemoveNth(3);
		REQUIRE(snake_list.size() == 3);

		//tests that will see if pop back was called and executed properly
		snake_list.RemoveNth(2);
		REQUIRE(snake_list.size() == 2);
		REQUIRE(snake_list.front() == 2);
		REQUIRE(snake_list.head_->next_.data_ == 3);
		REQUIRE(*snake_list.head_->next->next == nullptr);
	}

	TEST_CASE("clear tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snake_list.clear();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.front() == nullptr);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		snake_list.clear();
		REQUIRE(snake_list.size() == 0);
		REQUIRE(*snake_list.front() == nullptr);
	}

	//TESTS FOR ACCESSOR METHODS

	TEST_CASE("front() tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.front() == snakelinkedlist::SnakeBodySegment());
		
		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.front() == 1);
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE(snake_list.front() == 1);
		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 3 });
		REQUIRE(snake_list.front() == 3);
	}

	TEST_CASE("back() tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.back() == snakelinkedlist::SnakeBodySegment());

		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.back() == 1);
		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE(snake_list.back() == 2);
		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 3 });
		REQUIRE(snake_list.back() == 2);
	}

	TEST_CASE("size() tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.size() == 0);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.size() == 1);

		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE(snake_list.size() == 2);

		snake_list.pop_front();
		REQUIRE(snake_list.size() == 1);

		snake_list.pop_back();
		REQUIRE(snake_list.size() == 0);
	}

	TEST_CASE("getVector() tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		std::vector<snakelinkedlist::SnakeBodySegment> empty = { snakelinkedlist::SnakeBodySegment() };
		REQUIRE(snake_list.GetVector() == empty);

		snake_list.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		std::vector<snakelinkedlist::SnakeBodySegment> one_elem = { snakelinkedlist::SnakeBodySegment{1} };
		REQUIRE(snake_list.GetVector() == one_elem);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		std::vector<snakelinkedlist::SnakeBodySegment> two_elem = { snakelinkedlist::SnakeBodySegment{1},
															   snakelinkedlist::SnakeBodySegment{2} };
		REQUIRE(snake_list.GetVector() == two_elem);
	}

	TEST_CASE("empty tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE(snake_list.empty() == true);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(snake_list.empty() == false);

		snake_list.pop_back();
		REQUIRE(snake_list.empty() == true);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		snake_list.clear();
		REQUIRE(snake_list.empty() == true);
	}

	TEST_CASE("<< overload tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		REQUIRE((cout << snake_list) == "");

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE((cout << snake_list) == "1");

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 2 });
		REQUIRE((cout << snake_list) == "1, 2");
	}

	TEST_CASE("== overload with 1 param tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snakelinkedlist::LinkedList snake_list_2 = snakelinkedlist::LinkedList();
		REQUIRE(((cout << snake_list) == snake_list_2) == true);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(((cout << snake_list) == snake_list_2) == false);

		snake_list_2.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE(((cout << snake_list) == snake_list_2) == true);

		snake_list.pop_back();
		REQUIRE(((cout << snake_list) == snake_list_2) == false);

		snake_list_2.pop_front();
		REQUIRE(((cout << snake_list) == snake_list_2) == true);
	}

	TEST_CASE("== overload with 2 params tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snakelinkedlist::LinkedList snake_list_2 = snakelinkedlist::LinkedList();
		REQUIRE((snake_list == snake_list_2) == true);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE((snake_list == snake_list_2) == false);

		snake_list_2.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE((snake_list == snake_list_2) == true);

		snake_list.pop_back();
		REQUIRE((snake_list == snake_list_2) == false);

		snake_list_2.pop_front();
		REQUIRE((snake_list == snake_list_2) == true);
	}

	TEST_CASE("!= overload tests") {
		snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
		snakelinkedlist::LinkedList snake_list_2 = snakelinkedlist::LinkedList();
		REQUIRE((snake_list != snake_list_2) == false);

		snake_list.push_back(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE((snake_list != snake_list_2) == true);

		snake_list_2.push_front(snakelinkedlist::SnakeBodySegment{ 1 });
		REQUIRE((snake_list != snake_list_2) == false);

		snake_list.pop_back();
		REQUIRE((snake_list != snake_list_2) == true);

		snake_list_2.pop_front();
		REQUIRE((snake_list != snake_list_2) == false);
	}

	TEST_CASE("default constructor test") {

	}