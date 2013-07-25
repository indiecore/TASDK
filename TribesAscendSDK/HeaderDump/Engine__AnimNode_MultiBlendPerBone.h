#pragma once
#include "Engine__Pawn.h"
#include "Engine__AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNode_MultiBlendPerBone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNode_MultiBlendPerBone." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNode_MultiBlendPerBone : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(Pawn, PawnOwner)
		ADD_VAR(::ByteProperty, RotationBlendType, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetMaskWeight'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
