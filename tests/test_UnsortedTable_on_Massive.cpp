// Copyright 2025 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_TUnsortedTable/UnsortedTable_on_massive.h"
#include "../lib_ITable/ITable.h"
#include "../lib_pair/pair.h"
#include "../lib_DMassive/DMassive.h"

#define EPSILON 0.000001

TEST(UnsortedTableTest, can_insert) {
    // Arrange
    UnsortedTable<int, std::string> table;

    // Act
    int key = table.insert("Value1");

    // Assert
    EXPECT_EQ(table[key], "Value1");
}

TEST(UnsortedTableTest, can_insert_with_key) {
    // Arrange
    UnsortedTable<int, std::string> table;

    // Act
    table.insert(1, "Value1");
    table.insert(2, "Value2");

    // Assert
    EXPECT_EQ(table[1], "Value1");
    EXPECT_EQ(table[2], "Value2");
}

TEST(UnsortedTableTest, can_find_by_key) {
    // Arrange
    UnsortedTable<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");

    // Act & Assert
    EXPECT_EQ(table.find(1), "Value1");
    EXPECT_EQ(table.find(2), "Value2");
}

TEST(UnsortedTableTest, throw_when_key_not_found) {
    // Arrange
    UnsortedTable<int, std::string> table;
    table.insert(1, "Value1");

    // Act & Assert
    ASSERT_THROW(table.find(2), std::out_of_range);
}

TEST(UnsortedTableTest, can_erase_by_key) {
    // Arrange
    UnsortedTable<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");

    // Act
    table.erase(1);

    // Assert
    ASSERT_THROW(table.find(1), std::out_of_range);
    EXPECT_EQ(table.find(2), "Value2");
}

TEST(UnsortedTableTest, can_access_using_operator) {
    // Arrange
    UnsortedTable<int, std::string> table;
    table.insert(1, "Value1");

    // Act & Assert
    EXPECT_EQ(table[1], "Value1");
}

TEST(UnsortedTableTest, can_assign_table) {
    // Arrange
    UnsortedTable<int, std::string> table1;
    table1.insert(1, "Value1");
    table1.insert(2, "Value2");

    UnsortedTable<int, std::string> table2;

    // Act
    table2 = table1;

    // Assert
    EXPECT_EQ(table2[1], "Value1");
    EXPECT_EQ(table2[2], "Value2");
}

TEST(UnsortedTableTest, self_assignment) {
    // Arrange
    UnsortedTable<int, std::string> table;
    table.insert(1, "Value1");

    // Act & Assert
    table = table;
    EXPECT_EQ(table[1], "Value1");
}

TEST(UnsortedTableTest, can_find_in_empty_table) {
    // Arrange
    UnsortedTable<int, std::string> table;

    // Act & Assert
    ASSERT_THROW(table.find(1), std::out_of_range);
}