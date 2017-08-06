#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int findnum(const string & s)
{
	int i = 0;
	int n = 0;
	while(s[i] != '.')
	{
		n = 10*n+(s[i] - '0');
		i++;
	}
	return n;
}

class Compare
{
	public:
	bool operator()(const string &s1, const string & s2)
	{
		int n1 = findnum(s1);
		int n2 = findnum(s2);
		return n1 < n2;
	}
};

int main()
{
	vector<string> V;
	DIR *dpdf;
	struct dirent *epdf;
	dpdf = opendir(".");
	if (dpdf != NULL)
	{
	   while (epdf = readdir(dpdf))
	  {
	      V.push_back(string(epdf->d_name));
	  }
	}
	Compare C;
	sort(V.begin(), V.end(), C);
	for(int i = 0 ; i < V.size(); i++)
		cout<<V[i]<<endl;
	return 0;
}


