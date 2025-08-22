#include <iostream>
#include <string>

struct Names {
    std::string first_name;
    std::string second_name;
};

class Person {
public:
    Person() = default;

    Person(const Names &name, const int age): con_name(name), con_age(age) {
        validate(name, age);
    }

    [[nodiscard]] Names name() const { return con_name; }
    [[nodiscard]] int age() const { return con_age; }

    void set_name(const Names &new_name) {
        validate(new_name, con_age);
        con_name = new_name;
    };

    void set_age(const int new_age) {
        validate(con_name, new_age);
        con_age = new_age;
    };

private:
    Names con_name;
    int con_age = 0;

    static void validate(const Names &name, const int age) {
        if (age < 0 || age > 150) throw std::runtime_error("Age out of bounds");
        auto [first_name, second_name] = name;

        const std::string invalid_chars = R"(;:"'[]*&^%$#@!)";

        if (first_name.empty() || second_name.empty()) throw std::runtime_error("First name or second name empty");

        if (first_name.find_first_of(invalid_chars) != std::string::npos || second_name.
            find_first_of(invalid_chars) != std::string::npos)
            throw std::runtime_error(
                std::format("Name cannot contain chars: {}", R"(;:"'[]*&^%$#@!)"));
    };

    friend std::istream &operator>>(std::istream &is, Person &person);
};

std::ostream &operator<<(std::ostream &os, const Person &person) {
    auto [first_name, second_name] = person.name();
    return os << "Name: " << first_name << " " << second_name << "\nAge: " << person.age();
}

std::istream &operator>>(std::istream &is, Names &name) {
    return is >> name.first_name >> name.second_name;
}

std::istream &operator>>(std::istream &is, Person &person) {
    Names name;
    int age;

    if (!(is >> name >> age)) {
        return is;
    }

    Person::validate(name, age);
    person.set_name(name);
    person.set_age(age);
    return is;
}

int main() {
    std::vector<Person> people(3);
    for (Person &person: people) {
        std::cout << "Write name: ";
        std::cin >> person;
    }
    for (const Person &person: people) {
        std::cout << person << '\n';
    }
}
