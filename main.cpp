#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void setcolor(unsigned short color) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void gotoxy(short x, short y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int number_Seller = 2;
int number_Student = 2;
int number_Product = 1;
int number_discount = 0;
int number_cart = 0;
int input_Seller;
int input_Student;
int number_product_Seller[4] = { 1,0,0,0 };
int increase_money_bag;
int active_discount[5];
int zero = 0;
int u = 0;
int sum = 0;
int sum2 = 0;
int price1;
int factor_number = 0;
struct {
	string name = "yashar";
	string family = "amirloo";
	string username = "1234";
	string password = "yasharqwerty";
	int Balance = 1000;

}Admin;

struct {
	string name;
	string family;
	string username;
	string password;
	int money_bag;

}Seller[5];

struct {
	string name;
	string family;
	string digit_student;
	string password;
	int money_bag;
}Student[5];


enum category { food, book, entertarinment, kids, cleaning };

struct {

	int id;
	string name;
	string Description;
	string username_seller;
	int range;
	int capacity;
	int discount_percent;
	category Category;

}Product[21];



int enum_quality[20];



struct {

	string code_discount;
	int number;
	int Active_or_inactive;
	int persent;
}discount[5];



struct {
	string digit_student_Cart;
	string id_seller_product[20];
	int range_product[20];
	int number_product[20];
	int category_product[20];
}Cart;

enum Status{ Paid , Delivered_to_the_post_office};
struct {
	string id_buyer;	
	int number_product;
	int category_product;
	int address;
	int code_post;
	int Payment_code;
	int range_Payment;
	Status status;
}factor[20];

// functions of admin
void student();
void admin();
void seller();
void show_profile_Admin();
void edit_profile_Admin();
void add_Seller();
void show_Seller();
void change_Seller();
void delete_Seller();
void add_Student();
void show_Student();
void change_Student();
void delete_Student();
void add_Product();
void show_Product();
void change_Product();
void delete_Product();
void create_discount_code();
void to_take_care_of_factor();
void file_project();

// functions of seller
void add_Product_Seller();
void delete_Product_Seller();
void show_profile_Seller();
void edit_Seller();
void see_all_product_him();
void add_discount_percent_for_pruduct_him();

// functions of student
void show_profile_student();
void edit_student();
void show_all_product_with_enum();
void search_all_product_with_name();
void add_Cart();
void buy_product_add_Cart();
void ability_increase_money_bag();
void see_history_buy();
void see_discounts();
void Factor();
void project_file();
int main() {


	Seller[0].name = "sina";
	Seller[0].family = "nejadasadi";
	Seller[0].username = "11111";
	Seller[0].password = "sinaqwerty";
	Seller[0].money_bag = 1000;


	Seller[1].name = "arsham";
	Seller[1].family = "shyralyzade";
	Seller[1].username = "22222";
	Seller[1].password = "arshamqwerty";
	Seller[1].money_bag = 1000;


	Student[0].name = "arash";
	Student[0].family = "amiri";
	Student[0].digit_student = "11111111";
	Student[0].password = "qqqq";
	Student[0].money_bag = 100;


	Student[1].name = "reyhane";
	Student[1].family = "dehghan";
	Student[1].digit_student = "22222222";
	Student[1].password = "wwww";
	Student[1].money_bag = 200;


	Product[0].id = 1;
	Product[0].name = "chytoz";
	Product[0].Description = "porotein";
	Product[0].range = 15;
	Product[0].capacity = 201;
	Product[0].discount_percent = 0;
	Product[0].username_seller = "11111";
	Product[0].Category = food;

	while (true) {

		cout << "Admin  or  Seller  or  Student  or exit " << '\n';
		string input_menu;
		cin >> input_menu;

		if (input_menu == "Admin") {
			admin();

		}
		else
			if (input_menu == "Seller") {
				seller();
			}
			else
				if (input_menu == "Student") {
					student();
				}
				else
					if (input_menu == "exit") {
						break;
					}
					else
					{
						setcolor(4);
						cout << "error" << '\n';
						setcolor(7);
					}

	}

	return 0;
}

void admin() {
	while (true) {
		cout << "write username and password Admin" << '\n';
		string input_password_menu;
		string input_id_Admin;

		cin >> input_id_Admin;
		cin >> input_password_menu;

		if (Admin.username != input_id_Admin || Admin.password != input_password_menu)
		{
			setcolor(4);
			cout << "username and password Admin can't match because they are invalid " << '\n';
			setcolor(7);
		}
		else
		{
			break;
		}

	}

	while (true) {
		setcolor(1);
		cout << "1. show profile himself" << '\n';
		cout << "2. edit profile himself" << '\n';

		setcolor(2);
		cout << "3. add Seller" << '\n';
		cout << "4. show Seller" << '\n';
		cout << "5. change Seller" << '\n';
		cout << "6. delete Seller" << '\n';

		setcolor(6);
		cout << "7. add Student" << '\n';
		cout << "8. show Student" << '\n';
		cout << "9. change Student" << '\n';
		cout << "10. delete Student" << '\n';

		setcolor(5);
		cout << "11. add Product" << '\n';
		cout << "12. show Product" << '\n';
		cout << "13. change Product" << '\n';
		cout << "14. delete Product" << '\n';
		setcolor(7);
		cout << "15. create_discount_code" << '\n';
		cout << "16. to take care of factor" << '\n';
		cout << "17. file project :))" << '\n';
		cout << "18. back main menu" << '\n';
		string conformation;
		cin >> conformation;
		if (conformation == "1")show_profile_Admin();
		else if (conformation == "2")edit_profile_Admin();
		else if (conformation == "3")add_Seller();
		else if (conformation == "4")show_Seller();
		else if (conformation == "5")change_Seller();
		else if (conformation == "6")delete_Seller();
		else if (conformation == "7")add_Student();
		else if (conformation == "8")show_Student();
		else if (conformation == "9")change_Student();
		else if (conformation == "10")delete_Student();
		else if (conformation == "11")add_Product();
		else if (conformation == "12")show_Product();
		else if (conformation == "13")change_Product();
		else if (conformation == "14")delete_Product();
		else if (conformation == "15")create_discount_code();
		else if (conformation == "16")to_take_care_of_factor();
		else if (conformation == "17")file_project();
		else if (conformation == "18")break;
		else
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
		}
	}

}

void seller() {

	while (true) {

		
		cout << "which Seller you are?" << '\n';
		cin >> input_Seller;
		if (input_Seller >= 1 && input_Seller <= number_Seller) {
			cout << "write username and password Seller" << '\n';
			string input_password_menu;
			string input_id_seller;

			cin >> input_id_seller;
			cin >> input_password_menu;

			if (Seller[input_Seller -1].username != input_id_seller || Seller[input_Seller -1].password != input_password_menu)
			{
				setcolor(4);
				cout << "username and password Seller can't match because they are invalid " << '\n';
				setcolor(7);
			}
			else
			{
				break;
			}

		}
		else
		{
			setcolor(4);
			cout << "we dont have this seller" << '\n';
			setcolor(7);
		}

	}



	while (true) {
		setcolor(1);
		cout << "1. add product him" << '\n';
		cout << "2. delete product him" << '\n';

		setcolor(2);
		cout << "3. show profile" << '\n';
		cout << "4. edit Seller" << '\n';

		setcolor(6);
		cout << "5. see all product him " << '\n';
		cout << "6. add discount_percent for pruduct him" << '\n';
		cout << "7. back main menu" << '\n';
		setcolor(7);
		string conformation;
		cin >> conformation;
		if (conformation == "1")add_Product_Seller();
		else if (conformation == "2")delete_Product_Seller();
		else if (conformation == "3")show_profile_Seller();
		else if (conformation == "4")edit_Seller();
		else if (conformation == "5")see_all_product_him();
		else if (conformation == "6")add_discount_percent_for_pruduct_him();
		else if (conformation == "7")break;
		else
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
		}

	}

}

