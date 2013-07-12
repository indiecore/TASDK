#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKSkelControl_HoverboardSwing." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKSkelControl_HoverboardSwing." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKSkelControl_HoverboardSwing." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_HoverboardSwing : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentSwing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxUseVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSwing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SwingScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SwingHistorySlot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SwingHistoryWindow, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
