#include<iostream>
#include<string>
#include <fstream>
#include<conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
fstream file;
class Store {
protected:
    // data members//
    string category;
    int qty;
    string prName;
    int prNo;
    float price;
    float disc;
public:
    //member functios of store classs//
    void Add();
    void search();
    void modify();
    void dlete();
    void Show();
    void A();


};
class Categorymenu :public Store {
public:
    //member function of classs//
    void addbycategory();
    void showbycategory();
    void dletebycategory();
};
class Category :public Store {
public:
    //member function of classs//
    void addgrocery();
    void addclothes();
    void addvegetables();
    void Showgroc();
    void Showveg();
    void Showclo();
    void dleteveg();
    void dletegroc();
    void dleteclo();
};
class Login :public Store {
public:
    //MEMBER FUNCTIONS OF LOGIN CLASS//
    void signin();
    void signup();
    void loginform();
};
class Admin : public Store {

public:
    //MEMBER FUNCTIONS OF ADMIN CLASS//
    void menu();
    void admin();
    void list();


};
class Customer :public Admin {
public:

    //MEMBER FUNCTIONS OF CUSTOMER CLASS//
    void custmenu();
    void finalBill();
    void billpage();
    void signins();
    void billproductquan_modify();
    void billproductquan_modify2();





};

void Admin::menu() //Main Menu
{
    Login login_obj;
p:
    Customer customer_obj;
    system("cls");
    int choice;
    cout << "\n\n\n\n\n\t\t\t\t\t ------------------------------" << endl;
    cout << "\t\t\t\t\t| General Store Managment System|" << endl;
    cout << "\t\t\t\t\t ------------------------------" << endl;
    cout << "\n\n\t\t\t\t\t\t 1: Admin" << endl;
    cout << "\n\n\t\t\t\t\t\t 2: Customer" << endl;
    cout << "\n\n\t\t\t\t\t\t 3: list of all goods" << endl;
    cout << "\n\n\t\t\t\t\t\t 4: Exit" << endl;
    cout << "\n\n\t\t\t\t\tChoose the mode which u want to use:";
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1:
        system("cls");



        login_obj.loginform();
    case 2:
        system("cls");
        customer_obj.custmenu();
        break;
    case 3:
        system("cls");
        list();
        break;
    case 4:
        break;
    default:
        cout << "\n\n\t\t\t\t invalid input! plzz.... try agin later" << endl;

    }
    _getch();
    goto p;
}
void Login::loginform() //Login form ..
{
    system("cls");
    int choice;
    cout << "\n\t\t\t\t\t\t------------------------------" << endl;
    cout << " \t\t\t\t\t\t| Login and Sign up page :   |";
    cout << "\n\t\t\t\t\t\t------------------------------" << endl;
    cout << "\n\n\n\n\n\t\t\t\t\t\t 1: Presss 1 for Sign up Account ";
    cout << "\n\n\n\t\t\t\t\t\t 2: Presss 2 for Log in Account ";
    cout << "\n\n\n\t\t\t\t\t\t Enter your choice :";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        signup();

        loginform();
        break;

    case 2:
        system("cls");
        signin();

        break;
    default:
        cout << "invalid input !!.... Plzz try again later" << endl;

    }
}
void Login::signin()// SIGN IN PAGE //
{
    Admin admin_obj;
    int count = 0;
    char ch;
    string username, u, password, p;
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t SIGN IN :" << endl;
    cout << "\n\n\n\t\t\t\t PLEASE ENTER THE FOLLOWING DETAILS :" << endl;
    cout << "\n\n\n\t\t\t\t\t ENTER YOUR USERNAME :";
    cin >> username;
    cout << "\n\n\t\t\t\t\t ENTER YOUR PASSWORD :";
    cin >> password;




    fstream file2;
    file2.open("database.txt", ios::in);
    while (file2 >> u >> p)
    {
        if (u == username && p == password)

        {
            count = 1;

        }
    }
    file2.close();
    if (count == 1)
    {
        cout << "\t\t\t\n\t\t\t\t\t\t Hello " << username << "\n\n\t\t\t\t<LOGIN SUCCESSFUL>\n\n\t\t\t\tThanks for logging in..\n";
        cin.get();

        int back_to_admin;
        cout << "\n\n\t\t\t\t Now u will also able to access the Admin panel Press 1 to go";

        cin >> back_to_admin;

        if (back_to_admin == 1)
            admin_obj.admin();
    }
    else
    {
        cout << "\n\n\t\t\t\t\tLOGIN ERROR\n\n\t\t\t\t\tPlease check your username and password\n";
        _getch();
        // IF YOU WILL ENTER WRONG USER NAME AND PASSWORD U WILL REDIRECT TO LOGIN FORM BACK//
        loginform();
    }
}
void Customer::signins()
{
    int count = 0;
    char ch;

    string username, USERNAME_CHECK, password, PASSWORD_CHECK;
signin_again:
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t SIGN IN :" << endl;
    cout << "\n\n\n\t\t\t\t PLEASE ENTER THE FOLLOWING DETAILS :" << endl;
    cout << "\n\n\n\t\t\t\t\t ENTER YOUR USERNAME :";
    cin >> username;
    cout << "\n\n\t\t\t\t\t ENTER YOUR PASSWORD :";

    cin >> password;




    fstream file2;
    file2.open("database.txt", ios::in);
    while (file2 >> USERNAME_CHECK >> PASSWORD_CHECK)
    {
        if (USERNAME_CHECK == username && PASSWORD_CHECK == password)

        {
            count = 1;
        }
    }
    file2.close();
    if (count == 1)
    {
        cout << "\t\t\t\n\t\t\t\t\t\t Hello " << username << "\n\n\t\t\t\t<LOGIN SUCCESSFUL>\n\n\t\t\t\tThanks for logging in..\n";
        cin.get();


        int redirect_var;
        cout << "\n\n\t\t\t\t Now u will also able to access the Admin panel Press 1 to go";

        cin >> redirect_var;

        if (redirect_var == 1)
            billproductquan_modify();
    }
    else
    {
        cout << "\n\n\t\t\t\t\tLOGIN ERROR\n\n\t\t\t\t\tPlease check your username and password\n";
        goto signin_again;
    }
}
void Login::signup()//sign up page//
{

    string signuser, signpass, username_check, password_check;
    int count = 0;
signup_again:
    system("cls");
    cout << "\n\n\n\t\t\t\t\t  Sign Up :";
    cout << "\n\n\n\t\t\t\t\t Enter the username :";
    cin >> signuser;
    cout << "\n\n\t\t\t\t\t Enter the password :";
    cin >> signpass;

    fstream file;
    file.open("database.txt", ios::in);
    while (file >> username_check >> password_check)
    {
        if (username_check == signuser && password_check == signpass)

        {
            count = 1;
            cout << "\n\n\t\t\t This username and password already exsists.";
            _getch();
            goto signup_again;

        }
    }
    file.close();
    if (count == 0) {
        file.open("database.txt", ios::app | ios::out);
        file << signuser << ' ' << signpass << endl;


        cout << "\n\n\t\t\t\t\t Account Created Sucessfully \n";
        cout << "\n\n\t\t\t\t\t press 1 to go to Login form .....";
        _getch();
        system("cls");
        loginform();
    }

}

