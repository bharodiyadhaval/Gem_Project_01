#include "StandardList.h"
#include "Support.h"





bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

//1
bool StandardList::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
{
	StartPerformance(pData);

	if (!loadDataIntoVector(firstNameFemaleFileName, vecFemaleNames,
		firstNameMaleFileName, vecMaleNames,
		lastNameFileName, vecLastNames, error))
	{
		std::cout << "Error: " << error << std::endl;
		return -1;
	}

	for (int i = 0; i < vecFemaleNames.size(); i++)
	{
		listFemaleNames.push_back(vecFemaleNames[i]);
	}

	for (int i = 0; i < vecMaleNames.size(); i++)
	{
		listMaleNames.push_back(vecMaleNames[i]);
	}

	for (int i = 0; i < vecLastNames.size(); i++)
	{
		listLastNames.push_back(vecLastNames[i]);
	}

	EndPerformanceData(pData);
}

//2
bool StandardList::GenerateRandomPeople(int numberOfPeople)
{
	listPeople.clear();
	StartPerformance(pData);
	//srand(time(NULL));
	int random;
	unsigned long long Id = 1;
	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		sPerson p1;
		sPoint s1;
		std::list<std::string>::iterator it1;
		std::list<std::string>::iterator it2;
		random = rand() % 1000 + 1;
		int maleFirst = rand() % listMaleNames.size();
		int maleLast = rand() % listLastNames.size();
		int femaleFirst = rand() % listFemaleNames.size();
		int femaleLast = rand() % listLastNames.size();
		
		if (random % 2 == 0)
		{
			it1 = listFemaleNames.begin();
			for (int i = 0; i < femaleFirst; i++)
			{
				it1++;
			}
			it2 = listLastNames.begin();
			for (int i = 0; i < femaleLast; i++)
			{
				it2++;
			}

			p1.first = *it1;
			p1.last = *it2;

			
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.age = rand() % 90 + 1;
			p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
		
		}
		else
		{
			it1 = listMaleNames.begin();
			for (int i = 0; i < maleFirst; i++)
			{
				it1++;
			}
			it2 = listLastNames.begin();
			for (int i = 0; i < maleLast; i++)
			{
				it2++;
			}

			p1.first = *it1;
			p1.last = *it2;
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 90 + 1;
			p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
		
		
		}
		listPeople.push_back(p1);
		Id++;
	}

	int i = 0;
	for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
		std::cout 
			<< i + 1
			<< "     ( " << itp->uniqueID << " )    "
			<< itp->first
			<< "       " << itp->last 
			<< "        Age:" <<itp->age
			<< "       Health:" << itp->health
			<< "        Location ( "<<itp->location.x<<", "<< itp->location.y <<", "<< itp->location.z <<")"<< std::endl;
		i++;
	}
	EndPerformanceData(pData);
	return 0;
}

