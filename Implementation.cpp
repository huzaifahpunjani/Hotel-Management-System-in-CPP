#include "Header.h"

Person::Person(int id=0,char* n=NULL,long int t=0,char g='\0',string a="\0") {
	ID=id;
	Name=n;
	Telephone_num=t;
	Gender=g;
	Address=a;
}
Person::Person(const Person& obj) {
	ID=obj.ID;
	Name=new char[strlen(obj.Name)+1];
	strcpy(Name,obj.Name);
	Telephone_num=obj.Telephone_num;
	Gender=obj.Gender;
	Address=obj.Address;
}
void Person::setName(char* n) {
	Name=new char[strlen(n)+1];
	strcpy(Name,n);
}
void Person::setID(int id) {

	ID=id;
}
void Person::setTelephoneNum(long int tn) {
	Telephone_num=tn;
}
void Person::setAddress(string a) {
	Address=a;
}
void Person::setGender(char g) {
	Gender=g;
}
void Person::printinfo() {
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------------------------     PERSON'S DATA     ---------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<Name<<endl;
	cout<<"Telephone number: "<<Gender<<endl;
	cout<<"Address: "<<Address<<endl;
	cout<<"Gender: "<<Gender<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
}
char* Person::getName() {
	return Name;
}
long int Person::getTelephoneNum() {
	return Telephone_num;
}
char Person::getGender() {
	return Gender;
}
int Person::getID()
{
	return ID;
}
string Person::getAddress() {
	return Address;
}
Person::~Person() {
	delete Name;
}
Employee::Employee() {
	Designation="\0";
	Salary=0.00;
	Hours=0;
}
void Employee::setDesignation(string d) {
	Designation=d;
}
void Employee::setSalary(float s) {
	Salary=s;
}
void Employee::setHours(int h) {
	Hours=h;
}
string Employee::getDesignation() {
	return Designation;
}
void Employee::printinfo() {
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------  EMPLOYEE'S DATA  ------------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<Name<<endl;
	cout<<"Telephone number: "<<Gender<<endl;
	cout<<"Address: "<<Address<<endl;
	cout<<"Gender: "<<Gender<<endl;
	cout<<"Designation: "<<Designation<<endl;
	cout<<"Salary: "<<Salary<<endl;
	cout<<"Number of Working Hours: "<<Hours<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
}
float Employee::getSalary() {
	return Salary;
}
int Employee::getHours() {
	return Hours;
}
Employee::~Employee() {
	delete Name;
}
Customer::Customer(int id=0,char* n=NULL,long int t=0,char g='\0',string a="\0"):Person(id,n,t,g,a) {
}
Customer::Customer(const Customer& obj) {
	ID=obj.ID;
	Name=obj.Name;
	Telephone_num=obj.Telephone_num;
	Gender=obj.Gender;
	Address=obj.Address;
	roomAlloted=new Rooms;
	roomAlloted=obj.roomAlloted;
	orderedFoods=obj.orderedFoods;
}

