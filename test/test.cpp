#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/ll.h"
#include "../src/snakebody.h"
#include <vector>
#include <iostream>

//TESTS FOR MODIFIER METHODS
namespace snakelinkedlist {
    using namespace std;

    TEST_CASE("test test") {
        LinkedList<int> test_list = LinkedList<int>();
        test_list.push_back(1);
        test_list.push_back(2);
        test_list.push_back(3);

        std::cout << "Stuff: " << (test_list.back()) << endl;
    }

    TEST_CASE("push_front tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE((snake_list->size() == 1));

        REQUIRE(snake_list->head_->data_ == snakelinkedlist::SnakeBodySegment{1});
        REQUIRE(snake_list->head_->next_ == nullptr);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->size() == 2);
        REQUIRE((snake_list->head_->data_ == snakelinkedlist::SnakeBodySegment(2)));
        REQUIRE(snake_list->head_->next_->next_ == nullptr);


    }

    TEST_CASE("push_back test cases") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->size() == 0);
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_back(*add2);
        REQUIRE(snake_list->size() == 2);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_->next_ == nullptr);
    }

    TEST_CASE("pop_front tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_ == nullptr);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
        snake_list->pop_front();
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
    }

    TEST_CASE("pop_back tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_ == nullptr);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->head_->data_ == 1);
        REQUIRE(snake_list->head_->next_ == nullptr);
        snake_list->pop_back();
        REQUIRE(snake_list->size() == 0);
        REQUIRE(snake_list->head_->next_ == nullptr);
    }

    TEST_CASE("removeNth tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_back(*add2);

        snakelinkedlist::SnakeBodySegment* add3 = new snakelinkedlist::SnakeBodySegment(3);
        snake_list->push_back(*add3);

        snakelinkedlist::SnakeBodySegment *add4 = new snakelinkedlist::SnakeBodySegment(4);
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
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snake_list->clear();
        REQUIRE(snake_list->size() == 0);
        //REQUIRE(*snake_list.front() == nullptr);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        snake_list->clear();
        REQUIRE(snake_list->size() == 0);
    }

//TESTS FOR ACCESSOR METHODS

    TEST_CASE("front() tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add0 = new snakelinkedlist::SnakeBodySegment();
        snake_list->push_front(*add0);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE(snake_list->front() == snakelinkedlist::SnakeBodySegment{1});

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->front() == snakelinkedlist::SnakeBodySegment{2});

        snakelinkedlist::SnakeBodySegment* add3 = new snakelinkedlist::SnakeBodySegment(3);
        snake_list->push_front(*add3);
        REQUIRE(snake_list->front() == snakelinkedlist::SnakeBodySegment{3});
    }

    TEST_CASE("back() tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE((snake_list->back()) == SnakeBodySegment(0));

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->back() == snakelinkedlist::SnakeBodySegment{1});

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_back(*add2);
        REQUIRE(snake_list->back() == snakelinkedlist::SnakeBodySegment{2});

        snakelinkedlist::SnakeBodySegment* add3 = new snakelinkedlist::SnakeBodySegment(3);
        snake_list->push_front(*add3);
        REQUIRE(snake_list->back() == snakelinkedlist::SnakeBodySegment{2});
    }

    TEST_CASE("size() tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->size() == 0);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->size() == 1);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_front(*add2);
        REQUIRE(snake_list->size() == 2);

        snake_list->pop_front();
        REQUIRE(snake_list->size() == 1);

        snake_list->pop_back();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("getVector() tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        std::vector<snakelinkedlist::SnakeBodySegment> empty = {snakelinkedlist::SnakeBodySegment()};
        REQUIRE(snake_list->GetVector() != empty);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        std::vector<snakelinkedlist::SnakeBodySegment> one_elem = {snakelinkedlist::SnakeBodySegment{1}};
        REQUIRE(snake_list->GetVector() == one_elem);

        snakelinkedlist::SnakeBodySegment *add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_back(*add2);
        std::vector<snakelinkedlist::SnakeBodySegment> two_elem = {snakelinkedlist::SnakeBodySegment{1},
                                                                   snakelinkedlist::SnakeBodySegment{2}};
        REQUIRE(snake_list->GetVector() == two_elem);
    }

    TEST_CASE("empty tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->empty() == true);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        REQUIRE(snake_list->empty() == false);

        snake_list->pop_back();
        REQUIRE(snake_list->empty() == true);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add2);
        snake_list->clear();
        REQUIRE(snake_list->empty() == true);
    }

    TEST_CASE("<< overload tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment> snake_list = LinkedList<snakelinkedlist::SnakeBodySegment>();
        //expecting ""
        std::cout << snake_list;

        snake_list.push_back(snakelinkedlist::SnakeBodySegment{1});
        //expecting "1"
        std::cout << snake_list;

        snake_list.push_back(snakelinkedlist::SnakeBodySegment{2});
        //expecting "1, 2"
        std::cout << snake_list;
    }

    TEST_CASE("== overload tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list_2 = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE((snake_list->size() == snake_list_2->size()) == true);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE((snake_list == snake_list_2) == false);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list_2->push_front(*add2);
        REQUIRE((snake_list == snake_list_2) == true);

        snake_list->pop_back();
        REQUIRE((snake_list == snake_list_2) == false);

        snake_list_2->pop_front();
        REQUIRE((snake_list == snake_list_2) == true);
    }

    TEST_CASE("!= overload tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list_2 = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE((snake_list != snake_list_2) == false);

        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add1);
        REQUIRE((snake_list != snake_list_2) == true);

        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_front(*add2);
        REQUIRE((snake_list != snake_list_2) == false);

        snake_list->pop_back();
        REQUIRE((snake_list != snake_list_2) == true);

        snake_list_2->pop_front();
        REQUIRE((snake_list != snake_list_2) == false);
    }