//3
bool StandardList::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople )
{
	vecPeople.clear();
	StartPerformance(pData);
	int	i = 0,j=0;
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		i = 0; j = 0;
		itp = listPeople.begin();
		while (true)
		{
			
			if (itp->first == personToMatch.first)
			{
				vecPeople.push_back(*itp);
				std::cout
					<< i + 1
					<< "     ( " << itp->uniqueID << " )    "
					<< itp->first
					<< "       " << itp->last
					<< "        Age:" << itp->age
					<< "       Health:" << itp->health
					<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
				j++;
			}
			itp++;
			i++;
			if (j >= maxNumberOfPeople || itp==listPeople.end())
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length() == 0 && personToMatch.last.length() > 0)
	{
		i = 0; j = 0;
		itp = listPeople.begin();
		while (true)
		{

			if (itp->last == personToMatch.last)
			{
				vecPeople.push_back(*itp);

				std::cout
					<< i + 1
					<< "     ( " << itp->uniqueID << " )    "
					<< itp->first
					<< "       " << itp->last
					<< "        Age:" << itp->age
					<< "       Health:" << itp->health
					<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
				j++;
			}
			itp++;
			i++;
			if (j >= maxNumberOfPeople || itp == listPeople.end())
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length()>0 && personToMatch.last.length()>0)
	{
		i = 0; j = 0;
		itp = listPeople.begin();
		while (true)
		{

			if (itp->first == personToMatch.first && itp->last == personToMatch.last)
			{
				vecPeople.push_back(*itp);

				std::cout		
					<< i + 1
					<< "     ( " << itp->uniqueID << " )    "
					<< itp->first
					<< "       " << itp->last
					<< "        Age:" << itp->age
					<< "       Health:" << itp->health
					<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
				j++;
			}
			itp++;
			i++;
			if (j >= maxNumberOfPeople || itp == listPeople.end())
			{
				//return 0;
				break;
			}

		}
	}
	
	EndPerformanceData(pData);
	if (j == 0)
	{
		return 1;
	}
	return 0;
}

//4
bool StandardList::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);
	int	i = 0,
		j = 0;

	std::list<sPerson> listPeopleToMatch;
	std::list<sPerson>::iterator itp2;
	
	for (int i = 0; i < vecPeopleToMatch.size(); i++)
	{
		listPeopleToMatch.push_back(vecPeopleToMatch[i]);
	}


	for (itp2=listPeopleToMatch.begin();itp2!=listPeopleToMatch.end();itp2++)
	{
		if (itp2->first.length() > 0 && itp2->last.length() == 0)
		{
			
			i = 0;
			for(itp=listPeople.begin();itp!=listPeople.end();itp++)
			{
				if (itp->first == itp2->first && j < maxNumberOfPeople)
				{
					vecPeople.push_back(*itp);

					std::cout
						<< i + 1
						<< "     ( " << itp->uniqueID << " )    "
						<< itp->first
						<< "       " << itp->last
						<< "        Age:" << itp->age
						<< "       Health:" << itp->health
						<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
					j++;
				}
				i++;

			}
		}
		else if (itp2->first.length() == 0 && itp2->last.length() > 0)
		{
			
			
			for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
			{

				if (itp->last == itp2->last && j< maxNumberOfPeople)
				{
					vecPeople.push_back(*itp);

					std::cout
						<< i + 1
						<< "     ( " << itp->uniqueID << " )    "
						<< itp->first
						<< "       " << itp->last
						<< "        Age:" << itp->age
						<< "       Health:" << itp->health
						<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
					j++;
				}
				
				i++;
			
			}
		}
		else if (itp2->first.length()>0 && itp2->last.length()>0)
		{
			
			
			for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
			{

				if (itp->first == itp2->first && itp->last == itp2->last && j < maxNumberOfPeople)
				{
					vecPeople.push_back(*itp);

					std::cout
						<< i + 1
						<< "     ( " << itp->uniqueID << " )    "
						<< itp->first
						<< "       " << itp->last
						<< "        Age:" << itp->age
						<< "       Health:" << itp->health
						<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
					j++;
				}
				
				i++;
				

			}
		}
		
	}
	EndPerformanceData(pData);
	if (j == 0)
	{
		return 1;
	}
	return 0;
}

//5
bool StandardList::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	//vecPeople.clear();
	StartPerformance(pData);
	for (itp=listPeople.begin();itp!=listPeople.end();itp++)
	{
		if (uniqueID == itp->uniqueID)
		{
			person.first = itp->first;
			person.last = itp->last;
			person.uniqueID = itp->uniqueID;
			person.health = itp->health;
			person.location = itp->location;
			
			//vecPeople.push_back(*itp);


			std::cout
				
				<< "( " << itp->uniqueID << " )    "
				<<				itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "    Health:" << itp->health
				<< "    Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			break;
		}
		
	}
	EndPerformanceData(pData);
	return 0;

}

//6
bool StandardList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{	
	vecPeople.clear();
	StartPerformance(pData);
	int count = 0;
	float distancer;
	int j = 0;

	//for (int j = 0; j < listPeople.size(); j++)
	for	(itp = listPeople.begin(); itp != listPeople.end(); itp++)
	{
		distancer = powf(location.x - itp->location.x, 2) + powf(location.y - itp->location.y, 2) + powf(location.z - itp->location.z, 2);
		if (   radius >=  distancer )
		{
			vecPeople.push_back(*itp);

			std::cout

				<< "( " << itp->uniqueID << " )    "
				<< itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "    Health:" << itp->health
				<< "    Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

	}
	EndPerformanceData(pData);
	if (count == 0)
	{
		return 1;
	}
	return 0;
}

//7
bool StandardList::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	StartPerformance(pData);
	int count;
	count = 0;
	vecPeople.clear();
	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "Your data is out of range" << std::endl;
	}
	else
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{

		if (itp->health >= minHealth && itp->health <= maxHealth)
		{
			vecPeople.push_back(*itp);

			std::cout
				<< count + 1 << "   "
				<< "( " << itp->uniqueID << " )    "
				<< itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "    Health:" << itp->health
				<< "    Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

		}
	}

	EndPerformanceData(pData);
	if (count == 0)
	{
		return 1;
	}
	return 0;
}

