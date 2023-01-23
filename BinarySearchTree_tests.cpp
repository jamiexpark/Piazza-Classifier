// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}

TEST(test_ctor) {
    BinarySearchTree<int> hi;
    hi.empty();
    ASSERT_TRUE(hi.empty());
}


TEST(test_size) {
    BinarySearchTree<int> hi;
    hi.empty();
    ASSERT_TRUE(hi.empty());
    
    hi.size();
    ASSERT_EQUAL(hi.size(), 0);
}

TEST(test_max) {
    BinarySearchTree<int> hi;
    hi.empty();
    ASSERT_TRUE(hi.empty());
    
    hi.size();
    ASSERT_EQUAL(hi.size(), 0);
}

TEST(test_insert) {
    BinarySearchTree<int> hi;
    hi.insert(3);
    ASSERT_TRUE(!hi.empty());
    
    hi.size();
    ASSERT_EQUAL(hi.size(), 1);
}

TEST(test_insert2) {
    BinarySearchTree<int> hi;
    hi.insert(4);
    hi.insert(1);
    hi.insert(3);

    hi.size();
    ASSERT_EQUAL(hi.size(), 3);
}


TEST(test_min_element) {
    BinarySearchTree<int> hi;
    BinarySearchTree<int>::Iterator hello;
    hi.insert(2);
    hi.insert(3);
    hi.insert(4);
    hello = hi.min_element();
    hi.size();
    ASSERT_EQUAL(*hello, 2);
}



TEST(test_max_element) {
    BinarySearchTree<int> hi;
    BinarySearchTree<int>::Iterator hello;
    hi.insert(3);
    hi.insert(2);
    hello = hi.max_element();
    hi.size();
    ASSERT_EQUAL(*hello, 3);
}


TEST(test_insert3) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(1);
    hi.insert(3);
    hi.insert(5);
    BinarySearchTree<int>::Iterator hello;
    hello = hi.max_element();
    ASSERT_EQUAL(hi.height(), 3)
    ASSERT_EQUAL(hi.size(), 4);
    ASSERT_EQUAL(*hello, 5);

    hello = hi.min_element();
    ASSERT_EQUAL(*hello, 1);

    hello = hi.begin();
    ASSERT_EQUAL(*hello, 1);
}


TEST(test_inorder_impl) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(1);
    
    
    std::ostringstream output;
    hi.traverse_inorder(output);
    std::cout << output.str();
    ASSERT_EQUAL(output.str(), "1 4 ");
}


//TEST(test_prenorder_impl) {
//    BinarySearchTree<int> hi;
//    ASSERT_EQUAL(hi.empty(), true);
//    hi.insert(4);
//    hi.insert(7);
//    hi.insert(16);
////    hi.insert(29);
////    hi.insert(31);
//
//    std::ostringstream output;
//    hi.traverse_preorder(output);
//    ASSERT_EQUAL(output.str(), "4 7 16 ");
//}

TEST(test_insert4l) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(2);
    hi.insert(1);
    hi.insert(3);
    hi.insert(7);
    
    std::ostringstream output;
    hi.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), "1 2 3 7 ");
}

//TEST(test_insert42) {
//    BinarySearchTree<int> hi;
//    ASSERT_EQUAL(hi.empty(), true);
//    hi.insert(1);
//    hi.insert(2);
//    hi.insert(3);
//    hi.insert(4);
//    BinarySearchTree<int>::Iterator hello = hi.min_element();
//
//    ASSERT_EQUAL(*hello, 1);
//
//    hello = hi.max_element();
//    ASSERT_EQUAL(*hello, 4);
//
//    ASSERT_EQUAL(hi.size(), 3);
//    ASSERT_EQUAL(hi.height(), 3);
//    std::ostringstream output;
//    hi.find(2);
//    std::cout << output.str();
//
//
//    ASSERT_EQUAL(hi.size(), 4);
//    ASSERT_EQUAL(hi.height(), 3);
//}

TEST(test_min_greater_than) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(1);
    hi.insert(3);
    hi.insert(2);
    
    std::ostringstream output;
    hi.traverse_inorder(output);
    std::cout << output.str();
    ASSERT_EQUAL(output.str(), "1 2 3 4 ");
    
}


TEST(test_min_greater_than2) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(3);
    hi.insert(2);
    hi.insert(1);
    
    ASSERT_EQUAL(hi.size(), 4);
    int output = *hi.min_greater_than(1);
    ASSERT_EQUAL(output, 2);
}

TEST(test_min_greater_than3) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(3);
    hi.insert(2);
    hi.insert(1);
    hi.insert(32);
    hi.insert(6);
    hi.insert(5);
    
    
    ASSERT_EQUAL(hi.size(), 7);
    int output = *hi.min_greater_than(1);
    ASSERT_EQUAL(output, 2);
}


TEST(test_preor) {
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(4);
    hi.insert(3);
    hi.insert(1);
    hi.insert(2);
    
    
    std::ostringstream output;
    hi.traverse_preorder(output);
    std::cout << output.str();
    ASSERT_EQUAL(output.str(), "4 3 1 2 ");
}


