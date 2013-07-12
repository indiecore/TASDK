#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimNotify_PlayParticleEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimNotify_PlayParticleEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimNotify_PlayParticleEffect." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_PlayParticleEffect : public AnimNotify
	{
	public:
			ADD_OBJECT( ParticleSystem, PSTemplate )
			ADD_VAR( ::BoolProperty, bIsExtremeContent, 0x1 )
			ADD_VAR( ::BoolProperty, bAttach, 0x2 )
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSkipIfOwnerIsHidden, 0x8 )
			ADD_VAR( ::BoolProperty, bPreview, 0x4 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
