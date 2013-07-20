#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNode_MultiBlendPerBone." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNode_MultiBlendPerBone." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNode_MultiBlendPerBone." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNode_MultiBlendPerBone : public AnimNodeBlendBase
	{
	public:
			ADD_OBJECT( Pawn, PawnOwner )
			void SetMaskWeight( int MaskIndex, float DesiredWeight, float BlendTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNode_MultiBlendPerBone.SetMaskWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MaskIndex;
				*( float* )( params + 4 ) = DesiredWeight;
				*( float* )( params + 8 ) = BlendTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, RotationBlendType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
