#include <iostream>
#include <vector>
#include <string>

enum class book_type{ fic, tec };//enum class

class Books{
public:
    Books(const std::string& title, const std::string& author, const book_type& type) :
        m_title(title), m_author(author), m_type(type) {}

    ~Books() {}

    const std::string& get_title() const{ return m_title; };
    const std::string& get_author() const{ return m_author; };
    const book_type& get_type() const{ return m_type; };

private:
    const std::string m_title;
    const std::string m_author;
    const book_type m_type;
};

class Library {
public:
    void books_input(const std::string& title, const std::string& author, const book_type& type) {
        if (title.empty() == 0 && author.empty() == 0)
            m_books.push_back(Books(title, author, type)); //create
        else
            std::cout << author << "" << title << "has no author or title." << std::endl;
    }

    void type_books() {
        for (const Books& i : m_books) {
            std::cout << i.get_title() << " " << i.get_author() << std::endl;
            switch (i.get_type()){
            case(book_type::fic):
                std::cout << "- fictional book." << std::endl;
                break;
            case(book_type::tec):
                std::cout << "- tecnical book." << std::endl;
                break;
            default:
                std::cout << "- unknown." << std::endl;
                break;
            }
        }
    };

    void type_count_switch() {
        std::cout << "Output quantity of books with switch." << std::endl;
        unsigned fiction_quantity = 0;
        unsigned tecnical_quantity = 0;
        for (const Books& i: m_books) {// copy
            switch (i.get_type())
            {
            case(book_type::fic):
                ++fiction_quantity;//prefix/postfix
                break;
            case(book_type::tec):
                ++tecnical_quantity;
                break;
            }
        }
        std::cout << "Quantity of fiction books is: " << fiction_quantity << ".\n" << "Quantity of tecnical books is: " << tecnical_quantity << "." << std::endl;
    };

    void type_count_if() {
        std::cout << "Output quantity of books with if." << std::endl;
        unsigned fiction_quantity = 0;
        unsigned tecnical_quantity = 0;
        for (const Books& i: m_books) {
            if (i.get_type() == book_type::fic) { ++fiction_quantity; };//? i ?
            if (i.get_type() == book_type::tec) { ++tecnical_quantity; };
        }
        std::cout << "Quantity of fiction books is: " << fiction_quantity << ".\n" << "Quantity of tecnical books is: " << tecnical_quantity << "." << std::endl;
    };

private:
    std::vector <Books> m_books;

};

int main()
{
    Library all_books;

    all_books.books_input("22121","434234232", book_type::tec);
    all_books.books_input("1234242", "243424", book_type::fic);
    all_books.books_input("244242", "2434324", book_type::fic);
    all_books.books_input("342", "4242", book_type::tec);
    all_books.books_input("44423", "34342", book_type::tec);

    
    all_books.type_count_if();
    all_books.type_books();
    all_books.type_count_switch();

    return 0;
}
