#include "StandardMap.h"
#include "Support.h"




bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);


//1
bool StandardMap::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
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
		mapFemaleNames[i] = vecFemaleNames[i];
	}

	for (int i = 0; i < vecMaleNames.size(); i++)
	{
		mapMaleNames[i] = vecMaleNames[i];
	}

	for (int i = 0; i < vecLastNames.size(); i++)
	{
		mapLastNames[i] = vecLastNames[i];
	}

	EndPerformanceData(pData);
}


//2
bool StandardMap::GenerateRandomPeople(int numberOfPeople)
{

	mapPeople.clear();
	StartPerformance(pData);

	srand(time_t(NULL));
	unsigned long long Id = 1;
	int random;
	for (int i = 0; i < numberOfPeople; i++)
	{
		
		sPerson p1;
		sPoint s1;
		random = rand() % 1000 + 1;
		int MaleFirstIndex = rand() % mapMaleNames.size();
		int FemaleFirstIndex = rand() % mapFemaleNames.size();
		int MaleLastIndex = rand() % mapLastNames.size();
		int FemaleLastIndex = rand() % mapLastNames.size();

				if (random % 2 == 0)
				{
					p1.first = mapMaleNames[MaleFirstIndex];
					p1.last = mapLastNames[MaleLastIndex];

					p1.uniqueID = Id;

					
					s1.x = random % 50 + 1;
					s1.y = random % 150 + 2;
					s1.z = random % 250 + 3;
					p1.age = rand() % 80 + 1;
					p1.location = s1;
					p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
					mapPeople[i] = p1;
				}
				
				else
				{
					p1.first = mapFemaleNames[FemaleFirstIndex];
					p1.last = mapLastNames[FemaleLastIndex + 1219];
					p1.uniqueID = Id;
					s1.x = random % 50 + 1;
					s1.y = random % 150 + 2;
					s1.z = random % 250 + 3;
					p1.age = rand() % 90 + 1;
					p1.location = s1;
					p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
					
					mapPeople[i] = p1;
				}
				Id++;
	}

	
	for (int  i = 0; i <= numberOfPeople - 1; i++)
	{
		std::cout
			<< i + 1     
			<< "     ( " << mapPeople[i].uniqueID << " )    "
			<< mapPeople[i].first
			<< "       " << mapPeople[i].last
			<< "        Age:"  << mapPeople[i].age
			<< "       Health:" << mapPeople[i].health
			<< "        Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		
	}

	EndPerformanceData(pData);
	return 0;

}

