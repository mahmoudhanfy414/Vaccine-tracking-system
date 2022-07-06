#include "System.h"
#include"User.h"
int User::count_Female = 0;
int User::count_male = 0;

int Vaccine::both_count = 0;
int Vaccine::ones_count = 0;

int Vaccine::both_dose_Female = 0;
int Vaccine::both_dose_male = 0;

int Vaccine::one_dose_Female = 0;
int Vaccine::one_dose_male = 0;



void User::Edit() {

	Display(0);
	int number;
	cout << endl;
	cout << "                          Enter the Number of data you want to Edit :"; cin >> number;
	cout << endl;
	string editvalue;
	if (number == 1) {
		int x;
		cout << "                   1 for first 2 for second 3 for last 4 for all name : "; cin >> x; cout << endl;
		if (x == 1) {
			cout << "                    New data : "; cin >> editvalue; cout << endl;
			this->name.first_name = editvalue;

		}
		else if (x == 2)
		{
			cout << "                    New data : "; cin >> editvalue; cout << endl;
			this->name.second_name = editvalue;


		}
		else if (x == 3)
		{
			cout << "                    New data : "; cin >> editvalue; cout << endl;
			this->name.last_name = editvalue;

		}
		else if (x == 4)
		{
			full_name newname;
			cout << "                    New data : " << endl;
			cout << "                    first Name: "; cin >> newname.first_name; cout << endl;
			cout << "                    Second Name: "; cin >> newname.second_name; cout << endl;
			cout << "                    Last Name: "; cin >> newname.last_name; cout << endl;
			this->name = newname;

		}
		cout << "                                  process is done successfully               " << endl;

	}

	else if (number == 2)
	{
		cout << "                    New data : "; cin >> editvalue; cout << endl;

		if (editvalue != this->gender) {

			if (this->gender == "Male") {

				count_male--;
			}

			else if (this->gender == "Female")
			{
				count_Female--;
			}

			if (this->vaccine.dose2) {

				if (this->gender == "Male") {

					this->vaccine.both_dose_male--;

				}
				else if (this->gender == "Female")
				{

					this->vaccine.both_dose_Female--;
				}

			}

			if (this->vaccine.dose1) {

				if (this->gender == "Male") {

					this->vaccine.one_dose_male--;

				}
				else if (this->gender == "Female")
				{

					this->vaccine.one_dose_Female--;
				}


			}
			this->gender = editvalue;
			this->increase_counters();
			/* we didnot incliude gender counters in this function becouse it will be calling in another postion
									  must not keep track gender position
									  */
			if (this->gender == "Male") 
			{
				this->count_male++;
			}
			else if (this->gender == "Female")
			{
				this->count_Female++;
			}
			cout << "                                  process is done successfully               " << endl;


		}

		else
		{
			cout << "                    This value is already exist " << endl;
		}


	}
	else if (number == 3)
	{
		cout << "                    New data : "; cin >> editvalue; cout << endl;
		this->age = age;

		cout << "                                  process is done successfully               " << endl;

	}

	else if (number == 4)
	{
		cout << "                    New data : "; cin >> editvalue; cout << endl;
		this->country = country;
		cout << "                                  process is done successfully               " << endl;

	}
	else if (number == 5)
	{
		cout << "                    New data : "; cin >> editvalue; cout << endl;
		this->password = editvalue;
		cout << "                                  process is done successfully               " << endl;

	}
	else if (number == 6)
	{
		System s;
		cout << "                    New data : "; cin >> editvalue; cout << endl;
		this->Governorate = editvalue;
		cout << "                                  process is done successfully               " << endl;


	}
	else if (number == 7)
	{

		string x;
		cout << "                    New data : "; cin >> editvalue; cout << endl;
		System s;
		x = id; //???
		if (s.users.find(editvalue) != s.users.end()) {

			cout << "              The National number   is already used  " << endl;

		}
		else
		{


			s.users[editvalue] = s.users[this->id];
			s.users[editvalue].id = editvalue;
			helper_to_edit_id_in_waitinglist(x, editvalue);
			s.users.erase(x);

			cout << "                                  process is done successfully               " << endl;



			s.The_interface();

		}


	}
	else if (number == 8)
	{
	System s;
		int ans;
		cout << "                    Are you Vaccinated ?" << endl;
		cout << endl;
		cout << "                    1 for Yes or 2 for No :"; cin >> ans;

		cout << endl;

		if (ans == 1) {
			int edit_option;
			cout << "              Press 1 for one Dose Or 2 for both:-" << " "; cin >> edit_option;
			this->helper_for_delete_function(0);

			if (edit_option == 1) {

				this->helper_for_counters(0, 1);
				Vaccine vaccine;
				vaccine.vac = "1";
				vaccine.dose1 = 1;
				vaccine.dose2 = 0;
				vaccine.ones_count++;
				this->set_vaccine(vaccine);
				this->increase_counters();
				s.Second_Dose_List.push(s.users[this->get_id()]);

			}

			else if (edit_option == 2)
			{

				this->helper_for_counters(0, 1);
				Vaccine vaccine;
				vaccine.vac = "1";
				vaccine.dose1 = 0;
				vaccine.dose2 = 1;
				vaccine.both_count++;
				this->set_vaccine(vaccine);
				this->increase_counters();



			}


		}

		else if (ans == 2)
		{
			this->helper_for_counters(0, 1);

			Vaccine vaccine;
			vaccine.vac = "0";
			vaccine.dose1 = 0;
			vaccine.dose2 = 0;
			this->set_vaccine(vaccine);
			System s;
			s.Set_User_At_First_Dose_List(s.users[this->get_id()]);



		}
		cout << "                                  process is done successfully               " << endl;
		cout << endl;


	}
	cout << endl;
	this->undofun();

}



