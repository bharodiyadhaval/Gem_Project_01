#ifndef _StandardMap_HG_
#define _StandardMap_HG_

#include <string>
#include <map>
#include <algorithm>
#include "cPerson.h"
#include <iostream>
#include "iPersonMotron.h"

class StandardMap: public iPersonMotron{
	
public:


	std::vector< std::string > vecFemaleNames;
	std::vector< std::string > vecMaleNames;
	std::vector< std::string > vecLastNames;
	std::string error;
	std::vector<sPerson> vecSorted;

	std::map <int, std::string> mapMaleNames;
	std::map <int, std::string> mapFemaleNames;
	std::map <int, std::string> mapLastNames;
	std::map <int, sPerson> mapPeople;
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
	virtual bool FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn = INT_MAX);

	//7
	virtual bool FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn = INT_MAX);

	//8
	virtual bool FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn = INT_MAX);

	//9
	virtual bool SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType);

	//10
	virtual bool GetPerformanceFromLastCall(sPerfData &callStats);

	//11
	virtual eContainerType getContainerType(void);
};








#endif