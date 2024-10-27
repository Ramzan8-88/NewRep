// Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_list/list.h"

TEST(TNodeTest, DefaultConstructor) {
    TNode<int> node(5);
    EXPECT_EQ(node.getValue(), 5);
    EXPECT_EQ(node.getNext(), nullptr);
}

TEST(TNodeTest, SetValue) {
    TNode<int> node(5);
    node.setValue(10);
    EXPECT_EQ(node.getValue(), 10);
}

TEST(TNodeTest, SetNext) {
    TNode<int> node1(5);
    TNode<int> node2(10);
    node1.setNext(&node2);
    EXPECT_EQ(node1.getNext(), &node2);
}

TEST(TNodeTest, EqualityOperator) {
    TNode<int> node1(5);
    TNode<int> node2(5);
    TNode<int> node3(10);
    EXPECT_TRUE(node1 == node2);
    EXPECT_FALSE(node1 == node3);
}

TEST(TNodeTest, OutputStreamOperator) {
    TNode<int> node(5);
    std::stringstream ss;
    ss << node;
    EXPECT_EQ(ss.str(), "5");
}

TEST(TListTest, DefaultConstructor) {
    TList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(TListTest, InsertFront) {
    TList<int> list;
    list.insertFront(5);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.find(5)->getValue(), 5);
}

TEST(TListTest, InsertBack) {
    TList<int> list;
    list.insertBack(10);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.find(10)->getValue(), 10);
}

TEST(TListTest, InsertAfter) {
    TList<int> list;
    list.insertFront(5);
    TNode<int>* node = list.find(5);
    list.insertAfter(node, 10);
    EXPECT_EQ(list.find(10)->getValue(), 10);
}

TEST(TListTest, InsertAt) {
    TList<int> list;
    list.insertBack(1);
    list.insertBack(3);
    list.insertAt(1, 2);
    EXPECT_EQ(list.find(2)->getValue(), 2);
}

TEST(TListTest, RemoveFront) {
    TList<int> list;
    list.insertFront(5);
    list.removeFront();
    EXPECT_TRUE(list.isEmpty());
}

TEST(TListTest, RemoveBack) {
    TList<int> list;
    list.insertFront(5);
    list.insertBack(10);
    list.removeBack();
    EXPECT_EQ(list.find(5)->getValue(), 5);
    EXPECT_EQ(list.find(10), nullptr);
}

TEST(TListTest, RemoveAt) {
    TList<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.removeAt(1);
    EXPECT_EQ(list.find(2), nullptr);
}

TEST(TListTest, RemoveNode) {
    TList<int> list;
    list.insertBack(1);
    TNode<int>* node = list.find(1);
    list.removeNode(node);
    EXPECT_TRUE(list.isEmpty());
}

TEST(TListTest, ReplaceNode) {
    TList<int> list;
    list.insertBack(1);
    TNode<int>* node = list.find(1);
    list.replaceNode(node, 2);
    EXPECT_EQ(list.find(2)->getValue(), 2);
}

TEST(TListTest, ReplaceAt) {
    TList<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.replaceAt(1, 3);
    EXPECT_EQ(list.find(3)->getValue(), 3);
}

TEST(TListTest, AssignmentOperator) {
    TList<int> list1;
    list1.insertBack(1);
    list1.insertBack(2);
    TList<int> list2;
    list2 = list1;
    EXPECT_EQ(list2.find(1)->getValue(), 1);
    EXPECT_EQ(list2.find(2)->getValue(), 2);
}

TEST(TListTest, OutputStreamOperator) {
    TList<int> list;
    list.insertBack(1);
    list.insertBack(2);
    std::stringstream ss;
    ss << list;
    EXPECT_EQ(ss.str(), "1 -> 2 -> null");
}

TEST(TListTest, InsertAfterNullptrThrows) {
    TList<int> list;
    EXPECT_THROW(list.insertAfter(nullptr, 5), std::invalid_argument);
}

TEST(TListTest, InsertAtInvalidPositionThrows) {
    TList<int> list;
    EXPECT_THROW(list.insertAt(-1, 5), std::out_of_range);
    EXPECT_THROW(list.insertAt(1, 5), std::out_of_range);
}

TEST(TListTest, RemoveAtInvalidPositionThrows) {
    TList<int> list;
    EXPECT_THROW(list.removeAt(-1), std::out_of_range);
    EXPECT_THROW(list.removeAt(0), std::out_of_range);
}

TEST(TListTest, RemoveNodeNullptrThrows) {
    TList<int> list;
    EXPECT_THROW(list.removeNode(nullptr), std::invalid_argument);
}

TEST(TListTest, ReplaceNodeNullptrThrows) {
    TList<int> list;
    EXPECT_THROW(list.replaceNode(nullptr, 5), std::invalid_argument);
}

TEST(TListTest, ReplaceAtInvalidPositionThrows) {
    TList<int> list;
    EXPECT_THROW(list.replaceAt(-1, 5), std::out_of_range);
    EXPECT_THROW(list.replaceAt(0, 5), std::out_of_range);
}
