#include "List.h"

std::vector<std::unique_ptr<ListItem>>mylist;

void List::addListItem(std::string name, double quantity, std::string weightUnit) {
    mylist.push_back(std::make_unique<ListItem>(name, quantity, weightUnit));
}

void List::removeListItem(std::string name) {
    mylist.erase(searchList(name));
}

void List::removeListItem(std::vector<std::unique_ptr<ListItem>>::iterator &it) {
    mylist.erase(it);
}

std::vector<std::unique_ptr<ListItem>>::iterator List::searchList(std::string str) {
    return std::find_if(mylist.begin(), mylist.end(), [str](const std::unique_ptr<ListItem>& li) { return li->getName() == str; });
}

void List::updateListItem(std::string name, double quantity, std::string weightUnit) {
    auto it = searchList(name);

    if (it != mylist.end()) {
        if ((*it)->getQuantity() + quantity <= 0) {
            removeListItem(it);
        }
        else {
            (*it)->setQuantity(quantity);
        }
    }
    else if (it == mylist.end() && quantity > 0) {
        addListItem(name, quantity, weightUnit);
    }
}

void List::display() {
    std::cout << "\n===============" << std::endl;
    for (const auto &i : mylist) {
        double quantity = i->getQuantity();
        std::string weightUnit = i->getWeightUnit();
        std::cout << i->getName();
        if ((quantity > 1) || (quantity == 1 && !weightUnit.empty())) {
            std::cout << "\t\t" << quantity << " " << weightUnit << std::endl;
        }
        else {
            std::cout << std::endl;
        }
    }
    std::cout << "\n===============" << std::endl;
}


std::string List::jsonify(){
    std::string ret = "{ \"list\":[";
    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        ret += "{\"name\": \"";
        ret += (*it)->getName();
        ret += "\", \"quantity\":";
        ret += std::to_string((*it)->getQuantity());
        ret += ", \"weightunit\": \"";
        ret += (*it)->getWeightUnit();
        ret += "\"}";
        
        if (it != mylist.end()-1){
            ret += ",";
        }
    }
    ret += "]} ";
    return ret;
}

void List::reset(){
    mylist.clear();
}