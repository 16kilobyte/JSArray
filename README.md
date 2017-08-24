# JSArray
## JS-like array implementation in C++
Use JSArray to create JavaScript-like arrays in C++

### Usage
```cpp
include "JSArray.h"

int main(int argc, char const *argv[])
{
	JSArray<std::string>* jsArray = new JSArray<std::string>();
	jsArray->push("Kator"); //
	jsArray->push("James");
	jsArray->push("Jos");
	jsArray->push("Cpp");
  int jsArraySize = jsArray->size;
}
```
