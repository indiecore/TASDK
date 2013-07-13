#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LiftExit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LiftExit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LiftExit." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LiftExit : public NavigationPoint
	{
	public:
			ADD_VAR( ::BoolProperty, bExitOnly, 0x1 )
			ADD_OBJECT( LiftCenter, MyLiftCenter )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
