#pragma once
#include "Engine.PrefabSequence.h"
#include "Core.Object.h"
#include "Engine.Texture2D.h"
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
	class Prefab : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, PrefabArchetypes, 64)
		ADD_STRUCT(ScriptArray<class Object*>, RemovedArchetypes, 76)
		ADD_OBJECT(Texture2D, PrefabPreview, 92)
		ADD_OBJECT(PrefabSequence, PrefabSequence, 88)
		ADD_STRUCT(int, PrefabVersion, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
