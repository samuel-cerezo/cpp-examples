// time.cpp, Maggie Johnson
// Description: A simple time class.

#include <iostream>
using namespace std;

class Time {
 private:
  int hours_;
  int minutes_;
  int seconds_;
 public:
  void set(int h, int m, int s);
  void increment();
  void decrement();
  void display();
};


void Time::set(int h, int m, int s) {
  hours_ = h; 
  minutes_ = m; 
  seconds_ = s; 
  return;
}

// este es el metodo que agregué yo
void Time::decrement(){
    seconds_--;
    if(seconds_==-1){
      seconds_=59;
      minutes_--;
    } 
    if(minutes_==-1){
      minutes_=59;
      hours_--;
    }
    if(hours_==-1){
      hours_=23;
    }
    return;
}

void Time::increment() {
  seconds_++;   // aumenta segundos
  minutes_ = minutes_ + seconds_/60;  
  hours_ = hours_ + minutes_/60;
  seconds_ = seconds_ % 60;     //resto de la division entre estos dos enteros
  minutes_ = minutes_ % 60;
  hours_ = hours_ % 24;
  return;
}
/*
expresión boleana ? valor si cierto : valor si falso
*/

void Time::display() {
  cout << (hours_ % 12 ? hours_ % 12:12) << ':'
       << (minutes_ < 10 ? "0" :"") << minutes_ << ':'
       << (seconds_ < 10 ? "0" :"") << seconds_
       << (hours_ < 12 ? " AM" : " PM") << endl;
}

int main() {
  Time timer;
  timer.set(23,59,58);
  for (int i = 0; i < 5; i++) {
    timer.increment();
    timer.display();
    cout << endl;
  }

  timer.set(12,00,02);
  for (int i = 0; i < 5; i++) {
    timer.decrement();
    timer.display();
    cout << endl;
  }
  
}