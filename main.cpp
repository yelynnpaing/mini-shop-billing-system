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


void shopping::edit()
{
    fstream data, tempData;
    int productKey, token = 0, c;
    double p, d;
    string n;

    cout << "\n\n\t\t_______Edit Product________\n\n";
    cout << "\n\tTo edit enter product code : ";
    cin >> productKey;

    data.open("shopdata.txt", ios::in);
    if(!data)
    {
        cout << "\n\tFile does not exit.\n";
    }
    else
    {
        tempData.open("tempData.txt", ios::app | ios::out);
        data >> pCode >> price >> discount >> productName;

        while(!data.eof())
        {
            if(productKey == pcode)
            {
                cout << "\n\tEnter New Product Code : ";
                cin >> c;
                cout << "\n\tEnter New Prouduct Price : ";
                cin >> p;
                cout << "\n\tEnter Product Name : ";
                cin >> n;
                cout << "\n\tEnter Product Discount Range : ";
                cin >> d;
                tempData << " " << c << " " << p << " "  << d << " " << n << "\n";
                cout << "\n\n\tProduct update is successful ...\n";

                token++;
            }
            else
            {
                tempData << " " << pCode << " " << price << " "  << discount << " " << productName << "\n";
            }
        }

        data.close();
        tempData.close();

        remove("shopdata.txt");
        rename("tempData.txt", "shopdata.txt");

        if(token == 0)
            cout << "\n\n\tSorry!.. no product found.\n";
    }
}

void shopping::delete()
{
    fstream data, tempData;
    int productkey, token=0;

    cout << "\n\n\t\t_________Delete Product_________\n\n";
    cout << "\n\tEnter Product Code : ";
    cin >> productkey;

    data.open("shopdata.txt", ios::in);

    if(!data)
    {
        cout << "\n\tFile does not exit\n";
    }
    else
    {
        tempData.open("tempData.txt", ios::app | ios::out);
        data >> pCode >> price >> discount >> productName >> endl;
        while(!data.eof())
        {
            if(pCode == productkey)
            {
                cout << "\n\tProduct deleted successful.\n";
                token ++;
            }
            else
            {
                tempData << " " << pCode << " " << price << " " << discount << " " << productName << endl;
            }

            data >> pCode >> price >> discount >> productName >> endl;
        }

        data.close();
        tempData.close();
        remove("shopdata.txt");
        rename("tempData.txt" , "shopdata.txt");

        if(token == 0)
            cout << "\n\n\tNo record found !!! \n";

    }

}


void shopping::list()
{
    fstream data;
    cout << "\n\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
    cout << "\t|    Product Code   |            Product Name          |      Price      |\n\n";
    data.open("shopdata.txt", ios::in);
    data >> pCode >> price >> productName >> endl;

    while(!data.eof())
    {
        data << "\n\t|    " << pCode << "   |       " << productName << "       |      " << price << "   |" << endl;

        data >> pCode >> price >> productName;
    }

    data.close();
}


void shopping::receipt()
{
    m:
    fstream data;
    int arrCode[100], arrQuantity[100];
    char choice;
    int code=0;
    double amount=0, disc=0, total=0;

    cout << "\n\n\t\t__________Receipt__________\n\n";

    data.open("shopdata.txt", ios::in);
    if(!data)
    {
        cout << "\n\n\tData does not exit....\n";
    }
    else
    {
        data.close();
        list();

        cout << endl << endl;
        cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
        cout << "\t|                                                          |\n";
        cout << "\t|                 * * * Place an order * * *               |\n";
        cout << "\t|                                                          |\n";
        cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";

        do{
            cout << "\n\n\tEnter product code : \n";
            cin >> arrCode[code];
            cout << "\nEnter product quantity : \n";
            cin >> arrQuantity[code];

            for(int i=0; i<code; i++)
            {
                if(arrCode[code] == arrCode[i])
                {
                    cout << "\n\tDuplicate product code. Please try again...\n";
                    goto m;
                }
            }
            code++;

            cout << "\n\tDo you want to buy another product ? Please choice ( y / n ) : ";
            cin >> choice;
        }while(choice == 'y');


    }
}


int main()
{

    return 0;
}
