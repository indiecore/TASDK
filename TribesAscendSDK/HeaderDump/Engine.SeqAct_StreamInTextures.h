#pragma once
#include "Core.Object.h"
#include "Engine.SeqAct_Latent.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Texture.h"
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
	class SeqAct_StreamInTextures : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, LocationActors, 260)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, ForceMaterials, 272)
		ADD_STRUCT(int, SelectedCinematicTextureGroups, 288)
		ADD_STRUCT(Texture::TextureGroupContainer, CinematicTextureGroups, 284)
		ADD_STRUCT(float, StopTimestamp, 256)
		ADD_STRUCT(float, Seconds, 252)
		ADD_BOOL(bStreamingActive, 248, 0x2)
		ADD_BOOL(bLocationBased, 248, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_StreamInTextures.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