string User::get_id()
{
	return this->id;
}

string User::get_age()
{
	return this->age;
}

string User::get_password()
{
	return this->password;
}

string User::get_country()
{
	return this->country;
}

full_name User::get_name()
{
	return this->name;
}

string User::get_gender()
{
	return this->gender;
}

Vaccine User::get_vaccine()
{
	return this->vaccine;
}




void User::set_id(string id)
{
	this->id = id;
}

void User::set_age(string age)
{
	this->age = age;
}

void User::set_password(string password)
{
	this->password = password;
}

void User::set_country(string country)
{
	this->country = country;
}

void User::set_name(full_name name)
{
	this->name = name;
}

void User::set_gender(string gender)
{
	this->gender = gender;
}

void User::take_information()
{
	cout << "               *********************************************      " << endl;
	cout << "                         ENTER YOUR INFORMATION                  " << endl;
	cout << "               *********************************************      " << endl; cout << endl;

	cout << "\t""Enter Your Name :- " << "\n";
	cout << "\t""First :- " << " "; cin >> this->name.first_name; cout << "\n";
	cout << "\t""Second :- " << " "; cin >> this->name.second_name; cout << "\n";
	cout << "\t""Last :- " << " "; cin >> this->name.last_name; cout << "\n";
	cout << "\t""Enter Your Gender (Male/Female) :- " << " "; cin >> this->gender; cout << "\n";
	System s;
	if (gender == "Male") {
		count_male++;
	}
	else if (gender == "Female")
	{
		count_Female++;
	}
	cout << "\t""Enter Your Age :" << " "; cin >> this->age; cout << "\n";
	cout << "\t""Enter Your Country :" << " "; cin >> this->country; cout << "\n";
X:
	cout << "\t""Enter Your National ID :" << " "; cin >> this->id; cout << "\n";
	if (s.users.find(this->id) != s.users.end()) {
		cout << "\t""This id exists try another :" << " "; cout << "\n" << endl;
		goto X;
	}
	cout << "\t""Enter Your Password  :" << " "; cin >> this->password; cout << "\n";
	cout << "\t""Enter Your Goveronate  :" << " "; cin >> this->Governorate; cout << "\n";
	cout << "\t""Are you vaccinated ?:" << endl;
	cout << endl;
	while (true)
	{
		string x;

		cout << "\t""Press 1 for 'Yes' Or 2 for 'No':- "; cin >> x; ;
		cout << endl;
		if (x == "1") {
			this->vaccine.vac = "1";
			break;
		}
		else if (x == "2")
		{
			this->vaccine.vac = "0";
			break;
		}
		else
		{
			cout << "\t""Please Enter 1 or 2  only " << endl;
			cout << endl;
			continue;
		}
	}

}

void User::set_vaccine(Vaccine& vaccine)
{
	this->vaccine = vaccine;

}
void User::set_vaccine_vac(bool vac)
{
	this->vaccine.vac = vac;
}//?