TEST(sorting_invariant){
    
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(3);
    hi.insert(5);
    hi.insert(4);
    hi.insert(1);
    ASSERT_EQUAL(hi.size(), 4);
    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}
TEST(sorting_invariant2){
    
    BinarySearchTree<int> hi;
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(0);
    hi.insert(-2);
    hi.insert(-4);

    ASSERT_EQUAL(hi.size(), 4);
    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}

TEST(copy_nodes){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
 
    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(3);
    hi.insert(2);
    hi.insert(5);
    meow = hi.min_element();

    ASSERT_EQUAL(hi.size(), 4);
    ASSERT_EQUAL(meow.operator*(), 1);
    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}

TEST(copy_nodes_maybe){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(0);
    meow = hi.begin();
    ASSERT_EQUAL(meow.operator*(), 0);

    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}

TEST(empty_to_big_and_operators){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    ASSERT_EQUAL(hi.size(), 0);
    ASSERT_EQUAL(hi.height(), 0);
    hi.insert(4);
    hi.insert(24245);
    hi.insert(224);
    hi.insert(4586);
    hi.insert(-294);
    
    ASSERT_EQUAL(hi.size(), 5);
    ASSERT_EQUAL(hi.height(), 4);
    meow = hi.begin();
//    ASSERT_EQUAL(hi.min_element(), 4);
    

    ASSERT_EQUAL(meow.operator*(), -294);
    ASSERT_EQUAL(*meow++, -294);
    ASSERT_EQUAL(*++meow, 224);
    
    
}

TEST(diff_type_string){
    
    BinarySearchTree<std::string> hi;
    BinarySearchTree<std::string>:: Iterator meow;

    ASSERT_EQUAL(hi.size(), 0);
    ASSERT_EQUAL(hi.height(), 0);
    hi.insert("mike");
    hi.insert("jam");
    hi.insert("meow");
    
    ASSERT_EQUAL(hi.size(), 3);
    ASSERT_EQUAL(hi.height(), 3);
    meow = hi.begin();
//    ASSERT_EQUAL(hi.min_element(), 4);
    

    ASSERT_EQUAL(meow.operator*(), "jam");
    ASSERT_EQUAL(*meow++, "jam");
    ASSERT_EQUAL(*++meow, "mike");
    
    std::ostringstream output;
    hi.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), "mike jam meow ");
    
    
    std::ostringstream output2;
    hi.traverse_inorder(output2);
    ASSERT_EQUAL(output.str(), "mike jam meow ");
    
    std::string correct = "meow";
    
    ASSERT_EQUAL(*hi.min_greater_than("jam"), correct);
    ASSERT_EQUAL(*hi.min_element(), "jam");
    ASSERT_EQUAL(*hi.max_element(), "mike");
    
}

TEST(diff_type_char){
    
    BinarySearchTree<char> hi;
    BinarySearchTree<char>:: Iterator meow;

    ASSERT_EQUAL(hi.size(), 0);
    ASSERT_EQUAL(hi.height(), 0);
    hi.insert('m');
    hi.insert('j');
    hi.insert('a');
    
    ASSERT_EQUAL(hi.size(), 3);
    ASSERT_EQUAL(hi.height(), 3);
    meow = hi.begin();

    ASSERT_EQUAL(meow.operator*(), 'a');
    ASSERT_EQUAL(*meow++, 'a');
    ASSERT_EQUAL(*++meow, 'm');
    
    std::ostringstream output;
    hi.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), "m j a ");
    
    
    std::ostringstream output2;
    hi.traverse_inorder(output2);
    ASSERT_EQUAL(output.str(), "m j a ");
    
    char correct = 'j';
    
    ASSERT_EQUAL(*hi.min_greater_than('a'), correct);
    ASSERT_EQUAL(*hi.min_element(), 'a');
    ASSERT_EQUAL(*hi.max_element(), 'm');
    
}



TEST(copy_nodes_fr){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(0);
    meow = hi.begin();
    ASSERT_EQUAL(meow.operator*(), 0);
    BinarySearchTree<int> hi2(hi);
    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}

TEST(copy_nodes_frfr){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(0);
    hi.insert(23);
    hi.insert(5);
    hi.insert(-2);
    hi.insert(6);
    meow = hi.begin();
    ASSERT_EQUAL(meow.operator*(), -2);
    BinarySearchTree<int> hi2(hi);
    ASSERT_EQUAL(*hi2.begin(), *hi.begin());
    ASSERT_EQUAL(hi2.size(), hi.size());
    ASSERT_EQUAL(hi2.height(), hi.height());
    ASSERT_EQUAL(*hi2.min_element(), *hi.min_element());
    ASSERT_EQUAL(*hi2.min_greater_than(1), *hi.min_greater_than(1));
    hi2.insert(-4);
    hi.insert(-4);
    
    ASSERT_EQUAL(*hi2.begin(), *hi.begin());
    hi.insert(-5);
    hi.insert(-6);
    
    ASSERT_NOT_EQUAL(*hi2.begin(), *hi.begin());
    ASSERT_EQUAL(hi.check_sorting_invariant(), true);
}


