#include <vector>
#include <string>
#include <fstream>

bool loadDataIntoVector( std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale, 
						 std::string maleNamesFileName, std::vector<std::string> &vecFirstMale, 
						 std::string lastNamesFileName, std::vector<std::string> &vecLast, 
						 std::string &error )
{
	std::fstream femaleFile(femaleNamesFileName.c_str());
	std::fstream maleFile(maleNamesFileName.c_str());
	std::fstream lastFile(lastNamesFileName.c_str());



	std::string tempName;	float garbage;

	if (!femaleFile.is_open())
	{
		error = "Can't open female name file called " + femaleNamesFileName;
		return false;
	}

	while (femaleFile >> tempName)
	{
		vecFirstFemale.push_back(tempName);
		femaleFile >> garbage >> garbage >> garbage;
	}

	if (!maleFile.is_open())
	{
		error = "Can't open female name file called " + maleNamesFileName;
		return false;
	}

	while (maleFile >> tempName)
	{
		vecFirstMale.push_back(tempName);
		maleFile >> garbage >> garbage >> garbage;
	}


	if (!lastFile.is_open())
	{
		error = "Can't open female name file called " + maleNamesFileName;
		return false;
	}

	while (lastFile >> tempName)
	{
		vecLast.push_back(tempName);
		lastFile >> garbage >> garbage >> garbage;
	}
	// and so on... 

	return true;
}

unsigned int scanToToken( char* pArray,  char tokenToFind, 
						  unsigned int maxIndex, unsigned int index = 0 )
{
	while ( index < maxIndex )
	{
		if ( pArray[index] == tokenToFind )
		{
			return index;
		}
		index++;
	};

	return maxIndex;
}

// Uses c interface, rather than C++ one (so WAY faster)
bool loadDataIntoVector2( std::string femaleNamesFileName, std::vector<std::string> &vecFirstFemale,
						  std::string maleNamesFileName, std::vector<std::string> &vecFirstMale,
						  std::string lastNamesFileName, std::vector<std::string> &vecLast,
						  std::string &error )
{

	{	// START OF: load female file
		std::fstream femaleFile(femaleNamesFileName.c_str());
		if (!femaleFile.is_open())
		{
			error = "Can't open female name file called " + femaleNamesFileName;
			return false;
		}
		femaleFile.seekg(0, std::ios::end);
		// reutrns "std::ios::pos_type" type (which seems to be int in VC++)
		unsigned int fileSize = static_cast<unsigned int>( femaleFile.tellg() );
		// Return to start
		femaleFile.seekg(0, std::ios::beg);

		//std::vector<char> data( static_cast<unsigned int>(fileSize), 0);
		//this->m_vecRawData.resize( static_cast<unsigned int>(fileSize), 0);
		char* pCharData = new char[fileSize];

		femaleFile.read(pCharData, fileSize);
		femaleFile.close();

		// Now pRawData contains the entire file
		// You can scan to the 1st 'whitespace' to get the end of the first name
		// You can scan to the 1st newline (\n) to get the end of the first line
		// ...etc.
		unsigned int startIndex = 0;
		unsigned int endIndex = scanToToken( pCharData, ' ', fileSize, startIndex);

		char tempBuff[100] = {0};
		memcpy( tempBuff, &(pCharData[startIndex]), endIndex - startIndex);
		tempBuff[endIndex - startIndex] = '\0';
		std::string tempString(tempBuff);
		
		// Scan for '\n'

		delete pCharData;
	}//ENDOF: load female file

	return true;
}
