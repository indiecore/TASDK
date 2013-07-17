#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrLoadingData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrLoadingData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrLoadingData." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrLoadingData : public Object
	{
	public:
			ADD_VAR( ::StrProperty, RulesForBlitz, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForCaH, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForDaD, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForArena, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForRabbit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForTDM, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForCTF, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MapName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MapURL, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Rules, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Tip, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetRandomTip( int GameIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLoadingData.GetRandomTip" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = GameIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLoadingData.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDataFields(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLoadingData.SetDataFields" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
