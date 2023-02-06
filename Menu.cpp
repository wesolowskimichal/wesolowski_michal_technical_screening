#include "Menu.h"
#include <algorithm>
#include <unordered_map>
#include <fstream>

Menu::Menu(){
	show_menu();
}

Menu::Menu(std::string file_path){
	try {
		get_phones_from_file(file_path);
	}
	catch (std::string e) {
		std::cerr << e << std::endl;
		system("pause");
	}
	show_menu();
}

void Menu::show_menu() {
	clear_console();
	std::cout << "1) Add phone\n2) Delete a phone\n3) Reports\n4) Exit\n";
	int option;
	std::cout << "Insert option: ";
	std::cin >> option;
	switch (option)
	{
	case 1:
		add_phone();
		break;
	case 2:
		delete_phone();
		show_menu();
		break;
	case 3:
		reports();
		break;
	case 4:
		break;
	default:
		show_menu();
		break;
	}
}

void Menu::add_phone() {
	clear_console();
	std::string brand_name, model_name, form_factor;
	unsigned int year_of_issue, screen_width, screen_height;
	double price;
	std::cout << "Add phone:\n\n";
	std::cout << "Insert phone's brand name: ";
	std::cin.get();
	std::getline(std::cin, brand_name);
	std::cout << "Insert phone's model name: ";
	std::getline(std::cin, model_name);
	std::cout << "Insert phone's form factor: ";
	std::getline(std::cin, form_factor);
	std::cout << "Insert phone's year of issue: ";
	std::cin >> year_of_issue;
	std::cout << "Insert phone's screen width: ";
	std::cin >> screen_width;
	std::cout << "Insert phone's screen height: ";
	std::cin >> screen_height;
	std::cout << "Insert phone's price: ";
	std::cin >> price;
	phones.push_back(new Phone(brand_name, model_name, form_factor, year_of_issue, screen_width, screen_height, price));
	show_menu();
}


void Menu::delete_phone() {
	clear_console();
	std::string brand_name, model_name, form_factor;
	unsigned int year_of_issue, screen_width, screen_height;
	double price;
	std::cout << "Delete phone:\n\n";
	std::cout << "Insert phone's brand name: ";
	std::cin.get();
	std::getline(std::cin, brand_name);
	std::cout << "Insert phone's model name: ";
	std::getline(std::cin, model_name);
	std::cout << "Insert phone's form factor: ";
	std::getline(std::cin, form_factor);
	std::cout << "Insert phone's year of issue: ";
	std::cin >> year_of_issue;
	std::cout << "Insert phone's screen width: ";
	std::cin >> screen_width;
	std::cout << "Insert phone's screen height: ";
	std::cin >> screen_height;
	std::cout << "Insert phone's price: ";
	std::cin >> price;
	bool f{};
	for (int i{}; i < phones.size(); i++) {
		if (phones[i]->get_brand_name() == brand_name &&
			phones[i]->get_model_name() == model_name &&
			phones[i]->get_form_factor() == form_factor &&
			phones[i]->get_year_of_issue() == year_of_issue &&
			phones[i]->get_screen_size().first == screen_width &&
			phones[i]->get_screen_size().second == screen_height &&
			phones[i]->get_price() == price) {
				phones.erase(phones.begin() + i); 
				f = 1; 
				break;
			}
	}
	if (f)
		std::cout << "Deleted phone\n";
	else
		std::cout << "Phone not found\n";
	system("pause");
	show_menu();
	
}

void Menu::reports() {
	clear_console();
	std::cout << " 1) Show all phones by the same brand\n";
	std::cout << " 2) Show all phones of a given form factorand screen size\n";
	std::cout << " 3) Show the name of the brand with the maximum quantity of the phones\n";
	std::cout << " 4) Show TOP - 3 screen sizes(popularity is determined by the number of phones with the screen size)\n";
	int option;
	std::cout << "Insert option: ";
	std::cin >> option;
	switch (option)
	{
	case 1:
		reports_opt1();
		break;
	case 2:
		reports_opt2();
		break;
	case 3:
		reports_opt3();
		break;
	case 4:
		reports_opt4();
		break;
	default:
		show_menu();
		break;
	}
}

void Menu::reports_opt1() {
	std::string brand_name;
	std::cout << "Insert brand of phone: ";
	std::cin >> brand_name;
	int found = std::count_if(phones.begin(), phones.end(), [&](auto& p) {return p->get_brand_name() == brand_name; });
	if (found == 0) {
		std::cout << "No phones of " << brand_name << " brand name\n";
		system("pause");
		show_menu();
		return;
	}
	std::cout << "Found " << found << " phones of " << brand_name << " brand name:\n";
	for (auto& phone : phones) {
		if (phone->get_brand_name() == brand_name)
			std::cout << phone->to_string() << std::endl;
	}
	system("pause");
	show_menu();
}


