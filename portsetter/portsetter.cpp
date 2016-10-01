//This Program was written by Adam Case
//portsetter:
//Takes in arguments and either prints the usage page, or connects the user to a port.
//Written for CS3370 David Wagstaff
//Date: 2016-09-02

#include"iostream"
#include"string"
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include<vector>
#include<regex>

using namespace std;

//enumerates messages
enum {
    SET,
    EXCEEDS,
    INVPARAM,
    RANGE,
    INVPORT,
    VERSION,
};

//Prints help section for user
void printUsage(string fileName);

void printAbout(string fileName);

string determineLang();

int main(int argc, const char * args[]){
    
    //declare local variables
    const int PORT_MAX = 65536;
    int connectToPort;
    string::size_type strSize;
    string flag;
    string portNumber;
    string version = "1.2";
    vector<string> msg;
    string langCode;
    
    //file name variables
    string usageFile, aboutFile, msgFile;
    
    //setenv("LANGUAGE","de.UTF-8",1);//testing purposes
    
    //get language code defaults to english if none is set
    langCode = determineLang();
    
    //build file names based on language code returned
    msgFile = "/home/ubuntu/workspace/portsetter/portsetter.messages_" + langCode + ".txt";
    
    //get msg file and load messages
    ifstream messages(msgFile);
    
    if (messages.good()) {
        while(messages.peek() != EOF) {
            string line;
            getline(messages, line);
            msg.push_back(line);
        }
        
        //build file names
        usageFile = "/home/ubuntu/workspace/portsetter/portsetter.usage_" + langCode + ".txt";
        aboutFile = "/home/ubuntu/workspace/portsetter/portsetter.about_" + langCode + ".txt";
    } else { // if msgFile failed to open translations don't exists default to english
        
        cout << "Missing " << langCode << " translation files. Using English." << endl;
        msgFile = "/home/ubuntu/workspace/portsetter/portsetter.messages_en.txt";
        ///home/ubuntu/workspace/portsetter/
        
        ifstream messages(msgFile);
        
        if (messages.good()) {
            while(messages.peek() != EOF) {
                string line;
                getline(messages, line);
                msg.push_back(line);
            }
        }
        
        usageFile = "/home/ubuntu/workspace/portsetter/portsetter.usage_en.txt";
        aboutFile = "/home/ubuntu/workspace/portsetter/portsetter.about_en.txt";
    }
    
    //if only one parameter printUsage if more assign second parameter to variable.
    if (argc == 1) { 
        printUsage(usageFile);
        return 0;
    }//end of argc 1 check
    
    flag = string(args[1]);
    
    //If two parameters check flag and see if it is == '-h' || '--help'. anything else throw an error
    if (argc == 2){
        
        
        if ((flag == "-h" || flag == "--help") || flag == "-?"){
            printUsage(usageFile);
            return 0;
        }
        
        if (flag == "-!" || flag == "--about"){
            printAbout(aboutFile);
            return 0;
        }
        
        if (flag == "-v" || flag == "--version"){
            cout << "\n" << msg[VERSION] << version << endl;
            return 0;
        }
        
        cout << "\n" << msg[INVPARAM] << '\n';
        printUsage(usageFile);
        return 11;
    }//end of argc 2 check
    
    //check to see if 3 parameters passed. if # check to see if parameter is == '-p' || '--port'. 
    //If true check third parameter to verify it is an int within range for port numbers
    //If not throw an error or if not an int throw an error otherwise connect to port.
    if (argc == 3){
        
        if (flag == "-p" || flag == "--port") {
            
            portNumber = string(args[2]);
            
            if (portNumber == "-e") {
               char* envPort = getenv("PORT");
               connectToPort = stoi(envPort);
               cout << msg[SET] << connectToPort << endl;
               return 0;
            }
            
            connectToPort = stoi(portNumber, &strSize);
            
            //checks to see if there is more than just a number on the third parameter. if there is throw an error
            if (portNumber.substr(strSize) != "")
            {
                cout << "\n" << msg[INVPORT] << endl;
                printUsage(usageFile);
                return 13;
            }
            
            //checks range of port. if in range connect if not throw error
            if(connectToPort > 0 && connectToPort < PORT_MAX){
                cout << msg[SET] << connectToPort << endl;
                return 0;
            }
            cout << "\n" << msg[RANGE] << endl;
            printUsage(usageFile);
            return 12;
            
            
        }
        // throws error if parameter 2 is != '-p' || '--port'.
        cout << "\n" << msg[INVPARAM] << '\n';
        printUsage(usageFile);
        return 11;

    }//end of argc 3 check
    
    //if more than 4 parameters are passed in throw an error
    if (argc == 4) {
        
        //this section is for -e flag. first checks if a -p flag exists if it 
        //does it checks for a -e flag then either sets to default or sets to 
        //name passed in
        if (flag == "-p" || flag == "--port") {
            portNumber = string(args[2]);
            
            if(portNumber == "-e") {
                const char * envVar = args[3];
                char* envPort = getenv(envVar);
                connectToPort = stoi(envPort, &strSize);
                
                
                 //checks to see if there is more than just a number on the third parameter. if there is throw an error
                if (string(envPort).substr(strSize) != "")
                {
                    cout << "\n" << msg[INVPORT] << endl;
                    printUsage(usageFile);
                    return 13;
                }
                
                
                //checks range of port. if in range connect if not throw error
                if(connectToPort > 0 && connectToPort < PORT_MAX){
                    cout << msg[SET] << connectToPort << endl;
                    return 0;
                }
                
                cout << "\n" << msg[RANGE] << endl;
                printUsage(usageFile);
                return 12;
                
                
            }
        }//end of argc4 check
        
        cout << "\n" << msg[EXCEEDS] << endl;
        printUsage(usageFile);
        return 10;
    }
    
    if (argc >= 5) {
        cout << "\n" << msg[EXCEEDS] << endl;
        printUsage(usageFile);
        return 10;
    }

}

void printUsage(string fileName){
    ifstream usagefile (fileName);
    
    if(usagefile.good()) {
        while(usagefile.peek() != EOF)
        {
            string line;
            getline(usagefile, line);
            cout << line << endl;
        }
    }
}

void printAbout(string fileName){
    ifstream aboutfile (fileName);
    
    if(aboutfile.good()) {
        while(aboutfile.peek() != EOF)
        {
            string line;
            getline(aboutfile, line);
            cout << line << endl;
        }
    }
}

string determineLang(){
    string::size_type strSize;
    string langEnv = "C C.UTF-8";
    char* language;
    string langVal;
    //regex e("^([a-z]{2})_([A-Z]{2})|^([a-z]{2})");// This is where I am erring out. expression is bad?
    //smatch match;
    
    //list of env variabels to look through
    const char* envVar[] = {
        "LANGUAGE",
        "LC_ALL",
        "LC_MESSAGES",
        "LANG"
    };
    
    //loop through envVar and determine if they exist and what value they have
    for (int i = 0; i < 4; ++i) {
        language = getenv(envVar[i]);
        
        if (language != nullptr) {
            string slang(language);
            //start test regex
            /*
            if (regex_search(slang, match, e)) {
                langVal = match[1];
            } else {
                cout << "Bad Language Specification in enviroment variable " 
                << envVar[i] << "=" << slang << "using english." << endl;
                langVal = "en";
            }
            
            //end test regex
            */
            strSize = langEnv.find(slang);
        
            if (strSize == string::npos && slang != "") {
                langVal = slang.substr(0,2);
                break;
            } else {
                langVal = "en";
            }
            
        }
    }
    
    return langVal;
}
