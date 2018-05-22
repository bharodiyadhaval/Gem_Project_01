#include "StandardVector.h"
#include "Support.h"

bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

//1
bool StandardVector::LoadDataFilesIntoContainer (std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
{
	StartPerformance(pData);

	if (!loadDataIntoVector(firstNameFemaleFileName, vecFemaleNames,
		firstNameMaleFileName, vecMaleNames,
		lastNameFileName, vecLastNames, error))
	{
		std::cout << "Error: " << error << std::endl;
		return -1;
	}
	EndPerformanceData(pData);
}


//2
bool StandardVector::GenerateRandomPeople(int numberOfPeople)
{
	Container.clear();
	StartPerformance(pData);
	//srand(time(NULL));
	unsigned long long Id = 1;
	int random;
	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		sPerson p1;
		sPoint s1;

		random = rand() % 1000 + 1;
		int MaleFirstIndex = rand() % vecMaleNames.size();
		int FemaleFirstIndex = rand() % vecFemaleNames.size();
		int MaleLastIndex = rand() % vecLastNames.size();
		int FemaleLastIndex = rand() % vecLastNames.size();

		if (random % 2 == 0)
		{
			
			p1.first = vecFemaleNames[FemaleFirstIndex];
			p1.last = vecLastNames[FemaleLastIndex + 1219];
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 90 + 1;
			p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
		}
		else
		{
			p1.first = vecMaleNames[MaleFirstIndex];
			p1.last = vecLastNames[MaleLastIndex];
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 80 + 1;
			p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
		
		}
		
		Container.push_back(p1);
		Id++;
	}

	for (int i = 0; i <= numberOfPeople - 1; i++) {
		std::cout 
			<< i + 1 << "   "
			<< "( " << Container[i].uniqueID << " )    "
			<< Container[i].first
			<< "       " << Container[i].last
			<< "        Age:" << Container[i].age
			<< "    Health:" << Container[i].health
			<< "    Location ( "<< Container[i].location.x<<", "<< Container[i].location.y <<", "<< Container[i].location.z <<")"<< std::endl;
	}

	EndPerformanceData(pData);
	return 0;
}

