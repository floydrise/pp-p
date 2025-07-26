/*
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

private:
    bool full = false;
    Token buffer = {'0'};
};

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
        case ';':
        case 'q':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
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
            std::cin.putback(ch);
            double val = 0;
            std::cin >> val;
            return Token{'8', val};
        }
        default:
            throw std::runtime_error("Bad token");
    }
}


/*Token get_token() // read a token from cin
{
    char ch;
    std::cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token(ch); // let each character represent itself
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
            std::cin.putback(ch); // put digit back into the input stream
            double val;
            std::cin >> val; // read a floating-point number
            return Token('8', val); // let '8' represent "a number"
        }
        default:
            std::cerr << "Bad token";
    }
}*/

Token_stream ts;

double expression();

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '8':
            return t.value;
        case '(': {
            double expr = expression();
            t = ts.get();
            if (t.kind != ')') std::cerr << "')' expected";
            return expr;
        }
        default:
            std::cerr << "Primary expected";
    }
}

double term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) std::cerr << "Can't divide by 0";
                left /= d;
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

int main()
try {
    double val = 0;
    std::cout << "Enter an expression and ';' to print or 'q' to exit: ";
    while (std::cin) {
        Token t = ts.get();
        if (t.kind == 'q')
            break;
        if (t.kind == ';')
            std::cout << val << std::endl;
        else
            ts.putback(t);
        val = expression();
    }
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...) {
    std::cerr << "Exception" << std::endl;
    return 2;
}
