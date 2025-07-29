/*
 * Revision history:
 * Revised by Stefan Petrov 2025 following PP&P 3rd edition
 *
 * This program implements a basic expression calculator. Input from cin; output to cout.
 * The grammar is as below:
 **************************
 * OG Grammar:
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
****************************
    * New Grammar:
    * Calculation:
         Statement
         Print
         Quit
         Calculation

    * Statement:
         Declaration
         Expression
    * Declaration:
         "let" Name "=" Expression”
 */

#include <iostream>
#include <valarray>
#include <vector>

constexpr char number = '8';
constexpr char print = ';';
constexpr char quit = 'q';
const std::string prompt = "> ";
const std::string result = "= ";
constexpr char name = 'a'; // name token
constexpr char let = 'L'; // declaration token
constexpr char square_root = '/'; // sqrt token
const std::string declkey = "let"; // declaration keyword
const std::string sqrtkey = "sqrt"; // sqrt keyword

class Variable {
public:
    std::string name;
    double value;
};

std::vector<Variable> var_table;

double get_value(const std::string &str) {
    for (const Variable &v: var_table)
        if (v.name == str) return v.value;
    throw std::invalid_argument("Trying to read undefined variable: " + str);
}

void set_value(const std::string &str, double val) {
    for (Variable &table: var_table) {
        if (table.name == str) {
            table.value = val;
            return;
        }
    }
    throw std::invalid_argument("Trying to set undefined variable: " + str);
}


class Token {
public:
    char kind;
    double value;
    std::string name;

    Token() : kind{0} {
    } // default constructor
    Token(char ch) : kind{ch} {
    } // initialize kind with ch
    Token(char ch, double val) : kind{ch}, value{val} {
    } // initialize kind and value
    Token(char ch, std::string n) : kind{ch}, name{n} {
    } // initialize kind and name
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
        case '=':
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
            if (isalpha(ch)) {
                std::string s;
                s += ch;
                while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch;
                std::cin.putback(ch);
                if (s == declkey)
                    return Token{let};
                if (s == sqrtkey)
                    return Token{square_root};
                return Token{name, s};
            }
            throw std::runtime_error("Bad token");
    }
}

Token_stream ts;

double expression();

double calc_sqrt() {
    char ch;
    if (std::cin.get(ch) && ch != '(') throw std::invalid_argument("'(' expected");
    std::cin.putback(ch);
    double d = expression();
    if (d < 0) throw std::invalid_argument("sqrt: negative value no permitted");
    return std::sqrt(d);
}

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
        case name:
            return get_value(t.name);
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
        case square_root:
            return calc_sqrt();
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

bool is_declared(std::string var) {
    // is var already in var_table ?
    for (const Variable &v: var_table)
        if (v.name == var) return true;

    return false;
}

double define_name(std::string var, double val) {
    if (is_declared(var)) throw std::invalid_argument("Variable declared twice: " + var);
    var_table.push_back(Variable{var, val});
    return val;
}

double declaration() {
    Token t = ts.get();
    if (t.kind != name) throw std::invalid_argument("name expected in declaration");
    Token t2 = ts.get();
    if (t2.kind != '=') throw std::invalid_argument("'=' missing in declaration");
    double d = expression();
    define_name(t.name, d);
    return d;
}

double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
};


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
            std::cout << result << statement() << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            clean_up_mess();
        }
}

int main()
try {
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);
    define_name("k", 1000);
    calculate();
    return 0;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
} catch (...) {
    std::cerr << "Exception" << std::endl;
    return 2;
}
