// CreditSuisse_portfolio.cpp : Defines the entry point for the console application.
//
/*
input
m /d /a
12/11/2020
4
2000000 Private 12/29/2025
400000 Public 07/01/2020
5000000 Public 01/02/2024
3000000 Public 10/26/2023

Sample output
HIGHRISK
DEFAULTED
MEDIUMRISK
MEDIUMRISK

*/
#include "stdafx.h"
#include "ITrade.h"
#include <string> // for string class
#include <iostream>
#include <ctime>
#include <list>
#pragma warning(disable : 4996)

/*
struct tm {
   int tm_sec;   // seconds of minutes from 0 to 61
   int tm_min;   // minutes of hour from 0 to 59
   int tm_hour;  // hours of day from 0 to 24
   int tm_mday;  // day of month from 1 to 31
   int tm_mon;   // month of year from 0 to 11
   int tm_year;  // year since 1900
   int tm_wday;  // days since sunday
   int tm_yday;  // days since January 1st
   int tm_isdst; // hours of daylight savings time
};*/



void printdate(tm date) 
{
	cout << date.tm_mon+1 << "/" << date.tm_mday << "/" << date.tm_year+1900 << endl; 
}

void printoutput(tm getreferenceDate, int lnumbertrades, list<ITrade> tradeList)
{
	printdate(getreferenceDate);
    cout << lnumbertrades << endl;

	for (auto tList : tradeList)
	{
		switch (tList.getcategorie())
		{
			case  HIGHRISK:
				cout << "HIGHRISK" << endl;
				break;
			case  DEFAULTED:
				cout << "DEFAULTED" << endl;
				break;
			case  MEDIUMRISK:
				cout << "MEDIUMRISK" << endl;
				break;

			default:
				break;
		}
	}
}

void updatecategorie(ITrade *pCS)
{
	if(pCS->getValue() < 1000000) 
	{
		time_t x = mktime(&pCS->getreferenceDate());
		time_t y = mktime(&pCS->getnextPayment());

		if ( x != (time_t)(-1) && y != (time_t)(-1) )
		{
			double difference = std::difftime(y, x) / (60 * 60 * 24);
			//cout << std::ctime(&x);
			//cout << std::ctime(&y);
			//cout << "difference = " << difference << " days" << endl;
			if(difference < -30)
				pCS->setcategorie(DEFAULTED);
		}
	}else
	{
		if(pCS->getSector() == PRIVATE)
		{
			pCS->setcategorie(HIGHRISK);
		}else
		{
			pCS->setcategorie(MEDIUMRISK);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ITrade CS;
	list<ITrade> lp;

	tm tm1 = {0,0,0,11,12-1,120}; /* 12/11/2020*/
	CS.setreferenceDate(tm1);
	CS.setnumbertrades(4);
	
	tm tm2 = {0,0,0,29,12-1,125}; /* 12/29/2025 */
	CS.setnextPayment(tm2);
	CS.setValue(2000000);
	CS.setSector(PRIVATE);
	updatecategorie(&CS);
	lp.push_back(CS); //2000000 Private 12/29/2025

	tm tm3 = {0,0,0,01,7-1,120}; /* 07/01/2020 */
	CS.setnextPayment(tm3);
	CS.setValue(400000);
	CS.setSector(PUBLIC);
	updatecategorie(&CS);
	lp.push_back(CS); //400000 Public 07/01/2020

	tm tm4 = {0,0,0,2,1-1,124}; /* 01/02/2024 */
	CS.setnextPayment(tm3);
	CS.setValue(5000000);
	CS.setSector(PUBLIC);
	updatecategorie(&CS);
	lp.push_back(CS); //5000000 Public 01/02/2024

	tm tm5 = {0,0,0,26,10-1,123}; /* 10/26/2023 */
	CS.setnextPayment(tm3);
	CS.setValue(3000000);
	CS.setSector(PUBLIC);
	updatecategorie(&CS);
	lp.push_back(CS); //3000000 Public 10/26/2023

	printoutput(CS.getreferenceDate(), CS.getnumbertrades(), lp);

	system("pause");
	return 0;
}


