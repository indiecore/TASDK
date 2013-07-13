#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNode : public AnimObject
	{
	public:
			ADD_VAR( ::IntProperty, SearchTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bCachedHasRootMotion, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CachedNumDesiredBones, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, NodeName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NodeTotalWeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NodeCachedAtomsTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TickArrayIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NodeInitTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NodeTickTag, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCallScriptEventOnCeaseRelevant, 0x40 )
			ADD_VAR( ::BoolProperty, bCallScriptEventOnBecomeRelevant, 0x20 )
			ADD_VAR( ::BoolProperty, bCallScriptEventOnInit, 0x10 )
			ADD_VAR( ::BoolProperty, bDisableCaching, 0x8 )
			ADD_VAR( ::BoolProperty, bTickDuringPausedAnims, 0x4 )
			ADD_VAR( ::BoolProperty, bJustBecameRelevant, 0x2 )
			ADD_VAR( ::BoolProperty, bRelevant, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
