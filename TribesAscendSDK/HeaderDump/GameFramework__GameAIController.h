#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameAIController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameAIController." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameAIController." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameAIController : public AIController
	{
	public:
			ADD_VAR( ::StrProperty, DemoActionString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CommandHistoryNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DebugTextMaxLen, 0xFFFFFFFF )
			ADD_OBJECT( FileLog, AILogFile )
			ADD_OBJECT( GameAICommand, CommandList )
			ADD_VAR( ::BoolProperty, bAIBroken, 0x80 )
			ADD_VAR( ::BoolProperty, bAIDrawDebug, 0x40 )
			ADD_VAR( ::BoolProperty, bMapBasedLogName, 0x20 )
			ADD_VAR( ::BoolProperty, bFlushAILogEachLine, 0x10 )
			ADD_VAR( ::BoolProperty, bAILogToWindow, 0x8 )
			ADD_VAR( ::BoolProperty, bAILogging, 0x4 )
			ADD_VAR( ::BoolProperty, bHasRunawayCommandList, 0x2 )
			ADD_VAR( ::BoolProperty, bUseAITree, 0x1 )
			ADD_OBJECT( AITree, AITree )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
