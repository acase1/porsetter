####Program Location
Make sure that when program is downloaded it is placed in the following location `~/workspace`

####Make and compile program
In to create the executable for the portsetter and testportsetter program perform the following steps

1. make sure you are in the directory for portsetter
2. type the command `make`
3. after typing make you should see two new files appear `testportsetter` and `setport`
4. Now that you have made these executables you can now setup the shortcut

####Create "setport" shortcut:

**Note:** Make sure you have created the executables before performing this step. 
creating executables can be found in the **Make and compile program** section 

1. From your home directory type in the following command: `sudo nano /bin/setport`
   This will open a text editor.
2. Type the following into nano: `~/workspace/portsetter/setport $1 $2 $3 $4`
3. Save file.
4. Exit nano
5. from the command line type the following: `sudo chmod 777 /bin/setport`
6. now type in `setport`. This will print the usage page.

####Test portsetter.cpp.o

1. make sure you are in the _portsetter_ directory
2. type `./testportsetter` this will initiate the test program. The test program will list all test performed, 
	   if the test succeeded or not, and makes sure the proper output is printed.

####Adding new test for testportsetter:

testportsetter was written in a way to allow users to create their own tests. In order to add new tests for testportsetter follow the below steps.
	
1. open the _testCases.txt_ file
2. scroll to the bottom of the file.
3. each test will require three lines within the _testCase.txt_ file

   **note: optional first line** when testing with another language, add a line that includes the statement 'change envVar' followed by another line with the language enviroment variable value.
         All other lines preceding this change should include the tests desired for this language until the end of file is reached or another language change will happen.
         For example; if you wanted to run a test on the language code for german enter the following two lines: 
         
         `change envVar`
         `de_DE.UTF-8` (assuming that this would be the enviremoent variable for german language)
         
	1. **first line:** the desired command and flags along with piping into _test.txt_ file. For example to run the command `setport -p 592` type `setport -p 592 >test.txt`
	2. **second line:** the expected return value. From the command above we would enter a `0` for the second line
	3. **third line:** for the third line type the name of the file you want to compare it to. Make sure that the file you select will have the expected output from the program in it.
4. Make sure that the cursor is at the end of the last line entered and no blank lines are left in the _testCase.txt_ file.

####Add new language support:

In order to add new languages to the existing program all that is needed is translated files. Make sure that those files are saved with the following file name format:
`portsetter.[file purpose]_[language code].txt`
		
note that `file purpose` is for what the file contains. for example the usage file has the purpose of **'usage'** thus `usage` will be use in place of `file purpose`; ` language code` is the 
two letter language code.
	
Make sure when adding the new `portsetter.messages_[language code].txt` file that the message translations are kept in the same order.