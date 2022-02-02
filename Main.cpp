#include <string>
#include <iostream>
#include <memory>
using namespace std;

/*
Problem
We want to construct a complex object, however we do not want to have a complex constructor member or
one that would need many arguments.
Solution
Define an intermediate object whose member functions define the desired object part by part before the object 
is available to the client. Builder Pattern lets us defer the construction of the object until all the options 
for creation have been specified.
*/
class Tank {

private:
	std::string sDriver;
	std::string sGunType;
	std::string sArmour;
public:
	void setDriver(const std::string& sDriverIn) {
		this->sDriver = sDriverIn;
	}
	void setGunType(const std::string& sGunTypeIn) {
		this->sGunType =  sGunTypeIn;
	}
	void setArmour(const std::string& sArmourIn) {
		this->sGunType = sArmourIn;
	}
	void form() const {
		std::cout << "The tank has " <<
		sDriver << ", " << sArmour << ", " << sGunType << "." <<std::endl;
	}

};

class TankBuilder {
protected:
	std::unique_ptr<Tank> mTank;
public:
	virtual ~TankBuilder() = default;
	void createNewTank() {
		mTank = std::make_unique<Tank>();
	}
	Tank* getTank() {
		return mTank.release();
	}
	virtual void buildDriver(std::string sDriverIn) = 0;
	virtual void buildGun(std::string sGunIn) = 0;
	virtual void buildArmour(std::string sArmourIn) = 0;

};






int main() {
	
}


