#include <iostream>
using namespace std;

class Sun
{
public:
  static Sun &getInstance()
  {
    static Sun instance; // Instantiated on first use. 也是懒汉式。
    return instance;
  }

  void setX(int x)
  {
    this->x = x;
  }

  void setY(int y)
  {
    this->y = y;
  }

  int getX()
  {
    return this->x;
  }

  int getY()
  {
    return this->y;
  }

  void show()
  {
    cout << "x = " << this->x << ", y = " << this->y << endl;
  }

private:
  int x = 0;
  int y = 0;
  Sun() {}
  // Don't forget to declare these two. You want to make sure they are inaccessible(especially from outside,
  // otherwise, you may accidentally get copies of your singleton appearing.
  Sun(const Sun &);            // Don't Implement.
  void operator=(const Sun &); // Don't Implement.
};

int main()
{
  Sun &sun = Sun::getInstance();
  sun.show();
  sun.setX(4);
  Sun &sun1 = Sun::getInstance();
  sun.show();
  // Sun sun2();
  // sun2.setX(5);
  return 0;
}