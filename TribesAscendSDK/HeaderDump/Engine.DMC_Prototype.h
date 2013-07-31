#pragma once
#include "Engine.K2GraphBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DMC_Prototype : public K2GraphBase
	{
	public:
		struct DMCNewVar
		{
		public:
			ADD_STRUCT(ScriptName, VarType, 8)
			ADD_STRUCT(ScriptName, VarName, 0)
		};
		ADD_STRUCT(ScriptArray<DMC_Prototype::DMCNewVar>, NewVars, 104)
		ADD_STRUCT(ScriptString*, DefaultPropText, 92)
		ADD_STRUCT(ScriptString*, FunctionCode, 80)
		ADD_OBJECT(ScriptClass, GeneratedClass, 76)
		ADD_OBJECT(ScriptClass, ParentClass, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
