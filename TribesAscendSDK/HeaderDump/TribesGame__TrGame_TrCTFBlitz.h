#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame_TrCTFBlitz." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame_TrCTFBlitz." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame_TrCTFBlitz." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TrCTFBlitz : public TrGame_TRCTF
	{
	public:
			ADD_VAR( ::BoolProperty, m_bRotateBothFlagsOnCapture, 0x1 )
			ADD_OBJECT( TrCTFBase_DiamondSword, DiamondSwordFlagStands )
			ADD_OBJECT( TrCTFBase_BloodEagle, BloodEagleFlagStands )
			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCTFBlitz.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterFlagBase( class TrCTFBase* FlagBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCTFBlitz.RegisterFlagBase" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrCTFBase** )( params + 0 ) = FlagBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreFlag( class Controller* Scorer, class TrFlagBase* theFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCTFBlitz.ScoreFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Scorer;
				*( class TrFlagBase** )( params + 4 ) = theFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RotateFlag( class TrFlagBase* theFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame_TrCTFBlitz.RotateFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrFlagBase** )( params + 0 ) = theFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
