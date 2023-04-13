#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class car {
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
