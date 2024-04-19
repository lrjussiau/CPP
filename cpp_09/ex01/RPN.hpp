#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <stack>
#include <sstream>

class RPN {

    private:
        
        std::stack<int>     _number;
        void    checkInput(std::string);
        void    parseNumber(std::string);
        int     ctoi(char);
        void    doCalcul(std::string);

    public:
        RPN();
        virtual ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);

        void    run(std::string);

    class WrongInput : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Wrong Input : Must be a number beetween 0 and 9 or a symbol (+-/*) separate by single space");
            }
    };
    class TooManyNumber : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("There is to many number compare to symbol to be correct");
            }
    };
    class TooManySymbol: public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("There is to many symbol compare to number to be correct");
            }
    };
};

#endif