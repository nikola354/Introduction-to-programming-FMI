# Компилация на C++ при различните операционни системи

## Windows

* Има голям набор от IDE-та (Integrated Development Environment) и Text Editor-и, но в рамките на курса се препоръчват ```Visual Studio 2022 Community```, ```CLion``` и в краен случай ```Code::Blocks```
* При програмиране на VSCode се следват същите стъпки за компилация, както при ```macOS```, но трябва допълнителна конфигурация на GCC през тези линкове:
  * [Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
  * [GCC and MinGW-w64 for Windows](https://winlibs.com/)
* Накрая във ```VSCode``` се изтегля допълнителен ```Extension: C/C++```
 
## macOS

* За IDE можете да използвате ```VSCode``` или ```CLion```
* За компилация на код ви трябва GCC, който може да си го свалите по следния начин ```xcode-select --install``` и след това да проверите, че всичко е наред, като изпълните командата ```g++ --version```
* За да компилирате даден .cpp файл, трябва да се намирате в папката, където се намира файлът и да run-нете ```g++ <fileName>.cpp -o <outputName>.out```
* За изпълнение на executable файла, ако няма компилационни грешки, се използва ```./<outputName>.out```

## Linux

* За IDE се използват ```VSCode``` и ```CLion```, като допълнително трябва да се свали g++ в зависимост от дистрото на Linux:
  * Debian / Ubuntu: ```sudo apt install g++```
  * Red Hat / Fedora: ```sudo dnf install gcc-c++```
* Компилацията на .cpp е със същите команди като при macOS

### !!! При допълнителни въпроси относно конфигурация питайте [Slavi Rezashki](https://github.com/Slavi15)
