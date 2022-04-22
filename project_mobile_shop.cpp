#include <iostream>
#include <fstream>
using namespace std;
enum OS
{
    IOS = 1,
    Android = 2,
    windows_phone = 3
};
enum Ram
{
    _2gb = 2,
    _4gb = 4,
    _6gb = 6,
    _8gb = 8,
    _12gb = 12,
    _16gb = 16,
    _32gb = 32,
    _64gb = 64
};
enum Storage
{
    s16gb = 16,
    s32gb = 32,
    s64gb = 64,
    s128gb = 128,
    s256gb = 256,
    s512gb = 512,
    s1tb = 1024,
    s2tb = 2048
};
enum Color
{
    golden = 1,
    gray = 2,
    black = 3,
    white = 4,
    silver = 5
};
struct mobile
{
    string name;
    string factory;
    OS os;
    Ram ram;
    Storage storage;
    Color color;
    long long int price;
    int number_available = 0;
    int number_sold = 0;
};
void add_phone(mobile *&, int &);
mobile *add_phone(mobile *, int, int);
mobile getinfo(mobile);
void remove_phone(mobile *&, int &, int);
void sort_by_price(mobile *&, int);
void readfile(mobile *&, int &);
void fout(mobile *, int);
int search(string, string, mobile *, int);
void change_mobile_info(mobile *&, int, string, string);
void changeinfo(mobile &, int);
void sell_a_phone(mobile *&, int, string, string);
void print_phones(mobile *, int);
void most_sold_item(mobile *, int);
void increase(mobile *&, int &);
int main()
{
    ofstream file("mobiles.txt", ios::app);
    if (file)
    {
        cout << "\nfile oppened successfully\n";
        file.close();
    }
    else
    {
        cout << "\nfile did not oppen\n";
    }
    mobile *mobiles = new mobile[0];
    int n = 0;
    readfile(mobiles, n);
    remove_phone(mobiles, n, n - 1);
    int list = 0;
    while (list != 9)
    {
        system("cls");
        cout << "1-Add a phone\n2-Remove a phone\n3-Sort phones by price\n4-search a phone\n5-Change mobile info\n6-Sell a phone\n7-Print phones\n8-Print phones sorted by the most sold to the least\n9-Quit\n(1/2/3/4/5/6/7/8/9): ";
        cin >> list;
        if (list == 1)
        {

            system("cls");
            string name, factory;
            cout << "name:";
            cin >> name;
            cout << "factory:";
            cin >> factory;
            int test = 0;
            for (int i = 0; i <= n; i++)
            {
                if (name == mobiles[i].name && factory == mobiles[i].factory)
                {
                    cout << "How many?";
                    int tedadnew;
                    cin >> tedadnew;
                    mobiles = add_phone(mobiles, i, tedadnew);
                    test++;
                }
            }
            if (test == 0)
            {

                add_phone(mobiles, n);
                mobiles[n - 1].name = name;
                mobiles[n - 1].factory = factory;
            }
            fout(mobiles, n);
            cout << "Done now ";
            system("pause");
        }
        else if (list == 2)
        {
            system("cls");

            if (n == 0)
            {
                cerr << "there is no mobile in shop\n";
            }
            else
            {
                string name, factory;
                cout << "name:";
                cin >> name;
                cout << "factory:";
                cin >> factory;
                int test2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (name == mobiles[i].name && factory == mobiles[i].factory)
                    {
                        test2++;
                        remove_phone(mobiles, n, i);
                    }
                }
                if (test2 == 0)
                {
                    cerr << "there is no mobile phone with this information\n";
                }
            }
            fout(mobiles, n);
            cout << "Now ";
            system("pause");
        }
        else if (list == 3)
        {
            system("cls");
            sort_by_price(mobiles, n);
            fout(mobiles, n);
            cout << "Done now ";
            system("pause");
        }
        else if (list == 4)
        {
            system("cls");
            string name, factory;
            cout << "name:";
            cin >> name;
            cout << "factory:";
            cin >> factory;
            int index = search(name, factory, mobiles, n);
            if (index == -1)
            {
                cout << "there is no mobile phone with this information.\n";
            }
            else
            {
                cout << "OS:";
                switch (mobiles[index].os)
                {
                case 1:
                    cout << "IOS";
                    break;
                case 2:
                    cout << "Android";
                    break;
                default:
                    cout << "Windows phone";
                    break;
                }
                cout << "\nRam:" << mobiles[index].ram << "\nStorage:" << mobiles[index].storage << "\nprice:" << mobiles[index].price << "\ncolor:";
                switch (mobiles[index].color)
                {
                case 1:
                    cout << "golden";
                    break;
                case 2:
                    cout << "gray";
                    break;
                case 3:
                    cout << "black";
                    break;
                case 4:
                    cout << "white";
                    break;
                case 5:
                    cout << "silver";
                    break;
                }
                cout << "\nnumber of availables:" << mobiles[index].number_available << "\nnumber of sold:" << mobiles[index].number_sold << "\n";
            }
            system("pause");
        }
        else if (list == 5)
        {
            system("cls");
            string name, factory;
            cout << "name:";
            cin >> name;
            cout << "factory:";
            cin >> factory;
            change_mobile_info(mobiles, n, name, factory);
            fout(mobiles, n);
            cout << "\nnow ";
            system("pause");
        }
        else if (list == 6)
        {
            system("cls");
            string name, factory;
            cout << "name:";
            cin >> name;
            cout << "factory:";
            cin >> factory;
            sell_a_phone(mobiles, n, name, factory);
            fout(mobiles, n);
            cout << "now ";
            system("pause");
        }
        else if (list == 7)
        {
            system("cls");
            print_phones(mobiles, n);
            system("pause");
        }
        else if (list == 8)
        {
            system("cls");
            mobile *komaki = new mobile[n];
            for (int i = 0; i < n; i++)
            {
                komaki[i] = mobiles[i];
            }
            most_sold_item(komaki, n);
            delete[] komaki;
            system("pause");
        }
        else
        {
            if (list != 9)
            {
                cerr << "\nwrong number .Now ";
                system("pause");
            }
        }
    }

    delete[] mobiles;
    system("pause");
    return 0;
}
void add_phone(mobile *&mobiles, int &n)
{
    mobile *komaki = new mobile[n + 1];
    for (int i = 0; i < n; i++)
    {
        komaki[i] = mobiles[i];
    }
    delete[] mobiles;
    mobiles = new mobile[n + 1];
    for (int i = 0; i < n; i++)
    {
        mobiles[i] = komaki[i];
    }
    delete[] komaki;
    mobiles[n] = getinfo(mobiles[n]);
    n++;
}
mobile *add_phone(mobile *mobiles, int i, int tedadnew)
{
    mobiles[i].number_available = mobiles[i].number_available + tedadnew;
    return mobiles;
}
mobile getinfo(mobile mobile)
{
    cout << "\nOS:\n1)ios\n2)android\n3)windows phone\n(1/2/3):";
    int list;
    cin >> list;
    mobile.os = (OS)list;
    cout << "Ram(2/4/6/8/12/16/32/64):";
    cin >> list;
    mobile.ram = (Ram)list;
    cout << "storage(16/32/64/128/256/512/1024(1TB)/2048(2TB):";
    cin >> list;
    mobile.storage = (Storage)list;
    cout << "price:";
    cin >> mobile.price;
    cout << "color:\n1)Golden\n2)Gray\n3)Black\n4)White\n5)Silver\n?";
    cin >> list;
    mobile.color = (Color)list;
    cout << "number of availables:";
    cin >> mobile.number_available;
    cout << "number of sold:";
    cin >> mobile.number_sold;
    return mobile;
}
void remove_phone(mobile *&mobiles, int &n, int i)
{
    mobile *komaki = new mobile[n - 1];
    for (int j = 0; j < i; j++)
    {
        komaki[j] = mobiles[j];
    }
    for (int j = i + 1; j < n; j++)
    {
        komaki[j - 1] = mobiles[j];
    }
    delete[] mobiles;
    mobiles = new mobile[n - 1];
    n--;
    for (int i = 0; i < n; i++)
    {
        mobiles[i] = komaki[i];
    }
    delete[] komaki;
}
void sort_by_price(mobile *&mobiles, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mobiles[j].price < mobiles[j + 1].price)
            {
                mobile x = mobiles[j + 1];
                mobiles[j + 1] = mobiles[j];
                mobiles[j] = x;
            }
        }
    }
}
void fout(mobile *mobiles, int n)
{
    ofstream ofile("mobiles.txt", ios::trunc);
    if (ofile)
    {
        for (int i = 0; i < n; i++)
        {
            ofile << mobiles[i].name << '\t' << mobiles[i].factory << '\t';
            ofile << "OS: ";
            if (mobiles[i].os == 1)
            {
                ofile << "IOS\t";
            }
            else if (mobiles[i].os == 2)
            {
                ofile << "Android\t";
            }
            else
            {
                ofile << "Windows_phone\t";
            }
            ofile << "Ram: " << mobiles[i].ram << '\t';
            ofile << "Storage: " << mobiles[i].storage << '\t';
            ofile << "Price: " << mobiles[i].price << '\t';
            ofile << "color: ";
            if (mobiles[i].color == 1)
            {
                ofile << "golden\t";
            }
            else if (mobiles[i].color == 2)
            {
                ofile << "gray\t";
            }
            else if (mobiles[i].color == 3)
            {
                ofile << "black\t";
            }
            else if (mobiles[i].color == 4)
            {
                ofile << "white\t";
            }
            else if (mobiles[i].color == 5)
            {
                ofile << "silver\t";
            }
            ofile << "available: " << mobiles[i].number_available << '\t';
            ofile << "sold: " << mobiles[i].number_sold << '\n';
        }
        ofile.close();
    }
    else
    {
        cerr << "\nthe file couldn`t find! ...\n";
    }
}
void readfile(mobile *&mobiles, int &n)
{
    string nothing;
    ifstream fin("mobiles.txt", ios::in);
    if (fin)
    {
        while (fin)
        {
            increase(mobiles, n);
            fin >> mobiles[n - 1].name >> mobiles[n - 1].factory >> nothing >> nothing;
            if (nothing == "IOS")
            {
                mobiles[n - 1].os = OS::IOS;
            }
            else if (nothing == "Android")
            {
                mobiles[n - 1].os = OS::Android;
            }
            else
            {
                mobiles[n - 1].os = OS::windows_phone;
            }
            int ram;
            fin >> nothing >> ram;
            switch (ram)
            {
            case 2:
                mobiles[n - 1].ram = Ram::_2gb;
                break;
            case 4:
                mobiles[n - 1].ram = Ram::_4gb;
                break;
            case 6:
                mobiles[n - 1].ram = Ram::_6gb;
                break;
            case 8:
                mobiles[n - 1].ram = Ram::_8gb;
                break;
            case 12:
                mobiles[n - 1].ram = Ram::_12gb;
                break;
            case 16:
                mobiles[n - 1].ram = Ram::_16gb;
                break;
            case 32:
                mobiles[n - 1].ram = Ram::_32gb;
                break;
            case 64:
                mobiles[n - 1].ram = Ram::_64gb;
                break;
            }
            int storage;
            fin >> nothing >> storage;
            switch (storage)
            {
            case 16:
                mobiles[n - 1].storage = Storage::s16gb;
                break;
            case 32:
                mobiles[n - 1].storage = Storage::s32gb;
                break;
            case 64:
                mobiles[n - 1].storage = Storage::s64gb;
                break;
            case 128:
                mobiles[n - 1].storage = Storage::s128gb;
                break;
            case 256:
                mobiles[n - 1].storage = Storage::s256gb;
                break;
            case 512:
                mobiles[n - 1].storage = Storage::s512gb;
                break;
            case 1024:
                mobiles[n - 1].storage = Storage::s1tb;
                break;
            case 2048:
                mobiles[n - 1].storage = Storage::s2tb;
                break;
            }
            fin >> nothing >> mobiles[n - 1].price >> nothing >> nothing;
            if (nothing == "golden")
            {
                mobiles[n - 1].color = Color::golden;
            }
            else if (nothing == "black")
            {
                mobiles[n - 1].color = Color::black;
            }
            else if (nothing == "silver")
            {
                mobiles[n - 1].color = Color::silver;
            }
            else if (nothing == "gray")
            {
                mobiles[n - 1].color = Color::gray;
            }
            else
            {
                mobiles[n - 1].color = Color::white;
            }
            fin >> nothing >> mobiles[n - 1].number_available >> nothing >> mobiles[n - 1].number_sold;
        }
        fin.close();
    }
    else
    {
        cerr << "\nthe file couldn`t find! ...\n";
    }
}
int search(string name, string factory, mobile *mobiles, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (name == mobiles[i].name && factory == mobiles[i].factory)
            return i;
    }
    return -1;
}
void change_mobile_info(mobile *&mobiles, int n, string name, string factory)
{
    int test = 0;
    for (int i = 0; i < n; i++)
    {
        if (name == mobiles[i].name && factory == mobiles[i].factory)
        {
            test++;
            cout << "1-OS\n2-Ram\n3-Storage\n4-Price\n5-color\n6-number of availables\n7-number of sold\nwhich one do you want to change?";
            int list;
            cin >> list;
            changeinfo(mobiles[i], list);
        }
    }
    if (test == 0)
    {
        cout << "there is no mobile phone with this information\n";
    }
}
void changeinfo(mobile &mobile, int list)
{
    int list2;
    system("cls");
    switch (list)
    {
    case 1:
        cout << "1)ios\n2)android\n3)windows phone\n(1/2/3):";
        cin >> list2;
        mobile.os = (OS)list2;
        break;
    case 2:
        cout << "Ram(2/4/6/8/12/16/32/64):";
        cin >> list2;
        mobile.ram = (Ram)list2;
        break;
    case 3:
        cout << "storage(16/32/64/128/256/512/1024(1TB)/2048(2TB):";
        cin >> list2;
        mobile.storage = (Storage)list2;
        break;
    case 4:
        cout << "new price:";
        cin >> mobile.price;
        break;
    case 5:
        cout << "color:\n1)Golden\n2)Gray\n3)Black\n4)White\n5)Silver\n?";
        cin >> list2;
        mobile.color = (Color)list2;
        break;
    case 6:
        cout << "new number of availables:";
        cin >> mobile.number_available;
        break;
    case 7:
        cout << "new number of sold:";
        cin >> mobile.number_sold;
        break;
    }
}
void sell_a_phone(mobile *&mobiles, int n, string name, string factory)
{
    int test = 0;
    for (int i = 0; i < n; i++)
    {
        if (name == mobiles[i].name && factory == mobiles[i].factory)
        {
            mobiles[i].number_available--;
            mobiles[i].number_sold++;
            test++;
        }
    }
    if (test == 0)
    {
        cerr << "there is no mobile phone with this information\n";
    }
}
void print_phones(mobile *mobiles, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << mobiles[i].name << '\n'
             << mobiles[i].factory << '\n';
        cout << "OS:";
        if (mobiles[i].os == 1)
        {
            cout << "IOS\n";
        }
        else if (mobiles[i].os == 2)
        {
            cout << "Android\n";
        }
        else
        {
            cout << "Windows_phone\n";
        }
        cout << "Ram:" << mobiles[i].ram;
        cout << "\nStorage: " << mobiles[i].storage;
        cout << "\nPrice: " << mobiles[i].price;
        cout << "\ncolor: ";
        if (mobiles[i].color == 1)
        {
            cout << "golden";
        }
        else if (mobiles[i].color == 2)
        {
            cout << "gray";
        }
        else if (mobiles[i].color == 3)
        {
            cout << "black";
        }
        else if (mobiles[i].color == 4)
        {
            cout << "white";
        }
        else if (mobiles[i].color == 5)
        {
            cout << "silver";
        }
        cout << "\navailable: " << mobiles[i].number_available;
        cout << "\nsold: " << mobiles[i].number_sold << "\n\n";
    }
}
void most_sold_item(mobile *mobiles, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mobiles[j].number_sold < mobiles[j + 1].number_sold)
            {
                mobile x = mobiles[j + 1];
                mobiles[j + 1] = mobiles[j];
                mobiles[j] = x;
            }
        }
    }

    print_phones(mobiles, n);
}
void increase(mobile *&mobiles, int &n)
{
    mobile *komaki = new mobile[n + 1];
    for (int i = 0; i < n; i++)
    {
        komaki[i] = mobiles[i];
    }
    delete[] mobiles;
    mobiles = new mobile[n + 1];
    for (int i = 0; i < n; i++)
    {
        mobiles[i] = komaki[i];
    }
    n++;
}