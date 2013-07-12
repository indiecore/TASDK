#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.SeqEvent_MobileButton." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.SeqEvent_MobileButton." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.SeqEvent_MobileButton." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileButton : public SeqEvent_MobileZoneBase
	{
	public:
			ADD_VAR( ::BoolProperty, bSendPressedOnlyOnTouchUp, 0x4 )
			ADD_VAR( ::BoolProperty, bSendPressedOnlyOnTouchDown, 0x2 )
			ADD_VAR( ::BoolProperty, bWasActiveLastFrame, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
