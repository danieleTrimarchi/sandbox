// Keylok.cpp: implementation of the CKeylok class.
//
//////////////////////////////////////////////////////////////////////

//#include "stdafx.h"
#include "Keylok.h"
#include "keylokclass.h"
#include "client.h"
#include <cstdlib>
#include <time.h>
#include <windows.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CKeylok::CKeylok()
{
}

CKeylok::~CKeylok()
{

}


/********************************* KTASK **********************************/

void CKeylok::KTASK(int CommandCode, int Argument2, int Argument3, int Argument4)
{

  // Only enable the next line of code when you are through debugging from within
  // the 32 bit IDE and are ready to test your program in a compiled .EXE format from
  // outside of the IDE.
  //KEYBD(LAUNCHANTIDEBUGGER); // Launch anti-debugging utility PPMON.EXE
  
  ReturnValue =  KFUNC(CommandCode, Argument2, Argument3, Argument4);
  ReturnValue1 = (int)ReturnValue & 0XFFFF;
  ReturnValue2 = (int)(ReturnValue >> 16);
 
  if ((CommandCode != TERMINATE ) && (CommandCode != CKREALCLOCK ))
    ShowLastKeyError();          // Display any errors from KTASK call 
}

bool CKeylok::CheckForKeyLok()
{
   KTASK((unsigned)(KLCHECK), ValidateCode1, ValidateCode2, ValidateCode3);
   KTASK(RotateLeft(ReturnValue1, (ReturnValue2 & 7)) ^ ReadCode3 ^ ReturnValue2,
         RotateLeft(ReturnValue2, (ReturnValue1 & 15)),
         ReturnValue1 ^ ReturnValue2, 0);
   // NOTE: Higher security can be achieved by using return values in
   //       computations and performing comparison of computed values to
   //       expected values deeper in your code than here.
   if ((ReturnValue1 == ClientIDCode1) && (ReturnValue2 == ClientIDCode2))
   {
		return true;
   }
   else
   {
        return false;
   }
}

void CKeylok::Terminate()
{
	KTASK(TERMINATE, rand(),rand(),rand() );
}

void CKeylok::ReadAuthorization()
{
	KTASK(READAUTH, ReadCode1, ReadCode2, ReadCode3);
}

int  CKeylok::GetSerialNumber()
{
	KTASK(GETSN, rand(), rand(), rand());

	return ReturnValue1;
}

int  CKeylok::GetDongleType()
{
	KTASK(GETDONGLETYPE, rand(), rand(), rand());

	return ReturnValue1;
}

unsigned long  CKeylok::GetLongSN()
{
	KTASK(GETLONGSN, rand(), rand(), rand());

	return ReturnValue;
}


int CKeylok::ReadMemory(int nAddr)
{
	KTASK(GETVARWORD, nAddr, rand(), rand());

	return ReturnValue1;
}

unsigned long CKeylok::CheckExpiration()
{
	KTASK(CKLEASEDATE, rand(), rand(), rand());

	return ReturnValue;
}

unsigned long CKeylok::CheckRTC()
{
	unsigned long status;
	KTASK(CKREALCLOCK, rand(), rand(), rand());
	status = GETLASTKEYERROR();
	if (status == 0)
		return ReturnValue;
	else		
		return (status);
}

int CKeylok::GetExpiration()
{
	KTASK(GETEXPDATE, rand(), rand(), rand());

	return ReturnValue1;
}

void CKeylok::WriteAuthorization()
{
	KTASK(WRITEAUTH, WriteCode1, WriteCode2, WriteCode3);
}

void CKeylok::WriteMemory(int nAddr, int nValue)
{
	KTASK(WRITEVARWORD, nAddr, nValue, rand());
}

unsigned long CKeylok::DecrementMemory(int nAddr)
{
	KTASK(DECREMENTMEM, nAddr, rand(), rand());
	return ReturnValue;
}

void CKeylok::WriteSerial(unsigned long lSerial)
{
	KTASK(SETLONGSN, (int)(lSerial >> 16), (int)lSerial, rand());
}

void CKeylok::SetExpiration(int nWriteDate)
{
	KTASK(SETEXPDATE, rand(), nWriteDate, rand());
}

void CKeylok::SetSessionTimeOut(int nTimeOut)
{
	KTASK(SETTIMEOUT, nTimeOut, rand(), rand());
}

int CKeylok::GetSessionTimeOut()
{
	KTASK(GETTIMEOUT, rand(), rand(), rand());

	return ReturnValue1;
}

void CKeylok::SelectTargetSN(int nSNIndex)
{
	KTASK(SELECTTARGETSN, nSNIndex, rand(), rand());

	return;
}

int CKeylok::GetWriteDate(int nYear, int nMonth, int nDay)
{
	int nWriteDate;
	nWriteDate = 512 * (nYear - 1990) + (32 * nMonth) + nDay;
	return nWriteDate;
}

int CKeylok::GetExpYear(int nExpDate)
{
	int nYear;
	nYear = (nExpDate & 0XFE00) / 512 + 1990;
	return nYear;
}

int CKeylok::GetExpMonth(int nExpDate)
{
	int nMonth;
	nMonth = ((nExpDate & 0X1E0)/32);
	return nMonth;
}

int CKeylok::GetExpDay(int nExpDate)
{
	int nDay;
	nDay = (nExpDate & 0X1F);
	return nDay;
}

