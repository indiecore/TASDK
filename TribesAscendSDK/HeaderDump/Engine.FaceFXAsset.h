#pragma once
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SoundCue.h"
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
	class FaceFXAsset : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, RawFaceFXActorBytes, 68)
		ADD_STRUCT(ScriptArray<byte>, RawFaceFXSessionBytes, 80)
		ADD_STRUCT(ScriptArray<class MorphTargetSet*>, PreviewMorphSets, 92)
		ADD_STRUCT(ScriptArray<class FaceFXAnimSet*>, MountedFaceFXAnimSets, 104)
		ADD_STRUCT(ScriptArray<class SoundCue*>, ReferencedSoundCues, 116)
		ADD_STRUCT(int, NumLoadErrors, 128)
		ADD_STRUCT(Object::Pointer, FaceFXActor, 64)
		ADD_OBJECT(SkeletalMesh, DefaultSkelMesh, 60)
		void MountFaceFXAnimSet(class FaceFXAnimSet* AnimSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FaceFXAsset.MountFaceFXAnimSet");
			byte params[4] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnmountFaceFXAnimSet(class FaceFXAnimSet* AnimSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FaceFXAsset.UnmountFaceFXAnimSet");
			byte params[4] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
