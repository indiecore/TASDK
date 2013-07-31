#pragma once
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "Engine.FaceFXAsset.h"
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
	class FaceFXAnimSet : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, RawFaceFXAnimSetBytes, 68)
		ADD_STRUCT(ScriptArray<byte>, RawFaceFXMiniSessionBytes, 80)
		ADD_STRUCT(ScriptArray<class SoundCue*>, ReferencedSoundCues, 92)
		ADD_STRUCT(int, NumLoadErrors, 104)
		ADD_STRUCT(Object::Pointer, InternalFaceFXAnimSet, 64)
		ADD_OBJECT(FaceFXAsset, DefaultFaceFXAsset, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
