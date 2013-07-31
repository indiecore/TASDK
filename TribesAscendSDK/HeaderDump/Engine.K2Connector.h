#pragma once
#include "Core.Object.h"
#include "Engine.K2NodeBase.h"
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
	class K2Connector : public Object
	{
	public:
		enum EK2ConnectorType : byte
		{
			K2CT_Bool = 0,
			K2CT_Int = 1,
			K2CT_Float = 2,
			K2CT_Vector = 3,
			K2CT_Rotator = 4,
			K2CT_String = 5,
			K2CT_Object = 6,
			K2CT_Exec = 7,
			K2CT_Unsupported = 8,
			K2CT_MAX = 9,
		};
		enum EK2ConnectorDirection : byte
		{
			K2CD_Input = 0,
			K2CD_Output = 1,
			K2CD_MAX = 2,
		};
		ADD_STRUCT(K2Connector::EK2ConnectorType, Type, 76)
		ADD_STRUCT(ScriptString*, ConnName, 64)
		ADD_OBJECT(K2NodeBase, OwningNode, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
