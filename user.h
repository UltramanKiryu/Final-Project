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
    void exportUsers(string currentUser);


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
    float getPrice(string ID);
    bool quantiy_check(string name,string amount);

};


class Cart
{
private:
    vector<string>cart;

public:
    Cart();
    void display();
    void addItem(string qr);
    void checkout();
    void insertCart(string car);
    string is_Empty(string username);
    float totalPrice(string ID,int amount);
    bool removeItem(string qr);
    bool purchase();
    void exportUsers(string currentUser);

};
#endif // USER_H
