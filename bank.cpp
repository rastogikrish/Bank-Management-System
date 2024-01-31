
// HEADER FILES USED 
#include<windows.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std; 

class account
{
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int acno;
    char name[50];
    int deposit;
    char type;

public:
	
    void create_account();     // get data from user
    void show_account() const; //  show data on screen
    void modify();             //  add new data
    void dep(int);             //  accept amount and add to balance amount
    void draw(int);            //  accept amount and subtract from balance amount
    void report() const;       //  show data in tabular format
    int retacno() const;       //  return account number
    int retdeposit() const;    //  return balance amount
    char rettype() const;      //  return type of account
    
    
    void bgrecolor_red(){ 
    
        // Set the background color to Red and the text color to white
        SetConsoleTextAttribute(hConsole, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    void bgrecolor_green(){ 
    
        // Set the background color to Green and the text color to white
        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    void bgrecolor_normal(){
        
        // Set the background color to normal and the text color to white
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    void fgrecolor_blue(){
        
        // Set the background color to blue and the text color to white
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    void fgrecolor_green(){
        
        // Set the background color to blue and the text color to white
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    }
    void fgrecolor_rblue(){
        
        // Set the background color to blue and the text color to white
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_BLUE);
    }
    void fgrecolor_yellow(){
        
        // Set the background color to blue and the text color to white
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN);
    }
};                              

void account::create_account()
{
	fgrecolor_green();
    cout << "\n\n\tEnter the Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\tEnter type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\tEnter the Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin >> deposit;
    cout << "\n\n\n\tAccount Created..";
}

void account::show_account() const
{
    cout << "\n\tAccount No. : " << acno;
    cout << "\n\tAccount Holder Name : ";
    cout << name;
    cout << "\n\tType of Account : " << type;
    cout << "\n\tBalance amount : " << deposit;
}

void account::modify()
{
	fgrecolor_rblue();
    cout << "\n\tAccount No. : " << acno;
    cout << "\n\tModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\tModify Balance amount : ";
    cin >> deposit;
}

void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

void account::report() const
{
    cout <<"\t"<< acno << setw(10) << " " << name << setw(8) << " " << type << setw(10) << deposit << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}
 
//      function declaration 
void write_account();            // write record in binary file
void display_sp(int);            // display account details given by user
void modify_account(int);        // modify record of file
void delete_account(int);        // delete record of file
void display_all();              // display all account details
void deposit_withdraw(int, int); // desposit/withdraw amount for given account
void intro();                    // introductory screen function
  
void resize(){
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);

    // Change the console window size
    MoveWindow(console, rect.left, rect.top, 800, 600, TRUE);
}
int main()
{
    account obj;
    resize(); 
    char ch;
    int num; 
        	string aid;
        	int psd;
    do
    {
        system("cls");  
        obj.fgrecolor_blue();
        cout << "\n\t\tMAIN MENU\n";
        cout << "\n\t|\t1. NEW ACCOUNT";
        cout << "\n\t|\t2. DEPOSIT AMOUNT";
        cout << "\n\t|\t3. WITHDRAW AMOUNT";
        cout << "\n\t|\t4. BALANCE ENQUIRY";
        cout << "\n\t|\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t|\t6. CLOSE AN ACCOUNT";
        cout << "\n\t|\t7. MODIFY AN ACCOUNT";
        cout << "\n\t|\t8. EXIT\n";
        cout << "\n\t\tSelect Your Option (1-8) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
        	cout << "\n\t|\t NEW ACCOUNT\n";
            write_account();
            break;
        case '2':
        	cout << "\n\t|\t DEPOSIT AMOUNT\n";
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
        	cout << "\n\t|\t WITHDRAW AMOUNT";
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
        	cout << "\n\t|\t BALANCE ENQUIRY";
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            display_sp(num);
            break;
        case '5':
        	cout<<"\n\tEnter admin Id : ";
        	cin>>aid;
        	cout<<"\n\tEnter admin Password : ";
        	cin>>psd;
        	if(psd == 1028 && aid == "bank"){
        		system("cls");
	 			display_all();
			}
			else{
				main();
			}
            break;
        case '6':
        	cout << "\n\t|\t CLOSE AN ACCOUNT";
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':
        	
        	cout << "\n\t|\t MODIFY AN ACCOUNT";
        	obj.fgrecolor_rblue();
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\t ";
            obj.bgrecolor_green();
			cout << "Thanks for using bank managemnt system";
			obj.fgrecolor_blue();
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}
 
//       write in file 

void write_account()
{
	int acno;
    account ac;
    ofstream outFile;
    outFile.open("account.txt", ios::binary | ios::app); 
    ac.fgrecolor_green();
    cout << "\n\tEnter the account No. : ";
    cin >> acno;
    fstream File;
    
    File.open("account.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
    	ac.bgrecolor_red();
        cout << "File could not be open !! Try again later !! Press any Key...";
        ac.fgrecolor_green();
        return;
    }
    bool found = false;
    while (!File.eof() && found == false)
    {
    	
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == acno)
        { 
            found = true;
        }
    }
    if (found == true){ 
    	cout<< "\n\t";  
        cout << "Account already exists !"; 
        write_account();
    }
    
    File.close();
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}
 
//       read specific record from file 

void display_sp(int n)
{
    account ac;
    ac.fgrecolor_green();
    bool flag = false;
    ifstream inFile;
    inFile.open("account.txt", ios::binary);
    if (!inFile)
    {
    	ac.bgrecolor_red();
        cout << "File could not open !! Press any Key...";
        ac.fgrecolor_green();
        return;
    }
    cout << "\n\tBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false){
    	ac.bgrecolor_red();
        cout << "\n\nAccount number does not exist";
        ac.fgrecolor_green();
	}
}
 
//       modify record of file 

void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    ac.fgrecolor_rblue();
    File.open("account.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
    	ac.bgrecolor_red();
        cout << "File could not be open !! Press any Key...";
        ac.fgrecolor_rblue();
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\n\tEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            ac.bgrecolor_green();
            cout << "\n\n\t Record Updated";
            ac.fgrecolor_rblue();
            found = true;
        }
    }
    File.close();
    if (found == false){
    	ac.bgrecolor_red();
        cout << "\n\nRecord Not Found ";
        ac.fgrecolor_rblue();
	}
}
 
