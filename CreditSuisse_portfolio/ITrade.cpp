#include "stdafx.h"
#include "ITrade.h"


ITrade::ITrade(void)
{

}


ITrade::~ITrade(void)
{
}

//------------------------------------------------------

void ITrade::setValue(double value)
{
	lvalue = value;
}

double ITrade::getValue()
{
	return lvalue;
}

//------------------------------------------------------
void ITrade::setSector(unsigned char sector)
{
	lclientSector = sector;
}

unsigned char ITrade::getSector()
{
	return lclientSector;
}
//------------------------------------------------------
void ITrade::setnextPayment(struct tm nextPayment)
{
	lnextPaymentDate = nextPayment;
	/*cout << "Year:" << nextPayment.tm_year <<endl;
    cout << "Month: "<<nextPayment. tm_mon << endl;
    cout << "Day: "<< nextPayment.tm_mday << endl;*/
}

tm ITrade::getnextPayment()
{
	return lnextPaymentDate;
}
void ITrade::setreferenceDate(struct tm referenceDate)
{
	lreferenceDate = referenceDate;
	/*cout << "Year:" << lreferenceDate.tm_year <<endl;
    cout << "Month: "<<lreferenceDate. tm_mon << endl;
    cout << "Day: "<< lreferenceDate.tm_mday << endl;*/
}

tm ITrade::getreferenceDate()
{
	return lreferenceDate;
}
//------------------------------------------------------
void ITrade::setnumbertrades(int numbertrades)
{
	lnumbertrades = numbertrades;
}

int ITrade::getnumbertrades()
{
	return lnumbertrades;
}
//------------------------------------------------------
void ITrade::setcategorie(unsigned char value)
{
	lcategories = value;
}

unsigned char ITrade::getcategorie()
{
	return lcategories;
}