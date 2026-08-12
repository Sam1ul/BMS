#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<ctime>
#include<windows.h>

using namespace std;

class log 
{
struct password
{
    char passcode[30];
};
public:
void design()
{  
system("color f0");
cout<<"\n\n\n\n\n";
 cout<<"\t\t\t    ____  __  __  _____ "<<endl;
 cout<<"\t\t\t   |  _ \\|  \\/  |/ ____|"<<endl;
 cout<<"\t\t\t   | |_) | \\  / | (___  "<<endl;
 cout<<"\t\t\t   |  _ <| |\\/| |\\___ \\ "<<endl;
 cout<<"\t\t\t   | |_) | |  | |____) |"<<endl;
 cout<<"\t\t\t   |____/|_|  |_|_____/ "<<endl;
cout<<"                                    Money Bank Ltd."<<endl;                   
                      


    system("pause>0");
}
void createPassword()
{
    system("color 2");
    password uno;
    
    ofstream fileA("password.dat",ios::binary|ios::out);
    cout<<"\n                         New Password:";
    int p=0;
    do{
        uno.passcode[p]=getch();
        if(uno.passcode[p]!='\r'){
            cout<<"*";
        }
        p++;
    }while(uno.passcode[p-1]!='\r');
    uno.passcode[p-1]='\0';
    

    fileA.write((char*)&uno,sizeof(uno));
    fileA.close();
}
void login()
{
    int verify=0;
    do
    {
    system("cls");
    system("color f0");
    password uno;
    ifstream fileA("password.dat",ios::binary|ios::in);
    
    char key[30];
    
        system("cls");
    cout<<"\n\t\t\t           \n";
    cout<<"\t\t\t  ________________________\n";
	cout<<"\t\t\t   BANK MANAGEMENT SYSTEM ";
	cout<<"\n\t\t\t        _____________ \n";
    cout<<"\n\n\n\n\n\n\t\t\tEnter System Password:";
    int p=0;
    do{
        key[p]=getch();
        if(key[p]!='\r'){
            cout<<"*";
        }
        p++;
    }while(key[p-1]!='\r');
    key[p-1]='\0';
    
    while(fileA.read((char*)&uno,sizeof(uno)))
    {
       int s=strcmp(key,uno.passcode);
       if(s==0)
       {
        verify=1;
        system("color A0");
        cout<<"\n\n\n\t\t\t\tAccess Granted"<<endl;
        cout<<"\t\tDo you want to create a new password?(y/n):";
        char c;
        cin.get(c);
        cin.ignore();
        if(c=='y')
        {
            createPassword();
            cout<<"\n\n                            New password created.........."<<endl;
            system("pause>0");
    
        }
       }
       else if(s!=0)
       {
        system("color C0");
        cout<<"\n\n\n\t\t\t\tWrong Password"<<endl;
        system("pause>0");
       }
    }
    fileA.close();
    
    }while(verify!=1);
}
void readpassword()
{
    password uno;
    ifstream fileA("password.dat",ios::binary|ios::in);
    fileA.read((char*)&uno,sizeof(uno));
    cout<<uno.passcode<<endl;
    fileA.close();
}
};
class Business : public log
{
struct Count
{
    int number=1;
};
struct Client
{
    int id;
    char name[30];
    char adress[30];
    char actype[30];
    char client_password[30];
    int vote=0;
    double money;
    char status;
    
};
struct SUD
{
    double ssud;
};
public:

void employeeOftheYear()
{
    system("color f0");
    system("vote.exe");
}

void lomod()
{
    cout<<"\n BORROWER INFORMATION MODIFICATION"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Loan no.:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("laccount.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"REASON"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                
                cout<<"\nName: ";cin.get(person.name,30);cin.ignore();
                cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
                
                cout<<"Password: ";
                int b=0;
                do{
                    person.client_password[b]=getch();
                    if(person.client_password[b]!='\r'){
                        cout<<"*";
                    }
                    b++;
                }while(person.client_password[b-1]!='\r');
                person.client_password[b-1]='\0';
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n\n\nAccount is modified successfully. . . ."<<endl;

                ofstream fileAL("llog.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": Loan no. "<<search<<"'s information was modified."<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}

void lodel()
{
    system("cls");
    system("color f0");
    cout<<"\n LOAN CANCEL"<<endl;
    cout<<"___________________________________________________"<<endl;
    
        int search;
       
        cout<<"Enter Loan no.:";cin>>search;cin.ignore();
        

       Client person;
       fstream fbin("laccount.dat",ios::binary|ios::in);       
       fstream fbd("ltemp.dat",ios::binary|ios::out);
       
        while(fbin.read((char*)&person,sizeof(person)))
        { 
            
             
            if((person.id!=search))
            {
                fbd.write((char*)&person,sizeof(person));
                 
                
            }
        }
        fbd.close();
        fbin.close();

        remove("laccount.dat");
        rename("ltemp.dat","laccount.dat");
        cout<<"\n\n\nLoan is cancelled successfully . . . ."<<endl;

        ofstream fileAL("llog.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Loan no. "<<search<<" was cancelled."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();  
}

void loallAccount()
{
    cout<<"\n ALL ACCOUNT HOLDER LIST"<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    Client person;
    ifstream fileB("laccount.dat",ios::binary|ios::in);
    
    if(!fileB)
    {
        cout<<"Error in file opening"<<endl;
    }
    else
    {
        cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(17)<<"REASON"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        while (fileB.read((char*)&person,sizeof(person)))
        {
            cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(17)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
        }
        fileB.close();
    }
}
void lobalance()
{
    cout<<"\n CURRENT LOAN CHECK"<<endl;
    cout<<"___________________________________________________"<<endl;
    char client_key[30];
    int search;
    bool flag=0;
    
    cout<<"Enter Loan no.:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    Client person;
    ifstream fileB("laccount.dat",ios::binary|ios::in);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    {
        while(fileB.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<"\n\n\n\n\t\t\tLoan no.: "<<person.id<<endl;
                cout<<"\t\t\tBorrower Name: "<<person.name<<endl;
                cout<<"\t\t\tAdress: "<<person.adress<<endl;
                cout<<"\t\t\tReason: "<<person.actype<<endl;
                cout<<"\t\t\tMore to pay: "<<person.money<<" taka";
                flag=1;

            }
        }
        if(flag==0)
        {
            cout<<"\n\nNot found"<<endl;
        }
        
    }
}

void lodepo()
{
    cout<<"\n PAY INSTALLMENT"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter loan no.:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("laccount.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(17)<<"REASON"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(17)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                int deposit;
                cout<<"\nInstallment amount(BDT): ";cin>>deposit;cin.ignore();
                person.money=person.money-deposit;
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n"<<deposit<<" taka is installed successfully. . . ."<<endl;

                ofstream fileAL("llog.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": "<<deposit<<" taka was installed to loan no. "<<person.id<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}
void locreateNewAccount()
{
    cout<<"\n NEW LOAN"<<endl;
    cout<<"___________________________________________________"<<endl;
    int count;
    Count s;

    ifstream fila("lcounter.dat",ios::binary|ios::in);    
    fila.read((char*)&s,sizeof(s));
    count=s.number;
    fila.close();

    ofstream filb("lcounter.dat",ios::binary|ios::out);
    s.number=count+1;
    filb.write((char*)&s,sizeof(s));
    filb.close();

    Client person;
    ofstream fileB("laccount.dat",ios::binary|ios::app);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    {
        person.status='B'; 
        person.id=count;cin.ignore();
        cout<<"Name: ";cin.get(person.name,30);cin.ignore();
        cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
        cout<<"Reason: ";cin.get(person.actype,30);cin.ignore();
        cout<<"Password: ";
        int b=0;
        do{
            person.client_password[b]=getch();
            if(person.client_password[b]!='\r'){
                cout<<"*";
            }
            b++;
        }while(person.client_password[b-1]!='\r');
        person.client_password[b-1]='\0';
        cout<<"\nEnter loan amount(BDT): ";cin>>person.money;cin.ignore();
        fileB.write((char*)&person,sizeof(person));
        fileB.close();
        cout<<"\n\n\nLoan no. "<<count<<" has given successfully . . . . ."<<endl;


        ofstream fileAL("llog.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Loan no. "<<count<<" was given."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();


    }
    
}

void loPortal()
{
    char ch;
	do
	{
	system("cls");
    system("color f0");
	cout<<"\n";
	cout<<"\t\t|||||||||| BANK MANAGEMENT SYSTEM ||||||||||"<<endl;
        cout<<"\n\t\t\t      LOAN MANAGEMENT";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\t 1. CREATE NEW LOAN";
		cout<<"\n\t\t\t 2. PAY INSTALLMENT";
		cout<<"\n\t\t\t 3. CURRENT LOAN ENQUIRY";
		cout<<"\n\t\t\t 4. ALL LOAN LIST";
		cout<<"\n\t\t\t 5. LOAN CANCEL";
		cout<<"\n\t\t\t 6. BORROWER'S INFORMATION MODIFICATION";
        cout<<"\n\t\t\t 7. ACTIVITY LOG";
		cout<<"\n\t\t\t 8. BACK";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			system("cls");
            login();
            system("cls");
            locreateNewAccount();
			break;
		case '2':
			system("cls");
			lodepo();
			break;
		case '3':
			system("cls");
            lobalance();
			break;
		case '4':
            system("cls");
            loallAccount();
			break;
		case '5':
			system("cls");
            login();
            lodel();
			break;
		 case '6':
            system("cls");
            lomod();
			break;
            case '7':
            system("cls");
            login();
            system("cls");
            system("color B");
            cout<<"\n ACTIVITY LOG"<<endl;
            cout<<"___________________________________________________"<<endl;
            system("type llog.txt");
			break;
		 case '8':
		 	system("CLS");
			break;
		}
        cin.ignore();
        cout<<"\n\n\n\t\t\tPress Enter to Continue. . . . . ."<<endl;
		cin.get();
    }while(ch!='8');
}


void empmod()
{
    cout<<"\n EMPLOYEE MODIFICATION"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Employee ID:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("eaccount.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"DESIGNATION"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                
                cout<<"\nName: ";cin.get(person.name,30);cin.ignore();
                cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
                
                cout<<"Password: ";
                int b=0;
                do{
                    person.client_password[b]=getch();
                    if(person.client_password[b]!='\r'){
                        cout<<"*";
                    }
                    b++;
                }while(person.client_password[b-1]!='\r');
                person.client_password[b-1]='\0';
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n\n\n Modification successful. . . ."<<endl;

                ofstream fileAL("elog.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": Employee ID "<<search<<" was modified."<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}

void empdel()
{
    system("cls");
    system("color f0");
    cout<<"\n FIRING"<<endl;
    cout<<"___________________________________________________"<<endl;
    
        int search;
       
        cout<<"Enter Employee ID:";cin>>search;cin.ignore();
        

       Client person;
       fstream fbin("eaccount.dat",ios::binary|ios::in);       
       fstream fbd("etemp.dat",ios::binary|ios::out);
       
        while(fbin.read((char*)&person,sizeof(person)))
        { 
            
             
            if((person.id!=search))
            {
                fbd.write((char*)&person,sizeof(person));
                 
                
            }
        }
        fbd.close();
        fbin.close();

        remove("eaccount.dat");
        rename("etemp.dat","eaccount.dat");
        cout<<"\n\n\nAccount is closed successfully . . . ."<<endl;

        ofstream fileAL("elog.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Emplouyee ID "<<search<<" was fired."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();  
}
void empallAccount()
{
    cout<<"\n ALL ACCOUNT HOLDER LIST"<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    Client person;
    ifstream fileB("eaccount.dat",ios::binary|ios::in);
    
    if(!fileB)
    {
        cout<<"Error in file opening"<<endl;
    }
    else
    {
        cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(17)<<"DESIGNATION"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        while (fileB.read((char*)&person,sizeof(person)))
        {
            cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(17)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
        }
        fileB.close();
    }
}
void empbalance()
{
    cout<<"\n BALENCE CHECK"<<endl;
    cout<<"___________________________________________________"<<endl;
    char client_key[30];
    int search;
    bool flag=0;
    
    cout<<"Enter Employee ID:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    Client person;
    ifstream fileB("eaccount.dat",ios::binary|ios::in);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    {
        while(fileB.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<"\n\n\n\n\t\t\tEmployee ID: "<<person.id<<endl;
                cout<<"\t\t\tEmployer's Name: "<<person.name<<endl;
                cout<<"\t\t\tAdress: "<<person.adress<<endl;
                cout<<"\t\t\tDesignation: "<<person.actype<<endl;
                cout<<"\t\t\tTotal Balance: "<<person.money<<" taka";
                
                flag=1;

            }
        }
        if(flag==0)
        {
            cout<<"\n\nNot found"<<endl;
        }
        
    }
}

void empwithdr()
{
    cout<<"\n WITHDRAW"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Employee ID:";cin>>search;cin.ignore();
    cout<<"Enter Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("eaccount.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(17)<<"DESIGNATION"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(17)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                int withdraw;
                cout<<"\nWithdraw amount(BDT): ";cin>>withdraw;cin.ignore();
                if(withdraw>person.money)
                {
                    cout<<"insufficient balance. . . . ."<<endl;
                }
                else
                {
                    person.money=person.money-withdraw;
                    int pos=(-1)*sizeof(person);
                    fbin.seekp(pos,ios::cur);
                    fbin.write((char*)&person,sizeof(person));
                    cout<<"\n\n"<<withdraw<<" taka is withdrawn successfully. . . ."<<endl;

                    ofstream fileAL("elog.txt",ios::app);
                    time_t now = time(0);
                    char* dt=ctime(&now);
                    fileAL<<"\n---------------------------------------------------"<<endl;
                    fileAL<<dt<<": "<<withdraw<<" taka was withdrawn from account ID "<<person.id<<endl;
                    fileAL<<"---------------------------------------------------"<<endl;
                    fileAL.close();
                }
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}

void empdepo()
{
    cout<<"\n DEPOSIT"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    int search;
    
    cout<<"Enter Employee ID:";cin>>search;cin.ignore();
    
    
    
    Client person;
    fstream fbin("eaccount.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            
            if(person.id==search)
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(17)<<"DESIGNATION"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(17)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                int deposit;
                cout<<"\nDeposit Salary(BDT): ";cin>>deposit;cin.ignore();
                person.money=person.money+deposit;
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n"<<deposit<<" taka is deposited successfully. . . ."<<endl;

                ofstream fileAL("elog.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": "<<deposit<<" taka was deposited to account ID "<<person.id<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}
void empcreateNewAccount()
{
    cout<<"\n NEW EMPLOYEE"<<endl;
    cout<<"___________________________________________________"<<endl;
    int count;
    Count s;

    ifstream fila("ecounter.dat",ios::binary|ios::in);    
    fila.read((char*)&s,sizeof(s));
    count=s.number;
    fila.close();

    ofstream filb("ecounter.dat",ios::binary|ios::out);
    s.number=count+1;
    filb.write((char*)&s,sizeof(s));
    filb.close();

    Client person;
    ofstream fileB("eaccount.dat",ios::binary|ios::app);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    { 
        person.status='E';
        person.id=count;cin.ignore();
        cout<<"Name: ";cin.get(person.name,30);cin.ignore();
        cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
        cout<<"Designation: ";cin.get(person.actype,30);cin.ignore();
        cout<<"Password: ";
        int b=0;
        do{
            person.client_password[b]=getch();
            if(person.client_password[b]!='\r'){
                cout<<"*";
            }
            b++;
        }while(person.client_password[b-1]!='\r');
        person.client_password[b-1]='\0';
        cout<<"\nEnter Advance Salary(BDT): ";cin>>person.money;cin.ignore();
        fileB.write((char*)&person,sizeof(person));
        fileB.close();
        cout<<"\n\n\nEmployee ID "<<count<<" is created successfully . . . . ."<<endl;


        ofstream fileAL("elog.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Employee ID "<<count<<" was created."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();


    }
    
}
void empPortal()
{
    system("color f0");
    char ch;
	do
	{
	system("cls");
    system("color 0");
	cout<<"\n";
	cout<<"\t\t|||||||||| BANK MANAGEMENT SYSTEM ||||||||||"<<endl;
        cout<<"\n\t\t\t   EMPLOYEE MANAGEMENT";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\t 1. CREATE NEW EMPLOYEE";
		cout<<"\n\t\t\t 2. DEPOSIT SALARY";
		cout<<"\n\t\t\t 3. WITHDRAW SALARY";
		cout<<"\n\t\t\t 4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t 5. ALL EMPLOYEE LIST";
		cout<<"\n\t\t\t 6. FIRE AN EMPLOYEE";
		cout<<"\n\t\t\t 7. EMPLOYER'S INFORMATION MODIFICATION";
        cout<<"\n\t\t\t 8. ACTIVITY LOG";
        cout<<"\n\t\t\t 9. EMPLOYEE OF THE MONTH";
		cout<<"\n\t\t\t 0. BACK";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\tSelect Your Option (1-9): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			system("cls");
            empcreateNewAccount();
			break;
		case '2':
			system("cls");
            login();
			empdepo();
			break;
		case '3':
			system("cls");
            empwithdr();
			break;
		case '4':
			system("cls");
            empbalance();
			break;
		case '5':
            system("cls");
            empallAccount();
			break;
		case '6':
			system("cls");
            login();
            empdel();
			break;
		 case '7':
            system("cls");
            empmod();
			break;
            case '8':
            system("cls");
            login();
            system("cls");
            system("color B");
            cout<<"\n ACTIVITY LOG"<<endl;
            cout<<"___________________________________________________"<<endl;
            system("type elog.txt");
			break;
          case '9':
            login();
		 	system("CLS");
            employeeOftheYear();
			break;
		 case '0':
		 	system("CLS");
            
			break;
		}
        
        cin.ignore();
        cout<<"\n\n\n\t\t\tPress Enter to Continue. . . . . ."<<endl;
		cin.get();
    }while(ch!='0');
    portal();
}
portal()
{
    int f;
    
    system("cls");
    system("color E0");
    
    cout<<"\n\t\t|||||||||| BANK MANAGEMENT SYSTEM ||||||||||"<<endl;
    cout<<"\n\t\t\t         MAIN MENU";
    cout<<"\n\t\t\t __________________________\n";
    cout<<"\n\t\t            1.CLIENT MANAGEMENT"<<endl;
    cout<<"\t\t            2.EMPLOYEE MANAGEMENT"<<endl;
    cout<<"\t\t            3.LOAN MANAGEMENT"<<endl;
    cout<<"\t\t            4.EXIT"<<endl;

    cout<<"\n\n\t\t          ENTER OPTION:";
    cin>>f;
    switch (f)
    {
    case 1:
        clientPortal();
        break;

    case 2:
        empPortal();
        break;
        
    case 3:
        loPortal();
        break;
    
    
    default:
        break;
    }
    
}
void del()
{
    system("cls");
    system("color f0");
    cout<<"\n ACCOUNT CLOSING"<<endl;
    cout<<"___________________________________________________"<<endl;
    
        int search;
       
        cout<<"Enter Account ID:";cin>>search;cin.ignore();
        

       Client person;
       fstream fbin("account.dat",ios::binary|ios::in);       
       fstream fbd("temp.dat",ios::binary|ios::out);
       
        while(fbin.read((char*)&person,sizeof(person)))
        { 
            
             
            if((person.id!=search))
            {
                fbd.write((char*)&person,sizeof(person));
                 
                
            }
        }
        fbd.close();
        fbin.close();

        remove("account.dat");
        rename("temp.dat","account.dat");
        cout<<"\n\n\nAccount is closed successfully . . . ."<<endl;

        ofstream fileAL("log.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Account ID "<<search<<" was closed."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();  
}

void mod()
{
    cout<<"\n ACCOUNT MODIFICATION"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Account ID:";cin>>search;cin.ignore();
    cout<<"Enter Account Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("account.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"A/C"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                
                cout<<"\nName: ";cin.get(person.name,30);cin.ignore();
                cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
                
                cout<<"Password: ";
                int b=0;
                do{
                    person.client_password[b]=getch();
                    if(person.client_password[b]!='\r'){
                        cout<<"*";
                    }
                    b++;
                }while(person.client_password[b-1]!='\r');
                person.client_password[b-1]='\0';
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n\n\nAccount is modified successfully. . . ."<<endl;

                ofstream fileAL("log.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": Account ID "<<search<<" was modified."<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}
void withdr()
{
    cout<<"\n WITHDRAW"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Account ID:";cin>>search;cin.ignore();
    cout<<"Enter Account Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("account.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"A/C"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                int withdraw;
                cout<<"\nWithdraw amount(BDT): ";cin>>withdraw;cin.ignore();
                if(withdraw>person.money)
                {
                    cout<<"insufficient balance. . . . ."<<endl;
                }
                else
                {
                    person.money=person.money-withdraw;
                    int pos=(-1)*sizeof(person);
                    fbin.seekp(pos,ios::cur);
                    fbin.write((char*)&person,sizeof(person));
                    cout<<"\n\n"<<withdraw<<" taka is withdrawn successfully. . . ."<<endl;

                    ofstream fileAL("log.txt",ios::app);
                    time_t now = time(0);
                    char* dt=ctime(&now);
                    fileAL<<"\n---------------------------------------------------"<<endl;
                    fileAL<<dt<<": "<<withdraw<<" taka was withdrawn from account ID "<<person.id<<endl;
                    fileAL<<"---------------------------------------------------"<<endl;
                    fileAL.close();
                }
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}
void depo()
{
    cout<<"\n DEPOSIT"<<endl;
    cout<<"___________________________________________________"<<endl;
    int flag=0;
    char client_key[30];
    int search;
    
    cout<<"Enter Account ID:";cin>>search;cin.ignore();
    cout<<"Enter Account Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    cout<<"\n";
    
    
    Client person;
    fstream fbin("account.dat",ios::binary|ios::in|ios::out);
    fbin.seekg(0);
    if(!fbin)
    {
        cout<<"Error in opening file"<<endl;
    }
    else
    {
        while(fbin.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"A/C"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
                cout<<"       ------------------------------------------------------------------"<<endl;
                cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
                flag=1;
                int deposit;
                cout<<"\nDeposit amount(BDT): ";cin>>deposit;cin.ignore();
                person.money=person.money+deposit;
                int pos=(-1)*sizeof(person);
                fbin.seekp(pos,ios::cur);
                fbin.write((char*)&person,sizeof(person));
                cout<<"\n\n"<<deposit<<" taka is deposited successfully. . . ."<<endl;

                ofstream fileAL("log.txt",ios::app);
                time_t now = time(0);
                char* dt=ctime(&now);
                fileAL<<"\n---------------------------------------------------"<<endl;
                fileAL<<dt<<": "<<deposit<<" taka was deposited to account ID "<<person.id<<endl;
                fileAL<<"---------------------------------------------------"<<endl;
                fileAL.close();
            }
        } 
        fbin.close();
        if (flag==0)
        {
            cout<<"Not found"<<endl;
        }
    }
}
void balance()
{
    cout<<"\n BALENCE CHECK"<<endl;
    cout<<"___________________________________________________"<<endl;
    char client_key[30];
    int search;
    bool flag=0;
    
    cout<<"Enter Account ID:";cin>>search;cin.ignore();
    cout<<"Enter Account Password:";
    int a=0;
    do{
        client_key[a]=getch();
        if(client_key[a]!='\r'){
            cout<<"*";
        }
        a++;
    }while(client_key[a-1]!='\r');
    client_key[a-1]='\0';
    Client person;
    ifstream fileB("account.dat",ios::binary|ios::in);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    {
        while(fileB.read((char*)&person,sizeof(person)))
        {
            int l=strcmp(person.client_password,client_key);
            if((person.id==search)&&(l==0))
            {
                cout<<"\n\n\n\n\t\t\tA/C ID: "<<person.id<<endl;
                cout<<"\t\t\tA/C Holder Name: "<<person.name<<endl;
                cout<<"\t\t\tAdress: "<<person.adress<<endl;
                cout<<"\t\t\tA/C Type: "<<person.actype<<endl;
                cout<<"\t\t\tTotal Balance: "<<person.money<<" taka";
                flag=1;

            }
        }
        if(flag==0)
        {
            cout<<"\n\nNot found"<<endl;
        }
        
    }
}

void allAccount()
{
    cout<<"\n ALL ACCOUNT HOLDER LIST"<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    Client person;
    ifstream fileB("account.dat",ios::binary|ios::in);
    
    if(!fileB)
    {
        cout<<"Error in file opening"<<endl;
    }
    else
    {
        cout<<setw(10)<<"ID"<<setw(17)<<"NAME"<<setw(10)<<"A/C"<<setw(17)<<"ADRESS"<<setw(17)<<"AMOUNT"<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        while (fileB.read((char*)&person,sizeof(person)))
        {
            cout<<setw(10)<<person.id<<setw(17)<<person.name<<setw(10)<<person.actype<<setw(17)<<person.adress<<setw(17)<<person.money<<endl;
        }
        fileB.close();
    }
}

void createNewAccount()
{
    cout<<"\n NEW BANK ACCOUNT"<<endl;
    cout<<"___________________________________________________"<<endl;
    int count;
    Count s;

    ifstream fila("counter.dat",ios::binary|ios::in);    
    fila.read((char*)&s,sizeof(s));
    count=s.number;
    fila.close();

    ofstream filb("counter.dat",ios::binary|ios::out);
    s.number=count+1;
    filb.write((char*)&s,sizeof(s));
    filb.close();

    Client person;
    ofstream fileB("account.dat",ios::binary|ios::app);
    if(!fileB)
    {
        cout<<"Can not open file"<<endl;
    }
    else
    { 
        person.status='C';
        person.id=count;cin.ignore();
        cout<<"Name: ";cin.get(person.name,30);cin.ignore();
        cout<<"Adress: ";cin.get(person.adress,30);cin.ignore();
        cout<<"Account Type(c/s): ";cin.get(person.actype,2);cin.ignore();
        cout<<"Password: ";
        int b=0;
        do{
            person.client_password[b]=getch();
            if(person.client_password[b]!='\r'){
                cout<<"*";
            }
            b++;
        }while(person.client_password[b-1]!='\r');
        person.client_password[b-1]='\0';
        cout<<"\nEnter initial amount(BDT): ";cin>>person.money;cin.ignore();
        fileB.write((char*)&person,sizeof(person));
        fileB.close();
        cout<<"\n\n\nAccount ID "<<count<<" is created successfully . . . . ."<<endl;


        ofstream fileAL("log.txt",ios::app);
        time_t now = time(0);
        char* dt=ctime(&now);
        fileAL<<"\n---------------------------------------------------"<<endl;
        fileAL<<dt<<": Account ID "<<count<<" was created."<<endl;
        fileAL<<"---------------------------------------------------"<<endl;
        fileAL.close();


    }
    
}
void clientPortal()
{
    char ch;
	int num;
	do
	{
	system("cls");
    system("color f0");
	cout<<"\n";
	cout<<"\t\t|||||||||| BANK MANAGEMENT SYSTEM ||||||||||"<<endl;
        cout<<"\n\t\t\t     CLIENT MANAGEMENT";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\t 1. CREATE NEW ACCOUNT";
		cout<<"\n\t\t\t 2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t 3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t 4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t 5. ALL ACCOUNT LIST";
		cout<<"\n\t\t\t 6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t 7. MODIFY AN ACCOUNT";
        cout<<"\n\t\t\t 8. ACTIVITY LOG";
		cout<<"\n\t\t\t 0. BACK";
        cout<<"\n\t\t\t __________________________\n";
		cout<<"\n\t\t\tSelect Your Option (1-9): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			system("cls");
            createNewAccount();
			break;
		case '2':
			system("cls");
			depo();
			break;
		case '3':
			system("cls");
            withdr();
			break;
		case '4':
			system("cls");
            balance();
			break;
		case '5':
            system("cls");
            allAccount();
			break;
		case '6':
			system("cls");
            login();
            del();
			break;
		 case '7':
            system("cls");
            mod();
			break;
            case '8':
            system("cls");
            login();
            system("cls");
            system("color f0");
            cout<<"\n ACTIVITY LOG"<<endl;
            cout<<"___________________________________________________"<<endl;
            system("type log.txt");
			break;
		 case '0':
		 	system("CLS");
			break;
		}
        cin.ignore();
        cout<<"\n\n\n\t\t\tPress Enter to Continue. . . . . ."<<endl;
		cin.get();
    }while(ch!='0');

    portal();
}
void home()
{
  system("cls");
  system("color e0");  
  cout<<"\n\n\n\n"<<endl;
  cout<<"                     ************* Welcome ************"<<endl;
  cout<<"                     |          MONEY BANK LTD.       |"<<endl;
  cout<<"                     |    Keep your money safe here   |"<<endl;
  cout<<"                     **********************************\n\n\n\n\n\n"<<endl;
  Sleep(1000);
  cout<<"                               loading........."<<endl;
  Sleep(1000);
  system("color d0");
  Sleep(1000);
  system("color c0");
  Sleep(1000);
  system("color b0");
  Sleep(1000);
  system("color a0");
  system("cls");
  cout<<"\n\n\n\n"<<endl;
  cout<<"                     ************* Welcome ************"<<endl;
  cout<<"                     |          MONEY BANK LTD.       |"<<endl;
  cout<<"                     |    Keep your money safe here   |"<<endl;
  cout<<"                     **********************************\n\n\n\n\n\n"<<endl;
  cout<<"                           Press Enter to continue"<<endl;
  system("pause>0");
  portal();
}
};

int main()
{
    int i;
    string bye="Thank you for choosing this bank.";
    log ad;
    ad.design();
    ad.login();
    Business xd;
    xd.home();

    
    system("CLS");
    system("color f0");
	cout<<"\n\n\n\n\n\t\t\t";
            
    for(i=0;i<34;i++)
    {
        cout<<bye[i];
        Sleep(100);
    }
    
    
}
