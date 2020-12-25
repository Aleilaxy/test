#pragma once
#ifndef GETDATA_H_
#define GETDATA_H_
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

#define S_ARR 2
#define R_ARR 2

typedef struct tableform {
	void *tablepos = NULL;
	char *tablename = "";
};

typedef struct dataform {
	void *datapos = NULL;
	char *dataname = "";
};


void getDataFromTbl();



#endif