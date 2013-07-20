#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVGSNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVGSNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVGSNode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVGSNode : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, m_bDrawHeader, 0x10 )
			ADD_VAR( ::StrProperty, m_MenuString, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_KeyBind, 0xFFFFFFFF )
			ScriptClass* ProcessKeyInput( ScriptName Key, class TrPlayerInput* PlayerInput, ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVGSNode.ProcessKeyInput" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = Key;
				*( class TrPlayerInput** )( params + 8 ) = PlayerInput;
				*( ScriptClass** )( params + 12 ) = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			bool VerifyVGSCommandEntry( byte Command, ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVGSNode.VerifyVGSCommandEntry" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = Command;
				*( ScriptClass** )( params + 4 ) = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bIgnoreCaH, 0x8 )
			ADD_VAR( ::BoolProperty, m_bIgnoreArena, 0x4 )
			ADD_VAR( ::BoolProperty, m_bIgnoreTeamRabbit, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIgnoreCTF, 0x1 )
			bool VerifyVGSChild( ScriptClass* VGSNodeClass, ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVGSNode.VerifyVGSChild" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = VGSNodeClass;
				*( ScriptClass** )( params + 4 ) = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetGametypeSpecificCommands( ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVGSNode.GetGametypeSpecificCommands" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 12 ) = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetGametypeSpecificChildrenNodes( ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVGSNode.GetGametypeSpecificChildrenNodes" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 12 ) = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
