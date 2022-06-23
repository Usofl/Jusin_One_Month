#pragma once

#ifdef MY220623_ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)

#else
#define ENGINE_DLL _declspec(dllimport)
#endif