// Copyright 2025 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_SortedTable/SortedTable_on_massive.h"
#include "../lib_ITable/ITable.h"
#include "../lib_pair/pair.h"
#include "../lib_DMassive/DMassive.h"

#define EPSILON 0.000001

TEST(SortedTableTest, can_insert_and_find) {
    // Arrange
    SortedTable<int, std::string> table;

    // Act
    int key1 = table.insert("First");
    std::string actual_result = table.find(key1);

    // Assert
    std::string expected_result = "First";
    EXPECT_EQ(expected_result, actual_result);
}

TEST(SortedTableTest, can_erase_element) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    int key2 = table.insert("Second");

    // Act
    table.erase(key2);

    // Assert
    ASSERT_ANY_THROW(table.find(key2));
}

TEST(SortedTableTest, can_find_element_with_binary_search) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    int key2 = table.insert("Second");

    // Act & Assert
    EXPECT_EQ(table.find(key1), "First");
    EXPECT_EQ(table.find(key2), "Second");
}

TEST(SortedTableTest, can_use_operator_square_brackets_for_find) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("Test");

    // Act
    std::string actual_result = table[key1];

    // Assert
    EXPECT_EQ(actual_result, "Test");
}

TEST(SortedTableTest, can_copy_and_assign_table) {
    // Arrange
    SortedTable<int, std::string> table1;
    int key1 = table1.insert("First");
    int key2 = table1.insert("Second");

    // Act
    SortedTable<int, std::string> table2 = table1;
    SortedTable<int, std::string> table3;
    table3 = table1;

    // Assert
    EXPECT_EQ(table2.find(key1), "First");
    EXPECT_EQ(table2.find(key2), "Second");
    EXPECT_EQ(table3.find(key1), "First");
    EXPECT_EQ(table3.find(key2), "Second");
}

TEST(SortedTableTest, can_generate_keys_automatically) {
    // Arrange
    SortedTable<int, std::string> table;

    // Act
    int key1 = table.insert("Item1");
    int key2 = table.insert("Item2");

    // Assert
    EXPECT_EQ(key1 + 1, key2);
}

TEST(SortedTableTest, can_find_after_multiple_insert_and_erase) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    int key2 = table.insert("Second");
    table.erase(key1);

    // Act & Assert
    EXPECT_EQ(table.find(key2), "Second");
    ASSERT_ANY_THROW(table.find(key1));
}

TEST(SortedTableTest, can_insert_with_same_key) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    int key2 = table.insert("First");

    // Act & Assert
    EXPECT_EQ(table.find(key1), "First");
    EXPECT_EQ(table.find(key2), "First");
}

TEST(SortedTableTest, generate_keys_in_sequence) {
    // Arrange
    SortedTable<int, std::string> table;

    // Act
    int key1 = table.insert("Item1");
    int key2 = table.insert("Item2");
    int key3 = table.insert("Item3");

    // Assert
    EXPECT_EQ(key1 + 1, key2);
    EXPECT_EQ(key2 + 1, key3);
}

TEST(SortedTableTest, insert_after_erase) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    table.erase(key1);

    // Act
    int key2 = table.insert("Second");

    // Assert
    EXPECT_EQ(table.find(key2), "Second");
}

TEST(SortedTableTest, insert_in_middle) {
    // Arrange
    SortedTable<int, std::string> table;
    int key1 = table.insert("First");
    int key2 = table.insert("Third");

    // Act
    int key3 = table.insert("Second");

    // Assert
    EXPECT_EQ(table.find(key1), "First");
    EXPECT_EQ(table.find(key3), "Second");
    EXPECT_EQ(table.find(key2), "Third");
}