void Menu::reports_opt2() {
	std::cin.get();
	std::string form_factor;
	unsigned int screen_width;
	unsigned int screen_height;
	std::cout << "Insert form factor of phone: ";
	std::getline(std::cin, form_factor);
	std::cout << "Insert phone's screen width: ";
	std::cin >> screen_width;
	std::cout << "Insert phone's screen height: ";
	std::cin >> screen_height;
	int found = std::count_if(phones.begin(), phones.end(), [&](auto& p) {return p->get_form_factor() == form_factor && p->get_screen_size().first == screen_width && p->get_screen_size().second == screen_height; });
	if (found == 0) {
		std::cout << "No phones of " << form_factor << " form factor and {"<<screen_width<<", "<<screen_height<<"} size\n";
		system("pause");
		show_menu();
		return;
	}
	std::cout << "Found " << found << " phones of " << form_factor << " form factor and {" << screen_width << ", " << screen_height << "} size: \n";
	for (auto& phone : phones) {
		if (phone->get_form_factor() == form_factor && phone->get_screen_size().first == screen_width && phone->get_screen_size().second == screen_height)
			std::cout << phone->to_string() << std::endl;
	}
	system("pause");
	show_menu();
}


void Menu::reports_opt3() {
	std::unordered_map<std::string, int> mp;
	int res_number{};
	std::string res_name;
	for (auto& phone : phones) {
		mp[phone->get_brand_name()]++;
		if (mp[phone->get_brand_name()] > res_number) {
			res_number = mp[phone->get_brand_name()];
			res_name = phone->get_brand_name();
		}
	}
	if (mp.empty()) {
		std::cout << "No phones in database\n";
		system("pause");
		show_menu();
		return;
	}
	
	std::cout << res_name << " has the biggest amount of phones (" << res_number << ")\n";
	system("pause");
	show_menu();
}


void Menu::reports_opt4() {
	std::cout << "Top-3 screen sizes: \n";
	std::unordered_map<std::string, int> mp;
	for (auto& phone : phones) {
		std::string s = "{" + std::to_string(phone->get_screen_size().first) + ", " + std::to_string(phone->get_screen_size().second) + "}";
		mp[s]++;
	}
	std::vector<std::pair<std::string, int>> res;
	for (auto& p : mp)
		res.push_back(p);
	std::sort(res.begin(), res.end(), [](auto& a, auto& b) {return a.second > b.second; });
	for (int i{}; i < res.size() && i<3; i++)
		std::cout << res[i].first <<" -> "<<res[i].second<< std::endl;
	system("pause");
	show_menu();

}


void Menu::get_phones_from_file(std::string file_path) {
	std::ifstream file(file_path);
	if (!file.is_open() && !file.good()) {
		file.close();
		throw "Cannot open " + file_path;
	}
	std::string line;
	while (std::getline(file, line)) {
		std::string brand_name;
		std::string model_name;
		std::string form_factor;
		unsigned int year_of_issue;
		std::pair<unsigned int, unsigned int> screen_size;
		double price;
		int seg{};
		std::string temp{};
		for (auto c : line) {
			if (c == ';') {
				std::cout << temp << std::endl;
				if (seg == 0) brand_name = temp;
				else if (seg == 1) model_name = temp;
				else if (seg == 2) form_factor = temp;
				else if (seg == 3) year_of_issue = std::stoi(temp);
				else if (seg == 4) {
					int space{};
					for (auto cc : temp) {
						if (cc == ' ')
							break;
						space++;
					}
					screen_size = { std::stoi(temp.substr(0, space)), std::stoi(temp.substr(space + 1, temp.size())) };
				}
				else if (seg == 5) price = std::stod(temp);
				temp = "";
				seg++;
				continue;
			}
			temp += c;
		}
		phones.push_back(new Phone(brand_name, model_name, form_factor, year_of_issue, screen_size, price));
	}
	file.close();

}

void Menu::clear_console() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	std::cout << "|Author: Michal Wesolowski|\n";
	std::cout << "---------------------------\n";
}

Menu::~Menu() {
	std::ofstream f("saved_db.txt");
	std::string temp{};

	for (auto& p : phones) {
		temp += p->get_brand_name() + ";";
		temp += p->get_model_name() + ";";
		temp += p->get_form_factor() + ";";
		temp += std::to_string(p->get_year_of_issue()) + ";";
		temp += std::to_string(p->get_screen_size().first) + ' ';
		temp += std::to_string(p->get_screen_size().second) + ";";
		temp += std::to_string(p->get_price()) + ";\n";
	}
	f << temp;
	f.close();
	for (std::vector<Phone*>::iterator it = phones.begin(); it != phones.end(); it++)
		delete* it;
}