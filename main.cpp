#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#include <fstream>

using namespace std;

COORD coord = {0, 0};
void gotoxy(int x, int y)
{

    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class student
{
private:
    string first_name, last_name, father_name, clss, section, dob, address, email_id, contact, roll_no;

public:
    void menu();
    void insert();
    void display();
    void search();
    void update();
    void deletedata();
};

class teachers
{
    string teacher_first_name, teacher_last_name, age, teacher_address, teacher_email, teacher_contact;

public:
    void teacher_menu();
    void insert_teacher_record();
    void display_teacher_record();
    void search_teacher_record();
    void update_teacher_record();
    void delete_teacher_record();
};

student s;
teachers t;

void intro()
{
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t             ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t          WELCOME ADMIN, PLEASE LOG IN TO PROCEED          " << endl;
}

void loading()
{
    gotoxy(30, 12);
    int i;
    for (i = 1; i <= 5; i++)
    {
        cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
        Sleep(100);
    }
    Sleep(500);
    cout << endl
         << endl;
    gotoxy(30, 14);
}

void li_success()
{
    system("cls");
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t             ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\n\n\t\t\t                    Log In Successful!" << endl;
    loading();
}
//ADMIN LOGIN
void login()
{
    system("cls");

    string username = "";
    string password = "";
    char retry, ch;
    int i = 0;
    intro();

    cout << "\n\t\t\t                          LOG IN                         " << endl;
    cout << "\n\t\t\t                     Username : ";
    cin >> username;
    cout << "\n\t\t\t                     Password : ";

    ch = getch();
    while (ch != 13)
    {

        if (ch == '\b')
        {
            if (password.size() > 0)
            {
                password.erase(password.begin() + password.size() - 1);
                cout << "\b \b";
                i--;
            }
            ch = getch();
        }
        else
        {
            if (i < 10)
            {
                password.push_back(ch);
                cout << "*";
                ch = getch();
                i++;
            }
            else
            {
                ch = getch();
            }
        }
    }

    if (username == "admin" && password == "n1234")
    {
        li_success();
        return;
    }
    else
    {
        system("cls");
        cout << "\n\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t             ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\n\n\t\t\t                Wrong Username or Password !! ";
        cout << "\n\n\t\t\t    Press 'R' or 'r' to Retry OR any other key to exit...\n\n";
        cin >> retry;
        if (retry == 'r' || retry == 'R')
        {
            system("cls");
            login();
        }
        else
        {
            exit(0);
        }
    }
}
//ADMIN MAIN MENU
void main_menu()
{
    system("cls");
    int choice;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t              ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\n\t\t\t                 1. Students Portal" << endl;
    cout << "\n\t\t\t                 2. Teachers Portal" << endl;
    cout << "\n\t\t\t                 3. Exit" << endl;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t               Choose Option : [ 1 | 2 | 3 ]               " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\n\t\t\t       Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        s.menu();
        break;
    case 2:
        t.teacher_menu();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\t\t\t   Invalid Choice. Please Try Again...!! ";
    }
}

void back_to_admin_panel()
{
    system("cls");
    main_menu();
}