//TESTS FOR CONSTRUCTORS AND BIG 5

    TEST_CASE("default constructor test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("construct linked list from vector tests") {
        vector<snakelinkedlist::SnakeBodySegment> snakes;
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snakes.push_back(*add1);
        snakes.push_back(*add2);

        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>(snakes);
        REQUIRE(snake_list->size() == 2);
        REQUIRE(snake_list->GetVector() == snakes);

        vector<snakelinkedlist::SnakeBodySegment> snakes2;
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>(snakes2);
        REQUIRE(snake_list2->size() == 0);
        REQUIRE(snake_list2->GetVector() == snakes2);
    }

    TEST_CASE("destructor tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        snake_list->~LinkedList();
        REQUIRE(snake_list->size() == 0);
    }

    TEST_CASE("deep copy constructor test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>(*snake_list);
        REQUIRE(snake_list->size() == snake_list2->size());
        REQUIRE(snake_list2->size() != 0);
        }

    TEST_CASE("move constructor test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>(*snake_list);
        REQUIRE(snake_list->size() == 1);
        REQUIRE(snake_list2->size() == 0);
    }

    TEST_CASE("copy assignment tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);

        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snake_list2->operator=(*snake_list);
        REQUIRE(snake_list2->size() == 1);
    }

    TEST_CASE("move assignment tests") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);

        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snake_list2->operator=(*snake_list);
        REQUIRE(snake_list2->size() == 1);
    }

    //ITERATOR TESTS
    TEST_CASE("default constructor") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        auto iterator = snake_list->begin();
        REQUIRE(iterator.current_ = nullptr);
    }

    TEST_CASE("++ test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list->push_back(*add2);

        auto iterator = snake_list->begin();
        REQUIRE(iterator.current_->data_ == snakelinkedlist::SnakeBodySegment(1));
        iterator.operator++();
        REQUIRE(iterator.current_->data_ == snakelinkedlist::SnakeBodySegment(2));
    }

    TEST_CASE("* test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);

        auto iterator = snake_list->begin();
        REQUIRE(iterator.operator*() == snakelinkedlist::SnakeBodySegment(1));
    }

    TEST_CASE("!= test") {
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add1 = new snakelinkedlist::SnakeBodySegment(1);
        snake_list->push_back(*add1);
        LinkedList<snakelinkedlist::SnakeBodySegment>* snake_list2 = new LinkedList<snakelinkedlist::SnakeBodySegment>();
        snakelinkedlist::SnakeBodySegment* add2 = new snakelinkedlist::SnakeBodySegment(2);
        snake_list2->push_back(*add2);

        auto iterator = snake_list->begin();
        auto iterator2 = snake_list2->begin();
        REQUIRE((iterator.operator!=(iterator2)) == true);
    }

    TEST_CASE("begin() test") {
        
    }
}