#ifndef CSM_DEV_H_INCLUDED
#define CSM_DEV_H_INCLUDED

#include "CSM.h"

typedef enum {
    CSM_TRUE = 1,
    CSM_FALSE = 0
} CSM_Boolean;

typedef struct CSM_String_tag CSM_String;

typedef struct {
    char *name;
} CSM_NativePointerInfo;

typedef enum{
    CSM_BOOLEAN = 1,
    CSM_INT,
    CSM_DOUBLE,
    CSM_STRING,
    CSM_NATIVEPOINTER,
    CSM_NULL
} CSM_ValueType;

typedef struct {
    CSM_NativePointerInfo   *info;
    void    *pointer;
} CSM_NativePointer;

typedef struct {
    CSM_ValueType type;
    union {
        CSM_Boolean boolean_value;
        int int_value;
        double double_value;
        CSM_String *string_value;
        CSM_NativePointer native_pointer;
    }   u;
} CSM_Value;

typedef CSM_Value CSM_NativeFunctionProc(CSM_Interpreter *interpreter, int args_count, CSM_Value *args);
void CSM_addNativeFunction(CSM_Interpreter *interpreter, char *name, CSM_NativeFunctionProc *proc);

#endif // CSM_DEV_H_INCLUDED
