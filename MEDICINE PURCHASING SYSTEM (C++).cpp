/*NAME : MUHAMMAD AKHMAL , RIZALIFF NABIL, NIK YUSUF, AHMAD BENJAMIN
  DATE : 17/01/23 - 06/02/23
  TITLE: MEDICINE PURCHASING SYSTEM
*/
#include <iostream> //start   
#include <iomanip>   //setprecision
#include <windows.h>  //sleep
#include <conio.h>  //getch
#include <math.h>  //fabs()
using namespace std;
//FUNCTION FOR ADMIN
void adminPage();
void adminMenu();
void adminTot();
void adminAvg();
void adminLogout();

//FUNCTION FOR USER
void studentPage();
void guestPage();
void studentMenu();
void studLogout();

//FUNCTION FOR PROBLEM
void head();
void eyes();
void nose();
void drymouth();
void throat();
void stomach();

//FUNCTION FOR CALCULATE & ENDTASK
double calculatePrice(double,int);
void terminates();
void payment();
void receipt(string, double);                                                   
void block();

//GLOBAL VARIABLES
string product[3];
int quantity[3];
double prices[3];
double totAdmin = 0, totCust, totAvg;
int custCount = 0, count;
char mainCode;

//FUNCTION CALL (MAIN)
int main()
{
	do{
		count = 0;
		totCust = 0;
		cout<<fixed<<setprecision(2);
		cout <<"Welcome To Meidicine Purchasing System !"<<endl;
		cout<<"\n"<<endl;
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |              MAIN MENU                  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  A   |               ADMIN                     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  B   |            UITM STUDENT                 |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  C   |               GUEST                     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  X   |            EXIT PROGRAM                 |"<<endl;
		cout<<"+================================================+"<<endl;	
		
		cout << "Enter a VALID code above : ";
		cin >> mainCode;
		
	
		if (toupper(mainCode) == 'A')
			adminPage();
		else if (toupper(mainCode) == 'B'){
			studentPage();
		}
		else if (toupper(mainCode) == 'C')
			guestPage();
		else if (toupper(mainCode) == 'X'){
			terminates();
	}
		else{
			cout<<"\nEnter a VALID option! "<<endl;
			Sleep(2000);
			system("cls");
			}
	}while (toupper(mainCode) != 'A'&& toupper(mainCode) != 'B'&& toupper(mainCode) != 'C'&& toupper(mainCode) != 'X');  //REPEATED UNTIL FALSE
	return 0 ;
}
//FUNCTION DEFINITION
void adminPage(){		
		char proceed;
		string username = "123" , password = "gempuck";
		string user, pass;
		int i = 0;    //FOR LOOPING
		int j = 2;
	
	while (username != user && password != pass, i<3)   // ATTEMPT LESS THAN 3 TIMES
	{
		system("cls");
		cout<<" ADMIN LOGIN PAGE                                "<<endl;
		cout<<"-------------------------------------------------"<<endl;
		cout<<" USERNAME : "; cin>>user;                   
		cout<<" PASSWORD : "; cin>>pass; 
		i++;
		
		
		if(username != user || password != pass)
		{
			cout << "\n Invalid username or password! Try again..."<<endl;
			cout<<" You Only Have "<<j<< " Attempt Left."<<endl;
			j--;
			Sleep(2000);
		}
		else {
			 i=3;
		}
	}
	if(username == user && password == pass){
			cout<<"\n Login Successful !"<<endl;
			cout<<" Redirecting to Admin Menu..." <<endl;
			Sleep(3000);
			adminMenu();
		}
	else
		block();
}
void studentPage(){
	string username = "123" , password = "123";
	string user, pass;
	int i = 0;    //FOR LOOPING
	int j = 2;
	
	while (username != user && password != pass, i<3)   // ATTEMPT LESS THAN 3 TIMES
	{
		system("cls");
		cout<<" STUDENT UITM LOGIN PAGE (I-STUDENT)             "<<endl;
		cout<<"-------------------------------------------------"<<endl;
		cout<<" STUDENT ID : "; cin>>user;                   
		cout<<" PASSWORD   : "; cin>>pass; 
		i++;
		
	
		if(username != user || password != pass)
		{
			cout << "\n Invalid username or password! Try again..."<<endl;
			cout<<" You Only Have "<<j<< " Attempt Left."<<endl;
			j--;
			Sleep(2000);
		}
		else {
			 i=3;
		}
	}
	if(username == user && password == pass){
			cout<<"\n Login Successful !"<<endl;
		cout<<" Redirecting to Purchasing Menu..."<<endl;
			Sleep(3000);
			studentMenu(); 
		}
	else
		block();
}

