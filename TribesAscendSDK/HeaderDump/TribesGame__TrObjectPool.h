#pragma once
#include "Engine__Actor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrObjectPool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrObjectPool : public Actor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObjectPool.TracerCacheInfo' for the property named 'm_TracerCache'!
	};
}
#undef ADD_STRUCT
