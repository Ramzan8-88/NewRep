// Copyright 2024 Ramzan Kamaletdinov

#ifndef LIB_CALCULATOR_CALCULATOR_H_
#define LIB_CALCULATOR_CALCULATOR_H_

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "../lib_List/List.h"


enum class LexType {
    Number,
    Variable,
    Operator,
    Function,
    LeftParenthesis,
    RightParenthesis,
    End
};

// класс, представл€ющий одну лексему
class Lexema {
public:
    LexType type;
    std::string value;

    Lexema(LexType t, const std::string& val) : type(t), value(val) {}
};

// класс, представл€ющий арифметическое выражение
class Expression {
private:
    TList<Lexema> lexemes;

    // функци€ дл€ разбора числа
    bool parseNumber(const std::string& expr, size_t* index) {
        std::string num;
        bool hasDot = false;

        while (*index < expr.length() &&
            (isdigit(expr[*index]) || expr[*index] == '.')) {
            if (expr[*index] == '.') {
                if (hasDot) return false;
                hasDot = true;
            }
            num += expr[*index];
            (*index)++;
        }
        lexemes.insertBack(Lexema(LexType::Number, num));
        return true;
    }

    // функци€ дл€ разбора переменной
    bool parseVariable(const std::string& token) {
        if (token.empty() || (!isalpha(token[0]) && token[0] != '_')) {
            throw std::invalid_argument("Invalid variable name: " + token);
        }

        if (isdigit(token[0])) {
            throw std::invalid_argument("Variable name cannot "
                "start with a digit: " + token);
        }

        for (char c : token) {
            if (!(isalnum(c) || c == '_')) {
                throw std::invalid_argument("Invalid variable name: " + token);
            }
        }

        lexemes.insertBack(Lexema(LexType::Variable, token));
        return true;
    }

    // функци€ дл€ разбора функции (например, sin, cos)
    bool parseFunction(const std::string& token) {
        if (token == "sin" || token == "cos" || token == "tg"
            || token == "ctg") {
            lexemes.insertBack(Lexema(LexType::Function, token));
            return true;
        }

        throw std::invalid_argument("Invalid function name: " + token);
    }

    // функци€ дл€ разбора операторов и скобок
    bool parseOperatorOrParenthesis(const std::string& expr, size_t* index) {
        char ch = expr[*index];
        (*index)++;

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            lexemes.insertBack(Lexema(LexType::Operator, std::string(1, ch)));
            return true;
        }
        else if (ch == '(') {
            lexemes.insertBack(Lexema(LexType::LeftParenthesis, "("));
            return true;
        }
        else if (ch == ')') {
            lexemes.insertBack(Lexema(LexType::RightParenthesis, ")"));
            return true;
        }

        return false;
    }

    // функци€ дл€ разбора переменной или функции
    bool parseVariableOrFunction(const std::string& expr, size_t* index) {
        std::string token;
        size_t start = *index;

        while (*index < expr.length()
            && (isalnum(expr[*index]) || expr[*index] == '_')) {
            token += expr[*index];
            (*index)++;
        }

        if (*index < expr.length() && expr[*index] == '(') {
            if (token == "sin" || token == "cos" || token == "tg"
                || token == "ctg") {
                lexemes.insertBack(Lexema(LexType::Function, token));
                return true;
            }
            else {
                throw std::invalid_argument("Invalid function name: " + token);
            }
        }

        return parseVariable(token);
    }

public:
    // конструктор, который разбирает строку на лексемы
    explicit Expression(const std::string& expr) {
        size_t index = 0;

        if (expr.empty()) {
            return;
        }

        while (index < expr.length()) {
            if (isspace(expr[index])) {
                ++index;
                continue;
            }

            if (isalpha(expr[index])) {
                if (!parseVariableOrFunction(expr, &index)) {
                    throw std::invalid_argument("Invalid function "
                        "or variable name.");
                }
            }
            else if (isdigit(expr[index])) {
                if (!parseNumber(expr, &index)) {
                    throw std::invalid_argument("Invalid number format.");
                }
            }
            else {
                if (!parseOperatorOrParenthesis(expr, &index)) {
                    throw std::invalid_argument("Invalid character "
                        "in expression.");
                }
            }
        }

        lexemes.insertBack(Lexema(LexType::End, ""));
    }

    // вывод лексем дл€ отладки
    void printLexemes() const {
        for (const auto& lex : lexemes) {
            if (lex.type == LexType::Function) {
                std::cout << "Function Value: " << lex.value << std::endl;
            }
            else if (lex.type == LexType::Variable) {
                std::cout << "Variable Value: " << lex.value << std::endl;
            }
            else if (lex.type == LexType::Operator) {
                std::cout << "Operator Value: " << lex.value << std::endl;
            }
            else if (lex.type == LexType::LeftParenthesis) {
                std::cout << "Left Parenthesis Value: (" << std::endl;
            }
            else if (lex.type == LexType::RightParenthesis) {
                std::cout << "Right Parenthesis Value: )" << std::endl;
            }
            else if (lex.type == LexType::Number) {
                std::cout << "Number Value: " << lex.value << std::endl;
            }
            else {
                std::cout << "Unknown Lexeme Type: " << lex.value << std::endl;
            }
        }
    }
};

#endif  // LIB_CALCULATOR_CALCULATOR_H_
