//
//  KJLundump.c
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#include "KJLundump.h"
#include "KJLzio.h"
#include <string.h>


typedef struct {
  lua_State *L;
  ZIO *Z;
  const char *name;
} LoadState;






static l_noret error(LoadState *S, const char *why) {
//  luaO_pushfstring(S->L, "%s: %s precompiled chunk", S->name, why);
//  luaD_throw(S->L, LUA_ERRSYNTAX);
}



#pragma mark -
#define LoadVector(S,b,n)    LoadBlock(S,b,(n)*sizeof((b)[0]))
static void LoadBlock(LoadState *S, void *b, size_t size) {
  if (luaZ_read(S->Z, b, size) != 0)
    error(S, "truncated");
}

#define LoadVar(S,x)        LoadVector(S,&x,1)
static lu_byte LoadByte(LoadState *S) {
    lu_byte x;
    LoadVar(S, x);
    return x;
}


static void checkliteral (LoadState *S, const char *s, const char *msg) {
  char buff[sizeof(LUA_SIGNATURE) + sizeof(LUAC_DATA)]; /* larger than both */
  size_t len = strlen(s);
  LoadVector(S, buff, len);
  if (memcmp(s, buff, len) != 0)
    error(S, msg);
}

static void checkHeader (LoadState *S) {
    checkliteral(S, LUA_SIGNATURE + 1, "not a");  /* 1st char already checked */
    if (Load) {
        <#statements#>
    }

}


#pragma mark - api

LClosure *luaU_undump(lua_State *L, ZIO *Z, const char *name) {
    LoadState S;
    LClosure *cl;

    // 判断来源
    if (*name == '@' || *name == '=') {
        S.name = name + 1; //指针偏移一个字节
    } else if (*name == LUA_SIGNATURE[0]) {
        S.name = "binary string"; //与魔数签名地址相同，说明是二进制chunk
    } else {
        S.name = name;
    }
    
    S.L = L;
    S.Z = Z;
    checkHeader(&S);
    
    
    return cl;
}
