/*
Group 3
Section 01

PIRAVEEN ASHWINATH A/L R JAYABALAN	A19SC0349
SEIFELDIN TAHA ABDELRAHIM TOHAMI	A19EC3030
ASHRAFUR RAHMAN NAZIN				A20EC4012
TAHMEDUR RAHMAN						A19EC4059
*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class library{
	public:
		string book;
		string availability;
		int copies;
		library* next;
};

class list{
	public:
		string title;
		string status;
		int borrowers;
		list* on;
};

void view(library*n){
	while(n!=NULL){
	cout<<"Title: "<<n->book<<endl;
	cout<<"Availability: "<<n->availability<<endl;
	cout<<"Number of copies left: "<<n->copies<<endl;
	cout<<endl;	
	n=n->next;
	}
}

void view2(list*m){
	while(m!=NULL){
	cout<<"Title: "<<m->title<<endl;
	cout<<"Availability: "<<m->status<<endl;
	cout<<"Number of copies left:  "<<m->borrowers<<endl;
	cout<<endl;	
	m=m->on;
	}
}

void insert(library** head,int newCopies,string newBook, string newAvailability){
	library* newLibrary= new library();
	newLibrary->copies=newCopies;
	newLibrary->book=newBook;
	newLibrary->availability=newAvailability;
	newLibrary->next=*head;
	*head=newLibrary;
}

void insert2(list** front,int newBorrowers,string newTitle, string newStatus){
	list* newList= new list();
	newList->borrowers=newBorrowers;
	newList->title=newTitle;
	newList->status=newStatus;
	newList->on=*front;
	*front=newList;
}

void menu(){
	cout<<"1. STUDENT"<<endl;
	cout<<"2. ADMINISTRATOR"<<endl;
	cout<<"3. EXIT"<<endl;
}

void adminMenu(){
	cout<<"1. VIEW LIST"<<endl;
	cout<<"2. VIEW BORROWER INFORMATION"<<endl;
	cout<<"3. EXIT"<<endl;
}

void studentMenu(){
	cout<<"1. VIEW LIST"<<endl;
	cout<<"2. RESERVE"<<endl;
	cout<<"3. EXIT"<<endl;
}

int main(){
	int a;
	string name,id;
	
	cout<<"----- LIBRARY -----"<<endl;
	cout<<endl;
	
	library* head=new library();
	library* second=new library();
	library* third=new library();
	
	list* front=new list();
	list* middle=new list();
	list* rear=new list();
	
	insert(&head,5,"Moby Dick","AVAILABLE");
	insert(&head,0,"Java for NOOBS","NOT AVAILABLE");
	insert(&head,1,"Little Red Riding Hood","AVAILABLE");
	insert(&head,17,"History","AVAILABLE");
	insert(&head,0,"Member Terapung","NOT AVAILABLE");
	insert(&head,0,"Ace MUET","NOT AVAILABLE");
	insert(&head,25,"Collection of English Literature","AVAILABLE");
	insert(&head,9,"Climate Change is Real","AVAILABLE");
	insert(&head,0,"University Physics","NOT AVAILABLE");
	insert2(&front,0,"Engineering Mathematics","NOT AVAILABLE");
	insert2(&front,3,"Business for NOOBS","AVAILABLE");
	insert2(&front,1,"Psychology","AVAILABLE");
	insert2(&front,31,"The Big Bang","AVAILABLE");
	insert2(&front,0,"Chemistry","NOT AVAILABLE");
	insert2(&front,0,"Biology","NOT AVAILABLE");
	insert2(&front,19,"Ancient Rome","AVAILABLE");
	insert2(&front,15,"Geography","AVAILABLE");
	
//	view(head);

do{
		menu();
		cout<<"Input: ";
		cin>>a;
		
		if(a==1){
			do{
				studentMenu();
				cout<<"Input: ";
				cin>>a;
				
				if(a==1){
					view(head);
					cout<<endl;
					cout<<"View next page?"<<endl;
					cout<<"1. YES"<<endl;
					cout<<"2. NO"<<endl;
					cout<<"Input: ";
					cin>>a;
					
						if(a==1){
							view2(front);
						}
						if(a==2){
							return 0;
						}
						
				}
				if(a==2){
					cout<<"Name: ";
					cin>>name;
					cout<<endl;
					cout<<"ID: ";
					cin>>id;
					cout<<endl;
				}
			}
			while(a!=3);
		}
		
		if(a==2){
			do{
				adminMenu();
				cout<<"Input: ";
				cin>>a;
				
				if(a==1){
					view(head);
					cout<<endl;
					cout<<"View next page?"<<endl;
					cout<<"1. YES"<<endl;
					cout<<"2. NO"<<endl;
					cout<<"Input: ";
					cin>>a;
					
						if(a==1){
							view2(front);
						}
						if(a==2){
							return 0;
						}
				}
				if(a==2){
					cout<<"Name: "<<name<<endl;
					cout<<"ID: "<<id<<endl;
				}
			}
			while(a!=3);
		}
	}
	while(a!=3);

	return 0;
}
