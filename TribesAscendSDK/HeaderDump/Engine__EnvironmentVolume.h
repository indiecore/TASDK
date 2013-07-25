#pragma once
#include "Engine__Volume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.EnvironmentVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.EnvironmentVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EnvironmentVolume : public Volume
	{
	public:
		ADD_VAR(::BoolProperty, bSplitNavMesh, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavMeshPathObject'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavMeshPathObstacle'!
		void SetSplitNavMesh(bool bNewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EnvironmentVolume.SetSplitNavMesh");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
