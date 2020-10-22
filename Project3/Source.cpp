#include "Header.h"

long long howManyLine(ifstream& f1)
{
	string s;
	int numlines = 0;
	while (getline(f1, s)) numlines++;
	return numlines;
}
Examinee loadExaminee(ifstream& f)
{
	Examinee ex;
	char c = NULL;
	string str;
	while(c!=',')
	{
		c = f.peek();
		if (c != ',')
			ex.id += c;
		f.seekg(1, f.cur);
	}
	
	f.seekg(1, f.cur);
	
	c = NULL;
	string temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.math = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.literature = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.physic = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.chemistry = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.biology = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.history = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.geography = stof(temp);

	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.civic_education = stof(temp);

	f.seekg(2, f.cur);
	
	c = NULL; temp = "0";
	while (c != ',')
	{
		c = f.peek();
		if (c != ',')
		{
			temp += c;
		}
		f.seekg(1, f.cur);
	}
	ex.foreign_language = stof(temp);
	return ex;
}
void loadVectorExaminee(ifstream& f, vector<Examinee>& ex)
{
	f.seekg(0, f.beg);
	string s;
	getline(f, s);
	while (!f.eof())
	{
		ex.push_back(loadExaminee(f));
		getline(f, s);
	}
}