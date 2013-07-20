#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicleSimChopper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicleSimChopper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicleSimChopper." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicleSimChopper : public UDKVehicleSimChopper
	{
	public:
			ADD_VAR( ::BoolProperty, bShouldStabilizeRotation, 0x2 )
			ADD_VAR( ::BoolProperty, m_bInvertFlight, 0x1 )
			ADD_VAR( ::IntProperty, m_nLastYawInput, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastPitchInput, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReverseSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HoverHeight, 0xFFFFFFFF )
			void SetVehicleControls( bool bInvert )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleSimChopper.SetVehicleControls" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInvert;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
