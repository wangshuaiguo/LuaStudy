//
//  KJLuaconf.h
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#ifndef KJLuaconf_h
#define KJLuaconf_h

#if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
    defined(__ELF__)        /* { */
#define LUAI_FUNC    __attribute__((visibility("hidden"))) extern
#else                /* }{ */
#define LUAI_FUNC    extern
#endif                /* } */



#pragma mark - Limites

typedef unsigned char lu_byte;

#if defined(__GNUC__)
#define l_noret        void __attribute__((noreturn))
#elif defined(_MSC_VER) && _MSC_VER >= 1200
#define l_noret        void __declspec(noreturn)
#else
#define l_noret        void
#endif


//外界提供， 内部进出虚拟机core的时候调用
#if !defined(lua_lock)
#define lua_lock(L)    ((void) 0)
#define lua_unlock(L)    ((void) 0)
#endif

// 类型转换
#define cast(t, exp)    ((t)(exp))
#define cast_void(i)    cast(void, (i))
#define cast_byte(i)    cast(lu_byte, (i))
#define cast_num(i)    cast(lua_Number, (i))
#define cast_int(i)    cast(int, (i))
#define cast_uchar(i)    cast(unsigned char, (i))



#endif /* KJLuaconf_h */
