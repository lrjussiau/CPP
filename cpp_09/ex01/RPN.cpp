#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) {
    (void)src;
}

RPN& RPN::operator=(const RPN &src) {
    (void)src;
    return *this;
}

//---------------------------------------//
//            Check + Parse              //
//---------------------------------------//

void    RPN::checkInput(std::string str) {
    for (size_t i = 0; i < str.length() - 1; i++) {
        char c = str[i];
        if (!isdigit(c) && !isspace(c) && c != '+' && c != '-' && c != '/' && c != '*')
            throw WrongInput();
        if (isdigit(c) && !isspace(str[i + 1]))
            throw WrongInput();
        if ((c == '+' || c == '-' || c == '/' || c == '*') && !isspace(str[i + 1]))
            throw WrongInput();
    }
}

int RPN::ctoi(char c) {
    int num = c - '0';
    return num;
}

void    RPN::parseNumber(std::string str) {
    for (int i = static_cast<int>(str.length()); i >= 0; i--) {
        if (isdigit(str[i]))
            _number.push(ctoi(str[i]));
    }
}

//---------------------------------------//
//             Calculation               //
//---------------------------------------//

void    RPN::doCalcul(std::string str) {
    int value = _number.top();
    _number.pop();
    for (size_t i = 0; i < str.length(); i++) {
        if (_number.empty() && (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'))
            throw TooManySymbol();
        switch (str[i])
        {
        case '+':
            value += _number.top();
            _number.pop();
            break;
        
        case '-':
            value -= _number.top();
            _number.pop();
            break;

        case '*':
            value *= _number.top();
            _number.pop();
            break;

        case '/':
            value /= _number.top();
            _number.pop();
            break;
        
        default:
            break;
        }
    }
    if (!_number.empty())
        throw TooManyNumber();
    std::cout << value << std::endl;
}


//---------------------------------------//
//             Run Function              //
//---------------------------------------//

void    RPN::run(std::string str) {
    try {
        checkInput(str);
        parseNumber(str);
        try {
            doCalcul(str);
        } catch (TooManyNumber &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        } catch (TooManySymbol &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } catch (WrongInput &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

}