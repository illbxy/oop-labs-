// lab2.01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <typeinfo>

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

struct Leaks
{
    ~Leaks() 
    {
        _CrtDumpMemoryLeaks();
    }
}_leaks;

class Class1 
{
public:
    Class1() {}
    virtual ~Class1() {}

    virtual Class1* clone() 
    {
        Class1* CopiedObject = new Class1(*this);
        return CopiedObject;
    }
    
};


class Class2 : public Class1 
{
public:
    Class2() {}
    ~Class2() {}

    Class1* clone()
    {
        Class1* CopiedObject = new Class2(*this);
        return CopiedObject;
    }
};

void my_copy(Class1* obj, std::vector <Class1*>& dB)
{
    Class1* CopyObject = obj->clone();
    dB.push_back(CopyObject);
}

int main()
{
    Class1* obj1 = new Class1();
    Class1* obj2 = new Class2();

    std::vector <Class1*> dataBase;

    my_copy(obj1,dataBase);
    my_copy(obj2, dataBase);

    for (int i = 0; i < dataBase.size(); ++i) 
    {
        std::cout << typeid(*(dataBase[i])).name() << std::endl;
        delete dataBase[i];
    }

    delete obj1;
    delete obj2;

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
