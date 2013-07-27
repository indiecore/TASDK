#pragma once
#include "Engine.SequenceAction.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ModifyProperty : public SequenceAction
	{
	public:
		struct PropertyInfo
		{
		public:
			ADD_STRUCT(ScriptString*, PropertyValue, 12)
			ADD_BOOL(bModifyProperty, 8, 0x1)
			ADD_STRUCT(ScriptName, PropertyName, 0)
		};
		ADD_STRUCT(ScriptArray<SeqAct_ModifyProperty::PropertyInfo>, Properties, 232)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
