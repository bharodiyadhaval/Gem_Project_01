#include "DIYList.h"
#include "Support.h"


bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

//1
bool DIYList::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
{
	StartPerformance(pData);

	if (!loadDataIntoVector(firstNameFemaleFileName, lvecFemaleNames,
		firstNameMaleFileName, lvecMaleNames,
		lastNameFileName, lvecLastNames, error))
	{
		std::cout << "Error: " << error << std::endl;
		return -1;
	}

	for (int i = 0; i < lvecFemaleNames.size(); i++)
	{
		listFemaleNames.push_back(lvecFemaleNames[i]);
	}

	for (int i = 0; i < lvecMaleNames.size(); i++)
	{
		listMaleNames.push_back(lvecMaleNames[i]);
	}

	for (int i = 0; i < lvecLastNames.size(); i++)
	{
		listLastNames.push_back(lvecLastNames[i]);
	}

	EndPerformanceData(pData);
	return 0;
}

bool DIYList::GenerateRandomPeople(int numberOfPeople)
{
	StartPerformance(pData);
	int random;
	unsigned long long Id = 1;

	
	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		sPerson p1;
		sPoint s1;
		DiyList<std::string>::diylist* it1;
		DiyList<std::string>::diylist* it2;
		random = rand() % 1000 + 1;

		int male = rand() % listMaleNames.size();
		int female = rand() % listFemaleNames.size();
		int malelast = rand() % listLastNames.size();

		if (random % 2 == 0)
		{
			it1 = listFemaleNames.begin();
			for (int i = 0; i < female; i++)
			{
				it1 = it1->next;
			}
			it2 = listLastNames.begin();
			for (int i = 0; i < malelast; i++)
			{
				it2 = it2->next;
			}

			p1.first = it1->myperson;
			p1.last = it2->myperson;
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 90 + 1;
			p1.health = random % 100 + 1;
		}
		else
		{
			it1 = listMaleNames.begin();
			for (int i = 0; i < male; i++)
			{
				it1 = it1->next;
			}
			it2 = listLastNames.begin();
			for (int i = 0; i < malelast; i++)
			{
				it2 = it2->next;
			}
			p1.first = it1->myperson;
			p1.last = it2->myperson;
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 90 + 1;
			p1.health = random % 100 + 1;

		}
		listPeople.push_back(p1);
		Id++;

	}
	
	for (itp = listPeople.begin(); itp->next != 0; itp=itp->next) {
	
		std::cout
	<< "     ( " << itp->myperson.uniqueID << " )    "
	<< itp->myperson.first
	<< "       " << itp->myperson.last
	<< "      age:"<< itp->myperson.age
	<< "       Health:" << itp->myperson.health
	<< "        Location ( "<<itp->myperson.location.x<<", "<< itp->myperson.location.y <<", "<< itp->myperson.location.z <<")"<< std::endl;
	
	}

	EndPerformanceData(pData);
	return 0;
}

bool DIYList::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);


	int	i = 0, j = 0;
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		itp = listPeople.begin();
		i = 0; j = 0;
		while (true)
		{
			if (itp->myperson.first == personToMatch.first)
			{
				vecPeople.push_back(itp->myperson);
				std::cout
					<< i + 1
					<< "     ( " << itp->myperson.uniqueID << " )    "
					<< itp->myperson.first
					<< "       " << itp->myperson.last
					<< "      Age:"<<itp->myperson.age
					<< "       Health:" << itp->myperson.health
					<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
				j++;
			}
			itp = itp->next;
			i++;
			if (j >= maxNumberOfPeople || itp->next == 0)
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length() == 0 && personToMatch.last.length() > 0)
	{
		itp = listPeople.begin();
		i = 0; j = 0;
		while (true)
		{

			if (itp->myperson.last == personToMatch.last)
			{
				vecPeople.push_back(itp->myperson);

				std::cout
					<< i + 1
					<< "     ( " << itp->myperson.uniqueID << " )    "
					<< itp->myperson.first
					<< "       " << itp->myperson.last
					<< "      Age:" << itp->myperson.age
					<< "       Health:" << itp->myperson.health
					<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
				j++;
			}
			itp = itp->next;
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
		itp = listPeople.begin();
		i = 0; j = 0;
		itp = listPeople.begin();
		while (true)
		{

			if (itp->myperson.first == personToMatch.first && itp->myperson.last == personToMatch.last)
			{
				vecPeople.push_back(itp->myperson);

				std::cout
					<< i + 1
					<< "     ( " << itp->myperson.uniqueID << " )    "
					<< itp->myperson.first
					<< "       " << itp->myperson.last
					<< "      Age:" << itp->myperson.age
					<< "       Health:" << itp->myperson.health
					<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
				j++;
			}
			itp = itp->next;
			i++;
			if (j >= maxNumberOfPeople || itp == listPeople.end())
			{
				//return 0;
				break;
			}

		}
	}
	else
	{
		std::cout << "\nNo Entries Found, Not Enough Data To Compare\n";
	}

	if (j == 0)
	{
		std::cout << "\n---------nNo Entries Found\n";
		return 1;

	}

	return 0;
}

