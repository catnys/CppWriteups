# StringStream

`stringstream` is a type of stream which allows the user to work with string. Moreoveri It implements input/output operations on memory (string) based streams. `stringstream` can be helpful in different type of parsing. The following operators/functions are;
* `clear()` To clear the stream.
* `str()` Gets the contents of underlying string device object 
* `<<`(leftshift operator) Add a string to the stringstream object. In other words,Extracts formatted data 
* `>>` (rightshift operator) Read something from the stringstream object or Inserts formatted data. 
* `str(string)` Sets the contents of underlying string device object.

**sample code**

```cpp
#include <iostream>
#include <sstream>
#include<string>
using namespace std;
 
int WordCounter(string s)
{
  //Initialize the counter
  int counter = 0;
   
    // Store independent words
    string w;
   
    // Breake words
    stringstream x(s);
 
    // counting words
    while (x >> w)
        counter++;
    return counter;
}
 

int main()
{
    string sample = "Sample code from cat";
    cout << " Word Count: " << WordCounter(sample);
    return 0;
}
```

**output:**
```
 Word Count : 4
```



---


**Another example**

```cpp
stringstream ss("15,44,46");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;
```
**output:**
```
a = 15, b = 44, c = 46
```

