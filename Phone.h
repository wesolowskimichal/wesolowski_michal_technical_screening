#pragma once
#include <string>
class Phone
{
	const std::string brand_name;
	const std::string model_name;
	const std::string form_factor;
	const unsigned int year_of_issue;
	const std::pair<unsigned int, unsigned int> screen_size;
	const double price;
public:
	Phone(std::string brand_name, std::string model_name, std::string form_factor, unsigned int year_of_issue, std::pair<unsigned int, unsigned int> screen_size, double price);
	Phone(std::string brand_name, std::string model_name, std::string form_factor, unsigned int year_of_issue, unsigned int screen_width, unsigned int screen_hight, double price);
	std::string to_string();
	std::string get_brand_name() const;
	std::string get_model_name() const;
	std::string get_form_factor() const;
	unsigned int get_year_of_issue() const;
	std::pair<unsigned int, unsigned int> get_screen_size() const;
	double get_price() const;
};

