#pragma once
#include "Engine.PrefabSequence.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Prefab.h"
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
	class PrefabInstance : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, PI_Bytes, 556)
		ADD_STRUCT(ScriptArray<class Object*>, PI_CompleteObjects, 568)
		ADD_STRUCT(ScriptArray<class Object*>, PI_ReferencedObjects, 580)
		ADD_STRUCT(ScriptArray<ScriptString*>, PI_SavedNames, 592)
		ADD_STRUCT(int, PI_LicenseePackageVersion, 552)
		ADD_STRUCT(int, PI_PackageVersion, 548)
		ADD_OBJECT(PrefabSequence, SequenceInstance, 544)
		ADD_STRUCT(int, TemplateVersion, 480)
		ADD_OBJECT(Prefab, TemplatePrefab, 476)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