//STUDENTS MENU SECTION
void student::menu()
{
menustart:
    system("cls");
    int choice;
    char x;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t              ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                       STUDENTS MENU                       " << endl;
    cout << "\t\t\t                   ---------------------                   " << endl;
    cout << "\n\t\t\t                 1. Create New Record" << endl;
    cout << "\n\t\t\t                 2. Display Record" << endl;
    cout << "\n\t\t\t                 3. Search Record" << endl;
    cout << "\n\t\t\t                 4. Update Record" << endl;
    cout << "\n\t\t\t                 5. Delete Record" << endl;
    cout << "\n\t\t\t                 6. Back to Main Menu " << endl;
    cout << "\n\t\t\t                 7. Exit" << endl;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t       Choose Option : [ 1 | 2 | 3 | 4 | 5 | 6 |7 ]        " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\n\t\t\t       Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t           Add Another Student Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        do
        {
            search();
            cout << "\n\t\t\t           Search Another Student Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 4:
        do
        {
            update();
            cout << "\n\t\t\t          Uppdate Another Student Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 5:
        do
        {
            deletedata();
            cout << "\n\t\t\t           Delete Another Student Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 6:
        back_to_admin_panel();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t   Invalid Choice. Please Try Again...!! ";
    }
    getch();
    goto menustart;
}

void student::insert()
{
    system("cls");
    fstream file;
    char x;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                 ||  CREATE NEW RECORD  ||                 " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    cout << "\n\t\t\t First Name                 : ";
    cin >> first_name;
    cout << "\n\t\t\t Last Name                  : ";
    cin >> last_name;
    cout << "\n\t\t\t Father's Name              : ";
    cin.get();
    getline(cin, father_name);
    cout << "\n\t\t\t Roll No                    : ";
    cin >> roll_no;
    cout << "\n\t\t\t Class                      : ";
    cin >> clss;
    cout << "\n\t\t\t Section                    : ";
    cin >> section;
    cout << "\n\t\t\t Date of Birth [dd.mm.yyyy] : ";
    cin >> dob;
    cout << "\n\t\t\t Address                    : ";
    cin >> address;
    cout << "\n\t\t\t E-Mail ID                  : ";
    cin >> email_id;
    cout << "\n\t\t\t Contact No.                : ";
    cin >> contact;

    file.open("student.txt", ios::app | ios::out);
    file << first_name << endl;
    file << last_name << endl;
    file << father_name << endl;
    file << roll_no << endl;
    file << clss << endl;
    file << section << endl;
    file << dob << endl;
    file << address << endl;
    file << email_id << endl;
    file << contact << endl;

    file.close();

    cout << "\n\t\t\t                  New Record Created !";
}

void student::display()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                  ||  STUDENTS RECORD  ||                  " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!";
        file.close();
    }
    else
    {
        file >> first_name;
        file >> last_name;
        file.ignore();
        getline(file, father_name);
        file >> roll_no;
        file >> clss;
        file >> section;
        file >> dob;
        file >> address;
        file >> email_id;
        file >> contact;
        while (!file.eof())
        {
            cout << "\n\t\t    Sl.No. : " << total++ << endl;
            cout << "\n\t\t\t First Name                 : " << first_name << endl;
            cout << "\n\t\t\t Last Name                  : " << last_name << endl;
            cout << "\n\t\t\t Father's Name              : " << father_name << endl;
            cout << "\n\t\t\t Roll No                    : " << roll_no << endl;
            cout << "\n\t\t\t Class                      : " << clss << endl;
            cout << "\n\t\t\t Section                    : " << section << endl;
            cout << "\n\t\t\t Date of Birth [dd.mm.yyyy] : " << dob << endl;
            cout << "\n\t\t\t Address                    : " << address << endl;
            cout << "\n\t\t\t E-Mail ID                  : " << email_id << endl;
            cout << "\n\t\t\t Contact No.                : " << contact << endl;
            file >> first_name;
            file >> last_name;
            file.ignore();
            getline(file, father_name);
            file >> roll_no;
            file >> clss;
            file >> section;
            file >> dob;
            file >> address;
            file >> email_id;
            file >> contact;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t No Record Found...!";
        }
    }
    file.close();
}