void User::helper_for_delete_function(int i = 1)
{

	queueArr<User>deletee;

	System s;


	if (this->vaccine.vac == "0")
	{
		while (!s.First_Dose_List.empty()) {

			if (s.First_Dose_List.Front().id != this->id) {

				deletee.push(s.First_Dose_List.Front());

				s.First_Dose_List.pop();
			}
			else if (s.First_Dose_List.Front().id == this->id)
			{
				s.First_Dose_List.pop();


			}
		}

		while (!deletee.empty())
		{


			s.First_Dose_List.push(deletee.Front());

			deletee.pop();

		}
	}
	if (this->vaccine.dose1 == 1)
	{
		while (!s.Second_Dose_List.empty()) {

			if (s.Second_Dose_List.Front().id != this->id) {

				deletee.push(s.Second_Dose_List.Front());

				s.Second_Dose_List.pop();
			}
			else if (s.Second_Dose_List.Front().id == this->id)
			{
				s.Second_Dose_List.pop();


			}
		}

		while (!deletee.empty())
		{


			s.Second_Dose_List.push(deletee.Front());

			deletee.pop();

		}



	}
	if (i == 1) {
		this->helper_for_counters(1, 1);

		s.users.erase(this->id);
	}
}
void User::helper_for_counters(int for_gender, int for_vaccine)
{
	cout << "hellllllllllo";
	if (for_gender == 1)
	{
		if (this->gender == "Male") {

			count_male--;
		}

		else if (this->gender == "Female")
		{
			count_Female--;
		}
	}
	if (for_vaccine == 1)
	{
		if (this->vaccine.dose2) {

			this->vaccine.both_count--;

			if (this->gender == "Male") {

				this->vaccine.both_dose_male--;

			}
			else if (this->gender == "Female")
			{

				this->vaccine.both_dose_Female--;
			}

		}

		if (this->vaccine.dose1) {
			this->vaccine.ones_count--;

			if (this->gender == "Male") {

				this->vaccine.one_dose_male--;

			}
			else if (this->gender == "Female")
			{

				this->vaccine.one_dose_Female--;
			}
		}
	}

}

void User::set_Governorate(string Governorate)
{
	this->Governorate = Governorate;
}

void User::users_operation()
{

	cout << "\n                      YOU ARE LOGIN SUCCESSFULLY       " << endl;
	cout << endl;
	cout << "               ***********************************************           " << endl;
	cout << "                           Welcome to User  page                          " << endl;
	cout << "               ***********************************************           " << endl;
	cout << endl;
	cout << endl;
	cout << "                   1.Edit                     2.Delete  " << endl;
	cout << "                   3.Display data             4.previous menu         " << endl;
	cout << endl;
	string ans;
	cout << "                       Your choice:-"; cin >> ans;
	cout << endl;
	if (ans == "1") {
		this->Edit();

	}
	else if (ans == "2")
	{
		this->Delete();

	}
	else if (ans == "3")
	{
		this->Display(1);
	}
	else if (ans == "4")
	{
		System s;
		s.login_helper();
	}


}

void User::increase_counters()
{


	if (this->vaccine.dose2) {


		if (this->gender == "Male") {

			this->vaccine.both_dose_male++;

		}
		else if (this->gender == "Female")
		{

			this->vaccine.both_dose_Female++;
		}

	}

	else if (this->vaccine.dose1) {


		if (this->gender == "Male") {

			this->vaccine.one_dose_male++;

		}
		else if (this->gender == "Female")
		{

			this->vaccine.one_dose_Female++;
		}
	}
}

void User::undofun()
{
	string xx;
	cout << "                1.Back to main menu           2.Another Operation" << endl;
	cout << "                                      3.Exit                          " << endl;
	cout << endl;
	cout << "                         Your choice:-"; cin >> xx;
	if (xx == "1") {
		System s;

		s.The_interface();
	}
	else if (xx == "2")
	{

		this->users_operation();
	}
	else if (xx == "3")
	{
		exit(0);
	}
}
void User::Display(int i) {
	cout << endl;
	cout << "               *********************************************      " << endl;
	cout << "                               RECORDS                                 " << endl;
	cout << "               *********************************************      " << endl;
	cout << endl;
	cout << "                \t""1:Name :- " << this->name.first_name << " " << this->name.second_name << " " << this->name.last_name << endl;
	cout << "                \t""2:Gender :- " << this->gender << endl;
	cout << "                \t""3:Age :- " << this->age << endl;
	cout << "                \t""4:Country :- " << this->country << endl;
	cout << "                \t""5:Password :- " << this->password << endl;
	cout << "                \t""6:Governorate :- " << this->Governorate << endl;
	cout << "                \t""7:National Number :- " << this->id << endl;
	cout << "                \t""8:Vaccine status :- ";
	if (this->vaccine.dose1 == 1)
	{
		cout << " have the first one " << endl;
	}
	else if (this->vaccine.dose2 == 1)
	{
		cout << " have the both " << "\n";

	}

	else if (this->vaccine.vac == "0")
	{
		cout << " in the waiting list" << "\n";

	}
	else
	{
		cout << this->vaccine.vac;

	}



	if (i == 1) {
		cout << endl;
		this->undofun();
	}


}

