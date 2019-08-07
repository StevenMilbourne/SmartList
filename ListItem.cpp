#include "ListItem.h"

ListItem::ListItem(std::string name, double quantity, std::string weightUnit) :name{ name }, quantity{ quantity }, weightUnit { weightUnit } {}
ListItem::~ListItem() {}

std::string ListItem::getName() { return name; }
double ListItem::getQuantity() { return quantity; }
std::string ListItem::getWeightUnit() { return weightUnit; }

void ListItem::setName(std::string name) { this->name = name; }
void ListItem::setQuantity(double quantity) { this->quantity += quantity; }
void ListItem::setWeightUnit(std::string weightUnit) { this->weightUnit = weightUnit; }