void Admin::admin() { // Admin menu
admin:

    system("cls");
    Categorymenu c1;

    int choice;
    cout << "\n\n\n\t\t\t\t\t\t Admin Panel Of Our Store";
    cout << "\n\n\n\n\t\t\t\t\t\t 1: Add a New Product.";
    cout << "\n\n\n\t\t\t\t\t\t 2: Search Exsisting Product.";
    cout << "\n\n\n\t\t\t\t\t\t 3: Delete Exsisting Product.";
    cout << "\n\n\n\t\t\t\t\t\t 4: Modify Exsisting Product.";
    cout << "\n\n\n\t\t\t\t\t\t 5:Show All Exsisting Product.";
    cout << "\n\n\n\t\t\t\t\t\t 6:Add products by category.";
    cout << "\n\n\n\t\t\t\t\t\t 7:Show products by category.";
    cout << "\n\n\n\t\t\t\t\t\t 8:delete products by category.";
    cout << "\n\n\n\t\t\t\t\t\t 9: Back to Main menu.";
    cout << "\n\n\n\t\t\t\tEnter the number of functionality which u want to choose:";
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1:
        Add();
        break;
    case 2:
        search();
        break;
    case 3:
        dlete();
        break;
    case 4:
        modify();
        break;
    case 5:
        Show();
        break;
    case 6:

        c1.addbycategory();
        break;
    case 7:
        c1.showbycategory();
        break;
    case 8:
        c1.dletebycategory();
        break;
    case 9:
        menu();
        break;
    default:
        cout << "\n\n invalid input! plzz.... try agin later" << endl;

    }
    _getch();
    goto admin;

}
void Store::Add() // Add Products Details
{

    fstream file;
    int found = 0;
    char ch;
addagain:
    system("cls");
    //variables use for check product data from file//
    string prname, cat;
    int prno, quan;
    float pric, dsc;
    int m;
    cout << "\n\n\t\t\t\t\t Enter number of Products which u want to enter..";
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        system("cls");

        cout << "\n\n\n\t\t\t\t\tEnter data of your" << i + 1 << "Product :";
        cout << "\n\n\n\t\t\t\t\tEnter the ProductNo of Product :";

        cin >> prNo;
        cin.ignore();
    name_again:
        cout << "\n\n\n\t\t\t\t\tEnter Name of Product :";
        getline(cin, prName);
        // we are not allowed user to put spaces while writing the name if user will put space we will ask him to enter name again//
        if (prName.find(" ") != -1) {
            cout << "\n\n\t\t\t\t wrong syntax";
            goto name_again;
        }
        cout << "\n\n\n\t\t\t\t\tEnter the Price of Product :";
        cin >> price;
    quantity:
        // we are not allowed user to add quantity of any single product greater than 100 while storing quantity
//if user will add quantity >100 we will ask him to enter quantity again//
        cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
        cin >> qty;
        if (qty > 100) {
            cout << "\n\n\t\t\t\t No space available... ";
            goto quantity;
        }
    discount:
        // we are not allowed user to add discount of any single product greater than 10.00 while storing Discount
 //if user will add discount >10.00 we will ask him to enter discount again//
        cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
        cin >> disc;
        if (disc > 10.00) {
            cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
            goto discount;
        }
        cin.ignore();
    categori:
        // Category check//
        cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
        getline(cin, category);

        if (category != "grocery" && category != "vegetables" && category != "clothes" && category != "fruit" && category != "bakery") {
            cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
            goto categori;
        }
        cout << "\n\n\n\t\t\t\t\tProducts are added to your store..";

        // READING DATA FROM PRODUCT FILE// 
        file.open("product.txt", ios::in);
        if (!file) {
            // WRITING DATA IN PRODUCT FILE// 
            file.open("product.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();
            // WRITING DATA IN DATA FILE// 
            file.open("dataa.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();

        }

        else {

            file >> prno >> prname >> pric >> quan >> dsc >> cat;
            while (!file.eof()) {
                // WE ARE CHECKING THAT IF THE PRODUCT DATA WHICH R U ENTERING IN FILE IS ALREADY PRESENT IN FILE THEN GIVE ERROR//
               // DONT ADD PRODUCT IN FILE// 
                if (prno == prNo) {

                    found++;


                }
                file >> prno >> prname >> pric >> quan >> dsc >> cat;
            }
            file.close();//COSING THE FILE AFTER CHECKING//
            if (found > 0) {
                cout << "\n\n\n\t\t\t already present in file";
                goto addagain;
            }
            else
            {
                file.open("product.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();
                file.open("dataa.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();
            }
        }
    }




}


void Store::search() {
    Admin admin;// Search Products Details
search_again:
    system("cls");
    int search_code, found = 0;

    cout << "\n\n\n\t\t\t\t Enter the product code of product which u want to search : ";
    cin >> search_code;
    fstream file;
    file.open("product.txt", ios::in);
    if (!file) {
        cout << "\n\n\n File not found";
    }
    else {
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    while (!file.eof()) {
        if (search_code == prNo) {

            cout << "\n\n\n\n\t\t\t\t\t\t Your Searched record of Product :";
            cout << "\n\n\t\t\t\t\t Product Code is :" << prNo;
            cout << "\n\n\t\t\t\t\t Product Name is :" << prName;
            cout << "\n\n\t\t\t\t\t Product Price is :" << price;
            cout << "\n\n\t\t\t\t\t Product Quantity is :" << qty;
            cout << "\n\n\t\t\t\t\t Discount Rate on Product  is :" << disc;
            cout << "\n\n\t\t\t\t\t Product Category is :" << category;
        }
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    _getch();
    char choic;
    cout << "\n\n\t\t Press Y if u want to search another students data other wise Press N to go back to Admin... ";
    cin >> choic;
    if (choic == 'Y') {
        goto search_again;
    }
    else {
        admin.admin();
    }

    file.close();
    if (found == 0) {
        cout << "\n\n\n\t\t\t\t\t Record not found....!!!";

    }

}

void Store::modify() // Modify Products Details
{
    system("cls");
    fstream file, file1;
    int code_for_modify;
    int founds = 0;
po:
    cout << "\nEnter Product no of Product which you want to Modify: ";
    cin >> code_for_modify;
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;

        while (!file.eof())
        {
            if (code_for_modify != prNo)
            {

                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
            }
            else
            {
                cout << "\n\n\n\n\t\t\t\t\t\t Your Searched record of Product :";
                cout << "\n\n\t\t\t\t\t Product Code is :" << prNo;
                cout << "\n\n\t\t\t\t\t Product Name is :" << prName;
                cout << "\n\n\t\t\t\t\t Product Price is :" << price;
                cout << "\n\n\t\t\t\t\t Product Quantity is :" << qty;
                cout << "\n\n\t\t\t\t\t Discount Rate on Product  is :" << disc;
                cout << "\n\n\t\t\t\t\t Product category is :" << category;
                cout << "\n\n\n\t\t\tEnter product no: ";
                cin >> prNo;
            name_againss:
                cin.ignore();
                cout << "\n\n\t\t\tEnter Name of Product :";
                getline(cin, prName);
                // we are not allowed user to put spaces while writing the name if user will put space we will ask him to enter name again//
                if (prName.find(" ") != -1) {
                    cout << "\n\n\t\t\t\t wrong syntax";
                    goto name_againss;
                }
                cout << "\n\n\t\t\tEnter Price: ";
                cin >> price;
            quantitys:
                cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
                cin >> qty;
                // quantitiy check//
                if (qty > 100) {
                    cout << "\n\n\t\t\t\t No space available... ";
                    goto quantitys;
                }
            discounts:
                cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
                cin >> disc;
                // discount check//
                if (disc > 10.00) {
                    cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
                    goto discounts;
                }
                cin.ignore();
            categori:
                // Category check//
                cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
                getline(cin, category);

                if (category != "grocery" && category != "vegetables" && category != "clothes" && category != "fruit" && category != "bakery") {
                    cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
                    goto categori;
                }
                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                founds = founds + 1;
                if (founds == 0) {
                    cout << "\n\n\n\t\t\t\t product no not found";
                }
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;


        }
        file1.close();
        file.close();
        remove("product.txt");
        rename("record.txt", "product.txt");
    }
    A();
}
void Store::A() {
    fstream file, file1;
    int code_for_modifyr=0;
    int founds = 0;
    // Now modify data from our second file.//
    file.open("dataa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\n\n\t\t\t\t Now modify second file data";
        cout << "\nEnter Product no of Product which you want to Modify: ";
        cin >> code_for_modifyr;
        file1.open("recordt.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;

        while (!file.eof())
        {
            if (code_for_modifyr != prNo)
            {
                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
            }
            else
            {
                cout << "\n\n\n\n\t\t\t\t\t\t Your Searched record of Product :";
                cout << "\n\n\t\t\t\t\t Product Code is :" << prNo;
                cout << "\n\n\t\t\t\t\t Product Name is :" << prName;
                cout << "\n\n\t\t\t\t\t Product Price is :" << price;
                cout << "\n\n\t\t\t\t\t Product Quantity is :" << qty;
                cout << "\n\n\t\t\t\t\t Discount Rate on Product  is :" << disc;
                cout << "\n\n\t\t\t\t\t Product category is :" << category;

                cout << "\n\n\n\t\t\tEnter product no: ";
                cin >> prNo;
                cin.ignore();
            name_agains:

                cout << "\n\n\t\t\tEnter Name of Product :";
                getline(cin, prName);
                if (prName.find(" ") != -1) {
                    cout << "\n\n\t\t\t\t wrong syntax";
                    goto name_agains;
                }
                cout << "\n\n\t\t\tEnter Price: ";
                cin >> price;
            quantity:
                cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
                cin >> qty;
                if (qty > 100) {
                    cout << "\n\n\t\t\t\t No space available... ";
                    goto quantity;
                }
            discount:
                cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
                cin >> disc;
                if (disc > 10.00) {
                    cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
                    goto discount;
                }
                cin.ignore();
            categoris:
                // Category check//
                cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
                getline(cin, category);

                if (category != "grocery" && category != "vegetables" && category != "clothes" && category != "fruit" && category != "bakery") {
                    cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
                    goto categoris;
                }
                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                founds = founds + 1;
                if (founds == 0) {
                    cout << "\n\n\n\t\t\t\t product no not found";
                }
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;


        }
        file1.close();
        file.close();
        remove("dataa.txt");//removing dataa file//
        rename("recordt.txt", "dataa.txt");
    }
}
void Store::dlete() // Delete Products Details
{
    system("cls");
    fstream file, file1;
    int founds = 0;
    int delete_code;
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> delete_code;
        //making new file//
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (delete_code != prNo) {
                // IN THIS THE DATA WE DONT WANT TO DELETE WILL GO TO MEW FILE //
                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
            }
            else
            {

                // AND THE DATA WHICH IS FOUND IS DELETED FROM FILE //
                founds++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (founds == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("product.txt");
        rename("record.txt", "product.txt");
    }
    //deleting data from second file..//
    int found = 0;
    file.open("dataa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t Now delete second file data";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> delete_code;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (delete_code != prNo)
                file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
            else
            {


                found++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("dataa.txt");
        rename("record.txt", "dataa.txt");
    }



}
void Store::Show() // Show Products Details
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t Show All products :";
    file.open("dataa.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t\t File not Found.";

    }
    else {
        cout << "\n\n Product number |" << setw(21) << "Product name |" << setw(21) << "Price |" << setw(21) << "quantity |" << setw(19) << "discount| " << setw(22) << "category| ";
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    while (!file.eof()) {
        //showing products in table form//
        cout << "\n\n" << setw(3) << prNo << setw(27) << prName << setw(26) << price << setw(22) << qty << setw(21) << disc << setw(21) << category;
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    file.close();

}
// CUSTOMER PANEL WORKING//

void Customer::custmenu() {
    system("cls");
    int choice;
    cout << "\n\n\n\n\t\t\t\t\t\t 1: SALE PRODUCTS.";
    cout << "\n\n\n\t\t\t\t\t\t 2: BACK.";

    cout << "\n\n\t\t\t\t\tChoose the functionality which u want to use:";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        billpage();
        break;

    case 2:
        menu();
        break;



    default:
        cout << "\n\n\t\t\t Invalid input ! plzzz try again later...";

    }
}
//global variables//
int pro_c[50], pro_q[50], c = 0;
void Customer::billpage()
{
    system("cls");
    fstream file;
    int found = 0;
    //variables which r used while sale products process and bill generating process//


//variable which will used for taking command from user also for taking user choice//
    char choice;
    char choice2;
    char choicet;

    int remove_code = 0;
    // variables which r used for calculating amount and for calclating amount after discount and total bill// 
    float amt = 0, damt = 0, total = 0;
    file.open("product.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t\t File not Exsisted";
    }
    else {
        file.close();
        list();
        cout << "\n========================================================================================================================";
        cout << "\n\n\t\t\t\t\t\t START SHOPPING PROCESS";
        cout << "\n\n========================================================================================================================";
        cout << "\n\n\t\t\t\t\t\t PLACE YOUR ORDER ";
        cout << "\n========================================================================================================================";


        file.open("product.txt", ios::in);
        // here when user will enter any variable for sale this will check that this
        //product is available in our store or not //
        do {
            bool exist = false;
            do {
                //FROM HERE WE WILL START SAIL PROCESS USER WILL INPUT PRODUCT CODE AND QUANTITY//
                pr:
                cout << "\n\n\t\t\t\t Enter product code :";
                cin >> pro_c[c];
                for (int i = 0; i < c; i++) {
                    if (pro_c[c] == pro_c[i]) {
                        cout << "exsisted";
                        _getch();
                        goto pr;
                    }
                }
                
                file.clear();//if we want to read same file more than one time bcoz some timess when
                //we want to read files more than one time and we want to read file again so we will use 
                //file.clear //

                file.seekg(0);//if we want to read file from start then we will use file.seekg(0)//
                while (!file.eof()) {
                    file >> prNo >> prName >> price >> qty >> disc >> category;
                    if (pro_c[c] == prNo) {
                        exist = true;
                        break;
                    }
                }
                if (!exist)
                    cout << "\n\n\t\t\t\tNo such product in the list. " << endl;
            } while (!exist);
        tt:
            cout << "\n\n\t\t\t\t Enter Quantity Of Product: ";
            cin >> pro_q[c];
         
            //HERE WE WILL CHECK THAT THE QUANTITY THAT USER WANTS IS SUITABLE
            //OR NOT MEANS THAT MUCH QUANTITY IS AVAILABLE IN OUR STORE OR NOT IF
            //QUANTITY U ENTER IS GREATER THAN PRESENT QUANTIY THIS WILL GIVE ERROR
            if (pro_q[c] > qty) {
                cout << "\n\n\t\t\t you enter the more quantity than the quantity which is available in store..";
                goto tt;
            }
            c++;
            //HERE IT WILL ASK U THAT IF U WANT TO BUY ANY OTHER PRODUCT OR NOT//
            cout << "\n\t If you want to buy Another Product Press Y or y otherwise press N or n or or if u want to exit press q";
            cin >> choice;
            if (choice == 'q' || choice == 'Q') {
                custmenu();
            }
        } while (choice == 'Y' || choice == 'y');
        _getch();
        system("cls");
        cout << endl;
        cout << endl;
        // BILL DISPLAY PAGE//
        cout << "\n\n======================================================BILL DETAILS======================================================";
        cout << "\n\n======================================================================================================================";
        cout << "\n\n PR.NO \t\t PR.NAME \t\t PRICE \t\t QUANTITY \t\t AMOUNT \t\t AMT AFT DISC \n";
        cout << "\n ======================================================================================================================";
        for (int i = 0; i < c; i++) {
            file.clear();
            file.seekg(0);// USE FOR READING FILE FROM START//
            file >> prNo >> prName >> price >> qty >> disc >> category;

            while (!file.eof()) //THIS MEANS READ THE DATA AND ALSO KEEP CHECKING THIS IF CONDITION UNTILL FILE DIDNT END.//
            {
                if (prNo == pro_c[i]) {
                    //HERE ALL PRODUCTS AMOUNT WILL BE CALCULATED AND THERE AMOUNT AFTER DISCOUNT AND TOTAL//
                    amt = price * pro_q[i];
                    damt = amt - (amt / 100 * disc);
                    total += damt;

                    cout << "\n" << setw(7) << pro_c[i] << setw(12) << prName << setw(22) << price << setw(22) << pro_q[i] << setw(21) << amt << setw(25) << damt << "\n";
                    cout << "\n======================================================================================================================";

                }

                file >> prNo >> prName >> price >> qty >> disc >> category;

            }

        }
        if (choice == 'N' || choice == 'n') {
        remove_again:
            // HERE WE WILL ASK USER IF HE WANT TO REMOVE ANY PRODUCT FROM BILL TELL US//
            cout << "\n\n\t\t\t\t Do you want to remove any product from bill";
            cin >> choice2;

            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                cout << "\n\t\t\t\t\t Enter the Product Code ";
                cin >> remove_code;
                // HERE OUR CODE WILL CHECK THE CODE WHICH WE ARE REMOVING IS IN BILL OR NOT//
                bool found = false;
                for (int i = 0; i < c; i++)
                    if (pro_c[i] == remove_code)
                        found = true;

                if (!found)
                    cout << "\n\t\t\t\t\tNo such item selected" << endl;

                else {

                    _getch();
                    system("cls");

                    // THIS IS THE BILL WHICH WILL DISPLAY AFTER REMOVING ALL PRODUCTS HE WANTED//
                    cout << "\n\n======================================================BILL DETAILS======================================================";
                    cout << "\n\n======================================================================================================================";
                    cout << "\n\n PR.NO \t\t PR.NAME \t\t PRICE \t\t QUANTITY \t\t AMOUNT \t\t AMT AFT DISC \n";
                    cout << "\n======================================================================================================================";
                    file.open("product.txt", ios::in);
                    file >> prNo >> prName >> price >> qty >> disc >> category;

                    total = 0;

                    for (int i = 0; i < c; i++) {

                        if (remove_code == pro_c[i])
                            pro_c[i] = -1;
                        else if (remove_code != pro_c[i] && pro_c[i] != -1) {
                            file.clear();
                            file.seekg(0);

                            while (!file.eof()) {
                                file >> prNo >> prName >> price >> qty >> disc >> category;
                                if (pro_c[i] == prNo) {
                                    break;
                                }
                            }
                            // HERE WE WILL CALCULATING NEW AMOUNT AND AMT AFTER DISCOUNT  AND TOTAL
                            //OF PRODUCTS WHICH WERE STILL IN BILL AFTER REMOVING PRODUCTS
                            amt = price * pro_q[i];
                            damt = amt - (amt / 100 * disc);
                            total += damt;
                            cout << "\n" << setw(9) << pro_c[i] << setw(12) << prName << setw(21) << price << setw(22) << pro_q[i] << setw(21) << amt << setw(25) << damt << "\n";
                            cout << "\n======================================================================================================================";
                        }
                        // 

                    }
                    cout << "\n\n\t\t\t\t\t The product you wanted to remove from bill is removed.";

                }
                // IF WE WANT TO REMOVE ANY OTHER PRODUCT FORM BILL WE WILL REMOVE AGAIN//
                goto remove_again;


            }
            else if (choice2 == 'n' || choice2 == 'N') {
            finalbill:
                system("cls");
                // THIS BILL IS FINAL BILL WHICH WE WILL GIVE TO OUR CUSTOMER AFTER
                //REMOVING PRODUCTS MORE THAN ONE PRODUCTS FROM LIST//
                cout << "\n\n\t\t\t\t\t <Your Final Bill Is Ready Sir>";
                cout << "\n\n======================================================================================================================";
                cout << "\n\n PR.NO \t\t PR.NAME \t\t PRICE \t\t QUANTITY \t\t AMOUNT \t\t AMT AFT DISC \n";
                cout << "\n======================================================================================================================";
                total = 0;

                for (int i = 0; i < c; i++) {

                    //HERE WE WILL DO THE WORK THAT THE PRODUCTS WHICH ARE NOT REMOVED FROM BILL
                    // WE WILL SHOW THOSE PRODUCTS DATA AND THIER PRICE AMOUNT DAMT AND TOTAL// 
                    if (remove_code != pro_c[i] && pro_c[i] != -1) {
                        file.clear();
                        file.seekg(0);

                        while (!file.eof()) {
                            file >> prNo >> prName >> price >> qty >> disc >> category;
                            if (pro_c[i] == prNo) {
                                break;
                            }
                        }

                        amt = price * pro_q[i];

                        damt = amt - (amt / 100 * disc);
                        total += damt;


                        cout << "\n" << setw(4) << pro_c[i] << setw(14) << prName << setw(25) << price << setw(20) << pro_q[i] << setw(22) << amt << setw(26) << damt << "\n";
                        cout << "\n======================================================================================================================";
                    }

                }
                // PAYMENT PROCESS //
                float bill;// USE FOR TAKING BILL AMOUNT FROM CUSTOMER// 
                float rem;
                if (total == 0) {
                    // IF NO AMOUNT IS BUYS BY CUSTOMER GO BACK TO MENU//
                    custmenu();
                }
                cout << "\n\n\t\t\t\t\t YOUR TOTAL BILL IS :" << total;

                cout << "\n\n\t\t\t\t\t< START PAYMENT PROCESS >";
                cout << "\n\n\t\t\t\t\t TOTAL AMOUNT YOU HAVE TO PAY IS :" << total;
            rr:
                cout << "\n\n\t\t\t\t\t PLZZ PAY THE BILL SIR :";
                cin >> bill;
                // IF YOUR PAID AMOUNT IS GREATER FROM REQUIRED AMOUNT IT WILL GIVE REMAINING AMOUNT//
                if (bill > total) {
                    rem = bill - total;
                    cout << "\n\n\t\t\t\t\t YOUR REMAINING AMOUNT :" << rem;
                    _getch();


                }
                // IF YOUR PAID AMOUNT IS LESSER THAN REQUIRED AMOUNT IT WILL GIVE EROOR//
                else if (bill < total) {
                    cout << "\n\n\t\t\t\t\t PLZZ PAY FULL AMOUNT SIR :";
                    goto rr;
                    cout << "\n\n\t\t\t\t\t THANKS FOR USING OUR SERVICES SIR";
                    _getch();

                }
                else {
                    cout << "\n\n\t\t\t\t\t THANKS FOR USING OUR SERVICES SIR";

                }
                // FROM HERE WHEN WE WILL GIVE BILL TO OUR CUSTOMER AFTER PAYMENT 
                // OUR USER WILL GO TO ADMIN PANEL FOR MODIFYING THOSE PRODUCTS QUANTITIES
                //WHICH ARE ALREADY BUYED BY CUSTOMER SO NEXT TIME UPDATED QUANTITY WILL SHOW TO USER//


                _getch();

                system("cls");

                cout << "\n\n\t\t\t\t Now go to Admin panel for modifying the quantities of products..";

                _getch();

                signins();
            }

        }
    }
}
void Admin::list() // THIS WILL SHOW ALL PRODUCTS WHICH ARE AVAILAIBLE IN OUR STORE//
{
    system("cls");
    fstream file;

    file.open("dataa.txt", ios::in);
    cout << "\n====================================================LIST OF PRODUCTS====================================================";
    cout << "\n\n========================================================================================================================";
    cout << "\n\n\t P.NO \t\t Product Name \t\t Price \t\t Quantity \t\t Category \n";
    cout << "\n========================================================================================================================";
    file >> prNo >> prName >> price >> qty >> disc >> category;

    while (!file.eof()) {

        cout << "\n" << setw(12) << prNo << setw(18) << prName << setw(22) << price << setw(20) << qty << setw(25) << category;
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    file.close();
}
void Customer::finalBill() // THIS FUNCTION WILL SHOW US FINAL BILL OF CUSTOMER//
{
    float amt = 0, damt = 0, total = 0;
    cout << "\n\n======================================================BILL DETAILS======================================================";
    cout << "\n\n======================================================================================================================";
    cout << "\n\n PR.NO \t\t PR.NAME \t\t PRICE \t\t QUANTITY \t\t AMOUNT \t\t AMT AFT DISC \n";
    cout << "\n======================================================================================================================";
    file.open("product.txt", ios::in);
    file >> prNo >> prName >> price >> qty >> disc >> category;

    total = 0;

    for (int i = 0; i < c; i++) {


        if (pro_c[i] != -1) {
            file.clear();
            file.seekg(0);

            while (!file.eof()) {
                file >> prNo >> prName >> price >> qty >> disc >> category;
                if (pro_c[i] == prNo) {
                    break;
                }
            }

            amt = price * pro_q[i];

            damt = amt - (amt / 100 * disc);
            total += damt;


            cout << "\n" << setw(9) << pro_c[i] << setw(12) << prName << setw(21) << price << setw(22) << pro_q[i] << setw(21) << amt << setw(25) << damt << "\n";
            cout << "\n======================================================================================================================";
        }
    }
}

// HERE WE WILL MODIFY QUANTITIES OF PRODUCTS WHUCH ARE BUYED BYB CUSTOMER //
                           //RECENTLY//
void Customer::billproductquan_modify() {
again_modify:
    system("cls");
    cout << "\n\n\t\t\t\t\t QUANTITY MODIFYING PAGE :";
    fstream file, file1;
    int modify_code_var;
    int founds = 0;
    char modify_another;

    file.open("dataa.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t file not found";
    }
    else {
        finalBill();

        cout << "\n\n\t\t\t\t  Enter Product no of Product which quantity you want to AModify: ";
        cin >> modify_code_var;
        file1.open("recor.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof()) {


            for (int i = 0; i < 1; i++) {


                if (modify_code_var == prNo) {




                    cout << "\n\n\t\t\t\t Now update quantities of products which user buys.";
                    //here user will modify quantities of products which user buys recently// 
                    cout << "\n\n\t\t\t\tEnter new Quantity of " << prName << " :";
                    cin >> qty;


                    // and data which is modified now this will go to new file //
                    file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                }
                // and data which we are not modifying will also go to new file //
                else if (modify_code_var != prNo) {
                    file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                }
            }

            file >> prNo >> prName >> price >> qty >> disc >> category;

        }


        file1.close();
        file.close();
        remove("dataa.txt");
        rename("recor.txt", "dataa.txt");
        billproductquan_modify2();
        cout << "\n\n\t\t\t Press y to modify another product quantity :";
        cin >> modify_another;
        if (modify_another == 'y' || modify_another == 'Y') {
            goto again_modify;
        }
        else {
            //if choice is not equal to y or Y it will redirect u to main menu//
            menu();
        }
    }

}
void Customer::billproductquan_modify2() {
again_modify:
    system("cls");
    cout << "\n\n\t\t\t\t\t QUANTITY MODIFYING PAGE :";
    fstream file, file1;
    int modify_code_var;
    int founds = 0;
    char modify_another;

    file.open("product.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t file not found";
    }
    else {
        finalBill();

        cout << "\n\n\t\t\t\t  Enter Product no of Product which quantity you want to AModify: ";
        cin >> modify_code_var;
        file1.open("product.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof()) {


            for (int i = 0; i < 1; i++) {


                if (modify_code_var == prNo) {




                    cout << "\n\n\t\t\t\t Now update quantities of products which user buys.";
                    //here user will modify quantities of products which user buys recently// 
                    cout << "\n\n\t\t\t\tEnter new Quantity of " << prName << " :";
                    cin >> qty;


                    // and data which is modified now this will go to new file //
                    file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                }
                // and data which we are not modifying will also go to new file //
                else if (modify_code_var != prNo) {
                    file1 << " " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << "\n";
                }
            }

            file >> prNo >> prName >> price >> qty >> disc >> category;

        }


        file1.close();
        file.close();
        remove("product.txt");
  

        cout << "\n\n\t\t\t Press y to modify another product quantity :";
        cin >> modify_another;
        if (modify_another == 'y' || modify_another == 'Y') {
            goto again_modify;
        }
        else {
            //if choice is not equal to y or Y it will redirect u to main menu//
            menu();
        }
    }

}
// HERE WE WILL ADD PRODUCTS DATA INTO FILE BY CATEGORY WISE//
void Categorymenu::addbycategory() {
    Admin ad_obj;
    system("cls");
    Category category_obj;
    int category_search;
    cout << "\n\n\t\t\t ADD BY CATEGORIES MENU";
    cout << "\n\n\t\t\t\t 1.Grocery.";
    cout << "\n\n\t\t\t\t 2.Clothes.";
    cout << "\n\n\t\t\t\t 3.Vegetables.";
    cout << "\n\n\t\t\t\t 4.Exit.";
    cout << "\n\n\n\t\t Now tell us which type of category products u want to choose:";
    cin >> category_search;

    switch (category_search) {
    case 1:
        category_obj.addgrocery();
        break;
    case 2:
        category_obj.addclothes();
        break;
    case 3:
        category_obj.addvegetables();
        break;
    case 4:
        ad_obj.admin();
        break;
    default:
        cout << "\n\n\t\t\t\t Invalid input";

    }
}
// ADDING PRODUCTS BY CATEGORY WISE//
void Category::addclothes() //ADD PRODUCTS TO CLOTHES CATEGORY//
{
    system("cls");



    Categorymenu cm1;
    cout << "\n\n\t\t\t\t YOU SELECTED CLOTHES CATEGORY:";
    cout << "\n\n\t\t\t\t NOW ADD PRODUCTS IN CLOTHES CATEGORY";
    fstream file;
    int found = 0;
    char ch;

    system("cls");
    string prname, cat;
    int prno, quan;
    float pric, dsc;
    int num_of_products;
    cout << "\n\n\t\t\t\t\t Enter number of Products which u want to enter..";
    cin >> num_of_products;
    cin.ignore();

    for (int i = 0; i < num_of_products; i++) {
        system("cls");
        cout << "\n\n\n\t\t\t< YOU ARE ENTERING PRODUCTS INTO CLOTHES CATEGORY > ";
        cout << "\n\n\n\t\t\t\t\tEnter data of your " << i + 1 << " Product :";
        cout << "\n\n\n\t\t\t\t\tEnter the ProductNo of Product :";

        cin >> prNo;
        cin.ignore();
    name_again:
        cout << "\n\n\n\t\t\t\t\tEnter Name of Product :";
        getline(cin, prName);
        // we are not allowed user to put spaces while writing the name if user will put space we will ask him to enter name again//
        if (prName.find(" ") != -1) {
            cout << "\n\n\t\t\t\t wrong syntax";
            goto name_again;
        }
        cout << "\n\n\n\t\t\t\t\tEnter the Price of Product :";
        cin >> price;
    quantity:
        // we are not allowed user to add quantity of any single product greater than 100 while storing quantity
        //if user will add quantity >100 we will ask him to enter quantity again//
        cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
        cin >> qty;
        if (qty > 100) {
            cout << "\n\n\t\t\t\t No space available... ";
            goto quantity;
        }
    discount:
        // we are not allowed user to add discount of any single product greater than 10.00 while storing Discount
  //if user will add discount >10.00 we will ask him to enter discount again//
        cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
        cin >> disc;
        if (disc > 10.00) {
            cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
            goto discount;
        }
        cin.ignore();
    categorid:
        // Category check//
        cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
        getline(cin, category);

        if (category != "clothes")
        {
            cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
            goto categorid;
        }
        cout << "\n\n\n\t\t\t\t\tProducts are added to your store..";


        file.open("clothes.txt", ios::in);
        if (!file) {
            file.open("dataa.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();
            file.open("clothes.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();

        }

        else {

            file >> prno >> prname >> pric >> quan >> dsc >> cat;
            while (!file.eof()) {
                if (prno == prNo) {

                    found++;


                }
                file >> prno >> prname >> pric >> quan >> dsc >> cat;;
            }
            file.close();
            if (found > 0) {
                cout << "\n\n\n\t\t\t already present in file";
                _getch();
                cm1.addbycategory();
            }
            else
            {
                file.open("dataa.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
                file.close();
                file.open("clothes.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();
                file.open("product.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();

            }
        }
    }

}
//ADDing products  TO vegetables CATEGORY//
void Category::addvegetables() {
    system("cls");
    Categorymenu cm2;
    int cate;
    cout << "\n\n\t\t\t\t\t ADD PRODUCTS BY CATEGORY PAGE";


    cout << "\n\n\t\t\t\t YOU SELECTED VEGETABLES CATEGORY.";
    cout << "\n\n\t\t\t\t NOW ADD VEGETABLES CATEGORY PRODUCTS.";
    fstream file;
    int found = 0;
    char ch;
ii:
    system("cls");
    string prname, cat;
    int prno, quan;
    float pric, dsc;
    int m;
    cout << "\n\n\t\t\t\t\t Enter number of Products which u want to enter..";
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        system("cls");
        cout << "\n\n\n\t\t\t< YOU ARE ENTERING PRODUCTS INTO VEGETABLES CATEGORY > ";
        cout << "\n\n\n\t\t\t\t\tEnter data of your " << i + 1 << " Product :";
        cout << "\n\n\n\t\t\t\t\tEnter the ProductNo of Product :";

        cin >> prNo;
        cin.ignore();
    name_again:
        cout << "\n\n\n\t\t\t\t\tEnter Name of Product :";
        getline(cin, prName);
        if (prName.find(" ") != -1) {
            cout << "\n\n\t\t\t\t wrong syntax";
            goto name_again;
        }
        cout << "\n\n\n\t\t\t\t\tEnter the Price of Product :";
        cin >> price;
    quantity:
        cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
        cin >> qty;
        if (qty > 100) {
            cout << "\n\n\t\t\t\t No space available... ";
            goto quantity;
        }
    discount:
        cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
        cin >> disc;
        if (disc > 10.00) {
            cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
            goto discount;
        }
        cin.ignore();
    categorif:
        // Category check//
        cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
        getline(cin, category);

        if (category != "vegetables") {
            cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
            goto categorif;
        }
        cout << "\n\n\n\t\t\t\t\tProducts are added to your store..";


        file.open("vegetables.txt", ios::in);
        if (!file) {
            file.open("dataa.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();
            file.open("vegetables.txt", ios::app | ios::out);
            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();

        }

        else {

            file >> prno >> prname >> pric >> quan >> dsc >> cat;
            while (!file.eof()) {
                if (prno == prNo) {

                    found++;


                }
                file >> prno >> prname >> pric >> quan >> dsc >> cat;
            }
            file.close();
            if (found > 0) {
                cout << "\n\n\n\t\t\t already present in file";
                _getch();
                cm2.addbycategory();
            }
            else
            {
                file.open("dataa.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();
                file.open("vegetables.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();
                file.open("product.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();

            }
        }
    }

}
//ADD PRODUCTS TO GROCERY CATEGORY//
void Category::addgrocery() {
    system("cls");
    Categorymenu cm3;
    int cate;
    cout << "\n\n\t\t\t\t\t ADD PRODUCTS BY CATEGORY ";


    cout << "\n\n\t\t\t\t YOU SELECTED GROCERY PRODUCTS";
    cout << "\n\n\t\t\t\t NOW ADD GROCERY PRODUCTS ";
    fstream file;
    int found = 0;
    char ch;
ii:
    system("cls");
    string prname, cat;
    int prno, quan;
    float pric, dsc;
    int m;
    cout << "\n\n\t\t\t\t\t Enter number of Products which u want to enter..";
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        system("cls");
        cout << "\n\n\n\t\t\t< YOU ARE ENTERING PRODUCTS INTO GROCERY CATEGORY > ";
        cout << "\n\n\n\t\t\t\t\tEnter data of your " << i + 1 << " Product :";
        cout << "\n\n\n\t\t\t\t\tEnter the ProductNo of Product :";

        cin >> prNo;
        cin.ignore();
    name_again:
        cout << "\n\n\n\t\t\t\t\tEnter Name of Product :";
        getline(cin, prName);
        if (prName.find(" ") != -1) {
            cout << "\n\n\t\t\t\t wrong syntax";
            goto name_again;
        }
        cout << "\n\n\n\t\t\t\t\tEnter the Price of Product :";
        cin >> price;
    quantity:
        cout << "\n\n\n\t\t\t\t\tEnter the Quantity of Product :";
        cin >> qty;
        if (qty > 100) {
            cout << "\n\n\t\t\t\t No space available... ";
            goto quantity;
        }
    discount:
        cout << "\n\n\n\t\t\t\t\tEnter the Discount percentage :";
        cin >> disc;
        if (disc > 10.00) {
            cout << "\n\n\t\t This Discount amount is not suitable plzz Enter suitable discount amount..";
            goto discount;
        }
        cin.ignore();
    categoria:
        // Category check//
        cout << "\n\n\n\t\t\t\t\tEnter category of Product :";
        getline(cin, category);

        if (category != "grocery") {
            cout << "\n\n\t\t\t\t\t THIS CATEGORY PRODUCTS ARE NOT ALLOWED IN OUR STORE ...";
            goto categoria;
        }
        cout << "\n\n\n\t\t\t\t\tProducts are added to your store..";


        file.open("grocery.txt", ios::in);
        if (!file) {
            file.open("dataa.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();
            file.open("grocery.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();
            file.open("product.txt", ios::app | ios::out);

            file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

            file.close();

        }

        else {

            file >> prno >> prname >> pric >> quan >> dsc >> cat;
            while (!file.eof()) {
                if (prno == prNo) {

                    found++;


                }
                file >> prno >> prname >> pric >> quan >> dsc >> cat;
            }
            file.close();
            if (found > 0) {
                cout << "\n\n\n\t\t\t already present in file";
                _getch();
                cm3.addbycategory();
            }
            else
            {
                file.open("dataa.txt", ios::app | ios::out);

                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
                file.close();
                file.open("grocery.txt", ios::app | ios::out);
                file << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;

                file.close();

            }
        }
    }



}
// this is the menu of show products by category//
void Categorymenu::showbycategory() {
    system("cls");
    Admin ad_objs;
    Category category_objs;
    int cate;
    cout << "\n\n\t\t\t SHOW BY CATEGORIES MENU";
    cout << "\n\n\t\t\t\t 1.SHOW GROCERY RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 2.SHOW CLOTHES RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 3.SHOW VEGETABLES RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 4.EXIT.";
    cout << "\n\n\n\t\t\t\t Now tell us which type of category products u want to choose:";
    cin >> cate;

    switch (cate) {
    case 1:
        category_objs.Showgroc();
        break;
    case 2:
        category_objs.Showclo();
        break;
    case 3:
        category_objs.Showveg();
        break;
    case 4:
        ad_objs.admin();
        break;
    default:
        cout << "\n\n\t\t\t\t Invalid input";

    }
}
// this is the menu of deleteing products according to category// 
void Categorymenu::dletebycategory()
{
    Admin ad_obj2;
    Category category_obj3;
    system("cls");
    int cate;
    cout << "\n\n\t\t\t DLETE BY CATEGORIES MENU";
    cout << "\n\n\t\t\t\t 1.DLETE GROCERY RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 2.DLETE CLOTHES RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 3.DLETE VEGETABLES RELATED PRODUCTS.";
    cout << "\n\n\t\t\t\t 4.EXIT.";
    cout << "\n\n\n\t\t\t\t NOW TELL US WHICH CATEGORY PRODUCTS YO WANT TO DELETE :";
    cin >> cate;

    switch (cate) {
    case 1:
        category_obj3.dletegroc();
        break;
    case 2:
        category_obj3.dleteclo();
        break;
    case 3:
        category_obj3.dleteveg();
        break;
    case 4:
        ad_obj2.admin();
        break;
    default:
        cout << "\n\n\t\t\t\t Invalid input";

    }
}
// START DELETING PRODUCTS CATEGORY WISE//
void Category::Showclo() // Show Clothes category product//
{
    system("cls");
    cout << "\n\n\t\t\t\t SHOW PRODUCTS OF CLOTHES CATEGORY";
    fstream file;
    cout << "\n\n\t\t\t Show All products :";
    file.open("clothes.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t\t File not Found.";

    }
    else {
        cout << setw(19) << "\n\n\t Product number |" << setw(24) << "Product name |" << setw(23) << "Price |" << setw(22) << "quantity |" << setw(22) << "discount| ";
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    while (!file.eof()) {
        cout << "\n\n" << setw(16) << prNo << setw(27) << prName << setw(24) << price << setw(22) << qty << setw(21) << disc;
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    file.close();

}
void Category::Showveg() //Show Vegetables category product//
{
    system("cls");
    cout << "\n\n\t\t\t\t SHOW PRODUCTS OF VEGETABLES CATEGORY";
    fstream file;
    cout << "\n\n\t\t\t Show All products :";
    file.open("vegetables.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t\t File not Found.";

    }
    else {
        cout << setw(19) << "\n\n\t Product number |" << setw(24) << "Product name |" << setw(23) << "Price |" << setw(22) << "quantity |" << setw(22) << "discount| ";
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    while (!file.eof()) {
        cout << "\n\n" << setw(16) << prNo << setw(27) << prName << setw(24) << price << setw(22) << qty << setw(21) << disc;
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    file.close();

}
void Category::Showgroc() //Show Grocery category product//
{

    system("cls");
    cout << "\n\n\t\t\t\t SHOW PRODUCTS OF GROCERY CATEGORY";
    fstream file;
    cout << "\n\n\t\t\t Show All products :";
    file.open("grocery.txt", ios::in);
    if (!file) {
        cout << "\n\n\t\t\t\t File not Found.";

    }
    else {
        cout << setw(19) << "\n\n\t Product number |" << setw(24) << "Product name |" << setw(23) << "Price |" << setw(22) << "quantity |" << setw(22) << "discount| ";
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    while (!file.eof()) {
        cout << "\n\n" << setw(16) << prNo << setw(27) << prName << setw(24) << price << setw(22) << qty << setw(21) << disc;
        file >> prNo >> prName >> price >> qty >> disc >> category;
    }
    file.close();

}

// START DELETING PRODUCTS CATEGORY WISE// 
void Category::dletegroc() //delete Grocery category product//
{
    system("cls");
    fstream file, file1;
    int founds = 0;
    int codesss;
    file.open("grocery.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t NOW YOU ARE DELETING GROCERY PRODUCTS.";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo) {

                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            }
            else
            {


                founds++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (founds == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("grocery.txt");
        rename("record.txt", "grocery.txt");
    }
    int found = 0;
    file.open("dataa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t Now delete second file data";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo)
                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            else
            {


                found++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("dataa.txt");
        rename("record.txt", "dataa.txt");
    }



}
void Category::dleteclo() //delete Clothes category product//
{
    system("cls");
    fstream file, file1;
    int founds = 0;
    int codesss;
    file.open("clothes.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t NOW YOU ARE DELETING CLOTHES PRODUCTS.";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo) {

                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            }
            else
            {


                founds++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (founds == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("clothes.txt");
        rename("record.txt", "clothes.txt");
    }
    int found = 0;
    file.open("dataa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t Now delete second file data";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo)
                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            else
            {


                found++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("dataa.txt");
        rename("record.txt", "dataa.txt");
    }



}
void Category::dleteveg() //delete Vegetables category product//
{
    system("cls");
    fstream file, file1;
    int founds = 0;
    int codesss;
    file.open("vegetables.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t NOW YOU ARE DELETING VEGETABLES PRODUCTS.";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo) {

                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            }
            else
            {


                founds++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (founds == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("vegetables.txt");
        rename("record.txt", "vegetables.txt");
    }
    int found = 0;
    file.open("dataa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();

    }
    else

    {
        cout << "\n\n\t\t\t\t Now delete second file data";
        cout << "\n\n\n\t\t\t\t Enter Product no of Product which you want to Delete: ";
        cin >> codesss;
        file1.open("record.txt", ios::app | ios::out);
        file >> prNo >> prName >> price >> qty >> disc >> category;
        while (!file.eof())
        {
            if (codesss != prNo)
                file1 << "     " << prNo << " " << prName << " " << price << " " << qty << " " << disc << " " << category << endl;
            else
            {


                found++;
                cout << "\n\n\t\t\t\t\t Record Sucessfully Deleted...";
            }
            file >> prNo >> prName >> price >> qty >> disc >> category;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Product No. Not Found....";
        }

        file1.close();
        file.close();
        remove("dataa.txt");
        rename("record.txt", "dataa.txt");
    }



}
int main()
{
    Admin s1;
    s1.menu();
    s1.admin();

    system("pause");
}
