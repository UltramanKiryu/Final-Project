#include "user.h"

userInfo::userInfo()
{

}
bool userInfo::login(string username, string password)
{
    // check to see if username  and pass word are in the username file and passfile
    for(unsigned int i=0;i<name.size();i++)
    {
        if(username==name[i])
        {
            if(password==pass[i])//see if the
            {
                cout<<"Welcome: "<<username<<endl;
                return true;
             }
        }
    }
    return false;
}
void userInfo::editAccount(string username) // replaceing the current user's info with the new infomation
{
    bool qe =false;
    string w,p,e,an,aw;
        unsigned int i=0;
        cout<<"Enter in your name: ";
        getline(cin,aw);
       cout<<"Enter in a password: ";
       getline(cin,p);
       cout<<"Enter in your email: ";
       getline(cin,e);
       cout<<"Enter a address: ";
       getline(cin,an);

}
void userInfo::createAccount()
{
    string w,p,e,an,aw,er,co,qw,str;
        cout<<"Enter in your first name: ";
        cin>>w;
        cout<<"Enter in your last name: ";
        cin>>co;
        aw = w+"_"+co;
       cout<<"Enter in a password: ";
       getline(cin,p);
       cout<<"Enter in your email: ";
       getline(cin,e);
       cout<<"Enter a address: ";
       getline(cin,an);

       int random = 100+(rand()%101);
       str=to_string(random);
       er= w[0];
       qw =co[0];

       string wer= er+qw+str;
       UserID.push_back(wer);
       email.push_back(e);
       name.push_back(aw);
       pass.push_back(p);
       address.push_back(an);

   }
bool userInfo::removeAccount(string word)
{
    //delete the current user account
    for(unsigned int i=0;i<name.size();i++)
    {
        if(word==name[i])
        {
          name.erase(name.begin()+i);
          UserID.erase(UserID.begin()+i);
          address.erase(address.begin()+i);
          pass.erase(pass.begin()+i);
          email.erase(email.begin()+i);
          return true;
        }
    }
    return false;
}
void userInfo::displayUser(string word)
{
    userInfo u;
    for(unsigned int i=0;i<name.size();i++)
    {
        if(word==name[i])
        {
            cout<<endl;
            cout<<"Name: "<<name[i]<<endl;
            cout<<"UserID: "<<u.getUserID(name[i])<<endl;
            cout<<"Address: "<<u.getAddress(name[i])<<endl;
            cout<<"Email: "<<u.getEmail(name[i])<<endl;
            cout<<endl;

        }

    }
}
string userInfo::getUserID(string word)
{
    //look through the name to get the UserID
    for(unsigned int i=0;i<name.size();i++)
    {
        if(word==name[i])
        {
          return UserID[i];
        }
    }
    return "Not listed";
}
string userInfo::getAddress(string word)
{
    for(unsigned int i=0;i<name.size();i++)
    {
        if(word==name[i])
        {
          return address[i];
        }
    }
    return "Not listed";
}
string userInfo::getEmail(string word)
{
    for(unsigned int i=0;i<name.size();i++)
    {
        if(word==name[i])
        {
          return email[i];
        }
    }
    return "Not listed";
}

string ItemInfo::getitemName(string ID)
{
    for(unsigned int i=0;i<itemID.size();i++)
    {
        if(itemID[i]==ID)
        {
            return itemName[i];
        }
    }
    return "Not listed";
}


string ItemInfo::getItemID(string name)
{
    for(unsigned int i=0;i<itemName.size();i++)
    {
        if(itemName[i]==name)
        {
            return itemID[i];
        }
    }
    return "Not listed";
}
void ItemInfo::displayItem(string type)
{
    for(unsigned int i=0;i<itemID.size();i++)
    {
        if(itemID[i].find(type)!=std::string::npos)// it makes it to where only certian type of items ar edisplay instead of all of them
        {
        cout<<"Name: "<<itemName[i]<<endl;
        cout<<"ID: "<<itemID[i]<<endl;
        cout<<"Price: "<<Price[i]<<endl;
        cout<<"Quanity: "<<quaitiy[i]<<endl;
        cout<<endl;
        }
    }
}
bool ItemInfo::quantiy_check(string name,string amount)
{
    for(unsigned int i=0; i<itemName.size();i++)
    {
        if(name==itemName[i])
        {
            int amu=stoi(amount);
            if(amu < quaitiy[i])
            {
                return true;
            }
            else if(amu==quaitiy[i])
            {
                return true;
            }

        }
    }
    return false; // if the amount requested by the user is greater than what is in stock
}
void Cart::display()
{
    ItemInfo pp;
    string nn,qq,ee;
    for(int i=0;i<cart.size();i++)
    {
        cout<<cart[i]<<endl;
        nn=cart[i];
        qq=nn[0];
        ee=nn[2]+nn[3]+nn[4]+nn[5]+nn[6]+nn[7]+nn[8];
        int to = stoi(qq);

    }

}
int Cart::totalPrice(string name)
{

}
void Cart::addItem(string qr)
{
    cart.push_back(qr);
}
void removeItem(string qr);
