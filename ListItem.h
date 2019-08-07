#include <iostream>

#pragma once

class ListItem {
    private:
        std::string name;
		double quantity{ 0 };
		std::string weightUnit;
		

	public:
		ListItem(std::string name, double quantity, std::string weightUnit);
		~ListItem();

		std::string getName();
		double getQuantity();
		std::string getWeightUnit();
		
		void setName(std::string name);
		void setQuantity(double quantity);
		void setWeightUnit(std::string weightUnit);
		

};
