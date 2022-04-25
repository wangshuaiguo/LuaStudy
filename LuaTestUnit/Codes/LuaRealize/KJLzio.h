//
//  KJLZio.h
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#ifndef KJLZio_h
#define KJLZio_h

#include <stddef.h> // size_t

#include "KJLua.h"

#define EOZ    (-1)            /* end of stream */
typedef struct Zio ZIO;


LUAI_FUNC size_t luaZ_read (ZIO* z, void *b, size_t n);    /* read next n bytes */





struct Zio {
  size_t n;            /* bytes still unread */
  const char *p;        /* current position in buffer */
  lua_Reader reader;        /* reader function */
  void *data;            /* additional data */
  lua_State *L;            /* Lua state (for reader) */
};


#endif /* KJLZio_h */
