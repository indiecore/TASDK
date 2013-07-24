#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Core.Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Core.Object." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Object
	{
	public:
		ADD_OBJECT(Object, Outer)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTableObject'!
		ADD_VAR(::IntProperty, ObjectInternalInteger, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'ObjectFlags'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'HashNext'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'HashOuterNext'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StateFrame'!
		ADD_OBJECT(Object, Linker)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LinkerIndex'!
		ADD_VAR(::IntProperty, NetIndex, 0xFFFFFFFF)
		ADD_OBJECT(Object, ObjectArchetype)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
