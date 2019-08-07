#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>
#include "ListItem.h"

#pragma once
class List {
	private:
		std::vector<std::unique_ptr<ListItem>>mylist;

		void addListItem(std::string name, double quantity, std::string weightUnit);

		void removeListItem(std::string name);

		void removeListItem(std::vector<std::unique_ptr<ListItem>>::iterator &it);

	public:
		std::vector<std::unique_ptr<ListItem>>::iterator searchList(std::string str);

		void updateListItem(std::string name, double quantity, std::string weightUnit = "");

		void display();
        
        std::string jsonify();
        
        void reset();

};