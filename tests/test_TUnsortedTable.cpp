// Copyright 2025 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_TUnsortedTable/TUnsortedTable.h"
#include "../lib_List/List.h"
#include "../lib_pair/pair.h"

#define EPSILON 0.000001

TEST(TUnsortedTableTest, can_insert_and_find_by_key) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act
    int key1 = table.insert("Hello");
    int key2 = table.insert("World");

    // Assert
    EXPECT_EQ("Hello", table.find(key1));
    EXPECT_EQ("World", table.find(key2));
}

TEST(TUnsortedTableTest, can_insert_with_given_key) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act
    table.insert(1, "One");
    table.insert(2, "Two");

    // Assert
    EXPECT_EQ("One", table.find(1));
    EXPECT_EQ("Two", table.find(2));
}

TEST(TUnsortedTableTest, can_access_by_operator) {
    // Arrange
    TUnsortedTable<int, std::string> table;
    int key = table.insert("Test");

    // Act & Assert
    EXPECT_EQ("Test", table[key]);
}

TEST(TUnsortedTableTest, throw_when_access_by_operator_with_non_existing_key) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act & Assert
    ASSERT_THROW(table[1], std::out_of_range);
}

TEST(TUnsortedTableTest, can_erase_by_key) {
    // Arrange
    TUnsortedTable<int, std::string> table;
    int key = table.insert("To be erased");

    // Act
    table.erase(key);

    // Assert
    ASSERT_THROW(table.find(key), std::out_of_range);
}

TEST(TUnsortedTableTest, can_assign_another_table) {
    // Arrange
    TUnsortedTable<int, std::string> table1;
    table1.insert(1, "One");
    table1.insert(2, "Two");

    // Act
    TUnsortedTable<int, std::string> table2;
    table2 = table1;

    // Assert
    EXPECT_EQ("One", table2.find(1));
    EXPECT_EQ("Two", table2.find(2));
}

TEST(TUnsortedTableTest, can_work_with_empty_table) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act & Assert
    ASSERT_THROW(table.find(1), std::out_of_range);
    ASSERT_THROW(table[1], std::out_of_range);
}

TEST(TUnsortedTableTest, can_insert_and_generate_key) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act
    int key1 = table.insert("Item 1");
    int key2 = table.insert("Item 2");

    // Assert
    EXPECT_EQ("Item 1", table.find(key1));
    EXPECT_EQ("Item 2", table.find(key2));
    EXPECT_NE(key1, key2);
}

TEST(TUnsortedTableTest, throw_when_key_not_found) {
    // Arrange
    TUnsortedTable<int, std::string> table;

    // Act & Assert
    ASSERT_THROW(table.find(999), std::out_of_range);
}