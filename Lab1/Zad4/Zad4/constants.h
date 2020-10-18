#pragma once
#include <string>

// break function
const char LINE_CHAR = '=';
const int LINE_LEN = 50;


// procedurest test
std::string PROC_TAB_NAME = "Imie";
const int PROC_BASE_TAB_LEN = -1;
const std::string PROC_MODIFY_AS_ARGUMENT = "Modify using object as argument";
const std::string PROC_MODIFY_AS_REFERENCE = "Modify using reference";
const int PROC_NEW_TAB_LEN = 10;

// test cloning 
std::string DYN_JANUSZ_NAME = "Janusz";
std::string DYN_ALBERT_NAME = "Albert";
std::string DYN_ZBIGNIEW_NAME = "Zbiegniew";
const int DYN_JANUSZ_LEN = -5;
const std::string DYN_CHANGE_TAB_TO_ALBERT = "Change name table2 to Albert";
const std::string DYN_CHANGE_TAB_TO_ZBIGNIEW = "Change name table3 to Zbigniew";

// test arrays 
const int ARR_STAT_SIZE = 5;
const std::string ARR_STAT_CREATE_INFO = "Creating array of 5 objects 'Table' (static): ";
const std::string ARR_DYN_CREATE_INFO = "Creating array of 5 objects 'Table' (dynamic): ";