bool DIYList::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);
	int	i = 0,
		j = 0;
	
	DiyList<sPerson> listPeopleToMatch;
	DiyList<sPerson>::diylist* itp2;

	for (int i = 0; i < vecPeopleToMatch.size(); i++)
	{
		listPeopleToMatch.push_back(vecPeopleToMatch[i]);
	}

	for (itp2 = listPeopleToMatch.begin(); itp2 != listPeopleToMatch.end(); itp2 = itp2->next)
	{
		if (itp2->myperson.first.length() > 0 && itp2->myperson.last.length() == 0)
		{
			for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
			{
				

				i = 0;

				if (itp->myperson.first == itp2->myperson.first && j<maxNumberOfPeople)
				{
					vecPeople.push_back(itp->myperson);
					std::cout
						<< i + 1
						<< "     ( " << itp->myperson.uniqueID << " )    "
						<< itp->myperson.first
						<< "       " << itp->myperson.last
						<< "      Age:" << itp->myperson.age
						<< "       Health:" << itp->myperson.health
						<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
					j++;
				}
				i++;
			}


		}
		else if (itp2->myperson.first.length() == 0 && itp2->myperson.last.length() > 0)
		{


			for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
			{

				if (itp->myperson.last == itp2->myperson.last && j< maxNumberOfPeople)
				{
					vecPeople.push_back(itp->myperson);
					std::cout
						<< i + 1
						<< "     ( " << itp->myperson.uniqueID << " )    "
						<< itp->myperson.first
						<< "       " << itp->myperson.last
						<< "      Age:" << itp->myperson.age
						<< "       Health:" << itp->myperson.health
						<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
					j++;
				}

				i++;

			}
		}
		else if (itp2->myperson.first.length()>0 && itp2->myperson.last.length()>0)
		{


			for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
			{

				if (itp->myperson.first == itp2->myperson.first && itp->myperson.last == itp2->myperson.last && j < maxNumberOfPeople)
				{
					vecPeople.push_back(itp->myperson);
					std::cout
						<< i + 1
						<< "     ( " << itp->myperson.uniqueID << " )    "
						<< itp->myperson.first
						<< "       " << itp->myperson.last
						<< "      Age:" << itp->myperson.age
						<< "       Health:" << itp->myperson.health
						<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
					j++;
				}

				i++;


			}
		}
		else
		{
			std::cout << "\nNo Entries Found, Not Enough Data To Compare\n";
			return 1;

		}

		
	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYList::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	StartPerformance(pData);

	for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
	{
		if (uniqueID == itp->myperson.uniqueID)
		{
			person.first = itp->myperson.first;
			person.last = itp->myperson.last;
			person.uniqueID = itp->myperson.uniqueID;
			person.health = itp->myperson.health;
			person.location = itp->myperson.location;

			std::cout

				<< "( " << itp->myperson.uniqueID << " )  "
				<< itp->myperson.last
				<< "       " << itp->myperson.last
				<< "      Age:" << itp->myperson.age
				<< "    Health:" << itp->myperson.health
				<< "    Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			break;
		}

	}
	EndPerformanceData(pData);
	return 0;

}

