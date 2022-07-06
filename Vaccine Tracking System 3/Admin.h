#pragma once
#include"User.h"

class Admin
{

private:
	string name;
	string password;
public:
	~Admin();
	Admin(string name, string password);
	void Statistics();
	void view();
	void basic_statistics();
	void Delete_AT_Admin();
	void Advanced_Statistics();
	void helper_for_counters(User user);
	string get_Password();
	string get_Name();
	void watinglistview();
	void first_waiting_list_veiw();

	Admin();

};

