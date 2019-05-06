#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stock{
private:
    string name;
    int price;
    int qty;
public:
    Stock(string name,int price,int qty){
        this->name = name;
        this->price = price;
        this->qty = qty;
    }
    void display(){
        cout << "Stock Name : " << this->name << endl;
        cout << "Stock Price : " << this->price << endl;
        cout << "Stock Quantity : " << this->qty << endl;
    }
};

class OrderInterface{
public:
    OrderInterface(){}
    virtual void execute()=0;
};
class BuyStock:public OrderInterface{
private:
    Stock* stock;
public:
    BuyStock(Stock* stock):OrderInterface(){
        this->stock = stock;
    }
    void execute(){
        cout << "Buy Stock" << endl;
        this->stock->display();
        cout << "**************" << endl;
    }
};

class SellStock:public OrderInterface{
private:
    Stock* stock;
public:
    SellStock(Stock* stock):OrderInterface(){
        this->stock = stock;
    }
    void execute(){
        cout << "Sell Stock" << endl;
        this->stock->display();
        cout << "**************" << endl;
    }
};
class Broker{
private:
    vector<OrderInterface*> orders;
public:
    Broker(){}
    void takeOrder(OrderInterface* order){
        orders.push_back(order);
    }
    void placeOrder(){
        for(auto order:orders){
            order->execute();
        }
        cout << "Order Placed Succesfully!" << endl;
        orders.clear();
    }
};
int main(){
    Broker* broker = new Broker();
    broker->takeOrder(new BuyStock(new Stock("Fervent Syn",27,100)));
    broker->takeOrder(new SellStock(new Stock("RCom",20,89)));
    broker->placeOrder();
}