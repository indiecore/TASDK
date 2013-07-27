#pragma once
#include "Engine.SkeletalMeshComponent.h"
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
	class TrSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
		ADD_STRUCT(float, m_fClearStreamingTime, 1520)
		ADD_BOOL(m_bForceLoadTextures, 1516, 0x1)
		ADD_STRUCT(float, m_fFOV, 1512)
		void PreloadTextures(bool bForcePreload, float ClearTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112418);
			byte params[8] = { NULL };
			*(bool*)params = bForcePreload;
			*(float*)&params[4] = ClearTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112422);
			byte params[4] = { NULL };
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
