#pragma once
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.FaceFXAnimSet.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FaceFXAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FaceFXAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FaceFXAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FaceFXAsset : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumLoadErrors, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FaceFXActor'!
		ADD_OBJECT(SkeletalMesh, DefaultSkelMesh)
		void MountFaceFXAnimSet(class FaceFXAnimSet* AnimSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FaceFXAsset.MountFaceFXAnimSet");
			byte* params = (byte*)malloc(4);
			*(class FaceFXAnimSet**)params = AnimSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnmountFaceFXAnimSet(class FaceFXAnimSet* AnimSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FaceFXAsset.UnmountFaceFXAnimSet");
			byte* params = (byte*)malloc(4);
			*(class FaceFXAnimSet**)params = AnimSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
