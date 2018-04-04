#define CATCH_CONFIG_MAIN
#include "../src/ll.h"
#include "../src/snakebody.h"
#include "catch.hpp"
#include <vector>
#include <iostream>

//TESTS FOR MODIFIER METHODS
namespace snakelinkedlist {
    using namespace std;

    TEST_CASE("push_front tests") {
        LinkedList *snake_list = new LinkedList();
        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE(snake_list->size() == 1);

        REQUIRE(snake_list->head_->data_ == SnakeBodySegment{1});
        REQUIRE(snake_list->head_->next_ == nullptr);

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->size() == 2);
        REQUIRE(snake_list->head_->data_ == 2);
        REQUIRE(snake_list->head_->next_->next_ == nullptr);
    }

    TEST_CASE("push_back test cases") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->size() == 0);
        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_back(*add2);
        REQUIRE(snake_list->size() == 2);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_->next_ == nullptr);
    }

    TEST_CASE("pop_front tests") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_ == nullptr);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
        snake_list->pop_front();
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
    }

    TEST_CASE("pop_back tests") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_ == nullptr);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
        snake_list->pop_back();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_->next_ == nullptr);
    }

    TEST_CASE("removeNth tests") {
        LinkedList *snake_list = new LinkedList();

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_back(*add2);

        SnakeBodySegment *add3 = new SnakeBodySegment(3);
        snake_list->push_back(*add3);

        SnakeBodySegment *add4 = new SnakeBodySegment(4);
        snake_list->push_back(*add4);

        //tests that will not return anything, so check that size remains same
        snake_list->RemoveNth(-1);
        REQUIRE(snake_list->size() == 4);
        snake_list->RemoveNth(4);
        REQUIRE(snake_list->size() == 4);

        //tests that will see if pop front was called and executed properly
        snake_list->RemoveNth(0); //new size is 3
        REQUIRE(snake_list->size() == 3);
        REQUIRE(snake_list->head_->data_ == 2);

        //check again that something over the size cannot be removed
        snake_list->RemoveNth(3);
        REQUIRE(snake_list->size() == 3);

        //tests that will see if pop back was called and executed properly
        snake_list->RemoveNth(1);
        REQUIRE(snake_list->size() == 2);
        REQUIRE(snake_list->head_->data_ == 2);
        //REQUIRE(snake_list->GetVector().at(2) == SnakeBodySegment{3});
        REQUIRE(snake_list->head_->next_->next_ == nullptr);
    }

    TEST_CASE("clear tests") {
        LinkedList *snake_list = new LinkedList();
        snake_list->clear();
        REQUIRE(snake_list->size() == 0);
        //REQUIRE(*snake_list.front() == nullptr);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        snake_list->clear();
        REQUIRE(snake_list->size() == 0);
    }

//TESTS FOR ACCESSOR METHODS

    TEST_CASE("front() tests") {
        LinkedList *snake_list = new LinkedList();
        SnakeBodySegment *add0 = new SnakeBodySegment();
        snake_list->push_front(*add0);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE(snake_list->front() == SnakeBodySegment{1});

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->front() == SnakeBodySegment{2});

        SnakeBodySegment *add3 = new SnakeBodySegment(3);
        snake_list->push_front(*add3);
        REQUIRE(snake_list->front() == SnakeBodySegment{3});
    }

    TEST_CASE("back() tests") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE((snake_list->back()) == SnakeBodySegment(0));

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->back() == SnakeBodySegment{1});

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_back(*add2);
        REQUIRE(snake_list->back() == SnakeBodySegment{2});

        SnakeBodySegment *add3 = new SnakeBodySegment(3);
        snake_list->push_front(*add3);
        REQUIRE(snake_list->back() == SnakeBodySegment{2});
    }

    TEST_CASE("size() tests") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->size() == 0);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->size() == 1);

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->size() == 2);

        snake_list->pop_front();
        REQUIRE(snake_list->size() == 1);

        snake_list->pop_back();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("getVector() tests") {
        LinkedList *snake_list = new LinkedList();
        std::vector<snakelinkedlist::SnakeBodySegment> empty = {snakelinkedlist::SnakeBodySegment()};
        REQUIRE(snake_list->GetVector() == empty);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        std::vector<snakelinkedlist::SnakeBodySegment> one_elem = {snakelinkedlist::SnakeBodySegment{1}};
        REQUIRE(snake_list->GetVector() == one_elem);

        SnakeBodySegment *add2 = new SnakeBodySegment(2);
        snake_list->push_back(*add2);
        std::vector<snakelinkedlist::SnakeBodySegment> two_elem = {snakelinkedlist::SnakeBodySegment{1},
                                                                   snakelinkedlist::SnakeBodySegment{2}};
        REQUIRE(snake_list->GetVector() == two_elem);
    }