//3
bool StandardMap::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)
{
	StartPerformance(pData);
	vecPeople.clear();
	int	i = 0, j = 0;
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		i = 0; j = 0;
		
		for(i=0; i<mapPeople.size(); i++)
		{
			if (mapPeople[i].first == personToMatch.first)
			{
				vecPeople.push_back(mapPeople[i]);
				std::cout
					<< i + 1
					<< "     ( " << mapPeople[i].uniqueID << " )    "
					<< mapPeople[i].first
					<< "       " << mapPeople[i].last
					<< "        Age:" << mapPeople[i].age
					<< "       Health:" << mapPeople[i].health
					<< "        Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople )
			{
				//return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length() == 0 && personToMatch.last.length() > 0)
	{
		i = 0; j = 0;
		for (i = 0; i<mapPeople.size(); i++)
		{
			if (mapPeople[i].last == personToMatch.last)
			{
				vecPeople.push_back(mapPeople[i]);

				std::cout
					<< i + 1
					<< "     ( " << mapPeople[i].uniqueID << " )    "
					<< mapPeople[i].first
					<< "       " << mapPeople[i].last
					<< "        Age:" << mapPeople[i].age
					<< "       Health:" << mapPeople[i].health
					<< "        Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
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
		for (i = 0; i < mapPeople.size(); i++)
		{
			if (mapPeople[i].last == personToMatch.last && mapPeople[i].first == personToMatch.first)
			{
				vecPeople.push_back(mapPeople[i]);

				std::cout
					<< i + 1
					<< "     ( " << mapPeople[i].uniqueID << " )    "
					<< mapPeople[i].first
					<< "       " << mapPeople[i].last
					<< "        Age:" << mapPeople[i].age
					<< "       Health:" << mapPeople[i].health
					<< "        Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
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
	}
	return 0;
}

//4
bool StandardMap::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();
	StartPerformance(pData);
	int	i = 0,
		ji = 0;


	std::map <int, sPerson> mapPeopleToMatch;
	for (int i = 0; i < vecPeopleToMatch.size(); i++)
	{
		mapPeopleToMatch[i] = vecPeopleToMatch[i];
	}

	for (int k = 0; k < mapPeopleToMatch.size(); k++)
	{

		if (mapPeopleToMatch[k].first.length() > 0 && mapPeopleToMatch[k].last.length() == 0 )
		{

			i = 0; 
			do
			{

				if (mapPeople[i].first == mapPeopleToMatch[k].first && ji < maxNumberOfPeople)
				{

					vecPeople.push_back(mapPeople[i]);

					std::cout
						<< i + 1 << "   "
						<< "( " << mapPeople[i].uniqueID << " )    "
						<< mapPeople[i].first
						<< "       " << mapPeople[i].last
						<< "        Age:" << mapPeople[i].age
						<< "    Health:" << mapPeople[i].health
						<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (i < mapPeople.size() );
		}
		else if (mapPeopleToMatch[k].first.length() == 0 && mapPeopleToMatch[k].last.length() > 0 )
		{
			i = 0;
			do
			{

				if (mapPeople[i].last == mapPeopleToMatch[k].last&& ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mapPeople[i]);

					std::cout
						<< i + 1 << "   "
						<< "( " << mapPeople[i].uniqueID << " )    "
						<< mapPeople[i].first
						<< "       " << mapPeople[i].last
						<< "        Age:" << mapPeople[i].age
						<< "    Health:" << mapPeople[i].health
						<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
					
					ji++;
					
				}
				i++;

			} while (i < mapPeople.size());
		}
		else if (mapPeopleToMatch[k].first.length()>0 && mapPeopleToMatch[k].last.length()>0 )
		{
			i = 0;
			do
			{

				if (mapPeople[i].first == mapPeopleToMatch[k].first && mapPeople[i].last == mapPeopleToMatch[k].last && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mapPeople[i]);

					std::cout
						<< i + 1 << "   "
						<< "( " << mapPeople[i].uniqueID << " )    "
						<< mapPeople[i].first
						<< "       " << mapPeople[i].last
						<< "        Age:" << mapPeople[i].age
						<< "    Health:" << mapPeople[i].health
						<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (i < mapPeople.size() );
		}
	
	}

	EndPerformanceData(pData);
	if (ji == 0)
	{
		return 1;
	}
	return 0;
}

//5
bool StandardMap::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	StartPerformance(pData);
	for (int i = 0; i <= mapPeople.size(); i++)
	{
		if (uniqueID == mapPeople[i].uniqueID)
		{
			person.first = mapPeople[i].first;
			person.last = mapPeople[i].last;
			person.uniqueID = mapPeople[i].uniqueID;
			person.health = mapPeople[i].health;
			person.location = mapPeople[i].location;

			std::cout
				<< i + 1 << "  "
				<< "  ( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "       " << mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "       Health:" << mapPeople[i].health
				<< "        Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
			break;
		}
		
	}

	EndPerformanceData(pData);
	return 0;

}

//6
bool StandardMap::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count = 0;
	float distancer;
	int j = 0;

	
	for (int i = 0; i <= mapPeople.size(); i++ )
	{
		distancer = powf(location.x - mapPeople[i].location.x, 2) + powf(location.y - mapPeople[i].location.y, 2) + powf(location.z - mapPeople[i].location.z, 2);
		if (radius >= distancer)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<<i + 1 << "  "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "       " << mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
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
bool StandardMap::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count;
	count = 0;
	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "\nYour data is out of range" << std::endl;
	}
	else
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{


		if (mapPeople[i].health >= minHealth && mapPeople[i].health <= maxHealth)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< count + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "       " << mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
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
bool StandardMap::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn)
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
		for (int i = 0; i < mapPeople.size(); i++)
		{

			distancer = powf(location.x - mapPeople[i].location.x, 2) + powf(location.y - mapPeople[i].location.y, 2) + powf(location.z - mapPeople[i].location.z, 2);
			if (mapPeople[i].health >= minHealth && mapPeople[i].health <= maxHealth && radius >= distancer)
			{
				vecPeople.push_back(mapPeople[i]);

				std::cout
					<< count + 1 << "   "
					<< "( " << mapPeople[i].uniqueID << " )    "
					<< mapPeople[i].first
					<< "       " << mapPeople[i].last
					<< "        Age:" << mapPeople[i].age
					<< "    Health:" << mapPeople[i].health
					<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
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
bool StandardMap::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	vecPeople.clear();
	StartPerformance(pData);
	sPerson temp;

	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (strcmp(mapPeople[i].first.c_str(), mapPeople[j].first.c_str()) == 0)
				{
					if (strcmp(mapPeople[i].last.c_str(), mapPeople[j].last.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople[i].first.c_str(), mapPeople[j].first.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "       " << mapPeople[i].last
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}

	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (strcmp(mapPeople[i].last.c_str(), mapPeople[j].last.c_str()) == 0)
				{
					if (strcmp(mapPeople[i].first.c_str(), mapPeople[j].first.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople[i].last.c_str(), mapPeople[j].last.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].last
				<< "        "
				<< mapPeople[i].first
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{

		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (strcmp(mapPeople[i].first.c_str(), mapPeople[j].first.c_str()) == 0)
				{
					if (strcmp(mapPeople[j].last.c_str(), mapPeople[i].last.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople[j].first.c_str(), mapPeople[i].first.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "       " << mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (strcmp(mapPeople[i].last.c_str(), mapPeople[j].last.c_str()) == 0)
				{
					if (strcmp(mapPeople[j].first.c_str(), mapPeople[i].first.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mapPeople[j].last.c_str(), mapPeople[i].last.c_str()) > 0)
					{
						temp = mapPeople[i];
						mapPeople[i] = mapPeople[j];
						mapPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].last
				<< "        "
				<< mapPeople[i].first
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}


	}

	else if (sortType == ASC_BY_ID)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (mapPeople[i].uniqueID > mapPeople[j].uniqueID)
				{
					temp = mapPeople[i];
					mapPeople[i] = mapPeople[j];
					mapPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "        "
				<< mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_BY_ID)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (mapPeople[j].uniqueID > mapPeople[i].uniqueID)
				{
					temp = mapPeople[i];
					mapPeople[i] = mapPeople[j];
					mapPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "        "
				<< mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Health:" << mapPeople[i].health
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == ASC_BY_HEALTH)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (mapPeople[i].health > mapPeople[j].health)
				{
					temp = mapPeople[i];
					mapPeople[i] = mapPeople[j];
					mapPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "  "
				<< "    Health:" << mapPeople[i].health << "  "
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "    "
				<< mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_BY_HEALTH)
	{
		for (int i = 0; i < mapPeople.size(); i++)
		{
			for (int j = i + 1; j < mapPeople.size(); j++)
			{
				if (mapPeople[j].health > mapPeople[i].health)
				{
					temp = mapPeople[i];
					mapPeople[i] = mapPeople[j];
					mapPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < mapPeople.size(); i++)
		{
			vecPeople.push_back(mapPeople[i]);

			std::cout
				<< i + 1 << "   "
				<< "    Health:" << mapPeople[i].health
				<< "( " << mapPeople[i].uniqueID << " )    "
				<< mapPeople[i].first
				<< "      "
				<< mapPeople[i].last
				<< "        Age:" << mapPeople[i].age
				<< "    Location ( " << mapPeople[i].location.x << ", " << mapPeople[i].location.y << ", " << mapPeople[i].location.z << ")" << std::endl;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

//10
bool StandardMap::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                                  Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                                  Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                                  Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                                  Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

//11
eContainerType StandardMap::getContainerType(void)
{
	StartPerformance(pData);

	EndPerformanceData(pData);
	return STD_MAP;
}