// Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_vector/vector.h"

TEST(VectorTest, can_create_empty_vector) {
    // Act
    Vector<int> vec;

    // Assert
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, can_create_vector_with_size_and_value) {
    // Act
    Vector<int> vec(5, 10);

    // Assert
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 10);
    }
}

TEST(VectorTest, can_create_vector_from_array) {
    // Arrange
    int arr[] = { 1, 2, 3 };

    // Act
    Vector<int> vec(arr, 3);

    // Assert
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, can_create_vector_from_initializer_list) {
    // Act
    Vector<int> vec = { 4, 5, 6 };

    // Assert
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 4);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec[2], 6);
}

TEST(VectorTest, can_copy_vector) {
    // Arrange
    Vector<int> vec1 = { 1, 2, 3 };

    // Act
    Vector<int> vec2 = vec1;

    // Assert
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

TEST(VectorTest, can_assign_vector) {
    // Arrange
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2;

    // Act
    vec2 = vec1;

    // Assert
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

TEST(VectorTest, can_add_vectors) {
    // Arrange
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2 = { 4, 5, 6 };

    // Act
    Vector<int> result = vec1 + vec2;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST(VectorTest, can_subtract_vectors) {
    // Arrange
    Vector<int> vec1 = { 5, 7, 9 };
    Vector<int> vec2 = { 1, 2, 3 };

    // Act
    Vector<int> result = vec1 - vec2;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 5);
    EXPECT_EQ(result[2], 6);
}

TEST(VectorTest, can_multiply_vector_by_scalar) {
    // Arrange
    Vector<int> vec = { 1, 2, 3 };

    // Act
    Vector<int> result = vec * 2;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 6);
}

TEST(VectorTest, can_add_assign_vectors) {
    // Arrange
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2 = { 4, 5, 6 };

    // Act
    vec1 += vec2;

    // Assert
    EXPECT_EQ(vec1.size(), 3);
    EXPECT_EQ(vec1[0], 5);
    EXPECT_EQ(vec1[1], 7);
    EXPECT_EQ(vec1[2], 9);
}

TEST(VectorTest, can_subtract_assign_vectors) {
    // Arrange
    Vector<int> vec1 = { 5, 7, 9 };
    Vector<int> vec2 = { 1, 2, 3 };

    // Act
    vec1 -= vec2;

    // Assert
    EXPECT_EQ(vec1.size(), 3);
    EXPECT_EQ(vec1[0], 4);
    EXPECT_EQ(vec1[1], 5);
    EXPECT_EQ(vec1[2], 6);
}

TEST(VectorTest, can_compare_vectors) {
    // Arrange
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2 = { 1, 2, 3 };
    Vector<int> vec3 = { 4, 5, 6 };

    // Assert
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_FALSE(vec1 == vec3);
}

TEST(VectorTest, can_not_add_vectors_with_different_sizes) {
    // Arrange
    Vector<int> vec1 = { 1, 2 };
    Vector<int> vec2 = { 1 };

    // Act & Assert
    ASSERT_THROW(vec1 + vec2, std::invalid_argument);
}

TEST(VectorTest, can_not_subtract_vectors_with_different_sizes) {
    // Arrange
    Vector<int> vec1 = { 1, 2 };
    Vector<int> vec2 = { 1 };

    // Act & Assert
    ASSERT_THROW(vec1 - vec2, std::invalid_argument);
}

TEST(VectorTest, can_not_add_assign_vectors_with_different_sizes) {
    // Arrange
    Vector<int> vec1 = { 1, 2 };
    Vector<int> vec2 = { 1 };

    // Act & Assert
    ASSERT_THROW(vec1 += vec2, std::invalid_argument);
}

TEST(VectorTest, can_not_subtract_assign_vectors_with_different_sizes) {
    // Arrange
    Vector<int> vec1 = { 1, 2 };
    Vector<int> vec2 = { 1 };

    // Act & Assert
    ASSERT_THROW(vec1 -= vec2, std::invalid_argument);
}