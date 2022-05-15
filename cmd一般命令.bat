color 0a
pause

改視窗名
title ABCCD
pause



新增txt >覆蓋 >>追加
cd C:\Users\safef\Desktop\bat
echo world is very well >aaa.txt
echo !!!>>aaa.txt
type aaa.txt | more
pause


dir c:\windows | more
pause
del aaa.txt
pause
echo aaaaaaaaaaa >aaa1.txt
echo aaaaaaaaaaa >aaa2.txt
echo aaaaaaaaaaa >aaa3.txt
echo aaaaaaaaaaa >aaa4.txt
echo aaaaaaaaaaa >aaa5.txt
echo aaaaaaaaaaa >aaa6.txt
echo aaaaaaaaaaa >aaa7.txt
pause
del *.txt
pause

複製檔案、移動、改名
cd C:\Users\safef\Desktop\bat
mkdir a b
pause
新增檔案
echo aaaaaaaaaaaaa >C:\Users\safef\Desktop\bat\a\aaa3.txt
pause
同一文件夾下複製
copy C:\Users\safef\Desktop\bat\a\aaa3.txt C:\Users\safef\Desktop\bat\a\aaa4.txt
pause
跨文件夾複製
copy C:\Users\safef\Desktop\bat\a\aaa4.txt C:\Users\safef\Desktop\bat\b\aaa4.txt
pause
移動文件
move C:\Users\safef\Desktop\bat\a\aaa3.txt C:\Users\safef\Desktop\bat\b
pause
文件改名
move C:\Users\safef\Desktop\bat\b\aaa3.txt C:\Users\safef\Desktop\bat\b\aaa5.txt
pause
刪除三個文件
del C:\Users\safef\Desktop\bat\a\aaa4.txt
del C:\Users\safef\Desktop\bat\b\aaa5.txt
del C:\Users\safef\Desktop\bat\b\aaa4.txt
刪除兩個文件夾
rmdir C:\Users\safef\Desktop\bat\a
rmdir C:\Users\safef\Desktop\bat\b
pause


mkdir newfile
pause
cd C:\Users\safef\Desktop\bat\newfile
echo aaaaaaaaaaa >aaa1.txt
echo aaaaaaaaaaa >aaa2.txt
echo aaaaaaaaaaa >aaa3.txt
echo aaaaaaaaaaa >aaa4.txt
echo aaaaaaaaaaa >aaa5.txt
echo aaaaaaaaaaa >aaa6.txt
echo aaaaaaaaaaa >aaa7.txt
pause
批量刪除所有檔案,/q無提示
del *.* /q
pause
cd C:\Users\safef\Desktop\bat 
pause
rmdir newfile /q
pause


新增隱藏檔案
mkdir attrib_system_file
pause
attrib +h +s +a attrib_system_file
pause
dir /a
pause
attrib -h -s -a attrib_system_file
rmdir attrib_system_file
pause


新增10GB隱藏檔案
fsutil file createNew C:\Users\safef\Desktop\bat\system.ini路徑 檔案名 10000000000大小
pause
fsutil file createNew C:\Users\safef\Desktop\bat\system.ini 10000000000
pause
attrib屬性 +h隱藏 +s設置成系統檔案 +a只讀 system.ini
attrib +h +s +a system.ini
pause
attrib -h -s -a system.ini
del system.ini
pause

(暫時無用)修改檔關聯性
pause
echo aaaaaaaaaa >aaa.txt
assoc .txt=exefile
pause
assoc .txt=txtfile
pause

@echo off
echo =====================
echo.
echo           A
echo.
echo =====================
