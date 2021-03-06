#ifndef USER_H
#define USER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdlib>
using namespace std;

class userInfo
{
private:
    vector<string>name;
    vector<string>UserID;
    vector<string>email;
    vector<string>address;
    vector<string>pass;

public:
    userInfo();
    void insertUser(string name,string ID,string mail,string add,string password);
    string getUserID(string word);
    string getAddress(string word);
    string getEmail(string word);
    void displayUser(string username);
    void editAccount(string username);
    void createAccount();
    bool removeAccount(string word);
    bool login(string username, string password);


};
//scene graph
class ItemInfo
{
private:
    vector<string>itemName;
    vector<string>itemID;
    vector<float>Price;
    vector<int>quaitiy;
public:
    void insertItem(string name,string ID,float pr,int qu);
    void displayItem(string type);
    void ItemOrder(string name,int amount);
    string getItemID(string name);
    string getitemName(string ID);
    int getInventory(string ID);
    double getPrice(string ID);
    float totalPrice(string ID,int amount);
    bool quantiy_check(string name,string amount);
    void InsertCart(vector<string>&rt, string list);

};


class shop
{
private:
    vector<string>ca;

public:
    void display(vector<string>&list);
    void addItem(string qr);
    void checkout(vector<string>&list);
    void insertCart(string car);
    string is_Empty(string username);
    bool removeItem(string qr);
    bool purchase();

};
#endif // USER_H
