//
//  KJLundump.h
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#ifndef KJLundump_h
#define KJLundump_h

#include "KJLua.h"
#include "KJLzio.h"

/**
 1. 魔数 LUA_SIGNATURE
 2. 版本号 LUAC_VERSION
 3. 格式号 LUAC_FORMAT
 4. 进一步校验 LUAC_DATA
 5. 整数和lua虚拟机指令宽度
 6. 大小端 LUAC_INT
 7. 浮点数校验 LUAC_NUM
 */


#define MYINT(s)    (s[0]-'0')

// 版本号 5*16 + 3
#define LUAC_VERSION    (MYINT(LUA_VERSION_MAJOR)*16+MYINT(LUA_VERSION_MINOR))

#define LUAC_FORMAT    0    /* this is the official format */

// 0x1993 0x0D(回车符) 0x0A(换行符) 0x1A(替换符) 0x0A(换行符) 进一步校验
#define LUAC_DATA    "\x19\x93\r\n\x1a\n"

// LUAC——INT 判断大小端用
#define LUAC_INT    0x5678

// IEEE 754浮点数格式。
#define LUAC_NUM    cast_num(370.5)


//LUAI_FUNC int luaU_dump (lua_State* L, const Proto* f, lua_Writer w, void* data, int strip);

LUAI_FUNC LClosure* luaU_undump (lua_State* L, ZIO* Z, const char* name);


#endif /* KJLundump_h */
