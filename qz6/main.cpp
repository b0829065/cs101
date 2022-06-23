#include <iostream>
#include<string>
using namespace std;

class Clock{
    public:
        int hour;
        int minute;
        int second;
        string meridian;
        Clock(int h, int m, int s, string Mil){
            hour = h;
            minute = m;
            second = s;
            meridian = Mil;
        }
        void display(){
            cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
        }
};

class StandardClock : public Clock{
    public:
        StandardClock(int h, int m, int s, string Mil) : Clock(h,m,s,Mil){
            hour = h;
			minute = m;
			second = s;
			meridian = Mil;
        }
        display(){
            if(meridian == "AM"){
                cout << "早上 " << hour << ":" << minute << ":" << second << endl;
            } else if (meridian == "PM") {
                cout << "下午 " << hour << ":" << minute << ":" << second << endl;
            }
        }
};

class MilitaryClock : public Clock{
    public:
        MilitaryClock(int h, int m, int s, string Mil) : Clock(h,m,s,Mil){
            hour = h;
			minute = m;
			second = s;
			meridian = Mil;
        }
        display(){
			if (meridian == "AM") {
				cout << hour << ":" << minute << ":" << second << endl;
			} else if (meridian == "PM") {
				cout << hour+12 << ":" << minute << ":" << second << endl;
			}
        }
};

int main()
{
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();
    return 0;
}
