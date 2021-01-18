// Copyright 2021 by me
#include "../include/MyStack.h"
#include "../include/postfix.h"

bool isOperator(char c) {
    switch (c) {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    case '(':
        return true;
    case ')':
        return true;
    default:
        return false;
    }
}

int priority(char c) {
    switch (c) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        return 4;
    }
}

std::string infix2postfix(std::string infix) {
    std::string prefix("");
    MyStack<std::string> stack(500);
    for (size_t i = 0; i < infix.size(); ++i) {
        if (infix[i] == ' ') {
            continue;
        }
        if (isOperator(infix[i])) {
            if (infix[i] == '(' || stack.isEmpty()) {
                stack.push(std::string(1, infix[i]));
            } else {
                if (priority(infix[i]) > priority(stack.get()[0])) {
                    stack.push(std::string(1, infix[i]));
                } else {
                    while (!stack.isEmpty() &&
                        priority(stack.get()[0]) >= priority(infix[i])) {
                        prefix += stack.pop() + " ";
                    }
                    if (infix[i] == ')') {
                        if (stack.get()[0] == '(') {
                            stack.pop();
                        }
                    } else {
                        stack.push(std::string(1, infix[i]));
                    }
                }
            }
        } else {
            std::string buff("");
            while (infix[i] != ' ' && i < infix.size()) {
                buff += infix[i];
                i++;
                if (i < infix.size() && infix[i] == ')') {
                    i--;
                    break;
                }
            }
            prefix += buff + ' ';
        }
    }
    while (!stack.isEmpty()) {
        if (stack.get() == "(") {
            stack.pop();
            continue;
        }
        prefix += stack.pop() + " ";
    }
    if (!prefix.empty()) {
        prefix.erase(prefix.size() - 1, 1);
    }
    return prefix;
}
