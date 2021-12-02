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
    removeAccount(username);
    string w,p,e,an,aw;
        cout<<"Enter in your name: ";
        getline(cin,aw);
       cout<<"Enter in a password: ";
       getline(cin,p);
       cout<<"Enter in your email: ";
       getline(cin,e);
       cout<<"Enter a address: ";
       getline(cin,an);
       //inserting the new infomation
       email.push_back(e);
       name.push_back(aw);
       pass.push_back(p);
       address.push_back(an);


}

void userInfo::insertUser(string na, string ID, string mail, string add, string password)
{
    email.push_back(mail);
    name.push_back(na);
    pass.push_back(password);
    address.push_back(add);
    UserID.push_back(ID);
}
void userInfo::createAccount()
{
    string w,p,e,an,aw,er,co,qw,str;
        cout<<"Enter in your first name: ";
        getline(cin,w);
        cout<<"Enter in your last name: ";
        getline(cin,co);
        aw = w+"_"+co;
       cout<<"Enter in a password: ";
       getline(cin,p);
       cout<<"Enter in your email: ";
       getline(cin,e);
       cout<<"Enter a address: ";
       getline(cin,an);

       int random = 100+(rand()%201);
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
void userInfo::displayUser(string username)
{
    userInfo u;
    for(unsigned int i=0;i<name.size();i++)
    {

        if(username==name[i])
        {
            cout<<endl;
            cout<<"Name: "<<name[i]<<endl;
            cout<<"UserID: "<<getUserID(name[i])<<endl;
            cout<<"Address: "<<getAddress(name[i])<<endl;
            cout<<"Email: "<<getEmail(name[i])<<endl;
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

    for(int i=0;i<itemID.size();i++)
    {
        if(ID==itemID[i])
        {
            cout<<itemName[i]<<endl;
            return itemName[i];
        }
    }
    return "Not listed";
}

int ItemInfo::getInventory(string ID)
{
    for(unsigned int i=0;i<itemID.size();i++)
    {
        if(itemID[i]==ID)
        {
            return quaitiy[i];
        }
    }
    return 0;
}
double ItemInfo::getPrice(string ID)
{
    for(unsigned int i=0;i<itemID.size();i++)
    {
        if(itemID[i].find(ID)!=std::string::npos)
        {
            return Price[i];
        }
    }
    return 0.00;
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
void ItemInfo::insertItem(string name, string ID, float pr, int qu)
{
    itemName.push_back(name);
    itemID.push_back(ID);
    Price.push_back(pr);
    quaitiy.push_back(qu);
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

void ItemInfo::ItemOrder(string name,int amount)
{
    int we=0,te,e=0;
    for(unsigned int i=0; i<itemName.size();i++)
    {
        if(name==itemName[i])
        {
            te =getInventory(itemID[i]);
            te=te-amount;
            e=we;
        }
        we++;
    }
    quaitiy.insert(quaitiy.begin()+e,te);

}
string shop::is_Empty(string username)
{
    if(!ca.empty())
    {
        string trs;
        // insert the vector back into the txt file
        for(int i=0;i<ca.size();i++)
        {
            trs+=ca[i]+"_";
        }
        return trs;
    }
}
void shop::display(vector<string>&list)
{
    ItemInfo pp;
    string nn,qq,ee;
    int num=0,aa=0;
    for(int i=0;i<list.size();i++)
    {
        nn=list[i];
        int to = stoi(list[i]);
        /*
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
        cout<<"Amount wanted: "<<to<<endl;
         cout<<endl;
         */
    }

}
float ItemInfo::totalPrice(string ID,int amount)
{
    ItemInfo pp;
    float qe =getPrice(ID);
    float rr=qe*amount;
    return rr;
}
void shop::addItem(string qr)
{
    ca.push_back(qr);
}
void shop::insertCart(string car)
{
    ca.push_back(car);

}
bool shop::removeItem(string qr)
{
    for(unsigned int i=0;i<ca.size();i++)
    {
        if(ca[i].find(qr)!=std::string::npos)// it makes it to where only certian type of items ar edisplay instead of all of them
        {
            ca.erase(ca.begin()+i);
            return true;
        }
    }
    return false;
}
/*
void shop::checkout(vector<string>&list)
{
    ItemInfo pp;
    string nn,qq,ee;
    int num=0,aa=0;
    float ad=0;
    for(int i=0;i<list.size();i++)
    {
        nn=ca[i];
        int to = stoi(ca[i]);
         aa=to;
        while(aa!=0)
        {
            aa/=10;
            num++;
        }
        nn.erase(0,num);
        nn.erase(0,1);
        num=0;
        float t=totalPrice(nn,to);
        ad+=t;
         //pp.ItemOrder(nn,to);
    }
    cout<<"Total Price: "<<ad<<endl;
     cout<<endl;
}
*/
bool shop::purchase()
{ ItemInfo pp;

    ca.clear();
    return true;
}



