#include "DIYMap.h"
#include "Support.h"


bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);


bool DIYMAP::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
{
	StartPerformance(pData);

	if (!loadDataIntoVector(firstNameFemaleFileName, mvecFemaleNames,
		firstNameMaleFileName, mvecMaleNames,
		lastNameFileName, mvecLastNames, error))
	{
		std::cout << "Error: " << error << std::endl;
		return -1;
	}

	for (int i = 0; i < mvecFemaleNames.size(); i++)
	{
		mapFemaleNames.push_back(i, mvecFemaleNames[i]);
	}

	for (int i = 0; i < mvecMaleNames.size(); i++)
	{
		mapMaleNames.push_back(i,mvecMaleNames[i]);
	}

	for (int i = 0; i < mvecLastNames.size(); i++)
	{
		mapLastNames.push_back(i,mvecLastNames[i]);
	}

	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::GenerateRandomPeople(int numberOfPeople)
{
	StartPerformance(pData);
	int random;
	unsigned long long Id = 1;

	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		sPerson p1;
		sPoint s1;
		random = rand() % 1000 + 1;

		//DiyMap<int,std::string>::diymap* it1;
		//DiyMap<int,std::string>::diymap* it2;

		int male = rand() % mapMaleNames.maxindex();
		int female = rand() % mapFemaleNames.maxindex();
		int malelast = rand() % mapLastNames.maxindex();

		if (random % 2 == 0)
		{
			
			p1.first = mapFemaleNames.find(female)->myperson;
			p1.last = mapLastNames.find(malelast)->myperson;
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
			p1.first = mapMaleNames.find(male)->myperson;
			p1.last = mapLastNames.find(malelast)->myperson;
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 90 + 1;
			p1.health = random % 100 + 1;
			
		}
		mapPeople.push_back(i,p1);
		Id++;

	}
	
	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		std::cout
			<< i + 1
			<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
			<< mapPeople.find(i)->myperson.first
			<< "       " << mapPeople.find(i)->myperson.last
			<< "        Age:" << mapPeople.find(i)->myperson.age
			<< "       Health:" << mapPeople.find(i)->myperson.health
			<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;

	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);

	int	i = 0, j = 0;
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		i = 0; j = 0;

		for (i = 0; i < mapPeople.maxindex(); i++)
		{
			if (mapPeople.find(i)->myperson.first == personToMatch.first)
			{
				vecPeople.push_back(mapPeople.find(i)->myperson);
				std::cout
					<< i + 1
					<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
					<< mapPeople.find(i)->myperson.first
					<< "       " << mapPeople.find(i)->myperson.last
					<< "        Age:" << mapPeople.find(i)->myperson.age
					<< "       Health:" << mapPeople.find(i)->myperson.health
					<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople)
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length() == 0 && personToMatch.last.length() > 0)
	{
		i = 0; j = 0;
		for (i = 0; i < mapPeople.maxindex(); i++)
		{
			if (mapPeople.find(i)->myperson.last == personToMatch.last)
			{
				vecPeople.push_back(mapPeople.find(i)->myperson);

					std::cout
					<< i + 1
					<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
					<< mapPeople.find(i)->myperson.first
					<< "       " << mapPeople.find(i)->myperson.last
					<< "        Age:" << mapPeople.find(i)->myperson.age
					<< "       Health:" << mapPeople.find(i)->myperson.health
					<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople)
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length()>0 && personToMatch.last.length()>0)
	{
		i = 0; j = 0;
		for (i = 0; i < mapPeople.maxindex(); i++)
		{
			if (mapPeople.find(i)->myperson.last == personToMatch.last && mapPeople.find(i)->myperson.first == personToMatch.first)
			{
				vecPeople.push_back(mapPeople.find(i)->myperson);

				std::cout
					<< i + 1
					<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
					<< mapPeople.find(i)->myperson.first
					<< "       " << mapPeople.find(i)->myperson.last
					<< "        Age:" << mapPeople.find(i)->myperson.age
					<< "       Health:" << mapPeople.find(i)->myperson.health
					<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople)
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
		std::cout << "\n Your data is not in this random generator list. Please try other data...... \n";
	}
	return 0;
}

bool DIYMAP::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);
	int	i = 0,
		ji = 0;
	
	DiyMap <int, sPerson> mapPeopleToMatch;

	for (int i = 0; i < vecPeopleToMatch.size(); i++)
	{
		mapPeopleToMatch.push_back(i,vecPeopleToMatch[i]);
	}

	for (int k = 0; k <= mapPeopleToMatch.maxindex(); k++)
	{

		if (mapPeopleToMatch.find(k)->myperson.first.length() > 0 && mapPeopleToMatch.find(k)->myperson.last.length() == 0)
		{

			i = 0;
			do
			{

				if (mapPeople.find(i)->myperson.first == mapPeopleToMatch.find(k)->myperson.first && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mapPeople.find(i)->myperson);

					std::cout
						<< i + 1
						<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
						<< mapPeople.find(i)->myperson.first
						<< "       " << mapPeople.find(i)->myperson.last
						<< "        Age:" << mapPeople.find(i)->myperson.age
						<< "       Health:" << mapPeople.find(i)->myperson.health
						<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
					ji++;

				}
				i++;
			} while (i <= mapPeople.maxindex());
		}
		else if (mapPeopleToMatch.find(k)->myperson.first.length() == 0 && mapPeopleToMatch.find(k)->myperson.last.length() > 0)
		{
			i = 0;
			do
			{

				if (mapPeople.find(i)->myperson.last == mapPeopleToMatch.find(k)->myperson.last&& ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mapPeople.find(i)->myperson);


					std::cout
						<< i + 1
						<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
						<< mapPeople.find(i)->myperson.first
						<< "       " << mapPeople.find(i)->myperson.last
						<< "        Age:" << mapPeople.find(i)->myperson.age
						<< "       Health:" << mapPeople.find(i)->myperson.health
						<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;

					ji++;

				}
				i++;

			} while (i <= mapPeople.maxindex());
		}
		else if (mapPeopleToMatch.find(k)->myperson.first.length()>0 && mapPeopleToMatch.find(k)->myperson.last.length() > 0)
		{
			i = 0;
			do
			{

				if (mapPeople.find(i)->myperson.first == mapPeopleToMatch.find(k)->myperson.first && mapPeopleToMatch.find(i)->myperson.last == mapPeopleToMatch.find(k)->myperson.last && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mapPeople.find(i)->myperson);


					std::cout
						<< i + 1
						<< "     ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
						<< mapPeople.find(i)->myperson.first
						<< "       " << mapPeople.find(i)->myperson.last
						<< "        Age:" << mapPeople.find(i)->myperson.age
						<< "       Health:" << mapPeople.find(i)->myperson.health
						<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (i <= mapPeople.maxindex());
		}
		
		if (ji == 0)
		{
			std::cout << "\n Your data is not in this random generator list. Please try other data...... \n";
			return 1;

		}
	}

	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	StartPerformance(pData);
	for (int i = 0; i <= mapPeople.maxindex(); i++)
	{
		if (uniqueID == mapPeople.find(i)->myperson.uniqueID)
		{
			person.first = mapPeople.find(i)->myperson.first;
			person.last = mapPeople.find(i)->myperson.last;
			person.uniqueID = mapPeople.find(i)->myperson.uniqueID;
			person.health = mapPeople.find(i)->myperson.health;
			person.location = mapPeople.find(i)->myperson.location;

			std::cout
				<< i + 1 << "  "
				<< "  ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "       " << mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "       Health:" << mapPeople.find(i)->myperson.health
				<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
			break;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count = 0;
	float distancer;
	int j = 0;


	for (int i = 0; i <= mapPeople.maxindex(); i++)
	{
		distancer = powf(location.x -  mapPeople.find(i)->myperson.location.x, 2) + powf(location.y -  mapPeople.find(i)->myperson.location.y, 2) + powf(location.z - mapPeople.find(i)->myperson.location.z, 2);
		if (radius >= distancer)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "  "
				<< "  ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "       " << mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "       Health:" << mapPeople.find(i)->myperson.health
				<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

	}

	if (count == 0)
	{
		return 1;
	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	StartPerformance(pData);
	int count;
	count = 0;
	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "\nYour data is out of range" << std::endl;
	}
	else
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{


			if (mapPeople.find(i)->myperson.health >= minHealth && mapPeople.find(i)->myperson.health <= maxHealth)
			{
				vecPeople.push_back(mapPeople.find(i)->myperson);

				std::cout
					<< i + 1 << "  "
					<< "  ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
					<< mapPeople.find(i)->myperson.first
					<< "       " << mapPeople.find(i)->myperson.last
					<< "        Age:" << mapPeople.find(i)->myperson.age
					<< "       Health:" << mapPeople.find(i)->myperson.health
					<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
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

bool DIYMAP::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count;
	count = 0;
	float distancer;

	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "\nYour data is out of range" << std::endl;
	}
	else
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{

			distancer = powf(location.x - mapPeople.find(i)->myperson.location.x, 2) + powf(location.y - mapPeople.find(i)->myperson.location.y, 2) + powf(location.z - mapPeople.find(i)->myperson.location.z, 2);
			if (mapPeople.find(i)->myperson.health >= minHealth && mapPeople.find(i)->myperson.health <= maxHealth && radius >= distancer)
			{
				vecPeople.push_back(mapPeople.find(i)->myperson);

				std::cout
					<< i + 1 << "  "
					<< "  ( " << mapPeople.find(i)->myperson.uniqueID << " )    "
					<< mapPeople.find(i)->myperson.first
					<< "       " << mapPeople.find(i)->myperson.last
					<< "        Age:" << mapPeople.find(i)->myperson.age
					<< "       Health:" << mapPeople.find(i)->myperson.health
					<< "        Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
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

bool DIYMAP::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	vecPeople.clear();
	StartPerformance(pData);
	sPerson temp;

	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (strcmp(mapPeople.find(i)->myperson.first.c_str(), mapPeople.find(j)->myperson.first.c_str()) == 0)
				{
					if (strcmp(mapPeople.find(i)->myperson.last.c_str(), mapPeople.find(j)->myperson.last.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople.find(i)->myperson.first.c_str(), mapPeople.find(j)->myperson.first.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "       " << mapPeople.find(i)->myperson.last
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}

	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (strcmp(mapPeople.find(i)->myperson.last.c_str(), mapPeople.find(j)->myperson.last.c_str()) == 0)
				{
					if (strcmp(mapPeople.find(i)->myperson.first.c_str(), mapPeople.find(j)->myperson.first.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople.find(i)->myperson.last.c_str(), mapPeople.find(j)->myperson.last.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;
					}
				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.last
				<< "        "
				<< mapPeople.find(i)->myperson.first
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (strcmp(mapPeople.find(i)->myperson.first.c_str(), mapPeople.find(j)->myperson.first.c_str()) == 0)
				{
					if (strcmp(mapPeople.find(j)->myperson.last.c_str(), mapPeople.find(i)->myperson.last.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople.find(j)->myperson.first.c_str(), mapPeople.find(i)->myperson.first.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;
					}
				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "       " << mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (strcmp(mapPeople.find(i)->myperson.last.c_str(), mapPeople.find(j)->myperson.last.c_str()) == 0)
				{
					if (strcmp(mapPeople.find(j)->myperson.first.c_str(), mapPeople.find(i)->myperson.first.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople.find(j)->myperson.last.c_str(), mapPeople.find(i)->myperson.last.c_str()) > 0)
					{
						temp = mapPeople.find(i)->myperson;
						mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
						mapPeople.find(j)->myperson = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.last
				<< "        "
				<< mapPeople.find(i)->myperson.first
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}


	}

	else if (sortType == ASC_BY_ID)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (mapPeople.find(i)->myperson.uniqueID > mapPeople.find(j)->myperson.uniqueID)
				{
					temp = mapPeople.find(i)->myperson;
					mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
					mapPeople.find(j)->myperson = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "        "
				<< mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_BY_ID)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (mapPeople.find(j)->myperson.uniqueID > mapPeople.find(i)->myperson.uniqueID)
				{
					temp = mapPeople.find(i)->myperson;
					mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
					mapPeople.find(j)->myperson = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "        "
				<< mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}

	else if (sortType == ASC_BY_HEALTH)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (mapPeople.find(i)->myperson.health > mapPeople.find(j)->myperson.health)
				{
					temp = mapPeople.find(i)->myperson;
					mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
					mapPeople.find(j)->myperson = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "  "
				<< "    Health:" << mapPeople.find(i)->myperson.health << "  "
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "    "
				<< mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_BY_HEALTH)
	{
		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			for (int j = i + 1; j < mapPeople.maxindex(); j++)
			{
				if (mapPeople.find(j)->myperson.health > mapPeople.find(i)->myperson.health)
				{
					temp = mapPeople.find(i)->myperson;
					mapPeople.find(i)->myperson = mapPeople.find(j)->myperson;
					mapPeople.find(j)->myperson = temp;
				}

			}
		}

		for (int i = 0; i < mapPeople.maxindex(); i++)
		{
			vecPeople.push_back(mapPeople.find(i)->myperson);

			std::cout
				<< i + 1 << "   "
				<< "    Health:" << mapPeople.find(i)->myperson.health
				<< "( " << mapPeople.find(i)->myperson.uniqueID << " )    "
				<< mapPeople.find(i)->myperson.first
				<< "      "
				<< mapPeople.find(i)->myperson.last
				<< "        Age:" << mapPeople.find(i)->myperson.age
				<< "    Location ( " << mapPeople.find(i)->myperson.location.x << ", " << mapPeople.find(i)->myperson.location.y << ", " << mapPeople.find(i)->myperson.location.z << ")" << std::endl;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

bool DIYMAP::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                                  Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                                  Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                                  Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                                  Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

eContainerType DIYMAP::getContainerType(void)
{
	StartPerformance(pData);

	EndPerformanceData(pData);
	return CUSTOM_DIY_MAP;
}