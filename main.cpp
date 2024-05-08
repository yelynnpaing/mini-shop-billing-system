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
        void del();
        void list();
        void receipt();
};


void Shopping::mainMenu()
{
    m:
    system("Color 09");
    int choice;
    string email, password;

    cout << "\n\n\n\n";
    cout << "\t\t\t_________ Mini Shop Billing System ________" << endl << endl << endl << endl;
    cout << "\t1 ] Administrator\n\n" ;
    cout << "\t2 ] Buyer\n\n";
    cout << "\t0 ] Exit Application\n\n";

    cout <<"\nEnter your choice (0 to 2) : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            system("Color 0A");
            cout << "\n\t\t* * * Please Login to continue * * * ";
            cout << "\n\n\nEnter admin email : ";
            cin >> email;
            cout << "\nEnter password : ";
            cin >> password;

            if(email == "admin@gmail.com" && password == "admin123")
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
    int choice;

    cout << "\n\n\n\t________Admin Dashboard________\n\n";
    cout << "\t|       1 ] Add record        |\n";
    cout << "\t|                             |\n";
    cout << "\t|       2 ] Modify record     |\n";
    cout << "\t|                             |\n";
    cout << "\t|       3 ] Delete record     |\n";
    cout << "\t|                             |\n";
    cout << "\t|       4 ] Show record       |\n";
    cout << "\t|                             |\n";
    cout << "\t|       5 ] Back to main menu |\n";

    cout << "\n\nEnter your choice [1 to 4] : ";
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
            del();
            break;
        case 4:
            system("cls");
            cout << "\n\n\t\t\t\tProuct List\n\n";
            list();
            break;
        case 5:
            system("cls");
            mainMenu();
            break;
        default:
            cout << "\n\tInvalid choice !!!\n";
    }
    goto m;
}

void Shopping::buyer()
{
    m:
    int choice;

    cout << "\n\n\t\t______Buyer______\n\n";
    cout << "\t|     1 ] Buy Product      |\n";
    cout << "\t|                          |\n";
    cout << "\t|     2 ] Go Back          |\n";
    cout << "\t|                          |\n";

    cout << "\n\tEnter your choice [1 to 2] : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            system("cls");
            receipt();
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


void Shopping::add()
{
    m:
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
        data >> c >> p >> d >> n;
        while(!data.eof())
        {
            if(c == pCode)
            {
                token++;
            }
            data >> c >> p >> d >> n;
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

    cout << "\n\n\tNew record is successfully inserted.\n\n";
}


void Shopping::edit()
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
            if(productKey == pCode)
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
            data >> pCode >> price >> discount >> productName;
        }

        data.close();
        tempData.close();

        remove("shopdata.txt");
        rename("tempData.txt", "shopdata.txt");

        if(token == 0)
            cout << "\n\n\tSorry!.. no product found.\n";
    }
}

void Shopping::del()
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
        tempData.open("tempData.txt", ios::app|ios::out);
        data >> pCode >> price >> discount >> productName;
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

            data >> pCode >> price >> discount >> productName;
        }

        data.close();
        tempData.close();
        remove("shopdata.txt");
        rename("tempData.txt" , "shopdata.txt");

        if(token == 0)
            cout << "\n\n\tNo record found !!! \n";

    }

}


void Shopping::list()
{
    fstream data;
    cout << "\n\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    cout << "\t|    Product Code   |            Product Name          |      Price      |       Discount      |\n";
    cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    data.open("shopdata.txt", ios::in);
    data >> pCode >> price >> discount >> productName;

    while(!data.eof())
    {
        cout << "\n\t|    " << pCode << "\t\t   |       " << productName << "\t\t       |      " << price << "   |    " <<  discount << " %    |" << endl;

        data >> pCode >> price >> discount >> productName;
    }
    cout << "\n\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    data.close();
}


void Shopping::receipt()
{
    fstream data;
    int arrCode[100], arrQuantity[100];
    char choice;
    int code=0;
    double amount=0, disc=0, total=0;

    cout << "\n\n\t\t\t\t__________PRODUCTS LIST__________\n\n";

    data.open("shopdata.txt", ios::in);
    if(!data)
    {
        cout << "\n\n\tData does not exit....\n";
    }
    else
    {
        data.close();
        list();

        cout << endl << endl << endl ;
        cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
        cout << "\t|                                                          |\n";
        cout << "\t|                 * * * Place an order * * *               |\n";
        cout << "\t|                                                          |\n";
        cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";

        do{
            m:
            cout << "\n\n\tEnter product code : ";
            cin >> arrCode[code];
            cout << "\n\tEnter product quantity : ";
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

        cout << "\n\n\t\t\t\tRECEIPT\n";
        cout << "\t\t\t\t- - - - \n\n";
        cout << "\t_______________________________________________________________________________________________\n";
        cout << "\tProduct Code" << "\tProduct Name" << "\tQuantity" << "\tPrice" << "\t\tAmount" << "\t\tDiscount\n";
        cout << "\t_______________________________________________________________________________________________\n";

        for(int i=0; i<code; i++)
        {
            data.open("shopdata.txt", ios::in);
            data >> pCode >> price >> discount >> productName;

            while(!data.eof())
            {
                if( pCode == arrCode[i] )
                {
                    amount = price * arrQuantity[i];
                    disc = amount - (amount * discount/100);
                    total = total + disc;

                    cout << "\n\t\t" << pCode << "\t" << productName << "\t\t   " << arrQuantity[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << disc;
                }

                data >> pCode >> price >> discount >> productName;
            }
        }
        data.close();

    }
    cout << "\n\t_______________________________________________________________________________________________\n";
    cout << "\n\n\tTotal is " << total << endl;
    cout << "\n\t_______________________________________________________________________________________________\n";
}


int main()
{
    Shopping shopping;
    shopping.mainMenu();

    return 0;
}
