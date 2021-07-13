#include <iostream>
#include <string> // for string class
#include <ctime>

using namespace std;

/*#define HIGHRISK 0
#define DEFAULTED 1
#define MEDIUMRISK 2*/

typedef enum {
    HIGHRISK = 0,
    DEFAULTED,
    MEDIUMRISK
} categories;

#define PUBLIC 0
#define PRIVATE 1

class ITrade
{
public:
	ITrade(void);
	~ITrade(void);

	/********************variaveis****************************/
	double lvalue;				 //indicates the transaction amount in dollars
	unsigned char lclientSector; //indicates the client ́s sector which can be "Public" or "Private"
	tm lnextPaymentDate;		 //indicates when the next payment from the client to the bank is expected
	tm lreferenceDate;
	int lnumbertrades;
	unsigned char lcategories;

	/********************Metodos****************************/
	void setValue(double value);
	double getValue();
	//------------------------------------------------------
	void setSector(unsigned char sector);
	unsigned char getSector();
	//------------------------------------------------------
	void setnextPayment(struct tm nextPayment);
	tm getnextPayment();
	void setreferenceDate(struct tm nextPayment);
	tm getreferenceDate();
	//------------------------------------------------------
	void setnumbertrades(int value);
	int getnumbertrades();
	//------------------------------------------------------
	void setcategorie(unsigned char value);
	unsigned char getcategorie();
};
