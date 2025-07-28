/*
 * Revision history:
 * Revised by Stefan Petrov 2025 following PP&P 3rd edition
 *
 * This program implements a basic expression calculator. Input from cin; output to cout.
 * The grammar is as below:
 *
 * Grammar:
     * Expression:
        * Term
        * Term + Expression
        * Term - Expression
     *
     * Term:
        * Primary
        * Term * Primary
        * Term / Primary
     *
     * Primary:
        * Number
        * ( Expression )
 */

#include <iostream>

constexpr char number = '8';
constexpr char print = ';';
constexpr char quit = 'q';
const std::string prompt = "> ";
const std::string result = "= ";

class Token {
public:
    char kind;
    double value;

    Token(char kind): kind(kind), value(0) {
    };

    Token(char kind, double value): kind(kind), value(value) {
    };
};

class Token_stream {
public:
    Token get();

    void putback(Token t);

    void ignore(char c);

private:
    bool full = false;
    Token buffer = {'0'};
};

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while (std::cin >> ch)
        if (ch == c)
            return;
}


void Token_stream::putback(Token t) {
    if (full)
        throw std::runtime_error("putback() into full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch = 0;
    if (!(std::cin >> ch)) {
        throw std::runtime_error("No input");
    }
    switch (ch) {
        case print:
        case quit:
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '!':
        case '%':
            return Token{ch};
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            std::cin.putback(ch); // put input back into stream
            double val = 0;
            std::cin >> val; // read a floating-point number
            return Token{number, val};
        }
        default:
            throw std::runtime_error("Bad token");
    }
}

Token_stream ts;

double expression();

int factorial(int num) {
    if (num == 0) return 1;
    int res = 1;
    for (int i = num; i >= 1; --i) {
        res *= i;
    }
    return res;
}

double primary() {
    Token t = ts.get();
    double val = 0;
    switch (t.kind) {
        case number:
            val = t.value; // return the number's value
            break;
        case '(': {
            val = expression();
            t = ts.get();
            if (t.kind != ')') std::cerr << "')' expected";
            break;
        }
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            std::cerr << "Primary expected";
            val = 0;
    }
    t = ts.get();
    while (t.kind == '!') {
        int n = static_cast<int>(val);
        if (n < 0 || n != val) throw std::runtime_error("Can't get factorial of value");
        val = factorial(n);
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

double term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*': {
                left *= primary();
                t = ts.get();
                break;
            }
            case '/': {
                double d = primary();
                if (d == 0) std::cerr << "Can't divide by 0";
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                if (d == 0)
                    throw std::invalid_argument("%: divide by 0");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    std::cout << "Enter an expression and ';' to print or 'q' to exit" << std::endl;
    while (std::cin)
        try {
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return;
            ts.putback(t);
            std::cout << result << expression() << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            clean_up_mess();
        }
}

int main()
try {
    calculate();
    return 0;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
} catch (...) {
    std::cerr << "Exception" << std::endl;
    return 2;
}
