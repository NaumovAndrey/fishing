#include <iostream>
#include <ctime>

using namespace std;

class Item
{
public:
    virtual ~Item() {}  // Добавлен виртуальный деструктор для корректного удаления объектов
    virtual void display() = 0;
};

class Fish: public Item
{
public:
    Fish()
    {
        cout << "Fish constructor called." << std::endl;
    }

    ~Fish()
    {
        cout << "Fish destructor called." << std::endl;
    }

    void display() override {
        cout << "Fish" << std::endl;
    }

};

class Boot: public Item
{
public:
    Boot()
    {
        cout << "Boot constructor called." << std::endl;
    }

    ~Boot()
    {
        cout << "Boot destructor called." << std::endl;
    }

    void display() override {
        cout << "Boot" << std::endl;
    }
};


template<typename T>
class Field
{
private:
    static const int SIZE = 9;
    T *field[SIZE]; // Массив указателей на Fish, Boot
public:
    Field()
    {
        // Инициализация массива указателей нулевыми указателями
        for(int i = 0; i < SIZE; ++i)
        {
            field[i] = nullptr;
        }
    }

    // Деструктор для освобождения памяти из кучи
    ~Field()
    {
        for(int i = 0; i < SIZE; ++i)
        {
            delete field[i]; // Удаление объектов Fish из кучи
        }
    }

    void addFish()
    {
        // Генерация случайного индекса
        int randomIndex = std::rand() % SIZE;
        // Создание нового объекта Fish в куче и присвоение его указателя элементу массива field
        field[randomIndex] = new Fish();
    }

    void addBoot()
    {
        // Генерация случайного индекса
        int randomIndex = std::rand() % SIZE;
        // Создание нового объекта Fish в куче и присвоение его указателя элементу массива field
        field[randomIndex] = new Boot();
    }
};

void cast()
{

}

int main()
{
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Field<Item> field;
    field.addFish(); // Добавление рыбы на случайную позицию в поле
    field.addBoot(); // Добавление сапога на случайную позицию в поле

    // Вывод типов объектов из коллекции
    //int size = sizeof(field) / sizeof(field[0]);
    for (int i = 0; i < 9; ++i)
    {
        field[i]->display();
    }
    return 0;
}