void student() {

	while (true) {

		cout << "which Student you are?" << '\n';
		cin >> input_Student;
		if (input_Student >= 1 && input_Student <= number_Student) {
			cout << "write username and password Seller" << '\n';

			string input_password_menu;
			string input_id_student;

			cin >> input_id_student;
			cin >> input_password_menu;
			
			if (Student[input_Student - 1].digit_student != input_id_student || Student[input_Student - 1].password != input_password_menu)
			{
				setcolor(4);
				cout << "username and password Student can't match because they are invalid " << '\n';
				setcolor(7);
			}
			else
			{
				break;
			}

		}
		else
		{
			setcolor(4);
			cout << "we dont have this student" << '\n';
			setcolor(7);
		}

	}



	while (true) {
		setcolor(1);
		cout << "1. show profile student" << '\n';
		cout << "2. edit student" << '\n';
		cout << "3. show all product with enum" << '\n';
		setcolor(2);
		cout << "4. search all product with name" << '\n';
		cout << "5. add Cart" << '\n';
		cout << "6. buy product add Cart" << '\n';
		cout << "7. ability increase money bag" << '\n';
		setcolor(6);
		cout << "8. see history buy " << '\n';
		cout << "9. see discounts" << '\n';
		cout << "10. back main menu" << '\n';
		setcolor(7);
		string conformation;
		cin >> conformation;
		if (conformation == "1")show_profile_student();
		else if (conformation == "2")edit_student();
		else if (conformation == "3")show_all_product_with_enum();
		else if (conformation == "4")search_all_product_with_name();
		else if (conformation == "5")add_Cart();
		else if (conformation == "6")buy_product_add_Cart();
		else if (conformation == "7")ability_increase_money_bag();
		else if (conformation == "8")see_history_buy();
		else if (conformation == "9")see_discounts();
		else if (conformation == "10")break;
		else
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
		}

	}


}
void show_profile_Admin() {

	cout << "name Admin:" << Admin.name << '\n';
	cout << "family Admin:" << Admin.family << '\n';
	cout << "id Admin:" << Admin.username << '\n';
	cout << "password Admin:" << Admin.password << '\n';
	cout << "Balance Admin:" << Admin.Balance << '\n';

}

