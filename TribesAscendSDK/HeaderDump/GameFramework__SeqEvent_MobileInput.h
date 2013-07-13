#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_MobileInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_MobileInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_MobileInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileInput : public SeqEvent_MobileZoneBase
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, YAxisValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, XAxisValue, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
