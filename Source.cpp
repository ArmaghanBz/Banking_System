#include <iostream>
#include <string>
using namespace std;

struct bank {
	string name;
	string account_no;
	int deposit;
	string type;
	bank* prev, * next;
};
bank* head = NULL;
void createNewAcc() {
	int d = 0; string na, acc_n, t; 
	cout << "Please enter new name: ";
	cin.ignore();
	getline(cin,na);
	cout << "Please enter new account: ";
	getline(cin, acc_n);
	cout << "Please enter the type of the account: ";
	getline(cin, t);
	cout << "Please enter the Amount to deposit: ";
	cin >> d;
	cout << "\n------------------------------\n";
	bank* newnode = new bank;
	newnode->name = na;
	newnode->account_no= acc_n;
	newnode->type = t;
	newnode->deposit = d;
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
void display() {
	bank* temp = head;
	while (temp != NULL) {
		cout << temp->name << endl;
		cout << temp->account_no << endl;
		cout << temp->deposit << endl;
		cout << temp->type << endl;
		temp = temp->next;
	}
}

void main() {
	createNewAcc();
	createNewAcc();
	createNewAcc();
	display();
}