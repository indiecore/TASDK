#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCaHCapturePoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCaHCapturePoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCaHCapturePoint." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCaHCapturePoint : public TrGameObjective
	{
	public:
			ADD_VAR( ::FloatProperty, m_HoldTheLineAccoladeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fNearbyPawnCheckTime, 0xFFFFFFFF )
			ADD_OBJECT( TrPlayerController, m_LastCapturedBy )
			ADD_VAR( ::FloatProperty, m_fPointPulseMarkerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPointPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPointPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseMarkerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MarkerSize, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nFlashPointPulse, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CapturePointLabel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsHeld, 0x1 )
			ADD_STRUCT( ::VectorProperty, LastCameraPos, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraDir, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastScreenLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInfluenceRadiusSize, 0xFFFFFFFF )
			ADD_OBJECT( SkelControlSingleBone, m_SkyHologramSkelControl )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleDS, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleBE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vSkyHologramOffsetDS, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vSkyHologramOffsetBE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_DiamondSwordHologramMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_BloodEagleHologramMIC )
			ADD_VAR( ::StrProperty, m_sCapturePointName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