ostream& operator <<(ostream &out,const Customer &obj1) {
	out<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	out<<"-------------------------------------------------     CUSTOMER'S DATA     --------------------------------------------------"<<endl;
	out<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	out<<"ID: "<<obj1.ID<<endl;
	out<<"Name: "<<obj1.Name<<endl;
	out<<"Telephone number: "<<obj1.Telephone_num<<endl;
	out<<"Gender: "<<obj1.Gender<<endl;
	out<<"Address: "<<obj1.Address<<endl;
	out<<"Room number allotted: "<<obj1.roomAlloted->getRoomNo()<<endl;
	for(int i=0; i<(obj1.orderedFoods[0]->getFoodQuantity()); i++) {
		cout<<"Food item "<<i+1<<" ordered: "<<obj1.orderedFoods[i]->getFoodOrdered()->getName()<<endl;
	}
	out<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	return out;
}
void Customer::setOrderedFood(orderFood** O) {
	orderedFoods=O;
	cout<<endl<<"Order # "<<O[0]->getOrderNo()<<" has been confirmed for the customer ID "<<ID<<endl;
}
void Customer::setOrderedFoodItems(Fooditems* F) {
	orderedFoods[index++]->setFoodOrdered(F);
//	int index=orderedFoods->getIndex();
//	++index;
//	orderedFoods->setIndex(index);
}
Fooditems* Customer::getOrderedFoodItems(int i) {
	return orderedFoods[i]->getFoodOrdered();
}
orderFood** Customer::getOrderedFoods() {
	return orderedFoods;
}
bool Customer::BooksRoom(Rooms *R) {
	roomAlloted=R;
	if(R->getIsEmpty()==true)
	{
		R->setIsEmpty(false);
		cout<<"Room number "<<R->getRoomNo()<<" booked successfully."<<endl;
		return true;
	}
	else
	{
		cout<<"Sorry! Room "<<R->getRoomNo()<<" has already been booked."<<endl;
		return false;
	}
		
	
}
Check* Customer::getCheckInOut() {
	return checkInOut;
}
void Customer::setCheckInOut(Check *C) {
	checkInOut=C;
}
void Customer::CheckOut() {
	roomAlloted->setIsEmpty(true);
	int h,n,d,m,y;
	cout<<"Enter the (hours,mins,date,month,year) for Check Out of Customer ID "<<Person::getName()<<": "<<endl;
	cin>>h>>n>>d>>m>>y;
	checkInOut->setDateTimeOut(h,n,d,m,y);

}
void Customer::CheckIn() {
	roomAlloted->setIsEmpty(false);
	int h,n,d,m,y;
	cout<<"Enter the (hours,mins,date,month,year) for Check In of Customer "<<Person::getName()<<": "<<endl;
	cin>>h>>n>>d>>m>>y;
	checkInOut->setDateTimeIn(h,n,d,m,y);
}
void Customer::printinfo() {
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------     CUSTOMER'S DATA     --------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<Name<<endl;
	cout<<"Telephone number: "<<Gender<<endl;
	cout<<"Address: "<<Address<<endl;
	cout<<"Gender: "<<Gender<<endl;
	cout<<"Room alloted: "<<roomAlloted->getRoomNo()<<endl;
	for(int i=0; i<(orderedFoods[0]->getFoodQuantity()); i++) {
		cout<<"Food item "<<i+1<<" ordered: "<<orderedFoods[i]->getFoodOrdered()->getName()<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
}
Customer::~Customer() {
	delete Name;
	index=0;
}
DateTime::DateTime(int h=0,int m=0,int d=0,int mo=0,int y=0) {
	hour=h;
	min=m;
	day=d;
	month=mo;
	year=y;

}
int DateTime::getDay() {
	return day;
}
int DateTime::getHour() {
	return hour;
}
int DateTime::getMin() {
	return min;
}
int DateTime::getMonth() {
	return month;
}
int DateTime::getYear() {
	return year;
}
void DateTime::setDateTime(int hour,int min,int day,int month,int year) {
//        time_t now = time(0);
//        dt = ctime(&now);
	if(hour>-1 && hour<25) {
		this->hour=hour;
	} else {
		this->hour=0;
	}
	if(min>-1 && min<61) {
		this->min=min;
	} else {
		this->min=0;
	}
	if(day>0 && day<=30) {
		this->day=day;
	} else {
		this->day=0;
	}
	if(month>0 && month<=12) {
		this->month=month;
	} else {
		this->month=0;
	}
	this->year=year;
}
void DateTime::DisplayDateTime() {
	cout<<"Time of check in (24 hour clock):"<<hour<<":"<<min<<endl;
	cout<<"Date of check in: "<<day<<"-"<<month<<"-"<<year<<endl;

}
Rooms::Rooms(int r=0,bool IE=true) {
	roomNo=r;
	isEmpty=IE;
}
Rooms::Rooms() {

}
void Rooms::operator =(const Rooms& obj1) {
	this->roomNo=obj1.roomNo;
	this->isEmpty=obj1.isEmpty;
}
Rooms::Rooms(const Rooms& obj) {
	roomNo=obj.roomNo;
	isEmpty=obj.isEmpty;
}
void Rooms::setRoomNo(int r) {
	roomNo=r;
}
bool Rooms::getIsEmpty() {
	return isEmpty;
}
void Rooms::setIsEmpty(bool IE) {
	isEmpty=IE;
}
int Rooms::getTotalEmptyRooms() {
	return total;
}
int Rooms::setTotalEmptyRooms(int i) {
	total=i;
}
Rooms* Customer::getRoomAlloted() {
	return roomAlloted;
}
int Rooms::getRoomNo() {
	return roomNo;
}

void Rooms::CustomerInfo( Customer& obj) {
	obj.printinfo();
}
void Rooms::UpdateRoomInfo(int rn,bool ie) {
	roomNo=rn;
	isEmpty=ie;
}
void checkAvailability(Rooms** obj,int noOfRooms) {
	cout<<endl<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	Rooms::setTotalEmptyRooms(0);
	int j=0;
	for(int i=0; i<noOfRooms; i++) {
		if(obj[i]->getIsEmpty()==true) {
			cout<<"	Room Number available: "<<obj[i]->getRoomNo()<<endl;
			Rooms::setTotalEmptyRooms(++j);
		} else {
			cout<<"	Room Number not available: "<<obj[i]->getRoomNo()<<endl;
		}
	}
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Total rooms available: "<<Rooms::getTotalEmptyRooms()<<endl;
}
Fooditems::Fooditems(int f=0,float ppi=0,string n="\0") {
	FoodId=f;
	PricePerItem=ppi;
	Name=n;
	//foodType="\0";
	//index=0;
}
float Fooditems::getPricePerItem() {
	return PricePerItem;
}
int Fooditems::getFoodId() {
	return FoodId;
}
void Fooditems::displayMenu()
{
	cout<<"Food Id: "<<FoodId<<" 	Dish: "<<Name<<"	 Price: "<<PricePerItem<<endl;
}
void Fooditems::setPricePerItem(float ppi) {
	PricePerItem=ppi;
}
void Fooditems::setName(string n) {
	Name=n;
}
string Fooditems::getName() {
	return Name;
}
orderFood::orderFood(int q=0,int i=0) {
	orderNo=i;
	quantity=q;
	//Client=new Customer;
}
void orderFood::setFoodQuantity(int q) {
	quantity=q;
}

orderFood::orderFood(int q,int i,Fooditems*F) {
	orderNo=i;
	quantity=q;
	Foodordered=new Fooditems;
	Foodordered=F;
//        Client=new Customer;
//        Client=C;
}
orderFood::orderFood(const orderFood& obj) {
	quantity=obj.quantity;
	Foodordered=new Fooditems;
	Foodordered=obj.Foodordered;
//	index=obj.index;
//	Client=new Customer;
//	Client=obj.Client;
}
int orderFood::getFoodQuantity() {
	return quantity;
}
int orderFood::getOrderNo() {
	return orderNo;
}
//Customer* orderFood::getCustomer()
//{
//	return Client;
//}
Fooditems* orderFood::getFoodOrdered() {
	return Foodordered;
}
void orderFood::setFoodOrdered(Fooditems *F) {
	Foodordered=F;
	//Select[index]=F.getFoodId();
}
//int orderFood::getIndex()
//{
//	return index;
//}
//void orderFood::setIndex(int i)
//{
//	index=i;
//}
int Bill::billNo=0;
Bill::Bill() {
	amount=0;
	billNo++;
}
float Bill::calculateRoomBill(Customer *C,Check* DT) {
	Client=C;
	float roomAmount=0;
	checkInOut=DT;
	int dayOut=(checkInOut->getDateOut()->getDay());
	int dayIn=checkInOut->getDateIn()->getDay();
	int cday=dayOut-dayIn;
	int monthOut=(checkInOut->getDateOut()->getMonth());
	int monthIn=(checkInOut->getDateIn()->getMonth());
	int cmonth=monthOut-monthIn;
	int yearOut=(checkInOut->getDateOut()->getYear());
	int yearIn=(checkInOut->getDateIn()->getYear());
	int cyear=yearOut-yearIn;
//	cout<<"Days are "<<cday;
//	cout<<"Months are "<<cmonth;
//	cout<<"Years are "<<cyear;
//	cout<<day<<" "<<month<<" "<<year<<endl;
	//cout<<int total=(day+((month-1)*30)+((year-1)*12*30));
//	amount+=(PricePerDay*days);//
//	if(day<0) {
//		if(month>0 && month<=12) {
//			roomAmount+=PricePerDay*(day+((month-1)*30));
//		} else if (month>0 && year==0) {
//			roomAmount+=PricePerDay*((day+30)+((month-1)*30));
//		} else if (month<0 && year>0) {
//			roomAmount+=PricePerDay*((day+30)+((month-1+12)*30)+((year-1)*12*30));
//		}
//
//	} else if (day>0) {
//		if(month==0 && year==0) {
//			roomAmount+=(PricePerDay*day);
//		} else if(month>0 && year==0) {
//			roomAmount+=PricePerDay*(day+((month-1)*30));
//		} else if(month>0 && year >0) {
//			roomAmount+=PricePerDay*(day+((month-1)*30)+((year-1)*12*30));
//		}
//
//	} else if (day==0) {
//		if(month>0 && year==0) {
//			roomAmount+=PricePerDay*(day+((month-1)*30));
//		} else if (month>0&& year>0) {
	roomAmount+=PricePerDay*((365*cyear) + (cyear/4) - (cyear/100 )+ (cyear/400) + cday + ((153*cmonth+8)/5));
	amount+=roomAmount;
	return roomAmount;

}
void Bill::setAmount(float n) {
	amount=n;
}
float Bill::getAmount() {
	return amount;
}
float Bill::getTaxedAmount() {
	float temp=amount;
	temp+=(tax*amount);
	return temp;
}
float Bill::calculateFoodBill(Customer *C) {
	Client=C;
	float Foodamount=0;
	int TotalOrderedFoods=C->getOrderedFoods()[0]->getFoodQuantity();
	float price=0;
	for(int i=0; i<TotalOrderedFoods; i++) {
		Foodamount+=C->getOrderedFoodItems(i)->getPricePerItem();
	}
	amount+=Foodamount;
	return Foodamount;
}
Bill operator +(Bill & rhs,Bill & lhs) {
	Bill T;
	float a=rhs.getAmount()+lhs.getAmount();
	T.setAmount(a);
	return T;
}
Bill operator -( Bill &lhs,Bill &rhs) {
	Bill T;
	T.setAmount(lhs.getAmount()-rhs.getAmount());
	return T;
}
float operator ++(Bill & obj) {
	cout<<"inside pre-increment"<<endl;
	return ++obj.amount;
}
float operator --(Bill & obj) {
	cout<<"inside pre-decrement"<<endl;
	return --obj.amount;
}
float Bill::operator ++(int) {
	cout<<"inside post-increment"<<endl;
	return amount++;
}
float Bill::operator --(int) {
	cout<<"inside post-decrement"<<endl;
	return amount--;
}

void Bill::DisplayBill() {
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------     CUSTOMER'S BILL     --------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Bill# "<<billNo<<endl;
	cout<<"Name of Customer: "<<Client->getName()<<endl;
	cout<<"Total payment(exclusive of tax): "<<Bill::getAmount()<<endl;
	cout<<"taxes applied: "<<tax<<endl;
	cout<<"Payment (inclusive of tax): "<<Bill::getTaxedAmount()<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
}
Check::Check() {

	dateIn=new DateTime;
	dateOut=new DateTime;
}
Check::Check(const Check& obj) {
	dateIn=new DateTime;
	dateOut=new DateTime;
	dateIn=obj.dateIn;
	dateOut=obj.dateOut;
}
DateTime* Check::getDateIn() {
	return dateIn;
}
DateTime* Check::getDateOut() {
	return dateOut;
}

void makeRoomEmpty(Customer &C) {
	C.getRoomAlloted()->setIsEmpty(true);
}
void Check::setDateTimeIn(int h,int m,int d,int mo,int y) {
	dateIn->setDateTime(h, m, d, mo, y);
}
void Check::setDateTimeOut(int h,int m,int d,int mo,int y) {
	dateOut->setDateTime(h, m, d, mo, y);
}

