#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.CameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.CameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.CameraAnim." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraAnim : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, BaseFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BasePPSettingsAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimLength, 0xFFFFFFFF )
			ADD_OBJECT( InterpGroup, CameraInterpGroup )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
