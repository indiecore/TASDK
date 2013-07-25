#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByFlying." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByFlying." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByFlying : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn)
		ADD_VAR(::ByteProperty, LastDirection, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
