#pragma once
#include "Phone.h"
#include <iostream>
#include <vector>
class Menu
{
	std::vector<Phone*> phones;
public:
	Menu();
	Menu(std::string file_path);
	~Menu();

private:
	void show_menu();
	void add_phone();
	void delete_phone();
	void reports();
	void reports_opt1();
	void reports_opt2();
	void reports_opt3();
	void reports_opt4();
	void get_phones_from_file(std::string file_path);
	static void clear_console();
};