void guestPage(){
	system("cls");
	char name[50];
	cout<<" GUEST LOGIN PAGE          				        "<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<" NICKNAME : "; 
	cin.ignore(1024,'\n');
	cin.getline(name, 50);  //COPY ALL INPUT
	cout<<"\nHi, "<< name <<". Enjoy your shopping!"<<endl;
	cout<<"Redirecting to Purchasing Page..."<<endl;
	Sleep(3000);
	studentMenu();
}
//FUNCTION FOR ADMIN
void adminMenu(){
	system("cls");
	char adminCode;
	do{
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |             ADMIN MENU                  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  A   |             TOTAL SALES                 |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  B   |            AVERAGE SALES                |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  X   |          LOG OUT ADMIN PAGE             |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Enter a VALID code above : ";
		cin>>adminCode;
	
		if(toupper(adminCode) == 'A')
			adminTot();
		else if(toupper(adminCode) == 'B')
			adminAvg();
		else if(toupper(adminCode) == 'X')
			adminLogout();
		else{
			cout<<"\nInvalid CODE !. Please enter the correct one."<<endl;
			Sleep(2000);
			system("cls");
			}
	}while (toupper(adminCode) != 'A'&& toupper(adminCode) != 'B'&& toupper(adminCode) != 'X'); //REPEATED UNTIL FALSE
	
}
void adminTot(){
	system("cls");
	cout<<"MEDICINE SALES REPORT"<<endl;
	cout<<"\n+================================================+"<<endl;
	cout<<"| TOTAL SALES     |           RM" << totAdmin << "            |"<<endl;
	cout<<"+================================================+"<<endl;
	
	cout<<"\nPress any key to return to admin menu : ";
	getch();
	adminMenu();
}
void adminAvg(){
	system("cls");
	cout<<"MEDICINE SALES REPORT"<<endl;
	cout<<"\n+================================================+"<<endl;
	cout<<"| AVERAGE SALES   |           RM" << totAdmin / custCount << "            |"<<endl;
	cout<<"+================================================+"<<endl;
	
	cout<<"\nPress any key to return to admin menu : ";
	getch();
	adminMenu();
}
void adminLogout(){
	char option;
	system("cls");
	cout<<"+===================================================+"<<endl;
	cout<<"|     WARNING! ARE YOU SURE YOU WANT TO LOGOUT?     |"<<endl;
	cout<<"|       You will be redirected to Main Page.        |" <<endl;
	cout<<"| Username and Password are required to login again.|" <<endl;
	cout<<"|---------------------------------------------------|"<<endl;
	cout<<"|          [Y] - Yes     |     [N] - No             |"<<endl;
	cout<<"+===================================================+"<<endl;
	
	cout<<"\nPress [Y] or [N] : ";
	cin>>option;

	if(toupper(option) == 'Y'){
		system("cls");
		cout<<"Loging out..."<<endl;
		cout<<"Redirecting to Main Page..."<<endl;
		Sleep(3000);
		system("cls");
		main();
	}
	else if(toupper(option) == 'N'){
	  adminMenu();
	}
	else{
		cout<<"\nEnter a VALID option! "<<endl;
		Sleep(2000);
		adminLogout();	
	}
}
//FUCNTION FOR USER
void studentMenu(){
	system("cls");
	char studCode, proceed;
	while (count < 3){
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |             PROBLEM PART                |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  A   |                HEAD                     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  B   |                EYES                     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  C   |                NOSE                     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  D   |              DRY MOUTH                  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  E   |               THROAT                    |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  F   |               STOMACH                   |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  X   |              MAIN MENU                  |"<<endl;
		cout<<"+================================================+"<<endl;
		cout<<"\t***LIMIT TO 3 PRODUCTS ONLY***" << endl;	
		
		cout<<"\nEnter a VALID code above : ";
		cin>>studCode;
	
		if(toupper(studCode) == 'A')
			head();
		else if(toupper(studCode) == 'B')
			eyes();
		else if(toupper(studCode) == 'C')
			nose();
		else if(toupper(studCode) == 'D')
			drymouth();
		else if(toupper(studCode) == 'E')
			throat();
		else if(toupper(studCode) == 'F')
			stomach();
		else if(toupper(studCode) == 'X')
			studLogout();
		else{
			cout<<"Enter a VALID code! "<<endl;
			Sleep(2000);
			studentMenu();
		}
		
		cout<<"Press [Y] to continue buying or any key to pay : ";
		cin>>proceed;
		
		if(toupper(proceed) == 'Y')
			studentMenu();
		else
			payment();	
		}
	cout << "YOU HAVE REACHED THE PRODUCT LIMIT" << endl;
	cout << "Press any key to continue." << endl;
	getch();
	cout << "Redirecting to Payment..." << endl; Sleep(2000);
	payment();
}

