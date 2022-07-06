#include "Admin.h"
#include"System.h"
#include"User.h"
#include <cmath>
#include <iomanip> 
#include<vector>
//#include"PiePlot.hpp"



Admin::Admin() {

}

Admin::~Admin()
{
}

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;
}

void Admin::Statistics()
{
	string number;
	cout << "               ***********************************************           " << endl;
	cout << "                             VACCINE STATISTICS                           " << endl;
	cout << "               ***********************************************           " << endl;
	cout << endl;
	cout << "             1.Basic statistics    2.Advanced Statistics     3.Back " << endl;
	cout << endl;
	cout << "                       Your choice:-"; cin >> number;
	cout << endl;
	if (number == "1") {
		this->basic_statistics();
	}

	else if (number == "2")
	{
		this->Advanced_Statistics();
	}




}


void Admin::view()
{
	string id;
	System s;
	int i = 3;
	while (i > 0) {

		cout << "         ************************************************************\n";
		cout << "            viewing the records of user by his National Number" << endl;
		cout << "         ************************************************************\n\n";
		cout << "\t\t\t\t\n                                    THE NATIONAL NUMBER: "; cin >> id;
		cout << endl;

		if (s.users.find(id) != s.users.end()) {
			s.users[id].Display(0);
			break;
		}
		else
		{
			cout << " \n                                   Sorry User is not found" << endl;
			i--;
		}
	}

	if (i == 0) {
		cout << "\n\t\t\tplease make sure this national number is true and try again\n\n";

	}


}

void Admin::basic_statistics()
{
	User u;
	System s;
	cout << endl;
	cout << "          **********************************************************************************************************                 " << endl;
	cout << "                  Basic statistical analysis of Egyptian people who vaccinated in and outside Egypt                           " << endl;
	cout << "         **********************************************************************************************************                 " << endl;
	if (isnan(double(((double)u.vaccine.ones_count / ((double)s.users.size())) * 100.0)))
	{
		cout << "                Percentage of people registered in the system that has received the first dose is = " << 0 << " %" << endl;
		cout << endl;
	}
	else
	{
		cout << "                Percentage of people registered in the system that has received the first dose is = " << setprecision(2) << abs(double(((double)u.vaccine.ones_count / ((double)s.users.size())) * 100.0)) << " %" << endl;
		cout << endl;
	}
	if (isnan(double(((double)u.vaccine.both_count / ((double)s.users.size()))) * 100.0)) {
		cout << "                Percentage of people registered in the system that has received both doses is = " << 0 << " %" << endl;
		cout << endl;
	}

	else
	{
		cout << "                Percentage of people registered in the system that has received both doses is = " << setprecision(2) << abs(double(((double)u.vaccine.both_count / ((double)s.users.size())) * 100.0)) << " %" << endl;

		cout << endl;
	}

	cout << "                       Percentage of Females and Males registered in the system :-" << endl;
	cout << endl;
	if (isnan(double(((double)u.count_Female / ((double)u.count_Female + (double)u.count_male)) * 100.0))) {
		cout << "                       Females = " << 0 << " %" << endl;
	}
	else
	{
		cout << "                      Females = " << setprecision(2) << abs(double(((double)u.count_Female / ((double)u.count_Female + (double)u.count_male)) * 100.0)) << " %" << endl;
		cout << endl;


	}

	cout << endl;
	if (isnan(double(((double)u.count_male / ((double)u.count_Female + (double)u.count_male)) * 100.0))) {
		cout << "                       Males = " << " 0 %" << endl;
		cout << endl;

	}
	else
	{
		cout << "                       Males = " << setprecision(2) << abs(double(((double)u.count_male / ((double)u.count_Female + (double)u.count_male)) * 100.0)) << " %" << endl;
		cout << endl;

	}

	cout << endl;
	if (isnan(double(((double)u.vaccine.one_dose_Female / (((double)s.users.size()))) * 100.0))) {
		cout << "              Percentage of Females registered in the system that has received the first dose is = " << 0 << " %" << endl;
		cout << endl;


	}
	else
	{
		cout << "              Percentage of Females registered in the system that has received the first dose is =  " << setprecision(2) << (abs(double(((double)u.vaccine.one_dose_Female / ((double)s.users.size())))) * 100.0) << " %" << endl;
		cout << endl;

	}

	cout << endl;
	if (isnan(double(((double)u.vaccine.one_dose_male / ((double)s.users.size())) * 100.0))) {
		cout << "              Percentage of Males registered in the system that has received the first dose is = " << 0 << " %" << endl;
		cout << endl;

	}
	else
	{
		cout << "              Percentage of Males registered in the system that has received the first dose is = " << setprecision(2) << abs((double(((double)u.vaccine.one_dose_male / ((double)s.users.size())))) * 100.0) << " %" << endl;
		cout << endl;

	}

	cout << endl;
	if (isnan(double(((double)u.vaccine.both_dose_Female / ((double)u.vaccine.both_dose_Female + (double)u.vaccine.both_dose_male)) * 100.0))) {
		cout << "              Percentage of Females registered in the system that has received both doses is = " << 0 << "%" << endl;
		cout << endl;
	}
	else
	{
		cout << "              Percentage of Females registered in the system that has received both doses is = " << setprecision(2) << abs(double((((double)u.vaccine.both_dose_Female / ((double)s.users.size())))) * 100.0) << " %" << endl;
		cout << endl;
	}


	if (isnan(double((((double)u.vaccine.both_dose_male / (((double)s.users.size())))) * 100.0))) {
		cout << "              Percentage of Male registered in the system that has received both doses is =  " << 0 << "%" << endl;
		cout << endl;

	}
	else
	{
		cout << "               Percentage of Male registered in the system that has received both doses is = " << setprecision(2) << abs(double((((double)u.vaccine.both_dose_male / (((double)s.users.size())))) * 100.0)) << " %" << endl;
		cout << endl;
	}


	cout << endl;

	string xx;
	cout << "                            \t\t 1.Exit        2.Back to previous   " << endl;
	cout << endl;
	cout << "                                         Your choice:-"; cin >> xx;
	cout << endl;
	while (true)
	{
		if (xx == "1") {
			cout << "                                     ***********************************************           " << endl;
			cout << "                                        THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
			cout << "                                                   HAVE A NICE DAY                               " << endl;
			cout << "                                     ***********************************************           " << endl;

			exit(0);
			break;
		}
		else if (xx == "2")
		{
			this->Statistics();
			break;
		}

	}


}