//8
bool StandardList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count;
	count = 0;
	float distancer;

	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "Your data is out of range" << std::endl;
	}
	else
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			distancer = powf(location.x - itp->location.x, 2) + powf(location.y - itp->location.y, 2) + powf(location.z - itp->location.z, 2);


		if (itp->health >= minHealth && itp->health <= maxHealth && radius >= distancer)
		{
			vecPeople.push_back(*itp);

			std::cout
				<< count + 1 << "   "
				<< "( " << itp->uniqueID << " )    "
				<< itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "    Health:" << itp->health
				<< "    Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

		}
	}
	EndPerformanceData(pData);
	if (count == 0)
	{
		return 1;
	}
	return 0;
}

//9
bool StandardList::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	StartPerformance(pData);
	sPerson temp;
	vecPeople.clear();
	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (itp=listPeople.begin();itp!=listPeople.end();itp++)
		{
			for (itp2 = std::next(itp,1); itp2 != listPeople.end(); itp2++)
			{
				if (strcmp(itp->first.c_str(), itp2->first.c_str()) == 0)
				{
					if (strcmp(itp->last.c_str(), itp2->last.c_str()) > 0)
					{
						std::swap(*itp, *itp2);

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp->first.c_str(), itp2->first.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
				}
				
			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
			
	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (strcmp(itp->last.c_str(), itp2->last.c_str()) == 0)
				{
					if (strcmp(itp->first.c_str(), itp2->first.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp->last.c_str(), itp2->last.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{

		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (strcmp(itp->first.c_str(), itp2->first.c_str()) == 0)
				{
					if (strcmp(itp2->last.c_str(), itp->last.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp2->first.c_str(), itp->first.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->first
				<< "       " << itp->last
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}

	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (strcmp(itp->last.c_str(), itp2->last.c_str()) == 0)
				{
					if (strcmp(itp2->first.c_str(), itp->first.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp2->last.c_str(), itp->last.c_str()) > 0)
					{
						temp = *itp;
						*itp = *itp2;
						*itp2 = temp;

					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}

	}

	else if (sortType == ASC_BY_ID)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (itp->uniqueID > itp2->uniqueID)
				{
					temp = *itp;
					*itp = *itp2;
					*itp2 = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<<			 itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == DESC_BY_ID)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (itp2->uniqueID > itp->uniqueID)
				{
					temp = *itp;
					*itp = *itp2;
					*itp2 = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "     ( " << itp->uniqueID << " )    "
				<<			itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				<< "       Health:" << itp->health
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == ASC_BY_HEALTH)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (itp->health > itp2->health)
				{
					temp = *itp;
					*itp = *itp2;
					*itp2 = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "       Health:" << itp->health
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
	}

	else if(sortType == DESC_BY_HEALTH)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++)
		{
			for (itp2 = std::next(itp, 1); itp2 != listPeople.end(); itp2++)
			{
				if (itp2->health > itp->health)
				{
					temp = *itp;
					*itp = *itp2;
					*itp2 = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp++) {
			
			vecPeople.push_back(*itp);

			std::cout
				<< i + 1
				<< "       Health:" << itp->health
				<< "     ( " << itp->uniqueID << " )    "
				<< itp->last
				<< "       " << itp->first
				<< "        Age:" << itp->age
				
				<< "        Location ( " << itp->location.x << ", " << itp->location.y << ", " << itp->location.z << ")" << std::endl;
			i++;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

//10
bool StandardList::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                     Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                       Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                       Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                       Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

//11
eContainerType StandardList::getContainerType(void)
{
	StartPerformance(pData);

	EndPerformanceData(pData);
	return STD_LIST;
}
