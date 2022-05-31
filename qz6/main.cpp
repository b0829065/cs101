#include<iostream>
#include<string>

using namespace std;

class Clock {
	public:
		int hr, min, sec;
		string mer;
		Clock(int hr_, int min_, int sec_, string mer_) {
			hr = hr_;
			min = min_;
			sec = sec_;
			mer = mer_;
		}
		display() {
			cout << hr << ":" << min << ":" << sec << " " << mer << endl;
		}
}; 

class StandardClock : Clock {
	public:
		StandardClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (mer == "AM") {
				cout << "上午 " << hr << ":" << min << ":" << sec << endl;
			} else if (mer == "PM") {
				cout << "下午 " << hr << ":" << min << ":" << sec << endl;
			}
		}
};

class MilitaryClock : Clock {
	public:
		MilitaryClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (mer == "AM") {
				cout << hr << ":" << min << ":" << sec << endl;
			} else if (mer == "PM") {
				cout << hr+12 << ":" << min << ":" << sec << endl;
			}
		}
};

int main() {
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();
	return 0;
}
