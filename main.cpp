#include <iostream>
#include <algorithm>
#include <string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include"user.h"
using namespace std;

int main()
{

    int num1;
    float flo1;
    userInfo u; 
    ItemInfo pp;
    Cart q;


    string username, password,qu,cat,wan;
    string ss;
    bool hh=false;
    bool qq= false;
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
    do {
        cout<<"Welcome to the Team 24 e-commerce"<<endl;
        //display the name of a catagories
        cout<<"Type one of the following the catagories to display the "<<endl;
        cout<<"Jewels "<<" "<<"Toys"<<" "<<"Movies "<<" "<<"Food"<<endl;
        cout<<"type display- display your profile"<<endl;
        cout<<"type View Cart- to view you cart"<<endl;
        cout<<"type edit - edit your account"<<endl;
        cout<<"type exit -exit the program"<<endl;
       cout<<">> ";
       getline(cin,ss);
       if(ss=="Jewels")
       {
           string want,amu;
           while(want !="back")
           {
               cout<<"Welcome to the Jewels catagory"<<endl;
               pp.displayItem("JW");// this will only display the jewels items
               cout<<"Type the name of what you want to buy or type go back to return to the main menu: ";
               getline(cin,want);
               if(want !="back"){
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
           while(want !="back"){
           cout<<"Welcome to the Movies catagory"<<endl;
           pp.displayItem("MV");// this will only display the Moies items
           cout<<"Which one you want to buy or type go back to return to the main menu: ";
           getline(cin,want);
            if(want !="back"){
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
           while(want !="back"){
           cout<<"Welcome to the Toys catagory"<<endl;
          pp.displayItem("TO");// this will only display the Toys items
          cout<<"Which one you want to buy or type back to return to the main menu: ";
          getline(cin,want);
           if(want !="back"){
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
          while(want !="back")
          {
              cout<<"Welcome to the Toys catagory"<<endl;
             pp.displayItem("TO");// this will only display the Toys items
             cout<<"Which one you want to buy or type back to return to the main menu: ";
             getline(cin,want);
              if(want !="back"){
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
           u.displayUser(username);
           cout<<endl;
       }
       else if (ss=="View Cart")
       {
           string w,l;
           cout<<"Your Cart"<<endl;
           q.display();
            cout<<endl;
           while(w!="back")
           {
               cout<<"type proceed- to proceed to checkout"<<endl;
               cout<<"type remove - to remove an item from your list"<<endl;
               cout<<"type back to return to main menu"<<endl;
               cout<<">>: ";
               getline(cin,w);
            if(w=="remove")
            {
                string mm;
                cout<<endl;
                cout<<"type the name of which item you want to delete"<<endl;
                cout<<"type back to return to main menu"<<endl;
                cout<<">>: ";
                getline(cin,w);
                mm=pp.getItemID(w);
                bool as =q.removeItem(mm);
                if(as==true)
                {
                    cout<<"The Item has been removed"<<endl;
                }
                else
                {
                    cout<<"The item is not in your cart"<<endl;
                }
            }
            else if(w =="proceed")
            {
                cout<<endl;
                cout<<"...Proceeding to checkout"<<endl;
                q.checkout();
                string mm;
                while(mm!="back"){
                    cout<<endl;
                cout<<"type continue to pay for you order:"<<endl;
                cout<<"type back to return to main menu"<<endl;
                cout<<">>: ";
                getline(cin,mm);
                if(mm=="continue")
                {
                    u.displayUser(username);
                     cout<<endl;
                    cout<<"Is this the correct infomation"<<endl;
                    cout<<"type yes to confirm"<<endl;
                    cout<<"type back to return to main menu"<<endl;
                     cout<<">>: ";
                      getline(cin,mm);
                    if(mm=="yes")
                    {
                        cout<<"Thnak you for your pruchase"<<endl;
                        //q.purchase();
                        w="back";
                        mm="back";
                    }
                }
                }
            }
           }
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
    u.exportUsers(username);
    //q.exportUsers(username);
return 0;

}

