#pragma once
#include <Workspace/Environment/Environment.hpp>
/* Hello so, you need to make the declared functions yourself. I may add them in the future*/
enum RequestMethods
{
    H_GET,
    H_HEAD,
    H_POST,
    H_PUT,
    H_DELETE,
    H_OPTIONS
};

inline std::map<std::string, RequestMethods> RequestMethodMap = {
   { "get", H_GET },
   { "head", H_HEAD },
   { "post", H_POST },
   { "put", H_PUT },
   { "delete", H_DELETE },
   { "options", H_OPTIONS }
};

class HTTPLibrary
{
public:
	static void Initialize(lua_State* L);
    static int GetObjects(lua_State* L);
    static int HTTPGet(lua_State* L);
};
