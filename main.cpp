#include <iostream>
#include <algorithm>
#include <string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include"user.h"
using namespace std;

void selection(string type);

int main()
{
    /*
    ifstream infile;
    ofstream outfile;
    string ttk1,ttk2;
    int num1;
    vector<string>name ={"Andrew","Banks"};
    vector<int>UserID;
    vector<string>email;
    vector<string>address;
    vector<string>pass={"1a1a1","dd1d1d1"};
    infile.open("Name.txt");

    if(!infile.is_open())
    {
        cout<<"Error opening."<<endl;
        return 1;
    }
    while(!infile.eof())
    {
    infile >>num1 >> ttk1;
    if(!infile.fail())
    {
        UserID.push_back(num1);
        name.push_back(ttk1);

    }
    }
    infile.close();
    */
    string username, password,qu,cat,wan;
    string ss;
    userInfo u;
    ItemInfo pp;
    Cart q;
    bool hh=false;
    bool qq= false;
    /*
   do {
        cout<<"Do you have an account Y/N: ";
        getline(cin,qu);
        if(qu=="Y" or qu=="Yes" or qu=="yes")
        {
            qq=true;
        }
        else
        {
           u.createAccount();
           qq=true;
        }
} while (qq==false);
    do { // the input screen
        cout<<"Username: ";
        getline(cin,username);
        cout<<"Password: ";
        getline(cin,password);
        hh=u.login(username,password);// the login funtion that checks the files to see if the user is in the files
        if(hh==false)
        {
            cout<<"Your username/password is incorrect. Make sure that you use the '_'key instead of spaces"<<endl;
            cout<<"Sorry, Please try again"<<endl;

        }
    } while (hh==false);
    */
    do {
        cout<<"Welcome to the Team 24 e-commerce"<<endl;
        //display the name of a catagories
        cout<<"Type one of the following the catagories to display the "<<endl;
        cout<<"Jewels "<<" "<<"Toys"<<" "<<"Movies "<<" "<<"Food"<<endl;
        cout<<"type display- display your profile"<<endl;
        cout<<"type proceed- proceed to checkout"<<endl;
        cout<<"type edit - edit your account"<<endl;
        cout<<"type exit -exit the program"<<endl;
       cout<<">> ";
       getline(cin,ss);
       if(ss=="Jewels")
       {
           string want,amu;
           while(want !="go back")
           {
               cout<<"Welcome to the Jewels catagory"<<endl;
               pp.displayItem("JW");// this will only display the jewels items
               cout<<"Type the name of what you want to buy or type go back to return to the main menu: ";
               getline(cin,want);
               if(want !="go back"){
               cout<<"Type in the amount you want to buy: ";
               getline(cin,amu);
               bool tt=pp.quantiy_check(want,amu);
               if(tt==true)
               {
                   string cq= amu+"x"+pp.getItemID(want);
                   q.addItem(cq);


               }
               else
               {
                   cout<<"Sorry, we do not have the amount that you requested"<<endl;
               }
           }
           }

       }
       else if (ss=="Movies")
       {
           string want,amu;
           while(want !="go back"){
           cout<<"Welcome to the Movies catagory"<<endl;
           pp.displayItem("MV");// this will only display the Moies items
           cout<<"Which one you want to buy or type go back to return to the main menu: ";
           getline(cin,want);
            if(want !="go back"){
           cout<<"Type in the amount you want to buy: ";
           getline(cin,amu);
           bool tt=pp.quantiy_check(want,amu);
           if(tt==true)
           {
               string cq= amu+"x"+pp.getItemID(want);
               q.addItem(cq);
           }
           else
           {
               cout<<"Sorry, we do not have the amount that you requested"<<endl;
           }
            }
           }
       }
       else if (ss=="Toys")
       {
           string want,amu;
           while(want !="go back"){
           cout<<"Welcome to the Toys catagory"<<endl;
          pp.displayItem("TO");// this will only display the Toys items
          cout<<"Which one you want to buy or type go back to return to the main menu: ";
          getline(cin,want);
           if(want !="go back"){
          cout<<"Type in the amount you want to buy: ";
          getline(cin,amu);
          bool tt=pp.quantiy_check(want,amu);
          if(tt==true)
          {
              string cq= amu+"x"+pp.getItemID(want);
              q.addItem(cq);
          }
          else
          {
              cout<<"Sorry, we do not have the amount that you requested"<<endl;
          }
           }
           }
       }
       else if (ss=="Food")
       {
          string want,amu;
          while(want !="go back")
          {
              cout<<"Welcome to the Toys catagory"<<endl;
             pp.displayItem("TO");// this will only display the Toys items
             cout<<"Which one you want to buy or type go back to return to the main menu: ";
             getline(cin,want);
              if(want !="go back"){
             cout<<"Type in the amount you want to buy: ";
             getline(cin,amu);
             bool tt=pp.quantiy_check(want,amu);
             if(tt==true)
             {
                 string cq= amu+"x"+pp.getItemID(want);
                 q.addItem(cq);
             }
             else
             {
                 cout<<"Sorry, we do not have the amount that you requested"<<endl;
             }
              }
          }
       }
       else if (ss=="display")
       {
           q.display();
       }
       else if (ss=="proceed")
       {
       }
       else if (ss=="edit")
       {
           u.editAccount(username);
       }
       else if (ss=="exit")
       {
           cout<<"Thank you for using this website"<<endl;
       }
       //if the user want to exit the program they type exit
    } while (ss!="exit");
    //when the user exits the input screen use the out line function to reinsert the vector infomation back into their apporite files

return 0;

}
void selection(string type)
{
    ItemInfo pp;
    Cart q;
    string want,amu;
    while(want !="go back"){
    if(type=="Jewels")
    {
        cout<<"Welcome to the Jewels catagory"<<endl;
        pp.displayItem("JW");// this will only display the jewels items
        cout<<"Type the name of what you want to buy or type go back to return to the main menu: ";
        getline(cin,want);
        if(want !="go back"){
        cout<<"Type in the amount you want to buy: ";
        getline(cin,amu);
        bool tt=pp.quantiy_check(want,amu);
        if(tt==true)
        {
            string cq= amu+"x"+pp.getItemID(want);
            q.addItem(cq);


        }
        else
        {
            cout<<"Sorry, we do not have the amount that you requested"<<endl;
        }
        }
    }
    else if (type=="Movies")
    {
        cout<<"Welcome to the Movies catagory"<<endl;
        pp.displayItem("MV");// this will only display the Moies items
        cout<<"Which one you want to buy or type go back to return to the main menu: ";
        getline(cin,want);
         if(want !="go back"){
        cout<<"Type in the amount you want to buy: ";
        getline(cin,amu);
        bool tt=pp.quantiy_check(want,amu);
        if(tt==true)
        {
            string cq= amu+"x"+pp.getItemID(want);
            q.addItem(cq);
        }
        else
        {
            cout<<"Sorry, we do not have the amount that you requested"<<endl;
        }
         }
    }
    else if (type=="Toys")
    {
         cout<<"Welcome to the Toys catagory"<<endl;
        pp.displayItem("TO");// this will only display the Toys items
        cout<<"Which one you want to buy or type go back to return to the main menu: ";
        getline(cin,want);
         if(want !="go back"){
        cout<<"Type in the amount you want to buy: ";
        getline(cin,amu);
        bool tt=pp.quantiy_check(want,amu);
        if(tt==true)
        {
            string cq= amu+"x"+pp.getItemID(want);
            q.addItem(cq);
        }
        else
        {
            cout<<"Sorry, we do not have the amount that you requested"<<endl;
        }
         }
    }
    else if (type=="Food")
    {
        cout<<"Welcome to the Toys catagory"<<endl;
       pp.displayItem("TO");// this will only display the Toys items
       cout<<"Which one you want to buy or type go back to return to the main menu: ";
       getline(cin,want);
        if(want !="go back"){
       cout<<"Type in the amount you want to buy: ";
       getline(cin,amu);
       bool tt=pp.quantiy_check(want,amu);
       if(tt==true)
       {
           string cq= amu+"x"+pp.getItemID(want);
           q.addItem(cq);
       }
       else
       {
           cout<<"Sorry, we do not have the amount that you requested"<<endl;
       }
        }
    }
    }
}
