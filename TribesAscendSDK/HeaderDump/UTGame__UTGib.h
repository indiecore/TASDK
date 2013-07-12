#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTGib." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTGib." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTGib." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGib : public Actor
	{
	public:
			ADD_VAR( ::NameProperty, DecalDissolveParamName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DecalWaitTimeBeforeDissolve, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseUnrealPhysics, 0x1 )
			ADD_STRUCT( ::RotatorProperty, OldCamRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OldCamLoc, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bStopMovingCamera, 0x2 )
			ADD_OBJECT( ParticleSystem, PS_CustomEffect )
			ADD_VAR( ::FloatProperty, GibMeshWaitTimeBeforeDissolve, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, GibMeshDissolveParamName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceTimeVarying, MITV_GibMeshTemplateSecondary )
			ADD_OBJECT( MaterialInstanceTimeVarying, MITV_GibMeshTemplate )
			ADD_OBJECT( MaterialInstanceTimeVarying, MITV_DecalTemplate )
			ADD_OBJECT( MaterialInstance, MI_Decal )
			ADD_OBJECT( MaterialInstanceConstant, MIC_Gib )
			ADD_OBJECT( SoundCue, HitSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