//       delete record of file 

void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.txt", ios::binary);
    if (!inFile)
    {
		ac.bgrecolor_red();
        cout << "File could not be open !! Press any Key...";
        ac.fgrecolor_rblue();
        return;
    }
    outFile.open("Temp.txt", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.txt");
    rename("Temp.txt", "account.txt");
    ac.bgrecolor_green();
    cout << "\n\n\tRecord Deleted ..";
    ac.fgrecolor_rblue();
}
 
//       display all accounts deposit list 

void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.txt", ios::binary);
    if (!inFile)
    {
    	ac.bgrecolor_red();
        cout << "File could not be open !! Press any Key...";
        ac.fgrecolor_rblue();
        return;
    }
    ac.fgrecolor_rblue();
    cout << "\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
    cout << "\t====================================================\n";
    cout << "\tA/c no.      NAME \t\tType  Balance\n";
    cout << "\t====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}
 
//deposit and withdraw amounts 

void deposit_withdraw(int n, int option)
{
	account obj; 
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
    	obj.bgrecolor_red();
        cout << "File could not be open !! Press any Key...";
        obj.fgrecolor_yellow();
        return;
    }
    while (!File.eof() && found == false)
    {
    	
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
        	
        	obj.fgrecolor_yellow();
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSITE AMOUNT ";
                cout << "\n\n\tEnter the amount to be deposited : \t";
                cin >> amt;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\n\tEnter the amount to be withdraw : \t";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C')){
                	obj.bgrecolor_red(); 
				    cout << "Insufficience balance"; 
				    obj.fgrecolor_yellow();
                }
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            obj.bgrecolor_green();
            cout << "\n\n\t Record Updated";
            obj.fgrecolor_yellow();
            found = true;
        }
    }
    File.close();
    if (found == false){
    	cout<<"\n\n \t";
    	obj.bgrecolor_red();
        cout << "Record Not Found ";
        obj.fgrecolor_yellow();
    }
}
  
