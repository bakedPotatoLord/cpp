
#include <string>

using namespace std;

class Inventory {
private:
	unsigned int serialNum;
	string manufactureDate;
	unsigned int lotnum;
public:
	Inventory();
	Inventory(int, string, int);

	int getSerialNum() const;
	void setSerialNum(unsigned int);
	string getManufactureDate() const;
	void setmanufactureDate(string);
	int getLotNum() const;
	void setLotNum(unsigned int);

};