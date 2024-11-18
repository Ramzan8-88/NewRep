//Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_Vector/Vector.h"

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
    Vector<int> vec(arr, 3);

    // Assert
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, can_copy_vector) {
    // Arrange
    Vector<int> vec1(3, 5);
    // Act
    Vector<int> vec2 = vec1;

    // Assert
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 5);
}

TEST(VectorTest, can_assign_vector) {
    // Arrange
    Vector<int> vec1(3, 5);
    Vector<int> vec2;

    // Act
    vec2 = vec1;

    // Assert
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 5);
}

TEST(VectorTest, can_access_elements) {
    // Arrange
    Vector<int> vec(3, 1);

    // Act & Assert
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 1);
}

TEST(VectorTest, throws_when_accessing_out_of_bounds) {
    // Arrange
    Vector<int> vec(3, 1);

    // Act & Assert
    ASSERT_THROW(vec[3], std::out_of_range);
}

TEST(VectorTest, can_add_vectors) {
    // Arrange
    Vector<int> vec1(3, 1);
    Vector<int> vec2(3, 2);

    // Act
    Vector<int> result = vec1 + vec2;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 3);
}

TEST(VectorTest, can_subtract_vectors) {
    // Arrange
    Vector<int> vec1(3, 5);
    Vector<int> vec2(3, 2);

    // Act
    Vector<int> result = vec1 - vec2;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 3);
}

TEST(VectorTest, can_multiply_vector_by_scalar) {
    // Arrange
    Vector<int> vec(3, 2);

    // Act
    Vector<int> result = vec * 3;

    // Assert
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], 6);
    EXPECT_EQ(result[2], 6);
}

TEST(VectorTest, throws_when_add_vectors_of_different_sizes) {
    // Arrange
    Vector<int> vec1(3, 1);
    Vector<int> vec2(4, 2);

    // Act & Assert
    ASSERT_THROW(vec1 += vec2, std::invalid_argument);
}

TEST(VectorTest, throws_when_subtract_vectors_of_different_sizes) {
    // Arrange
    Vector<int> vec1(3, 1);
    Vector<int> vec2(4, 2);

    // Act & Assert
    ASSERT_THROW(vec1 -= vec2, std::invalid_argument);
}

TEST(VectorTest, can_compare_vectors) {
    // Arrange
    Vector<int> vec1(3, 1);
    Vector<int> vec2(3, 1);
    Vector<int> vec3(3, 2);

    // Assert
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_FALSE(vec1 == vec3);
    EXPECT_FALSE(vec1 != vec2);
    EXPECT_TRUE(vec1 != vec3);
}