void edit_profile_Admin() {

	while (true) {
		int flag = 1;
		cout << "what a part of profile do you want to edit?" << '\n';
		cout << "name  or  family   or  password  or  Balance" << '\n';

		string conformation;
		string input;
		cin >> input;
		if (input == "name")
		{
			cout << "pelease enter new name of Admin" << '\n';
			cin >> conformation;
			Admin.name = conformation;



			while (true) {

				cout << "do you want edit one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}

		}
		else if (input == "family")
		{
			cout << "pelease enter new family of Admin" << '\n';
			cin >> conformation;
			Admin.family = conformation;



			while (true) {

				cout << "do you want edit one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}

		}
		else if (input == "password")
		{
			cout << "pelease enter new password of Admin" << '\n';
			cin >> conformation;
			Admin.password = conformation;



			while (true) {

				cout << "do you want edit one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}


		}
		else if (input == "Balance")
		{
			int input;
			cout << "pelease enter new Balance of Admin" << '\n';
			cin >> input;
			Admin.Balance = input;




			while (true) {

				cout << "do you want edit one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}


		}
		else
		{
			setcolor(4);
			cout << "error!!!!!!" << '\n';
			setcolor(7);
		}

		if (flag == 0)break;

	}


}

void add_Seller() {

	int flag = 1;

	while (true) {

		number_Seller++;
		if (number_Seller > 4)
		{
			setcolor(4);
			cout << '\n' << '\n' << "you cant add Seller because The capacity is full" << '\n' << '\n' << '\n';
			setcolor(7);
			number_Seller--;
			break;
		}


		cout << "name Seller:" << '\n';
		cin >> Seller[number_Seller - 1].name;

		cout << "family Seller:" << '\n';
		cin >> Seller[number_Seller - 1].family;




		while (true) {
			cout << "username Seller:" << '\n';
			cin >> Seller[number_Seller - 1].username;

			int b = 1;

			for (int j = 0; j < number_Seller; j++) {


				if (Seller[number_Seller - 1].username == Seller[j].username && number_Seller - 1 != j) {
					b = 0;
					break;

				}

			}

			if (Seller[number_Seller - 1].username.length() == 5 && b == 1)
			{
				break;
			}
			else {
				setcolor(4);
				cout << "Username does not match the rules of the system" << '\n';
				setcolor(7);
			}

		}

		cout << "password Seller:" << '\n';
		cin >> Seller[number_Seller - 1].password;


		cout << "money_bag Seller:" << '\n';
		cin >> Seller[number_Seller - 1].money_bag;



		cout << "do you want to add one more Seller?" << '\n';
		while (true) {

			string input;
			cin >> input;
			if (input == "no")
			{
				flag = 0;
				break;
			}
			else if (input == "yes")break;
			else {
				setcolor(4);
				cout << "invalid input###" << '\n';
				setcolor(7);
			}
		}
		if (flag == 0)break;
	}

}

void show_Seller() {

	for (int j = 0; j < number_Seller; j++) {
		cout << "***************************" << '\n';
		cout << "*  name Seller :  ";
		cout << Seller[j].name << '\n';
		cout << "*  family Seller :";
		cout << Seller[j].family << '\n';
		cout << "*  id Seller :";
		cout << Seller[j].username << '\n';
		cout << "*  password Seller :";
		cout << Seller[j].password << '\n';
		cout << "*  money_bag Seller :";
		cout << Seller[j].money_bag << '\n';
		cout << "***************************" << '\n';

	}

}

void change_Seller() {

	while (true) {
		int x;
		cout << "which Seller do you want to change?" << '\n';
		cin >> x;
		if (x >= 1 && x <= number_Seller) {
			x--;
			int flag = 1;
			cout << "what a part of profile do you want to change?" << '\n';
			cout << "name  or  family   or  password  or  money_bag" << '\n';

			string conformation;
			string input;
			cin >> input;
			if (input == "name")
			{
				cout << "pelease enter new name of Seller" << '\n';
				cin >> conformation;
				Seller[x].name = conformation;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "family")
			{
				cout << "pelease enter new family of Seller" << '\n';
				cin >> conformation;
				Seller[x].family = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "password")
			{
				cout << "pelease enter new password of Seller" << '\n';
				cin >> conformation;
				Seller[x].password = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else if (input == "money_bag")
			{


				int input;
				cout << "pelease enter new money_bag of Seller" << '\n';
				cin >> input;
				Seller[x].money_bag = input;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else
			{
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);
			}

			if (flag == 0)break;

		}
		else cout << "We do not have such a seller" << '\n';


	}

}


void delete_Seller() {






	while (true) {
		int x;
		cout << "which Seller do you want to delete?" << '\n';
		cin >> x;

		if (x >= 1 && x <= number_Seller) {
			x--;

			for (int i = x; i < number_Seller; i++) {

				Seller[i].name = Seller[i + 1].name;
				Seller[i].family = Seller[i + 1].family;
				Seller[i].username = Seller[i + 1].username;
				Seller[i].password = Seller[i + 1].password;
				Seller[i].money_bag = Seller[i + 1].money_bag;

			}
			number_Seller--;
			cout << "do you want delete one more Seller ?" << '\n';
			string edit;
			cin >> edit;
			if (edit == "no")
			{

				break;
			}
			else if (edit == "yes")break;
			else {
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);

			}

		}
		else {
			setcolor(4);
			cout << "We do not have such a seller" << '\n';
			setcolor(7);
		}


	}

}


void add_Student() {

	int flag = 1;

	while (true) {

		number_Student++;
		if (number_Student > 4)
		{
			setcolor(4);
			cout << '\n' << '\n' << "you cant add Student because The capacity is full" << '\n' << '\n' << '\n';
			setcolor(7);
			number_Student--;
			break;
		}


		cout << "name Student:" << '\n';
		cin >> Student[number_Student - 1].name;

		cout << "family Student:" << '\n';
		cin >> Student[number_Student - 1].family;

		while (true) {
			cout << "digit_student Student:" << '\n';
			cin >> Student[number_Student - 1].digit_student;
			int b = 1;

			for (int j = 0; j < number_Student; j++) {


				if (Student[number_Student - 1].digit_student == Student[j].digit_student && number_Student - 1 != j) {
					b = 0;
					break;

				}

			}

			if (Student[number_Student - 1].digit_student.length() == 8 && b == 1)
			{
				break;
			}
			else {
				setcolor(4);
				cout << "Digit_student does not match the rules of the system" << '\n';
				setcolor(7);
			}

		}

		cout << "password Student:" << '\n';
		cin >> Student[number_Student - 1].password;


		cout << "money_bag Student:" << '\n';
		cin >> Student[number_Student - 1].money_bag;



		cout << "do you want to add one more Student?" << '\n';
		while (true) {

			string input;
			cin >> input;
			if (input == "no")
			{
				flag = 0;
				break;
			}
			else if (input == "yes")break;
			else {
				setcolor(4);
				cout << "invalid input###" << '\n';
				setcolor(7);
			}
		}
		if (flag == 0)break;
	}

}
void show_Student() {
	for (int j = 0; j < number_Student; j++) {
		cout << "***************************" << '\n';
		cout << "*  name Student :  ";
		cout << Student[j].name << '\n';
		cout << "*  family Student :";
		cout << Student[j].family << '\n';
		cout << "*  digit_student Student :";
		cout << Student[j].digit_student << '\n';
		cout << "*  password Student :";
		cout << Student[j].password << '\n';
		cout << "*  money_bag Student :";
		cout << Student[j].money_bag << '\n';
		cout << "***************************" << '\n';

	}
}
void change_Student() {

	while (true) {
		int x;
		cout << "which Student do you want to change?" << '\n';
		cin >> x;
		if (x >= 1 && x <= number_Student) {
			x--;
			int flag = 1;
			cout << "what a part of profile do you want to change?" << '\n';
			cout << "name  or  family   or  password  or  money_bag" << '\n';

			string conformation;
			string input;
			cin >> input;
			if (input == "name")
			{
				cout << "pelease enter new name of Student" << '\n';
				cin >> conformation;
				Student[x].name = conformation;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "family")
			{
				cout << "pelease enter new family of Student" << '\n';
				cin >> conformation;
				Student[x].family = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}

			else if (input == "password")
			{
				cout << "pelease enter new password of Student" << '\n';
				cin >> conformation;
				Student[x].password = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else if (input == "money_bag")
			{


				int input;
				cout << "pelease enter new money_bag of Student" << '\n';
				cin >> input;
				Student[x].money_bag = input;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else
			{
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);
			}

			if (flag == 0)break;

		}
		else cout << "We do not have such a Student" << '\n';


	}

}


void delete_Student() {
	while (true) {
		int x;
		cout << "which Student do you want to delete?" << '\n';
		cin >> x;

		if (x >= 1 && x <= number_Student) {
			x--;

			for (int i = x; i < number_Student; i++) {

				Student[i].name = Student[i + 1].name;
				Student[i].family = Student[i + 1].family;
				Student[i].digit_student = Student[i + 1].digit_student;
				Student[i].password = Student[i + 1].password;
				Student[i].money_bag = Student[i + 1].money_bag;

			}
			number_Student--;
			cout << "do you want delete one more Student ?" << '\n';
			string edit;
			cin >> edit;
			if (edit == "no")
			{

				break;
			}
			else if (edit == "yes")break;
			else {
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);

			}

		}
		else {
			setcolor(4);
			cout << "We do not have such a seller" << '\n';
			setcolor(7);
		}


	}
}

void add_Product() {

	int flag = 1;

	while (true) {

		
		if (number_Product > 20)
		{
			setcolor(4);
			cout << '\n' << '\n' << "you cant add Product because The capacity is full" << '\n' << '\n' << '\n';
			setcolor(7);
			
			break;
		}

		while (true) {
			int x;
			cout << "who seller you want to add product? " << '\n';
			cin >> x;
			if (x >= 1 && x <= number_Seller) {

				while (true) {

					number_Product++;
					if (number_Product > 20)
					{
						setcolor(4);
						cout << '\n' << '\n' << "you cant add Product because The capacity is full" << '\n' << '\n' << '\n';
						setcolor(7);
						number_Product--;
						break;
					}

					while (true) {

						Product[number_Product - 1].id = rand() % 100 + 1;

						int b = 1;

						for (int j = 0; j < number_Product; j++) {


							if (Product[number_Product - 1].id == Product[j].id && number_Product - 1 != j) {
								b = 0;
								break;

							}

						}

						if (b == 1)
						{
							break;
						}

					}

					cout << "name Product:" << '\n';
					cin >> Product[number_Product - 1].name;


					cout << "Description Product:" << '\n';
					cin >> Product[number_Product - 1].Description;


					cout << "range Product:" << '\n';
					cin >> Product[number_Product - 1].range;

					cout << "capacity Product:" << '\n';
					cin >> Product[number_Product - 1].capacity;


					int l;
					cout << "categoty Product:" << '\n';
					cin >> l;
					if (l == 1) { Product[number_Product - 1].Category = book; }
					else if (l == 2) { Product[number_Product - 1].Category = entertarinment; }
					else if (l == 3) { Product[number_Product - 1].Category = kids; }
					else if (l == 4) { Product[number_Product - 1].Category = cleaning; }
					else if (l == 0) { Product[number_Product - 1].Category = food; }


					//{ food, book, entertarinment, kids, cleaning };

					number_product_Seller[x - 1]++;

					Product[number_Product - 1].username_seller = Seller[x - 1].username;

					cout << "do you want to add one more Product?" << '\n';
					while (true) {

						string input;
						cin >> input;
						if (input == "no")
						{
							flag = 0;
							break;
						}
						else if (input == "yes")break;
						else {
							setcolor(4);
							cout << "invalid input###" << '\n';
							setcolor(7);
						}
					}
					if (flag == 0)break;
				}
				if (flag == 0)break;
			}
			else
			{
				setcolor(4);
				cout << "We do not have such a seller" << '\n';
				setcolor(7);
			}
		}
		if (flag == 0)break;



	}
}

void show_Product() {

	for (int i = 0; i < number_Product; i++) {

		cout << "***************************" << '\n';
		cout << "*  name Product :  ";
		cout << Product[i].name << '\n';
		cout << "*  id Product :";
		cout << Product[i].id << '\n';
		cout << "*  Description Product :";
		cout << Product[i].Description << '\n';
		cout << "*  capacity Product :";
		cout << Product[i].capacity << '\n';
		cout << "*  range Product :";
		cout << Product[i].range << '\n';
		cout << "*  discount_percent Product :";
		cout << Product[i].discount_percent << '\n';
		cout << "***************************" << '\n';
	}

}
void change_Product() {

	while (true) {
		int x;
		cout << "which Product do you want to change?" << '\n';
		cin >> x;
		if (x >= 1 && x <= number_Product) {
			x--;
			int flag = 1;
			cout << "what a part of profile do you want to change?" << '\n';
			cout << "name  or  Description   or  capacity  or  range" << '\n';

			string conformation;
			string input;
			cin >> input;
			if (input == "name")
			{
				cout << "pelease enter new name of Product" << '\n';
				cin >> conformation;
				Product[x].name = conformation;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "Description")
			{
				cout << "pelease enter new Description of Product" << '\n';
				cin >> conformation;
				Product[x].Description = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}

			else if (input == "capacity")
			{
				int money;
				cout << "pelease enter new password of Product" << '\n';
				cin >> money;
				Product[x].capacity = money;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}


				}


			}
			else if (input == "range")
			{

				int input;
				cout << "pelease enter new money_bag of Product" << '\n';
				cin >> input;
				Product[x].range = input;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else
			{
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);
			}

			if (flag == 0)break;

		}
		else cout << "We do not have such a Product" << '\n';


	}

}
void delete_Product() {

	while (true) {

		int x;
		cout << "which Product do you want to delete?" << '\n';
		cin >> x;

		if (x >= 1 && x <= number_Product) {
			x--;

			string h;

			for (int i = x; i < number_Product; i++) {

				Product[i].name = Product[i + 1].name;
				Product[i].id = Product[i + 1].id;
				Product[i].Description = Product[i + 1].Description;
				Product[i].capacity = Product[i + 1].capacity;
				Product[i].range = Product[i + 1].range;
				Product[i].discount_percent = Product[i + 1].discount_percent;
				h = Product[i].username_seller;
				Product[i].username_seller = Product[i + 1].username_seller;
		
			}
			number_Product--;
			int n=1;
			int counter = -1;
			for (int k = 0; k < 4; k++)
			{
				counter++;
				if (Seller[k].username == h) {
					n = 0;					
					break;

				}
				
			}
			number_product_Seller[counter]--;
			cout << "do you want delete one more Product ?" << '\n';
			string edit;
			cin >> edit;
			if (edit == "no")
			{

				break;
			}
			else if (edit == "yes")break;
			else {
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);

			}

		}
		else {
			setcolor(4);
			cout << "We do not have such a Product" << '\n';
			setcolor(7);
		}

	}

}

void create_discount_code() {
	int k = 0;
	int flag = 1;
	while (true)
	{
		if (k == 5) {
			cout << "you cant add discount  code because The capacity is full";
			break;
		}
		cout << "palese enter discount code" << '\n';
		cin >> discount[k].code_discount;
		cin >> discount[k].persent;
		cin >> discount[k].number;
		cin >> discount[k].Active_or_inactive;
		number_discount++;
		string conformation;
		while (true) {
			cout << "do you want to add more discount code?" << '\n';
			cin >> conformation;
			if (conformation == "yes") {
				break;
			}
			else if (conformation == "no") {
				flag = 0;
				break;
			}else 
			{
				setcolor(4);
				cout << "error" << '\n';
				setcolor(7);
			}

		}
		if (flag == 1)k++;
		if (flag == 0)break;
	}

}
void file_project() {

	ofstream f1("Admin");

	for (int l = 0; l < 1; l++) {

		f1 << Admin.name << "     " << Admin.family << "     " << Admin.username << "      " << Admin.password << "          " << Admin.Balance << endl;
	}

	f1.close();

	ifstream f2("Admin");

	for (int l = 0; l < 1; ++l) {

		f2 >> Admin.name;
		f2 >> Admin.family;
		f2 >> Admin.username;
		f2 >> Admin.password;
		f2 >> Admin.Balance;

	}

	f2.close();


	ofstream f3("Seller");

	for (int l = 0; l < number_Seller; l++) {

		f3 << Seller[l].name << "     " << Seller[l].family << "     " << Seller[l].username << "      " << Seller[l].password << "          " << Seller[l].money_bag << endl;
	}

	f3.close();

	ifstream f4("Seller");

	for (int l = 0; l < number_Seller; l++) {

		f4 >> Seller[l].name;
		f4 >> Seller[l].family;
		f4 >> Seller[l].username;
		f4 >> Seller[l].password;
		f4 >> Seller[l].money_bag;

	}

	f4.close();


	ofstream f5("Student");

	for (int l = 0; l < number_Student; l++) {

		f5 << Student[l].name << "     " << Student[l].family << "     " << Student[l].digit_student << "      " << Student[l].password << "          " << Student[l].money_bag << endl;
	}

	f5.close();

	ifstream f6("Student");

	for (int l = 0; l < number_Student; ++l) {

		f6 >> Student[l].name;
		f6 >> Student[l].family;
		f6 >> Student[l].digit_student;
		f6 >> Student[l].password;
		f6 >> Student[l].money_bag;

	}

	f6.close();


	ofstream f7("Product");

	for (int l = 0; l < number_Product; l++) {

		f7 << Product[l].name << "     " << Product[l].id << "     " << Product[l].Description << "      " << Product[l].username_seller << "          " << Product[l].range << "          " << Product[l].capacity << "          "  <<"          " << Product[l].discount_percent << "          " << Product[l].Category <<endl;
	}

	f7.close();

	ifstream f8("Product");

	for (int l = 0; l < number_Product; ++l) {

		f8 >> Product[l].name;
		f8 >> Product[l].id;
		f8 >> Product[l].Description;
		f8 >> Product[l].username_seller;
		f8 >> Product[l].range;
		f8 >> Product[l].capacity;
		f8 >> Product[l].discount_percent;
	}

	f8.close();

	ofstream f9("discount");

	for (int l = 0; l < number_discount; l++) {

		f9 << discount[l].code_discount << "     " << discount[l].number << "     " << discount[l].Active_or_inactive << "      " << discount[l].persent  << endl;}

	f9.close();

	ifstream f10("discount");

	for (int l = 0; l < number_discount; ++l) {

		f10 >> discount[l].code_discount;
		f10 >> discount[l].number;
		f10 >> discount[l].Active_or_inactive;
		f10 >> discount[l].persent;
	
	}

	f10.close();


	ofstream f11("Cart");

	f11 << Cart.digit_student_Cart;
	for (int l = 0; l < number_cart; l++) {

		f11 << Cart.id_seller_product[l] << "     " << Cart.range_product[l] << "     " << Cart.number_product[l] << "      " << Cart.category_product[l] << endl;
	}

	f11.close();

	ifstream f12("Cart");
	f12 >> Cart.digit_student_Cart;
	for (int l = 0; l < number_cart; ++l) {

		f12 >> Cart.id_seller_product[l];
		f12 >> Cart.range_product[l];
		f12 >> Cart.number_product[l];
		f12 >> Cart.category_product[l];

	}

	f12.close();

	/*
	string id_buyer;	
	int number_product;
	int category_product;
	int address;
	int code_post;
	string Payment_code;
	int range_Payment;
	Status status;
}factor[20];
	*/
	ofstream f13("factor");

	
	for (int l = 0; l < factor_number; l++) {

		f13 << factor[l].id_buyer << "     " << factor[l].number_product << "     " << factor[l].category_product << "      " << factor[l].address << "     " << factor[l].code_post << "     " << factor[l].Payment_code <<"     " << factor[l].range_Payment  <<endl ;
	}

	f13.close();

	ifstream f14("factor");

	for (int l = 0; l < factor_number; ++l) {

		f14 >> factor[l].id_buyer;
		f14 >> factor[l].number_product;
		f14 >> factor[l].category_product;
		f14 >> factor[l].address;
		f14 >> factor[l].code_post;
		f14 >> factor[l].Payment_code;
		f14 >> factor[l].range_Payment;
	
	}

	f14.close();
}


//  this part is seller menu

void add_Product_Seller() {

	int flag = 1;

	while (true)
	{

		if (number_Product > 20)
		{
			setcolor(4);
			cout << '\n' << '\n' << "you cant add Product because The capacity is full" << '\n' << '\n' << '\n';
			setcolor(7);
			
			break;
		}

			while (true) {

				number_Product++;
				if (number_Product > 20)
				{
					setcolor(4);
					cout << '\n' << '\n' << "you cant add Product because The capacity is full" << '\n' << '\n' << '\n';
					setcolor(7);
					number_Product--;
					break;
				}

				while (true) {


					Product[number_Product - 1].id = rand() % 100 + 1;

					int b = 1;

					for (int j = 0; j < number_Product; j++) {


						if (Product[number_Product - 1].id == Product[j].id && number_Product - 1 != j) {
							b = 0;
							break;

						}

					}

					if (b == 1)
					{
						break;
					}

				}

				cout << "name Product:" << '\n';
				cin >> Product[number_Product - 1].name;


				cout << "Description Product:" << '\n';
				cin >> Product[number_Product - 1].Description;


				cout << "range Product:" << '\n';
				cin >> Product[number_Product - 1].range;

				cout << "capacity Product:" << '\n';
				cin >> Product[number_Product - 1].capacity;
				int l;
				cout << "categoty Product:" << '\n';
				cin >> l;
				if(l==1){ Product[number_Product - 1].Category = book;}
				else if (l == 2) { Product[number_Product - 1].Category = entertarinment;}
				else if (l == 3) { Product[number_Product - 1].Category = kids;}
				else if (l == 4) { Product[number_Product - 1].Category = cleaning;}
				else if (l == 0) { Product[number_Product - 1].Category = food;}


				//{ food, book, entertarinment, kids, cleaning };
				number_product_Seller[input_Seller - 1]++;

				Product[number_Product - 1].username_seller = Seller[input_Seller - 1].username;

				cout << "do you want to add one more Product?" << '\n';
				while (true) {

					string input;
					cin >> input;
					if (input == "no")
					{
						flag = 0;
						break;
					}
					else if (input == "yes")break;
					else {
						setcolor(4);
						cout << "invalid input###" << '\n';
						setcolor(7);
					}
				}
				if (flag == 0)break;
			}

			if (flag == 0)break;
	}

}

void delete_Product_Seller() {

	while (true) {
		int x;
		cout << "which Product Seller do you want to delete?" << '\n';
		cin >> x;
		//number_product_Seller[4]
		if (x >= 1 && x <= number_product_Seller[input_Seller-1]) {
			x--;

			for (int i = x; i < number_Product; i++) {

				if (Product[i].username_seller == Seller[input_Seller - 1].username) {

					Product[i].name = Product[i + 1].name;
					Product[i].id = Product[i + 1].id;
					Product[i].Description = Product[i + 1].Description;
					Product[i].capacity = Product[i + 1].capacity;
					Product[i].range = Product[i + 1].range;
					Product[i].discount_percent = Product[i + 1].discount_percent;
					Product[i].username_seller = Product[i + 1].username_seller;



				}
									
			}
			number_Product--;
			number_product_Seller[input_Seller - 1]--;
			cout << "do you want delete one more Product ?" << '\n';
			string edit;
			cin >> edit;
			if (edit == "no")
			{

				break;
			}
			else if (edit == "yes")break;
			else {
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);

			}

		}
		else {
			setcolor(4);
			cout << "We do not have such a Product" << '\n';
			setcolor(7);
		}

	}
}
void show_profile_Seller() {
	
			cout << Seller[input_Seller - 1].name << '\n';
			cout << Seller[input_Seller - 1].family << '\n';
			cout << Seller[input_Seller - 1].username << '\n';
			cout << Seller[input_Seller - 1].password << '\n';
			cout << Seller[input_Seller - 1].money_bag << '\n';
			
}
void edit_Seller() {

	while (true) {

			int flag = 1;
			cout << "what a part of profile do you want to change?" << '\n';
			cout << "name  or  family   or  password  or  money_bag" << '\n';

			string conformation;
			string input;
			cin >> input;
			if (input == "name")
			{
				cout << "pelease enter new name of Seller" << '\n';
				cin >> conformation;
				Seller[input_Seller-1].name = conformation;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "family")
			{
				cout << "pelease enter new family of Seller" << '\n';
				cin >> conformation;
				Seller[input_Seller-1].family = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}

			}
			else if (input == "password")
			{
				cout << "pelease enter new password of Seller" << '\n';
				cin >> conformation;
				Seller[input_Seller-1].password = conformation;



				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else if (input == "money_bag")
			{

				int input;
				cout << "pelease enter new money_bag of Seller" << '\n';
				cin >> input;
				Seller[input_Seller-1].money_bag = input;


				while (true) {

					cout << "do you want change one more part of profile ?" << '\n';
					string edit;
					cin >> edit;
					if (edit == "no")
					{
						flag = 0;
						break;
					}
					else if (edit == "yes")break;
					else {
						setcolor(4);
						cout << "error!!!!!!" << '\n';
						setcolor(7);
					}

				}


			}
			else
			{
				setcolor(4);
				cout << "error!!!!!!" << '\n';
				setcolor(7);
			}

			if (flag == 0)break;

		

	}
}