void CKeylok::GetGUID(char* GlobalSN)
{
	DWORD	SNArray[10];
	memset((char *)SNArray,0,sizeof(SNArray));
	char	textStr[26];
	char 	textStr2[26];
	char	textStr3[10];
	char	textStr4[10];
	char	textStr5[10];
	memset((char *)textStr,0,sizeof(textStr));	
	memset((char *)textStr2,0,sizeof(textStr2));	
	memset((char *)textStr3,0,sizeof(textStr3));	
	memset((char *)textStr4,0,sizeof(textStr4));	
	memset((char *)textStr5,0,sizeof(textStr5));	
	KGETGUSN((char*)SNArray);
	_ltoa_s(SNArray[0],textStr3,sizeof(textStr3),16);
    strcpy_s(textStr4,sizeof(textStr4),"\0");
	while (strlen(textStr3) + strlen(textStr4) < 8)
	   strcat_s(textStr4, "0");
	strcpy_s(textStr2,sizeof(textStr2),"0x");
	strcat_s(textStr2, sizeof(textStr2),textStr4);
	strcat_s(textStr2, sizeof(textStr2),textStr3);
    strcpy_s(textStr,sizeof(textStr),textStr2);
	_ltoa_s(SNArray[1],textStr3,sizeof(textStr3),16);
	strcpy_s(textStr4,sizeof(textStr4),"\0");
	while (strlen(textStr3) + strlen(textStr4) < 8)
	  strcat_s(textStr4, "0");
	strcpy_s(textStr2,sizeof(textStr2),textStr4);
	strcat_s(textStr2, sizeof(textStr2),textStr3);
	strcat_s(textStr,sizeof(textStr),textStr2);
	strcat_s(GlobalSN,sizeof(textStr),textStr);
}
void CKeylok::ReadBlock(unsigned long lAddress, unsigned long lWordCount, char*
 pArray)
{
	KBLOCK(BLOCKREAD, lAddress, lWordCount, pArray);
}

void CKeylok::WriteBlock(unsigned long lAddress, unsigned long lWordCount, char*
 pArray)
{
	KBLOCK(BLOCKWRITE, lAddress, lWordCount, pArray);
}

void CKeylok::CodeVault(char* pExeDir, char* pExeFile, char* pUserPin, char* pData, short sBufferSize)
{
	KEXEC(pExeDir, pExeFile, pUserPin, pData, sBufferSize);
}

unsigned long CKeylok::GetFortressDongles(char* pSNArray, short sMaxSN)
{
	unsigned long count;
	count = KGETSNS(pSNArray, sMaxSN);
	return count;
}

int CKeylok::GetMaxUsers()
{
	KTASK(GETMAXUSERS, rand(), rand(), rand());

	return ReturnValue1;
}

int CKeylok::GetAbsMaxUsers()
{
	KTASK(GETABSOLUTEMAXUSERS, rand(), rand(), rand());

	return ReturnValue1;
}

void CKeylok::SetMaxUsers(int nMaxUsers)
{
	KTASK(SETMAXUSERS, nMaxUsers, rand(), rand());
}

void CKeylok::LEDOn()
{
	KTASK(LEDON, rand(), rand(), rand());
}

void CKeylok::LEDOff()
{
	KTASK(LEDOFF, rand(), rand(), rand());
}

void CKeylok::ShowLastKeyError()
{
/*  unsigned int error;

  error = GETLASTKEYERROR();
  switch( error ) {
    case 0:              // There was no error 
      return; 

    case KEY_ERROR_NOKEYLOK:
    case ERROR_FILE_NOT_FOUND:
      break;  // Let application display message
    case KEY_ERROR_WRONGKEYLOK:
	  MessageBox( "The KEY-LOK device failed to Authenticate.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_BADVERSION:
      MessageBox( "This KEY-LOK KFUNC call found old version of Driver.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_BADFUNC:
      MessageBox( "This KEY-LOK KFUNC Command was not recognized by the driver.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_NOREADAUTH:
      MessageBox( "The KEY-LOK failed the Read Authorization call.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_NOWRITEAUTH:
      MessageBox( "The KEY-LOK Memory  Write has not been authorized.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_INVALIDADDRESS:
      MessageBox( "The KEY-LOK Device Address is out of range.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_NOCOUNTSLEFT:
      MessageBox( "The counter was already fully counted down to zero.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_WRITETIMEOUT:
      MessageBox( "This KEY-LOK failed the internal Write Timeout Test.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;

    // the following error codes are standard winerror.h codes 

    case ERROR_NOT_SUPPORTED:
      MessageBox( "This KEY-LOK Internal DIOC Command not supported.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case ERROR_INTERNAL_ERROR:
      MessageBox( "This KEY-LOK command caused an internal DeviceIoControl Error.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case ERROR_BAD_ARGUMENTS:
      MessageBox( "This KEY-LOK command internal Arguments Bad.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case ERROR_OPEN_FAILED:
      MessageBox( "Could not find or load KEY-LOK device driver.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case ERROR_DEVICE_IN_USE:
      MessageBox( "The KEY-LOK LPT port cannot be accessed at this time.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case ERROR_ACCESS_DENIED:
      MessageBox( "The KEY-LOK session limit has been reached. Try again later.\n",
                  "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
    case KEY_ERROR_LEASEOVER:       // Lease Expiration
    case KEY_ERROR_SYSDATESETBK:    // System Date Setback Error
    case KEY_ERROR_NOLEASEDATE:     // No Lease Date   
    case KEY_ERROR_LEASEDATEBAD:    // Lease Date Bad  
    case KEY_ERROR_FSDATEBAD:       // FS Date Bad
      // Message box not required - taken care of within application
      break;
    default:
      wsprintf( textStr,
                "Unrecognized KEY-LOK error has occured (Error %x).",
                error );
      MessageBox( textStr, "KEY-LOK COMMAND ERROR", MB_ICONEXCLAMATION | MB_OK );
      break;
  }*/
}

