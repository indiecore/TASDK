#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicle_Tank." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicle_Tank." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicle_Tank." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle_Tank : public TrVehicle
	{
	public:
			ADD_VAR( ::FloatProperty, m_CameraShakeEffectiveRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, m_FireCameraShake )
			ADD_VAR( ::ByteProperty, GunnerFiringMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, GunnerFlashCount, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, GunnerWeaponRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, GunnerFlashLocation, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