void student::search()
{
    system("cls");
    fstream file;
    char x;
    int found = 0;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!" << endl;
    }
    else
    {
        string rollno;
        cout << "\n\t\t\t                Enter Roll No. to Search : ";
        cin >> rollno;
        file >> first_name;
        file >> last_name;
        file.ignore();
        getline(file, father_name);
        file >> roll_no;
        file >> clss;
        file >> section;
        file >> dob;
        file >> address;
        file >> email_id;
        file >> contact;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                system("cls");
                cout << "\n\t\t\t-----------------------------------------------------------" << endl;
                cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
                cout << "\t\t\t-----------------------------------------------------------" << endl;
                cout << "\n\t\t\t First Name                 : " << first_name << endl;
                cout << "\n\t\t\t Last Name                  : " << last_name << endl;
                cout << "\n\t\t\t Father's Name              : " << father_name << endl;
                cout << "\n\t\t\t Roll No                    : " << roll_no << endl;
                cout << "\n\t\t\t Class                      : " << clss << endl;
                cout << "\n\t\t\t Section                    : " << section << endl;
                cout << "\n\t\t\t Date of Birth [dd.mm.yyyy] : " << dob << endl;
                cout << "\n\t\t\t Address                    : " << address << endl;
                cout << "\n\t\t\t E-Mail ID                  : " << email_id << endl;
                cout << "\n\t\t\t Contact No.                : " << contact << endl;
                found++;
            }
            file >> first_name;
            file >> last_name;
            file.ignore();
            getline(file, father_name);
            file >> roll_no;
            file >> clss;
            file >> section;
            file >> dob;
            file >> address;
            file >> email_id;
            file >> contact;
        }
        if (found == 0)
        {
            system("cls");
            cout << "\n\t\t\t-----------------------------------------------------------" << endl;
            cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
            cout << "\t\t\t-----------------------------------------------------------" << endl;
            cout << "\n\t\t\t                     Record Not Found...!!" << endl;
        }
        file.close();
    }
}

void student::update()
{
    system("cls");
    fstream file, file1;
    char x;
    int found = 0;
    string rollno;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  UPDATE RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t Enter Roll No. to Update : ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> first_name;
        file >> last_name;
        file.ignore();
        getline(file, father_name);
        file >> roll_no;
        file >> clss;
        file >> section;
        file >> dob;
        file >> address;
        file >> email_id;
        file >> contact;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << first_name << endl;
                file1 << last_name << endl;
                file1 << father_name << endl;
                file1 << roll_no << endl;
                file1 << clss << endl;
                file1 << section << endl;
                file1 << dob << endl;
                file1 << address << endl;
                file1 << email_id << endl;
                file1 << contact << endl;
            }
            else
            {
                cout << "\n\t\t\t First Name                 : ";
                cin >> first_name;
                cout << "\n\t\t\t Last Name                  : ";
                cin >> last_name;
                cout << "\n\t\t\t Father's Name              : ";
                cin.get();
                getline(cin, father_name);
                cout << "\n\t\t\t Roll No                    : ";
                cin >> roll_no;
                cout << "\n\t\t\t Class                      : ";
                cin >> clss;
                cout << "\n\t\t\t Section                    : ";
                cin >> section;
                cout << "\n\t\t\t Date of Birth [dd.mm.yyyy] : ";
                cin >> dob;
                cout << "\n\t\t\t Address                    : ";
                cin >> address;
                cout << "\n\t\t\t E-Mail ID                  : ";
                cin >> email_id;
                cout << "\n\t\t\t Contact No.                : ";
                cin >> contact;

                file1 << first_name << endl;
                file1 << last_name << endl;
                file1 << father_name << endl;
                file1 << roll_no << endl;
                file1 << clss << endl;
                file1 << section << endl;
                file1 << dob << endl;
                file1 << address << endl;
                file1 << email_id << endl;
                file1 << contact << endl;

                cout << "\n\t\t\t Record Updated...!";
                found++;
            }
            file >> first_name;
            file >> last_name;
            file.ignore();
            getline(file, father_name);
            file >> roll_no;
            file >> clss;
            file >> section;
            file >> dob;
            file >> address;
            file >> email_id;
            file >> contact;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Record Not Found...!!";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("record.txt", "student.txt");
    }
}

