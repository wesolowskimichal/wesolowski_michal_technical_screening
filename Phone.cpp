#include "Phone.h"

Phone::Phone(std::string brand_name, 
			 std::string model_name, 
			 std::string form_factor, 
			 unsigned int year_of_issue, 
			 std::pair<unsigned int, unsigned int> screen_size, 
			 double price) : brand_name(brand_name), 
							 model_name(model_name), 
							 form_factor(form_factor), 
							 year_of_issue(year_of_issue), 
							 screen_size(screen_size), 
							 price(price) {}


Phone::Phone(std::string brand_name,
			 std::string model_name,
			 std::string form_factor,
			 unsigned int year_of_issue,
			 unsigned int screen_width,
			 unsigned int screen_height,
			 double price) : brand_name(brand_name),
							 model_name(model_name),
							 form_factor(form_factor),
							 year_of_issue(year_of_issue),
							 screen_size({screen_width, screen_height}),
							 price(price) {}

std::string Phone::to_string() {
	return "{" + brand_name + ", " + model_name + ", " + form_factor + ", " + std::to_string(year_of_issue) + ", " + '{' + std::to_string(screen_size.first) + ", " + std::to_string(screen_size.second) + "}, " + std::to_string(price) + '}';
}

std::string Phone::get_brand_name() const {
	return this->brand_name;
}

std::string Phone::get_model_name() const {
	return this->model_name;
}

std::string Phone::get_form_factor() const {
	return this->form_factor;
}

unsigned int Phone::get_year_of_issue() const {
	return this->year_of_issue;
}

std::pair<unsigned int, unsigned int> Phone::get_screen_size() const {
	return this->screen_size;
}

double Phone::get_price() const {
	return this->price;
}
