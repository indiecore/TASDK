#pragma once
#include "TribesGame__TrProj_Tracer.h"
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
		// Here lies the not-yet-implemented method 'GetTracer'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'CreatePools'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'CleanUpPools'
		// Here lies the not-yet-implemented method 'CreateTracers'
		// Here lies the not-yet-implemented method 'CleanupTracers'
		// Here lies the not-yet-implemented method 'CreateTracer'
	};
}
#undef ADD_STRUCT