/*
    TEST_CASE("empty tests") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->empty() == true);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->empty() == false);

        snake_list->pop_back();
        REQUIRE(snake_list->empty() == true);

        SnakeBodySegment *add2 = new SnakeBodySegment(1);
        snake_list->push_front(*add2);
        snake_list->clear();
        REQUIRE(snake_list->empty() == true);
    }

//TEST_CASE("<< overload tests") {
//    snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
//    REQUIRE((cout << snake_list) == "");
//
//    snake_list.push_back(snakelinkedlist::SnakeBodySegment{1});
//    REQUIRE((cout << snake_list) == "1");
//
//    snake_list.push_back(snakelinkedlist::SnakeBodySegment{2});
//    REQUIRE((cout << snake_list) == "1, 2");
//}

//TEST_CASE("== overload with 1 param tests") {
//    snakelinkedlist::LinkedList snake_list = snakelinkedlist::LinkedList();
//    snakelinkedlist::LinkedList snake_list_2 = snakelinkedlist::LinkedList();
//    REQUIRE(((cout << snake_list) == snake_list_2) == true);
//
//    snake_list.push_back(snakelinkedlist::SnakeBodySegment{1});
//    REQUIRE(((cout << snake_list) == snake_list_2) == false);
//
//    snake_list_2.push_front(snakelinkedlist::SnakeBodySegment{1});
//    REQUIRE(((cout << snake_list) == snake_list_2) == true);
//
//    snake_list.pop_back();
//    REQUIRE(((cout << snake_list) == snake_list_2) == false);
//
//    snake_list_2.pop_front();
//    REQUIRE(((cout << snake_list) == snake_list_2) == true);
//}

    TEST_CASE("== overload with 2 params tests") {
        LinkedList *snake_list = new LinkedList();
        LinkedList *snake_list_2 = new LinkedList();
        REQUIRE((snake_list == snake_list_2) == true);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE((snake_list == snake_list_2) == false);

        SnakeBodySegment *add2 = new SnakeBodySegment(1);
        snake_list_2->push_front(*add2);
        REQUIRE((snake_list == snake_list_2) == true);

        snake_list->pop_back();
        REQUIRE((snake_list == snake_list_2) == false);

        snake_list_2->pop_front();
        REQUIRE((snake_list == snake_list_2) == true);
    }

    TEST_CASE("!= overload tests") {
        LinkedList *snake_list = new LinkedList();
        LinkedList *snake_list_2 = new LinkedList();
        REQUIRE((snake_list != snake_list_2) == false);

        SnakeBodySegment *add1 = new SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE((snake_list != snake_list_2) == true);

        SnakeBodySegment *add2 = new SnakeBodySegment(1);
        snake_list->push_front(*add2);
        REQUIRE((snake_list != snake_list_2) == false);

        snake_list->pop_back();
        REQUIRE((snake_list != snake_list_2) == true);

        snake_list_2->pop_front();
        REQUIRE((snake_list != snake_list_2) == false);
    }

//TESTS FOR CONSTRUCTORS AND BIG 5

    TEST_CASE("default constructor test") {
        LinkedList *snake_list = new LinkedList();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("construct linked list from vector tests") {
        vector<SnakeBodySegment> snakes = {1, 2, 3, 4, 0};
        LinkedList *snake_list = new LinkedList(snakes);
        REQUIRE(snake_list->size() == 5);
        REQUIRE(snake_list->GetVector() == snakes);

        vector<SnakeBodySegment> snakes2 = {};
        LinkedList *snake_list2 = new LinkedList(snakes2);
        REQUIRE(snake_list2->size() == 5);
        REQUIRE(snake_list2->GetVector() == snakes2);
    }

    TEST_CASE("destructor tests") {
        vector<SnakeBodySegment> snakes = {1, 2, 3, 4, 0};
        LinkedList *snake_list = new LinkedList(snakes);
        snake_list->~LinkedList();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("deep copy constructor tests") {
        vector<SnakeBodySegment> snakes = {1, 2, 3, 4, 0};
        LinkedList *snake_list = new LinkedList(snakes);
        LinkedList *snake_list2 = new LinkedList(*snake_list);
        REQUIRE(snake_list == snake_list2);

        snake_list->pop_back();
        LinkedList *snake_list3 = new LinkedList(*snake_list);
        REQUIRE(snake_list == snake_list3);
    }

    TEST_CASE("move constructor tests") {
        vector<SnakeBodySegment> snakes = {1, 2, 3, 4, 0};
        LinkedList *snake_list = new LinkedList(snakes);
        LinkedList *snake_list2 = new LinkedList(*snake_list);
        REQUIRE(snake_list->head_ == snake_list2->head_);

        snake_list->pop_back();
        LinkedList *snake_list3 = new LinkedList(*snake_list);
        REQUIRE(snake_list->head_ == snake_list3->head_);
    }*/
}