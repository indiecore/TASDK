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
		void SetMaskWeight(int MaskIndex, float DesiredWeight, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode_MultiBlendPerBone.SetMaskWeight");
			byte* params = (byte*)malloc(12);
			*(int*)params = MaskIndex;
			*(float*)(params + 4) = DesiredWeight;
			*(float*)(params + 8) = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
