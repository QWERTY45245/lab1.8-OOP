#ifndef GOODS_H
#define GOODS_H

#include <string>

class Goods {
private:
    class Money {
    private:
        long hryvnia;
        int kopiyka;

    public:
        void Init();
        void Read();
        void Display();
        void ChangeAmount(double amount);
        double getAmount();
        std::string toString();
        void Discount(int percentage);
    };

private:
    std::string name;
    std::string date;
    Money price;
    int quantity;
    int invoiceNumber;

public:
    Goods();
    void Init();
    void Read();
    void Display();
    void ChangePrice(double newPrice);
    void ChangeQuantity(int newQuantity);
    double CalculateTotal();
    std::string toString();
    void DiscountProduct(int daysExpired);
};

#endif
