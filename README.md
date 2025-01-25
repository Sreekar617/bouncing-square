# bouncing-square
bouncing square dvd-style, all within 635 bytes. This project was made for Hack Club's [Say Cheese](https://saycheese.hackclub.com/), inspired by MattKC's [Snake in a QR Code](https://www.youtube.com/watch?v=ExwqNreocpg)

## Usage

Download `dvd.exe` and run it. Or if you're cool, scan this qr code, and run the downloaded file as an exe (rename it to something.exe)
![qr](https://github.com/user-attachments/assets/50fedf3c-e1a4-4664-b843-3e4dd72dd0ea)


### Manual usage

Download and extract the repository, and run `new.bat` in an **x86 Native Tools Command Prompt**
If it doesn't work, try deleting the line that says `/TINYIMPORT`. If it still doesn't work, try deleting `/TINYHEADER` and `/UNALIGNCODE`

### Reading the code

Due to the nature of tiny executables, the code is pretty hard to read. If you find `dvd.cpp` difficult to read, try `backup3.cpp`. If that's still too difficult, try `backup2.cpp`, and then `backup1.cpp`. Decreasing backup number means more readability, but higher file size.
