#include <string.h>
#include "ListUtil.h"

void strTidy(std::string &str){
    
    strRemove(str, "%20", " ");
    
    strRemove(str, "one ", " 1 ");
    strRemove(str, "two ", " 2 ");
    strRemove(str, "to ", " 2 ");
    strRemove(str, "free ", " 3 ");
    strRemove(str, "three ", " 3 ");
    strRemove(str, "for ", " 4 ");
    strRemove(str, "four ", " 4 ");
    strRemove(str, "five ", " 5 ");
    strRemove(str, "six ", " 6 ");
    strRemove(str, "seven ", " 7 ");
    strRemove(str, "eight ", " 8 ");
    strRemove(str, "nine ", " 9 ");
    strRemove(str, "ten ", " 10 ");

    strRemove(str, " all of the ", " ");

    strRemove(str, " had ", " add ");
    strRemove(str, " at ", " add ");
    
    strRemove(str, " removed ", " remove ");
    
    strRemove(str, "an ", "1");
    strRemove(str, "more ", "");
    strRemove(str, "some ", "");
    strRemove(str, "another ", "1 ");
    strRemove(str, "pack ", "");
    strRemove(str, "packs ", "");
    strRemove(str, "jar ", "");
    strRemove(str, "jars ", "");
    strRemove(str, "packet ", "");
    strRemove(str, "packets ", "");
    strRemove(str, "of ", "");
    
    strRemove(str, " kgs ", " kg ");
    strRemove(str, " kilogram ", " kg ");
    strRemove(str, " kilograms ", " kg ");
    strRemove(str, " lbs ", " lb ");
    strRemove(str, " pound ", " lb ");
    strRemove(str, " pounds ", " lb ");
}

void strRemove(std::string &str, const std::string target, const std::string replacement){
    size_t found = str.find(target);

    while(found != std::string::npos){
        str.replace(found, target.size(), replacement);
        found = str.find(target);
    }
}


void updateList(std::unique_ptr<List> &list, std::string &str) {
    strTidy(str);
    if (str != ""){
        auto strVec = strToStrVector(str, " and ");
        strsToList(list, strVec);
    }
    
}


void strsToList(std::unique_ptr<List> &list, const std::unique_ptr<std::vector<std::string>> &strs) {
	static bool remove{ false };
	std::string buffer{};
	double quantity{ 0 };
	std::string weightUnit;
	
	for (auto &str : *strs) {
		removeFrontSpace(str);
		if (str.find("add ") != std::string::npos) {
			remove = false;
			buffer = str.substr(strlen("add "));
			removeFrontSpace(buffer);
		}
		else if (str.find("remove ") != std::string::npos) {
			remove = true;
			buffer = str.substr(strlen("remove "));
			removeFrontSpace(buffer);
		}
		else {
			buffer = str;
		}

		quantity = getQuantityFromStr(buffer);

		if (quantity != 0 && remove) {	
			quantity *= -1;
		}

		else if (quantity == 0) {
			if (remove) {
				quantity = -9999999;
			}
			else {
				quantity = 1;
			}
		}
		weightUnit = getUnitFromStr(buffer);
		removeFrontSpace(buffer);
		list->updateListItem(buffer, quantity, weightUnit);
	}
}

std::unique_ptr<std::vector<std::string>> strToStrVector(const std::string str, const std::string target) {
	auto ret = std::make_unique<std::vector<std::string>>();
	std::string buffer{};
	int current{ 0 };
	size_t found = str.find(target);

	while (found != std::string::npos) {
		buffer = str.substr(current, found - current);
		ret->push_back(buffer);
		current = found + target.length();
		found = str.find(target, current);
	}

	if (found == std::string::npos) {
		buffer = str.substr(current);
		ret->push_back(buffer);
	}
	return ret;
}

std::string getUnitFromStr(std::string &str) {
	const std::vector<std::string> weightUnits{ "kg ", "kgs ", "lb ", "lbs " };
	std::string unit{};
	for (auto &i : weightUnits) {
		size_t foundpos = str.find(i);
		if (foundpos != std::string::npos) {
			unit = str.substr(foundpos, i.size() - 1);
			str.erase(0, unit.size() + 1);
			size_t strEnd{ unit.find('s') };
			if (strEnd != std::string::npos) {
				unit.erase(strEnd, 1);
			}
			return unit;
		}
	}
	return "";
}

double getQuantityFromStr(std::string &str) {
	int found = str.find_first_of("123456789");
	if (found != -1) {
		int ret = stoi(str.substr(found));
		str.erase(0, str.find_first_not_of("123456789"));
		return ret;
	}
	else {
		return 0;
	}
}
void removeFrontSpace(std::string &str) {
	str.erase(0, str.find_first_not_of(' '));
}
