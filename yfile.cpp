#include "yfile.h"

yFile::yFile(std::string fileName)
	:m_fileName(fileName)
{
	GetDataByFile();
}

void yFile::GetDataByFile()
{
	std::ifstream ifread(m_fileName);
	std::string szBuf;

	if (!ifread.is_open())
	{
		return;
	}


	while (getline(ifread,szBuf))
	{
		std::size_t pos = szBuf.find('=');
		if (std::string::npos == pos)
		{
			break;
		}
		else
		{
			m_data.insert(std::pair<std::string, std::string>(
				szBuf.substr(0, pos), szBuf.substr(pos + 1)));
		}
		szBuf.erase();
	}

	ifread.close();
}

std::string yFile::operator[](std::string paramName)
{
	std::map<std::string, std::string>::iterator s_it;
	
	s_it = m_data.find(paramName);

	if (s_it == m_data.end())
	{
		return "";
	}

	return s_it->second;
}

std::string yFile::at(std::string paramName)
{
	std::map<std::string, std::string>::iterator s_it;

	s_it = m_data.find(paramName);

	if (s_it == m_data.end())
	{
		return "";
	}

	return s_it->second;
}
