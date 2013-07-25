#pragma once
#include "Engine.SkeletalMeshComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSkeletalMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
		ADD_VAR(::FloatProperty, m_fClearStreamingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bForceLoadTextures, 0x1)
		ADD_VAR(::FloatProperty, m_fFOV, 0xFFFFFFFF)
		void PreloadTextures(bool bForcePreload, float ClearTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSkeletalMeshComponent.PreloadTextures");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForcePreload;
			*(float*)(params + 4) = ClearTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSkeletalMeshComponent.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
