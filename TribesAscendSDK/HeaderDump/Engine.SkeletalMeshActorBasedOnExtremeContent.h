#pragma once
#include "Engine.SkeletalMeshActor.h"
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
	class SkeletalMeshActorBasedOnExtremeContent : public SkeletalMeshActor
	{
	public:
		class SkelMaterialSetterDatum
		{
		public:
			ADD_OBJECT(MaterialInterface, TheMaterial, 4)
			ADD_STRUCT(int, MaterialIndex, 0)
		};
		ADD_STRUCT(ScriptArray<SkeletalMeshActorBasedOnExtremeContent::SkelMaterialSetterDatum>, ExtremeContent, 536)
		ADD_STRUCT(ScriptArray<SkeletalMeshActorBasedOnExtremeContent::SkelMaterialSetterDatum>, NonExtremeContent, 548)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorBasedOnExtremeContent.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorBasedOnExtremeContent.SetMaterialBasedOnExtremeContent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
