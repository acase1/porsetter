####Create "setport" shortcut:

    1. From your home directory type in the following command: `sudo nano /bin/setport`
   This will open a text editor.
    2. Type the following into nano: `~/workspace/portsetter/porsetter.cpp.o $1 $2 $3 $4`
    3. Save file.
    4. Exit nano
    5. from the command line type the following: `sudo chmod 777 /bin/setport`
    6. now type in `setport`. This will print the usage page.

####Test portsetter.cpp.o

1. make sure you are in the _portsetter_ directory
2. type `./testportsetter.cpp.o` this will initiate the test program. The test program will list all test performed, 
	   if the test succeeded or not, and makes sure the proper output eas printed.

####Adding new test for testportsetter:

testportsetter was written in a way to allow users to create their own tests. In order to add new tests for testportsetter follow the below steps.
	
>1. open the testCases.txt file
>2. scroll to the bottom of the file.
>3. each test will require three lines within the testCase.txt file
>	a. first line: the desired command and flags along with piping into test.txt file. For example to run the command setport -p 592 type setport -p 592 >test.txt
>	b. second line: the expected return value. From the command above we would enter a 0 for the second line
>	c. third line: for the third lilne type the name of the file you want to compare it to. Make sure that the file you select will have the expected output from the program in it.
>4. Make sure that the cursor is at the end of the last line entered and no blank lines are left in the testCase.txt file.

####Add new language support:

In order to add new languages to the existing program all that is needed is translated files. Make sure that those files are saved with the following file name format:
`portsetter.[_file purpose_]_[_language code_].txt`
		
note that _file purpose_ is for what the file contains. for example the usage file has the purpose of **'usage'** thus _usage_ will be use in place of 'file purpose';_ language code_ is the 
two letter language code.
	
Make sure when adding the new `portsetter.messages_[language_code].txt` file that the message translations are kept in the same order.