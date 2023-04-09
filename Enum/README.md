# Enumeration in cpp

In C++, an enum (short for "enumeration") is a user-defined type that represents a set of named values. Enums are typically used to represent a fixed set of possible values, such as the days of the week or the months of the year.

![](https://i.imgur.com/pfLmRwc.png)


```cpp

enum DayOfWeek {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

DayOfWeek today = Wednesday;
if (today == Wednesday) {
  cout << "Today is Wednesday!" << endl;
}
```

In the example above, we define an enum called DayOfWeek that represents the seven days of the week. The names of the enum values (e.g. Monday, Tuesday, etc.) are all implicitly assigned integer values starting from 0 (i.e. Monday has a value of 0, Tuesday has a value of 1, and so on).

We then declare a variable called today of type DayOfWeek and assign it the value Wednesday. We can then use this variable in an if statement to check whether it is equal to Wednesday.

Enums are useful because they provide a way to define a set of named values that can be used throughout your program, and they help make your code more readable and self-documenting.


```cpp
class MyClass {
public:
  enum Color {
    Red,
    Green,
    Blue
  };

  void setColor(Color newColor) {
    color_ = newColor;
  }

  Color getColor() const {
    return color_;
  }

private:
  Color color_;
};

int main() {
  MyClass obj;
  obj.setColor(MyClass::Red);
  cout << "Color is: " << obj.getColor() << endl; // Output: Color is: 0
  return 0;
}

```
