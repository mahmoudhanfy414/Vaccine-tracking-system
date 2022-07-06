#include "System.h"
#include<queue>
using namespace std;

void System::Set_User_At_First_Dose_List(User user)
{
	this->First_Dose_List.push(user);

}

queueArr<User>System::First_Dose_List;

unordered_map<string, User>System::users;

unordered_map<string, Admin>System::Admins;
queueArr<User>System::Second_Dose_List;



User System::Get_User_From_First_Dose_List()
{

	User user;
	user = this->First_Dose_List.Front();
	if (user.get_gender() == "Female") {
		user.count_Female--;
	}
	else if ("Male")
	{
		user.count_male--;
	}
	this->First_Dose_List.pop();



	return user;
}

System::~System()
{
}

bool System::Check_id_is_Unique(User user) // it isnot have any benfit bocouse we check the id in (taking information) function 
{
	int flag = 0;

	if (this->users.find(user.get_id()) != users.end()) {
		cout << "\t""Account Already Exists !" << endl;
		user.helper_for_counters(1);//????
		cout << endl;
		string ans;
		while (true)
		{
			cout << "\t""If you want to see your account press 1:-" << " "; cin >> ans;
			cout << endl;
			if (ans == "1") {
				this->users[user.get_id()].Display(0);

				break;
			}

			else
			{
				cout << "\t""Please Enter 1 only " << endl;
				cout << endl;
				continue;
			}
		}
		flag = 0;
	}
	else
	{
		flag = 1;
	}

	return flag;

}//

void System::check_vaccine(User& user)
{

	/*if (!this->Check_id_is_Unique(user)) {
		return;
	}*/
	
		if (user.vaccine.vac == "1")
		{
			cout << "\t""Which Doses You Had ?" << endl;
			cout << endl;
			string ans;

			while (true)
			{
				cout << "\t""Press 1 for one Dose Or 2 for both:-" << " "; cin >> ans;

				cout << endl;

				if (ans == "1") {

					user.vaccine.set_dose1(1);
					Second_Dose_List.push(user);
					user.increase_counters();

					break;
				}

				else if (ans == "2")
				{
					user.vaccine.set_dose2(1);

					user.increase_counters();
					break;
				}
				else
				{
					cout << "\t""Please Enter 1 Or 2  only " << endl;
					cout << endl;
					continue;
				}
			}

			if (ans == "1") {

				cout << "\t" << "You Have been added to the Second Dose List and we will message you with your next appointment date" << endl;
				cout << endl;
			}
			else if (ans == "2")
			{
				cout << "\t" << "Thank you for helping us find out who got Vaccinated" << endl;
				cout << endl;
			}

			this->users[user.get_id()] = user;
		}
		else if (user.vaccine.vac == "0")
		{

			this->Set_User_At_First_Dose_List(user);
			this->users[user.get_id()] = user;
			cout << "\t" << "You are added to First Dose List we will message you with your next appointment date" << endl;
			cout << endl;

		}
	

}

void System::Add_User()
{
	User new_one;
	new_one.take_information();
	this->check_vaccine(new_one);
}

void System::Sign_in()
{
	int i = 2;

	string id, password;
	cout << "               *********************************************      " << endl;
	cout << "                   Enter The National Number and Password         " << endl;
	cout << "               *********************************************      " << endl;
	cout << endl;
	cout << "\t\t\t\t\n                         THE NATIONAL NUMBER: "; cin >> id;
	cout << "\t\t\t\t\n                         PASSWORD: "; cin >> password;





	while (i != 0)
	{




		if (this->users.find(id) == this->users.end())
		{

			cout << " \n\                           National Number doesn't exist   " << endl;
			cout << "\n\                            You Can try Only " << i << " times more" << endl;
			cout << "\t\t\t\t\n                         THE NATIONAL NUMBER: "; cin >> id;
			cout << "\t\t\t\t\n                         PASSWORD: "; cin >> password;
			i--;


		}

		if (this->users.find(id) != this->users.end())
		{
			if (this->users[id].get_password() != password)
			{

				cout << "\n\     Wrong Password  You Can try Only " << i - 1 << " times more" << endl;
				cout << "\t\t\t\t\n                         THE NATIONAL NUMBER: "; cin >> id;
				cout << "\t\t\t\t\n                         PASSWORD: "; cin >> password;

				i--;

			}

			else if (this->users[id].get_password() == password) 
			{
				cout << endl;
				this->users[id].users_operation();
				break;
			}
		}



	}
	if (i == 0)
	{

		cout << "\n               YOU ARE BLOCKED FOR 10 SECONDS!!" << endl;;
		cout << endl;
		cout << "\t\t 1 for previous menu       \t\t\t2 for Exit \n\t\t\t\t\    Press any key to continue                  " << endl;
		cout << endl;
		string d;
		cout << "                       Your choice:-"; cin >> d;
		cout << endl;

		if (d == "2") {

			cout << "               ***********************************************           " << endl;
			cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
			cout << "                              HAVE A NICE DAY              " << endl;
			cout << "               ***********************************************           " << endl;

			exit(0);

		}

		else if (d == "1")
		{
			this->login_helper();
		}
		else
		{
			Sign_in();

		}
	}
}
void System::Sign_up()
{
	this->Add_User();
	this->The_interface();
}