bool DIYList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	StartPerformance(pData);
	int count = 0;
	float distancer;

	vecPeople.clear();
	for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
	{
		distancer = powf(location.x - itp->myperson.location.x, 2) + powf(location.y - itp->myperson.location.y, 2) + powf(location.z - itp->myperson.location.z, 2);
		if (radius >= distancer)
		{
			vecPeople.push_back(itp->myperson);
			std::cout
				<< count + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.first
				<< "       " << itp->myperson.last
				<< "      Age:" << itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;

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

bool DIYList::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count;
	count = 0;
	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "Your data is out of range" << std::endl;
	}
	else
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{


			if (itp->myperson.health >= minHealth && itp->myperson.health <= maxHealth)
			{
				vecPeople.push_back(itp->myperson);
				std::cout
					<< count + 1 << "   "
					<< "( " << itp->myperson.uniqueID << " )    "
					<< itp->myperson.first
					<< "       " << itp->myperson.last
					<< "      Age:" << itp->myperson.age
					<< "    Health:" << itp->myperson.health
					<< "    Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
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

bool DIYList::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn)
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
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			distancer = powf(location.x - itp->myperson.location.x, 2) + powf(location.y - itp->myperson.location.y, 2) + powf(location.z - itp->myperson.location.z, 2);

			if (itp->myperson.health >= minHealth && itp->myperson.health <= maxHealth && radius >= distancer)
			{
				vecPeople.push_back(itp->myperson);
				std::cout
					<< count + 1 << "   "
					<< "( " << itp->myperson.uniqueID << " )    "
					<< itp->myperson.first
					<< "       " << itp->myperson.last
					<< "      Age:" << itp->myperson.age
					<< "    Health:" << itp->myperson.health
					<< "    Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
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

bool DIYList::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	vecPeople.clear();
	StartPerformance(pData);
	sPerson temp;

	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (strcmp(itp->myperson.first.c_str(), itp2->myperson.first.c_str()) == 0)
				{
					if (strcmp(itp->myperson.last.c_str(), itp2->myperson.last.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;
					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp->myperson.first.c_str(), itp2->myperson.first.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;
					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.first
				<< "       " << itp->myperson.last
				<< "      Age: " << itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}

	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (strcmp(itp->myperson.last.c_str(), itp2->myperson.last.c_str()) == 0)
				{
					if (strcmp(itp->myperson.first.c_str(), itp2->myperson.first.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;
					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp->myperson.last.c_str(), itp2->myperson.last.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;


					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "     Age:  "<<itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{

		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (strcmp(itp->myperson.first.c_str(), itp2->myperson.first.c_str()) == 0)
				{
					if (strcmp(itp2->myperson.last.c_str(), itp->myperson.last.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;
					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp2->myperson.first.c_str(), itp->myperson.first.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;
					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.first
				<< "       " << itp->myperson.last
				<< "      Age: "<<itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}

	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (strcmp(itp->myperson.last.c_str(), itp2->myperson.last.c_str()) == 0)
				{
					if (strcmp(itp2->myperson.first.c_str(), itp->myperson.first.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(itp2->myperson.last.c_str(), itp->myperson.last.c_str()) > 0)
					{
						temp = itp->myperson;
						itp->myperson = itp2->myperson;
						itp2->myperson = temp;

					}
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "   Age: "<<itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}

	}

	else if (sortType == ASC_BY_ID)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (itp->myperson.uniqueID > itp2->myperson.uniqueID)
				{
					temp = itp->myperson;
					itp->myperson = itp2->myperson;
					itp2->myperson = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "   Age: "<<itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == DESC_BY_ID)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (itp2->myperson.uniqueID > itp->myperson.uniqueID)
				{
					temp = itp->myperson;
					itp->myperson = itp2->myperson;
					itp2->myperson = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "   Age: "<< itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}
	}

	else if (sortType == ASC_BY_HEALTH)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (itp->myperson.health > itp2->myperson.health)
				{
					temp = itp->myperson;
					itp->myperson = itp2->myperson;
					itp2->myperson = temp;
				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "   Age: " << itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}
	}

	else if(sortType == DESC_BY_HEALTH)
	{
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next)
		{
			for (itp2 = itp->next; itp2 != listPeople.end(); itp2 = itp2->next)
			{
				if (itp2->myperson.health > itp->myperson.health)
				{
					temp = itp->myperson;
					itp->myperson = itp2->myperson;
					itp2->myperson = temp;

				}

			}
		}

		int i = 0;
		for (itp = listPeople.begin(); itp != listPeople.end(); itp = itp->next) {
			vecPeople.push_back(itp->myperson);
			std::cout
				<< i + 1
				<< "     ( " << itp->myperson.uniqueID << " )    "
				<< itp->myperson.last
				<< "       " << itp->myperson.first
				<< "   Age: " << itp->myperson.age
				<< "       Health:" << itp->myperson.health
				<< "        Location ( " << itp->myperson.location.x << ", " << itp->myperson.location.y << ", " << itp->myperson.location.z << ")" << std::endl;
			i++;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYList::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                                  Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                                  Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                                  Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                                  Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

eContainerType DIYList::getContainerType(void)
{
	StartPerformance(pData);

	EndPerformanceData(pData);
	return CUSTOM_DIY_LIST;
}