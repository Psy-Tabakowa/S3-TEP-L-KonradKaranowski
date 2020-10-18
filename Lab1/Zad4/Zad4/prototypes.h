#pragma once
#include "Table.h"


// test functions
void test_procedures();
void test_dynamic_static_allocation();
void test_create_array_objects_static();
void test_create_array_objects_dynamic(int array_size);
// helper functions
void mod_tab(Table* table, int new_size);
void mod_tab(Table table, int new_size);
void show_lines();