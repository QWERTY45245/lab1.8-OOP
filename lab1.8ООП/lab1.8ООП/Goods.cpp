#include "Goods.h"
#include <iostream>
#include<Windows.h>
using namespace std;
void Goods::Money::Init() {
    hryvnia = 0;
    kopiyka = 0;
}

void Goods::Money::Read() {
    std::cin >> hryvnia >> kopiyka;
}

void Goods::Money::Display() {
    std::cout << hryvnia << " " << static_cast<int>(kopiyka) << std::endl;
}

void Goods::Money::ChangeAmount(double amount) {
    hryvnia = static_cast<long>(amount);
    kopiyka = static_cast<unsigned char>((amount - hryvnia) * 100);
}

double Goods::Money::getAmount() {
    return hryvnia + kopiyka / 100.0;
}

std::string Goods::Money::toString() {
    // Створення рядка для представлення гривень
    std::string hryvniaStr = std::to_string(hryvnia);

    // Перевірка, чи потрібно додати 0 перед копійками, якщо вони менші за 10
    std::string kopiykaStr;
    if (kopiyka < 10) {
        kopiykaStr = "0" + std::to_string(kopiyka);
    }
    else {
        kopiykaStr = std::to_string(kopiyka);
    }

    // Повернення суми у вигляді рядка з розділенням комою
    return hryvniaStr + "," + kopiykaStr;
}

void Goods::Money::Discount(int percentage) {
    double discountRate = 1 - (percentage / 100.0);
    double discountedAmount = getAmount() * discountRate;
    ChangeAmount(discountedAmount);
}

Goods::Goods() {}

void Goods::Init() {
    name = "";
    date = "";
    price.Init();
    quantity = 0;
    invoiceNumber = 0;
}

void Goods::Read() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введіть найменування товару: ";
    cin >> name;
    cout << "Введіть дату оформлення: ";
    cin >> date;
    cout << "Введіть ціну товару (гривні та копійки через пробіл): ";
    price.Read();
    cout << "Введіть номер накладної: ";
    cin >> invoiceNumber;
    cout << "Введіть кількість одиниць товару: ";
    cin >> quantity;
}

void Goods::Display() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Найменування товару: " << name << endl;
    cout << "Дата оформлення: " << date << endl;
    cout << "Ціна товару: " << price.toString() << endl;
    cout << "Кількість одиниць товару: " << quantity << endl;
    cout << "Номер накладної: " << invoiceNumber << endl;
}

void Goods::ChangePrice(double newPrice) {
    price.ChangeAmount(newPrice);
}

void Goods::ChangeQuantity(int newQuantity) {
    quantity = newQuantity;
}

double Goods::CalculateTotal() {
    return price.getAmount() * quantity;
}

std::string Goods::toString() {
    return std::to_string(CalculateTotal());
}

void Goods::DiscountProduct(int daysExpired) {
    price.Discount(daysExpired);
}
