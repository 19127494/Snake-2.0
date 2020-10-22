#include "Header.h"
Examinee contructor()
{
    Examinee ex;
    ex.id = "000000000";
    ex.math = ex.literature = ex.physic = ex.chemistry = ex.biology = ex.history = ex.geography = ex.civic_education = ex.natural_science = ex.social_science = ex.foreign_language = 0;
    return ex;
}
void displayID(Examinee ex)
{
    cout << ex.id << "--" << ex.math << "--" << ex.literature << "--" << ex.physic << "--" << ex.chemistry << "--" << ex.biology << "--" << ex.history << "--" << ex.geography  << "--" << ex.civic_education << "--" << ex.foreign_language;
}
void displayV(vector<Examinee>ex)
{
	for(long i=0;i<ex.size();i++)
	{
        displayID(ex.at(i)); cout << endl;
	}
}
Examinee find(vector<Examinee>ex, string ID)
{
    Examinee f;
    bool flag = 0;
	for(long i=0;i<ex.size();i++)
	{
        if (ID == ex.at(i).id)
        {
	        f = ex.at(i);
            flag = 1;
        }
	}
    if (flag == 1)
        return f;
    else return contructor();
}
float sumScore(Examinee ex)
{
	return  ex.math + ex.literature + ex.physic + ex.chemistry + ex.biology + ex.history + ex.geography + ex.civic_education + ex.foreign_language ;
}
void saveExaminee(ofstream&f,Examinee ex)
{
    f << ex.id << "    " << sumScore(ex) << endl;
}
void saveExamineeVector(ofstream& f, vector<Examinee> ex)
{
    f << "ID           " << "Score" << endl;
	for(long i=0;i<ex.size();i++)
	{
        saveExaminee(f, ex.at(i));
	}
}

void writeTotal(vector<Examinee>ex, string out_file_name)
{
    ofstream f;
    string name; name = out_file_name + ".txt";
    f.open(name);
    if (!f.is_open()) {
        cout << "Can not create file" << endl;
    }
    else {
        saveExamineeVector(f, ex);
        f.close();
    }
}
int main()
{
	ifstream f;
    vector<Examinee> ex;
	f.open("data.txt");
    if (!f.is_open()) {
        cout << "Can not open file" << endl;
    }
    else {
        loadVectorExaminee(f, ex);
        //displayV(ex);
        //displayID(find(ex, "BD1200100"));
        writeTotal(ex, "out");
        f.close();
    }
    return 0;
}
