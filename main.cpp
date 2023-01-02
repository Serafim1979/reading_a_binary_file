#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct DATA
{
	float time;
	short int month[12];
}

void read_binary_file(std::vector<DATA> &vec, const std::string &file_path)
{
	std::ifstream ifs(file_path, std::ifstream::binary);
	assert(ifs.is_open());
	DATA st;

	while (!ifs.eof())
	{
		ifs.read(reinterpret_cast<char*>(&st), sizeof(DATA));
		vec.push_back(st);
	}

	ifs.close();
}

int main()
{
	std::cout << "Successfully" << std::endl;
	return 0;
}