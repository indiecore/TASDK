#pragma once
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDynamicFieldProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDynamicFieldProvider : public UIDataProvider
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'RuntimeCollectionData'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'PersistentCollectionData'!
	};
}
#undef ADD_STRUCT