void System::Sign_in_as_admin() {
	string name, password;
	cout << "               ***********************************************           " << endl;
	cout << "                          Enter The Name And Password                  " << endl;
	cout << "               ***********************************************           " << endl;
	cout << endl;
	cout << "\t\t\t\t\n                  	NAME: "; cin >> name;
	cout << "\t\t\t\t\n                        PASSWORD: "; cin >> password;

	int i = 2;
	while (i >= 1)
	{



		if (Admins[name].get_Password() != password)
		{

			cout << "\n\n\t     Wrong Password Or name  You Can try Only " << i << " times more" << endl;
			cout << "\t\t\t\t\n                  	NAME: "; cin >> name;
			cout << "\t\t\t\t\n                        PASSWORD: "; cin >> password;

		}


		if (Admins[name].get_Password() == password)
		{

			cout << "\n                      YOU ARE LOGIN SUCCESSFULLY       " << endl;
			cout << endl;
			cout << "               ***********************************************           " << endl;
			cout << "                           Welcome to admin page                   " << endl;
			cout << "               ***********************************************           " << endl;
			cout << endl;
		X:
			cout << "\t1.VIEW STATISTICS       \t\t2.SEARCHING ON USER \n\t\t       3.viewQueue          4.DELETE     " << endl;
			cout << endl;
			string ans;
			cout << "                       Your choice:-"; cin >> ans;

			cout << endl;

			if (ans == "1") {
				Admins[name].Statistics();
				break;
			}
			else if (ans == "2")
			{
				Admins[name].view();
				break;

			}
			else if (ans == "3")
			{
				int choice;
				cout << "\t" << " \t" << "FIRST DOES Press 1 OR SECOND SECOND DOES press 2 : "; cin >> choice;
				if (choice == 1)
				{
					Admins[name].watinglistview();
					break;
				}
				else
				{
					Admins[name].first_waiting_list_veiw();
					break;
				}


			}
			else if (ans == "4")
			{
				Admins[name].Delete_AT_Admin();
				break;


			}

		}


		i--;
	}
	if (i == 0) {
		cout << endl;
		cout << "                    YOU ARE BLOCKED FOR 10 SECONDS!!" << endl;
		cout << endl;

		cout << "\t\t 1 for previous menu       \t\t\t2 for Exit \n\t\t\t\t\    Press any key to continue                  " << endl;
		cout << endl;


		string d;
		cout << "                       Your choice:-"; cin >> d;
		cout << endl;
		if (d == "1") {
			this->login_helper();
		}
		else if (d == "2")
		{
			cout << "               ***********************************************           " << endl;
			cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
			cout << "                              HAVE A NICE DAY              " << endl;
			cout << "               ***********************************************           " << endl;

			exit(0);
		}
		else
		{
			Sign_in_as_admin();

		}
	}
	cout << endl;
	cout << endl;
	string xx;
	cout << "\t\t 1.Back to login page            2.Another Operation \n\t\t\t\              3.Exit" << endl;
	cout << endl;
	cout << "                       Your choice:-"; cin >> xx;
	cout << endl;
	if (xx == "1") {
		this->login_helper();
	}

	else if (xx == "3")
	{
		cout << "               ***********************************************           " << endl;
		cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
		cout << "                              HAVE A NICE DAY              " << endl;
		cout << "               ***********************************************           " << endl;

		exit(0);
	}
	else if (xx == "2")
	{
		goto X;
	}

}

void System::login_helper()
{

	string x;
	cout << "               ***********************************************           " << endl;
	cout << "                          Welcome  at login page                              " << endl;
	cout << "               ***********************************************           " << endl; cout << endl;

	cout << "\t\t 1. Admin             \t\t\t2.User \n\t\t\t\     3. Back To main menu" << endl;

	cout << endl;
	cout << "                       Your choice:-"; cin >> x;

	cout << endl;
	if (x == "3") {
		this->The_interface();
	}

	else if (x == "1")
	{
		this->Sign_in_as_admin();

	}


	else if (x == "2")
	{
		this->Sign_in();
	}

}


