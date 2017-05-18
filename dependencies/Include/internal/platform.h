#ifndef MUTINY_PLATFORM_H
#define MUTINY_PLATFORM_H

#define USE_GLUT

#ifdef _WIN32
  #define USE_WINAPI 1
#endif

#include <memory>
#define shared std::shared_ptr
#define weak std::weak_ptr

#endif
