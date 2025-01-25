# bouncing-square
bouncing square dvd-style, all within 635 bytes. This project was made for Hack Club's [Say Cheese](https://saycheese.hackclub.com/), inspired by MattKC's [Snake in a QR Code](https://www.youtube.com/watch?v=ExwqNreocpg)

### Usage

Download `dvd.exe` and run it.

##### Manual usage

Download and extract the repository, and run `new.bat`
If it doesn't work, try deleting the line that says `/TINYIMPORT`. If it still doesn't work, try deleting `/TINYHEADER` and `/UNALIGNCODE`

##### Reading the code

Due to the nature of tiny executables, the code is pretty hard to read. If you find `dvd.cpp` difficult to read, try `backup3.cpp`. If that's still too difficult, try `backup2.cpp`, and then `backup1.cpp`. Decreasing backup number means more readability, but higher file size.
