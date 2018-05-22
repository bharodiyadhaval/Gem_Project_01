#include "cPerson.h"
#include <list>
#include <string>
#include <iostream>
#include<iomanip>
#include"iPersonMotron.h"

class StandardList : public iPersonMotron {

public:





	std::vector< std::string > vecFemaleNames;
	std::vector< std::string > vecMaleNames;
	std::vector< std::string > vecLastNames;
	std::string error;
	std::vector<sPerson> vecSorted;


	std::list< std::string > listFemaleNames;
	std::list< std::string > listMaleNames;
	std::list< std::string > listLastNames;
	std::list<sPerson> listPeople;
	std::list<sPerson> listPeopleToFind;
	std::list<sPerson> listSorted;
	std::list<sPerson>::iterator itp;
	std::list<sPerson>::iterator itp2;
	sPerfData pData;


//1
virtual bool LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName);

//2
virtual	bool GenerateRandomPeople(int numberOfPeople);

//3
virtual	bool FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople = INT_MAX);

//4
virtual bool FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople = INT_MAX);

//5
virtual bool FindPersonByID(sPerson &person, unsigned long long uniqueID);

//6
virtual bool FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius,int maxPeopleToReturn = INT_MAX);

//7
virtual bool FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth,int maxPeopleToReturn = INT_MAX);

//8
virtual bool FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn = INT_MAX);

//9
virtual bool SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType);

//10
virtual bool GetPerformanceFromLastCall(sPerfData &callStats);

//11
virtual eContainerType getContainerType(void);

};

