#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/link.cpp"

TEST_CASE( "returns nullptr for head of empty list" ) {
    LinkedList<std::string> list;
    REQUIRE(list.get_head() == nullptr);
}

TEST_CASE( "returns head node with correct material" ) {
    LinkedList<std::string> list;
    Link<std::string> gold = Link<std::string>("gold");
    Node<std::string>* node_one = new Node(&gold);
    list.add(node_one);
    REQUIRE( list.get_head()->link->get_material() == "gold" );
}

TEST_CASE( "retrieve next node from node" ) {
    LinkedList<std::string> list;
    Link<std::string> gold = Link<std::string>("gold");
    Node<std::string>* node_one = new Node(&gold);
    list.add(node_one);

    Link<std::string> silver = Link<std::string>("silver");
    Node<std::string>*  node_two = new Node(&silver);
    list.add(node_two);

    Link<std::string> bronze = Link<std::string>("bronze");
    Node<std::string>*  node_three = new Node(&bronze);
    list.add(node_three);

    Node<std::string>*  retrieved_node_two = node_one->next;
    Node<std::string>*  retrieved_node_three = node_two->next;
    REQUIRE(retrieved_node_two->link->get_material() == "silver");
    REQUIRE(retrieved_node_three->link->get_material() == "bronze");
}

TEST_CASE("works with integers") {
    LinkedList<int> numList;
    Link<int> day = Link<int>(22);
    Node<int>* num_node_one = new Node(&day);
    numList.add(num_node_one);

    REQUIRE(numList.get_head()->link->get_material() == 22);
    REQUIRE(numList.get_head()->next == nullptr);
}
