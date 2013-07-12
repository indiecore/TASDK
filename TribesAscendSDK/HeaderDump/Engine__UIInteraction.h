#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIInteraction." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIInteraction." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIInteraction." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIInteraction : public Interaction
	{
	public:
			ADD_OBJECT( GameUISceneClient, SceneClient )
			ADD_VAR( ::IntProperty, DoubleClickPixelTolerance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTriggerSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseButtonRepeatDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AxisRepeatDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UIAxisMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UIJoystickDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bProcessInput, 0x1 )
			ADD_OBJECT( DataStoreClient, DataStoreManager )
			ADD_OBJECT( UIManager, UIManager )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