void Admin::helper_for_counters(User user)
{

	if (user.get_gender() == "Male") {

		user.count_male--;
	}

	else if (user.get_gender() == "Female")
	{
		user.count_Female--;
	}

	if (user.vaccine.dose2) {

		user.vaccine.both_count--;

		if (user.get_gender() == "Male") {

			user.vaccine.both_dose_male--;

		}
		else if (user.get_gender() == "Female")
		{

			user.vaccine.both_dose_Female--;
		}

	}

	if (user.vaccine.dose1) {
		user.vaccine.ones_count--;

		if (user.get_gender() == "Male") {

			user.vaccine.one_dose_male--;

		}
		else if (user.get_gender() == "Female")
		{

			user.vaccine.one_dose_Female--;
		}
	}
}

string Admin::get_Password()
{
	return this->password;
}

string Admin::get_Name()
{
	return this->name;
}

void Admin::watinglistview()
{
	queueArr<User>a;
	vector<User>vec;
	System s;

	while (!s.First_Dose_List.empty())
	{
		a.push(s.First_Dose_List.Front());
		s.First_Dose_List.pop();

	}

	while (!a.empty())
	{
		vec.push_back(a.Front());
		a.pop(); 
	}
	for (int i = 0; i < vec.size(); i++) {
		s.First_Dose_List.push(vec[i]);
	}

	for (int i = 0; i < vec.size(); i++) {
		vec[i].Display(0);
	}
}

