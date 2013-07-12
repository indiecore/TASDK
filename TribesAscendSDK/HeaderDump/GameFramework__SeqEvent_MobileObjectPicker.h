#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.SeqEvent_MobileObjectPicker." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.SeqEvent_MobileObjectPicker." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.SeqEvent_MobileObjectPicker." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileObjectPicker : public SeqEvent_MobileRawInput
	{
	public:
			ADD_OBJECT( Object, FinalTouchObject )
			ADD_STRUCT( ::VectorProperty, FinalTouchNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FinalTouchLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TraceDistance, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
