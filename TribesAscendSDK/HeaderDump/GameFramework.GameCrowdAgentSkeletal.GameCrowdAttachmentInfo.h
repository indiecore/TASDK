#pragma once
#include "Core.Object.Vector.h"
#include "Engine.StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameCrowdAgentSkeletal.GameCrowdAttachmentInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameCrowdAgentSkeletal.GameCrowdAttachmentInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameCrowdAgentSkeletal.GameCrowdAttachmentInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdAttachmentInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, Scale3D, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Chance, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, StaticMesh)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
