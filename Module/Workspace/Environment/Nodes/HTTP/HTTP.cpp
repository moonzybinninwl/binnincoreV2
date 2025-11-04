#include "HTTP.hpp"
#pragma comment(lib, "wininet.lib")

#include <Dependencies/nlohmann/json.hpp>
#include <unordered_set>
#include <winbase.h>
#include <wininet.h>
#include <optional>
#include <sstream>    
#include <string>     
#include <iostream>   
#include <windows.h>
#include <string>
#include <stdexcept>
#include <windows.h>
#include <string>
#include <stdexcept>
#include <cctype>
#include <lualib.h>
#include <cpr/cpr.h>

void HTTPLibrary::Initialize(lua_State* L)
{

}