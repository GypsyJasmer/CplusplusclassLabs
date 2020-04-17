#include <iostream>

using namespace std;

class FtIn {
private:
  int
    ft,
    in;
public:
  FtIn() {ft = 0; in = 0;}
  FtIn(int f, int i) {ft = f; in = i;}
  FtIn(int i) {ft=i/12; in=i%12;}
  void printIt() {cout << ft << " " << in << endl;}
};

void cvtConEx1(FtIn ob) {
  ob.printIt();
}

FtIn cvtConEx2(int i) {
  return i;
}

int main() {
  cout << "Convert constructor at declaration:\n";
  FtIn wid = 23;
  wid.printIt();

  cout << "\nConvert constructor assignment:\n";
  wid = 24;
  wid.printIt();

  cout << "\nConvert constructor in a function arg:\n";
  cvtConEx1(25);

  cout << "\nConvert constructor with a return value:\n";
  // Note a FtIn is returned, despite what the book says
  // so this doesn't work:
  // int rslt = cvtConEx2(26);
  //cout << rslt << endl;

  wid = cvtConEx2(26);
  wid.printIt();

  return 0;
}