//3
bool StandardVector::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople )
{
	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	vecPeople.clear();
	int	i = 0,
		j = 0;
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		i = 0; j = 0;
		for (i = 0; i<Container.size(); i++)
		{
			
			if (Container[i].first == personToMatch.first)
			{
				vecPeople.push_back(Container[i]);
				std::cout
					<< i + 1 << "   "
					<< "( " << Container[i].uniqueID << " )    "
					<< Container[i].first
					<< "       " << Container[i].last
					<< "        Age:" << Container[i].age
					<< "    Health:" << Container[i].health
					<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople)
			{
				EndPerformanceData(pData);
				return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length() == 0 && personToMatch.last.length() > 0)
	{
		i = 0; j = 0;
		for (i = 0; i<Container.size(); i++)
		{
			
			if (Container[i].last == personToMatch.last)
			{
				vecPeople.push_back(Container[i]);


				std::cout
					<< i + 1 << "   "
					<< "( " << Container[i].uniqueID << " )    "
					<< Container[i].first
					<< "       " << Container[i].last
					<< "        Age:" << Container[i].age
					<< "    Health:" << Container[i].health
					<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
				j++;
			};
			if (j >= maxNumberOfPeople)
			{
				EndPerformanceData(pData);
				return 0;
				break;
			}

		}
	}
	else if (personToMatch.first.length()>0 && personToMatch.last.length()>0)
	{
		i = 0; j = 0;
		for (i = 0; i<Container.size(); i++)
		{
			
			if (Container[i].first == personToMatch.first && Container[i].last == personToMatch.last)
			{
				vecPeople.push_back(Container[i]);

				std::cout
					<< i + 1 << "   "
					<< "( " << Container[i].uniqueID << " )    "
					<< Container[i].first
					<< "       " << Container[i].last
					<< "        Age:" << Container[i].age
					<< "    Health:" << Container[i].health
					<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
				j++;
			};

			if (j >= maxNumberOfPeople)
			{
				EndPerformanceData(pData);
				return 0;
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
bool StandardVector::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();

	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	//vecPeople.clear();
	int	i = 0,
		ji = 0;

	for (int k = 0; k < vecPeopleToMatch.size(); k++)
	{

		if (vecPeopleToMatch[k].first.length() > 0 && vecPeopleToMatch[k].last.length() == 0)
		{

			i = 0;
			do
			{

				if (Container[i].first == vecPeopleToMatch[k].first && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(Container[i]);
					std::cout
						<< i + 1 << "   "
						<< "( " << Container[i].uniqueID << " )    "
						<< Container[i].first
						<< "       " << Container[i].last
						<< "        Age:" << Container[i].age
						<< "    Health:" << Container[i].health
						<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (i < Container.size());
		}
		else if (vecPeopleToMatch[k].first.length() == 0 && vecPeopleToMatch[k].last.length() > 0)
		{
			i = 0;
			do
			{

				if (Container[i].last == vecPeopleToMatch[k].last&& ji < maxNumberOfPeople)
				{
					vecPeople.push_back(Container[i]);
					std::cout
						<< i + 1 << "   "
						<< "( " << Container[i].uniqueID << " )    "
						<< Container[i].first
						<< "       " << Container[i].last
						<< "        Age:" << Container[i].age
						<< "    Health:" << Container[i].health
						<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;

					ji++;

				}
				i++;

			} while (i < Container.size());
		}
		else if (vecPeopleToMatch[k].first.length()>0 && vecPeopleToMatch[k].last.length()>0)
		{
			i = 0;
			do
			{

				if (Container[i].first == vecPeopleToMatch[k].first && Container[i].last == vecPeopleToMatch[k].last && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(Container[i]);
					std::cout
						<< i + 1 << "   "
						<< "( " << Container[i].uniqueID << " )    "
						<< Container[i].first
						<< "       " << Container[i].last
						<< "        Age:" << Container[i].age
						<< "    Health:" << Container[i].health
						<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (i < Container.size());
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
bool StandardVector::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	//Container.clear();
	for (int k = 0; k < Container.size(); k++)
	{
		if (uniqueID == Container[k].uniqueID)
		{

			person.first = Container[k].first;
			person.last = Container[k].last;
			person.uniqueID = Container[k].uniqueID;
			person.health = Container[k].health;
			person.location = Container[k].location;

			
			/*std::cout
				<< k + 1 << "   "
				<< "( " << person.uniqueID << " )    "
				<<		person.first
				<< "       " << person.last
				<< "        Age:" << Container[i].age
				<< "    Health:" << person.health
				<< "    Location ( " << person.location.x << ", " << person.location.y << ", " << person.location.z << ")" << std::endl;*/
			std::cout
				<< k + 1 << "   "
				<< "( " << Container[k].uniqueID << " )    "
				<< Container[k].first
				<< "       " << Container[k].last
				<< "        Age:" << Container[k].age
				<< "    Health:" << Container[k].health
				<< "    Location ( " << Container[k].location.x << ", " << Container[k].location.y << ", " << Container[k].location.z << ")" << std::endl;
			break;
		}
	}
	EndPerformanceData(pData);
	return 0;

}

//6
bool StandardVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius,int maxPeopleToReturn)
{
	vecPeople.clear();

	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	//Container.clear();
	int count = 0;
	float distancer;
	

	for (int j = 0; j < Container.size(); j++)
	{
		distancer = powf(location.x - Container[j].location.x, 2) + powf(location.y - Container[j].location.y, 2) + powf(location.z - Container[j].location.z, 2);
		if (   radius >=  distancer )
		{
			vecPeople.push_back(Container[j]);
			std::cout
				<< j + 1 << "   "
				<< "( " << Container[j].uniqueID << " )   "
				<< Container[j].first
				<< "       " << Container[j].last
				<< "        Age:" << Container[j].age
				<< "    Health:" << Container[j].health
				<< "    Location ( " << Container[j].location.x << ", " << Container[j].location.y << ", " << Container[j].location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				EndPerformanceData(pData);
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
bool StandardVector::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();

	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	//Container.clear();
	int count;
	count = 0;
	if (minHealth <= 0 || maxHealth > 100)
	{
		std::cout << "\nYour data is out of range" << std::endl;
	}
	else
	{
		for (int i = 0; i <= Container.size(); i++)
		{


			if (Container[i].health >= minHealth && Container[i].health <= maxHealth)
			{
				vecPeople.push_back(Container[i]);
				std::cout
					<< count + 1 << "   "
					<< "( " << Container[i].uniqueID << " )    "
					<< Container[i].first
					<< "       " << Container[i].last
					<< "        Age:" << Container[i].age
					<< "    Health:" << Container[i].health
					<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
				count++;
				if (count >= maxPeopleToReturn)
				{
					EndPerformanceData(pData);
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
bool StandardVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn )
{
	vecPeople.clear();

	//start = std::chrono::high_resolution_clock::now();
	StartPerformance(pData);
	//Container.clear();
	int count;
	float distancer;

	count = 0;
	for (int i = 0; i < Container.size(); i++)
	{
		distancer = powf(location.x - Container[i].location.x, 2) + powf(location.y - Container[i].location.y, 2) + powf(location.z - Container[i].location.z, 2);
		if (minHealth <= 0 || maxHealth > 100 && radius >= distancer)
		{
			std::cout << "Your data is out of range" << std::endl;
		}

		else if (Container[i].health >= minHealth && Container[i].health <= maxHealth)
		{
			vecPeople.push_back(Container[i]);
			std::cout
				<< count + 1 << "   "
				<< "( " << Container[i].uniqueID << " )    "
				<< Container[i].first
				<< "       " << Container[i].last
				<< "        Age:" << Container[i].age
				<< "    Health:" << Container[i].health
				<< "    Location ( " << Container[i].location.x << ", " << Container[i].location.y << ", " << Container[i].location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				EndPerformanceData(pData);
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

//9
bool StandardVector::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	//start = std::chrono::high_resolution_clock::now();
	
	vecPeople.clear();
	for (int i = 0; i < Container.size(); i++)
	{
		vecPeople.push_back(Container[i]);
	}

	StartPerformance(pData);
	//vecPeople.clear();
	sPerson temp;

	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i+1; j < vecPeople.size(); j++)
			{
				if (strcmp(vecPeople[i].first.c_str(), vecPeople[j].first.c_str()) == 0)
				{
					if (strcmp(vecPeople[i].last.c_str(), vecPeople[j].last.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(vecPeople[i].first.c_str(), vecPeople[j].first.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
				}
				
			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].first
				<< "       " << vecPeople[i].last
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}
			
	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (strcmp(vecPeople[i].last.c_str(), vecPeople[j].last.c_str()) == 0)
				{
					if (strcmp(vecPeople[i].first.c_str(), vecPeople[j].first.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(vecPeople[i].last.c_str(), vecPeople[j].last.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;
					}
				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].last
				<< "        "
				<< vecPeople[i].first
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}

	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (strcmp(vecPeople[i].first.c_str(), vecPeople[j].first.c_str()) == 0)
				{
					if (strcmp(vecPeople[j].last.c_str(), vecPeople[i].last.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(vecPeople[j].first.c_str(), vecPeople[i].first.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].first
				<< "       " << vecPeople[i].last
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}

	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (strcmp(vecPeople[i].last.c_str(), vecPeople[j].last.c_str()) == 0)
				{
					if (strcmp(vecPeople[j].first.c_str(), vecPeople[i].first.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(vecPeople[j].last.c_str(), vecPeople[i].last.c_str()) > 0)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}
				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].last
				<< "        "
				<< vecPeople[i].first
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}

	}

	else if (sortType == ASC_BY_ID)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
					if (vecPeople[i].uniqueID > vecPeople[j].uniqueID)
					{
						temp = vecPeople[i];
						vecPeople[i] = vecPeople[j];
						vecPeople[j] = temp;

					}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].first
				<< "        "
				<< vecPeople[i].last
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == DESC_BY_ID)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (vecPeople[j].uniqueID > vecPeople[i].uniqueID)
				{
					temp = vecPeople[i];
					vecPeople[i] = vecPeople[j];
					vecPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< vecPeople[i].first
				<< "        "
				<< vecPeople[i].last
				<< "        Age:" << vecPeople[i].age
				<< "    Health:" << vecPeople[i].health
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}
	}

	else if (sortType == ASC_BY_HEALTH)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (vecPeople[i].health > vecPeople[j].health)
				{
					temp = vecPeople[i];
					vecPeople[i] = vecPeople[j];
					vecPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "    Health:" << vecPeople[i].health
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< "        Age:" << vecPeople[i].age
				<< vecPeople[i].first
				<< "        "
				<< vecPeople[i].last
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}
	}

	else if(sortType == DESC_BY_HEALTH)
	{
		for (int i = 0; i < vecPeople.size(); i++)
		{
			for (int j = i + 1; j < vecPeople.size(); j++)
			{
				if (vecPeople[j].health > vecPeople[i].health)
				{
					temp = vecPeople[i];
					vecPeople[i] = vecPeople[j];
					vecPeople[j] = temp;

				}

			}
		}

		for (int i = 0; i < vecPeople.size(); i++)
		{
			std::cout
				<< i + 1 << "   "
				<< "    Health:" << vecPeople[i].health
				<< "( " << vecPeople[i].uniqueID << " )    "
				<< "        Age:" << vecPeople[i].age
				<< vecPeople[i].first
				<< "        "
				<< vecPeople[i].last
				<< "    Location ( " << vecPeople[i].location.x << ", " << vecPeople[i].location.y << ", " << vecPeople[i].location.z << ")" << std::endl;
		}
	}
	EndPerformanceData(pData);
	return 0;
}

//10
bool StandardVector::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                                  Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                                  Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                                  Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                                  Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

//11
 eContainerType StandardVector::getContainerType(void)
{
	 StartPerformance(pData);

	 EndPerformanceData(pData);

	return STD_VECTOR;
}
