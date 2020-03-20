#include <iostream>
#include <string>
#include <iomanip>
#include<windows.h>
#include<fstream>
#include "LOGIN.h"
#include "Implementation.cpp"
using namespace std;


int main() {
	char c;
	int choice;
	int totalEmployee=0;
	bool LoginDone=LOGIN();
	if(LoginDone==1) {
		
		cout<<"                                   |            Press the following keys              |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [1] Add a Room                     |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [2] Add an Employee                |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [3] Add a Customer                 |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [4] Book Room                      |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [5] Check In                       |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [6] Display Food Menu              |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [7] Order Food                     |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [8] Check Out                      |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [9] Calculate Bill                 |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"                                   |               [10] Display Details               |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
    	cout<<"                                   |               [11] EXIT                          |                    "<<endl;
		cout<<"                                   ----------------------------------------------------                              "<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
    
		Rooms *R[10];
		Employee *E[10];
		Customer *C[10];
		Check *check[10];
		Bill *bill[10];
		for (int i=0;i<10;i++)
		{	
				E[i]=new Employee;
				C[i]=new Customer;
				check[i]=new Check;
		}
		int j=0;
		char* nam=new char[17];
		long int tn;
		int ch;
		char gen;
		int id;
		string designate;
		long int salar;
		string add;
		Fooditems F1(001,45.6,"Lasagne");
		Fooditems F2(002,20.4,"Pizza");
		Fooditems F3(003,30.1,"Burger");
	
		int hour;
		int k=0,booked=0,noOfRooms=0;
		int m=0;
		int order=1;
		int u;
		int r;
		
		
		bool e;
		bool flag=true;
		while (flag==true){
		
			
			try{
				cout<<"------------------------------------------------ ENTER THE CHOICE OF MENU --------------------------------------------------"<<endl;
				cin>>choice;
				if(choice==1)
				{
					cout<<"---------------------------------------------------Displaying Room Management Menu----------------------------------------"<<endl;
					cout<<"Enter the number of rooms you want to add:"<<endl;
					cin>>ch;
					
					for(int i = noOfRooms; i < noOfRooms+ch; i ++) 
					{


							cout<<"Enter the Room number for object "<<i+1<<": ";
							cin>>r;

						
							cout<<"Is the Room Number "<<r<<" empty? ";
							cin>>e;
					
							R[i] = new Rooms(r,e);
							
							
		
				}
				noOfRooms+=ch;
			}
				else if(choice==2)
				{
				
					cout<<"--------------------------------------------------EMPLOYEE DATA ENTRY Menu------------------------------------------------"<<endl;
					cout<<"Enter number of employees: "<<endl;
					cin>>ch;
				
				
					cout<<"---------------------------------------------------DATA ENTRY OF EMPLOYEE---------------------------------------------------"<<endl;
					for (j=0;j<ch;j++)
					{
						cout<<"----------------------------------------------------ENTRY OF EMPLOYEE "<<j+1<<"-----------------------------------------------------"<<endl;
						cin.ignore();
						cout<<"Enter the name of employee: "<<endl;
						cin.getline( nam,17);
						
						E[j]->setName(nam);
						cout<<"Enter the telephone number(8 digits only): "<<endl;
						cin>>tn;
						while(1)
						{
							int num=tn,count=0;
							while(num!=0)
							{
								 num /= 10;
	        					++count;
							}
								if(count==8)
								{
									E[j]->setTelephoneNum(tn);
									break;
								}
								else
								{
									cout<<"Telephone number must have 8 digits only.Please Re-enter."<<endl;
									cin>>tn;
								}
						}
						
						cout<<"Enter the gender(M/F): "<<endl;
						while(1)
						{
							cin>>gen;
							if(gen!='M' || gen!='F')
							{
								E[j]->setGender(gen);
								break;
							}		
							else
								cout<<"Only M/F can be entered."<<endl;
						}
						
						cout<<"Enter the ID: "<<endl;
						cin>>id;
						E[j]->setID(id);
						cout<<"Enter the Salary: $"<<endl;
						cin>>salar;
						E[j]->setSalary(salar);
						cin.ignore();
						cout<<"Enter the address: "<<endl;
						getline(cin,add);
						E[j]->setAddress(add);
						cout<<"Enter the designation: "<<endl;
						getline( cin,designate);
						E[j]->setDesignation(designate);
						cout<<"Enter the working hours: "<<endl;
						cin>>hour;
						E[j]->setHours(hour);
						totalEmployee++;
					}
					
				}
				else if(choice==3)
				{
					cout<<"--------------------------------------------------DATA ENTRY OF CUSTOMER--------------------------------------------------"<<endl;
					
						cout<<"Enter the name of customer: "<<endl;
						cin.ignore();
						cin.getline( nam,17);
						C[k]->setName(nam);
						cout<<"Enter the telephone number(8 digits only): "<<endl;
						cin>>tn;
						while(1)
						{
							int num=tn,count=0;
							while(num!=0)
							{
								 num /= 10;
	        					++count;
							}
								if(count==8)
								{
									C[k]->setTelephoneNum(tn);
									break;
								}
								else
								{
									cout<<"Telephone number must have 8 digits only.Please Re-enter."<<endl;
									cin>>tn;
								}
						}
						cin.ignore();
						cout<<"Enter the gender(M/F): "<<endl;
						while(gen)
						{
							cin>>gen;
							if(gen!='M' || gen!='F')
							{
								C[k]->setGender(gen);
								break;
							}		
							else
								cout<<"Only M/F can be entered."<<endl;
						}
						
						cout<<"Enter the ID: "<<endl;
						cin>>id;
						C[k]->setID(id);
						cout<<"Enter the address: "<<endl;
						cin.ignore();
						getline(cin,add);
						
						C[k]->setAddress(add);
					k++;
				}
				else if(choice==4)
				{	
					cout<<"-----------------------------------------------------Customer Room Booking Menu---------------------------------------------"<<endl;
					checkAvailability(R,noOfRooms);
					bool isbooked=false,isempty;
					for(int i=0;i<noOfRooms;i++)
					{
						isempty=R[i]->getIsEmpty();
						if(isempty==false)
						{
							booked++;
						}
					}
					if(booked==noOfRooms)
					{
						cout<<"Sorry!All the rooms are booked currently."<<endl;
					}
					else
					{
					
						for (m=0;m<noOfRooms;m++)
						{
							cout<<"Enter "<<m<< " to choose Room# "<<R[m]->getRoomNo()<<endl;
						}
						cin>>ch;
						while(ch<0 || ch>=noOfRooms)
						{
							cout<<"Wrong Choice!Please Re-enter."<<endl;
							cin>>ch;
							
						}
						int cus;
						for (u=0;u<k;u++)
						{
							cout<<"Press "<<u<<" for Customer name:"<<C[u]->getName()<<"|ID: "<<C[u]->getID()<<endl;
						}
						cin>>cus;
						isbooked=C[cus]->BooksRoom(R[ch]);
						while(isbooked==false)
						{
							for (m=0;m<noOfRooms;m++)
							{
							cout<<"Enter "<<m<< " to choose Room# "<<R[m]->getRoomNo()<<endl;
							}
							cin>>ch;
							if(ch>0 && ch<noOfRooms)
								isbooked=C[cus]->BooksRoom(R[ch]);
							else
							{
								cout<<"Wrong Choice!Please Re-enter."<<endl;
								isbooked=false;
							}
						}
					}
				}
				else if(choice==5)
				{
					cout<<"-----------------------------------------------------Customer Check Out Menu----------------------------------------------"<<endl;
					
					int cus;
					for (u=0;u<k;u++)
					{
						cout<<"Press "<<u<<" for "<<C[u]->getName()<<" and  "<<C[u]->getID()<<endl;
					}
					cin>>cus;
					C[cus]->setCheckInOut(check[cus]);
					C[cus]->CheckIn();
				}
				else if(choice==6)
				{
					cout<<"-------------------------------------------------------Food Ordering Menu-------------------------------------------------"<<endl;
					
					F1.displayMenu();
					F2.displayMenu();
					F3.displayMenu();	
				}
				else if(choice==7)
				{
					cout<<"--------------------------------------------------Customer Food Ordering Menu---------------------------------------------"<<endl;
					int quan;
					int cus;
					for (u=0;u<k;u++)
					{
						cout<<"Press "<<u<<" for "<<C[u]->getName()<<" and  "<<C[u]->getID()<<endl;
					}
					cin>>cus;
					
					cout<<"Enter the quanity of Food you want to order: "<<endl;
					cin>>quan;
					
					orderFood *Order[quan];
					
					
					for (int i=0;i<quan;i++)
					{
						cout<<"Enter 0 to order "<<F1.getName()<<" with Food ID "<<F1.getFoodId()<<endl;
						cout<<"Enter 1 to order "<<F2.getName()<<" with Food ID "<<F2.getFoodId()<<endl;
						cout<<"Enter 2 to order "<<F3.getName()<<" with Food ID "<<F3.getFoodId()<<endl;
						cin>>ch;
						if (ch==0)
						{
							Order[i]=new orderFood(quan,order,&F1);
							Order[i]->setFoodQuantity(quan);
						}
						else if (ch==1)
						{
							Order[i]=new orderFood(quan,order,&F2);
							Order[i]->setFoodQuantity(quan);
						}
						else if (ch==2)
						{
							Order[i]=new orderFood(quan,order,&F3);
							Order[i]->setFoodQuantity(quan);
						}
					}
					
					C[cus]->setOrderedFood(Order);
					
					cout<<"----------------------------------------------------Food Ordered Successfully-----------------------------------------------"<<endl;	
					cout<<"Order# "<<Order[0]->getOrderNo()<<endl;
					cout<<"Customer Name & Id: "<<C[cus]->getName()<<" "<<C[cus]->getID()<<endl;
					cout<<"-----------------------------------------------------Ordered Food Is--------------------------------------------------------"<<endl;
					for (int i=0;i<quan;i++)
					{
						cout<<"----------------------"<<Order[i]->getFoodOrdered()->getName()<<"-------------------------------------------------------"<<endl;
					}
					}
				else if(choice==8)
				{
					cout<<"-----------------------------------------------------Customer Check Out Menu------------------------------------------------"<<endl;
					int cus;
					for (u=0;u<k;u++)
					{
						cout<<"Press "<<u<<" for "<<C[u]->getName()<<" and  "<<C[u]->getID()<<endl;
					}
					cin>>cus;
					C[cus]->CheckOut();
				}
				else if(choice==9)
				{
					
					cout<<"------------------------------------------------Customer Billing Calculation Menu-------------------------------------------"<<endl;
					int cus;
					for (u=0;u<k;u++)
					{
						cout<<"Press "<<u<<" for "<<C[u]->getName()<<" |  "<<C[u]->getID()<<endl;
					}
					cin>>cus;
					bill[cus]=new Bill;
					cout<<"Press 0 to calculate ROOM BILL| Press 1 to caculate FOOD BILL|\n Press 2 to caculate FOOD BILL| Press 3 to go to the menu"<<endl;
					
			   cin>>ch;
					
					while(ch!=3)
					{	
						if(ch==0)
						{
							cout<<"-----------------------------------------------Displaying Room Billing Data----------------------------------------------"<<endl;
							cout<<"Total Room Bill (exclusive of tax): "<<bill[cus]->calculateRoomBill(C[cus],check[cus])<<" for "<<(bill[cus]->calculateRoomBill(C[cus],check[cus])/5000)<<" Days"<<endl;
						}
						else if(ch==1)
						{
							cout<<"------------------------------------------------Displaying Food Billing Data----------------------------------------------"<<endl;
							cout<<"Total Food Bill (exclusive of tax): "<<bill[cus]->calculateFoodBill(C[cus])<<endl;
						}
						else if(ch==2)
						{
							cout<<"----------------------------------------------Displaying Total Billing Customer Data----------------------------------------"<<endl;
							cout<<"Total Bill (exclusive of tax): "<<bill[cus]->getAmount()<<endl;
							cout<<"Total Bill (inclusive of tax): "<<bill[cus]->getTaxedAmount()<<endl;
						}
						else 
						cout<<"Re-enter.Wrong Choice."<<endl;
						cin>>ch;
					}
					
				}
				else if(choice==10)
				{
					int a;
					cout<<"-------------------------------------------------- Details Displaying Menu--------------------------------------------------"<<endl;	
					cout<<"----------------------------------------------Press 1 for Displaying Employee Data------------------------------------------"<<endl;	
					cout<<"----------------------------------------------Press 2 for Displaying Customer Data------------------------------------------"<<endl;	
					cout<<"----------------------------------------------Press 3 for Displaying Rooms Data   ------------------------------------------"<<endl;
						try{
							cin>>a;
							if (a==1){
									cout<<"--------------------------------------------------Displaying Employee Data-----------------------------------------------"<<endl;
								for (int i=0;i<totalEmployee;i++)
								{
									cout<<"----------------------------------------------------DETAILS OF EMPLOYEE "<< i+1<<"---------------------------------------"<<endl;
									E[i]->printinfo();
								}	
										
							}
							else if (a==2){
									cout<<"--------------------------------------------------Displaying Customer Data------------------------------------------------"<<endl;
								for (int i=0;i<k;i++)
								{
									cout<<"-----------------------------------------------------DETAILS OF CUSTOMER "<<i+1<<"----------------------------------------"<<endl;
									C[i]->printinfo();
								}
							}
							else if (a==3)
							{
									cout<<"-------------------------------------------------DETAILS OF Room Availability---------------------------------------------"<<endl;
								checkAvailability(R,noOfRooms);
							}
							else if(a!=1|| a!=2 || a!=3){
								throw 99;
							}
						}
				catch(int x){
					
					cout<<"Invalid choice or data type entered \nSelect Again with valid Data type and choice\n";
					continue;	
					}
//					
				}
				else if(choice==11)
				
				{
					system("cls");
					char s=219;

					int count = 0;
				    cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
			    	cout<<"----------------------------------------           EXITING THE SYSTEM            -------------------------------------------"<<endl;
			    	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
			    	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout<<"\n---------------------------------------------------------Loading------------------------------------------------------------\n"<<endl;
					cout<<"----------------------------------------         ";
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 250);
					for(count;count < 26; ++count){
				        cout << s ;
				        fflush(stdout);
				        Sleep(200);
				    }
				    SetConsoleTextAttribute(hConsole, 240);
				    cout<<"         ----------------------------------------\n"<<endl;
				   	cout<<"                                                        THANKYOU!                                                           "<<endl;
					exit(0);
					return 0;


				}
				else if(choice!=1 || choice!=2 || choice!=3 || choice!=4 || choice!=5 || choice!=6 || choice !=7 || choice!=8 || choice !=9 || choice!= 10 ||choice !=11 )
				{
					flag=true;
					throw 404;
				}
			}
				catch(int x)
			{
				cout<<"Wrong Option Selected Error "<<x<<"\n Try Again\n";
				continue;
			}
					
		}
		
		
		Sleep(500);
	
		return 0;
		}
	

	 else {
		cout<<"Press any Other key to Exit..."<<endl;
		cin>>c;
		exit;
		return 0;
	}
}

