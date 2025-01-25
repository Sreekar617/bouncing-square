cl /c /W4 /O1 /Os /GS- dvd.cpp

crinkler /ENTRY:EntryPoint  ^
         /SUBSYSTEM:windows ^
         /COMPMODE:VERYSLOW ^
         /HASHSIZE:512      ^
         /UNSAFEIMPORT      ^
         /OUT:dvd.exe        ^
         /TINYHEADER        ^
         /TINYIMPORT        ^
         /HASHTRIES:512     ^
         /ORDERTRIES:512   ^
         /UNALIGNCODE       ^
         dvd.obj gdi32.lib kernel32.lib user32.lib winmm.lib