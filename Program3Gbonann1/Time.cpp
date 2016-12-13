#include "Time.h"

using namespace std;

Time::Time(){
	
}

Time::Time(string time){
	if(time[2] == ':'){
		hours = atoi(time.substr(0,2).c_str());
		minutes = atoi(time.substr(3,2).c_str());
		if(time[5] == 'p') {hours += 12;}
	}
	else {
		hours = atoi(time.substr(0,1).c_str());
		minutes = atoi(time.substr(2,2).c_str());
		if(time[4] == 'p') {hours += 12;}
	}
}

ostream& operator<<(ostream& out, const Time& printer){
	
	if(printer.hours > 12){
		cout << (printer.hours-12) << ":";
		if(printer.minutes < 10){
			cout << "0" << printer.minutes;
		}
		else {cout << printer.minutes;}
		cout << "pm";
	}
	else {cout << printer.hours << ":";
		if(printer.minutes < 10){
			cout << "0" << printer.minutes;
		}
		else {cout << printer.minutes;}
		cout << "am";
	}
	return out;	
}

bool Time::operator<(Time& secondTime){

}


