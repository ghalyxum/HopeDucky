#include "include/String2WString.h"

using namespace std;


wstring String2WString(const string & str)
{
   if (str.empty())
      return wstring();

   size_t charsNeeded = ::MultiByteToWideChar(CP_UTF8, 0, 
      str.data(), (int)str.size(), NULL, 0);
   if (charsNeeded == 0)
      throw runtime_error("Failed converting UTF-8 string to UTF-16");

   vector<wchar_t> buffer(charsNeeded);
   int charsConverted = ::MultiByteToWideChar(CP_UTF8, 0, 
      str.data(), (int)str.size(), &buffer[0], buffer.size());
   if (charsConverted == 0)
      throw runtime_error("Failed converting UTF-8 string to UTF-16");

   return wstring(&buffer[0], charsConverted);
}