void System::intial_users_store_at_system()
{
	User u1("1", "mostafa", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u1.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u1);
	u1.vaccine.one_dose_male++;
	this->users[u1.get_id()] = u1;
	User u2("2", "hanfy", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u2.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u2);
	u2.vaccine.one_dose_male++;
	this->users[u2.get_id()] = u2;
	User u3("3", "nahass", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u3.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u3);
	u3.vaccine.one_dose_male++;
	this->users[u3.get_id()] = u3;
	User u4("4", "hassan", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u4.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u4);
	this->users[u4.get_id()] = u4;
	u4.vaccine.one_dose_male++;
	User u5("5", "seif", "ahmed", "hinawi", "123", "20", "Male", "qalyubia", "Egypt", "1");
	u5.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u5);
	u5.vaccine.one_dose_male++;
	this->users[u5.get_id()] = u5;


	User u6("6", "reem", "ahmed", "hinawi", "123", "20", "Female", "qalyubia", "Egypt", "1");
	u6.vaccine.set_dose2(1);
	u6.vaccine.both_dose_Female++;
	this->users[u6.get_id()] = u6;
	User u7("7", "mona", "ahmed", "hinawi", "123", "20", "Female", "qalyubia", "Egypt", "1");
	u7.vaccine.set_dose2(1);
	u7.vaccine.both_dose_Female++;
	this->users[u7.get_id()] = u7;
	User u8("8", "heba", "ahmed", "hinawi", "123", "20", "Female", "qalyubia", "Egypt", "1");
	u8.vaccine.set_dose2(1);
	u8.vaccine.both_dose_Female++;
	this->users[u8.get_id()] = u8;
	User u9("9", "abeer", "ahmed", "hinawi", "123", "20", "Female", "Giza", "Egypt", "1");
	u9.vaccine.set_dose2(1);
	u9.vaccine.both_dose_Female++;
	this->users[u9.get_id()] = u9;
	User u10("10", "nada", "ahmed", "hinawi", "123", "20", "Female", "Giza", "Egypt", "1");
	u10.vaccine.set_dose2(1);
	u10.vaccine.both_dose_Female++;
	this->users[u10.get_id()] = u10;


	User u11("11", "mmmm", "ahmed", "hinawi", "123", "20", "Male", "Giza", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u11);
	this->users[u11.get_id()] = u11;
	User u12("12", "ail", "ahmed", "hinawi", "123", "20", "Male", "Giza", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u12);
	this->users[u12.get_id()] = u12;
	User u13("13", "aml", "ahmed", "hinawi", "123", "20", "Female", "Alexandria ", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u13);
	this->users[u13.get_id()] = u13;
	User u14("14", "a", "ahmed", "hinawi", "123", "20", "Female", "Alexandria ", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u14);
	this->users[u14.get_id()] = u14;
	User u15("15", "b", "ahmed", "hinawi", "123", "20", "Female", "Alexandria ", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u15);
	this->users[u15.get_id()] = u15;
	User u16("16", "c", "ahmed", "hinawi", "123", "20", "Female", "Alexandria ", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u16);
	this->users[u16.get_id()] = u16;


	User u17("17", "noha", "ahmed", "hinawi", "123", "20", "Female", "mansoura", "Egypt", "1");
	u17.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u17);
	u17.vaccine.one_dose_Female++;
	this->users[u17.get_id()] = u17;

	User u18("17", "amira", "ahmed", "hinawi", "123", "20", "Female", "mansoura", "Egypt", "1");
	u18.vaccine.set_dose2(1);
	u18.vaccine.both_dose_Female++;
	this->users[u18.get_id()] = u18;

	User u19("19", "maryam", "ahmed", "hinawi", "123", "20", "Female", "mansoura", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u19);
	this->users[u19.get_id()] = u19;
	User u20("20", "abeer", "ahmed", "hinawi", "123", "20", "Female", "mansoura", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u20);
	this->users[u20.get_id()] = u20;

	User u21("21", "Asmaa", "ahmed", "hinawi", "123", "20", "Female", "Asswan", "Egypt", "1");
	u21.vaccine.set_dose2(1);
	u21.vaccine.both_dose_Female++;
	this->users[u21.get_id()] = u21;

	User u22("22", "hamza", "ahmed", "hinawi", "123", "20", "Male", "Asswan", "Egypt", "1");
	u22.vaccine.set_dose2(1);
	u22.vaccine.both_dose_male++;
	this->users[u22.get_id()] = u22;

	User u23("23", "malk", "ahmed", "hinawi", "123", "20", "Female", "Asswan", "Egypt", "1");
	u23.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u23);
	u23.vaccine.one_dose_Female++;
	this->users[u23.get_id()] = u23;

	User u24("24", "rawan", "ahmed", "hinawi", "123", "20", "Malk", "Asswan", "Egypt", "0");
	this->users[u24.get_id()] = u24;
	this->Set_User_At_First_Dose_List(u24);

	User u25("25", "Hamdan", "ahmed", "hinawi", "123", "20", "Male", "sohag", "Egypt", "1");
	u25.vaccine.set_dose2(1);
	u25.vaccine.both_dose_male++;
	this->users[u25.get_id()] = u25;

	User u26("25", "zain", "ahmed", "hinawi", "123", "20", "Male", "sohag", "Egypt", "1");
	u26.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u26);
	u26.vaccine.one_dose_male++;
	this->users[u26.get_id()] = u26;

	User u27("27", "sabra", "ahmed", "hinawi", "123", "20", "Female", "sohag", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u27);
	this->users[u27.get_id()] = u27;

	User u28("28", "radwa", "ahmed", "hinawi", "123", "20", "Female", "sohag", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u28);
	this->users[u28.get_id()] = u28;


	User u29("29", "Aisha", "ahmed", "hinawi", "123", "20", "Female", "behira", "Egypt", "1");
	u21.vaccine.set_dose2(1);
	u21.vaccine.both_dose_Female++;
	this->users[u21.get_id()] = u21;

	User u30("30", "zeinab", "ahmed", "hinawi", "123", "20", "Female", "behira", "Egypt", "1");
	u30.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u30);
	u30.vaccine.one_dose_Female++;
	this->users[u30.get_id()] = u30;

	User u31("31", "ramdan", "ahmed", "hinawi", "123", "20", "Male", "behira", "Egypt", "0");
	this->users[u31.get_id()] = u31;
	this->Set_User_At_First_Dose_List(u31);

	User u32("32", "hazem", "ahmed", "hinawi", "123", "20", "Male", "behira", "Egypt", "0");
	this->Set_User_At_First_Dose_List(u32);
	this->users[u32.get_id()] = u32;

	User u33("33", "wael", "ahmed", "hinawi", "123", "20", "Female", "monfia", "Egypt", "1");
	u33.vaccine.set_dose2(1);
	u33.vaccine.both_dose_male++;
	this->users[u33.get_id()] = u33;

	User u34("34", "habiba", "ahmed", "hinawi", "123", "20", "Female", "monfia", "Egypt", "1");
	u34.vaccine.set_dose2(1);
	u34.vaccine.both_dose_Female++;
	this->users[u34.get_id()] = u34;

	User u35("35", "nassem", "ahmed", "hinawi", "123", "20", "male", "monfia", "Egypt", "1");
	u35.vaccine.set_dose1(1);
	this->Second_Dose_List.push(u35);
	u35.vaccine.both_dose_male++;
	this->users[u35.get_id()] = u35;









	Admin a1("Hinawi", "123");
	Admin a2("Hassan", "123");
	Admin a3("Hanfy", "123");
	Admin a4("Nahass", "123");
	Admin a5("Seif", "123");
	Admin a6("Moha", "123");
	Admin a7("Nassem", "123");


	Admins["Hinawi"] = a1;
	Admins["Hassan"] = a2;
	Admins["Hanfy"] = a3;
	Admins["Nahass"] = a4;
	Admins["Seif"] = a5;
	Admins["Moha"] = a6;
	Admins["Nassem"] = a7;





}




void System::test_display_map()
{

	for (auto it = users.begin(); it != users.end(); it++) {
		it->second.Display(0);
	}
}

void System::The_interface()
{
	string choice;
	cout << endl;
	cout << "               ***********************************************           " << endl;
	cout << "                    WELCOME TO VACCINE TRACKING SYSTEM                    " << endl;
	cout << "               ***********************************************           " << endl; cout << endl;
	cout << "\t\t 1. Sign In        \t\t\t2.Sign Up \n\t\t\t\t\     3. Exit" << endl;
	cout << endl;
	cout << "                       Your choice:-"; cin >> choice;
	cout << endl;

	if (choice == "3") {
		cout << "               ***********************************************           " << endl;
		cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
		cout << "                              HAVE A NICE DAY              " << endl;
		cout << "               ***********************************************           " << endl;
		exit(0);
	}

	else if (choice == "2")
	{
		this->Sign_up();

	}

	else if (choice == "1")
	{
		this->login_helper();

	}


}



System::System()
{

	/*User user(" ", " ", " ", " ", " ", " ", " ", " ", " ", " ");
		users[user.get_id()] = user;
		users.erase(user.get_id());
	*/

}