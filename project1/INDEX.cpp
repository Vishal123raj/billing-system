#include <bits/stdc++.h>
using namespace std;
class shopping
{
     private:
     int pcode;
     float price;
     float discount;
     string pname;

     public:
     void menu();
     void administrator();
     void buyer();
     void add();
     void edit();
     void Remove();
     void list();
     void reciept();



};
void shopping :: menu()
{
    m:  //level for goto function
    int choice;
    string email;    //this is for administrative purpose
    string password;  //administrative purpose
    cout<<"\t\t\t______________________\n";
    cout<<"\t\t\t       SUPER MARKET MAIN MENU        \n";
    cout<<"\t\t\t______________________\n";

    cout<<"\t\t\t\t   1.) Administrator   \n";
    cout<<"\t\t\t\t   2.) Buyer   \n";
    cout<<"\t\t\t\t   3.) exit   \n";
    cout<<"\t\t\t______________________\n";
    cout<<"\n \t\t\t Please select";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
           cout<<"\t\t\t Please login\n";
           cout<<"\t\t\t Enter email:\n";
           cin>>email;
           cout<<"\t\t\t Enter Password\n";
           cin>>password;
            
           if(email=="rajvishal1410@gmail.com" && password=="Vishal@123")
           {
               administrator();
           }
           else
           {
               cout<<"Invalid email/password";
           }
           break;
        }
         case 2:
        {
        buyer();
        }
        case 3:
       {
        exit(0);
       }
       default:
       {
        cout<<"Please selct from given options";
       }
           

    }
   goto m; // it is a function that helps us to jump to main menu with level m

}


void shopping :: administrator()
{ 
    m:
    int choice;
    cout<<"\n\n\t\t\tAdministrator Menu";
    cout<<"\n\t\t\t ____1.) Add product_____\n";
    cout<<"\n\t\t\t ____2.) Modify the product_____\n";
    cout<<"\n\t\t\t ____3.) Delete the product_____\n";
    cout<<"\n\t\t\t ____4.) Back to main menu _____\n";

    cout<<"\n\t\t\t Please Enter the choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            Remove();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"\n\t\t Invalid Choice!\n";
        }
    }
    goto m; //Jump statement
}

void shopping :: buyer()
{ 
    m:
    int choice;
    cout<<"\n\t\t\t Buyer\n";
    cout<<"\n\t\t\t 1.) Buy Product\n";
    cout<<"\n\t\t\t 2.)Go Back\n";
    cout<<"\n\t\tEnter your choice\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
            reciept(); //all buyer function is in reciept function
            break;

        case 2:
            menu();

        default:
        cout<<"\n\t\t\tInvalid choice\n";    
    }
   goto m;

}

void shopping ::add()
{ 
    m:
    fstream data; //file handling operations
    int c;
    int token=0;
    float p,d;
    string n;
    cout<<"\n\t\t\t Add new product\n";
    cout<<"\n\t\t\t Product code of the product";
    cin>>pcode;
    cout<<"\n\t\t\tName of the product\n";
    cin>>pname;
    cout<<"\n\t\t\tprice of the product\n";
    cin>>price;
    cout<<"\n\t\t\tDiscount on the product\n";
    cin>>discount;

    data.open("database.txt",ios::in);//this is file handling operation with the help of this we are able to open the 
                                      //file name database.txt in reading mode and for writing mode we use out in place of in
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);//if data is not exist then add 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close(); //for closing the file
    } 
    else
    {
        //initialse the file
        data>>c>>p>>n>>d; //if data exist then we read from the file
        //use while loop to iterate through the file
        while(!data.eof())  //eof means end of file functioin
        {
            if(c==pcode)  //if code is present the their is duplicacy
            {
                token++;
            }
            data>>c>>p>>n>>d; //reading from the file for iteration purpose

        }
        data.close();
    }
    if(token==1) //if product code enter by the administrator is already exist then he/she has to enter another code
    {
        goto m; //go back to menu because of dupicacy
    }
    else               //if code is unique
    {
        data.open("database.txt",ios::app|ios::out);//open the file in append and writing mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close(); 
    }

                                    
cout<<"\n\t\tRecord inserted";

}

void shopping :: edit()
{
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;
    cout<<"\n\t\t\tModify the record\n";
    cout<<"\n\t\t\t Product code\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\t\ttData not exist\n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);//for edit we create a new file and after edit we rename this as original file name
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t\tProduct new code\n\n";
                cin>>c;
                cout<<"\n\n\t\t\tName of the product\n\n";
                cin>>pname;
                cout<<"\n\n\t\t\tPrice of product\n\n";
                cin>>p;
                cout<<"\n\n\t\t\tDiscount on product\n\n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\tRecord edited\n";
                token++;

            }
            else
            {
                 data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("dastabase.txt");//remove all values from list/file
        rename("database1.txt","database.txt");//rename the file name
        if(token==0)
        {
            cout<<"\n\t\t\tRecord not found";
        }

    }

}

void shopping::Remove()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\t\tDelete product\n";
    cout<<"\n\t\tEnter product code\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\tFile doesn't exist";

    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pname>>pcode>>price>>discount;//initialize the while loop
        while(!data.eof())
        {
            if(pcode==pkey)               //If pkey matches then if block ececute otherwise else execute and all data is copied in this.
            {
            cout<<"\n\n\t\tProduct deleted sucessfully\n";
            token++;
            }
            else
            {
               data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";//in database1 file all the products will display 
                                                               //except the one which matches wurth pkey and after that we display the database1 file
                                                               //that contains all the elements except pkey:
            }
            data>>pname>>pcode>>price>>discount; //for iterating while loop.
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");


        if(token==0)
        {
            cout<<"\n\t\t\tRecord not found\n";
        }
        
    }

}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n";
    cout<<"\n\t\tProductNO.\t\tName\t\tprice";
    cout<<"\n\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t";
        data>>pcode>>pname>>price>>discount;//for iteration

    }
    data.close();
}

void shopping::reciept()
{
    
    fstream data;
    int codes[100];
    int quantity[100];
    int choice,counter=0;
    float amount=0,discount=0,total=0;
    cout<<"\n\t\tReciept\n";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\tEmpty Database\n";
    }
    else
    {
        data.close();
        list();
        cout<<"____________________";
        cout<<"\n\t\tPlease place the Order\n";
        cout<<"__________________________";
        do
        {
            m:
            cout<<"\n\t\tenter the product code\n";
            cin>>codes[counter];
            cout<<"\n\t\tenter the product quantity\n";
            cin>>quantity[counter]; 
            for(int i=0;i<counter;i++)
            {
               if(codes[counter]==codes[i])
               {
               cout<<"\n\t\tDuplicte product code. Please try again";
               goto m;
               }
            }
            counter++;
            cout<<"Want to buy another product if yes then press 1 else 0";
            cin>>choice;
        }while(choice==1);
        cout<<"\n\n\t\t\t_________RECIEPT__________\n";
        cout<<"\n\nproduct no.\t\tproduct name\t\tproduct quantity\tprice\tamount\tamount with discount\n";
        for(int i=0;i<counter;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==codes[i])
                {
                   amount=price*quantity[i];
                   discount=amount-(amount*discount/100);
                   total=total+discount;
                   cout<<"\n"<<pcode<<" "<<pname<<" "<<quantity[i]<<" "<<price<<" "<<amount<<" "<<discount<<"\n";
                }
                data>>pcode>>pname>>price>>discount;
            }
        }
        data.close();
    }

    cout<<"\n\n_________________";
    cout<<"\n\t\tTOTAL AMOUNT\n";
}
int main()
{
       shopping s;
       s.menu();

}