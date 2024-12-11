#include<iostream>
#include<string>
using namespace std;

struct BankAccount 
{
    string name;
    string address;
    char accountType;
    float balance;
    bool accountExists;
};

void open_account(BankAccount&account) 
{
    if (account.accountExists)
	 {
        cout<<"Account already exists"<<endl;
        return;
    }

    cout<<"Enter your full name: "<<endl;
    cin.ignore(); 
    getline(cin, account.name);
    cout <<"Enter your full address: "<<endl;
    getline(cin,account.address);

    do
	 {
        cout<<"What type of account you want to open (saving (s) or current (c)): "<<endl;
        cin>>account.accountType;
        
        if (account.accountType != 's' && account.accountType != 'c') {
            cout<<"Invalid account type.Please enter 's' for saving or 'c' for current."<<endl;
        }
    } 
	
	while (account.accountType!='s'&&account.accountType !='c');

    cout<< "Enter amount for deposit: "<<endl;
    cin>>account.balance;
    while (account.balance<0) 
	{
        cout<< "Deposit amount cannot be negative. Please enter a valid amount: "<<endl;
        cin>>account.balance;
    }
    account.accountExists=true;
    cout<<"Your account is created."<<endl;
}

void deposit_money(BankAccount& account) 
{
    if (!account.accountExists)
	 {
        cout<<"No account found. Please open an account first."<<endl;
        return;
    }

    float amount;
    cout << "Enter how much you want to deposit:"<<endl;
    cin>>amount;
    while (amount < 0) 
	{
        cout<<"Deposit amount cannot be negative. Please enter a valid amount: "<<endl;
        cin>>amount;
    }
    account.balance += amount;
    cout<<"Total amount you deposited: "<<account.balance<<endl;
}


void withdraw_money(BankAccount& account)
 {
    if (!account.accountExists) 
	{
        cout<<"No account found. Please open an account first."<<endl;
        return;
    }

    float amount;
    cout << "Enter amount to withdraw:"<<endl;
    cin>>amount;
    if (amount > account.balance) 
	{
        cout<<"Insufficient balance."<<endl;
    } else 
	{
        account.balance-=amount;
        cout<<"Now, total amount left: "<<account.balance<<endl;
    }
}

void display_account(const BankAccount& account)
 {
    if (!account.accountExists) 
	{
        cout<<"No account found."<<endl;
        return;
    }

    cout<<"Your full name: "<<account.name<<endl;
    cout<<"Your address: "<< account.address<<endl;
    cout<<"Type of account: "<<account.accountType<<endl;
    cout<<"Amount you deposited: "<<account.balance<<endl;
}

void update_account(BankAccount& account)
 {
    if (!account.accountExists) 
	{
        cout<<"No account found. Please open an account first."<<endl;
        return;
    }

    int choice;
    cout << "Which detail would you like to update?\n"<<endl;
    cout << "1) Update Address\n"<<endl;
    cout << "2) Update Account Type\n"<<endl;
    cout << "Enter your choice:"<<endl;
    cin >> choice;

    switch (choice) 
	{
        case 1:
            cout<<"Enter new address: "<<endl;
            cin.ignore(); 
            getline(cin, account.address);
            cout<<"Address updated successfully."<<endl;
            break;
        case 2:
            do {
                cout<<"Enter new account type (saving (s) or current (c)):"<<endl;
                cin>>account.accountType;
                if (account.accountType != 's' && account.accountType != 'c') 
				{
                    cout<<"Invalid account type. Please enter 's' for saving or 'c' for current."<<endl;
                }
            }
			 while (account.accountType != 's' && account.accountType != 'c');
            cout<<"Account type updated successfully."<<endl;
            break;
        default:
            cout<<"Invalid choice."<<endl;
    }
}


void delete_account(BankAccount& account) 
{
    if (!account.accountExists) 
	{
        cout<<"No account found to delete."<<endl;
        return;
    }

    account.name.clear();
    account.address.clear();
    account.accountType = '\0';
    account.balance = 0.0;
    account.accountExists=false;
    cout<<"Account deleted successfully."<<endl;
}

int main() 
{
    cout<<"\n\n\t\t\t\t***BANK MANAGEMENT SYSTEM***\n"<<endl;
    string username = "hacker", u;
    string pass = "123";  
    string p;

    while (true) 
	{
        cout<<"Enter Username: "<<endl;
        cin>>u;
        cout<<"Enter Password: "<<endl;
        cin>>p;

        if (username == u && pass == p)
		 {
            cout<<"\nLogin Successfully\n"<<endl;
            break;
        } 
		else 
		{
        cout<<"Invalid Username or Password. Please try again.\n"<<endl;
        }
    }

    BankAccount bankAccount = {"", "", '\0', 0.0, false};  

    int choice;
    char continueChoice;

    do 
	{
        cout<<"\n1) Open account"<<endl;
        cout<<"2) Deposit money"<<endl;
        cout<<"3) Withdraw money"<<endl;
        cout<<"4) Display account"<<endl;
        cout<<"5) Update account"<<endl;
        cout<<"6) Delete account"<<endl;
        cout<<"7) Exit"<<endl;
        cout<<"Select the option from above:";
        while (!(cin >> choice)) 
		{
            cout<<"Invalid input. Please enter a valid option:"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }

        switch (choice)
		 {
            case 1:
                open_account(bankAccount);
                break;
            case 2:
                deposit_money(bankAccount);
                break;
            case 3:
                withdraw_money(bankAccount);
                break;
            case 4:
                display_account(bankAccount);
                break;
            case 5:
                update_account(bankAccount);
                break;
            case 6:
                delete_account(bankAccount);
                break;
            case 7:
                cout<<"Thank you for using the Bank Management System. Exiting program."<<endl;
                return 0;
            default:
                cout<<"This option does not exist, please try again."<<endl;
        }

        cout<<"If you want to select another option, press 'Y'. If you want to exit, press 'N':"<<endl;
        cin>>continueChoice;
    } while (continueChoice == 'Y'||continueChoice == 'y');

    return 0;
}
