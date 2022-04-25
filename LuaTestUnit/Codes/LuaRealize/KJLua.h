//
//  KJLua.h
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#ifndef KJLua_h
#define KJLua_h

#include <stddef.h>

#include "KJLuaconf.h"

// `ESCLua`的 ASCII码， 0x1B4C7561, 魔数快速识别二进制文件格式
#define LUA_SIGNATURE    "\x1bLua"

// 线程状态机
typedef struct lua_State lua_State;

typedef struct LClosure {
//  ClosureHeader;
//  struct Proto *p;
//  UpVal *upvals[1];  /* list of upvalues */
} LClosure;


#pragma mark - 方法定义

typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);


#endif /* KJLua_h */
