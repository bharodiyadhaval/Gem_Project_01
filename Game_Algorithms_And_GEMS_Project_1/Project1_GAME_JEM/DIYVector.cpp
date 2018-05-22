#include "DIYVector.h"
#include "Support.h"


bool loadDataIntoVector(std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
	std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
	std::string lastNamesFileName, std::vector<std::string> &vecLast,
	std::string &error);

//1
bool DIYVector::LoadDataFilesIntoContainer(std::string firstNameFemaleFileName, std::string firstNameMaleFileName, std::string lastNameFileName)
{
	StartPerformance(pData);
	if (!loadDataIntoVector(firstNameFemaleFileName, SvecFemaleNames,
		firstNameMaleFileName, SvecMaleNames,
		lastNameFileName, SvecLastNames, error))
	{
		std::cout << "Error: " << error << std::endl;
		return -1;
	}

	for (int i = 0; i < SvecFemaleNames.size(); i++)
	{
		vecFemaleNames.push_back(SvecFemaleNames[i]);
	}

	for (int i = 0; i < SvecMaleNames.size(); i++)
	{
		vecMaleNames.push_back(SvecMaleNames[i]);
	}

	for (int i = 0; i < SvecLastNames.size(); i++)
	{
		vecLastNames.push_back(SvecLastNames[i]);
	}
	EndPerformanceData(pData);
}

//2
bool DIYVector::GenerateRandomPeople(int numberOfPeople)
{
	
	StartPerformance(pData);
	int random;
	srand(time(NULL));
	unsigned long long Id = 1;

	for (int i = 0; i <= numberOfPeople - 1; i++)
	{
		random = rand() % 1000 + 1;
		sPerson p1;
		sPoint s1;

		int MaleFirstIndex = rand() % vecMaleNames.size();
		int FemaleFirstIndex = rand() % vecFemaleNames.size();
		int MaleLastIndex = rand() % vecLastNames.size();
		int FemaleLastIndex = rand() % vecLastNames.size();
		
		if (random % 2 == 0)
		{
			p1.first = vecFemaleNames.arr[FemaleFirstIndex].value;
			p1.last = vecLastNames.arr[FemaleLastIndex + 1219].value;
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
			p1.first = vecMaleNames.arr[MaleFirstIndex].value;
			p1.last = vecLastNames.arr[MaleLastIndex].value;
			p1.uniqueID = Id;
			s1.x = random % 50 + 1;
			s1.y = random % 150 + 2;
			s1.z = random % 250 + 3;
			p1.location = s1;
			p1.age = rand() % 80 + 1;
			p1.health = (rand() % 100) + (rand() % 100001 / 100000.0f);
		
		}
		mvecPeople.push_back(p1);
		Id++;
	}
	

	for (int i = 0; i <= numberOfPeople - 1; i++) {
		std::cout 
			<< i + 1 << "   "
			<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
			<< mvecPeople.arr[i].value.first
			<< "       " << mvecPeople.arr[i].value.last
			<< "      Age:" << mvecPeople.arr[i].value.age
			<< "    Health:" << mvecPeople.arr[i].value.health
			<< "    Location ( "<<mvecPeople.arr[i].value.location.x<<", "<< mvecPeople.arr[i].value.location.y <<", "<< mvecPeople.arr[i].value.location.z <<")"<< std::endl;
	}

	EndPerformanceData(pData);
	return 0;
}

//3
bool DIYVector::FindPeopleByName(std::vector<sPerson> &vecPeople, sPerson personToMatch, int maxNumberOfPeople)

