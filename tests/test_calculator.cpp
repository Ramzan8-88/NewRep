// Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include <string>
#include "../lib_List/List.h"
#include "../lib_Calculator/Calculator.h"

TEST(ExpressionTest, can_create_expression_and_parse_numbers) {
    // Arrange
    std::string expr = "123 456.78";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Number Value: 123"), std::string::npos);
    EXPECT_NE(output.find("Number Value: 456.78"), std::string::npos);
}

TEST(ExpressionTest, can_create_expression_and_parse_variables) {
    // Arrange
    std::string expr = "x y_1";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Variable Value: x"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: y_1"), std::string::npos);
}

TEST(ExpressionTest, can_create_expression_and_parse_functions) {
    // Arrange
    std::string expr = "sin(x) cos(x) tg(x) ctg(x)";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Function Value: sin"), std::string::npos);
    EXPECT_NE(output.find("Function Value: cos"), std::string::npos);
    EXPECT_NE(output.find("Function Value: tg"), std::string::npos);
    EXPECT_NE(output.find("Function Value: ctg"), std::string::npos);
}

TEST(
    ExpressionTest,
    can_create_expression_and_parse_operators_and_parentheses
) {
    // Arrange
    std::string expr = "+ - * / ^ ( )";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Operator Value: +"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: -"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: *"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: /"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: ^"), std::string::npos);
    EXPECT_NE(output.find("Left Parenthesis Value: ("), std::string::npos);
    EXPECT_NE(output.find("Right Parenthesis Value: )"), std::string::npos);
}

TEST(ExpressionTest, throws_invalid_character_in_expression) {
    // Arrange
    std::string expr = "#";

    // Act & Assert
    ASSERT_THROW(Expression expression(expr), std::invalid_argument);
}

TEST(ExpressionTest, does_not_throw_on_valid_variable_names) {
    // Arrange
    std::string expr = "123 abc_123";

    // Act & Assert
    // так как имена переменных могут начинаться с цифры
    // (например, "123abc"), исключения не должно быть
    ASSERT_NO_THROW(Expression expression(expr));
}

TEST(ExpressionTest, can_handle_empty_expression) {
    // Arrange
    std::string expr = "";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");
}

TEST(ExpressionTest, throws_invalid_number_format) {
    // Arrange
    std::string expr = "12.34.56";

    // Act & Assert
    ASSERT_THROW(Expression expression(expr), std::invalid_argument);
}

TEST(ExpressionTest, can_handle_mixed_expressions) {
    // Arrange
    std::string expr = "sin(x) + 2 * y / 3";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Function Value: sin"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: x"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: +"), std::string::npos);
    EXPECT_NE(output.find("Number Value: 2"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: y"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: /"), std::string::npos);
    EXPECT_NE(output.find("Number Value: 3"), std::string::npos);
}

TEST(ExpressionTest, can_parse_expression_with_multiple_operators) {
    // Arrange
    std::string expr = "a + b * c - d / e ^ f";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Variable Value: a"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: +"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: b"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: *"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: c"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: -"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: d"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: /"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: e"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: ^"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: f"), std::string::npos);
}

TEST(ExpressionTest, throws_if_function_not_recognized) {
    // Arrange
    std::string expr = "unknownFunction(x)";

    // Act & Assert
    bool exceptionCaught = false;
    try {
        Expression expression(expr);
    }
    catch (const std::invalid_argument& e) {
        exceptionCaught = true;
    }

    // Assert that exception was caught
    ASSERT_TRUE(exceptionCaught);
}

TEST(ExpressionTest, can_parse_expression_with_parentheses) {
    // Arrange
    std::string expr = "(x + y) * 2";

    // Act
    Expression expression(expr);

    // Assert
    testing::internal::CaptureStdout();
    expression.printLexemes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Left Parenthesis Value: ("), std::string::npos);
    EXPECT_NE(output.find("Variable Value: x"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: +"), std::string::npos);
    EXPECT_NE(output.find("Variable Value: y"), std::string::npos);
    EXPECT_NE(output.find("Right Parenthesis Value: )"), std::string::npos);
    EXPECT_NE(output.find("Operator Value: *"), std::string::npos);
    EXPECT_NE(output.find("Number Value: 2"), std::string::npos);
}

TEST(ExpressionTest, throws_if_invalid_character_in_expression) {
    // Arrange
    std::string expr = "123 & 456";

    // Act & Assert
    ASSERT_THROW(Expression expression(expr), std::invalid_argument);
}

