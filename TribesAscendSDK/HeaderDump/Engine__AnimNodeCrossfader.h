#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeCrossfader." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeCrossfader." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeCrossfader." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeCrossfader : public AnimNodeBlend
	{
	public:
			ADD_VAR( ::FloatProperty, PendingBlendOutTimeOneShot, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDontBlendOutOneShot, 0x1 )
			ADD_VAR( ::NameProperty, DefaultAnimSeqName, 0xFFFFFFFF )
			void PlayOneShotAnim( ScriptName AnimSeqName, float BlendInTime, float BlendOutTime, bool bDontBlendOut, float Rate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeCrossfader.PlayOneShotAnim" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = AnimSeqName;
				*( float* )( params + 8 ) = BlendInTime;
				*( float* )( params + 12 ) = BlendOutTime;
				*( bool* )( params + 16 ) = bDontBlendOut;
				*( float* )( params + 20 ) = Rate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BlendToLoopingAnim( ScriptName AnimSeqName, float BlendInTime, float Rate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeCrossfader.BlendToLoopingAnim" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = AnimSeqName;
				*( float* )( params + 8 ) = BlendInTime;
				*( float* )( params + 12 ) = Rate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetAnimName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeCrossfader.GetAnimName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			class AnimNodeSequence* GetActiveChild(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeCrossfader.GetActiveChild" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