TEST(invariants){
    
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    ASSERT_EQUAL(hi.empty(), true);
    hi.insert(1);
    hi.insert(0);
    meow = hi.begin();
    meow.operator*() = 2;

    ASSERT_EQUAL(hi.check_sorting_invariant(), false);
}

TEST(sorting_time){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(1);
    hi.insert(4);
    hi.insert(0);
    hi.insert(-399);
    hi.insert(229);
    meow = hi.max_element();
    ASSERT_EQUAL(hi.size(), 5);
    
    meow.operator*() = -3984234;
    ASSERT_FALSE(hi.check_sorting_invariant());
    
}

TEST(invariants_empty){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    
    ASSERT_TRUE(hi.check_sorting_invariant());
}

TEST(invariants_more){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(0);
    hi.insert(-2);
    hi.insert(-5);
    hi.insert(458934);
    meow = hi.find(-5);
    meow.operator*() = 23222; 
    ASSERT_FALSE(hi.check_sorting_invariant());
}


TEST(confirm_max_element){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(0);
    hi.insert(-2);
    hi.insert(-5);
    hi.insert(4);
    hi.insert(345);
    hi.insert(-111);
    meow = hi.find(0);
    meow.operator*() = 55555;
    ASSERT_TRUE(hi.check_sorting_invariant());
    
    ASSERT_EQUAL(hi.max_element().operator*() , 345);
    
}

TEST(sorting_more){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(0);
    hi.insert(-2);
    hi.insert(-5);
    hi.insert(4);
    hi.insert(345);
    hi.insert(-24);
    hi.insert(25);
    hi.insert(455);
    hi.insert(124);
    hi.insert(-11);
    hi.insert(-555);
    hi.insert(7);
    hi.insert(9);
    hi.insert(-123);
    meow = hi.find(-555);
    meow.operator*() = 4414;
    ASSERT_EQUAL(hi.max_element().operator*() , 455);
    
    
    hi.min_element().operator*() = meow.operator*();
    
}


TEST(greater_than_doesnt_exist){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(0);

    ASSERT_TRUE(hi.check_sorting_invariant());
    meow = hi.end();
    ASSERT_TRUE(hi.min_greater_than(3) == meow);
    ASSERT_TRUE(hi.min_greater_than(3) == meow);
    

    
}

TEST(less_than_doesnt_exist){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    hi.insert(0);

    ASSERT_TRUE(hi.check_sorting_invariant());
    meow = hi.min_element();
    ASSERT_TRUE(hi.min_element() == meow);
    ASSERT_TRUE(meow.operator*() ==  0);
    
}


TEST(assignment_operator){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;
    BinarySearchTree<int> hi2;
    BinarySearchTree<int>:: Iterator meow2;
    hi.insert(0);
    hi.insert(-2);
    hi.insert(6);
    hi.insert(45);
    hi.insert(-552);
    hi.insert(-22);
    hi.insert(-7);
    
    hi2 = hi2.operator=(hi);
    
    meow = hi.find(-2);
    meow2 = hi2.find(-2);
    ASSERT_EQUAL(hi.size(), hi2.size());
    ASSERT_TRUE(hi.check_sorting_invariant());

    ASSERT_EQUAL(meow.operator*(), meow2.operator*());
    meow.operator++();
    meow2.operator++();
    
    ASSERT_EQUAL(meow.operator*(), meow2.operator*());
    
}

TEST(traverse_on_nothing){
    BinarySearchTree<int> hi;
    BinarySearchTree<int>:: Iterator meow;

    meow = hi.end();
    ASSERT_EQUAL(hi.size(), 0);
    ASSERT_EQUAL(hi.height(), 0);
    ASSERT_EQUAL(hi.empty(), true);
    
    std::ostringstream output;
    hi.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), "");
    
    
    std::ostringstream output2;
    hi.traverse_inorder(output2);
    ASSERT_EQUAL(output.str(), "");
    
}
TEST(exam_practice1){
    BinarySearchTree<int> hi;
    hi.insert(6);
    hi.insert(4);
    hi.insert(7);
    hi.insert(3);
    hi.insert(8);
    hi.insert(2);
    
    hi.greatestPath();

}





//TEST(test_preor2) {
//    BinarySearchTree<int> hi;
//TEST(test_preor2) {
//    BinarySearchTree<int> hi;
//    ASSERT_EQUAL(hi.empty(), true);
//    hi.insert(1);
//    hi.insert(3);
//    hi.insert(2);
//
//    ASSERT_EQUAL(hi.size(), 3);
//    std::ostringstream output;
//    hi.traverse_preorder(output);
//    std::cout << output.str();
//    ASSERT_EQUAL(output.str(), "1 3 2");
//}



TEST_MAIN()
