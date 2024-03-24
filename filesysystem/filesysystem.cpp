#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

void test1() {
	std::string path;
	std::cout << "Podaj sciezke: ";
	std::getline(std::cin, path);

	if (std::filesystem::exists(path)) {
		std::cout << "Plik istnieje." << std::endl;

		std::filesystem::file_status s = std::filesystem::status(path);
		switch (s.type()) {
		case std::filesystem::file_type::directory:
			std::cout << "Directory." << std::endl;
			break;
		case std::filesystem::file_type::regular:
			std::cout << "Regular." << std::endl;
			break;
		default:
			std::cout << "Other." << std::endl;
			break;
		}


	}
	else {
		std::cout << "Plik nie istnieje." << std::endl;
	}
	return;
}

void test2() {

	std::string path;
	std::cout << "Podaj sciezke: ";
	std::getline(std::cin, path);

	std::cout << "directory_iterator:\n";
	
	for (auto const& dir_entry : std::filesystem::directory_iterator{ path }) {
		std::cout << dir_entry.path();
		std::filesystem::file_status s = std::filesystem::status(dir_entry.path());
		switch (s.type()) {
		case std::filesystem::file_type::directory:
			std::cout << "(Directory)" << std::endl;
			break;
		case std::filesystem::file_type::regular: {
			std::cout << "(Regular, ";
			std::uintmax_t size = std::filesystem::file_size(dir_entry.path());
			std::cout << "Rozmiar pliku: " << size << ")" << std::endl;
			break;
		}
		default:
			std::cout << "(Other)" << std::endl;
			break;
		}
		
	}

}

std::uintmax_t test3(const std::filesystem::path& path) {
	std::uintmax_t size = 0;
	for (auto const& dir_entry : std::filesystem::directory_iterator{ path }) {
		std::filesystem::file_status s = std::filesystem::status(dir_entry.path());
		switch (s.type()) {
		case std::filesystem::file_type::directory: {
			std::uintmax_t s = test3(dir_entry.path());
			size += s;
			break;
		}
		case std::filesystem::file_type::regular: {

			std::uintmax_t s = std::filesystem::file_size(dir_entry.path());
			size += s;
			break;
		}
		}
	}

	return size;
}

int main()
{
	//test2();
	
}