User::~User()
{
}

void User::Delete()
{


	int n;
	cout << "                   1 to delete your record or 2 to delete your account: "; cin >> n;
	if (n == 1) {
		this->Display(0);
		string ans;
		cout << "              From which  The option you want to delete: "; cin >> ans;
		cout << endl;
		if (ans == "1") {
			this->set_name({ "delete","by","user" });
			cout << "                                process is done successfully                " << endl;

		}
		else if (ans == "2") {

			this->helper_for_counters(1, 1);
			this->gender = "deleted by user";
			cout << "                                process is done successfully                " << endl;

		}
		else if (ans == "3") {
			this->age = "deleted by user";
			cout << "                                process is done successfully                " << endl;

		}

		else if (ans == "4") {
			this->country = "deleted by user";
			cout << "                                process is done successfully                " << endl;

		}
		else if (ans == "5") {
			cout << "Password is deleted" << endl;
			cout << "*********************************" << endl;
			cout << "   you must enter new password" << endl;
			cout << "*********************************" << endl;
			string newpassword;
			cout << "The New passord :"; cin >> newpassword;
			cout << endl;
			this->password = newpassword;
			cout << "                                process is done successfully                " << endl;


		}

		else if (ans == "6")
		{
			this->Governorate = "deleted by user";
			cout << "                                process is done successfully                " << endl;

		}

		else if (ans == "7")
		{
			System s;
			cout << "!!!!!!!WARNING IF YOU DELETE YOUR NATIONAL  NUMBER MEANS YOU WANT TO DELETE YOUR ACCOUNT!!!!!!!!!" << endl;
			cout << endl;
			cout << endl; int x;
			cout << "                         Press 1 if you want to stop deleting Or Any key  to continue:"; cin >> x; cout << endl;
			if (x != 1)
			{
				cout << "                                   !!System is deleting your account!!                                " << endl;
				cout << endl;

				this->helper_for_delete_function(1);

				cout << "                                     your account is deleted Successfully                                   " << endl;

			}
			s.The_interface();
		}


		else if (ans == "8")
		{

			if (this->vaccine.vac == "1" || this->vaccine.vac == "0") {
				helper_for_counters(0, 1);
				this->helper_for_delete_function(0);
				Vaccine vaccine;
				vaccine.vac = "Deleted by user";
				vaccine.dose1 = 0;
				vaccine.dose2 = 0;
				this->vaccine = vaccine;


			}



			cout << "                                process is done successfully                " << endl;

		}

	}
	else if (n == 2) {
		System s;
		this->helper_for_delete_function(1);
		cout << endl;

		cout << "                                     your account is deleted Successfully                                   " << endl;

		s.The_interface();

	}

	this->undofun();

}

User::User()
{

}
User::User(string id, string first_name, string second_name, string last_name, string password, string age, string gender, string Governorate, string country, string vac)
{
	System s;
	this->id = id;
	this->password = password;
	this->age = age;
	this->gender = gender;
	this->country = country;
	this->vaccine.vac = vac;
	this->name.first_name = first_name;
	this->name.second_name = second_name;
	this->name.last_name = last_name;
	this->Governorate = Governorate;
	if (gender == "Male") {
		count_male++;
	}
	else if (gender == "Female")
	{
		count_Female++;
	}



}
void User::helper_to_edit_id_in_waitinglist(string id, string newid)
{

	System s;
	if (s.users[id].vaccine.vac == "0")
	{

		vector<User>vec;
		while (!s.First_Dose_List.empty())
		{

			vec.push_back(s.First_Dose_List.Front());
			s.First_Dose_List.pop();

		}

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].get_id() == id) {
				vec[i] = s.users[newid];
			}
		}

		for (int i = 0; i < vec.size(); i++) {
			s.First_Dose_List.push(vec[i]);

		}


	}
	else if (s.users[id].vaccine.dose1 == 1)
	{
		vector<User>vec;
		while (!s.Second_Dose_List.empty())
		{

			vec.push_back(s.Second_Dose_List.Front());
			s.Second_Dose_List.pop();

		}

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].get_id() == id) {
				vec[i] = s.users[newid];
			}
		}

		for (int i = 0; i < vec.size(); i++) {
			s.Second_Dose_List.push(vec[i]);

		}

	}


}

