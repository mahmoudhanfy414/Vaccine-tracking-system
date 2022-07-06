#include<queue>
#include "queueArr.cpp"
#include<unordered_map>
#include"User.h"
#include"Admin.h"
#include<stack>
#pragma once
class System
{


public:

	System();
	static queueArr<User>First_Dose_List;
	static queueArr<User>Second_Dose_List;
	static unordered_map<string, User>users;
	static unordered_map<string, Admin>Admins;

	~System();
	bool Check_id_is_Unique(User user);
	void Set_User_At_First_Dose_List(User user);
	User Get_User_From_First_Dose_List();//that have no use becouse it is return the only the front of waiting list (only front () function)
	void check_vaccine(User& user);
	void Add_User();
	void Sign_in();
	void Sign_up();
	void test_display_map();//this for testing only to show users in user map
	void The_interface();
	void Sign_in_as_admin();
	void login_helper();
	void intial_users_store_at_system();

};

