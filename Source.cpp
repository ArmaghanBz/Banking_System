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
	int d = 0, acc_n; string na, t;
	cout << "\t\tPlease enter new name: ";
	cin.ignore();
	getline(cin,na);
	cout << "\t\tPlease enter new account: ";
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
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
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
void transactions() {
	string tempName;
	cout << "\t\tPlease enter your name: ";
	cin.ignore();
	getline(cin, tempName);
	int tempId;
	cout << "\t\tPlease enter your Account Id: ";
	cin >> tempId;
	bank* temp = head;
	string recieverName, receiverAcc, recieverBankName, recieverAccountNo;
	int sendingAmount;
	while (temp != NULL) {
		if (temp->name != tempName && temp->account_no != tempId) {
			cout << "\t\tThis account does not exits!!";
		}
		else {
			system("cls");
			cout << "\n\t\tAccount found!!\n\n";
			cout << "\t\tPlease enter the name of the person to whom want to send the money: ";
			cin.ignore();
			getline(cin, recieverName);
			cout << "\t\tPlease enter the name of the bank of that person to whom want to send the money: ";
			getline(cin, recieverBankName);
			cout << "\t\tPlease enter aaccount number of that person to whom want to send the money: ";
			getline(cin, recieverAccountNo);
			cout << "\t\tPlease enter the amount: ";
			cin >> sendingAmount;
			temp->balance = temp->balance - sendingAmount; /*user balance will be updated after the
			transaction*/
		}
		temp = temp->next;
	}
	bank* temp1 = head;
	while (temp1 != NULL) {
		if (tempName != temp1->name && tempId != temp1->account_no) {
			cout << "\t\tThis account does not exits!!";
		}
		else {
			system("cls");
			cout << "\n\t\tThe transaction slip: \n\n";
			cout << "\t\tThe name: " << recieverName << endl;
			cout << "\t\tThe account number: " << recieverAccountNo << endl;
			cout << "\t\tThe reciever's bank: " << recieverBankName << endl;
			cout << "\t\tThe Amount send: " << sendingAmount << endl;
			temp1 = temp1->next;
		}
	}
}
void display() {
	bank* temp = head;
	while (temp != NULL) {
		cout<<"\t\tThe name: " << temp->name << endl;
		cout <<"\t\tThe account number: " << temp->account_no << endl;
		cout <<"\t\tThe deposited Amount on first time: " << temp->deposit << endl;
		cout << "\t\tThe Balance: " << temp->balance << endl;
		cout <<"\t\tThe type of the account: " << temp->type << endl;
		temp = temp->next;
	}
}

void main() {
	//-----------------Main screen------------------//
	mainwin:
	cout << "\n\n\t\tTHE BANK ALHABIB" << endl << endl;
	//cout << "\t\t Press enter to continue";
	int temp=0;
	while (true) {
		cout<<"\n\t\t---------------------------------------------\n";
		cout << "\n\t\tPlease enter 1 to enter new account: \n";
		cout << "\t\tPlease enter 2 to display the account: \n";
		cout << "\t\tPlease enter 3 to transfering the amount : \n";
		cout << "\t\tPlease enter 4 to exit the program : \n";
		cin >> temp;
		if (temp == 1) {
			system("cls");
			createNewAcc();
		}
		else if (temp == 2) {
			system("cls");
			display();
		}
		else if (temp == 3) {
			system("cls");
			transactions();
		}
		else if (temp == 4) {
			exit(1);
		}
	}
}
