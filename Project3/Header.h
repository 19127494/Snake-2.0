#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Examinee
{
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};
long long howManyLine(ifstream& f1);
Examinee loadExaminee(ifstream& f);
void loadVectorExaminee(ifstream& f, vector<Examinee>&ex);