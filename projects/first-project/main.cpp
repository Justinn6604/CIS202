/*
    File: main.cpp
    Description: This program sorts pizza orders by size, name, and price using lambda functions.
    Author: Justin Nakoud
    Email: Justinn6604@student.vvc.edu
    Course#: CIS202
    Section#: 30001
    Date: 06/08/2025
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct PizzaOrder {
    string name;
    int size;
};
struct PizzaOrderWithPrice {
    string name;
    int size;
    double price;
};
void printOrders(const vector<PizzaOrder>& orders) {
    for (const auto& order : orders) {
        cout << order.name << " " << order.size << " inches\n";
    }
}
void printOrdersWithPrice(const vector<PizzaOrderWithPrice>& orders) {
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << orders[i].name << " " << orders[i].size << " inches $" << fixed << setprecision(2) << orders[i].price;
        if (i < orders.size() - 1) {
            cout << "\n";
        }
    }
}
int main() {
    vector<PizzaOrder> orders = {
        {"Alice", 12},
        {"Bob", 16},
        {"Charlie", 10},
        {"Diana", 14}
    };
    cout << "\nOriginal Pizza Orders:\n";
    printOrders(orders);
    cout << "\nSorted by Size (Ascending):\n";
    sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
    });
    printOrders(orders);
    cout << "\nSorted by Name (Alphabetical):\n";
    sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
    });
    printOrders(orders);
    vector<PizzaOrderWithPrice> ordersWithPrice = {
        {"Alice", 12, 11.99},
        {"Bob", 16, 15.49},
        {"Charlie", 10, 9.99},
        {"Diana", 14, 13.75}
    };
    cout << "\nSorted by Price (Ascending):\n";
    sort(ordersWithPrice.begin(), ordersWithPrice.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });
    printOrdersWithPrice(ordersWithPrice);
    return 0;
}
