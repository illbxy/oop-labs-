 // lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class car {//
public:
    car(const std::string& model) : m_model(model) {}//const ref
    virtual ~car() {}

    virtual void print_model() = 0;
    
    const std::string& get_model() const { return m_model; }

private:
    const std::string m_model; //const
};

class Toyota : public car {//virtual destructor
public:
    Toyota(std::string model) : car( model) {} //naming
    virtual ~Toyota() { print_model(); }
    void print_model() { std::cout << "Brand of car is Toyota and model is" << " " << get_model() << std::endl; }
};

class Nissan : public car {
public:
    Nissan(std::string model) : car(model) {} 
    virtual ~Nissan() { print_model(); }
    void print_model() { std::cout << "Brand of car is Nissan and model is" << " " << get_model() << std::endl; }
};

class Volkswagen : public car {
public:
    Volkswagen(std::string model) : car(model) {} 
    virtual ~Volkswagen() { print_model(); }
    void print_model() { std::cout << "Brand of car is Volkswagen and model is" << " " << get_model() << std::endl; }
};


int main()
{
    std::vector <std::shared_ptr<car>> car;
    
    std::fstream cars_file;
    cars_file.open("cars.txt");
    
    std::string brand, model;

    if (cars_file.is_open())
    {
        std::string mark, model;
        while (cars_file >> mark >> model) {
            if (mark == "Toyota") {
                car.push_back(std::make_shared<Toyota>(model));
            }
            else if (mark == "Volkswagen") {
                car.push_back(std::make_shared<Volkswagen>(model));
            }
            else if (mark == "Nissan") {
                car.push_back(std::make_shared<Nissan>(model));
            }
        }
    }
    else
        std::cout << "File didn't open." << std::endl;

    cars_file.close();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
