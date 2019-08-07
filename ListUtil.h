#include "List.h"

#pragma once

void strTidy(std::string &str);

void updateList(std::unique_ptr<List> &list, std::string &str);

void strRemove(std::string &str, const std::string target, const std::string replacement);

std::unique_ptr<std::vector<std::string>> strToStrVector(const std::string str, const std::string target);

void strsToList(std::unique_ptr<List> &list, const std::unique_ptr<std::vector<std::string>>& strs);

std::string getUnitFromStr(std::string &str);

double getQuantityFromStr(std::string &str);

void removeFrontSpace(std::string &str);