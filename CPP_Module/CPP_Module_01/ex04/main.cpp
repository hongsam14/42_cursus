/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 03:18:57 by suhong            #+#    #+#             */
/*   Updated: 2022/01/03 17:45:27 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#define STATUS 2

#define SS 0
#define GL 1
#define IT 2

#if STATUS == IT
# define FIX_FILE(x, y, z, k) fix_file_by_iterator(x, y, z, k)
static void	fix_file_by_iterator(std::ifstream &fin, std::ofstream &fout, std::string s1, std::string s2)
{
	std::string line;
	size_t	_pos;
	size_t	past_pos(0);
	std::istreambuf_iterator<char>	begin(fin), end;

	std::cout<<"by iterator. "<<std::endl;
	line = std::string(begin, end);
	while ((_pos = line.find(s1, past_pos)) != std::string::npos)
	{
		line.replace(_pos, s1.length(), s2);
		past_pos = _pos + s2.length();
	}
	fout << line;
}

#elif STATUS == SS
# define FIX_FILE(x, y, z, k) fix_file_by_stringstream(x, y, z, k)
static void	fix_file_by_stringstream(std::ifstream &fin, std::ofstream &fout, std::string s1, std::string s2)
{
	std::string line;
	size_t	_pos;
	size_t	past_pos(0);
	std::stringstream	ss;

	std::cout<<"by string stream. "<<std::endl;
	ss << fin.rdbuf();
	line = ss.str();
	while ((_pos = line.find(s1, past_pos)) != std::string::npos)
	{
		line.replace(_pos, s1.length(), s2);
		past_pos = _pos + s2.length();
	}
	fout << line;
}

#else
# define FIX_FILE(x, y, z, k) fix_file_by_getline(x, y, z, k)
static void	fix_file_by_getline(std::ifstream &fin, std::ofstream &fout, std::string s1, std::string s2)
{
	std::string		line;
	std::string		contents;
	size_t	_pos;
	size_t	past_pos;
	
	std::cout<<"by getline func. "<<std::endl;
	while (fin.eof() == false)
	{
		std::getline(fin, line);
		
		past_pos = 0;
		while ((_pos = line.find(s1, past_pos)) != std::string::npos)
		{
			line.replace(_pos, s1.length(), s2);
			past_pos = _pos + s2.length();
		}
		if (fin.eof() == false)
			line += '\n';
		contents += line;
	}
	fout << contents;
}
#endif

int main(int argc, char *argv[])
{
	std::string	file_name;
	std::string	s1;
	std::string	s2;
	
	std::ifstream	fin;
	std::ofstream	fout;
	
	if (argc < 4 || argc > 4)
	{
		std::cerr<<"invalid argument count."<<std::endl;
		return (1);
	}
	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	fin.open(file_name.c_str(), std::ios::in);
	if (!fin.is_open())
	{
		std::cerr<<"file open failed. "<<std::endl;
		return (1);
	}
	
	fout.open((file_name + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!fout.is_open())
	{
		std::cerr<<"file open failed. "<<std::endl;
		fin.close();
		return (1);
	}
	
	FIX_FILE(fin, fout, s1, s2);
	
	fin.close();
	fout.close();
	return (0);
}