void Admin::first_waiting_list_veiw()
{
	queue<User>a;
	vector<User>vec;
	System s;

	while (!s.Second_Dose_List.empty())
	{
		a.push(s.Second_Dose_List.Front());
		s.Second_Dose_List.pop();

	}

	while (!a.empty())
	{
		vec.push_back(a.front());
		a.pop();
	}
	for (int i = 0; i < vec.size(); i++) {
		s.Second_Dose_List.push(vec[i]);
	}

	for (int i = 0; i < vec.size(); i++) {
		vec[i].Display(0);
	}
}
void Admin::Delete_AT_Admin()
{

	System s;

	string id;

	while (true)
	{

		cout << "         ************************************************************" << endl;
		cout << "              Delete the records of user by his National Number      " << endl;
		cout << "         *************************************************************" << endl;
		cout << endl;
		cout << "                           THE NATIONAL NUMBER: "; cin >> id;


		if (s.users.find(id) != s.users.end()) {

			string delete_option;
			cout << endl;
			cout << endl;
			cout << "\t\t 1. Remove This User              2.Remove Record" << endl;
			cout << endl;
			cout << "                               Your choice:-"; cin >> delete_option;
			s.users[id].Display(0);
			cout << endl;
			cout << endl;
		X:
			if (delete_option == "1" || delete_option == "7")
			{
				if (s.users[id].vaccine.vac == "0" || s.users[id].vaccine.dose1 == 1)
					
				{
					s.users[id].helper_for_delete_function(1);


				}
				
					s.users[id].helper_for_counters(1, 1);
					s.users.erase(id);
				
				
				cout << "               *********************************************      " << endl;
				cout << "                               USER IS DELETED                                 " << endl;
				cout << "               *********************************************      " << endl;


			}

			else if (delete_option == "2") {
				cout << endl;
				string number;
				cout << "                              The Number Of Record You want To Delete : "; cin >> number;
				cout << endl;

				if (number == "1") {
					s.users[id].set_name({ "Deleted ","by" ,"Admin" });
					cout << endl;
					cout << "                                process is done successfully                " << endl;
				}
				else if (number == "2")
				{
					s.users[id].helper_for_counters(1, 1);
					s.users[id].set_gender("Deleted by Admin");
					cout << endl;
					cout << "                                process is done successfully               " << endl;

				}
				else if (number == "3")
				{
					s.users[id].set_age("Deleted by Admin");
					cout << endl;
					cout << "                                 process is done successfully               " << endl;

				}
				else if (number == "4")
				{
					s.users[id].set_country("Deleted by Admin");
					cout << endl;
					cout << "                                  process is done successfully               " << endl;

				}
				else if (number == "5")
				{
					string pass;
					cout << "                            !!!!!Password is deleted!!!!!!           " << endl;
					cout << endl;
					cout << "                             You must enter new password for this user" << endl;
					cout << endl;
					cout << "                                           New password : "; cin >> pass;
					s.users[id].set_password(pass);

				}
				else if (number == "6")
				{
					s.users[id].set_Governorate("Deleted by Admin");
					cout << endl;
					cout << "                                        process is done successfully        " << endl;

				}
				else if (number == "7")
				{
					int x;
					delete_option = "7";
					cout << "!!!!!!!WARNING IF YOU DELETE THE NATIONAL  NUMBER MEANS YOU WANT TO DELETE  ACCOUNT OF THIS USER!!!!!!!!!" << endl;
					cout << endl;
					cout << "                         Press 1 if you want to stop deleting Or Any key  to continue:"; cin >> x; cout << endl;
					if (x == 1) {
						return;
					}
					else
					{
						goto X;

					}
				}
				else if (number == "8")
				{
					if (s.users[id].vaccine.vac == "1") {
						s.users[id].helper_for_counters(0, 1);
						Vaccine vaccine;
						vaccine.vac = "Deleted by admin";
						vaccine.dose1 = 0;
						vaccine.dose2 = 0;
						s.users[id].set_vaccine(vaccine);


					}

					else if (s.users[id].vaccine.vac == "0")
					{
						s.users[id].helper_for_delete_function(0);
						Vaccine vaccine;
						vaccine.vac = "Deleted by admin";
						vaccine.dose1 = 0;
						vaccine.dose2 = 0;
						s.users[id].set_vaccine(vaccine);


					}
					cout << "                               Vaccine information is deleted" << endl;
				}





			}
			break;
		}
		else
		{
			cout << "                                        invalid national number please Try Again" << endl;
		}

	}






}

void Admin::Advanced_Statistics()
{
	System s;
	User u;
	//PieChart();
	cout << "number of map :" << s.users.size()<<"\n";
	cout << "number of males:" << u.count_male << "\n";
}
