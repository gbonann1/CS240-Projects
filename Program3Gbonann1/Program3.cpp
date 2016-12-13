#include "Time.h"
#include "Date.h"
#include "Graph.h"

using namespace std;

int main(){
	ifstream in;
	in.open("ddfs.txt");
	Graph g1(in);
	string ourTime = "10:34am";
	string notOurTime = "8:15pm";
	Time t1(ourTime);
	Time t2(notOurTime);
	//cout << t1 << endl << t2 << endl;
	string ourDate = "12/02/2014";
	string ourNextDate = "01/14/2009";
	Date d1(ourDate);
	Date d2(ourNextDate);
	//cout << d1 << endl << d2 << endl;
	in.close();
	  cout << "Please pick an option below, or type 'Q' to quit." << endl;
	  cout << " J" << endl;
	  cout << " F" << endl;
	  cout << " C" << endl;
	  cout << " S" << endl;
	  cout << " P" << endl;
	  string userInput;
	  cin >> userInput;
	while (userInput != "Q") {
	  if (userInput == "P") {
	  g1.print();
	  }
	  else if (userInput == "J") {
	  //g1.j();
	  cout << "J option is not available" << endl;
	  }
	  else if (userInput == "F") {
	  g1.f();
	  //cout << "F option is not available" << endl;
	  }
	  else if (userInput == "C") {
	  //g1.c();
	  cout << "C option is not available" << endl;
	  }
	  else if (userInput == "S") {
	  //g1.s();
	  cout << "S option is not available" << endl;
	  }
	  else {
	  cout << "Not a valid option" << endl;
	  }
	  cout << "Please pick an option below, or type 'Q' to quit." << endl;
	  cout << " J" << endl;
	  cout << " F" << endl;
	  cout << " C" << endl;
	  cout << " S" << endl;
	  cout << " P" << endl;
	  cin >> userInput;
        }
	
	
	
	return 0;
}
