cl.exe /c /O1 /GS- /MD /EHsc /Tc test.cpp /Fo:test.obj
crinkler.exe test.obj /entry:WinMain /subsystem:windows /librarypath:"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\lib\x86" /librarypath:"C:\Program Files (x86)\Windows Kits\10\lib\10.0.26100.0\um\x86" /librarypath:"C:\Program Files (x86)\Windows Kits\10\lib\10.0.26100.0\ucrt\x86" "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\lib\x86\LIBCMT.lib" "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\lib\x86\libvcruntime.lib" "C:\Program Files (x86)\Windows Kits\10\lib\10.0.26100.0\ucrt\x86\libucrt.lib" "C:\Program Files (x86)\Windows Kits\10\lib\10.0.26100.0\um\x86\User32.lib" "C:\Program Files (x86)\Windows Kits\10\lib\10.0.26100.0\um\x86\Kernel32.lib"
out.exe