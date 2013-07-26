#pragma once
#include "TribesGame.TrMainMenuMeshInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrMainMenuContentData.MeshData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrMainMenuContentData.MeshData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MeshData
	{
	public:
		ADD_OBJECT(TrMainMenuMeshInfo, MainMeshInfo)
		ADD_VAR(::ByteProperty, ContentDataType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
