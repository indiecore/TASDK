#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMainMenuMeshInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrMainMenuMeshInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrMainMenuMeshInfo : public Object
	{
	public:
		ADD_VAR(::NameProperty, ParentSocketName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'MeshInfo'!
		void PreloadTextures(float ForceDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMainMenuMeshInfo.PreloadTextures");
			byte* params = (byte*)malloc(4);
			*(float*)params = ForceDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
