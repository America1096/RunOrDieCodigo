#ifndef THIRDPERSONCAMERA_H
#define THIRDPERSONCAMERA_H

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif

#include "Camera.h"

class DLL_PUBLIC ThirdPersonCamera: public Camera
{
public:
    ThirdPersonCamera();
    void mouseMoveCamera(float xoffset, float yoffset, float dt);
    void scrollMoveCamera(float soffset, float dt);
    void updateCamera();
	

};

#endif // THIRDPERSONCAMERA_H
