#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct DATA
{
	float time;
	short int month[12];
}

void read_binary_file(std::vector<STRUCT_NAME> &vec, const std::string &file_path)
{
	std::ifstream ifs(file_path, std::ifstream::binary);
	assert(ifs.is_open());
	STRUCT_NAME st;

	while (!ifs.eof())
	{
		ifs.read(reinterpret_cast<char*>(&st), sizeof(STRUCT_NAME));
		vec.push_back(st);
	}

	ifs.close();
}

int main()
{
	return 0;
}