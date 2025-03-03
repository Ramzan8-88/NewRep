//Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_MergingLists/MergingLists.h"
#include "../lib_List/List.h"
TEST(TestMergeSortedLists, CanMergeTwoSortedLists) {
    List<int> list1;
    List<int> list2;

    list1.append(1);
    list1.append(3);
    list1.append(5);

    list2.append(2);
    list2.append(4);
    list2.append(6);

    List<int> merged = mergeSortedLists(list1, list2);

    int expected[] = { 1, 2, 3, 4, 5, 6 };
    int count = 0;

    for (auto it = merged.head; it != nullptr; it = it->next) {
        EXPECT_EQ(it->data, expected[count]);
        ++count;
    }
    EXPECT_EQ(count, 6);
}

TEST(TestMergeSortedLists, CanMergeTwoEmptyLists) {
    List<int> list1;
    List<int> list2;

    List<int> merged = mergeSortedLists(list1, list2);

    EXPECT_EQ(merged.head, nullptr); // Ожидается, что результат пуст
}

TEST(TestMergeSortedLists, CanMergeEmptyAndNonEmptyList) {
    List<int> list1;
    List<int> list2;

    list2.append(1);
    list2.append(2);
    list2.append(3);

    List<int> merged1 = mergeSortedLists(list1, list2);
    List<int> merged2 = mergeSortedLists(list2, list1); // Проверка с пустым списком первым

    int expected[] = { 1, 2, 3 };

    int count = 0;
    for (auto it = merged1.head; it != nullptr; it = it->next) {
        EXPECT_EQ(it->data, expected[count]);
        ++count;
    }
    EXPECT_EQ(count, 3);

    count = 0;
    for (auto it = merged2.head; it != nullptr; it = it->next) {
        EXPECT_EQ(it->data, expected[count]);
        ++count;
    }
    EXPECT_EQ(count, 3);
}

TEST(TestMergeSortedLists, CanMergeListsWithSameElements) {
    List<int> list1;
    List<int> list2;

    list1.append(1);
    list1.append(1);
    list1.append(1);

    list2.append(1);
    list2.append(1);
    list2.append(1);

    List<int> merged = mergeSortedLists(list1, list2);

    int expected[] = { 1, 1, 1, 1, 1, 1 };
    int count = 0;

    for (auto it = merged.head; it != nullptr; it = it->next) {
        EXPECT_EQ(it->data, expected[count]);
        ++count;
    }
    EXPECT_EQ(count, 6);
}

TEST(TestMergeSortedLists, CanMergeListsOfUnequalLength) {
    List<int> list1;
    List<int> list2;

    list1.append(1);
    list1.append(3);

    list2.append(2);
    list2.append(4);
    list2.append(5);
    list2.append(6);

    List<int> merged = mergeSortedLists(list1, list2);

    int expected[] = { 1, 2, 3, 4, 5, 6 };
    int count = 0;

    for (auto it = merged.head; it != nullptr; it = it->next) {
        EXPECT_EQ(it->data, expected[count]);
        ++count;
    }
    EXPECT_EQ(count, 6);
}