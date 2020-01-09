#pragma once

#if (!defined(ROCK_LIB) && !defined(ROCK_LINUX_PLATFORM))
// ROCK is used as DLL
#define ROCK_DLLEXPORT __declspec(dllexport) 
#define ROCK_DLLIMPORT __declspec(dllimport) 
#else 
#define ROCK_DLLEXPORT 
#define ROCK_DLLIMPORT
#endif

#ifdef ROCK_EXPORTS
#define ROCK_API ROCK_DLLEXPORT  
#else 
#define ROCK_API ROCK_DLLIMPORT 
#endif

#ifdef __cplusplus 
extern "C" { 
#endif

int ROCK_API init(const char* ip, const char* username, const char* passwd);
void ROCK_API cleanup();
int ROCK_API upload_file2(const char *remotepath, const char *localpath, int timeout, int tries, int overlap);
int ROCK_API upload_file(const char *remotepath, const char *localpath);

#ifdef __cplusplus
}
#endif
