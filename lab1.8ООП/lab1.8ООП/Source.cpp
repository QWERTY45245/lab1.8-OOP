#include <iostream>
#include "Goods.h"
#include<Windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Goods goods;
    goods.Read();

    cout << "���������� ��� �����:\n";
    goods.Display();

    // ��������� ������� ������
    double total = goods.CalculateTotal();
    cout << "������� ������: " << total << endl;

    // ���� ���� ������
    double newPrice;
    cout << "������ ���� ���� ������: ";
    cin >> newPrice;
    goods.ChangePrice(newPrice);

    // ���� ������� ������
    int newQuantity;
    cout << "������ ���� ������� ������: ";
    cin >> newQuantity;
    goods.ChangeQuantity(newQuantity);

    // ��������� ������� ������ ���� ����
    total = goods.CalculateTotal();
    cout << "������� ������ ���� ���: " << total << endl;

    // ������ ������
    int daysExpired;
    cout << "������ ������� ��� ������������: ";
    cin >> daysExpired;
    goods.DiscountProduct(daysExpired);
    cout << "ֳ�� ���� ������: " << goods.CalculateTotal() << endl;

    return 0;
}
