#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Shopping
{
    private:
        int pCode;
        double price, discount;
        string productName;

    public:
        void mainMenu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void delete();
        void list();
        void report();
};


void Shopping::mainMenu()
{
    m:
    int choice;
    string email, password;

    cout << "\n\n\n\n";
    cout << "\t\t\t_________ Mini Shop Billing System ________" << endl << endl << endl << endl;
    cout << "\t1 ] Buyer\n\n" ;
    cout << "\t2 ] Administrator\n\n";
    cout << "\t0 ] Exit Application\n\n";

    cout <<"\nEnter your choice (0 to 2) : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            system("Color 0A");
            cout << "\t\n* * * Please Login to continue * * * ";
            cout << "\nEnter admin email : ";
            cin >> email;
            cout << "\nEnter password : ";
            cin >> password;

            if(email = "admin@gmail.com" && password = "admin123")
            {
                administrator();
            }
            else
                cout << "\nInvalid Email or password !!! ";
            break;
        case 2:
            system("cls");
            system("Color 0A");
            buyer();
            break;
        case 0:
            exit(0);
            cout << "\n\n\t\tThanks for using Mini Shop Billin Management System....\n\n";
            break;
        default:
            cout << "\n\tPlease select from the given option.....\n";
    }
    goto m;
}


void Shopping::administrator()
{
    m:
    int choice();

    cout << "\n\t\t________Admin Dashboard_______\n\n";
    cout << "\t|       1 ] Add record        |\n";
    cout << "\t|                             |\n";
    cout << "\t|       2 ] Modify record     |\n";
    cout << "\t|                             |\n";
    cout << "\t|       3 ] Delete record     |\n";
    cout << "\t|                             |\n";
    cout << "\t|       4 ] Back to main menu |\n";

    cout << "Enter your choice [1 to 4] : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            add();
            break;
        case 2:
            system("cls");
            edit();
            break;
        case 3:
            system("cls");
            delete();
            break;
        case 4:
            system("cls");
            mainMenu();
            break;
        default:
            cout << "\n\tInvalid choice !!!\n";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;

    cout << "\n\n\t\t______Buyer______\n\n";
    cout << "\t|     1 ] Buy Product      |\n";
    cout << "\t|                          |\n";
    cout << "\t|     2 ] Go Back          |\n";
    cout << "\t|                          |\n";

    cout << "\nEnter your choice [1 to 2] : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            report();
            break;
        case 2:
            system("cls");
            mainMenu();
            break;
        default:
            cout << "\n\tInvalid choice !!!\n";
    }
    goto m;
}


void shopping::add()
{
    fstream data;
    int c, token=0;
    float p, d;
    string n;

    cout << "\n\t\t___Add New Record___\n";
    cout << "\n\tEnter Product Code : ";
    cin >> pCode;
    cout << "\n\tEnter Product Price : ";
    cin >> price;
    cout << "\n\tEnter Product on discount : ";
    cin >> discount;
    cout << "\n\tEnter Product Name : ";
    cin >> productName;

    data.open("shopdata.txt", ios::in);

    if(!data)
    {
        data.open("shopdata.txt", ios::app | ios::out);
        data << pCode << " " << price << " " << discount << " " << productName << endl;
        data.close();
    }
    else
    {
        data >> c >> p >> d >> n >> endl;
        while(!data.eof())
        {
            if(c == pCode)
            {
                token++;
            }
            data >> c >> p >> d >> n >> endl;
        }
        data.close();


        if(token == 1)
            goto m;
        else
        {
            data.open("shopdata.txt", ios::app | ios::out);
            data << pCode << " " << price << " " << discount << " " << productName << endl;
            data.close();
        }
    }

    cout << "\n\n\tRecord is successfull inserted.";
}




int main()
{

    return 0;
}
