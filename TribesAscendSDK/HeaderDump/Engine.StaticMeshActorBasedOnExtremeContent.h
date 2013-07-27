#pragma once
#include "Engine.Actor.h"
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
	class StaticMeshActorBasedOnExtremeContent : public Actor
	{
	public:
		class SMMaterialSetterDatum
		{
		public:
			ADD_OBJECT(MaterialInterface, TheMaterial, 4)
			ADD_STRUCT(int, MaterialIndex, 0)
		};
		ADD_STRUCT(ScriptArray<StaticMeshActorBasedOnExtremeContent::SMMaterialSetterDatum>, ExtremeContent, 480)
		ADD_STRUCT(ScriptArray<StaticMeshActorBasedOnExtremeContent::SMMaterialSetterDatum>, NonExtremeContent, 492)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshActorBasedOnExtremeContent.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshActorBasedOnExtremeContent.SetMaterialBasedOnExtremeContent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
