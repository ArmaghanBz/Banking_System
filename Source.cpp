#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct bank {
	string name;
	int account_no;
	int deposit;
	double balance;
	string type;
	bank* prev, * next;
};
bank* head = NULL;
void createNewAcc() {
	system("cls");
	int d = 0, acc_n; string na, t;
	cout << "\t\tPlease enter new name: ";
	cin.ignore();
	getline(cin,na);
	cout << "\t\tPlease enter new account number: ";
	cin >> acc_n;
	cout << "\t\tPlease enter the type of the account: ";
	cin.ignore();
	getline(cin, t);
	cout << "\t\tPlease enter the Amount to deposit: ";
	cin >> d;
	cout << "\n\t\t\------------------------------\n";
	bank* newnode = new bank;
	newnode->name = na;
	newnode->account_no= acc_n;
	newnode->type = t;
	newnode->deposit = d;
	newnode->balance = d;
	//------------------------------------------------//
	if (head == NULL) {
		head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else {
		bank* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;
	}
}
int transactions() {
again:
	system("cls");
	int tempId;
	cout << "\t\tPlease enter your Account number: ";
	cin >> tempId;
	bank* temp = head;
	string recieverName, receiverAcc, recieverBankName, recieverAccountNo;
	int sendingAmount=0;
	bool flag=false;
	while (temp != NULL) {
		if ( tempId == temp->account_no) {
			system("cls");
			cout << "\n\t\tAccount found!!\n\n";
			cout << "\t\tPlease enter the name of the person to whom want to send the money: ";
			cin.ignore();
			getline(cin, recieverName);
			cout << "\t\tPlease enter the name of the bank of that person to whom want to send the money: ";
			getline(cin, recieverBankName);
			cout << "\t\tPlease enter account number of that person to whom want to send the money: ";
			getline(cin, recieverAccountNo);
			cout << "\t\tPlease enter the amount: ";
			cin >> sendingAmount;
			if (sendingAmount <= temp->balance) {
				temp->balance = temp->balance - sendingAmount; /*user balance will be updated after the
				transaction*/
			}
			else {
				cout << "\n\t\tYour account doesn't have sufficient balance to perform transaction\n\n";
				cout << "\t\tYour balance is: " << temp->balance << endl;
				_getch();
				return 1;
			}
			flag = true;
			
		}
		temp = temp->next;
	}
	if (flag==false) {
		cout << "The account doesn't exits- Try again";
		_getch();
		goto again;
	}
	else {
		system("cls");
		cout << "\n\t\tThe transaction slip: \n\n";
		cout << "\t\tThe name: " << recieverName << endl;
		cout << "\t\tThe account number: " << recieverAccountNo << endl;
		cout << "\t\tThe reciever's bank: " << recieverBankName << endl;
		cout << "\t\tThe Amount send: " << sendingAmount << endl;
	}

}
void display() {
	system("cls");
	bank* temp = head;
	while (temp != NULL) {

		cout<<"\n\n\t\tThe name: " << temp->name << endl;
		cout <<"\t\tThe account number: " << temp->account_no << endl;
		cout <<"\t\tThe deposited Amount on first time: " << temp->deposit << endl;
		cout << "\t\tThe Balance: " << temp->balance << endl;
		cout <<"\t\tThe type of the account: " << temp->type << endl;
		cout << "\t\t---------------------------------------\n\n";
		temp = temp->next;
	}
}

void main() {
	//-----------------Main screen------------------//
	mainwin:
	cout << "\n\n\n\n\t\t\t\tThe World Bank" << endl << endl;
	cout << "\t\t\t    Press enter to continue";
	_getch();
	system("cls");
	int temp=0,temp1=0;
	while (true) {
		menu:
		cout << "\n\t\tPlease enter 1 to enter new account: \n";
		cout << "\t\tPlease enter 2 to display the account: \n";
		cout << "\t\tPlease enter 3 to transfering the amount : \n";
		cout << "\t\tPlease enter 4 to exit the program : \n";
		cin >> temp;
		if (temp == 1) {
			createNewAcc();
			system("cls");
		}
		else if (temp == 2) {
			display();
			cout << "\n\t\tPress any key to continue: ";
			_getch();
			system("cls");
		}
		else if (temp == 3) {
			temp1=transactions();
			if (temp1 == 1) {
				system("cls");
				goto menu;
			}
			else {
				cout << "\n\t\tPress any key to continue: ";
				_getch();
				system("cls");
			}
		}
		else if (temp == 4) {
			system("cls");
			cout << "\n\n\t\tProgram Exited!!\n\n";
			exit(1);
		}
	}
}
