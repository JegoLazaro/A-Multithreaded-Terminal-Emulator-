# A-Multithreaded-Terminal-Emulator
A terminal prompt with your OS name like the illustration in  Figure 1. Ask the 
user for keyboard input. Your terminal should  recognize and execute the commands. 
The program should be compiled using gcc and should run in a Windows environment. 

say command 
Command: say <str> 
Parameters: str – text string to display 
Description: Displays the string str in a new line. The string can have spaces in 
between words. 
  
cls command 
Command: cls 
Parameters: None 
Description: Clears the entire screen. Displays a prompt like Figure 1. 
  
dir command 
Command: dir 
Parameters: None 
Description: Displays the content of the current directory. This includes the 
filename, file size, date and time created of each file. 
 
      Example output: 
      Filename: MyOS.exe 
      File Size: 153903 bytes 
      Created on: Sat Nov 14 18:47:43 2020 
pwd command 
Command: pwd 
Parameters: None 
Description: Prints current working directory. 
 
      Example output:  
      C:\Users\student\ 
  
time command 
Command: time 
Parameters: None 
Description: Prints the current date and time based on the clock.  
 
      Example output: 
      Sat Nov 14 18:48:15 2020 
  
title command 
Command: title <str> 
Parameters: str – new window title 
Description: Sets the string str as the new window title. If window title has been 
successfully changed, display an appropriate success message.  
  
Command color <color1> <color2> 
Parameters color1 – new background color 
color2 – new foreground color 
Description Sets color1 as new background color of the terminal and color2 as 
the new foreground (or font) color. 
 
Parameters color1 and color2 should be any of the following: 
• black 
• blue 
• green 
• red 
• purple 
• yellow 
• white 
• gray 
  
mkfldr command 
Command mkfldr <str> 
Parameters str – name of the folder to be created 
Description Creates a new folder named str in the current directory. If the 
folder has been successfully created, display an appropriate 
success message. Otherwise, display an appropriate error message. 
 
  
Command find <str> 
Parameters str – name of the text file to find 
Description Finds a text file named str in the current directory. If the file exists, 
display its details, including filename, file size, and date and time 
created. If the file does not exist, display an appropriate error 
message. 
 
      Example output: 
      File found! 
      Filename: Hello.txt 
      File Size: 153903 bytes 
      Created on: Sat Nov 14 18:47:43 2020 

  
open command 
Command open <str> 
Parameters str – name of the text file to open 
Description Opens a text file named str in the current directory. If the file 
exists, display its content as stored in the text file. If the file does 
not exist, display an appropriate error message. 
  
  
copy command 
Command copy <source> <dest> 
Parameters source – name of the source text file 
dest – name of the destination text file 
Description Copies a text file named source in the current directory to a new 
text file named dest. If the file source does not exist or the file dest 
already exist, display an appropriate error message. Otherwise, if 
the file source has been successfully copied to file dest, display an 
appropriate success message. 
  
  
rename command 
Command rename <oldName> <newName> 
Parameters oldName – name of the source text file 
newName – name of the destination text file 
Description Renames a text file named oldName in the current directory to 
newName. If the file oldName does not exist or the file newName already 
exist, display an appropriate error message. Otherwise, if the file 
oldName has been successfully renamed to file newName, display an 
appropriate success message. 
  
  
delete command 
Command delete <filename> 
Parameters filename – name of the text file to delete 
Description Deletes a text file named filename in the current directory. If the 
file filename does not exist, display an appropriate error message. 
Otherwise, if the file filename has been successfully deleted, 
display an appropriate success message. 
  
  
sort command 
Command sort <filename> <numLines> 
Parameters filename – name of the text file to sort 
numLines – integer representing the number of lines to sort in the 
text file 
Description Alphabetically sorts the contents of the text file named filename in 
the current directory. If the file filename does not exist, display an 
appropriate error message. Otherwise, display the sorted contents 
of the text file. 
 
        Sample content of input text file filename: 
        Zebra 
        Watch 
        Van 
        Umbrella 
        Cat 
        Apple 

        Sample output: 
        Apple 
        Cat 
        Umbrella 
        Van 
        Watch  
        Zebra 
  
  
marquee command 
Command marquee <str> 
Parameters str – text string to scroll from left to right 
Description Displays a scrolling string that will move from left to right. While 
the string is animating from left to right, you must still be able to 
enter and execute commands in the terminal.  
 
NOTE: It is possible to have multiple marquees executing in the 
same screen. 
  
  
exit command 
Command exit 
Parameters None 
Description Terminates the program.