//FUNCTION FOR PROBLEM PART
void head(){
	int qty,option;
	double price,total;
	do{
		system("cls");
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   |     PANADOL ACTIFAST    |      9.90     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   |     PANADOL EXTEND      |      6.00     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  3   |     UPHAMOL 650MG       |      5.70     |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"\nEnter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 9.90;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "PANADOL ACTIFAST";
		}
		else if(option == 2){
			price = 6.00;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "PANADOL EXTEND";
		}
		else if(option == 3){
			price = 5.70;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "UPHAMOL 650MG";
		}
		else{													
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2 && option !=3);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
void eyes(){
	int option,qty;
	double price,total;
	do{
		system("cls");
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   |         EYE MO          |      6.40     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   |     ROHTO COOL EYE      |      27.80    |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  3   |   SYSTANE EYE DROPS     |      10.90    |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Enter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 6.40;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "EYE MO";
		}
		else if(option == 2){
			price = 27.80;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "ROHTO COOL EYE";
		}
		else if(option == 3){
			price = 10.90;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "SYSTANE EYE DROPS";
		}
		else{													
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2 && option !=3);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
void nose(){
	int option, qty;
	double price,total;
	do{
		system("cls");
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   |     HURIX'S FLUAWAY     |      11.90    |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   |     PANADOL SOLUBLE     |      3.40     |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Enter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 11.90;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "HURIX'S FLUAWAY";
		}
		else if(option == 2){
			price = 3.40;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "PANADOL SOLUBLE";
		}
		else{													
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
void drymouth(){
	int option, qty;
	double price,total;
	do{
		system("cls");
		cout<<"+===============================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   | VASELINE LIPS CARE ROSE |     10.20     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   | NIVEA LIP GLOW LAVENDER |      6.50     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  3   |    LANEIGE LIP BALM     |      4.70     |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Enter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 10.20;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "VASELINE LIPS CARE ROSE";
		}
		else if(option == 2){
			price = 6.50;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "NIVEA LIP GLOW LAVENDER";
		}
		else if(option == 3){
			price = 4.70;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "LANEIGE LIP BALM";
		}
		else{														
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2 && option !=3);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
void throat(){
	int option,qty;
	double price,total;
	do{
		system("cls");
		cout<<"+===============================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   |    WOOD'S PEPPERMINT'   |      2.70     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   |    DIFFLAM AB(LEMON)    |      4.80     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  3   |     STREPSILS (COLD)    |      5.10     |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Enter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 2.70;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "WOOD'S PEPPERMINT'";
		}
		else if(option == 2){
			price = 4.80;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "DIFFLAM AB(LEMON)";
		}
		else if(option == 3){
			price = 5.10;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "STREPSILS(COLD)";
		}
		else{														
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2 && option !=3);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
void stomach(){
	int option,qty;
	double price,total;
	do{
		system("cls");
		cout<<"+===============================================+"<<endl;
		cout<<"| CODE |          BRAND          |    PRICE(RM)  |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  1   |  PIL CHIK-KIT TECK AUN  |      2.50     |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  2   | MINYAK YUYEE CAP LIMAU  |      9.60     |"<<endl;
		cout<<"+================================================+"<<endl;	
		
		cout<<"Enter a VALID code above : ";
		cin>>option;
		cout<<"Enter a quantity : ";
		cin>>qty;
		
		if(option == 1){
			price = 2.50;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "PIL CHIK-KIT TECK AUN";
		}
		else if(option == 2){
			price = 9.60;
			total = calculatePrice(price,qty);
			prices[count] = total;
			product[count] = "MINYAK YUYEE CAP LIMAU";
		}
		else{														
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(option != 1 && option !=2);
	totCust += total;
	cout<<"You Have Select "<<product[count]<<" with "<<qty<<" quantity has been recorded"<<endl;
	cout<<"Price : RM "<<total<<endl;
	cout<<"Total in cart : RM "<<totCust<<endl;
	quantity[count] = qty;
	count++;
}
//FUNCTION OF CALCULATION PRICE
double calculatePrice(double price, int quantity){
	return price * quantity;
}
//ADDITIONAL FUCNTION
void studLogout(){
	char option;
	system("cls");
	cout<<"+===================================================+"<<endl;
	cout<<"|     WARNING! ARE YOU SURE YOU WANT TO LOGOUT?     |"<<endl;
	cout<<"|       You will be redirected to Main Page.        |" <<endl;
	cout<<"| Username and Password are required to login again.|" <<endl;
	cout<<"|---------------------------------------------------|"<<endl;
	cout<<"|          [Y] - Yes     |     [N] - No             |"<<endl;
	cout<<"+===================================================+"<<endl;
	
	cout<<"Press Y to return to main menu : ";
	cin>>option;

	if(toupper(option) == 'Y'){
		
		system("cls");
		cout<<"Loging out..."<<endl;
		cout<<"Redirecting to Main Page..."<<endl;
		Sleep(3000);
		system("cls");
		main();
	}
	else{
	  studentMenu();
	}
}
void terminates(){
	system("cls");
	char option;
	cout<<"+===================================================+"<<endl;
	cout<<"|  WARNING! ARE YOU SURE YOU WANT TO EXIT PROGRAM?  |"<<endl;
	cout<<"|            This Action Can Not Be Undone          |"<<endl;
	cout<<"|---------------------------------------------------|"<<endl;
	cout<<"|          [Y] - Yes     |     [N] - No             |"<<endl;
	cout<<"+===================================================+"<<endl;
	cout<<"\nPress [Y/N]: ";
	cin>>option;
	
	if(toupper(option) == 'Y'){
		system("cls");
		cout<<"Exit program..."<<endl;
		cout<<"Please wait a second."<<endl;
		Sleep(3000);
		system("cls");
		cout<<"+===================================================+"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|         THIS PROGRAM HAVE BEEN TERMINATED !       |"<<endl;
		cout<<"|                                                   |"<<endl;	
		cout<<"+===================================================+"<<endl;
		abort();  //to prevent from abnormal end of the program
	}
	else if (toupper(option) == 'N'){
		system("cls");
		main();
	}
	else{
		cout<<"\nEnter a VALID option! "<<endl;
		Sleep(2000);
		terminates();
	}		
}
void payment(){   
	char method;
	double discount;
	string code[4] = {"TNG E-WALLET (5% DISCOUNT)", "QR PAY (3% DISCOUNT)", "ONLINE BANKING (2% INTEREST)", "CASH"};
	do{
		system("cls");
		cout<<"+================================================+"<<endl;
		cout<<"| CODE |           PAYMENT METHOD                |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  A   |       TNG E-WALLET (5% DISCOUNT)        |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  B   |         QR PAY (3% DISCOUNT)            |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  C   |      ONLINE BANKING (2% INTEREST)       |"<<endl;
		cout<<"|------------------------------------------------|"<<endl;
		cout<<"|  D   |                CASH                     |"<<endl;
		cout<<"+================================================+"<<endl;
		
		cout<<"Choose payment method CODE that you prefer : ";
		cin>>method;
		
		if(toupper(method) == 'A'){
		  	discount= 0.05;
		 	receipt(code[0], discount);    								
		}
		else if(toupper(method) == 'B'){
		 	discount= 0.03;
		 	receipt(code[1], discount);
		}
		else if (toupper(method) == 'C'){
			discount= -0.02;
		 	receipt(code[2], discount);
		}
		else if (toupper(method) == 'D'){
		    discount= 0.00;
		 	receipt(code[3], discount);  //CALLING ARRAY TO FUNCTION RECEIPT
		}
		else{
			cout<<"Invalid CODE !. Please enter the correct one."<<endl;
			cout<<"Refreshing the page..."<<endl;
			Sleep(3000);
		}
	}while(toupper(method) != 'A' && toupper(method) != 'B' && toupper(method) != 'C' && toupper(method) != 'D');
}
void receipt(string code, double discount){     
	double tax, totTax;
	if (toupper(mainCode)=='B') {
		totTax = 0;
		tax = 0;
	}
	else{
		totTax = totCust * 0.06;
		tax = 0.06;
	}
	double totDiscount = totCust * discount;   // CALCULATION FOR DISCOUNT
	double rTotal = totCust + totTax - totDiscount;  //MINUS & PLUS CALCULATION
	cout <<"\n\n";
	cout <<"=====================================================================" << endl;
	cout << "RECEIPT PURCHASING AT MEDICINE PURCHASING SYSTEM" << endl;
	cout <<"=====================================================================" << endl;
	cout << "1. " << product[0] <<endl;
	cout << "    QTY: " << quantity[0] << "\t << PRICE: " << prices[0] << endl;
	cout <<"---------------------------------------------------------------------" << endl;
	cout << "2. " << product[1] <<endl;
	cout << "    QTY: " << quantity[1] << "\t << PRICE: " << prices[1] << endl;
	cout <<"---------------------------------------------------------------------" << endl;
	cout << "3. " << product[2] <<endl;
	cout << "    QTY: " << quantity[2] << "\t << PRICE: " << prices[2] << endl;
	cout <<"---------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t         << TOTAL(RM): " << totCust << endl;
	cout <<"=====================================================================" << endl;
	cout << "\n";
	cout << "You Have Choose "<< code << " As Your Payment Method."<<endl;   
	cout << "TAX (" << tax * 100 << "%) : RM" << totTax << endl;   //CALCULATION FOR TAX
	cout << "DISCOUNT / CHARGE : RM" << fabs(totDiscount)<< endl;              //fabs (CHANGE TO POSITIVE WITH FLOATING NUMBER
	cout << "NEW TOTAL : RM" << rTotal << endl;

	totAdmin+=rTotal;
	custCount++;
	cout << "THANK YOU FOR PURCHASING!" << endl;
	cout << "\nPress any key to return to main menu..."<<endl;
	getch();
	cout<<"Redirecting to Main Menu..."<<endl;
	Sleep(2000);
	system("cls");
	main();
}
void block(){
	system("cls");
		cout<<"+===================================================+"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|               YOU HAVE BEEN BLOCKED !             |"<<endl;
		cout<<"|          PLEASE CONTACT YOUR ADMINISTRATOR        |"<<endl;
		cout<<"|                                                   |"<<endl;	
		cout<<"+===================================================+"<<endl;
}