{
	vecPeople.clear();
	StartPerformance(pData);

	int	i = 0,
		j = 0;

	
	if (personToMatch.first.length() > 0 && personToMatch.last.length() == 0)
	{
		i = 0; j = 0;
		for (i = 0; mvecPeople.arr[i].emp!=1; i++)
		{

			if (mvecPeople.arr[i].value.first == personToMatch.first)
			{
				vecPeople.push_back(mvecPeople.arr[i].value);
				std::cout
					<< i + 1 << "   "
					<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
					<< mvecPeople.arr[i].value.first
					<< "       " << mvecPeople.arr[i].value.last
					<< "      Age:" << mvecPeople.arr[i].value.age
					<< "    Health:" << mvecPeople.arr[i].value.health
					<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
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
		for (i = 0; mvecPeople.arr[i].emp != 1; i++)
		{

			if (mvecPeople.arr[i].value.last == personToMatch.last)
			{
				vecPeople.push_back(mvecPeople.arr[i].value);

				std::cout
					<< i + 1 << "   "
					<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
					<< mvecPeople.arr[i].value.first
					<< "       " << mvecPeople.arr[i].value.last
					<< "      Age:" << mvecPeople.arr[i].value.age
					<< "    Health:" << mvecPeople.arr[i].value.health
					<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
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
		for (i = 0; mvecPeople.arr[i].emp != 1; i++)
		{

			if (mvecPeople.arr[i].value.first == personToMatch.first && mvecPeople.arr[i].value.last == personToMatch.last)
			{
				vecPeople.push_back(mvecPeople.arr[i].value);

				std::cout
					<< i + 1 << "   "
					<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
					<< mvecPeople.arr[i].value.first
					<< "       " << mvecPeople.arr[i].value.last
					<< "      Age:" << mvecPeople.arr[i].value.age
					<< "    Health:" << mvecPeople.arr[i].value.health
					<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
				j++;
			};

			if (j >= maxNumberOfPeople)
			{
				
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
bool DIYVector::FindPeopleByName(std::vector<sPerson> &vecPeople, std::vector<sPerson> &vecPeopleToMatch, int maxNumberOfPeople)
{
	vecPeople.clear();

	StartPerformance(pData);

	int	i = 0,
		ji = 0;

	for (int i = 0; i < vecPeopleToMatch.size(); i++)
	{
		mvecPeopleToFind.push_back(vecPeopleToMatch[i]);
	}

	for (int k = 0; mvecPeople.arr[k].emp != 1; k++)
	{

	
		if (mvecPeopleToFind.arr[k].value.first.length() > 0 && mvecPeopleToFind.arr[k].value.last.length() == 0)
		{

			i = 0;
			do
			{

				if (mvecPeople.arr[i].value.first == mvecPeopleToFind.arr[k].value.first && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mvecPeople.arr[i].value);

					std::cout
						<< i + 1 << "   "
						<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
						<< mvecPeople.arr[i].value.first
						<< "       " << mvecPeople.arr[i].value.last
						<< "      Age:" << mvecPeople.arr[i].value.age
						<< "    Health:" << mvecPeople.arr[i].value.health
						<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (mvecPeople.arr[i].emp != 1);
		}
		else if (mvecPeopleToFind.arr[k].value.first.length() == 0 && mvecPeopleToFind.arr[k].value.last.length() > 0)
		{
			i = 0;
			do
			{

				if (mvecPeople.arr[i].value.last == mvecPeopleToFind.arr[k].value.last&& ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mvecPeople.arr[i].value);

					std::cout
						<< i + 1 << "   "
						<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
						<< mvecPeople.arr[i].value.first
						<< "       " << mvecPeople.arr[i].value.last
						<< "      Age:" << mvecPeople.arr[i].value.age
						<< "    Health:" << mvecPeople.arr[i].value.health
						<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;

					ji++;

				}
				i++;

			} while (mvecPeople.arr[i].emp != 1);
		}
		else if (mvecPeopleToFind.arr[k].value.first.length()>0 && mvecPeopleToFind.arr[k].value.last.length()>0)
		{
			i = 0;
			do
			{

				if (mvecPeople.arr[i].value.first == mvecPeopleToFind.arr[k].value.first && mvecPeople.arr[i].value.last == mvecPeopleToFind.arr[k].value.last && ji < maxNumberOfPeople)
				{
					vecPeople.push_back(mvecPeople.arr[i].value);

					std::cout
						<< i + 1 << "   "
						<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
						<< mvecPeople.arr[i].value.first
						<< "       " << mvecPeople.arr[i].value.last
						<< "      Age:" << mvecPeople.arr[i].value.age
						<< "    Health:" << mvecPeople.arr[i].value.health
						<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
					ji++;
				}
				i++;
			} while (mvecPeople.arr[i].emp != 1);
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
bool DIYVector::FindPersonByID(sPerson &person, unsigned long long uniqueID)
{
	StartPerformance(pData);
	for (int k = 0; k < mvecPeople.arr[k].emp != 1; k++)
	{
		if (uniqueID == mvecPeople.arr[k].value.uniqueID)
		{
			person.first = mvecPeople.arr[k].value.first;
			person.last = mvecPeople.arr[k].value.last;
			person.uniqueID = mvecPeople.arr[k].value.uniqueID;
			person.health = mvecPeople.arr[k].value.health;
			person.location = mvecPeople.arr[k].value.location;

				std::cout
				<< k + 1 << "   "
				<< "( " << mvecPeople.arr[k].value.uniqueID << " )    "
				<< mvecPeople.arr[k].value.first
				<< "       " << mvecPeople.arr[k].value.last
				<< "      Age:" << mvecPeople.arr[k].value.age
				<< "    Health:" << mvecPeople.arr[k].value.health
				<< "    Location ( " << mvecPeople.arr[k].value.location.x << ", " << mvecPeople.arr[k].value.location.y << ", " << mvecPeople.arr[k].value.location.z << ")" << std::endl;
			break;
		}
	}
	EndPerformanceData(pData);
	return 0;

}


//6
bool DIYVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, int maxPeopleToReturn)
{

	vecPeople.clear();
	StartPerformance(pData);
	int count = 0;
	float distancer;
	

	for (int j = 0; j < mvecPeople.arr[j].emp != 1; j++)
	{
		distancer = powf(location.x - mvecPeople.arr[j].value.location.x, 2) + powf(location.y - mvecPeople.arr[j].value.location.y, 2) + powf(location.z - mvecPeople.arr[j].value.location.z, 2);
		if (   radius >=  distancer )
		{
			vecPeople.push_back(mvecPeople.arr[j].value);

			std::cout
				<< j + 1 << "   "
				<< "( " << mvecPeople.arr[j].value.uniqueID << " )   "
				<< mvecPeople.arr[j].value.first
				<< "       " << mvecPeople.arr[j].value.last
				<< "       Age:" <<mvecPeople.arr[j].value.age
				<< "    Health:" << mvecPeople.arr[j].value.health
				<< "    Location ( " << mvecPeople.arr[j].value.location.x << ", " << mvecPeople.arr[j].value.location.y << ", " << mvecPeople.arr[j].value.location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

	}
	EndPerformanceData(pData);
	return 0;
}


//7
bool DIYVector::FindPeople(std::vector<sPerson> &vecPeople, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);
	int count;
	count = 0;
	if (minHealth < 1 || maxHealth > 100)
	{
		std::cout << "\nYour data is out of range" << std::endl;
	}
	else
	{
		for (int i = 0; i < mvecPeople.arr[i].emp != 1; i++)
		{


			if (mvecPeople.arr[i].value.health >= minHealth && mvecPeople.arr[i].value.health <= maxHealth)
			{

				vecPeople.push_back(mvecPeople.arr[i].value);

				std::cout
					
					<< count + 1 << "   "
					<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
					<< mvecPeople.arr[i].value.first
					<< "       " << mvecPeople.arr[i].value.last
					<<"       Age:  "<< mvecPeople.arr[i].value.age
					<< "    Health:" << mvecPeople.arr[i].value.health
					<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
				count++;
				if (count >= maxPeopleToReturn)
				{
					break;
				}
			}

		}
	}
	EndPerformanceData(pData);
	return 0;
}


//8
bool DIYVector::FindPeople(std::vector<sPerson> &vecPeople, sPoint location, float radius, float minHealth, float maxHealth, int maxPeopleToReturn)
{
	vecPeople.clear();
	StartPerformance(pData);

	int count;
	float distancer;

	count = 0;
	for (int i = 0; i < mvecPeople.arr[i].emp != 1; i++)
	{
		distancer = powf(location.x - mvecPeople.arr[i].value.location.x, 2) + powf(location.y - mvecPeople.arr[i].value.location.y, 2) + powf(location.z - mvecPeople.arr[i].value.location.z, 2);
		if (minHealth <= 0 || maxHealth > 100 && radius >= distancer)
		{
			std::cout << "Your data is out of range" << std::endl;
		}

		else if (mvecPeople.arr[i].value.health >= minHealth && mvecPeople.arr[i].value.health <= maxHealth)
		{

			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				
				<< count + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "       " << mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
			count++;
			if (count >= maxPeopleToReturn)
			{
				break;
			}
		}

	}
	EndPerformanceData(pData);
	return 0;
}


//9
bool DIYVector::SortPeople(std::vector<sPerson> &vecPeople, eSortType sortType)
{
	vecPeople.clear();
	StartPerformance(pData);
	sPerson temp;
	
	if (sortType == ASC_FIRST_THEN_LAST)
	{
		for (int i = 0; mvecPeople.arr[i].emp != 1; i++)
		{
			
			for (int j = i + 1; mvecPeople.arr[j].emp != 1 ; j++)
			{
				if (strcmp(mvecPeople.arr[i].value.first.c_str(), mvecPeople.arr[j].value.first.c_str()) == 0)
				{
					if (strcmp(mvecPeople.arr[i].value.last.c_str(), mvecPeople.arr[j].value.last.c_str()) > 0)
					{
					//	std::cout << " hellooo.." << mvecPeople.arr[i].value << std::endl;
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mvecPeople.arr[i].value.first.c_str(), mvecPeople.arr[j].value.first.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
				}
				
			}
		}

		for (int i = 0; mvecPeople.arr[i].emp != 1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "       " << mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}
			
	}

	else if (sortType == ASC_LAST_THEN_FIRST)
	{
		for (int i = 0; mvecPeople.arr[i].emp !=1 ; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp != 1; j++)
			{
				if (strcmp(mvecPeople.arr[i].value.last.c_str(), mvecPeople.arr[j].value.last.c_str()) == 0)
				{
					if (strcmp(mvecPeople.arr[i].value.first.c_str(), mvecPeople.arr[j].value.first.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mvecPeople.arr[i].value.last.c_str(), mvecPeople.arr[j].value.last.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
				}

			}
		}

		for (int i = 0; i < mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.last
				<< "        "
				<< mvecPeople.arr[i].value.first
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}

	}

	else if (sortType == DESC_FIRST_THEN_LAST)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (strcmp(mvecPeople.arr[i].value.first.c_str(), mvecPeople.arr[j].value.first.c_str()) == 0)
				{
					if (strcmp(mvecPeople.arr[j].value.last.c_str(), mvecPeople.arr[i].value.last.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mvecPeople.arr[j].value.first.c_str(), mvecPeople.arr[i].value.first.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "       " << mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}

	}

	else if (sortType == DESC_LAST_THEN_FIRST)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (strcmp(mvecPeople.arr[i].value.last.c_str(), mvecPeople.arr[j].value.last.c_str()) == 0)
				{
					if (strcmp(mvecPeople.arr[j].value.first.c_str(), mvecPeople.arr[i].value.first.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
					else
					{
						continue;
					}
				}
				else
				{
					if (strcmp(mvecPeople.arr[j].value.last.c_str(), mvecPeople.arr[i].value.last.c_str()) > 0)
					{
						temp = mvecPeople.arr[i].value;
						mvecPeople.arr[i].value = mvecPeople.arr[j].value;
						mvecPeople.arr[j].value = temp;

					}
				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.last
				<< "        "
				<< mvecPeople.arr[i].value.first
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}

	}


	else if (sortType == ASC_BY_ID)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (mvecPeople.arr[i].value.uniqueID > mvecPeople.arr[j].value.uniqueID)
				{
					temp = mvecPeople.arr[i].value;
					mvecPeople.arr[i].value = mvecPeople.arr[j].value;
					mvecPeople.arr[j].value = temp;

				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "        "
				<< mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}
	}


	else if (sortType == DESC_BY_ID)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (mvecPeople.arr[j].value.uniqueID > mvecPeople.arr[i].value.uniqueID)
				{
					temp = mvecPeople.arr[i].value;
					mvecPeople.arr[i].value = mvecPeople.arr[j].value;
					mvecPeople.arr[j].value = temp;

				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "        "
				<< mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}
	}


	else if (sortType == ASC_BY_HEALTH)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (mvecPeople.arr[i].value.health > mvecPeople.arr[j].value.health)
				{
					temp = mvecPeople.arr[i].value;
					mvecPeople.arr[i].value = mvecPeople.arr[j].value;
					mvecPeople.arr[j].value = temp;

				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "        "
				<< mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}
	}


	else if (sortType == DESC_BY_HEALTH)
	{
		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			for (int j = i + 1; mvecPeople.arr[j].emp!=1; j++)
			{
				if (mvecPeople.arr[j].value.health > mvecPeople.arr[i].value.health)
				{
					temp = mvecPeople.arr[i].value;
					mvecPeople.arr[i].value = mvecPeople.arr[j].value;
					mvecPeople.arr[j].value = temp;

				}

			}
		}

		for (int i = 0; mvecPeople.arr[i].emp!=1; i++)
		{
			vecPeople.push_back(mvecPeople.arr[i].value);

			std::cout
				<< i + 1 << "   "
				<< "    Health:" << mvecPeople.arr[i].value.health
				<< "( " << mvecPeople.arr[i].value.uniqueID << " )    "
				<< mvecPeople.arr[i].value.first
				<< "        "
				<< mvecPeople.arr[i].value.last
				<< "        Age:" << mvecPeople.arr[i].value.age
				<< "    Location ( " << mvecPeople.arr[i].value.location.x << ", " << mvecPeople.arr[i].value.location.y << ", " << mvecPeople.arr[i].value.location.z << ")" << std::endl;
		}
	}

	EndPerformanceData(pData);
	return 0;
}


//10
bool DIYVector::GetPerformanceFromLastCall(sPerfData &callStats)
{
	callStats = pData;

	std::cout << "\n                                  Elapsed time = " << pData.elapsedCallTime_ms << "ms" << std::endl;
	std::cout << "                                  Minimum Memory Usage = " << (int)pData.memoryUsageBytes_min / 1024 << " KB" << std::endl;
	std::cout << "                                  Maximum Memory Usage = " << (int)pData.memoryUsageBytes_max / 1024 << " KB" << std::endl;
	std::cout << "                                  Average Memory Usage = " << (int)pData.memoryUsageBytes_avg / 1024 << " KB" << std::endl;

	return 0;
}

//11
eContainerType DIYVector::getContainerType(void)
{
	StartPerformance(pData);

	EndPerformanceData(pData);
	return CUSTOM_DIY_VECTOR;
}
