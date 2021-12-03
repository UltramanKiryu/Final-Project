#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include"user.h"
using namespace std;

int main()
{

    ifstream infile;
    ofstream outfile;
    string ttk1,ttk2,ttk3,ttk4,ttk5;
    int num1;
    float flo1;
    userInfo u;
    ItemInfo pp;
    shop q;
    vector<string>qqq;
    infile.open("Username.txt");// insert
    if(!infile.is_open())
    {
        cout<<"Error opening."<<endl;
        return 1;
    }
    while(!infile.eof())
    {
    infile >>ttk1>>ttk2>>ttk3>>ttk4>>ttk5;
    if(!infile.fail())
    {
        u.insertUser(ttk1,ttk2,ttk3,ttk4,ttk5);
    }
    }
    infile.close();
    infile.open("inventory.txt");// insert

    if(!infile.is_open())
    {
        cout<<"Error opening."<<endl;
        return 1;
    }
    while(!infile.eof())
    {
    infile >>ttk2>>ttk1>>num1>>flo1;
    if(!infile.fail())
    {
        pp.insertItem(ttk1,ttk2,num1,flo1);
    }
    }
    infile.close();

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
        string rr,tt;
        infile.open("Cart.txt");// insert any infomation that was still in the cart is now reinsert back into the cart

        if(!infile.is_open())
        {
            cout<<"Error opening."<<endl;
            return 1;
        }
        if(!infile.eof())
        {
            infile >>rr>>tt;
            if(rr==u.getUserID(username))
            {

                pp.InsertCart(qqq,tt);
            }
        }
        infile.close();
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
                  qqq.push_back(cq);

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
               qqq.push_back(cq);

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
              qqq.push_back(cq);
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
             pp.displayItem("FO");// this will only display the Toys items
             cout<<"Which one you want to buy or type back to return to the main menu: ";
             getline(cin,want);
              if(want !="back"){
             cout<<"Type in the amount you want to buy: ";
             getline(cin,amu);
             bool tt=pp.quantiy_check(want,amu);
             if(tt==true)
             {
                 string cq= amu+"x"+pp.getItemID(want);
                 qqq.push_back(cq);

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
           string w,l,nn;
           float ad=0;
           int to=0, aa=0,num=0;
           cout<<"Your Cart"<<endl;
           for(int i=0;i<qqq.size();i++)
           {
               nn=qqq[i];
               to = stoi(nn);
               aa=to;
              while(aa!=0)
              {
                  aa/=10;
                  num++;
              }
              nn.erase(0,num);
              nn.erase(0,1);
              num=0;
              cout<<"Name: "<<pp.getitemName(nn)<<endl;
              cout<<"Amount wanted: "<< to<<endl;
           }
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
                string mm;bool as=false;
                cout<<endl;
                cout<<"type the name of which item you want to delete"<<endl;
                cout<<"type back to return to main menu"<<endl;
                cout<<">>: ";
                getline(cin,w);
                mm=pp.getItemID(w);
                for(int i=0;i<qqq.size();i++){
                    if(qqq[i].find(mm)!=std::string::npos)// it makes it to where only certian type of items ar edisplay instead of all of them
                    {
                        qqq.erase(qqq.begin()+i);
                        as =true;
                    }
                }
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
                for(int i=0;i<qqq.size();i++)
                {
                    nn=qqq[i];
                    int to = stoi(nn);
                     aa=to;
                    while(aa!=0)
                    {
                        aa/=10;
                        num++;
                    }
                    nn.erase(0,num);
                    nn.erase(0,1);
                    num=0;
                    float t=pp.totalPrice(nn,to);
                    ad+=t;

                     pp.ItemOrder(nn,to);
                }
                cout<<"Total Price: "<<ad<<endl;
                 cout<<endl;
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
                        cout<<"Thank you for your purchase"<<endl;
                        qqq.clear();
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
           string tte=u.getUserID(username);
           string trs;
           if(!qqq.empty())
           {
               // insert the vector back into the txt file
               for(int i=0;i<qqq.size();i++)
               {
                   trs+=qqq[i]+"_";
               }
           }
          if(!trs.empty())
          {
              outfile.open("Cart.txt"); // this will delete whatever is in the text file
              if(!outfile.is_open())
              {
                  cout<<"Error opening."<<endl;
              }
              outfile<<tte<<trs<<endl;
              outfile.close();
          }

       }
       //if the user want to exit the program they type exit
    } while (ss!="exit");
    //when the user exits the input screen use the out line function to reinsert the vector infomation back into their apporite files

return 0;

}

