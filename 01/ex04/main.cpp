#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string	filename;
	std::string	s1;
	std::string s2;
	char		buffer;
	bool		judgement;
	std::string	tmpbuffer;
	int			i;

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	ifs.open(filename);
	ifs.open(filename + ".replace");
	if (ifs.fail() || ofs.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return (1);
	}
	while(!ifs.eof())
	{
		buffer = ifs.get();
		if (ifs.eof())
			break;
		if (buffer != s1[0])
			ofs << buffer;
		else
		{
			if (s1.length() == 1)
			{
				if (!ifs.eof())
					ofs << s2;
				else
				{
					judgement = true;
					i = 1;
					tmpbuffer = buffer;
					while (!ifs.eof())
					{
						buffer = ifs.get();
						if (!ifs.eof())
							tmpbuffer += buffer;
						if (buffer != s1[i] || ifs.eof())
						{
							judgement = false;
							break ;
						}
						if (i == s1.length() - 1)
							break ;
						i++;
					}
				if (judgement)
					ofs << s2;
				else
					ofs << tmpbuffer;
				}
			}
		}
	}
	ifs.close();
	ofs.close();
}
