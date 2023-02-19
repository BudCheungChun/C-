import pyautogui
import sys
import os
import time



print(os.getcwd()) 														# For ready the files
File_01 = open("Pixel_File_01.txt","w")
File_02 = open("Pixel_File_02.txt","w")
File_01.write(" ")
File_02.write(" ")
File_01.close()
File_02.close()

Space_Time = 2
Space_Subtitle = 40
Time_x1 = 209
Time_y1 = 1032
Time_x2 = 223
Time_y2 = 1052
Subtitle_x1 = 759
Subtitle_y1 = 947
Subtitle_x2 = 1154
Subtitle_y2 = 974
#def Open_Program01_Pixel_File_01():
#	Pixel_File_01 = open("Pixel_File_01.txt","a")

#def Open_Program02_Pixel_File_02():
#	Pixel_File_02 = open("Pixel_File_02.txt","a")


def List_To_Combined_Str(RGB):											# >>> 3 <<< RGB List To Str
	Str_Pixel = ""
	for i in RGB:
		Str_Pixel = Str_Pixel + "," + str(i)
	Str_Pixel = Str_Pixel[1:]
	return Str_Pixel

# ~ def Write_File_01(Str):													# >>> 4 <<<
	# ~ _n = "\n"
	# ~ Pixel_File_01.write(Str + _n)
	# ~ #Pixel_File_01.close()

# ~ def Write_File_02(Str):													# >>> 5 <<<
	# ~ _n = "\n"
	# ~ Pixel_File_02.write(Str + _n)
	# ~ #Pixel_File_02.close()
	
def Program01(): 
	Pixel_File_01 = open("Pixel_File_01.txt","a")											# >>> 1 <<<
	for x in range (Time_x1,Time_x2,Space_Time):
		for y in range (Time_y1,Time_y2,Space_Time):
			
			RGB_01 = pyautogui.pixel(x,y)								# Put the recent pixel point's color in RGB01
			_n = "\n"								
			Pixel_File_01.write(List_To_Combined_Str(RGB_01) + _n)		# Call >List to Str< function to make the -
																		# RGB_01 list to str and write it to File_01
	# ~ for x in range (Subtitle_x1,Subtitle_x2,Space_Subtitle):
		# ~ for y in range (Subtitle_y1,Subtitle_y2,Space_Subtitle):
			# ~ RGB_01 = pyautogui.pixel(x,y)
			# ~ _n = "\n"
			# ~ Pixel_File_01.write(List_To_Combined_Str(RGB_01) + _n)		
	Pixel_File_01.close()											
			#List_To_Combined_Str(RGB_01)

# ~ def Subtitle_On_Off():
	# ~ if (((List_To_Combined_Str(pyautogui.pixel(Subtitle_x1,Subtitle_y1))) == "5,5,5") or ((List_To_Combined_Str(pyautogui.pixel(Subtitle_x2,Subtitle_y2))) == "5,5,5")):
		# ~ Subtitle = True
	# ~ else:
		# ~ Subtitle = False
	# ~ return Subtitle


def Program02():
	Pixel_File_02 = open("Pixel_File_02.txt","a")														# >>> 2 <<<
	for x in range (Time_x1,Time_x2,Space_Time):
		for y in range (Time_y1,Time_y2,Space_Time):
			RGB_02 = pyautogui.pixel(x,y)
			_n = "\n"													# Put the recent pixel point's color in RGB02
			#Write_File_01(List_To_Combined_Str(RGB_01))				
			Pixel_File_02.write(List_To_Combined_Str(RGB_02) + _n)		# Call >List to Str< function to make the -
																		# RGB_02 list to str and write it to File_02
	# ~ for x in range (Subtitle_x1,Subtitle_x2,Space_Subtitle):
		# ~ for y in range (Subtitle_y1,Subtitle_y2,Space_Subtitle):
			# ~ RGB_02 = pyautogui.pixel(x,y)
			# ~ _n = "\n"
			# ~ Pixel_File_02.write(List_To_Combined_Str(RGB_02) + _n)
	Pixel_File_02.close()
			#List_To_Combined_Str(RGB_02)

def Count_Lines(File_):													# >>> 7 <<< Count How Many Lines in File01
	with open("Pixel_File_01.txt") as File__:											#			To Determine How Many Times	The
		Lines = File__.readlines()										#			For Loop Will Run in 6
		Count_Lines = len(Lines)
		return Count_Lines
			
def StrCmp():															# >>> 6 <<< Compare Two Files With Every
	Equal = True														#			Single Line
	File_01 = open("Pixel_File_01.txt")
	File_02 = open("Pixel_File_02.txt")
	for i in range(Count_Lines("Pixel_File_01.txt")):					# ---> 7
		if ((File_01.readline()) == (File_02.readline())):
			Equal = True
		else:
			Equal = False
			break
	File_01.close()
	File_02.close()
	print(Equal)
	#print(Count_lines("Pixel_File_01.txt"))
	return Equal
	

Begining_Time = time.time()	
while ((time.time()) < (Begining_Time + (60*60*14))):
	pyautogui.moveTo(100,100,3)
	pyautogui.moveTo(500,100,3)
	Program01_Begin_time = time.time()
	
	Program01()
	
	# ~ Sub01 = Subtitle_On_Off()
	# ~ if(Sub01):
		# ~ print("Subtitle_Signal01_On")
	# ~ else:
		# ~ print("Subtitle_Signal01_Off")
		
	print("Program01 used",str(((time.time()) - Program01_Begin_time)/60) , "min")  #print how long does Prog01 take
	
	time.sleep(1)
	
	pyautogui.moveTo(100,200,3)
	pyautogui.moveTo(500,200,3)
	Program02_Begin_time = time.time()
	Program02()
	
	# ~ Sub02 = Subtitle_On_Off()
	# ~ if(Sub02):
		# ~ print("Subtitle_Signal02_On")
	# ~ else:
		# ~ print("Subtitle_Signal02_Off")
	
	print("Program02 used",str(((time.time()) - Program02_Begin_time)/60) , "min")
	
	# ~ if(Sub01 or Sub02):
		# ~ print("Subtitle_On_No_Action")
	# ~ else:
		# ~ pyautogui.click(1720,1049)
		
	
	if(StrCmp() == False):
		os.remove("Pixel_File_01.txt")
		os.remove("Pixel_File_02.txt")
		print("False , Playing")
		continue
	else:
		print("True , Stopped")
		pyautogui.press("space")
		# ~ time.sleep(5)
		os.remove("Pixel_File_01.txt")
		os.remove("Pixel_File_02.txt")


		





