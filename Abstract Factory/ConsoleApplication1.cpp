// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>
#include <string>

// Абстрактні продукти
class AbstractProductA {
public:
    virtual std::string getName() const = 0;
    virtual ~AbstractProductA() {}
};

class AbstractProductB {
public:
    virtual std::string getType() const = 0;
    virtual ~AbstractProductB() {}
};

// Конкретні продукти
class ConcreteProductA1 : public AbstractProductA {
public:
    std::string getName() const override {
        return "Product A1";
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    std::string getName() const override {
        return "Product A2";
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    std::string getType() const override {
        return "Product B1";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    std::string getType() const override {
        return "Product B2";
    }
};

// Абстрактна фабрика
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() {}
};

// Конкретні фабрики
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

// Клієнтський код
void clientCode(AbstractFactory& factory) {
    AbstractProductA* productA = factory.createProductA();
    AbstractProductB* productB = factory.createProductB();

    std::cout << "Product A: " << productA->getName() << std::endl;
    std::cout << "Product B: " << productB->getType() << std::endl;

    delete productA;
    delete productB;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ConcreteFactory1 factory1;
    ConcreteFactory2 factory2;

    std::cout << "Client 1:" << std::endl;
    clientCode(factory1);

    std::cout << "\nClient 2:" << std::endl;
    clientCode(factory2);

    return 0;
}