void see_all_product_him() {

	//{ food, book, entertarinment, kids, cleaning };
	
	cout << "which Category you determination"<<'\n';
	cout << "food  or   book  or  entertarinment   or   kids    or   cleaning  ?" << '\n';
	string input;
	cin >> input;
	if (input == "food") {

		for (int j = 0; j < number_Product; j++) {

			if (Product[j].username_seller == Seller[input_Seller - 1].username && Product[j].Category == food) {

				cout << " name Product :  ";
				cout << Product[j].name << '\n';
				cout << " id Product :";
				cout << Product[j].id << '\n';
				cout << " Description Product :";
				cout << Product[j].Description << '\n';
				cout << " capacity Product :";
				cout << Product[j].capacity << '\n';
				cout << " range Product :";
				cout << Product[j].range << '\n';
				cout << " discount_percent Product :";
				cout << Product[j].discount_percent << '\n';
				cout << "-------------------------------------------" << '\n';
			}

		}
	}
	else if (input == "book") {

		for (int j = 0; j < number_Product; j++) {

			if (Product[j].username_seller == Seller[input_Seller - 1].username && Product[j].Category == book) {

				cout << " name Product :  ";
				cout << Product[j].name << '\n';
				cout << " id Product :";
				cout << Product[j].id << '\n';
				cout << " Description Product :";
				cout << Product[j].Description << '\n';
				cout << " capacity Product :";
				cout << Product[j].capacity << '\n';
				cout << " range Product :";
				cout << Product[j].range << '\n';
				cout << " discount_percent Product :";
				cout << Product[j].discount_percent << '\n';
				cout << "-------------------------------------------" << '\n';
			}

		}

	}
	else if (input == "entertarinment") {

		for (int j = 0; j < number_Product; j++) {

			if (Product[j].username_seller == Seller[input_Seller - 1].username && Product[j].Category == entertarinment) {

				cout << " name Product :  ";
				cout << Product[j].name << '\n';
				cout << " id Product :";
				cout << Product[j].id << '\n';
				cout << " Description Product :";
				cout << Product[j].Description << '\n';
				cout << " capacity Product :";
				cout << Product[j].capacity << '\n';
				cout << " range Product :";
				cout << Product[j].range << '\n';
				cout << " discount_percent Product :";
				cout << Product[j].discount_percent << '\n';
				cout << "-------------------------------------------" << '\n';
			}

		}

	}
	else if (input == "kids") {

		for (int j = 0; j < number_Product; j++) {

			if (Product[j].username_seller == Seller[input_Seller - 1].username && Product[j].Category == kids) {

				cout << " name Product :  ";
				cout << Product[j].name << '\n';
				cout << " id Product :";
				cout << Product[j].id << '\n';
				cout << " Description Product :";
				cout << Product[j].Description << '\n';
				cout << " capacity Product :";
				cout << Product[j].capacity << '\n';
				cout << " range Product :";
				cout << Product[j].range << '\n';
				cout << " discount_percent Product :";
				cout << Product[j].discount_percent << '\n';
				cout << "-------------------------------------------" << '\n';
			}

		}

	}
	else if (input == "cleaning") {

		for (int j = 0; j < number_Product; j++) {

			if (Product[j].username_seller == Seller[input_Seller - 1].username && Product[j].Category == cleaning) {

				cout << " name Product :  ";
				cout << Product[j].name << '\n';
				cout << " id Product :";
				cout << Product[j].id << '\n';
				cout << " Description Product :";
				cout << Product[j].Description << '\n';
				cout << " capacity Product :";
				cout << Product[j].capacity << '\n';
				cout << " range Product :";
				cout << Product[j].range << '\n';
				cout << " discount_percent Product :";
				cout << Product[j].discount_percent << '\n';
				cout << "------------------------------------------" << '\n';
			}

		}

	}

}
void add_discount_percent_for_pruduct_him() {

	while (true)
	{
		int flag = 1;
		cout << "which product you want granted discount percent ? " << '\n';
		int v;
		cin >> v;
		if (v >= 1 && v <= number_product_Seller[input_Seller - 1]) {
			cout << "enter discount percent of product" << '\n';
			int g;
			cin >> g;
			Product[v - 1].discount_percent = g ;
		}
		else
		{
			setcolor(4);
			cout << "We do not have such a product" << '\n';
			setcolor(7);
		}

		cout << "do you want to add one more discount percent?" << '\n';
		while (true) {

			string input;
			cin >> input;
			if (input == "no")
			{
				flag = 0;
				break;
			}
			else if (input == "yes")break;
			else {
				setcolor(4);
				cout << "invalid input###" << '\n';
				setcolor(7);
			}
		}
		if (flag == 0)break;

	}
}
//   yasharqwerty

