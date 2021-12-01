#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include<string>
#include<cstdlib>
using namespace std;

class userInfo
{
private:
    vector<string>name ={"Andrew","Banks"};
    vector<string>UserID={"an1010","ba1021"};
    vector<string>email={"godzillamaster.gmail"};
    vector<string>address={"1811 Nottaway drive"};
    vector<string>pass={"1a1a1","dd1d1d1"};

public:
    userInfo();
    bool login(string username, string password);
    string getUserID(string word);
    string getAddress(string word);
    string getEmail(string word);
    void displayUser(string name);
    void editAccount(string username);
    void createAccount();
    bool removeAccount(string word);


};
//scene graph
class ItemInfo
{
private:
    vector<string>itemName={"Ruby","Quartz","Emerald","Godzilla","Avengers","Twlight"};
    vector<string>itemID={"JW-0001","JW-0002","JW-5001","MV-3332","MV-4546"," MV-7574"};
    vector<double>Price={12.20,120.00,514.00,10.00,12.20,20.00};
    vector<int>quaitiy={12,0,15,2,6,0};
public:
    string getItemID(string name);
    string getitemName(string ID);
    double getPrice();
    int getInventory();
    void displayItem(string type);
    bool quantiy_check(string name,string amount);

};

class Cart
{
private:
    vector<string>cart;

public:
    void display();
    int totalPrice(string name);
    void addItem(string qr);
    void removeItem(string qr);
    void checkout(string username);

};
#endif // USER_H
