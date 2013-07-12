#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameExplosionActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameExplosionActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameExplosionActor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameExplosionActor : public Actor
	{
	public:
			ADD_STRUCT( ::VectorProperty, ExplosionDirection, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectionalExplosionMinDot, 0xFFFFFFFF )
			ADD_OBJECT( Controller, AttacheeController )
			ADD_OBJECT( Actor, Attachee )
			ADD_STRUCT( ::VectorProperty, HitLocationFromPhysMaterialTrace, 0xFFFFFFFF )
			ADD_OBJECT( Actor, HitActorFromPhysMaterialTrace )
			ADD_OBJECT( Controller, InstigatorController )
			ADD_OBJECT( GameExplosion, ExplosionTemplate )
			ADD_VAR( ::FloatProperty, RadialBlurMaxBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialBlurFadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialBlurFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightInitialBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightFadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDrawDebug, 0x4 )
			ADD_VAR( ::BoolProperty, bExplodeMoreThanOnce, 0x2 )
			ADD_VAR( ::BoolProperty, bHasExploded, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
