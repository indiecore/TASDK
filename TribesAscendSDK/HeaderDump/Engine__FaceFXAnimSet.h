#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FaceFXAnimSet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FaceFXAnimSet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FaceFXAnimSet." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FaceFXAnimSet : public Object
	{
	public:
			ADD_VAR( ::IntProperty, NumLoadErrors, 0xFFFFFFFF )
			ADD_OBJECT( FaceFXAsset, DefaultFaceFXAsset )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
