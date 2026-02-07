/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:57:04 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/06 14:19:38 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {
    _operands = std::stack<int>();
}

RPN::RPN(const RPN &other) {
    _operands = other._operands;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _operands = other._operands;
    }
    return *this;
}

RPN::~RPN() {}

/*
 * Process the expression and return the result
 * @param expression: the expression to process
 * @return the result of the expression
 * @throw std::runtime_error: if the expression is invalid
 * @note: Logic: Parse the expression token by token, for each token:
 *       - If digit: push to stack
 *       - If operator: pop two operands, perform operation, push result
 *       - Return final result from stack
 *       - Throw exceptions for errors
 */
int RPN::processRPN(const std::string &expression) {
    _operands = std::stack<int>();
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (_isDigit(token)) {
            _operands.push(static_cast<int>(token[0] - '0'));
        }
        else if (_isOperator(token)) {
            if (_operands.size() < 2) {
                throw std::runtime_error("Error: not enough operands");
            }
            int b = _operands.top();
            _operands.pop();
            int a = _operands.top();
            _operands.pop();
            _operands.push(_performOperation(a, b, token[0]));
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    if (_operands.empty()) {
        throw std::runtime_error("Error: empty expression");
    }
    if (_operands.size() != 1) {
        throw std::runtime_error("Error: too many operands");
    }
    return _operands.top();
}

bool RPN::_isOperator(const std::string &token) const {
    return (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

bool RPN::_isDigit(const std::string &token) const {
    return (token.size() == 1 && token[0] >= '0' && token[0] <= '9');
}

int RPN::_performOperation(int a, int b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error");
    }
}