void student::deletedata()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    char x;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  DELETE RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!" << endl;
    }
    else
    {
        cout << "\n\t\t\t Enter Roll No. to Delete : ";
        cin >> rollno;

        file1.open("record.txt", ios::app | ios::out);
        file >> first_name;
        file >> last_name;
        file.ignore();
        getline(file, father_name);
        file >> roll_no;
        file >> clss;
        file >> section;
        file >> dob;
        file >> address;
        file >> email_id;
        file >> contact;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << first_name << endl;
                file1 << last_name << endl;
                file1 << father_name << endl;
                file1 << roll_no << endl;
                file1 << clss << endl;
                file1 << section << endl;
                file1 << dob << endl;
                file1 << address << endl;
                file1 << email_id << endl;
                file1 << contact << endl;
            }
            else
            {
                cout << "\n\t\t\t Record Deleted...!";
                found++;
            }
            file >> first_name;
            file >> last_name;
            file.ignore();
            getline(file, father_name);
            file >> roll_no;
            file >> clss;
            file >> section;
            file >> dob;
            file >> address;
            file >> email_id;
            file >> contact;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t                     Record not found...!!" << endl;
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("record.txt", "student.txt");
    }
}

//Teachers Infromation Section
void teachers::teacher_menu()
{
menustart:
    system("cls");
    int choice;
    char x;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t             ||  SCHOOL MANAGEMENT SYSTEM  ||             " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                       TEACHERS MENU                       " << endl;
    cout << "\t\t\t                   ---------------------                   " << endl;
    cout << "\n\t\t\t                 1. Create New Record" << endl;
    cout << "\n\t\t\t                 2. Display Record" << endl;
    cout << "\n\t\t\t                 3. Search Record" << endl;
    cout << "\n\t\t\t                 4. Update Record" << endl;
    cout << "\n\t\t\t                 5. Delete Record" << endl;
    cout << "\n\t\t\t                 6. Back to Main Menu " << endl;
    cout << "\n\t\t\t                 6. Exit" << endl;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t       Choose Option : [ 1 | 2 | 3 | 4 | 5 | 6 |7 ]        " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\n\t\t\t       Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert_teacher_record();
            cout
                << "\n\t\t\t           Add Another Teacher Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display_teacher_record();
        break;
    case 3:
        do
        {
            search_teacher_record();
            cout << "\n\t\t\t           Search Another Teacher Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 4:
        do
        {
            update_teacher_record();
            cout << "\n\t\t\t          Uppdate Another Teacher Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 5:
        do
        {
            delete_teacher_record();
            cout << "\n\t\t\t           Delete Another Teacher Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 6:
        back_to_admin_panel();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t   Invalid Choice. Please Try Again...!! ";
    }
    getch();
    goto menustart;
}

void teachers::insert_teacher_record()
{
    system("cls");
    fstream file;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                 ||  CREATE NEW RECORD  ||                 " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    cout << "\n\t\t\tFirst Name  : ";
    cin >> teacher_first_name;
    cout << "\n\t\t\tLast Name   : ";
    cin >> teacher_last_name;
    cout << "\n\t\t\tAge         : ";
    cin >> age;
    cout << "\n\t\t\tAddress     : ";
    cin >> teacher_address;
    cout << "\n\t\t\tE-Mail ID   : ";
    cin >> teacher_email;
    cout << "\n\t\t\tContact No. : ";
    cin >> teacher_contact;

    file.open("teacherRecord.txt", ios::app | ios::out);
    file << " " << teacher_first_name << " " << teacher_last_name << " " << age << " " << teacher_address << " " << teacher_email << " " << teacher_contact << " "
         << "\n";
    file.close();
}

void teachers::display_teacher_record()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                  ||  TEACHERS RECORD  ||                  " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("teacherRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!";
        file.close();
    }
    else
    {
        file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        while (!file.eof())
        {
            cout << "\n\t\t    Sl.No. : " << total++ << endl;
            cout << "\t\t\t           First Name  : " << teacher_first_name << endl;
            cout << "\t\t\t           Last Name   : " << teacher_last_name << endl;
            cout << "\t\t\t           Age         : " << age << endl;
            cout << "\t\t\t           Address     : " << teacher_address << endl;
            cout << "\t\t\t           E-Mail ID   : " << teacher_email << endl;
            cout << "\t\t\t           Contact No. : " << teacher_contact << endl;
            file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t No Record Found...!";
        }
    }
    file.close();
}

