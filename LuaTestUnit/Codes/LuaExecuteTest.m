//
//  LuaExcuteTest.m
//  LuaTestUnit
//
//  Created by Jack on 2022/4/24.
//

#import "LuaExecuteTest.h"
#import <lualib/lauxlib.h>
#import <lualib/lualib.h>

static lua_State *_luaP_currentState = nil;
lua_State *luaP_currentState(void) {
    if (!_luaP_currentState) {
        _luaP_currentState = luaL_newstate();
        luaL_openlibs(_luaP_currentState);
    }
    return _luaP_currentState;
}


@implementation LuaExecuteTest

+ (void)testExecute {
    lua_State * L = luaP_currentState();
    NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"luacode" ofType:@"bundle"];
    NSBundle *luaBundle = [[NSBundle alloc] initWithPath:bundlePath];
    
    
    NSString *luaPath = [luaBundle pathForResource:@"luaTest" ofType:@"lua"];
    luaL_dofile(L, luaPath.UTF8String);
    
    
    
}


+ (void)realize {
    
}



@end