//  this part is Student menu
void show_profile_student() {
	
	cout << "***************************" << '\n';
	cout << "*  name Student :  ";
	cout << Student[input_Student-1].name << '\n';
	cout << "*  family Student :";
	cout << Student[input_Student-1].family << '\n';
	cout << "*  digit_student Student :";
	cout << Student[input_Student-1].digit_student << '\n';
	cout << "*  password Student :";
	cout << Student[input_Student-1].password << '\n';
	cout << "*  money_bag Student :";
	cout << Student[input_Student-1].money_bag << '\n';
	cout << "***************************" << '\n';

}
void edit_student() {
	while (true) {
		int flag = 1;
		cout << "what a part of profile do you want to change?" << '\n';
		cout << "name  or  family   or  password  or  money_bag" << '\n';

		string conformation;
		string input;
		cin >> input;
		if (input == "name")
		{
			cout << "pelease enter new name of Student" << '\n';
			cin >> conformation;
			Student[input_Student-1].name = conformation;


			while (true) {

				cout << "do you want change one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}

		}
		else if (input == "family")
		{
			cout << "pelease enter new family of Student" << '\n';
			cin >> conformation;
			Student[input_Student-1].family = conformation;



			while (true) {

				cout << "do you want change one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}

		}

		else if (input == "password")
		{
			cout << "pelease enter new password of Student" << '\n';
			cin >> conformation;
			Student[input_Student-1].password = conformation;



			while (true) {

				cout << "do you want change one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}


		}
		else if (input == "money_bag")
		{


			int input;
			cout << "pelease enter new money_bag of Student" << '\n';
			cin >> input;
			Student[input_Student-1].money_bag = input;


			while (true) {

				cout << "do you want change one more part of profile ?" << '\n';
				string edit;
				cin >> edit;
				if (edit == "no")
				{
					flag = 0;
					break;
				}
				else if (edit == "yes")break;
				else {
					setcolor(4);
					cout << "error!!!!!!" << '\n';
					setcolor(7);
				}

			}


		}
		else
		{
			setcolor(4);
			cout << "error!!!!!!" << '\n';
			setcolor(7);
		}

		if (flag == 0)break;
	}
}
void show_all_product_with_enum(){

	while (true)
	{
		cout << " who group you want to see it" << '\n';
		cout << "food  or   book  or   entertarinment   or   kids   or  cleaning  ?" << '\n';

		string input;
		cin >> input;
		if (input == "food") {

			for (int j = 0; j < number_Product; j++) {

				if (Product[j].Category == food ) {

					cout << " name Product :  ";
					cout << Product[j].name << '\n';
					cout << " id Product :";
					cout << Product[j].id << '\n';
					cout << " Description Product :";
					cout << Product[j].Description << '\n';
					cout << " capacity Product :";
					cout << Product[j].capacity << '\n';
					cout << " range Product :";
					cout << Product[j].range << '\n';
					cout << " discount_percent Product :";
					cout << Product[j].discount_percent << '\n';
					cout << "-------------------------------------------" << '\n';
				}

			}
		}
		else if (input == "book") {

			for (int j = 0; j < number_Product; j++) {

				if (Product[j].Category == book) {

					cout << " name Product :  ";
					cout << Product[j].name << '\n';
					cout << " id Product :";
					cout << Product[j].id << '\n';
					cout << " Description Product :";
					cout << Product[j].Description << '\n';
					cout << " capacity Product :";
					cout << Product[j].capacity << '\n';
					cout << " range Product :";
					cout << Product[j].range << '\n';
					cout << " discount_percent Product :";
					cout << Product[j].discount_percent << '\n';
					cout << "-------------------------------------------" << '\n';
				}

			}

		}
		else if (input == "entertarinment") {

			for (int j = 0; j < number_Product; j++) {

				if ( Product[j].Category == entertarinment) {

					cout << " name Product :  ";
					cout << Product[j].name << '\n';
					cout << " id Product :";
					cout << Product[j].id << '\n';
					cout << " Description Product :";
					cout << Product[j].Description << '\n';
					cout << " capacity Product :";
					cout << Product[j].capacity << '\n';
					cout << " range Product :";
					cout << Product[j].range << '\n';
					cout << " discount_percent Product :";
					cout << Product[j].discount_percent << '\n';
					cout << "-------------------------------------------" << '\n';
				}

			}

		}
		else if (input == "kids") {

			for (int j = 0; j < number_Product; j++) {

				if (Product[j].Category == kids) {

					cout << " name Product :  ";
					cout << Product[j].name << '\n';
					cout << " id Product :";
					cout << Product[j].id << '\n';
					cout << " Description Product :";
					cout << Product[j].Description << '\n';
					cout << " capacity Product :";
					cout << Product[j].capacity << '\n';
					cout << " range Product :";
					cout << Product[j].range << '\n';
					cout << " discount_percent Product :";
					cout << Product[j].discount_percent << '\n';
					cout << "-------------------------------------------" << '\n';
				}

			}

		}
		else if (input == "cleaning") {

			for (int j = 0; j < number_Product; j++) {

				if ( Product[j].Category == cleaning) {

					cout << " name Product :  ";
					cout << Product[j].name << '\n';
					cout << " id Product :";
					cout << Product[j].id << '\n';
					cout << " Description Product :";
					cout << Product[j].Description << '\n';
					cout << " capacity Product :";
					cout << Product[j].capacity << '\n';
					cout << " range Product :";
					cout << Product[j].range << '\n';
					cout << " discount_percent Product :";
					cout << Product[j].discount_percent << '\n';
					cout << "------------------------------------------" << '\n';
				}

			}

		}
		string input3;
		cout << "do you want to exit ?" << '\n';
		cin >> input3;
		if (input3 == "yes")break;
		else if (input3 != "yes" && input3 != "no")
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
		}

	}

}
void search_all_product_with_name(){

	while (true)
	{
		string conformation;
		cout << "palease write name of product:" << '\n';
		cin >> conformation;
		int b = 1;

		for (int i = 0; i < number_Product; i++) {

			if (conformation == Product[i].name)break;
			else b = 0;

		}
		if (b == 0) 
		{ 
			setcolor(4);
			cout << "your product not found" << '\n'; 
			setcolor(7);
		}

		for (int i = 0; i < number_Product; i++) {

			if (conformation == Product[i].name) {
				cout << "***************************" << '\n';
				cout << "*  name Product :  ";
				cout << Product[i].name << '\n';
				cout << "*  id Product :";
				cout << Product[i].id << '\n';
				cout << "*  Description Product :";
				cout << Product[i].Description << '\n';
				cout << "*  capacity Product :";
				cout << Product[i].capacity << '\n';
				cout << "*  range Product :";
				cout << Product[i].range << '\n';
				cout << "*  discount_percent Product :";
				cout << Product[i].discount_percent << '\n';
				cout << "***************************" << '\n';
			}
		}
		if (b == 1)break;
	}
	
}
void add_Cart(){
	while (true)
	{
		int flag1 = 1;
		int flag2 = 1;
		int m;
		int n;
		int input_id1, input_id2;
		string q;
		while (true)
		{
			cout << "palease enter two id product" << '\n';
			cin >> input_id1 >> input_id2;

			for (int i = 0; i < number_Product; i++) {
				if (input_id1 == Product[i].id)
				{
					flag1 = 0;
					m = i;
				}
				if (input_id2 == Product[i].id)
				{
					flag2 = 0;
					n = i;
				}
				if (flag1 == 0 && flag2 == 0)break;
			}
			if (flag1 == 1 || flag2 == 1)
			{
				setcolor(4);
				cout << "id not found" << '\n';
				setcolor(7);
			}
			if (flag1 == 0 && flag2 == 0)break;
		}
		
		if (flag1 == 0 && flag2 == 0)
		{
			cout << "***************************" << '\n';
			cout << "*  name Product :  ";
			cout << Product[m].name   << "           " << Product[n].name << '\n';
			cout << "*  id Product :";
			cout << Product[m].id << "           " << Product[n].id << '\n';
			cout << "*  Description Product :";
			cout << Product[m].Description << "            " << Product[n].Description << '\n';
			cout << "*  capacity Product :";
			cout << Product[m].capacity << "           " << Product[n].capacity << '\n';
			cout << "*  range Product :";
			cout << Product[m].range << "           " << Product[n].range << '\n';
			cout << "*  discount_percent Product :";
			cout << Product[m].discount_percent << "           " << Product[n].discount_percent << '\n';
			cout << "*  group Product :";
			cout << Product[m].Category << "           " << Product[n].Category << '\n';
			cout << "*  seller Product id:";
			cout << Product[m].username_seller << "           " << Product[n].username_seller << '\n';
			cout << "***************************" << '\n';

		}

		int l = 0,p;
		string o;
		cout << "first or second" << '\n';
		cin >> o;
		while (true)
		{
			while(true){
				cout << "how many?" << '\n';
			cin >> p;
			if (o == "first") {
				
				if (p <= Product[m].capacity) {
					
					Product[m].capacity = Product[m].capacity - p;
					Cart.id_seller_product[l] = Product[m].username_seller;
					Cart.range_product[l]= Product[m].range /  1 + (Product[m].range * Product[m].discount_percent);
					Cart.digit_student_Cart = Student[input_Student - 1].digit_student;
					Cart.number_product[l] = p;
					Cart.category_product[l] = Product[m].Category;
						number_cart++;
					break;
					
				}
				else { setcolor(4); cout << "capacity invalid" << '\n'; setcolor(7); }
			}
			else if (o == "second") {
				
				if (p <= Product[n].capacity) {
					
					Product[n].capacity = Product[n].capacity - p;
					Cart.id_seller_product[l] = Product[n].username_seller;
					Cart.range_product[l] = Product[n].range /  1 + (Product[n].range * Product[n].discount_percent) ;
					Cart.digit_student_Cart = Student[input_Student - 1].digit_student;
					Cart.number_product[l] = p;
					Cart.category_product[l] = Product[n].Category;
						number_cart++;
					break;
					
				}
				else { setcolor(4); cout << "capacity invalid" << '\n'; setcolor(7); }
			}
		
				
			}
						
			cout << "continue?" << '\n';
			cin >> q;
			if (q == "no")break;
			else if (q == "yes")break;
			else if (q != "yes" && q != "no")
			{
				setcolor(4);
				cout << "error" << '\n';
				setcolor(7);
			}
			l++;
		}	
		if(q=="no")break;
	}
}
void buy_product_add_Cart(){
	
	int counter=0, counter2=0;
		
	int z;
	int numerator;
	while (true)
	{

		sum = sum + Cart.number_product[zero] * Cart.range_product[zero];


		cout << "total price without discount:" << sum << '\n';
		string question;
		cout << "do you want to use discount code?" << '\n';

		cin >> question;
		
		if (question == "yes" && Student[input_Student - 1].money_bag > sum) {
			for (int i = 0; i < 5; i++)
			{

				if (discount[i].Active_or_inactive == 1)
				{
					cout << "code discount :" << discount[i].code_discount << '\n';
					cout << "discount number :" << discount[i].number << '\n';
					numerator++;
					
				}
			}
			
			cout << "which one?" << '\n';
			cin >> z;
			if (z >= 1 && z <= numerator) {

			if (discount[z - 1].number != 0) {

					discount[z - 1].number--;
					sum2 = sum * (discount[z - 1].persent / 100);
					cout << "total price with discount:" << sum2 << '\n';

					if (Student[input_Student - 1].money_bag < sum2) {
						setcolor(4);
						cout << "you dont have money" << '\n';
						setcolor(7);
					}
					else if(Student[input_Student - 1].money_bag > sum2) {
						
					 while(true){
                      	        
			cout << "enter money :";
			cin >> price1;
			             	
	                    if(price1==sum2){
	                    	
	                    	Admin.Balance = Admin.Balance + (price1 * 0.22);
		                 	int b = 1;
			
		 	for (int t = 0; t < 20; t++) {

				for (int y = 0; y < 4; y++) {

					if (Cart.id_seller_product[t] == Seller[y].username) { b = 0; break; }
					u++;
				}
				if (b == 0) { break; }
			}
			
			Student[input_Student - 1].money_bag = Student[input_Student - 1].money_bag - price1;
			Seller[u].money_bag = Seller[u].money_bag + (price1 * 0.88);
	                  }else {
	                  	setcolor(4);
	                  	cout << "enter correct money"<<'\n';
	                  	setcolor(7);
					  }
	 
	 if(price1==sum2)break;
	 
                  }				
				
					}
				
            
             
         }else
				{
					setcolor(4);
					cout << "the number of discount code is zero" << '\n';
					setcolor(7);
				}
			
			}

	}
		else if (question != "yes" && question != "no")
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
		}else
		if ( Student[input_Student - 1].money_bag < sum) {
			cout << "you havenot enough" << '\n';
		}
		else if (question == "no" && Student[input_Student - 1].money_bag > sum) {
			
				
                  while(true){
                      	        
			cout << "enter money :";
			cin >> price1;
			             	
	                    if(price1==sum){
	                    	
	                    	Admin.Balance = Admin.Balance + (price1 * 0.22);
		                 	int b = 1;
			
		 	for (int t = 0; t < 20; t++) {

				for (int y = 0; y < 4; y++) {

					if (Cart.id_seller_product[t] == Seller[y].username) { b = 0; break; }
					u++;
				}
				if (b == 0) { break; }
			}
			
			Student[input_Student - 1].money_bag = Student[input_Student - 1].money_bag - price1;
			Seller[u].money_bag = Seller[u].money_bag + (price1 * 0.88);
	                  }else {
	                  	setcolor(4);
	                  	cout << "enter correct money"<<'\n';
	                  	setcolor(7);
					  }
	 
	 if(price1==sum)break;
	 
                  }						

		}

		Factor();

		string h;
		cout << "continue?" << '\n';
		cin >> h;
		if (h == "no")break;
		else if (question != "yes" && question != "no")
		{
			setcolor(4);
			cout << "error" << '\n';
			setcolor(7);
        } 
        
		
		zero++;
	}

  
}
void ability_increase_money_bag(){
	cout << "enter price you want to add" << '\n';
	cin >> increase_money_bag;
	Student[input_Student - 1].money_bag = Student[input_Student - 1].money_bag + increase_money_bag;
}
void see_history_buy(){
	
  for (int j=0;j<factor_number;j++){
	
	cout << "------factor------" << '\n' << '\n';
	cout << "id buyer :" << factor[j].id_buyer <<'\n';
	cout << "number product :" << factor[j].number_product << '\n';
	cout << "category products :" << factor[j].category_product << '\n';
	cout << "address :" << factor[j].address << '\n';
	cout << "code post :" << factor[j].code_post << '\n';
	cout << "range Payment products :" << factor[j].Payment_code << '\n';
	cout << "total range:" << factor[j].range_Payment << '\n';
	cout << "status :" << factor[j].status << '\n';
	
	
  }

}
void see_discounts(){
	for (int i = 0; i < 5; i++)
	{

		if (discount[i].Active_or_inactive == 1) 
		{
			cout << "code discount :" << discount[i].code_discount << '\n';
			cout << "discount number :" << discount[i].number << '\n';

		}
	}
}
void Factor() {

	factor[u].id_buyer = Student[u].digit_student;
	factor[u].number_product = Cart.number_product[u];
	factor[u].category_product = Cart.category_product[u];
	factor[u].address = rand() % 1000 + 1;
	factor[u].code_post = rand() % 500 + 1;
	factor[u].Payment_code = rand() % 600 + 500;
	factor[u].range_Payment = price1;
	factor[u].status = Paid;


	cout << "------factor------" << '\n' << '\n';
	cout << "id buyer :" << factor[u].id_buyer <<'\n';
	cout << "number product :" << factor[u].number_product << '\n';
	cout << "category products :" << factor[u].category_product << '\n';
	cout << "address :" << factor[u].address << '\n';
	cout << "code post :" << factor[u].code_post << '\n';
	cout << "range_Payment products :" << factor[u].Payment_code << '\n';
	cout << "total range:" << factor[u].range_Payment << '\n';
	cout << "status :" << factor[u].status << '\n';
	factor_number++;
}
void to_take_care_of_factor() {
	
	
	
	

	int address;
	int flag4 = 0;
	while (true)
	{
		cout << "search the factor" << '\n';
		cin >> address;
		for (int i = 0; i < factor_number; i++) {
			if (address == factor[i].address) {
				flag4 = 1;
				break;
			}


		}
		if (flag4 == 0) {
			setcolor(4);
			cout << "factor not found" << '\n';
			setcolor(7);
		}
		if (flag4 == 1) { break; }
	}
	

	if (flag4 == 1) {

		for (int i = 0; i < factor_number; i++) {

			if (address == factor[i].address) {

				cout << "------factor------" << '\n' << '\n';
				cout << "id buyer :" << factor[i].id_buyer << '\n';
				cout << "number product :" << factor[i].number_product << '\n';
				cout << "category products :" << factor[i].category_product << '\n';
				cout << "address :" << factor[i].address << '\n';
				cout << "code post :" << factor[i].code_post << '\n';
				cout << "range_Payment products :" << factor[i].Payment_code << '\n';
				cout << "total range:" << factor[i].range_Payment << '\n';
				cout << "status :" << factor[i].status << '\n';
			
			
				string conformation;
				cout << "Delivered to the post office?" << '\n';
				cin >> conformation;
				if (conformation == "yes") 
				{ 
					factor[i].status= Delivered_to_the_post_office;
					break;
				}
				else if (conformation != "yes" && conformation != "no")
				{
					setcolor(4);
					cout << "error" << '\n';
					setcolor(7);
				}


			}
		}
		

	}

}
void project_file(){

	ofstream f1("Admin");

	for (int l = 0; l < 1; l++) {

		f1 << Admin.name << "     " << Admin.family << "     " << Admin.username << "      " << Admin.password << "          " << Admin.Balance << endl;
	}

	f1.close();

	ifstream f2("Admin");

	for (int l = 0; l < 1; ++l) {

		f2 >> Admin.name;
		f2 >> Admin.family;
		f2 >> Admin.username;
		f2 >> Admin.password;
		f2 >> Admin.Balance;

	}

	f2.close();


	ofstream f3("Seller");

	for (int l = 0; l < number_Seller; l++) {

		f3 << Seller[l].name << "     " << Seller[l].family << "     " << Seller[l].username << "      " << Seller[l].password << "          " << Seller[l].money_bag << endl;
	}

	f3.close();

	ifstream f4("Seller");

	for (int l = 0; l < number_Seller; l++) {

		f4 >> Seller[l].name;
		f4 >> Seller[l].family;
		f4 >> Seller[l].username;
		f4 >> Seller[l].password;
		f4 >> Seller[l].money_bag;

	}

	f4.close();


	ofstream f5("Student");

	for (int l = 0; l < number_Student; l++) {

		f5 << Student[l].name << "     " << Student[l].family << "     " << Student[l].digit_student << "      " << Student[l].password << "          " << Student[l].money_bag << endl;
	}

	f5.close();

	ifstream f6("Student");

	for (int l = 0; l < number_Student; ++l) {

		f6 >> Student[l].name;
		f6 >> Student[l].family;
		f6 >> Student[l].digit_student;
		f6 >> Student[l].password;
		f6 >> Student[l].money_bag;

	}

	f6.close();


	ofstream f7("Product");

	for (int l = 0; l < number_Product; l++) {

		f7 << Product[l].name << "     " << Product[l].id << "     " << Product[l].Description << "      " << Product[l].username_seller << "          " << Product[l].range << "          " << Product[l].capacity << "          "  <<"          " << Product[l].discount_percent << "          " << Product[l].Category <<endl;
	}

	f7.close();

	ifstream f8("Product");

	for (int l = 0; l < number_Product; ++l) {

		f8 >> Product[l].name;
		f8 >> Product[l].id;
		f8 >> Product[l].Description;
		f8 >> Product[l].username_seller;
		f8 >> Product[l].range;
		f8 >> Product[l].capacity;
		f8 >> Product[l].discount_percent;
	}

	f8.close();

	ofstream f9("discount");

	for (int l = 0; l < number_discount; l++) {

		f9 << discount[l].code_discount << "     " << discount[l].number << "     " << discount[l].Active_or_inactive << "      " << discount[l].persent  << endl;}

	f9.close();

	ifstream f10("discount");

	for (int l = 0; l < number_discount; ++l) {

		f10 >> discount[l].code_discount;
		f10 >> discount[l].number;
		f10 >> discount[l].Active_or_inactive;
		f10 >> discount[l].persent;
	
	}

	f10.close();


	ofstream f11("Cart");

	f11 << Cart.digit_student_Cart;
	for (int l = 0; l < number_cart; l++) {

		f11 << Cart.id_seller_product[l] << "     " << Cart.range_product[l] << "     " << Cart.number_product[l] << "      " << Cart.category_product[l] << endl;
	}

	f11.close();

	ifstream f12("Cart");
	f12 >> Cart.digit_student_Cart;
	for (int l = 0; l < number_cart; ++l) {

		f12 >> Cart.id_seller_product[l];
		f12 >> Cart.range_product[l];
		f12 >> Cart.number_product[l];
		f12 >> Cart.category_product[l];

	}

	f12.close();


	ofstream f13("factor");

	
	for (int l = 0; l < factor_number; l++) {

		f13 << factor[l].id_buyer << "     " << factor[l].number_product << "     " << factor[l].category_product << "      " << factor[l].address << "     " << factor[l].code_post << "     " << factor[l].Payment_code <<"     " << factor[l].range_Payment  <<endl ;
	}

	f13.close();

	ifstream f14("factor");

	for (int l = 0; l < factor_number; ++l) {

		f14 >> factor[l].id_buyer;
		f14 >> factor[l].number_product;
		f14 >> factor[l].category_product;
		f14 >> factor[l].address;
		f14 >> factor[l].code_post;
		f14 >> factor[l].Payment_code;
		f14 >> factor[l].range_Payment;
	
	}

	f14.close();
}