void teachers::search_teacher_record()
{
    system("cls");
    fstream file;
    char x;
    int found = 0;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    file.open("teacherRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!" << endl;
    }
    else
    {
        string first_name;
        cout << "\n\t\t\t                Enter First Name to Search : ";
        cin >> first_name;
        file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        while (!file.eof())
        {
            if (first_name == teacher_first_name)
            {
                system("cls");
                cout << "\n\t\t\t-----------------------------------------------------------" << endl;
                cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
                cout << "\t\t\t-----------------------------------------------------------" << endl;
                cout << "\t\t\t           First Name  : " << teacher_first_name << endl;
                cout << "\t\t\t           Last Name   : " << teacher_last_name << endl;
                cout << "\t\t\t           Age         : " << age << endl;
                cout << "\t\t\t           Address     : " << teacher_address << endl;
                cout << "\t\t\t           E-Mail ID   : " << teacher_email << endl;
                cout << "\t\t\t           Contact No. : " << teacher_contact << endl;
                found++;
            }
            file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        }
        if (found == 0)
        {
            system("cls");
            cout << "\n\t\t\t-----------------------------------------------------------" << endl;
            cout << "\t\t\t                   ||  SEARCH RECORD  ||                   " << endl;
            cout << "\t\t\t-----------------------------------------------------------" << endl;
            cout << "\n\t\t\t                     Record Not Found...!!" << endl;
        }
        file.close();
    }
}

void teachers::update_teacher_record()
{
    system("cls");
    fstream file, file1;
    char x;
    int found = 0;
    string first_name;
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  UPDATE RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("teacherRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t Enter First Name to Update : ";
        cin >> first_name;
        file1.open("Record.txt", ios::app | ios::out);
        file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        while (!file.eof())
        {
            if (first_name != teacher_first_name)
            {
                file1 << " " << teacher_first_name << " " << teacher_last_name << " " << age << " " << teacher_address << " " << teacher_email << " " << teacher_contact << " "
                      << "\n";
            }
            else
            {
                cout << "\n\t\t\tFirst Name  : ";
                cin >> teacher_first_name;
                cout << "\n\t\t\tLast Name   : ";
                cin >> teacher_last_name;
                cout << "\n\t\t\tAge         : ";
                cin >> age;
                cout << "\n\t\t\tAddress     : ";
                cin >> teacher_address;
                cout << "\n\t\t\tE-Mail ID   : ";
                cin >> teacher_email;
                cout << "\n\t\t\tContact No. : ";
                cin >> teacher_contact;
                file1 << " " << teacher_first_name << " " << teacher_last_name << " " << age << " " << teacher_address << " " << teacher_email << " " << teacher_contact << " "
                      << "\n";
                cout << "\n\t\t\t Record Updated...!";
                found++;
            }
            file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Record Not Found...!!";
        }
        file1.close();
        file.close();
        remove("teacherRecord.txt");
        rename("record.txt", "teacherRecord.txt");
    }
}

void teachers::delete_teacher_record()
{
    system("cls");
    fstream file, file1;
    string first_name;
    int found = 0;
    char x;

    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t                   ||  DELETE RECORD  ||                   " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;

    file.open("teacherRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Record Found...!" << endl;
    }
    else
    {
        cout << "\n\t\t\t Enter First Name to Delete : ";
        cin >> first_name;

        file1.open("Record.txt", ios::app | ios::out);
        file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        while (!file.eof())
        {
            if (first_name != teacher_first_name)
            {
                file1 << " " << teacher_first_name << " " << teacher_last_name << " " << age << " " << teacher_address << " " << teacher_email << " " << teacher_contact << " "
                      << "\n";
            }
            else
            {
                cout << "\n\t\t\t Record Deleted...!";
                found++;
            }
            file >> teacher_first_name >> teacher_last_name >> age >> teacher_address >> teacher_email >> teacher_contact;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t                     Record not found...!!" << endl;
        }
        file1.close();
        file.close();
        remove("teacherRecord.txt");
        rename("record.txt", "teacherRecord.txt");
    }
}

main()
{

    login();
    while (true)
    {
        main_menu();
    }
    getch();
    return 0;
}

